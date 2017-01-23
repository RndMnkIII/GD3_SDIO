#include <SPI.h>
#include <GD3.h>
#include "V.h"

void setup()
{
  Serial.begin(9600);
  GD.begin();
  GD.cmd_setrotate(0);
   espera();
   LOAD_ASSETS();     
}

int X0=7, sepX=8, Y0=105, largobarra=214;
int Nbar=45;

void loop()
{
   GD.ClearColorRGB(0x000010);
   //GD.ClearColorRGB(0xffff00);
   GD.Clear();
    GD.SaveContext();
     //GD.ColorA(200);
      BarrasV();
     //GD.ColorA(255);
    GD.RestoreContext();
   
    GD.Begin(BITMAPS);
    GD.Vertex2ii(0, 95, 0);
   GD.swap();
   delay(20);   
}

int dato=0, velX=1;

void BarrasV()
{
  GD.Begin(LINES);
  GD.LineWidth(50);

for(int ki = 0; ki < Nbar+1; ki++) 
       { 
          GD.ColorRGB(0x101010);
          GD.Vertex2f((X0+(sepX*ki))*16,(Y0)*16);
          GD.Vertex2f((X0+(sepX*ki))*16,(Y0+largobarra)*16);
       }



   if(dato<=39){
    for(int i = 0; i < dato; i++) 
       { 
          GD.ColorRGB(0xffffff);
          GD.Vertex2f((X0+(sepX*i))*16,(Y0)*16);
          GD.Vertex2f((X0+(sepX*i))*16,(Y0+largobarra)*16);
       }}

   if(dato>=39){
    for(int i = 0; i < 39; i++) 
       { 
          GD.ColorRGB(0xffffff);
          GD.Vertex2f((X0+(sepX*i))*16,(Y0)*16);
          GD.Vertex2f((X0+(sepX*i))*16,(Y0+largobarra)*16);
       }
       
    for(int k = 39; k < dato; k++) 
       { 
          GD.ColorRGB(0xff0000);
          GD.Vertex2f((X0+(sepX*k))*16,(Y0)*16);
          GD.Vertex2f((X0+(sepX*k))*16,(Y0+largobarra)*16);
          GD.ColorRGB(0xffffff);
       }       
       
       }

       dato= dato+velX; 
       if (dato==46){velX=-1;}
       if (dato<=0){dato=0; velX=1;}
}
