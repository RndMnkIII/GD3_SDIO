//#include <EEPROM.h> 
#include <SPI.h>
#include <GD3.h>

void setup()
{
  GD.begin();
  GD.cmd_setrotate(0);
  agujasimple();
}

void loop(){}

float Xb = 400, Yb = 300, angP=-160, lp = 150;
float Xp, Yp, velp =1;

long previousMillis;
long interval = 0;
float pi=3.1415926535897932384626433832795;

void agujasimple()
{

while(1)
 {   
  GD.ClearColorRGB(0x002000);  
  GD.Clear();   

  if (abs(angP)<160){angP=-160; velp=1*abs(velp);}
  if (abs(angP)>380){angP=-380; velp=-1*abs(velp);}

  Xp = Xb + lp * cosf(angP*pi/180);
  Yp = Yb - lp * sinf(angP*pi/180);

  GD.printNfloat(100, 50, Xp, 2, 31);
  GD.printNfloat(300, 50, Yp, 2, 31);
  GD.printNfloat(500, 50, angP, 0, 31);
  
  GD.SaveContext();
   GD.Begin(LINES);
   GD.LineWidth(35);
   GD.Vertex2f(Xb*16, Yb*16); // inicio
   GD.Vertex2f(Xp*16, Yp*16); //  fin   
  GD.SaveContext();    

  unsigned long currentMillis = millis();        
  if(currentMillis - previousMillis > interval)
  {
    previousMillis = currentMillis;       
    angP = angP - velp;
  }
   GD.swap();
 }
}
