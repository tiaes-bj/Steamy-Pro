//assign led as pin 13
#define led 13
 
void setup()
{
  //set led as output
  pinMode(led, OUTPUT);
}
 
void loop()
{ //turn on led(set logic level high)
  digitalWrite(led, HIGH);
  //wait 500 ms
  delay(500);
  //turn off led(set logic level low)
  digitalWrite(led, LOW);
  //wait 500 ms
  delay(500);
}
