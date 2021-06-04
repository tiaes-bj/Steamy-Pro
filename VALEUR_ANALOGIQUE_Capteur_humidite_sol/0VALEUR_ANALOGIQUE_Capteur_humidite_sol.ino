#define capacitive_sensor A1

void setup(){
Serial.begin(9600);     // Communication started with 9600 baud
}
void loop(){
int capacitive_value=analogRead(capacitive_sensor); // Incoming analog signal read and appointed    //sensor
Serial.println(capacitive_value);   //Wrote serial port
delay(1000);
}
