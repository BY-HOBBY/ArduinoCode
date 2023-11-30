// Define constants for the ultrasonic sensor
const int trigPin = 10;
const int echoPin = 11;

// Define constants for LEDs
const int numLEDs = 8;
const int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9};
const int distance_step = 3;

// Define variables
long duration;
int distance;

void setup() {
  // Initialize the serial communication
  Serial.begin(9600);

  // Set ultrasonic sensor pins as OUTPUT and INPUT
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Set LED pins as OUTPUT
  for (int i = 0; i < numLEDs; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  // Measure distance using the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  // Print the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Turn on/off LEDs based on distance thresholds
  for (int i = 0; i < numLEDs; i++) {
    if (distance > (i + 1) * distance_step) {
      digitalWrite(ledPins[i], LOW);
    } else {
      digitalWrite(ledPins[i], HIGH);
    }
  }

  // Add a delay to avoid flooding the Serial Monitor
  delay(500);
}
