// obstacle warning on all 4 sides with 4 ultrasonic sensors (3 pin PING)
// RGB LED of each side: green = 200 cm or more, yellow = 75 to 200 cm, red = under 75 cm
// the buzzer of a side beeps while that side is red
// blue legs of the RGB LEDs are not used

// sides in order: front, back, left, right
int usPin[4]    = {3, 9, 2, 1};
int buzzer[4]   = {6, 5, 4, 7};
int redPin[4]   = {11, 17, 8, 14};
int greenPin[4] = {13, 19, 10, 16};

long cm[4];

void setup()
{
  for (int i = 0; i < 4; i++) {
    pinMode(buzzer[i], OUTPUT);
    pinMode(redPin[i], OUTPUT);
    pinMode(greenPin[i], OUTPUT);
  }
}

void loop()
{
  for (int i = 0; i < 4; i++) {
    cm[i] = 0.01723 * readUltrasonic(usPin[i]);

    if (cm[i] >= 200) {
      setColor(i, LOW, HIGH);      // green
    }
    else if (cm[i] >= 75) {
      setColor(i, HIGH, HIGH);     // yellow
    }
    else {
      setColor(i, HIGH, LOW);      // red
    }
  }

  // short beep on every side that is too close
  for (int i = 0; i < 4; i++) {
    if (cm[i] < 75) {
      tone(buzzer[i], 1000, 100);
      delay(150);
    }
  }
}

// PING uses the same pin for trigger and echo
long readUltrasonic(int pin)
{
  pinMode(pin, OUTPUT);
  digitalWrite(pin, LOW);
  delayMicroseconds(2);
  digitalWrite(pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pin, LOW);
  pinMode(pin, INPUT);
  return pulseIn(pin, HIGH);
}

void setColor(int side, int r, int g)
{
  digitalWrite(redPin[side], r);
  digitalWrite(greenPin[side], g);
}
