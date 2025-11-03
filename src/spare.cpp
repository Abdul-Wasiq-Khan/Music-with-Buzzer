/*
#include <Arduino.h>
#include <IRremote.hpp>

const int RECV_PIN = 2; // IR receiver connected to D2
const int code[7][3]={
  {69,70,71}, // Power, Vol+, Func/Stop
  {68,64,67}, // Vol-, Fast Backward, Pause
  {7,21,9}, // Play, Fast Forward, Down
  {22,25,13}, // Up, EQ, 0
  {12,24,94}, // 1, 2, 3
  {8,28,90}, // 4, 5, 6
  {66,82,74}  // 7, 8, 9
};
void setup() {
  Serial.begin(9600);
  pinMode(4, OUTPUT); // LED connected to D4
  IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK); // Start IR receiver
}

void loop() {
  if (IrReceiver.decode()) {
    Serial.println(IrReceiver.decodedIRData.command); // Print command value
    IrReceiver.resume(); // Ready to receive next signal
    Serial.print("Ready for next signal: ");
    Serial.println(IrReceiver.decodedIRData.command);
    if (IrReceiver.decodedIRData.command == 69) { // If "0" button
      digitalWrite(4, HIGH); // Turn on LED
      Serial.println("LED ON");
    }
    if (IrReceiver.decodedIRData.command == 68) { // If "1" button
      digitalWrite(4, LOW); // Turn off LED
      Serial.println("LED OFF");  
    }
  }
}
*/