#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP085_U.h>
#include <LiquidCrystal_I2C.h>

// Initialize the BMP180 sensor
Adafruit_BMP085_Unified bmp = Adafruit_BMP085_Unified(10085);

// Initialize the LiquidCrystal_I2C library with the correct I2C address (0x27 or 0x3F)
LiquidCrystal_I2C lcd(0x27, 20, 4);  // 20 columns, 4 rows

// Reference sea level pressure in hPa (adjust based on your location if needed)
float seaLevelPressure = 1013.25;

void setup() {
  Serial.begin(9600);

  // Initialize the BMP180 sensor
  if (!bmp.begin()) {
    Serial.println("Could not find a valid BMP180 sensor, check wiring!");
    while (1);
  }

  // Initialize the LCD
  lcd.init();      // Start the LCD
  lcd.backlight();  // Turn on the LCD backlight

  // Print a welcome message on the LCD
  lcd.setCursor(0, 0);  // Set cursor to the first column, first row
  lcd.print("BMP180 Sensor Test");
  delay(2000);  // Wait for 2 seconds
}

void loop() {
  sensors_event_t event;
  bmp.getEvent(&event);

  if (event.pressure) {
    float temperature;
    bmp.getTemperature(&temperature);

    // Calculate altitude based on the pressure and sea-level pressure
    float altitude = bmp.pressureToAltitude(seaLevelPressure, event.pressure) - 346; // do level with ground here

    // Clear the display before updating the values
    lcd.clear();

    // Display temperature on the first row
    lcd.setCursor(0, 0);  // Set cursor to first column, first row
    lcd.print("Temp: ");
    lcd.print(temperature);
    lcd.print(" C");

    // Display pressure on the second row
    lcd.setCursor(0, 1);  // Set cursor to first column, second row
    lcd.print("Pressure: ");
    lcd.print(event.pressure);
    lcd.print(" hPa");

    // Display altitude on the third row
    lcd.setCursor(0, 2);  // Set cursor to first column, third row
    lcd.print("Altitude: ");
    lcd.print(altitude);
    lcd.print(" m");

    // Display a custom message or additional data on the fourth row if needed
    lcd.setCursor(0, 3);  // Fourth row
    lcd.print("Data updated!");
  }

  delay(1000);  // Wait for 1 second before refreshing the display
}
