#define led 13
#define button_1 2
#define button_2 3

// Variables will change:
int lastState_1 = HIGH; // the previous state from the button_1
int currentState_1;    // the current reading from the button_1

int lastState_2 = LOW; // the previous state from the button_2
int currentState_2;    // the current reading from the button_2

void setup() {
   pinMode(led, OUTPUT);

  // initialize the pushbutton pin1 as an pull-up input
  // the pull-up input pin will be HIGH when the switch is open and LOW when the switch is closed.
  pinMode(button_1, INPUT);

    // initialize the pushbutton pin2 as an pull-down input
  // the pull-up input pin will be LOW when the switch is open and HIGH when the switch is closed.
  pinMode(button_2, INPUT);

   digitalWrite(led, LOW); //Shut down the led first

}

void loop() {
  // read the state of the buttons:
  currentState_1 = digitalRead(button_1);
  currentState_2 = digitalRead(button_2);

  if(lastState_1 == LOW && currentState_1 == HIGH)
    digitalWrite(led, HIGH);
  if(lastState_2 == HIGH && currentState_2 == LOW)
    digitalWrite(led, LOW);

  // save the the last state
  lastState_1 = currentState_1;
  lastState_2 = currentState_2;
}
