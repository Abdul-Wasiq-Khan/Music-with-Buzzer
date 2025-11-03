/*
#include <Arduino.h>
#include <Wire.h>

void Driver_setup() {
  Wire.begin();
  Serial.begin(9600);
  Serial.println("Scanning...");
}

void Driver_loop() {
  for (byte address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    if (Wire.endTransmission() == 0) {
      Serial.print("Found device at 0x");
      Serial.println(address, HEX);
    }
    delay(5);
  }
  Serial.println("Done.");
  delay(500); // Scan every 500 milliseconds
}*/