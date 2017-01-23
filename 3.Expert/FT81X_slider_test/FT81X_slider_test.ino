#include <SPI.h>
#include <GD3.h>

//http://gameduino2.proboards.com/thread/226/slider

#define SliderRojo  201
#define SliderVerde 202
#define SliderAzul  203
int ValorR=125, ValorG=0, ValorB=125, PX=350, PXS=100, PYS=35;
//unsigned long start;
uint16_t RectWidth=100, RectHeight=50;

float xReloj = 600, yReloj =400, yValor;

void setup() {
 Serial.begin(9600);
 GD.begin();
 GD.cmd_setrotate(0);
 GD.self_calibrate();    //FT801/813 Riverdi  
  
  espera();
 GD.cmd_loadimage(0, 0);
 GD.load("Fn1.jpg");  //si lo carga XD  800x480
}

void loop() {
//  GD.ClearColorRGB(0x103000);
  GD.Clear();
   GD.Begin(BITMAPS);  
   GD.Vertex2ii(0, 0); 
  GD.get_inputs();  

  if(xReloj>=850){xReloj=-150;}

//  GD.cmd_playvideo(OPT_FULLSCREEN | OPT_NOTEAR);
//Draw clock
//  GD.ColorRGB(0x0000ff);  //color de las manecillas, sino se selecciona se dibujan en color blanco
 GD.cmd_bgcolor(0xff0000); //color de fondo
 GD.cmd_clock(xReloj,yReloj-yValor,50,OPT_FLAT,12,33,45,0);

  xReloj = xReloj+4;

//  slider1();
 GD.ColorA(100);  
  slider2();
 GD.ColorA(255);  
   
  GD.swap();
}

