#define light_sensor A0

void setup(){
Serial.begin(9600);     // Communication started with 9600 baud
}
void loop(){
int light_value=analogRead(light_sensor); // Incoming analog signal read and appointed    //sensor
Serial.println(light_value);   //Wrote serial port
delay(1000);
}
