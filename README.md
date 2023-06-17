# esp-idf-mcp41010
Three-Wire Digitally Controlled Potentiometer driver for ESP-IDF.   

ESP32 has two 8-bit DAC (digital to analog converter) channels, connected to GPIO25 (Channel 1) and GPIO26 (Channel 2).   
However, the maximum voltage is up to VDD.   
If you control a voltage up to 5V, you can use this.   

And ESP32Sx/ESP32Cx core does not have a DAC function.   

- MCP41010 = Single Digital Potentiometer (10 kOhms)   
- MCP41050 = Single Digital Potentiometer (50 kOhms)   
- MCP41100 = Single Digital Potentiometer (100 kOhms)   
- MCP42010 = Dual Digital Potentiometer (10 kOhms)   
- MCP42050 = Dual Digital Potentiometer (50 kOhms)   
- MCP42100 = Dual Digital Potentiometer (100 kOhms)   

I ported from [here](https://github.com/sleemanj/MCP41_Simple).   

# Software requirements
ESP-IDF V4.4/V5.0.   
ESP-IDF V5.0 is required when using ESP32-C2.   

# Installation

```Shell
git clone https://github.com/nopnop2002/esp-idf-mcp41010
cd esp-idf-mcp41010
idf.py set-target {esp32/esp32s2/esp32s3/esp32c2/esp32c3}
idf.py menuconfig
idf.py flash
```


# Configuration   

![config-top](https://user-images.githubusercontent.com/6020549/222987838-0dd807c2-e6cb-45ec-9f2e-06a08ebb0504.jpg)
![config-mcp41010-1](https://user-images.githubusercontent.com/6020549/222987853-4be43700-ef92-4338-a19d-7fc6a5b4885e.jpg)
![config-mcp41010-2](https://user-images.githubusercontent.com/6020549/162594835-f059f585-567d-410a-9339-5a962c6d7f8d.jpg)

# SPI BUS selection   
![config-mcp41010-3](https://user-images.githubusercontent.com/6020549/222987872-4e9a662c-f051-49a9-a1b8-aff97bda3547.jpg)

The ESP32 series has three SPI BUSs.   
SPI1_HOST is used for communication with Flash memory.   
You can use SPI2_HOST and SPI3_HOST freely.   
When you use SDSPI(SD Card via SPI), SDSPI uses SPI2_HOST BUS.   
When using this module at the same time as SDSPI or other SPI device using SPI2_HOST, it needs to be changed to SPI3_HOST.   
When you don't use SDSPI, both SPI2_HOST and SPI3_HOST will work.   
Previously it was called HSPI_HOST / VSPI_HOST, but now it is called SPI2_HOST / SPI3_HOST.   

# Wirering

|Circuit|MCP||ESP32|ESP32-S2/S3|ESP32-C2/C3|
|:-:|:-:|:-:|:-:|:-:|:-:|
||CS|--|GPIO5|GPIO34|GPIO5|
||SCK|--|GPIO18|GPIO36|GPIO1|
||SI|--|GPIO23|GPIO35|GPIO0|
||Vss|--|GND|GND|GND|
|High terminals|PA0/PA1|--||||
|Wiper terminals|PW0/PW1|--||||
|Low terminals|PB0/PB1|--||||
||Vdd|--|3.3V|3.3V|3.3V|

__You can change it to any pin using menuconfig.__   

If you connect to Low terminals = Gnd and High terminals = 3.3V, 0 to 3.3V is output to Wiper terminals in 255 steps.   

# Typical circuit
![ESP32-mcp41xxx](https://user-images.githubusercontent.com/6020549/222988540-2d1d70b7-2aa1-4e90-a3a2-1a9666512fef.jpg)

# API
See [here](https://github.com/sleemanj/MCP41_Simple).


# Reference
https://github.com/nopnop2002/esp-idf-x9c103

