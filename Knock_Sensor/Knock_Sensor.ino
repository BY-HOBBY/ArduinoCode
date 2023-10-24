int val;    // numeric variable to store sensor status
const int greenLedPin = 2; // Green LED pin
const int redLedPin = 3;   // Red LED pin
const int buzzerPin = 4;   // Buzzer pin
const int shock = 5;       // Shock vibration input

void setup() {
  pinMode(shock, INPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);    // Initialize serial communication
}

void loop() {
  val = digitalRead(shock); // Read and assign the value of digital interface 3 to val 

  if (val == HIGH) {
    digitalWrite(buzzerPin, HIGH);    // No buzzer
    digitalWrite(redLedPin, LOW);    // Turn off red LED
    digitalWrite(greenLedPin, HIGH); // Turn on green LED
  } 
  else {    
    Serial.println("Knock detected..."); 
    digitalWrite(redLedPin, HIGH);   // Turn on red LED
    digitalWrite(greenLedPin, LOW);  // Turn off green LED
    digitalWrite(buzzerPin, LOW);   // Start the buzzer
    delay(3000);                     // Wait for 5 seconds
    digitalWrite(buzzerPin, HIGH);    // Stop the buzzer
    digitalWrite(redLedPin, LOW);    // Turn off red LED
    digitalWrite(greenLedPin, HIGH); // Turn on green LED
    delay(1000);                     // Wait for a moment to stabilize
  }
}
