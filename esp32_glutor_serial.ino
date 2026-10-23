/*
  GLUTOR serial data example
  Sends one JSON object per line at 115200 baud for the website to read.

  IMPORTANT:
  - This is a starting example, not a calibrated measurement system.
  - Check your exact MQ-138 module output voltage before connecting it to ESP32.
    ESP32 GPIO is NOT 5 V tolerant. Use suitable voltage conditioning if needed.
  - MQ-138 ADC values are raw response only, not acetone ppm or glucose.
  - Install the Adafruit BME680 Library and Adafruit Unified Sensor library
    from Arduino Library Manager. Confirm I2C pins for your board.
  - GPIO34 is an example ADC input on a classic ESP32 DevKit; confirm your board.
*/
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME680.h>

Adafruit_BME680 bme;
const int MQ138_PIN = 34;
const unsigned long SEND_INTERVAL_MS = 1500;
unsigned long lastSend = 0;
bool bmeReady = false;

void setup() {
  Serial.begin(115200);
  delay(1000);
  analogReadResolution(12); // typical ESP32 ADC range 0..4095; actual calibration varies
  pinMode(MQ138_PIN, INPUT);

  // Uses the board's default I2C pins. Change Wire.begin(SDA, SCL) if required.
  Wire.begin();
  bmeReady = bme.begin(0x76);
  if (!bmeReady) bmeReady = bme.begin(0x77);
  Serial.println("GLUTOR serial stream starting; JSON lines follow.");
  if (!bmeReady) Serial.println("WARNING: BME680 not found; environmental fields will be null.");
}

void loop() {
  if (millis() - lastSend < SEND_INTERVAL_MS) return;
  lastSend = millis();

  int mqRaw = analogRead(MQ138_PIN);
  float tempC = NAN, humidity = NAN, pressureHpa = NAN, gasOhms = NAN;
  if (bmeReady && bme.performReading()) {
    tempC = bme.temperature;
    humidity = bme.humidity;
    pressureHpa = bme.pressure / 100.0F;
    gasOhms = bme.gas_resistance;
  }

  Serial.print("{\"mq138_raw\":"); Serial.print(mqRaw);
  Serial.print(",\"temperature_c\":"); printNumberOrNull(tempC);
  Serial.print(",\"humidity_pct\":"); printNumberOrNull(humidity);
  Serial.print(",\"pressure_hpa\":"); printNumberOrNull(pressureHpa);
  Serial.print(",\"bme680_gas_ohms\":"); printNumberOrNull(gasOhms);
  Serial.println("}");
}

void printNumberOrNull(float value) {
  if (isnan(value) || isinf(value)) Serial.print("null");
  else Serial.print(value, 2);
}
