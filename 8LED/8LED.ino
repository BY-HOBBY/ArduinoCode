const int numLEDs = 8; // Number of LEDs
const int delayTime = 100; // Delay time in milliseconds (adjust for desired speed)
int ledPins[numLEDs] = {2, 3, 4, 5, 6, 7, 8, 9}; // Define the LED pins
void setup() {
  // Initialize LED pins as OUTPUT
  for (int i = 0; i < numLEDs; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}
void loop() {
  // Turn all LEDs off
  turnOffAllLEDs();
  // Loop through each LED and turn it on one by one
  for (int i = 0; i < numLEDs; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(delayTime);
  }
  // Turn all LEDs off in reverse order
  for (int i = numLEDs - 1; i >= 0; i--) {
    digitalWrite(ledPins[i], LOW);
    delay(delayTime);
  }
}
void turnOffAllLEDs() {
  // Turn off all LEDs
  for (int i = 0; i < numLEDs; i++) {
    digitalWrite(ledPins[i], LOW);
  }
}
