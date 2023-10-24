#include "LedControl.h"

LedControl lc = LedControl(12, 11, 10, 1);  // Initialize the MAX7219 with appropriate pins

void setup() {
  lc.shutdown(0, false);   // Wake up the MAX7219
  lc.setIntensity(0, 8);   // Set the brightness (0-15)
  lc.clearDisplay(0);      // Clear the display
}

void loop() {
  int x = 0;
  int y = 0;
  int xDirection = 1;
  int yDirection = 0;

  while (true) {
    lc.clearDisplay(0);  // Clear the display

    // Turn on the LED at the current position
    lc.setLed(0, x, y, true);

    // Update the position
    x += xDirection;
    y += yDirection;

    // Change direction if hitting the boundaries
    if (x == 7 && y == 0) {
      xDirection = 0;
      yDirection = 1;
    } else if (x == 7 && y == 7) {
      xDirection = -1;
      yDirection = 0;
    } else if (x == 0 && y == 7) {
      xDirection = 0;
      yDirection = -1;
    } else if (x == 0 && y == 0) {
      xDirection = 1;
      yDirection = 0;
    }

    delay(100);  // Adjust the delay to control the speed
  }
}
