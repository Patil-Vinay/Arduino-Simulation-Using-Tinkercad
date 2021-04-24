// HC-SR04 used like a digital obstacle sensor
// prints 0 when something is 3 cm or closer, otherwise 1

#define echoPin 2
#define trigPin 3

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // 10 us pulse on trig
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // sound travels 0.034 cm/us, divide by 2 for going and coming back
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  if (distance <= 3) {
    Serial.println("0");
  }
  else {
    Serial.println("1");
  }
  delay(100);
}
