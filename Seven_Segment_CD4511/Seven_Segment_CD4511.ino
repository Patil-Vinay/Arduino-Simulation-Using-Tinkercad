// count 0 to 9 on a common cathode 7 segment display
// the CD4511 decoder takes the number in BCD so only 4 pins are used

#define PinA 4
#define PinB 5
#define PinC 6
#define PinD 7

void setup()
{
  pinMode(PinA, OUTPUT);
  pinMode(PinB, OUTPUT);
  pinMode(PinC, OUTPUT);
  pinMode(PinD, OUTPUT);
}

void loop()
{
  for (int n = 0; n <= 9; n++) {
    showDigit(n);
    delay(1000);
  }

  // CD4511 blanks the display for anything above 9
  showDigit(15);
  delay(1000);
}

void showDigit(int n)
{
  digitalWrite(PinA, bitRead(n, 0));
  digitalWrite(PinB, bitRead(n, 1));
  digitalWrite(PinC, bitRead(n, 2));
  digitalWrite(PinD, bitRead(n, 3));
}
