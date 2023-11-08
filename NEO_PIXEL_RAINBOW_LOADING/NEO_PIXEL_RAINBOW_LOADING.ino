#include <Adafruit_NeoPixel.h>
#include "hsv.h"

// data pin
#define PIN 6
// led count
#define CNT 16
// max Hue
#define MAXHUE 256*6

int position = 0;
int hue = 0;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(CNT, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
}

void loop() {
  // hue - red
  // saturation - max
  // value - 0-255
  for (int i = 0; i < CNT; i++)
    strip.setPixelColor((i + position) % CNT, getPixelColorHsv(i, hue, 255, strip.gamma8(i * (255 / CNT))));
  strip.show();
  position++;
  position %= CNT;
  hue += 2;
  hue %= MAXHUE;
  delay(50);
}
