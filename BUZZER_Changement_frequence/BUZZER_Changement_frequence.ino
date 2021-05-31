//assign buzzer as pin 10
#define buzzer 10                

#define potentiometre A0

int potentiometre_value = 0;  // variable to store the value coming from the sensor

void setup()
{
  
}

void loop() {

   potentiometre_value = map(analogRead(potentiometre), 0, 1023, 0 , 2000);

  //tone(pin, frequency, duration);
  //set buzzer pin to play 264Hz for 300ms
  tone(buzzer,   potentiometre_value, 300);
  
        
}
