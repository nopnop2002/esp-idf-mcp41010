# esp-idf-mcp41010
Three-Wire Digitally Controlled Potentiometer driver for ESP-IDF.   

ESP32 has two 8-bit DAC (digital to analog converter) channels, connected to GPIO25 (Channel 1) and GPIO26 (Channel 2).   
However, the maximum voltage is up to VDD.   
If you control a voltage up to 5V, you can use this.   

- MCP41010 = Single Digital Potentiometer (10 kƒ¶)   
- MCP41050 = Single Digital Potentiometer (50 kƒ¶)   
- MCP41100 = Single Digital Potentiometer (100 kƒ¶)   
- MCP42010 = Dual Digital Potentiometer (10 kƒ¶)   
- MCP42050 = Dual Digital Potentiometer (50 kƒ¶)   
- MCP42100 = Dual Digital Potentiometer (100 kƒ¶)   

I ported from [here](https://github.com/sleemanj/MCP41_Simple).   

# Installation

```Shell
git clone https://github.com/nopnop2002/esp-idf-mcp41010
cd esp-idf-mcp41010
idf.py set-target {esp32/esp32s2/esp32c3}
idf.py menuconfig
idf.py flash
```


# Configuration   

![config-top](https://user-images.githubusercontent.com/6020549/162594830-9db662c0-27e8-4335-95bd-0a5836e913b3.jpg)
![config-mcp41010-1](https://user-images.githubusercontent.com/6020549/162594833-d3f2a8db-cf0c-40f1-be8b-eadece28e402.jpg)
![config-mcp41010-2](https://user-images.githubusercontent.com/6020549/162594835-f059f585-567d-410a-9339-5a962c6d7f8d.jpg)


# Wirering

|Circuit|MCP||ESP32|ESP32-S2|ESP32-C3|
|:-:|:-:|:-:|:-:|:-:|:-:|
||CS|--|GPIO5|GPIO34|GPIO5|
||SCLK|--|GPIO18|GPIO36|GPIO1|
||MOSI|--|GPIO23|GPIO35|GPIO0|
||Vss|--|GND|GND|GND|
|High terminals|PA0/PA1|--||||
|Wiper terminals|PW0/PW1|--||||
|Low terminals|PB0/PB1|--||||
||Vdd|--|3.3V|3.3V|3.3V|

__You can change it to any pin using menuconfig.__   

If you connect to Low terminals = Gnd and High terminals = 5V, 0 to 5V is output to Wiper terminals in 255 steps.   


# API
See [here](https://github.com/sleemanj/MCP41_Simple).


