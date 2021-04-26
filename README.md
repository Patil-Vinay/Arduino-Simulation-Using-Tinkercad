# Arduino Simulation Using Tinkercad

I started learning Arduino on Autodesk Tinkercad Circuits. These are the circuits I made while learning,
each one solving a small problem statement.

Every folder has:

- the sketch (`.ino`)
- `circuit.png`, the circuit from Tinkercad
- a `README.md` with the problem statement, parts, pin connections and how the code works

All of them were run in the Tinkercad simulator.

## Projects

| Project | What it does |
|---------|--------------|
| [LED_Bar_Push_Buttons](LED_Bar_Push_Buttons) | 5 buttons light 1 to 5 LEDs like a level bar |
| [Servo_Sweep_Push_Button](Servo_Sweep_Push_Button) | each button press sweeps 3 servos between 0 and 90 degrees |
| [Potentiometer_Voltage](Potentiometer_Voltage) | reads a pot on A3 and prints the voltage, checked with a multimeter |
| [LED_Ring_Patterns](LED_Ring_Patterns) | 12 LEDs in a ring, pattern picked from the Serial Monitor |
| [Keypad_LCD_Calculator](Keypad_LCD_Calculator) | calculator with a 4x4 keypad and 16x2 LCD |
| [Ultrasonic_Object_Detector](Ultrasonic_Object_Detector) | HC-SR04 gives 0 when something is within 3 cm, else 1 |
| [Seven_Segment_CD4511](Seven_Segment_CD4511) | counts 0 to 9 on a 7 segment display using a CD4511 |
| [DC_Motor_Speed_Control](DC_Motor_Speed_Control) | motor speed from a pot through an L293D |
| [Keypad_Robot_Car](Keypad_Robot_Car) | two motor car driven from a keypad |
| [DC_Motor_RPM_Serial](DC_Motor_RPM_Serial) | motor runs at the rpm typed in the Serial Monitor |
| [DC_Motor_Duty_Frequency](DC_Motor_Duty_Frequency) | one pot for duty cycle, one pot for PWM frequency |
| [Servo_Group_Two_Buttons](Servo_Group_Two_Buttons) | 3 servos as a group and 1 single servo, each stepped by its own button |
| [Servo_Group_One_Button](Servo_Group_One_Button) | same servos stepped together by one button |
| [Four_Side_Obstacle_Warning](Four_Side_Obstacle_Warning) | 4 ultrasonic sensors with RGB LEDs and buzzers for front, back, left and right |

## Trying a project

In Tinkercad:

1. Make a new circuit and build it from `circuit.png` and the connection table in the project README.
2. Open Code, switch it to Text and paste the `.ino` file.
3. Start Simulation. For buttons and keypads, click on them; for ultrasonic sensors, click the sensor and drag the target.

On a real board, open the `.ino` in the Arduino IDE. Servo and LiquidCrystal come with the IDE.
The two keypad projects need the Keypad library by Mark Stanley and Alexander Brevig (Library Manager).
