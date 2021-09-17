#include <Keypad.h>
const byte ROWS = 4;
const byte COLS = 3;
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte rowPins[ROWS] = {4, 3, 2, 1};
byte colPins[COLS] = {5, 6, 7};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

int last;

void setup()
{
  last = 0;
}

void loop()
{
  DDRB = 15;
  char customKey = customKeypad.getKey();

  switch (customKey)
  {
    case '1':
      PORTB = 8;
      last = PORTB;
      break;

    case '2':
      PORTB = 4;
      last = PORTB;
      break;

    case '3':
      PORTB = 12;
      last = PORTB;
      break;

    case '4':
      PORTB = 2;
      last = PORTB;
      break;

    case '5':
      PORTB = 10;
      last = PORTB;
      break;

    case '6':
      PORTB = 6;
      last = PORTB;
      break;

    case '7':
      PORTB = 14;
      last = PORTB;
      break;

    case '8':
      PORTB = 1;
      last = PORTB;
      break;

    case '9':
      PORTB = 9;
      last = PORTB;
      break;

    case '0':
      PORTB = 0;
      last = PORTB;
      break;

    case '*':
      PORTB = last;
      break;

    case '#':
      PORTB = 15;
      break;
  }
}
