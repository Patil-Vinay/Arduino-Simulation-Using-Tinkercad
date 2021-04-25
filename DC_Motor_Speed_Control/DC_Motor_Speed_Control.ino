// DC motor speed control with a potentiometer through the L293D
// pot on A0, PWM on pin 9 (input 1), pin 6 stays LOW (input 2)

int potPin = A0;
int motorPin1 = 9;
int motorPin2 = 6;
int potValue;
int motorValue;

void setup() {
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  potValue = analogRead(potPin);
  motorValue = map(potValue, 0, 1023, 0, 255);

  analogWrite(motorPin1, motorValue);
  digitalWrite(motorPin2, LOW);

  Serial.println(motorValue);
  delay(100);
}
