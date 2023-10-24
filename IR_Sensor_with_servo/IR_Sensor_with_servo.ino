#include <Servo.h>
// Pin definitions
const int irSensorPin = 2;  // Connect the IR sensor to digital pin 2
const int servoPin = 9;     // Connect the servo motor to digital pin 9
Servo servoMotor;

void setup() {
  pinMode(irSensorPin, INPUT);
  servoMotor.attach(servoPin);
  servoMotor.write(90);  // Set the initial position of the servo to 90 degrees
}

void loop() {
  int obstacle = digitalRead(irSensorPin);

  if (obstacle == LOW) {
    // Obstacle detected, start the motor
    servoMotor.write(0);  // Rotate the servo to a certain angle (e.g., 0 degrees)
  } else {
    // No obstacle, stop the motor
    servoMotor.write(90);  // Return the servo to the initial position (90 degrees)
  }
  delay(100);  // Add a small delay to prevent rapid switching due to sensor noise
}
