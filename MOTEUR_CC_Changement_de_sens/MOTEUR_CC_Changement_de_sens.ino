// Motor  connections
int motor_en = 9;
int motor_in1 = 11;
int motor_in2 = 12;

void setup() {
  // Set all the motor control pins to outputs
  pinMode(motor_en, OUTPUT);
  pinMode(motor_in1, OUTPUT);
  pinMode(motor_in2, OUTPUT);
  
  // Turn off motors - Initial state
  digitalWrite(motor_in1, LOW);
  digitalWrite(motor_in2, LOW);
}

void loop() {
  directionControl();
  delay(1000);
 
}

// This function lets you control spinning direction of motors
void directionControl() {
  // Set motor to maximum speed
  // For PWM maximum possible values are 0 to 255
  analogWrite(motor_en, 100);

  // Turn on motor 
  digitalWrite(motor_in1, HIGH);
  digitalWrite(motor_in2, LOW);
  delay(2000);

  // Turn off motors
  digitalWrite(motor_in1, LOW);
  digitalWrite(motor_in2, LOW);
  delay(2000);
  
  // Now change motor directions
  digitalWrite(motor_in1, LOW);
  digitalWrite(motor_in2, HIGH);
  delay(2000);

  // Turn off motors
  digitalWrite(motor_in1, LOW);
  digitalWrite(motor_in2, LOW);
  delay(2000);
  
}

  
