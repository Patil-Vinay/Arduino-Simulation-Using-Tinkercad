#include <LiquidCrystal.h>
#include <Keypad.h>

// RS, E, D4, D5, D6, D7  (A2, A1, A0, 13, 12, 11)
LiquidCrystal lcd(16, 15, 14, 13, 12, 11);

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

// A = +, B = -, C = *, D = /, # = equals, * = clear
long Num1, Num2, Number;
char key, action = ' ';
boolean result = false;
boolean error = false;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  DisplayResult();
}

void loop() {
  key = kpd.getKey();

  if (key != NO_KEY) {
    DetectButtons();
    DisplayResult();
  }
}

void Clear()
{
  Number = Num1 = Num2 = 0;
  action = ' ';
  result = false;
  error = false;
}

void DetectButtons()
{
  if (key == '*') {
    Serial.println("Button Cancel");
    Clear();
  }

  else if (key >= '0' && key <= '9') {
    Serial.print("Button ");
    Serial.println(key);
    if (result == true)   // new sum after the last answer
      Clear();
    Number = Number * 10 + (key - '0');
  }

  else if (key == 'A' || key == 'B' || key == 'C' || key == 'D') {
    if (key == 'A') { Serial.println("Addition"); action = '+'; }
    if (key == 'B') { Serial.println("Subtraction"); action = '-'; }
    if (key == 'C') { Serial.println("Multiplication"); action = '*'; }
    if (key == 'D') { Serial.println("Division"); action = '/'; }
    Num1 = Number;   // after = this carries the answer forward
    Num2 = 0;
    Number = 0;
    result = false;
    error = false;
  }

  else if (key == '#' && action != ' ') {
    Serial.println("Button Equal");
    Num2 = Number;
    CalculateResult();
    result = true;
  }
}

void CalculateResult()
{
  if (action == '+')
    Number = Num1 + Num2;

  if (action == '-')
    Number = Num1 - Num2;

  if (action == '*')
    Number = Num1 * Num2;

  if (action == '/') {
    if (Num2 == 0) {
      error = true;
      Number = 0;
    } else {
      Number = Num1 / Num2;
    }
  }
}

void DisplayResult()
{
  lcd.clear();

  // first line: the sum typed so far
  lcd.setCursor(0, 0);
  if (action != ' ') {
    lcd.print(Num1);
    lcd.print(action);
    if (result == true) {
      lcd.print(Num2);
      lcd.print(" =");
    }
  }

  // second line: number being typed or the answer
  lcd.setCursor(0, 1);
  if (error == true)
    lcd.print("Error: div by 0");
  else
    lcd.print(Number);
}
