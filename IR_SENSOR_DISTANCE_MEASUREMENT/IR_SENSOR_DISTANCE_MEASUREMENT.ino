const int irSensorPin = A0; // Analog input pin connected to the IR sensor
float sensorValues[] = {100, 200, 300, 400}; // Example recorded sensor values
float distances[] = {10, 20, 30, 40}; // Corresponding known distances

void setup() {
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  int sensorValue = analogRead(irSensorPin); // Read the sensor value

  // Use a linear interpolation to convert sensor value to distance
  float distance = map(sensorValue, sensorValues[0], sensorValues[3], distances[0], distances[3]);

  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  Serial.print(", Distance (cm): ");
  Serial.println(distance);

  delay(500); // Delay for readability, adjust as needed
}
