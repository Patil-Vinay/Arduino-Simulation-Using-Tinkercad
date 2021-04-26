#include <Servo.h>

// 3 servos on pin 3 move together, 1 servo on pin 9 moves on its own
// button on pin 2 steps the group, button on pin 4 steps the single servo

Servo commonservo;
Servo servo;

int commonservoPin = 3;
int servoPin = 9;
int commonbuttonpin = 2;
int buttonpin = 4;

int commonAngles[] = {0, 120, 30};
int angles[] = {0, 20, 90};

int commoncount = 0;
int count = 0;
int lastCommon = LOW;
int last = LOW;

void setup()
{
  pinMode(commonbuttonpin, INPUT);   // 1k pull-down, pressed = HIGH
  pinMode(buttonpin, INPUT);
  commonservo.attach(commonservoPin);
  servo.attach(servoPin);
  commonservo.write(0);
  servo.write(0);
  Serial.begin(9600);
}

void loop()
{
  int commonbtst = digitalRead(commonbuttonpin);
  int btst = digitalRead(buttonpin);

  // count only when the button goes from released to pressed
  if (commonbtst == HIGH && lastCommon == LOW) {
    commoncount = (commoncount + 1) % 3;
    commonservo.write(commonAngles[commoncount]);
    Serial.print("Group: ");
    Serial.println(commonAngles[commoncount]);
  }

  if (btst == HIGH && last == LOW) {
    count = (count + 1) % 3;
    servo.write(angles[count]);
    Serial.print("Single: ");
    Serial.println(angles[count]);
  }

  lastCommon = commonbtst;
  last = btst;
  delay(50);   // debounce
}
