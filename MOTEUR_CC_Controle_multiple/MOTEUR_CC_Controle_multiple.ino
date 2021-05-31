// Motor  connections
int motor_en = 9;
int motor_in1 = 11;
int motor_in2 = 12;

#define button_1 2
#define button_2 3

#define potentiometre A0

int potentiometre_value = 0;  // variable to store the value coming from the sensor

// Variables will change:
int lastState_1 = HIGH; // the previous state from the button_1
int currentState_1;    // the current reading from the button_1

int lastState_2 = LOW; // the previous state from the button_2
int currentState_2;    // the current reading from the button_2

bool sens1 = false;
bool sens2 = false;

void setup(){
  

  // Set all the motor control pins to outputs
  pinMode(motor_en, OUTPUT);
  pinMode(motor_in1, OUTPUT);
  pinMode(motor_in2, OUTPUT);

       // initialize the pushbutton pin1 as an pull-up input
  // the pull-up input pin will be HIGH when the switch is open and LOW when the switch is closed.
  pinMode(button_1, INPUT);

    // initialize the pushbutton pin2 as an pull-down input
  // the pull-up input pin will be LOW when the switch is open and HIGH when the switch is closed.
  pinMode(button_2, INPUT);

    // Turn off motors - Initial state
  digitalWrite(motor_in1, LOW);
  digitalWrite(motor_in2, LOW);
}

void loop() {
potentiometre_value = analogRead(potentiometre);
  // read the state of the buttons:
  currentState_1 = digitalRead(button_1);
  currentState_2 = digitalRead(button_2);

  if(lastState_1 == LOW && currentState_1 == HIGH)
       {sens1 = true;
      sens2 = false;
      // Turn off motors
  digitalWrite(motor_in1, LOW);
  digitalWrite(motor_in2, LOW);
  delay(1000);}

  if(lastState_2 == HIGH && currentState_2 == LOW)
    {sens1 = false;
      sens2 = true;
        // Turn off motors
  digitalWrite(motor_in1, LOW);
  digitalWrite(motor_in2, LOW);
  delay(1000);}
      if(sens1)  tourner_sens1(potentiometre_value);
      if(sens2)  tourner_sens2(potentiometre_value);
  // save the the last state
  lastState_1 = currentState_1;
  lastState_2 = currentState_2;
}

void tourner_sens1 (int speed){
int motor_value = map( speed, 0, 1023, 0, 255);
 analogWrite(motor_en, motor_value);
  // Turn on motor 
  digitalWrite(motor_in1, HIGH);
  digitalWrite(motor_in2, LOW);
  delay(2000);
}
void tourner_sens2 (int speed){
int  motor_value = map( speed, 0, 1023, 0, 255);
 analogWrite(motor_en,motor_value);

  // Turn on motor 
  digitalWrite(motor_in1, LOW);
  digitalWrite(motor_in2, HIGH);
  delay(2000); 
}
