#include <Servo.h>

#define potentiometre A0

Servo myservo;  // create servo object to control a servo

int motor_value;    // variable to read the value from the analog pin

void setup() {
  myservo.attach(11);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  motor_value = map( analogRead(potentiometre), 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo.write(motor_value);                  // sets the servo position according to the scaled value
  delay(15);                           // waits for the servo to get there
}
