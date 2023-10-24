int IRF520_PIN = 2;  // Connect the signal pin of IRF520 module to Arduino pin 2

void setup() {
  pinMode(IRF520_PIN, OUTPUT);
}

void loop() {
  // Turn the load on
  digitalWrite(IRF520_PIN, HIGH);
  delay(1000);  // Wait for 1 second

  // Turn the load off
  digitalWrite(IRF520_PIN, LOW);
  delay(1000);  // Wait for 1 second
}
