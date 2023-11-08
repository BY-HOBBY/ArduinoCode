#include<SoftwareSerial.h>

SoftwareSerial bt(2, 3);  // (Rx, Tx)
int redLedPin = 7;        // Pin to control the red LED
int greenLedPin = 6;      // Pin to control the green LED
bool redLedState = LOW;
bool greenLedState = LOW;

void setup() {
  bt.begin(9600);
  Serial.begin(9600);
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
}

void loop() {
  if (bt.available()) {
    String command = bt.readString();
    command.trim();  // Remove leading and trailing whitespaces
    command.toLowerCase();  // Convert to lowercase for case-insensitive comparison

    if (command == "red light on") {
      redLedState = HIGH;
      Serial.println("Red LED is ON");
    } else if (command == "red light off") {
      redLedState = LOW;
      Serial.println("Red LED is OFF");
    } else if (command == "green light on") {
      greenLedState = HIGH;
      Serial.println("Green LED is ON");
    } else if (command == "green light off") {
      greenLedState = LOW;
      Serial.println("Green LED is OFF");
    }
     else if (command == "all light on") {
      greenLedState = HIGH;
      redLedState = HIGH;
      Serial.println("Green LED is OFF");
    }
     else if (command == "all light off") {
      greenLedState = LOW;
      redLedState = LOW;
      Serial.println("Green LED is OFF");
    }

    digitalWrite(redLedPin, redLedState);
    digitalWrite(greenLedPin, greenLedState);
  }
}
