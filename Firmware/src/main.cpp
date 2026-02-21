#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/ledc.h"
#include "led_strip.h"
#include "esp_log.h"

#define LED1_GPIO 12
#define LED2_GPIO 48

static const char *TAG = "IrisZero";
static led_strip_handle_t led_strip;

void led1_task(void *pvParameters)
{
    int duty = 0;
    int direction = 1;
    while (1)
    {
        ledc_set_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0, duty);
        ledc_update_duty(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0);

        duty += direction * 200;
        if (duty >= 8191)
        {
            duty = 8191;
            direction = -1;
        }
        else if (duty <= 0)
        {
            duty = 0;
            direction = 1;
        }

        vTaskDelay(pdMS_TO_TICKS(10));
    }
}

void led2_task(void *pvParameters)
{
    uint32_t red = 255, green = 0, blue = 0;
    const int step = 5;

    while (1)
    {
        if (red > 0 && blue == 0)
        {
            red -= step;
            green += step;
        }
        else if (green > 0 && red == 0)
        {
            green -= step;
            blue += step;
        }
        else if (blue > 0 && green == 0)
        {
            blue -= step;
            red += step;
        }

        ESP_ERROR_CHECK(led_strip_set_pixel(led_strip, 0, red, green, blue));
        ESP_ERROR_CHECK(led_strip_refresh(led_strip));

        vTaskDelay(pdMS_TO_TICKS(50));
    }
}

extern "C" void app_main(void)
{
    // --- Configure LED1 ---
    ledc_timer_config_t ledc_timer = {
        .speed_mode = LEDC_LOW_SPEED_MODE,
        .duty_resolution = LEDC_TIMER_13_BIT,
        .timer_num = LEDC_TIMER_0,
        .freq_hz = 5000,
        .clk_cfg = LEDC_AUTO_CLK};
    ledc_timer_config(&ledc_timer);

    ledc_channel_config_t ledc_channel = {
        .gpio_num = LED1_GPIO,
        .speed_mode = LEDC_LOW_SPEED_MODE,
        .channel = LEDC_CHANNEL_0,
        .intr_type = LEDC_INTR_DISABLE,
        .timer_sel = LEDC_TIMER_0,
        .duty = 0,
        .hpoint = 0};
    ledc_channel_config(&ledc_channel);

    // --- Configure SK6805-EC14 ---
    led_strip_config_t strip_config = {
        .strip_gpio_num = LED2_GPIO,
        .max_leds = 1,
        .led_pixel_format = LED_PIXEL_FORMAT_GRB,
        .led_model = LED_MODEL_WS2812,
        .flags = {.invert_out = false}};

    led_strip_rmt_config_t rmt_config = {
        .clk_src = RMT_CLK_SRC_DEFAULT,
        .resolution_hz = 10 * 1000 * 1000, // 10MHz
        .mem_block_symbols = 64,
        .flags = {.with_dma = false}};

    ESP_ERROR_CHECK(led_strip_new_rmt_device(&strip_config, &rmt_config, &led_strip));
    led_strip_clear(led_strip);

    xTaskCreate(led1_task, "White_LED", 2048, NULL, 5, NULL);
    xTaskCreate(led2_task, "SK6805_RGB", 2048, NULL, 5, NULL);
}