const int voiceSensorPin = A0; // Analog pin connected to the voice sensor output
const int redPin = 9;          // Red pin of the RGB LED module
const int greenPin = 10;        // Green pin of the RGB LED module
const int bluePin = 11;         // Blue pin of the RGB LED module

void setup() {
  pinMode(voiceSensorPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(voiceSensorPin); // Read the analog sensor value

  // Map the sensor value to RGB color intensity range (0-255)
  int redIntensity = map(sensorValue, 0, 1023, 0, 255);
  int greenIntensity = map(sensorValue, 0, 1023, 0, 255);
  int blueIntensity = map(sensorValue, 0, 1023, 0, 255);

  // Adjust the color based on sound intensity
  if (sensorValue < 300) {
    redIntensity = 255;
    greenIntensity = 0;
    blueIntensity = 0;
  } else if (sensorValue < 600) {
    redIntensity = 255;
    greenIntensity = map(sensorValue, 300, 600, 0, 255);
    blueIntensity = 0;
  } else {
    redIntensity = map(sensorValue, 600, 1023, 0, 255);
    greenIntensity = 255;
    blueIntensity = 0;
  }

  // Set RGB LED color based on sound intensity
  analogWrite(redPin, redIntensity);
  analogWrite(greenPin, greenIntensity);
  analogWrite(bluePin, blueIntensity);

  // Print sensor value and RGB intensities for monitoring
  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  Serial.print(" - RGB Intensities: R=");
  Serial.print(redIntensity);
  Serial.print(", G=");
  Serial.print(greenIntensity);
  Serial.print(", B=");
  Serial.println(blueIntensity);

  // Delay to control the RGB LED color transition speed
  delay(100);
}
