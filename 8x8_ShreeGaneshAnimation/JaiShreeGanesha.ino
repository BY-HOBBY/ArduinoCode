#include "LedControl.h"

LedControl display = LedControl(12, 11, 10, 1);  // Initialize the MAX7219 with appropriate pins

const uint64_t IMAGES[] = {
  0x6050080e04140810, 0x7878189981a58181, 0xb9b95adb99a5423c, 0x30109282aa921000,
  0x6050080e04140810, 0x78581899db81a581, 0x78581899db81a542,0xc4c8f0d6c814ccc0,
  0x242a2c282828ff10, 0x0054dc7d57d47f00, 0x7e81bddb24241818, 0xdbff3c3c18181800
};
const int IMAGES_LEN = sizeof(IMAGES) / 8;

void setup() {
  display.clearDisplay(0);
  display.shutdown(0, false);
  display.setIntensity(0, 10);
}

void displayImage(uint64_t image) {
  for (int i = 0; i < 8; i++) {
    byte row = (image >> i * 8) & 0xFF;
    row = reverseByte(row);  // Reverse the bits in the row
    for (int j = 0; j < 8; j++) {
      display.setLed(0, i, j, bitRead(row, j));
    }
  }
}

byte reverseByte(byte b) {
  byte result = 0;
  for (int i = 0; i < 8; i++) {
    result |= ((b >> i) & 1) << (7 - i);
  }
  return result;
}

int i = 0;

void loop() {
  displayImage(IMAGES[i]);
  if (++i >= IMAGES_LEN) {
    i = 0;
  }
  delay(1000);
}
