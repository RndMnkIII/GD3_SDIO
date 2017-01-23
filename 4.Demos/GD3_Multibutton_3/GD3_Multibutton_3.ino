#include <SPI.h>
#include <GD3.h>

int i, j, kj, group1, group2, group3, group4, group5, group6, group7, group8;
char text[13];


int Xbase = 90, Ybase=65;
int sepX=8;

float datoB[10];
float velXB[10];

float dato=0;
float velX=1;
float dato2=0;
float velX2=1;

void setup()
{
  Serial.begin(9600);
  GD.begin();
  GD.cmd_setrotate(0);      
  //GD.self_calibrate();

  GD.cmd_loadimage(0, 0);
  GD.load("V1.png");
}

void loop()
{

  while(1)
  {
    //GD.ClearColorRGB(31, 63, 127);
    GD.Clear();

    GD.SaveContext();
           //(PX, PY, Maxbar, largobarra2, NRbar   IDBar     Aumento de vel      reducción del vel, CANAL ROJO, CANAL VERDE, CANAL AZUL
     //BarrasV2(120+50, 311, 15,         10,       2,      1,           1,                   -1, 255,255,0);  //Fuel bar   IDBar=1
     BarrasV2(351+50, 311, 15, 10, 4, 2, 0.1, -2, 0,0,255);  //Battery charge bar   IDBar=2
     BarrasV2(297+50, 160, 45, 142, 6, 3, 1, -1, 255,0,0);  //RPM bar             IDBar=3
    GD.RestoreContext(); 

    GD.SaveContext();
    GD.Begin(BITMAPS);
    GD.Vertex2ii(130, 65);
    GD.SaveContext();    
   
    GD.SaveContext();
    GD.get_inputs ();  Serial.println (GD.inputs.tag);    
    if(group1==1){Block1();}else{}
    if(group2==1){Block2();}else{}
    if(group3==1){Block3();}else{}
    if(group4==1){Block4();}else{}
    if(group5==1){Block5();}else{}
    if(group6==1){Block6();}else{}
    if(group7==1){Block7();}else{}
    if(group8==1){Block8();}else{}  

    //GD.cmd_fgcolor(0x008000);
    for(kj=1; kj<9; kj++)
    {
      sprintf(text, "%d", kj);
      GD.Tag(kj); GD.cmd_button(0, -25+(54*kj), 78, 52, 28, 0, text);
    } GD.Tag(255); 

    Choise();
    GD.RestoreContext(); 

   GD.swap();
  }
}



