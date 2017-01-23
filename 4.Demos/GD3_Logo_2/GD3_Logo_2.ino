#include <SPI.h>
#include <GD3.h>

#include "ALogo1.h"

int x=400, y=240, ylogo= y + 125, Vlogo=5;

void setup()
{
  Serial.begin(9600);
  GD.begin();
  GD.cmd_setrotate(0);

// Assets e imagen de fondo
  LOAD_ASSETS();   
 
  GD.BitmapHandle(15);
  GD.cmd_loadimage(ASSETS_END, 0);
  GD.load("LG1.png");  //si lo carga XD  800x480
 // Assets e imagen de fondo 
  
  MP();
}

void loop(){}

void MP()
{
  while(1)
  {
    GD.ClearColorRGB(0x103000);
    GD.Clear();
    GD.Begin(BITMAPS); 
     GD.Vertex2ii(0,0,15);
     
      DesplazamientoVLogo();     

     GD.SaveContext();
       GD.VertexTranslateX(16*180);
       GD.Vertex2ii(455,300,1);
       GD.Vertex2ii(300,400,0);
     GD.RestoreContext();      
    
     DesplazamientoH();
     DesplazamientoV();
     GD.SaveContext();
      GD.ColorA(150);
      GD.cmd_romfont(14,34);   //Usa las fuentes adicionales del FT81X: 32, 33, 34
      GD.ColorRGB(0,0,0);  GD.cmd_text(393, 253, 14, OPT_CENTER, "Hello world");
      GD.ColorRGB(255,0,0);  GD.cmd_text(400, 240, 14, OPT_CENTER, "Hello world");
     GD.RestoreContext(); 

    GD.swap();
  }
}

void DesplazamientoH()
{
  if(x<=-150){x=900;}
    GD.ColorRGB(0,255,0);
    GD.cmd_text(x, 240, 31, OPT_CENTER, "Hello world");
  x=x-2;
}

void DesplazamientoV()
{
  if(y<=-100){y=500;}
    GD.ColorRGB(255,255,0);
    GD.cmd_text(400, y, 31, OPT_CENTER, "Hello world");
    GD.cmd_text(400, y+35, 28, OPT_CENTER, "FT81X, 800x480, GD3");
    GD.cmd_text(400, y+60, 28, OPT_CENTER, "Riverdi breakout-20");
    GD.cmd_text(400, y+85, 28, OPT_CENTER, "Teensy 3.6, Arduino");
  y=y-5;
}

void DesplazamientoVLogo()
{
  if(ylogo<=0){Vlogo=-5;}
  if(ylogo>=380){Vlogo=5;}
     GD.Vertex2ii(300,ylogo,2);
  ylogo=ylogo-Vlogo;
}

