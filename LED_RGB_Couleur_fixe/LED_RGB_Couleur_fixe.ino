#define led_red 5
#define led_green 6
#define led_blue 9

int red_value = 200;
int green_value = 100;
int blue_value = 10;

void setup(){
  //set led as output
   pinMode(led_red , OUTPUT);
  pinMode(led_green , OUTPUT);
    pinMode(led_blue , OUTPUT);
     
}

void loop() {
   analogWrite(led_red,   red_value);
  analogWrite(led_green, green_value);
  analogWrite(led_blue,  blue_value);
}
