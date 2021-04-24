// LED bar with 5 push buttons
// button 1 lights 1 LED, button 2 lights 2 LEDs ... button 5 lights all 5

int buttons[] = {12, 11, 10, 9, 8};
int leds[] = {7, 6, 5, 4, 3};   // green, yellow, blue, orange, red

void setup()
{
  for (int i = 0; i < 5; i++) {
    pinMode(buttons[i], INPUT);
    pinMode(leds[i], OUTPUT);
  }
}

void loop()
{
  // find the highest button that is pressed
  int level = 0;
  for (int i = 0; i < 5; i++) {
    if (digitalRead(buttons[i]) == HIGH) {
      level = i + 1;
    }
  }

  // turn on that many LEDs, rest off
  for (int i = 0; i < 5; i++) {
    if (i < level) {
      digitalWrite(leds[i], HIGH);
    } else {
      digitalWrite(leds[i], LOW);
    }
  }
}
