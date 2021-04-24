#include <Servo.h>

// 3 servos share one signal pin so they all move together
// each button press sweeps them to the other end in 10 degree steps

Servo myservo;

#define servoPin 3
#define pushButtonPin 2

int angle = 0;
int angleStep = 10;
const int minAngle = 0;
const int maxAngle = 90;

int buttonPushed = 0;

void setup() {
  Serial.begin(9600);
  myservo.attach(servoPin);
  pinMode(pushButtonPin, INPUT_PULLUP);   // pressed = LOW
  myservo.write(angle);
}

void loop() {
  if (digitalRead(pushButtonPin) == LOW) {
    buttonPushed = 1;
  }

  if (buttonPushed == 1) {
    angle = angle + angleStep;

    // stop at the end and turn around for the next press
    if (angle >= maxAngle) {
      angle = maxAngle;
      angleStep = -angleStep;
      buttonPushed = 0;
    }
    if (angle <= minAngle) {
      angle = minAngle;
      angleStep = -angleStep;
      buttonPushed = 0;
    }

    myservo.write(angle);
    Serial.println(angle);
    delay(100);
  }
}
