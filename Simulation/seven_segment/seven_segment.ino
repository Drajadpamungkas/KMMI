#include <SegDisplay.h>

SegNumbers segdisp(7, 6, 5, 4, 3);

void setup()
{
}

void loop()
{
  segdisp.off();
  delay(200);
  segdisp.zero();
  delay(200);
  segdisp.one();
  delay(200);
  segdisp.two();
  delay(200);
  segdisp.three();
  delay(200);
  segdisp.four();
  delay(200);
  segdisp.five();
  delay(200);
  segdisp.six();
  delay(200);
  segdisp.seven();
  delay(200);
  segdisp.eight();
  delay(200);
  segdisp.nine();
  delay(200);
}
