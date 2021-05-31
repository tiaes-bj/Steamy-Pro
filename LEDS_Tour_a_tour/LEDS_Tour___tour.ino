#define led_green 5
#define led_yellow 12
#define led_red 13

void setup(){
  //set leds as output
  pinMode(led_green , OUTPUT);
    pinMode(led_yellow , OUTPUT);
      pinMode(led_red , OUTPUT);

}
void loop(){

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
