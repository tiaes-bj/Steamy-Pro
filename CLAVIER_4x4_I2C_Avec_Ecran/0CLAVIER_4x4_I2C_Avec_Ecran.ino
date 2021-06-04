#include <Key.h>
#include <Keypad.h>
#include <Keypad_I2C.h>
#include <LiquidCrystal_I2C.h>


#define I2CADDR 0x23 // Set the Address of the PCF8574

const byte ROWS = 4; // Set the number of Rows
const byte COLS = 4; // Set the number of Columns

// Set the Key at Use (4x4)
char keys [ROWS] [COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// define active Pin (4x4)
byte rowPins [ROWS] = {0, 1, 2, 3}; // Connect to Keyboard Row Pin
byte colPins [COLS] = {4, 5, 6, 7}; // Connect to Pin column of keypad.

// makeKeymap (keys): Define Keymap
// rowPins:Set Pin to Keyboard Row
// colPins: Set Pin Column of Keypad
// ROWS: Set Number of Rows.
// COLS: Set the number of Columns
// I2CADDR: Set the Address for i2C
// PCF8574: Set the number IC

Keypad_I2C keypad (makeKeymap (keys), rowPins, colPins, ROWS, COLS, I2CADDR, PCF8574);
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

int indL=0;
int indC=0;
int count=0;
String chaine="";


void setup () {
  Wire .begin (); // Call the connection Wire
  keypad.begin (makeKeymap (keys)); // Call the connection

   lcd.init();   
   lcd.backlight();

}



void loop () {
  
 char key=' ';
 do {// if the key variable contains
    key = keypad.getKey (); // Create a variable named key of type char to hold the characters pressed
   
     
        if(key=='*')
        {
          lcd.clear();
          lcd.setCursor(0,0);
          chaine="";
          indL=0;indC=0;count=0;
        }
         if( key=='A'||key=='B'||key=='C'||key=='D'||key=='#'||
             key=='0'||key=='1'||key=='2'||key=='3'||key=='4'||
             key=='5'||key=='6'||key=='7'||key=='8'||key=='9')
        {
           lcd.setCursor(indL,indC);
           indL++;
            if( indL==16)
              {
                indL=0;
                count++;
                indC=count%2;
              }
              
          if( key=='#') key=' ';
                
          lcd.print(key);
          chaine+=key;
              
        }
      
  } while (key) ;
}
