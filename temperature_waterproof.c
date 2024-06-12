/*
    Project name : Arduino nano Temperature sensor module Waterproof DS18B20
    Modified Date: 12-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/arduino-nano-temperature-sensor-module-waterproof-ds18b20
*/

#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is connected to pin 2 on the Arduino Nano
#define ONE_WIRE_BUS 2

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(ONE_WIRE_BUS);

// Pass oneWire reference to DallasTemperature library
DallasTemperature sensors(&oneWire);

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Initialize DS18B20 temperature sensor
  sensors.begin();
}

void loop() {
  // Request temperature readings from all DS18B20 sensors on the bus
  sensors.requestTemperatures();

  // Get temperature in Celsius from the first DS18B20 sensor found on the bus
  float temperatureC = sensors.getTempCByIndex(0);

  // Check if temperature reading is valid
  if (temperatureC != DEVICE_DISCONNECTED_C) {
    // Print temperature to Serial Monitor
    Serial.print("Temperature (C): ");
    Serial.println(temperatureC);
  } else {
    // Print error message if temperature reading failed
    Serial.println("Error reading temperature!");
  }

  // Wait a few seconds before taking the next reading
  delay(2000);
}
