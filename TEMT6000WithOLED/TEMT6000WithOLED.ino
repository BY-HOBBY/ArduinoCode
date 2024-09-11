#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int sensorPin = A0; // Analog pin connected to TEMT6000
int graph[SCREEN_WIDTH]; // Array to hold graph data

void setup() {
  Serial.begin(9600);

  // Initialize OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  display.display();
  delay(2000); // Pause for 2 seconds
  display.clearDisplay();

  // Draw labels and graph axis on OLED
  drawGraphBase();
}

void loop() {
  int lightLevel = analogRead(sensorPin); // Read analog value from sensor
  lightLevel = map(lightLevel, 0, 1023, 0, 63); // Map value to display height (0-63)

  // Shift all previous data to the left by one pixel
  for (int i = 1; i < SCREEN_WIDTH; i++) {
    graph[i - 1] = graph[i];
  }
  // Add new reading to the rightmost position
  graph[SCREEN_WIDTH - 1] = lightLevel;

  // Display graph
  display.clearDisplay(); // Clear the screen
  drawGraphBase(); // Redraw axis
  plotGraph(); // Plot new graph
  display.display(); // Show updated screen

  // Display numeric value of light level
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print("Light: ");
  display.print(lightLevel); // Show the raw value (can be changed to actual lux)
  display.display();

  delay(200); // Delay to slow down updates
}

void drawGraphBase() {
  // Draw the base of the graph (axes)
  display.drawLine(0, 63, SCREEN_WIDTH, 63, SSD1306_WHITE); // X-axis
  display.drawLine(0, 0, 0, SCREEN_HEIGHT, SSD1306_WHITE);  // Y-axis
}

void plotGraph() {
  // Plot the data points
  for (int i = 1; i < SCREEN_WIDTH; i++) {
    display.drawLine(i - 1, 63 - graph[i - 1], i, 63 - graph[i], SSD1306_WHITE);
  }
}
