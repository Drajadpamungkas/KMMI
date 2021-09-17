#include <Wire.h>
#define deviceID 0

void setup()
{
  Wire.begin(deviceID);
  Serial.begin(9600);
}

void loop()
{
  delay(100);
  Wire.onRequest(requestEvent);
}

void requestEvent()
{
  int adc = analogRead(A0);
  int temp = (adc * 500 / 1023);
  String data = String(temp);
  char charBuf[8];
  data.toCharArray(charBuf, 3);
  Serial.println(charBuf);
  Wire.write(charBuf, 3);
}
