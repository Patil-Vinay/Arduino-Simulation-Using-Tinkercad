#include <Servo.h>

// 3 servos on pin 3 move together, 1 servo on pin 9 moves on its own
// one button on pin 2 steps both through 3 positions

Servo commonservo;
Servo servo;

int commonservoPin = 3;
int servoPin = 9;
int buttonpin = 2;

// position 0, 1, 2 for the group and the single servo
int commonAngles[] = {0, 120, 30};
int angles[] = {0, 20, 90};

int count = 0;
int last = LOW;

void setup()
{
  pinMode(buttonpin, INPUT);   // 1k pull-down, pressed = HIGH
  commonservo.attach(commonservoPin);
  servo.attach(servoPin);
  commonservo.write(0);
  servo.write(0);
  Serial.begin(9600);
}

void loop()
{
  int btst = digitalRead(buttonpin);

  // count only when the button goes from released to pressed
  if (btst == HIGH && last == LOW) {
    count = (count + 1) % 3;
    commonservo.write(commonAngles[count]);
    servo.write(angles[count]);
    Serial.println(count);
  }

  last = btst;
  delay(50);   // debounce
}
