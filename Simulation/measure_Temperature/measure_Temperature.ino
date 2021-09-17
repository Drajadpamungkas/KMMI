#include <LiquidCrystal.h>

LiquidCrystal lang(4, 5, 6, 7, 8, 9);

int lm35 = A0;
int val = 0;
float temp;

void setup()
{
  pinMode(A0, INPUT);
  pinMode(10, OUTPUT);
  lang.begin(16, 2);
  lang.setCursor(0, 0);
  lang.print("Arduino");
  lang.setCursor(0, 1);
  lang.print("Pengukur Suhu");
  delay(1000);
  lang.clear();
}

void loop()
{
  val = analogRead(lm35);
  delay(100);
  lang.setCursor(0, 0);
  lang.print("Suhu celsius:");
  lang.setCursor(0, 1);
  temp = val * 5;
  temp *= 100;
  temp /= 1024;
  lang.print(temp);
}
