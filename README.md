# Beyond the Weather: BMP280 Monitoring with KiwisIoT

An IoT-based environmental monitoring project using **BMP280**, **NodeMCU ESP8266**, and **KiwisIoT** to monitor temperature, atmospheric pressure, and estimated altitude remotely.

## Overview

This project uses the BMP280 sensor to measure temperature and atmospheric pressure. The NodeMCU ESP8266 collects the readings through I2C communication and sends them to the KiwisIoT cloud dashboard using Wi-Fi.

The dashboard displays live environmental data, including estimated altitude calculated from atmospheric pressure.

## Features

- Real-time temperature monitoring
- Atmospheric pressure measurement
- Estimated altitude calculation
- Wireless data transmission using ESP8266
- Cloud-based monitoring through KiwisIoT
- Live dashboard visualization

## Hardware Components

- NodeMCU ESP8266
- BMP280 Environmental Sensor
- Jumper Wires
- USB-A to Mini-USB Cable

## Circuit Connections

| BMP280 | NodeMCU ESP8266 |
|---|---|
| VCC / VIN | 3.3V |
| GND | GND |
| SDA | D2 (GPIO4) |
| SCL | D1 (GPIO5) |

**Note:** Use a 3.3V-compatible BMP280 module.

## KiwisIoT Dashboard

| Channel | Parameter | Unit |
|---|---|---|
| Channel 0 | Temperature | °C |
| Channel 1 | Atmospheric Pressure | hPa |
| Channel 2 | Estimated Altitude | m |

## Working Principle

1. BMP280 measures surrounding temperature and atmospheric pressure.
2. NodeMCU ESP8266 reads the sensor data through I2C.
3. Altitude is estimated using atmospheric pressure.
4. ESP8266 sends all three readings through Wi-Fi.
5. KiwisIoT displays the live readings on the cloud dashboard.

## Applications

- Weather monitoring stations
- Agricultural environmental monitoring
- Greenhouse monitoring
- Atmospheric pressure observation
- Indoor environmental monitoring
- Altitude monitoring experiments
- IoT educational projects

## Libraries and Resources

- **KiwisIoT Platform:** https://www.kiwisiot.in/
- **KiwisIoT Arduino Library:** https://github.com/Kiwistron/KiwisIoT
- **KiwisIoT Example Projects:** https://github.com/Kiwistron/KiwisIoT-Projects/tree/main
- **Adafruit BMP280 Library:** Available through Arduino IDE Library Manager

## Project Tutorial

[Beyond the Weather: BMP280 Monitoring with KiwisIoT – Hackster.io](https://www.hackster.io/kirusokumar/beyond-the-weather-bmp280-monitoring-with-kiwisiot-f36c41)

## Author

**Kirusokumar**

## License

This project is intended for educational and experimental purposes. Please credit the original author when modifying or redistributing it.