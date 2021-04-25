#include <Keypad.h>

// two DC motors through the L293D, driven from a 4x4 keypad
// 2 = forward, 8 = back, 4 = left, 6 = right, 0 = stop

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad kpd = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// left motor on 11 (forward) and 10 (back)
// right motor on 12 (forward) and 13 (back)
int leftFwd = 11;
int leftBack = 10;
int rightFwd = 12;
int rightBack = 13;

void setup() {
  Serial.begin(9600);
  pinMode(leftFwd, OUTPUT);
  pinMode(leftBack, OUTPUT);
  pinMode(rightFwd, OUTPUT);
  pinMode(rightBack, OUTPUT);
}

void loop() {
  char key = kpd.getKey();

  if (key == '2') {
    Serial.println("Forward");
    drive(HIGH, LOW, HIGH, LOW);
  }
  if (key == '8') {
    Serial.println("Back");
    drive(LOW, HIGH, LOW, HIGH);
  }
  if (key == '4') {
    Serial.println("Left");
    drive(LOW, LOW, HIGH, LOW);    // only right motor runs
  }
  if (key == '6') {
    Serial.println("Right");
    drive(HIGH, LOW, LOW, LOW);    // only left motor runs
  }
  if (key == '0') {
    Serial.println("Stop");
    drive(LOW, LOW, LOW, LOW);
  }
}

void drive(int lf, int lb, int rf, int rb)
{
  digitalWrite(leftFwd, lf);
  digitalWrite(leftBack, lb);
  digitalWrite(rightFwd, rf);
  digitalWrite(rightBack, rb);
}
