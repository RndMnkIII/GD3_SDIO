//#include <EEPROM.h> 
#include <SPI.h>
#include <GD3.h>
#include "pez1.h"  //6 imagenes: ID = 0-5

#include <Encoder.h>
Encoder myEnc(3, 4);
int PX = 400, VelX=0;

int BX = GD.random(750), BY=400, BY1=425, Burb=3, BX1= GD.random(750), Burb1=4;
long previousMillisB = 0;
long intervalB = 60000;  

void setup()
{
  GD.begin();
  GD.cmd_setrotate(0);
  GD.play(0); //detiene sonido en altavoz
  espera();
  MP();
}

void loop(){}

int Pez=2;

void MP()
{
  CargaAssetF1();
  while(1)
  {  
    GD.ClearColorRGB(0x000000);
    GD.Clear();
    GD.Begin(BITMAPS);
    GD.Vertex2ii(0, 0, 15);   //800x480 px, fondo de pantalla
//Velocidad de desplazamiento en X  
    VelX = (-1*myEnc.read());
    GD.cmd_number(GD.w / 2, (GD.h / 2)-45, 31, OPT_SIGNED|OPT_RIGHTX, VelX);
//Velocidad de desplazamiento en X  

//Pez
    GD.SaveContext();
      GD.VertexTranslateX(16*(PX));
      GD.Vertex2ii(0, 300, Pez);

      PX = PX + VelX;
      if (VelX==0){Pez=2;}
      if (VelX>0){Pez=0;}
      if (VelX<0){Pez=1;}
        
       if(PX>=850){PX = -200;}
       if(PX<=-201){PX = 850;}
     GD.RestoreContext();        
//Pez

//Burbujas
    GD.SaveContext();
      GD.VertexTranslateX(16*(BX));
      GD.Vertex2ii(0, BY, 5);
      BY = BY - 5;
     GD.RestoreContext();

    GD.SaveContext();
      GD.VertexTranslateX(16*(BX1));
      GD.Vertex2ii(0, BY1, 5);
      BY1 = BY1 - 10;
     GD.RestoreContext();     
  unsigned long currentMillisB = millis();        
  if(currentMillisB - previousMillisB > intervalB)
  {
    previousMillisB= currentMillisB;       
        BX = GD.random(750);
        BX1 = GD.random(750);
        BY=400, BY1=425;
  }
//Burbujas
    GD.swap();
  }
}
