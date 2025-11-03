#include <Arduino.h>
#define IR_USE_AVR_TIMER2  // Avoid Timer1 conflict
#include <IRremote.hpp>

const int RECV_PIN = 2; // IR receiver connected to D2
const int buzzerPin = 3; // Buzzer connected to D3
const int ledPin = 4; // LED connected to D4
/*


// IR code mappings for my buttons
const int code[7][3] = {
  {69, 70, 71}, // Power, Vol+, Func/Stop
  {68, 64, 67}, // Vol-, Fast Backward, Pause
  {7, 21, 9}, // Play, Fast Forward, Down
  {22, 25, 13}, // Up, EQ, 0
  {12, 24, 94}, // 1, 2, 3
  {8, 28, 90}, // 4, 5, 6
  {66, 82, 74}  // 7, 8, 9
};
*/


unsigned long lastReceiveTime = 0;
const unsigned long DEBOUNCE_DELAY = 200; // 200ms debounce
const int DO  = 900;
const int RE  = 1200;
const int MI  = 1500;
const int FA  = 1800;
const int SO  = 2100;
const int LA  = 2400;
const int TI  = 2700;
const int DO2 = 3000;
void play(int frequency, int duration);
void rainwater();
void happyBirthday(){
  // "Happy Birthday to You"
  play(DO, 400);
  play(DO, 200);
  play(RE, 600);
  play(DO, 600);
  play(FA, 600);
  play(MI, 1200);

  // "Happy Birthday to You"
  play(DO, 400);
  play(DO, 200);
  play(RE, 600);
  play(DO, 600);
  play(SO, 600);
  play(FA, 1200);

  // "Happy Birthday Dear [Name]"
  play(DO, 400);
  play(DO2, 200);
  play(DO, 600);
  play(MI, 600);
  play(FA, 600);
  play(DO, 600);

  // "Happy Birthday to You"
  play(TI, 400);
  play(TI, 200);
  play(LA, 600);
  play(SO, 600);
  play(FA, 600);
  play(MI, 1200);}

void setup() {

  Serial.begin(9600);
  pinMode(ledPin, OUTPUT); 
  pinMode(buzzerPin, OUTPUT); 
  IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK); // Start IR receiver
  Serial.println("IR Receiver started. Press buttons on your remote...");
}

void loop() {

  if (IrReceiver.decode()) {

    


      
    const int command = IrReceiver.decodedIRData.command;
    Serial.print("Command received: ");
    Serial.println(command);

    switch (command) {
      case 0: // Func/Stop
        digitalWrite(7, HIGH);// 7 is reset
        noTone(buzzerPin);
        digitalWrite(7, LOW);
        break;




      case 67:
        happyBirthday();
        break;
      case 9: // Down
        rainwater();
        break;
      case 68:
        play(DO, 200); play(RE, 200); play(MI, 200); play(FA, 200); play(SO, 200); play(LA, 200); play(TI, 200); play(DO2, 400);
        break;
      case 69: // Power
        noTone(buzzerPin);
        digitalWrite(ledPin, HIGH);
        break;

      case 12: // Button 1
        tone(buzzerPin, 300); // 1000Hz
        break;

      case 24: // Button 2
        tone(buzzerPin, 600); // 2000Hz
        break;

      case 94: // Button 3
        tone(buzzerPin, 900); // 3000Hz
        break;

      case 8: // Button 4
        tone(buzzerPin, 1200); // 4000Hz
        break;

      case 28: // Button 5
        tone(buzzerPin, 1500); // 5000Hz
        break;

      case 90: // Button 6
        tone(buzzerPin, 1800); // 6000Hz
        break;

      case 66: // Button 7
        tone(buzzerPin, 2100); // 7000Hz
        break;

      case 82: // Button 8
        tone(buzzerPin, 2400); // 8000Hz
        break;

      case 74: // Button 9
        tone(buzzerPin, 2700); // 9000Hz
        break;

      default:
        noTone(buzzerPin); // Stop sound signal
        digitalWrite(ledPin, LOW);
        break;
    }
  }
    
    IrReceiver.resume(); // Enable receiving the next value
  }


void play(int frequency, int duration) {
  tone(buzzerPin, frequency, duration);
  delay(duration);
  noTone(buzzerPin);
}

void rainwater(){
  while(true){
    int drops = random(2, 8);

  for (int i = 0; i < drops; i++) {
    // random frequency range for "drop" timbre (higher = sharper drop)
    int freq = random(1500, 3500); // Hz
    // random short duration for the click
    int dur = random(20, 120); // ms

    // play the drop
    tone(buzzerPin, freq, dur);

    // small gap after the drop; vary to make it natural
    int gap = random(20, 200);
    delay(dur + gap);
  }

  // occasional heavier splash: lower pitch, longer
  if (random(0, 100) < 20) { // ~20% chance
    tone(buzzerPin, random(800, 1400), random(150, 400));
    delay(random(150, 450));
  }

  // pause between bursts to simulate changing rain intensity
  delay(random(200, 1200));
  }
}