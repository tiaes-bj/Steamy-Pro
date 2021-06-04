#include <Wire.h>
int us = 1;
uint8_t addLigne = 0x20;
uint8_t addCol = 0x27;

uint8_t tabA[8] = {0b00000000, 0b01111111, 0b10001000, 0b10001000, 0b10001000, 0b10001000, 0b01111111, 0b00000000};
uint8_t tabB[8] = {0b00000000, 0b11111111, 0b10010001, 0b10010001, 0b10010001, 0b10010001, 0b11101111, 0b00000000};
uint8_t tabC[8] = {0b00000000, 0b01111110, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b00000000};
uint8_t tabD[8] = {0b00000000, 0b11111111, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b01111110, 0b00000000};
uint8_t tabE[8] = {0b00000000, 0b11111111, 0b10011001, 0b10011001, 0b10011001, 0b10011001, 0b10011001, 0b00000000};
uint8_t tabF[8] = {0b00000000, 0b11111111, 0b10001000, 0b10001000, 0b10001000, 0b10001000, 0b10001000, 0b00000000};
uint8_t tabG[8] = {0b00000000, 0b01111110, 0b10000001, 0b10000001, 0b10011001, 0b10011001, 0b10011111, 0b00000000};
uint8_t tabH[8] = {0b00000000, 0b11111111, 0b00001000, 0b00001000, 0b00001000, 0b00001000, 0b11111111, 0b00000000};
uint8_t tabI[8] = {0b00000000, 0b10000001, 0b10000001, 0b11111111, 0b11111111, 0b10000001, 0b10000001, 0b00000000};
uint8_t tabJ[8] = {0b00000000, 0b10001110, 0b10000011, 0b11111111, 0b11111111, 0b10000000, 0b10000000, 0b00000000};
uint8_t tabK[8] = {0b00000000, 0b11111111, 0b11111111, 0b00011000, 0b00011000, 0b00100100, 0b01000010, 0b10000001};
uint8_t tabL[8] = {0b00000000, 0b11111111, 0b11111111, 0b00000011, 0b00000011, 0b00000011, 0b00000011, 0b00000011};
uint8_t tabM[8] = {0b00000000, 0b11111111, 0b01111111, 0b00100000, 0b00100000, 0b01111111, 0b11111111, 0b00000000};
uint8_t tabN[8] = {0b00000000, 0b11111111, 0b11111111, 0b00110000, 0b00011000, 0b11111111, 0b11111111, 0b00000000};
uint8_t tabO[8] = {0b00000000, 0b01111110, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b01111110, 0b00000000};
uint8_t tabP[8] = {0b00000000, 0b11111111, 0b11111111, 0b10001000, 0b10001000, 0b10001000, 0b01110000, 0b00000000};
uint8_t tabQ[8] = {0b00000000, 0b01111110, 0b10000001, 0b10000001, 0b10000001, 0b10000101, 0b01111110, 0b00000001};
uint8_t tabR[8] = {0b00000000, 0b11111111, 0b11111111, 0b10001000, 0b10001000, 0b10001100, 0b01110010, 0b00000001};
uint8_t tabS[8] = {0b00000000, 0b00000000, 0b11110111, 0b10010001, 0b10010001, 0b10010001, 0b11011111, 0b00000000}; 
uint8_t tabT[8] = {0b00000000, 0b11000000, 0b10000000, 0b11111111, 0b11111111, 0b10000000, 0b11000000, 0b00000000};
uint8_t tabU[8] = {0b00000000, 0b11111110, 0b11111101, 0b00000011, 0b00000011, 0b11111101, 0b11111110, 0b00000000};
uint8_t tabV[8] = {0b00000000, 0b11111000, 0b00000100, 0b00000010, 0b00000010, 0b00000100, 0b11111000, 0b00000000}; 
uint8_t tabW[8] = {0b00000000, 0b11111100, 0b11111010, 0b00000101, 0b00001010, 0b00000101, 0b11111010, 0b11111100};
uint8_t tabX[8] = {0b00000000, 0b11111111, 0b11100111, 0b00011000, 0b00011000, 0b11100111, 0b11111111, 0b00000000};
uint8_t tabY[8] = {0b00000000, 0b11100000, 0b11110000, 0b00011111, 0b00011111, 0b11110000, 0b11100000, 0b00000000};
uint8_t tabZ[8] = {0b11000011, 0b11000111, 0b11001111, 0b11011011, 0b11110011, 0b11100011, 0b11000011, 0b00000011};
uint8_t tabCoeur[8] = {0b00011000, 0b00100100, 0b00100010, 0b00010001, 0b00100010, 0b00100100, 0b00011000, 0b00000000};


void setup()
{
  Wire.begin();
  Serial.begin(9600);
}


void loop()
{

  for (int i = 0; i < 8; i++)
  {
    wire(addLigne, addCol, tabB[i], i + 1);
   delayMicroseconds(us);
  }

}



void wire(uint8_t addLigne, uint8_t addCol, uint8_t valeur, int colonne)
{
  Wire.beginTransmission(addLigne);
  Wire.write(valeur);
  Wire.endTransmission();

  Wire.beginTransmission(addCol);
  switch (colonne)
  {
    case 1:
      Wire.write(0b11111110);
      break;
    case 2:
      Wire.write(0b11111101);
      break;
    case 3:
      Wire.write(0b11111011);
      break;
    case 4:
      Wire.write(0b11110111);
      break;
    case 5:
      Wire.write(0b11101111);
      break;
    case 6:
      Wire.write(0b11011111);
      break;
    case 7:
      Wire.write(0b10111111);
      break;
    case 8:
      Wire.write(0b01111111);
      break;
    default:
      Wire.write(0b11111111);
      break;
  }
  Wire.endTransmission();

  Wire.beginTransmission(addLigne);
  Wire.write(0b00000000);
  Wire.endTransmission();

  Wire.beginTransmission(addCol);
  Wire.write(0b11111111);
  Wire.endTransmission();
}