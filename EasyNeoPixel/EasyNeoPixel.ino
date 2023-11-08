#include <EasyNeoPixels.h>

const int pinInput = 2;
const int numberOfLEDs = 1;

void setup() {
    setupEasyNeoPixels(pinInput, numberOfLEDs);
}

void loop() {
    // turn the NeoPixel ON
    writeEasyNeoPixel(1, HIGH);
    writeEasyNeoPixel(1, 255, 0, 255);      // make the first neopixel purple (red + blue)
}
