//#include <EEPROM.h>
#include <SPI.h>
#include <GD3.h>
#include "Icons2.h"

long previousMillis = 0;
long interval = 100;

float contador=0;
int TextS= 27;

void setup()
{
  GD.begin();
  GD.cmd_setrotate(0);
  Hello();
  espera();
   Imagenes();  
}

void loop(){ 
  Rotacion0();
  delay(1000);  
  Rotacion1();
  delay(1000);  
  Rotacion2();
  delay(1000);  
  Rotacion3();
  delay(1000);   
}


