// Motor control pins
const int motor1A = 8;  // Connect to IN1 on the Mini Motor Drive Shield
const int motor1B = 9;  // Connect to IN2 on the Mini Motor Drive Shield

void setup() {
  pinMode(motor1A, OUTPUT);
  pinMode(motor1B, OUTPUT);
}

void loop() {
  // Rotate motor clockwise for 2 seconds
  digitalWrite(motor1A, HIGH);
  digitalWrite(motor1B, LOW);
  delay(2000);

  // Stop the motor for 1 second
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, LOW);
  delay(1000);

  // Rotate motor counterclockwise for 2 seconds
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, HIGH);
  delay(2000);

  // Stop the motor for 1 second
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, LOW);
  delay(1000);
}
