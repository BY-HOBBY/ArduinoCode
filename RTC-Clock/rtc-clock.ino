#include <Wire.h>
#include <RTClib.h>

RTC_DS3231 rtc;

// Segment pin definitions (A to G)
const int segmentPins[7] = {2, 3, 4, 5, 6, 7, 8};
// Digit control pins
const int digitPins[6] = {9, 10, 11, 12, 13, A0};

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
  for (int i = 0; i < 6; i++) {
    pinMode(digitPins[i], OUTPUT);
  }
  Wire.begin();
  rtc.begin();

  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, setting the time!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

}

void displayNumber(int digit, int number) {
  const byte segments[10][7] = {
    {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW},    // 0
    {LOW, HIGH, HIGH, LOW, LOW, LOW, LOW},       // 1
    {HIGH, HIGH, LOW, HIGH, HIGH, LOW, HIGH},    // 2
    {HIGH, HIGH, HIGH, HIGH, LOW, LOW, HIGH},    // 3
    {LOW, HIGH, HIGH, LOW, LOW, HIGH, HIGH},     // 4
    {HIGH, LOW, HIGH, HIGH, LOW, HIGH, HIGH},    // 5
    {HIGH, LOW, HIGH, HIGH, HIGH, HIGH, HIGH},   // 6
    {HIGH, HIGH, HIGH, LOW, LOW, LOW, LOW},      // 7
    {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH},  // 8
    {HIGH, HIGH, HIGH, HIGH, LOW, HIGH, HIGH}     // 9
  };

  // Turn off all digits
  for (int i = 0; i < 6; i++) {
    digitalWrite(digitPins[i], HIGH);
  }

  // Turn on the segments for the specific number
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], segments[number][i]);
  }

  // Turn on the specific digit
  digitalWrite(digitPins[digit], LOW);
  delay(5); // Briefly delay to show the digit
  digitalWrite(digitPins[digit], HIGH);
}

void loop() {
  DateTime now = rtc.now();  // Get the current time from the RTC

  int hour = now.hour();
  int minute = now.minute();
  int second = now.second();

  // Display hours
  displayNumber(0, hour / 10);
  displayNumber(1, hour % 10);

  // Display minutes
  displayNumber(2, minute / 10);
  displayNumber(3, minute % 10);

  // Display seconds
  displayNumber(4, second / 10);
  displayNumber(5, second % 10);
}
