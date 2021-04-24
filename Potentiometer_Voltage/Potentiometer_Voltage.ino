// read the pot on A3 and print its voltage
// check the value against the multimeter

int potPin = A3;
int value = 0;
float voltage = 0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  value = analogRead(potPin);          // 0 to 1023
  voltage = value * 5.0 / 1023.0;      // 0 to 5 V

  Serial.print("ADC: ");
  Serial.print(value);
  Serial.print("  Voltage: ");
  Serial.println(voltage);
  delay(500);
}
