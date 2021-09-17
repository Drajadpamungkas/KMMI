int adc;
float volt;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  adc = analogRead(A0);
  volt = adc * (5.0 / 1023.0);
  Serial.print("Nilai ADC: ");
  Serial.println(adc);
  Serial.print("Nilai tegangan: ");
  Serial.println(volt);
  delay(1000);
}
