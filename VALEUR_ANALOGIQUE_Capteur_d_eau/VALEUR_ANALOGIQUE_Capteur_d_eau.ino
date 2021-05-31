#define water_sensor A1

void setup(){
Serial.begin(9600);     // Communication started with 9600 baud
}
void loop(){
int water_value=analogRead(water_sensor); // Incoming analog signal read and appointed    //sensor
Serial.println(water_value);   //Wrote serial port
delay(1000);
}
