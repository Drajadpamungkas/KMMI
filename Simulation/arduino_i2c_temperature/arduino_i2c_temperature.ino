#include <Wire.h>

#define DEV_ID 0x90 >> 1
#define DEV_ID2 0x9E >> 1

void setup()
{
  Serial.begin(9600);
  Wire.begin();
  Wire.beginTransmission(DEV_ID);
  Wire.write(0xAC);
  Wire.write(0x02);
  Wire.beginTransmission(DEV_ID);
  Wire.write(0xEE);
  Wire.endTransmission();



  Wire.begin();
  Wire.beginTransmission(DEV_ID2);
  Wire.write(0xAC);
  Wire.write(0x02);
  Wire.beginTransmission(DEV_ID2);
  Wire.write(0xEE);
  Wire.endTransmission();
}


void loop()
{
  int8_t firstByte;
  int8_t secondByte;
  int8_t firstByte2;
  int8_t secondByte2;
  float temp = 0;
  float temp2 = 0;
  Wire.beginTransmission(DEV_ID);
  Wire.write(0xAA);
  Wire.endTransmission();
  Wire.requestFrom(DEV_ID, 2);
  firstByte = Wire.read();
  secondByte = Wire.read();
  temp = firstByte;

  Wire.beginTransmission(DEV_ID2);
  Wire.write(0xAA);
  Wire.endTransmission();
  Wire.requestFrom(DEV_ID2, 2);
  firstByte2 = Wire.read();
  secondByte2 = Wire.read();
  temp2 = firstByte2;
  if (secondByte)
  {
    temp += 0.5;
  }
  if (secondByte2)
  {
    temp2 += 0.5;
  }
  Serial.print("Temperature 1: ");
  Serial.println(temp);
  Serial.print("Temperature 2: ");
  Serial.println(temp2);
  delay(500);
}
