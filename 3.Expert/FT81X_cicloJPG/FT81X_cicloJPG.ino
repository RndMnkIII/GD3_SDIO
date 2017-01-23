//#include <EEPROM.h>
#include <SPI.h>
#include <GD3.h>

unsigned long start;

void setup()
{
  GD.begin();
  GD.cmd_setrotate(0);
}

void loop(){
 Ciclo();
}

void CargaJPG()
{
   GD.Clear();
   GD.Begin(BITMAPS);  
   GD.Vertex2ii(0, 0); 
   
   GD.ColorRGB(0,255,0);  GD.cmd_number(730,465,21,OPT_CENTER|OPT_SIGNED,millis() - start);              
   GD.swap();
}
