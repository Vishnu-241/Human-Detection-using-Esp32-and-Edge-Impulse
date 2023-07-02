# Human-Detection-using-Esp32-and-Edge-Impulse
This project is used to detect human using FOMO machine learning algorithm that is trained using the platform **Edge impulse** and later deployed into esp32-cam board using **Arduino IDE** platform

# INTRODUCTION
**Esp32 cam**
One of the most popular and affordable development boards that already integrates a camera is the ESP32-CAM, which combines an Espressif ESP32-S MCU chip with an ArduCam OV2640 camera.
![image](https://github.com/Vishnu-241/Human-Detection-using-Esp32-and-Edge-Impulse/assets/84576905/35dd401e-0715-4dbc-ad62-f28a460c8597)

The ESP32 chip is so powerful that it can even process images. It includes I2C, SPI, UART communications, and PWM and DAC outputs.

Parameters:

Working voltage: 4.75-5.25V

splash: Default 32Mbit

RAM: Internal 520KB + external 8MB PSRAM

Wi-Fi: 802.11b/g/n/e/i

Bluetooth: Bluetooth 4.2BR/EDR and BLE standard

Support interface (2Mbps): UART, SPI, I2C, PWM

Support TF card: maximum support 4G

IO port: 9

Serial port rate: default 115200bps

Spectrum range: 2400 ~2483.5MHz

Antenna form: onboard PCB antenna, gain 2dBi

Image output format: JPEG (only OV2640 support), BMP, GRAYSCALE

Note that this device has not a USB-TTL Serial module integrated, so to upload a code to the ESP32-CAM will be necessary a special adapter as below:
![image](https://github.com/Vishnu-241/Human-Detection-using-Esp32-and-Edge-Impulse/assets/84576905/02372b7c-2235-4313-9fb4-cce79671423c)

**Installing the ESP32-Cam on Arduino IDE**

Open the preferences window from the Arduino IDE and go to:

Arduino > Preferences

Enter with the below line:

**https://dl.espressif.com/dl/package_esp32_index.json**

On the field ==> Additional Boards Manager URLs

![image](https://github.com/Vishnu-241/Human-Detection-using-Esp32-and-Edge-Impulse/assets/84576905/0975da0c-68e3-46e7-afb6-8145faac0bae)

Next, open boards manager. Go to Tools > Board > Boards Manager… and enter with esp32. Select and install the most updated package

![image](https://github.com/Vishnu-241/Human-Detection-using-Esp32-and-Edge-Impulse/assets/84576905/e122c1a5-4c09-4ea7-87e1-8e3750710b03)

Select an ESP32 board:

For example, AI-Thinker ESP32-CAM

![image](https://github.com/Vishnu-241/Human-Detection-using-Esp32-and-Edge-Impulse/assets/84576905/b008c7f6-9758-40fa-82ca-798c7eb1702b)



