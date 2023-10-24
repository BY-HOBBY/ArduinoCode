#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  // Array of words to display
  String words[] = {
    "Hello Friends, ", 
    "Welcome to ", 
    " BYHOBBY ",
     " Youtube Channel!, ", 
     "Please ",
     "Like ",
     "Share ",
     "& Subscribe", 
     };

  // Gradually increase the flashing speed
  int delayTime = 1000;

  for (int i = 0; i < sizeof(words) / sizeof(words[0]); i++) {
    String word = words[i];
      lcd.clear(); // Clear the LCD display
      lcd.setCursor(0, 0); // Set cursor to the current position
      lcd.print(word);
      delay(delayTime); // Adjust the delay to control the speed of the animation
  }
  
  // Delay at the end before starting over
  delay(1000);
}
