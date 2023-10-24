const int irSensorPin = 2;  // Connect the digital IR sensor to digital pin 2
const int OutLEDPin = 13;

void setup() {
  pinMode(irSensorPin, INPUT);
  pinMode(OutLEDPin, OUTPUT);
  
  Serial.begin(9600);  // Initialize the serial communication  
}

void loop() {
  int obstacle = digitalRead(irSensorPin);

  if (obstacle == LOW) {
    Serial.println("Obstacle detected!");
    digitalWrite(OutLEDPin, HIGH);
  } else {
    Serial.println("No obstacle.");
    digitalWrite(OutLEDPin, LOW);
  }

  delay(500);  // Add a small delay to prevent rapid readings
}
