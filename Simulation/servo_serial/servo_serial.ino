#include <Servo.h>

Servo feli;
int val;

void setup()
{
  val =0;
  feli.attach(9);
  Serial.begin(9600);
}

void loop()
{
  val = analogRead(A0);
  val = map(val, 0, 1023, 0, 180);
  feli.write(val);
  int data = feli.read();
  Serial.print("Sudut servo ");
  Serial.println(data);
  delay(600);
}

