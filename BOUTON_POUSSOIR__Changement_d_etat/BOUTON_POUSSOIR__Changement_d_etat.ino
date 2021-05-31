#define button 2

// Variables will change:
int lastState = HIGH; // the previous state from the input pin
int currentState;    // the current reading from the input pin

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // initialize the pushbutton pin as an pull-up input
  // the pull-up input pin will be HIGH when the switch is open and LOW when the switch is closed.
  pinMode(button, INPUT);
}

void loop() {
  // read the state of the switch/button:
  delay(500);
  currentState = digitalRead(button);

  if(lastState == LOW && currentState == HIGH)
    Serial.println("L'etat du bouton a change du bas vers le haut.");

  // save the the last state
  lastState = currentState;
}
