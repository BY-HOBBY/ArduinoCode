#define ANALOG_IN_PIN A0

// Define the pins for the RGB SMD LED module
const int redPin = 5;   // Red pin
const int greenPin = 3; // Green pin
const int bluePin = 6;  // Blue pin

// Floats for ADC voltage & Input voltage
float adc_voltage = 0.0;
float in_voltage = 0.0;

// Floats for resistor values in divider (in ohms)
float R1 = 30000.0;
float R2 = 7500.0;

// Float for Reference Voltage
float ref_voltage = 5.0;

// Integer for ADC value
int adc_value = 0;

// Define the duration (in milliseconds) to display the color
const unsigned long colorDisplayDuration = 50; // 1 second

unsigned long previousColorChangeMillis = 0;

void setup() {
  // Setup Serial Monitor
  Serial.begin(9600);
  // Set RGB LED pins as outputs
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();

  // Read the Analog Input only when a certain time has passed
  if (currentMillis - previousColorChangeMillis >= colorDisplayDuration) {
    previousColorChangeMillis = currentMillis;

    // Read the Analog Input
    adc_value = analogRead(ANALOG_IN_PIN);

    // Determine voltage at ADC input
    adc_voltage = (adc_value * ref_voltage) / 1024.0;

    // Calculate voltage at divider input
    in_voltage = adc_voltage * (R1 + R2) / R2;

    // Determine the color based on voltage range
    if (in_voltage >= 1.0 && in_voltage < 3.0) {
      setColor(0, 0, 255); 
    } else if (in_voltage >= 3.0 && in_voltage < 3.5) {
      setColor(0, 255, 255); 
    } else if (in_voltage >= 3.5 && in_voltage < 4.0) {
      setColor(0, 255, 0); 
    }
    else if (in_voltage >= 4.0 && in_voltage < 4.5) {
      setColor(255, 255, 0); 
    } else if (in_voltage >= 4.5 && in_voltage <= 5.0) {
      setColor(255, 0, 0); // Red
    } else {
      setColor(0, 0, 0); // Turn off the LED
    }

    // Print results to Serial Monitor
    Serial.print("Input Voltage = ");
    Serial.println(in_voltage, 2);
  }
}

void setColor(int red, int green, int blue) {
  digitalWrite(redPin, red);
  digitalWrite(greenPin, green);
  digitalWrite(bluePin, blue);
}
