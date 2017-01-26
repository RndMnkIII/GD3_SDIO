//#include <EEPROM.h>
#include <SPI.h>
#include <GD3.h>
#include <stdio.h>

char nombre[32];
char estado[40];
//int inicio=2110;
int inicio=3121;
//int fin=2210;
int fin=3759;
int fcount=inicio;


//variables para limitar los frames por segundo a 24
const long FPS=24;
long prevFTime;
long currFTime;
long frmTime=1000 / FPS;

//varialbes para llevar cuenta del tiempo de reproducción:
int hrs=0;
int mins=0;
int secs=0;

File archivo;
SdFatSdioEX SD;
long currMillis;
long prevMillis;
int contador=0;
int frms=0;

unsigned long start;

void setup()
{
  GD.begin();
  GD.cmd_setrotate(1);
  SD.begin();
  prevMillis=millis();
  prevFTime=millis();
  
}

void loop(){
  currMillis=millis();

  if(currMillis-prevMillis > 1000){
    prevMillis=currMillis;
    verEstado();
    contador=0;
  }
  
  if(fcount > fin)
  {
    fcount=inicio;
  }
  //800x480, 720x432, 640x380                        720x0.6
  //snprintf(nombre, 30, "frag%05d.jpg", fcount);
  
  currFTime=millis();
  if(currFTime-prevFTime > frmTime)
  {
      prevFTime=currFTime;
      snprintf(nombre, 30, "capB%05d.jpg", fcount);
      String str(nombre);
      archivo = SD.open(str);      
      GD.cmd_loadimage(0, 0);
      GD.loadSDIO(archivo); 
      
      contador++;
      fcount++;
      frms++;
  }
  if (frms == FPS){
    frms=0;
    secs++;
  }
  if (secs == 60)
  {
    secs=0;
    mins++;
  }
  if (mins == 60)
  {
    mins=0;
    hrs++;
  }

}

void verEstado()
{
   //snprintf(estado, 40, "H:%02d M:%02d S:%02d Fps:%02d", hrs,mins,secs,contador);
   sprintf(estado, "H:%02d M:%02d S:%02d Fps:%02d", hrs,mins,secs,contador); 
   //sprintf(estado, "S:%02d", secs); 
   GD.Clear();
   GD.Begin(BITMAPS);  
   GD.Vertex2ii(0, 0); 
   GD.ColorRGB(0,255,0);  GD.cmd_text(600,465,21,OPT_CENTER, estado);              
   GD.swap();
}
