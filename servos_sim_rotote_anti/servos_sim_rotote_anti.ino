#include <Servo.h>

Servo servo1;
Servo servo2;

int servoPin1 = 9; // Connect servo1 signal wire to pin 9
int servoPin2 = 10; // Connect servo2 signal wire to pin 10

void setup() {
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
}

void loop() {
  // Rotate both servo motors simultaneously
  for (int angle = 0; angle <= 180; angle++) {
    servo1.write(angle); // Rotate servo1 clockwise
    servo2.write(180 - angle); // Rotate servo2 counterclockwise
    delay(10); // Adjust the delay for the desired speed
  }
}
