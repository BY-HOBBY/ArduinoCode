#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int lcdAddress = 0x27;  // I2C address for the LCD
const int lcdCols = 20;       // Number of columns on the LCD
const int lcdRows = 4;        // Number of rows on the LCD

LiquidCrystal_I2C lcd(lcdAddress, lcdCols, lcdRows);

void setup() {
  lcd.init();
  lcd.backlight();  // Turn on the backlight

  // Print the initial message with line breaks for a good look and feel
  lcd.print("Welcome to BY HOBBY");
  lcd.setCursor(0, 1);  // Move to the second row
  lcd.print("YouTube Channel!");
  lcd.setCursor(0, 2);  // Move to the third row
  lcd.print("This is 20x4 LCD");
  lcd.setCursor(0, 3);  // Move to the fourth row
  lcd.print("with I2C Serial!");
  
  // Delay for 2-3 seconds (adjust as needed)
  delay(3000);

  // Clear the screen and print the second message
  lcd.clear();
  lcd.print("Don't Forget to");
  lcd.setCursor(0, 1);
  lcd.print("Like, Share &");
  lcd.setCursor(0, 2);
  lcd.print("Subscribe :)");
}

void loop() {
  // Your code here
}
