#include <U8g2lib.h>

U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
int messageIndex = 0;
unsigned long lastMessageChange = 0;
const int messageDuration = 3000; // 3 seconds per message

void setup(void) {
  u8g2.begin();
}

void loop(void) {
  u8g2.firstPage();
  do {
    u8g2.setFont(u8g2_font_6x10_tf); // Choose a font size

    if (messageIndex == 0) {
      u8g2.drawStr(0, 37, "welcome to by hobby youtube,");
    }
    else if (messageIndex == 1) {
      u8g2.drawStr(0, 37, "this is oled display!");
    }
    else if (messageIndex == 2) {
      u8g2.drawStr(0, 37, "please like, share & subscribe !!");
    }
  } while (u8g2.nextPage());

  if (millis() - lastMessageChange >= messageDuration) {
    // Switch to the next message after the messageDuration
    messageIndex = (messageIndex + 1) % 3;
    lastMessageChange = millis();
  }
}
