#include <LiquidCrystalSPI.h>
#include <SPI.h>

LiquidCrystalSPI lcd(10);

void setup()
{
  lcd.begin(16, 2);
  lcd.print("Hello world!");
  delay(1000);
  lcd.clear();
}

void loop()
{
  lcd.setCursor(0, 0);
  lcd.print("Arduino SPI");
  lcd.setCursor(0, 1);
  lcd.print("74HC595");
}
