int motorPin = A0; // The pin that the DC motor is connected to

void setup() {
  pinMode(motorPin, OUTPUT); // Set the motor pin as an output
}

void loop() {
  // Generate a PWM signal with a duty cycle of 50%
  analogWrite(motorPin, 50);

  // Wait for 1 second
  delay(1000);

  // Generate a PWM signal with a duty cycle of 0%
  analogWrite(motorPin, 0);

  // Wait for 1 second
  delay(1000);
}
