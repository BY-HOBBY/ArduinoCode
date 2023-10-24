const int sensorPin = A0;   // Analog input pin for the heartbeat sensor
const int numReadings = 10;  // Number of readings to average for EMA
const float smoothingFactor = 0.2;  // Smoothing factor for EMA
int threshold = 550;         // Adjust this threshold based on your sensor readings

unsigned long lastBeatTime = 0;  // Variable to measure pulse rate
float heartRate = 0;           // Variable to store the heart rate in beats per second (BPS)

void setup() {
  Serial.begin(9600);  // Initialize serial communication
}

void loop() {
  // Read the sensor value
  int pulseValue = analogRead(sensorPin);

  // Detect a heartbeat by checking if the sensor value is above the threshold
  if (pulseValue > threshold) {
    // Calculate the time between beats (in milliseconds)
    unsigned long timeSinceLastBeat = millis() - lastBeatTime;
    lastBeatTime = millis();

    // Calculate heart rate in beats per second (BPS)
    if (timeSinceLastBeat != 0) {
      float instantHeartRate = 1000.0 / timeSinceLastBeat;  // Calculate BPS
      heartRate = (smoothingFactor * instantHeartRate) + ((1.0 - smoothingFactor) * heartRate);
    }

    // Print heart rate to serial monitor
    Serial.println(heartRate);  // Send heart rate data for plotting
  }
}
