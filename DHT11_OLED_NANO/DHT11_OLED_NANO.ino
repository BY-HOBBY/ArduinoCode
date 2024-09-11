/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-temperature-humidity-sensor-oled-display
 */

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

#define SCREEN_WIDTH 128 // OLED display width,  in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define DHTPIN 2 // pin connected to DHT11 sensor
#define DHTTYPE DHT11

Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1); // create SSD1306 display object connected to I2C
DHT dht(DHTPIN, DHTTYPE);

String temperature;
String humidity;

void setup() {
  Serial.begin(9600);

  // initialize OLED display with address 0x3C for 128x64
  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (true)
      ;
  }

  delay(2000);          // wait for initializing
  oled.clearDisplay();  // clear display

  oled.setTextSize(3);       // text size
  oled.setTextColor(WHITE);  // text color
  oled.setCursor(0, 10);     // position to display

  dht.begin();  // initialize DHT11 the temperature and humidity sensor

  temperature.reserve(10);  // to avoid fragmenting memory when using String
  humidity.reserve(10);     // to avoid fragmenting memory when using String
}

void loop() {
  float humi = dht.readHumidity();      // read humidity
  float tempC = dht.readTemperature();  // read temperature

  // check if any reads failed
  if (isnan(humi) || isnan(tempC)) {
    temperature = "Failed";
    humidity = "Failed";
  } else {
    temperature = String(tempC, 1);  // one decimal places
    temperature += char(247);        // degree character
    temperature += "C";
    humidity = String(humi, 1);  // one decimal places
    humidity += "%";
  }

  Serial.print(tempC);  // print to Serial Monitor
  Serial.print("°C | " );  // print to Serial Monitor
  Serial.print(humi);  // print to Serial Monitor
  Serial.println("%");  // print to Serial Monitor
  oledDisplayCenter(temperature, humidity);      // display temperature and humidity on OLED
}

void oledDisplayCenter(String temperature, String humidity) {
  int16_t x1;
  int16_t y1;
  uint16_t width_T;
  uint16_t height_T;
  uint16_t width_H;
  uint16_t height_H;

  oled.getTextBounds(temperature, 0, 0, &x1, &y1, &width_T, &height_T);
  oled.getTextBounds(temperature, 0, 0, &x1, &y1, &width_H, &height_H);

  // display on horizontal and vertical center
  oled.clearDisplay();  // clear display
  oled.setCursor((SCREEN_WIDTH - width_T) / 2, SCREEN_HEIGHT / 2 - height_T - 5);
  oled.println(temperature);  // text to display
  oled.setCursor((SCREEN_WIDTH - width_H) / 2, SCREEN_HEIGHT / 2 + 5);
  oled.println(humidity);  // text to display
  oled.display();
}
