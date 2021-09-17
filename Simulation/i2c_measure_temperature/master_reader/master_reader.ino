#include <Wire.h>
#define slave 0
#define byteData 6

void setup()
{
  Wire.begin();
  Serial.begin(9600);
}

void loop()
{
  Wire.requestFrom(slave, byteData);
  while(Wire.available())
  {
    char data = Wire.read();
    Serial.print(data);
  }
  Serial.println();
  delay(500);
}
