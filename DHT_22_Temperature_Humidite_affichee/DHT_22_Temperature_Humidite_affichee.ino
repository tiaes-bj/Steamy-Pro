#include "DHT.h"
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define DHTPIN 2     // Digital pin connected to the DHT sensor

#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup() {
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("DHT 22 test!...");
  dht.begin();
  delay(2000);
  lcd.clear();
   
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) ) {
 lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Le capteur a un problème.");
  lcd.setCursor(0,1);
  lcd.print("probleme.");
  return;
  }


  lcd.setCursor(0,0);
  lcd.print(F("Humidite: "));
  lcd.setCursor(10,0);
  lcd.print(h);
  lcd.setCursor(15,0);
  lcd.print(F("%"));

  lcd.setCursor(0,1);
  lcd.print(F("Temp: "));
  lcd.setCursor(7,1);
  lcd.print(t);
  lcd.setCursor(12,1);
  lcd.print(F(" C"));
  
}
