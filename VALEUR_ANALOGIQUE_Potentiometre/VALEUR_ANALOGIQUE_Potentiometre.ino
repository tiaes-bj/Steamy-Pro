#define potentiometre A0

void setup(){
Serial.begin(9600);     // Communication started with 9600 baud
}
void loop(){
int potentiometre_value=analogRead(potentiometre); // Incoming analog signal read and appointed    //sensor
Serial.println(potentiometre_value);   //Wrote serial port
delay(1000);
}
