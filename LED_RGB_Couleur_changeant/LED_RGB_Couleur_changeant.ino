#define led_red 5
#define led_green 6
#define led_blue 9

#define potentiometre A0

int potentiometre_value = 0;  // variable to store the value coming from the sensor

void setup(){
  //set led as output
   pinMode(led_red , OUTPUT);
  pinMode(led_green , OUTPUT);
    pinMode(led_blue , OUTPUT);
     
}

void loop() {

   potentiometre_value = map(analogRead(potentiometre), 0, 1023, 0 , 255);

   analogWrite(led_red,  potentiometre_value);
   analogWrite(led_green, 255-potentiometre_value);
   analogWrite(led_blue, potentiometre_value*2);
   delay(10);
        
}
