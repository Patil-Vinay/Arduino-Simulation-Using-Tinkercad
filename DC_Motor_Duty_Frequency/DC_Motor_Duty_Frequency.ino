// DC motor with two pots
// pot on A0 sets the duty cycle, pot on A1 sets the PWM frequency
// PWM is done in software so the frequency can be changed

int pot_duty = A0;
int pot_pwm = A1;
int motorPin = 9;

int duty;        // 0 - 100 %
int freq;        // Hz
long period;     // us
long onTime;     // us
unsigned long lastRead = 0;
unsigned long lastPrint = 0;

void setup() {
  Serial.begin(9600);
  pinMode(motorPin, OUTPUT);
  readPots();
}

void loop() {
  // reading the pots takes time, so only do it every 100 ms
  // otherwise every PWM cycle gets longer and the duty is wrong
  if (millis() - lastRead > 100) {
    lastRead = millis();
    readPots();
  }

  // one PWM cycle
  if (onTime > 0) {
    digitalWrite(motorPin, HIGH);
    delayMicroseconds(onTime);
  }
  if (onTime < period) {
    digitalWrite(motorPin, LOW);
    delayMicroseconds(period - onTime);
  }

  // print the settings twice a second
  if (millis() - lastPrint > 500) {
    lastPrint = millis();
    Serial.print("Duty: ");
    Serial.print(duty);
    Serial.print(" %  Freq: ");
    Serial.print(freq);
    Serial.println(" Hz");
  }
}

void readPots() {
  duty = map(analogRead(pot_duty), 0, 1023, 0, 100);
  freq = map(analogRead(pot_pwm), 0, 1023, 100, 1000);

  period = 1000000L / freq;
  onTime = period * duty / 100;
}
