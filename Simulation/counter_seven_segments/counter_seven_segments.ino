#define A 7
#define B 6
#define C 5
#define D 4
const int segs[4] = {A, B, C, D};
int CA1 = 12;
int CA2 = 13;
int numbers[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

void setup()
{
  DDRD = B11110000;
  pinMode(CA1, OUTPUT);
  pinMode(CA2, OUTPUT);
}
void loop()
{
  for (int digit1 = 0; digit1 < 10; digit1++)
  {
    for (int digit2 = 0; digit2 < 10; digit2++)
    {
      unsigned long startTime = millis();
      for (unsigned long elapsed = 0; elapsed < 600; elapsed = millis() - startTime)
      {
        lightDigit1(numbers[digit1]);
        delay(500);
        lightDigit2(numbers[digit2]);
        delay(500);
      }
    }
  }
}

void lightDigit1(byte number)
{
  digitalWrite(CA1, LOW);
  digitalWrite(CA2, HIGH);
  lightSegments(number);
}

void lightDigit2(byte number)
{
  digitalWrite(CA1, HIGH);
  digitalWrite(CA2, LOW);
  lightSegments(number);
}

void lightSegments(byte number)
{
  for (int i = 0; i < 4; i++)
  {
    int bit = bitRead(number, i);
    digitalWrite(segs[i], bit);
  }
}
