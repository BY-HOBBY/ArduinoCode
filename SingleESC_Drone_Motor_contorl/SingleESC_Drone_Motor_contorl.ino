#define ESC_PIN 9  // Connect ESC signal wire to D9 (PWM pin)

int escValue = 0; // Initial PWM signal

void setup() {
  pinMode(ESC_PIN, OUTPUT);  // Set ESC pin as output

  // Start the motor at its minimum throttle value (1000 ms)
  analogWrite(ESC_PIN, escValue);
  delay(1000); // Give the ESC time to initialize
}

void loop() {
  // Example: gradually increase motor speed
  for (escValue = 0; escValue <= 255; escValue++) {
    analogWrite(ESC_PIN, escValue);  // Write PWM value to ESC
    delay(50);  // Slow down the increase in speed
  }
  
  // Example: gradually decrease motor speed
  for (escValue = 255; escValue >= 0; escValue--) {
    analogWrite(ESC_PIN, escValue);
    delay(50);
  }
}
