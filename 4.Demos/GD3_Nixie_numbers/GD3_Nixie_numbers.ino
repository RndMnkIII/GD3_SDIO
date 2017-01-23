//http://gameduino2.proboards.com/thread/242/jpg-quality

//#include <EEPROM.h>
#include <SPI.h>
#include <GD3.h>

#include "nixie1.h"
char TX[50];

void setup()
{
  Serial.begin(9600);
  GD.begin();
  GD.cmd_setrotate(0);
 
// Assets e imagen de fondo
  LOAD_ASSETSnix1();   //nixie1.h
 
  GD.BitmapHandle(15);
  GD.cmd_loadimage(ASSETS_END, 0);
  GD.load("HMI2.jpg");  
}

int num=0, k=1;
int Sec=0;

void loop()
{
  GD.ClearColorRGB(0x000000);
  GD.Clear();
  GD.Begin(BITMAPS);  
  
  GD.SaveContext(); 
   GD.VertexTranslateX(16*350);
   GD.Vertex2ii(380, 190, num); //Nixie
  GD.RestoreContext(); 
 
  GD.Vertex2ii(20, 10, num); //Nixie
  GD.Vertex2ii(380, 190, num); //Nixie
  GD.Vertex2ii(20, 400, num); //Nixie
  
  if (num == 10){k=-1;}
  if (num == 0){k=1;}
  if (Sec == 60){Sec=0;}


  int HH = random(11);
  int MM = random(59);
  int SS = random(59);

  HoraNixie(185, 400, HH, MM, SS);

  GD.SaveContext(); 
   GD.VertexTranslateX(16*260);
   HoraNixie(200, 10, HH, MM, SS);
   HoraNixie(200, 100, 5, 35, Sec);
  GD.RestoreContext(); 
  
  delay(1000);  num=num+k;
                Sec = Sec + 1;

  GD.swap();
}

void HoraNixie(int PXH, int PYH, int HH, int MM, int SS)
{
   NixieNUM(HH, PXH, PYH);
   NixieNUM(MM, PXH+115, PYH);
   NixieNUM(SS, PXH+115*2, PYH);
}
