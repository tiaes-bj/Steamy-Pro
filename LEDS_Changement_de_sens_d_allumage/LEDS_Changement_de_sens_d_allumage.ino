#define led_green 5
#define led_yellow 12
#define led_red 13
#define button_1 2
#define button_2 3

// Variables will change:
int lastState_1 = HIGH; // the previous state from the button_1
int currentState_1;    // the current reading from the button_1

int lastState_2 = LOW; // the previous state from the button_2
int currentState_2;    // the current reading from the button_2

bool sens1=false;
bool sens2=false;

void setup(){
  //set led as output
  pinMode(led_green , OUTPUT);
    pinMode(led_yellow , OUTPUT);
      pinMode(led_red , OUTPUT);

       // initialize the pushbutton pin1 as an pull-up input
  // the pull-up input pin will be HIGH when the switch is open and LOW when the switch is closed.
  pinMode(button_1, INPUT);

    // initialize the pushbutton pin2 as an pull-down input
  // the pull-up input pin will be LOW when the switch is open and HIGH when the switch is closed.
  pinMode(button_2, INPUT);

   digitalWrite(led_green, LOW); //Shut down the leds first
    digitalWrite(led_yellow, LOW); 
 digitalWrite(led_red, LOW); 
}

void loop() {
  // read the state of the buttons:
  currentState_1 = digitalRead(button_1);
  currentState_2 = digitalRead(button_2);
  delay(100);

  if(lastState_1 == LOW && currentState_1 == HIGH)
     {sens1 = true;
      sens2 = false;}
  if(lastState_2 == HIGH && currentState_2 == LOW)
      {sens1 =false ;
      sens2 = true;}
    

   if(sens1)  tourner_sens1();
    if(sens2)  tourner_sens2();

  // save the the last state
  lastState_1 = currentState_1;
  lastState_2 = currentState_2;
}

void tourner_sens1 (){
  digitalWrite(led_green, HIGH);
  digitalWrite(led_yellow, LOW);
  digitalWrite(led_red, LOW);
  delay(500);
  //wait 500 ms

  digitalWrite(led_green,LOW);
  digitalWrite(led_yellow, HIGH);
  digitalWrite(led_red, LOW);
  delay(500);
  //wait 500 ms

  digitalWrite(led_green,LOW );
  digitalWrite(led_yellow, LOW);
  digitalWrite(led_red,HIGH );
  delay(500);
  //wait 500 ms
}

void tourner_sens2 (){
  digitalWrite(led_green, HIGH);
  digitalWrite(led_yellow, LOW);
  digitalWrite(led_red, LOW);
  delay(500);
  //wait 500 ms

 digitalWrite(led_green,LOW );
  digitalWrite(led_yellow, LOW);
  digitalWrite(led_red,HIGH );
  delay(500);
  //wait 500 ms
  
  digitalWrite(led_green,LOW);
  digitalWrite(led_yellow, HIGH);
  digitalWrite(led_red, LOW);
  delay(500);
  //wait 500 ms

 
}
