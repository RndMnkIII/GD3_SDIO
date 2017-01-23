#include <SPI.h>
#include <GD3.h>

#include "Icons2.h"        //ASSETS7b   //+switchs, +boton enc, -icono de advertencia, -iconos de audio
  float V0, incremento;

void setup() {
  Serial.begin(9600);
  GD.begin();
  GD.cmd_setrotate(0);
  //GD.wr(REG_PWM_DUTY, 75);  //0-128  intensidad de la retroiluminación XD

  espera();          
  carga_iconos();   //ASSETS7/ASSETS7a/ASSETS7b
//  MP();  //con iconos
//  MP1();  //sin iconos
  MP3();  //sin iconos
}

//  int T1DX = 5;  //espesor de la base de la aguja
//  int VT1x1 = 100, VT1x2=VT1x1+T1DX, VT1xM = (VT1x1+VT1x1+T1DX)/2;
//  int T1DY = 100; //largo de la aguja
//  int VT1y1 = 200, VT1y2 = VT1y1, VT1yM = VT1y1 - T1DY;  


void loop(){}


void MP3(){

while(1)
{

  if(V0==100){incremento=-1;}
    if(V0==0){incremento=1;}  
   V0 = V0+incremento;
  

 GD.ClearColorRGB(0x151515); //fondo de pantalla
 GD.Clear();
// GD.SaveContext();     
//  GD.Begin(BITMAPS); GD.Vertex2ii(0, 100); GD.End();
// GD.RestoreContext();    



// Gauge vertical de -90 a 90 grados 
  MarcasDialV(70,85,125,3,1); //RadioBase, XBase, YBase, LargoMarcas, EspesorMarcas 
  GD.ColorA(255); GD.ColorRGB(0x00,0xff,0xff);
  Analogico2(70,85,125,30,1,2,V0,100,21,90,135, 4);  //RadioBase, XBase, YBase, LargoAguja, Addaguja, EspesorAguja, Variable,RangoEscala, Tamaño texto, Xtexto, Ytexto, diametro del pivote 
//  Analogico2(50,75,80,45,1,1,V0,100,21,45+25,115-18, 4);  //RadioBase, XBase, YBase, LargoAguja, Addaguja, EspesorAguja, Variable,RangoEscala, Tamaño texto, Xtexto, Ytexto, diametro del pivote
 
//  MarcasDial(70,240,135,3,1); //RadioBase, XBase, YBase, LargoMarcas, EspesorMarcas 
//   Analogico(70,240,135,7,65,1,5,V0,100,21,250,150, 0,0,255,4);
     
  MarcasDial(140,240,170,5,2); //RadioBase, XBase, YBase, LargoMarcas, EspesorMarcas 
   Analogico(140,240,170,20,135,2,4,V0,100,24,250,200, 0,0,255,6);   
//RadioBase, XBase, YBase, LargoSeguidor, largoAguja, EspesorAguja, SeparadorSeguidor, Variable,RangoEscala, Tamaño texto, Xtexto, Ytexto, R, G, B, radio del pivote.    
     
// Gauge vertical de 90 a 270 grados 
  MarcasDialV2(70,395,125,3,1); //RadioBase, XBase, YBase, LargoMarcas, EspesorMarcas 
  GD.ColorA(255); GD.ColorRGB(0x00,0xff,0xff);
  Analogico3(70,395,125,30,1,2,V0,100,21,410,135,4);  //RadioBase, XBase, YBase, LargoAguja, Addaguja, EspesorAguja, Variable,RangoEscala, Tamaño texto, Xtexto, Ytexto, diametro del pivote  
//  Analogico3(50,275,80,45,1,1,V0,100,21,295,115-18,4);  //RadioBase, XBase, YBase, LargoAguja, Addaguja, EspesorAguja, Variable,RangoEscala, Tamaño texto, Xtexto, Ytexto, diametro del pivote

 GD.swap();
// delay(50); 
 }
}


