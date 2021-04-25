// run the DC motor at the speed (rpm) typed in the serial monitor
// PWM on pin 9 goes to the L293D, motor runs from the 9 V battery

// rpm shown by Tinkercad for some PWM values, used to turn rpm into PWM
int pwmTable[] = {0, 10, 25, 50, 100, 150, 200, 255};
long rpmTable[] = {0, 1078, 2668, 4887, 9600, 14678, 18989, 25714};

long rpm = 0;
int pwm = 0;

void setup() {
  pinMode(9, OUTPUT);
  Serial.begin(9600);
  Serial.println("Enter speed in rpm (0 - 25000)");
}

void loop() {
  if (Serial.available() > 0) {
    rpm = Serial.parseInt();
    while (Serial.available() > 0) Serial.read();   // drop the newline

    pwm = rpmToPwm(rpm);
    analogWrite(9, pwm);

    Serial.print("rpm: ");
    Serial.print(rpm);
    Serial.print("  pwm: ");
    Serial.println(pwm);
  }
}

int rpmToPwm(long r)
{
  if (r <= 0) return 0;

  // straight line between the two nearest points of the table
  for (int i = 1; i < 8; i++) {
    if (r <= rpmTable[i]) {
      return pwmTable[i - 1] + (r - rpmTable[i - 1]) * (pwmTable[i] - pwmTable[i - 1]) / (rpmTable[i] - rpmTable[i - 1]);
    }
  }
  return 255;   // more than the motor can do
}
