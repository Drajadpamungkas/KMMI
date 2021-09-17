void setup()
{
  DDRD = 255;
}

void loop()
{
  int i;
  int lsb = 0b00000001;
  int msb = 0b10000000;
  byte dataLED;
  for (i = 0; i < 8; i++)
  {
    dataLED = ((lsb << i) | (msb >> i));
    PORTD = dataLED;
    delay(1000);
  }
}
