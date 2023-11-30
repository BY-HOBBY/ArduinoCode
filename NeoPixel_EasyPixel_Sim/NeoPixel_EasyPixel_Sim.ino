#include <EasyNeoPixels.h>

const int pinInput = 6;
const int numberOfLEDs = 16;
const int speedAnimation = 100;

void setup() {
    setupEasyNeoPixels(pinInput, numberOfLEDs);
}

// int r[16] = {255,255,255,0,0,0,0,255,255,255,255,0,0,0,0,255};
// int g[16] = {0,255,255,255,0,0,255,0,0,255,255,255,0,0,255,0};
// int b[16] = {0,0,255,255,255,0,0,255,0,0,255,255,255,0,0,255};
void loop() {
    // turn the NeoPixel ON
    for (int i=0;i<numberOfLEDs;i++)
    {
      // writeEasyNeoPixel(i, r[i],g[i],b[i]);
       writeEasyNeoPixel(i, 255,255, 255);
      delay(speedAnimation);
      // turn the NeoPixel OFF
      writeEasyNeoPixel(i, LOW);
      delay(speedAnimation);
    }
    //writeEasyNeoPixel(1, 255, 0, 255);      // make the first neopixel purple (red + blue)
}
