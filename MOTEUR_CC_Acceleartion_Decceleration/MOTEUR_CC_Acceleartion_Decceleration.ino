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
  speedControl();
  delay(1000);
 
}


// This function lets you control speed of the motors
void speedControl() {
  // Turn on motors
  digitalWrite(motor_in1, LOW);
  digitalWrite(motor_in2, HIGH);
  
  // Accelerate from zero to maximum speed
  for (int i = 0; i < 256; i++) {
    analogWrite(motor_en, i);
    delay(100);
  }
  
  // Decelerate from maximum speed to zero
  for (int i = 255; i >= 0; --i) {
    analogWrite(motor_en, i);
    delay(100);
  }
  
  // Now turn off motors
  digitalWrite(motor_in1, LOW);
  digitalWrite(motor_in2, LOW);
}
