#include <Wire.h>
#include "RTClib.h"

RTC_DS3231 rtc;

int buzzer = 7;

void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);

  rtc.begin();

  // Set time once (comment after upload)
  // rtc.adjust(DateTime(F(_DATE), F(TIME_)));
}

void loop() {
  DateTime now = rtc.now();

  if (now.hour() == 10 && now.minute() == 0) {
    digitalWrite(buzzer, HIGH);
    delay(5000); // ring for 5 sec
    digitalWrite(buzzer, LOW);
  }

  delay(1000);
}