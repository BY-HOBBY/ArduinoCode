#include <Keypad.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {13, 10, A1, A0}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

const String password = "1234"; // Set your 4-digit password here
int passwordIndex = 0;
bool locked = true;

const int ledPin = A2; // Connect your LED to this pin

void setup(){
  pinMode(ledPin, OUTPUT);
  lcd.begin(16, 2);
  lcd.print("Type Password");
  lcd.setCursor(0, 1);
}

void loop(){
  char key = keypad.getKey();
  if (key){
    if (locked){
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Type Password");
      passwordIndex = 0;
      locked = false;
    }
    if (key == password[passwordIndex]){
      passwordIndex++;
      if (passwordIndex == password.length()){
        digitalWrite(ledPin, HIGH); // LED ON
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Unlocked");
      }
    }
    else if (key == '0')
    {
        //delay(2000);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Type Password");
        digitalWrite(ledPin, LOW); // LED OFF
        locked = true;
    }
    else {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Type Password");
      delay(1000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Type Password");
      passwordIndex = 0;
      locked = true;
    }
  }
}
