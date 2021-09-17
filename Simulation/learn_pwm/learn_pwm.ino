#include <LiquidCrystal.h>
LiquidCrystal lang (2, 3, 4, 5, 6, 7);

void setup()
{
  lang.begin(16, 2);
  lang.setCursor(0, 0);
  lang.print("Arduino PWM");
  delay(2000);
  lang.clear();
}

void loop()
{
  int adc = analogRead(A0);
  int pwm = map(adc, 0, 1023, 0, 255);
  int dutyCycle = map(pwm, 0, 255, 0, 100);
  analogWrite(11, pwm);
  delay(10);
  lang.setCursor(0, 0);
  lang.print("Nilai PWM ");
  lang.print(pwm);
  lang.setCursor(0, 1);
  lang.print("Duty Cycle ");
  lang.print(dutyCycle);
  lang.print("%  ");
}
