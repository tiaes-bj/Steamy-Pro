#define potentiometre A0

#define led 13

void setup(){
 pinMode(led , OUTPUT);  
}

void loop(){
int pot_value=analogRead(potentiometre ); // Incoming analog signal read and appointed    //sensor

int delay_value = map(pot_value, 0 , 1023 , 0 , 2000);

digitalWrite(led,HIGH);
delay(delay_value);
digitalWrite(led,LOW);
delay(delay_value);

}
