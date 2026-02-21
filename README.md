# Iris Zero
A small ESP32-S3-MINI-1 based dev board with USB HID functionality.

You can use this board with your own personal project and peripherals. The dev board uses only 2 IO pins and its IO12 for a white LED and IO48 for a SK6805-EC14 LED.
Made this because of need for a small dev board with USB HID capabilities.

## Screenshots
<details>
    <summary>Click to expand</summary>
    <img width="1062" height="734" alt="image" src="https://github.com/user-attachments/assets/5348ab15-81dc-4150-b082-e184b53fedde" />
    <img width="959" height="632" alt="image" src="https://github.com/user-attachments/assets/233fca25-5d2b-403a-addd-14d1d2983484" />
    <img width="1190" height="845" alt="SCH_Iris Zero_1-P1_2026-02-21" src="https://github.com/user-attachments/assets/cf33a4a9-b746-4603-9493-5b2bea3cf0a4" />
    <img width="415" height="672" alt="image" src="https://github.com/user-attachments/assets/a5e14693-01f7-49aa-afc9-e92b5cd64995" />
    <img width="406" height="667" alt="image" src="https://github.com/user-attachments/assets/3d1d895e-ecd9-44bb-9f38-7ba4fc58c873" />
    <img width="1844" height="860" alt="image" src="https://github.com/user-attachments/assets/fa46c51e-87e8-4150-bd27-fda06fb33cc2" />
</details>

## Bill of materials
### To find each component use the Supplier Part field at https://www.lcsc.com/
|No.|Quantity|Comment            |Designator|Footprint                        |Value|Manufacturer Part  |Manufacturer       |Supplier Part|Supplier|
|---|--------|-------------------|----------|---------------------------------|-----|-------------------|-------------------|-------------|--------|
|1  |1       |1uF                |C1        |C0402                            |1uF  |CL05A105KA5NQNC    |SAMSUNG(三星)        |C52923       |LCSC    |
|2  |2       |10uF               |C2,C3     |C0402                            |10uF |CL05A106MQ5NUNC    |SAMSUNG(三星)        |C15525       |LCSC    |
|3  |1       |SK6805-EC14        |LED1      |LED-SMD_4P-L1.4-W1.4-TL          |     |SK6805-EC14        |欧思科光电              |C2909055     |LCSC    |
|4  |1       |KT-0805W           |LED2      |LED0805-R-RD                     |     |KT-0805W           |KENTO              |C34499       |LCSC    |
|5  |2       |10kΩ               |R1,R3     |R0402                            |10kΩ |0402WGF1002TCE     |UNI-ROYAL(厚声)      |C25744       |LCSC    |
|6  |1       |75Ω                |R2        |R0402                            |75Ω  |0402WGF750JTCE     |UNI-ROYAL(厚声)      |C25133       |LCSC    |
|7  |2       |5.1kΩ              |R4,R5     |R0402                            |5.1kΩ|0402WGF5101TCE     |UNI-ROYAL(厚声)      |C25905       |LCSC    |
|8  |2       |SKTDLHE010         |SW1,SW2   |KEY-SMD_SKTDLHE010               |     |SKTDLHE010         |ALPSALPINE(阿尔卑斯阿尔派)|C380198      |LCSC    |
|9  |1       |ESP32-S3-MINI-1    |U1        |BULETM-SMD_ESP32-S3-MINI-1-N8    |     |ESP32-S3-MINI-1    |                   |C9900015247  |LCSC    |
|10 |1       |AP2112K-3.3TRG1(MS)|U2        |SOT-23-5_L2.9-W1.6-P0.95-LS2.7-BR|     |AP2112K-3.3TRG1(MS)|MSKSEMI(美森科)       |C22365427    |LCSC    |
|11 |1       |TYPE-C 16P QTGM027 |USB1      |USB-C-SMD_TYPE-C-16P-QTGM027     |     |TYPE-C 16P QTGM027 |SHOU HAN(首韩)       |C2681552     |LCSC    |


**Total: ~$9.09**