#include <ESP8266WiFi.h>
#include <Wire.h>
#include <Adafruit_BMP280.h>
#include <KiwisIoT.h>

const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";
const char* topic = "YOUR_KIWISIOT_TOPIC_ID";

Adafruit_BMP280 bmp;

KiwisIoT kiwisiot(ssid, pass, topic);

unsigned long lastSend = 0;

void setup() {
  Serial.begin(115200);

  // NodeMCU I2C pins: SDA = D2, SCL = D1
  Wire.begin(D2, D1);

  Serial.println("BMP280 Monitoring");

  if (!bmp.begin(0x76)) {
    if (!bmp.begin(0x77)) {
      Serial.println("BMP280 sensor not found!");
      while (1) {
        delay(1000);
      }
    }
  }

  kiwisiot.begin();
}

void loop() {
  kiwisiot.run();

  if (millis() - lastSend >= 2000) {
    lastSend = millis();

    float temperature = bmp.readTemperature();
    float pressure = bmp.readPressure() / 100.0F;

    // Estimated altitude using standard sea-level pressure
    float altitude = bmp.readAltitude(1013.25);

    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" °C");

    Serial.print("Pressure: ");
    Serial.print(pressure);
    Serial.println(" hPa");

    Serial.print("Altitude: ");
    Serial.print(altitude);
    Serial.println(" m");

    // Send readings to KiwisIoT
    kiwisiot.send("0", String(temperature, 2));
    kiwisiot.send("1", String(pressure, 2));
    kiwisiot.send("2", String(altitude, 2));
  }

  delay(10);
}