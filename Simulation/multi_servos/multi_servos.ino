#include <Servo.h>
int adc, deg;
Servo feli;

void setup()
{
  Serial.begin(9600);
  Serial.println("Arduino servo");
  delay(100);
}

void loop()
{
  adc = analogRead(A0);
  deg = map(adc, 0, 1023, 0, 180);
  servo1();
  servo2();
  delay(1000);
}

void servo1()
{
  feli.attach(8);
  feli.write(deg);
  Serial.print("Sudut servo 1 ");
  Serial.print(deg);
  Serial.println(" derajat");
  delay(100);
  feli.detach();
}

void servo2()
{
  feli.attach(9);
  deg = 180 - deg;
  feli.write(deg);
  Serial.print("Sudut servo 2 ");
  Serial.print(deg);
  Serial.println(" derajat");
  delay(100);
  feli.detach();
}
