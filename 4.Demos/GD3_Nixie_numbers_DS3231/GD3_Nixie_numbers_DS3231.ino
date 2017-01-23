//http://gameduino2.proboards.com/thread/242/jpg-quality

//#include <EEPROM.h>
#include "Wire.h"
#include <SPI.h>
#include <GD3.h>

#include "nixie1.h"
char TX[50];

#define DS3231Pin        24

#define DS3231_I2C_ADDRESS 0x68
byte second, minute, hour, dayOfWeek, dayOfMonth, month, year; 
// Convert normal decimal numbers to binary coded decimal
byte decToBcd(byte val)
{
  return( (val/10*16) + (val%10) );
}
// Convert binary coded decimal to normal decimal numbers
byte bcdToDec(byte val)
{
  return( (val/16*10) + (val%16) );
}



void setup()
{
  Serial.begin(9600);
  Wire.begin();
  // set the initial time here:
  // DS3231 seconds, minutes, hours, day, date, month, year
  //setDS3231time(30,52,17,3,10,11,15);   //  day 3 =  Martes     //comentar cuando el tiempo den DS3231 esté asignado  
  GD.begin();
  GD.cmd_setrotate(0);

  pinMode(DS3231Pin, OUTPUT); 
  digitalWrite(DS3231Pin,HIGH);
 
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
  readDS3231time(&second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month,&year);   
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

  HoraNixie(185, 300, hour, minute, second);

  GD.SaveContext(); 
   GD.VertexTranslateX(16*260);
   HoraNixie(200, 10, HH, MM, SS);
   HoraNixie(200, 100, 5, 35, Sec);
  GD.RestoreContext(); 

GD.SaveContext();
     GD.cmd_romfont(14,34);   //Usa las fuentes adicionales del FT81X: 31, 32, 33, 34
     GD.ColorRGB(0xffff00);   
     //GD.cmd_number(50, 100, 14, 0, second); 
     sprintf(TX,"%02d:%02d:%02d", hour, minute, second);
     GD.cmd_text(265, 100, 14, OPT_CENTER, TX);
     
   GD.RestoreContext();
  
  
  delay(100);
  num=num+k;
  Sec = Sec + 1;

  GD.swap();
}

void HoraNixie(int PXH, int PYH, int HH, int MM, int SS)
{
   NixieNUM(HH, PXH, PYH);
   NixieNUM(MM, PXH+115, PYH);
   NixieNUM(SS, PXH+115*2, PYH);
}
