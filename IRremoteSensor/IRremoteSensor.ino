#include <IRremote.h>

#define IR_RECEIVE_PIN 11

#define IR_BUTTON_0 7
#define IR_BUTTON_1 10
#define IR_BUTTON_2 27
#define IR_BUTTON_3 31
#define IR_BUTTON_4 12
#define IR_BUTTON_5 13
#define IR_BUTTON_6 14
#define IR_BUTTON_7 0
#define IR_BUTTON_8 15
#define IR_BUTTON_9 25

#define IR_BUTTON_LIKE 6
#define IR_BUTTON_SHARE 3
#define IR_BUTTON_SUBSCRIBE 1
 

#define IR_BUTTON_PLAY_PAUSE 64

const int numLeds = 8;
const int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9};

//IRrecv IrReceiver(IR_RECEIVE_PIN);  // Declare a single IRrecv instance

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN);

  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }
}

void loop() {
  if (IrReceiver.decode()) {
    IrReceiver.resume();
    int command = IrReceiver.decodedIRData.command;
    processIRCommand(command);
  }
}

void processIRCommand(int command) {
  // Turn off all LEDs
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], LOW);
  }


  // Turn on LEDs based on the button pressed
  switch (command) {
    case IR_BUTTON_0:
      // LED 0 is OFF
      Serial.println("Button Pressed 0");
      break;

    case IR_BUTTON_1:
      for (int i = 0; i < 1; i++)
        digitalWrite(ledPins[i], HIGH);
        Serial.println("Button Pressed 1");
      break;

    case IR_BUTTON_2:
      for (int i = 0; i < 2; i++)
        digitalWrite(ledPins[i], HIGH);
        Serial.println("Button Pressed 2");
      break;

    case IR_BUTTON_3:
      for (int i = 0; i < 3; i++)
        digitalWrite(ledPins[i], HIGH);
        Serial.println("Button Pressed 3");
      break;

    case IR_BUTTON_4:
      for (int i = 0; i < 4; i++)
        digitalWrite(ledPins[i], HIGH);
        Serial.println("Button Pressed 4");
      break;

    case IR_BUTTON_5:
      for (int i = 0; i < 5; i++)
        digitalWrite(ledPins[i], HIGH);
        Serial.println("Button Pressed 5");
      break;

    case IR_BUTTON_6:
      for (int i = 0; i < 6; i++)
        digitalWrite(ledPins[i], HIGH);
        Serial.println("Button Pressed 6");
      break;

    case IR_BUTTON_7:
      for (int i = 0; i < 7; i++)
        digitalWrite(ledPins[i], HIGH);
        Serial.println("Button Pressed 7");
      break;

    case IR_BUTTON_8:
      for (int i = 0; i < 8; i++)
        digitalWrite(ledPins[i], HIGH);
        Serial.println("Button Pressed 8");
      break;

    case IR_BUTTON_9:
      // Turn on all LEDs
      for (int i = 0; i < numLeds; i++)
        digitalWrite(ledPins[i], HIGH);
        Serial.println("Button Pressed 9");
      break;

    case IR_BUTTON_LIKE:
        Serial.println("Like 👍");
      break;

    case IR_BUTTON_SHARE:
        Serial.println("Share ");
      break;

    case IR_BUTTON_SUBSCRIBE:
        Serial.println("Subscribe Channel");
      break;

    default:
      Serial.println("Button not recognized");
      Serial.println(command);
      break;
  }
}
