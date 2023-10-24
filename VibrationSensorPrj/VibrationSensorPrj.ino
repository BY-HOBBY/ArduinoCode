const int shockSensorPin = 2; // Digital pin connected to the Shock Sensor module
const int alertPin = 3; // Digital pin connected to the Buzzer or LED (optional)

void setup() {
  pinMode(shockSensorPin, INPUT); // Set the Shock Sensor pin as INPUT
  pinMode(alertPin, OUTPUT); // Set the Buzzer or LED pin as OUTPUT (optional)
  digitalWrite(alertPin, LOW); // Turn off the Buzzer or LED initially (optional)
  Serial.begin(9600); // Initialize serial communication for debugging (optional)
}

void loop() {
  int shockValue = digitalRead(shockSensorPin); // Read the digital value from the Shock Sensor
  Serial.println(shockValue);
  if (shockValue == LOW) {
    Serial.println("Shock detected!"); // Display a message when a shock is detected
    // Your custom actions or functions can be added here.
    // For example, you can activate the Buzzer or LED to indicate the shock.
    digitalWrite(alertPin, HIGH); // Turn on the Buzzer or LED (optional)
  } else {
    // No shock detected, turn off the Buzzer or LED (optional)
    digitalWrite(alertPin, LOW); // Turn off the Buzzer or LED (optional)
  }

  delay(100); // Add a small delay to avoid rapid repeated detections
}
