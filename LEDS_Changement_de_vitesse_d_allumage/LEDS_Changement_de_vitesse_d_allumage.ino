#define led_green 5
#define led_yellow 12
#define led_red 13
#define potentiometre A0

int potentiometre_value = 0;  // variable to store the value coming from the sensor

void setup(){
  //set led as output
  pinMode(led_green , OUTPUT);
    pinMode(led_yellow , OUTPUT);
      pinMode(led_red , OUTPUT);
}

void loop() {
  // read the value from the potentiometre:
  potentiometre_value = analogRead(potentiometre);

  tourner_led (potentiometre_value);
}

void tourner_led (int delay_time){
  digitalWrite(led_green, HIGH);
  digitalWrite(led_yellow, LOW);
  digitalWrite(led_red, LOW);
  delay(delay_time);
  
  digitalWrite(led_green,LOW);
  digitalWrite(led_yellow, HIGH);
  digitalWrite(led_red, LOW);
  delay(delay_time);

  digitalWrite(led_green,LOW );
  digitalWrite(led_yellow, LOW);
  digitalWrite(led_red,HIGH );
  delay(delay_time);
 
}
