int tiltPin = 2;      // pin number for tilt switch signal
int ledPin = LED_BUILTIN;     // pin number of LED
int tiltState = 0;    // variable for reading the tilt switch status

void setup() {
  pinMode(ledPin, OUTPUT);  // set the LED pin as output
  pinMode(tiltPin, INPUT);  // set the tilt switch pin as input

  // Initialize serial communication
  Serial.begin(9600);
}

void loop() {
  // get the tilt switch state
  tiltState = digitalRead(tiltPin);

  // Print the tilt switch state to the serial monitor
  Serial.println(tiltState);

  // check if tilt switch is tilted.
  if (tiltState == HIGH) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
    delay(1000);
  }
}
