// Define the pin number for the LED
const int ledPin = 13;

// Setup function runs once when the board starts up
void setup() {
  // Set the LED pin as an OUTPUT
  pinMode(ledPin, OUTPUT);
}

// Loop function runs repeatedly after the setup
void loop() {
  // Turn the LED on (HIGH) - LED glows
  digitalWrite(ledPin, HIGH);
  
  // Wait for 1 second (1000 milliseconds)
  delay(1000);

  // Turn the LED off (LOW) - LED turns off
  digitalWrite(ledPin, LOW);

  // Wait for 1 second (1000 milliseconds)
  delay(1000);
}
