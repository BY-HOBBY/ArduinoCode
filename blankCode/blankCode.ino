#include <LiquidCrystal.h>

const int ledPin = 13;             // Pin connected to the LED
const int switchPin = 6;           // Pin connected to the push switch

// LCD Pin Definitions
const int lcdRsPin = 12;
const int lcdEnablePin = 11;
const int lcdD4Pin = 5;
const int lcdD5Pin = 4;
const int lcdD6Pin = 3;
const int lcdD7Pin = 2;

LiquidCrystal lcd(lcdRsPin, lcdEnablePin, lcdD4Pin, lcdD5Pin, lcdD6Pin, lcdD7Pin);

int ledState = LOW;
int lastSwitchState = LOW;
boolean gameInProgress = false;
boolean gameEnded = false;
boolean gamePaused = false;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(switchPin, INPUT_PULLUP);
  lcd.begin(16, 2);  // Initialize the LCD with 16 columns and 2 rows
  lcd.clear();
  lcd.print("Press to Start!");
}

void loop() {
  int switchState = digitalRead(switchPin);

  if (switchState == LOW && lastSwitchState == HIGH && gameInProgress) {
    gamePaused = !gamePaused;
  }

  if (!gameInProgress) {
    gameInProgress = true;
    gameEnded = false;
    gamePaused = false;
    lcd.clear();
    //lcd.print("Game started!");
  }

  if (!gamePaused) {
    ledState = !ledState;
    digitalWrite(ledPin, ledState);
    delay(100);  // Adjust the delay to control the LED blink speed
  }

  if (gamePaused && !gameEnded) {
    lcd.setCursor(0, 1);

    if (ledState == HIGH) {
      lcd.print("YOU WON!!");
    } else {
      lcd.print("YOU LOSE :( ");
    }
  }

  if (switchState == LOW && lastSwitchState == HIGH && gameInProgress && !gamePaused) {
    gameInProgress = false;
    lcd.setCursor(0, 1);

    if (ledState == HIGH) {
      lcd.print("You WIN!           ");
    } else {
      lcd.print("You LOSE!          ");
    }

    lcd.setCursor(0, 0);
    lcd.print("Press to Play Again");
  }

  lastSwitchState = switchState;
}
