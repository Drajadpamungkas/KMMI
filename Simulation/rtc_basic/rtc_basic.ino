#include <Wire.h>
#include "RTClib.h"

RTC_DS1307 rtc;

void setup ()
{
  Serial.begin(9600);
  Wire.begin();
  rtc.begin();

  if (! rtc.isrunning())
  {
    Serial.println("RTC is not running!");
  }
  else
  {
    Serial.println("RTC is running");
  }
}

void loop ()
{
  DateTime now = rtc.now();
  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(' ');
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();
  delay(1000);
}
