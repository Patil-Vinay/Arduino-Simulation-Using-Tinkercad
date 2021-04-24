// 12 LEDs in a ring on pins 2 to 13
// type 1, 2, 3 or 4 in the serial monitor to pick a pattern

int number = 0;

void setup()
{
  for (int pin = 2; pin <= 13; pin++) {
    pinMode(pin, OUTPUT);
  }
  Serial.begin(9600);
  Serial.println("Enter 1, 2, 3 or 4");
}

void loop()
{
  if (Serial.available() > 0) {
    number = Serial.parseInt();

    switch (number) {
      case 1:   // one LED goes round
        for (int pin = 2; pin <= 13; pin++) {
          digitalWrite(pin, HIGH);
          delay(200);
          digitalWrite(pin, LOW);
        }
        break;

      case 2:   // same but the other way
        for (int pin = 13; pin >= 2; pin--) {
          digitalWrite(pin, HIGH);
          delay(200);
          digitalWrite(pin, LOW);
        }
        break;

      case 3:   // all LEDs blink 5 times
        for (int v = 0; v < 5; v++) {
          allLeds(HIGH);
          delay(500);
          allLeds(LOW);
          delay(500);
        }
        break;

      case 4:   // odd and even LEDs take turns, 5 times
        for (int v = 0; v < 5; v++) {
          for (int pin = 3; pin <= 13; pin += 2) digitalWrite(pin, HIGH);
          delay(500);
          for (int pin = 3; pin <= 13; pin += 2) digitalWrite(pin, LOW);
          for (int pin = 2; pin <= 12; pin += 2) digitalWrite(pin, HIGH);
          delay(500);
          for (int pin = 2; pin <= 12; pin += 2) digitalWrite(pin, LOW);
        }
        break;
    }
  }
}

void allLeds(int state)
{
  for (int pin = 2; pin <= 13; pin++) {
    digitalWrite(pin, state);
  }
}
