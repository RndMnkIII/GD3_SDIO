//#include <EEPROM.h>
#include "Wire.h"
#include <SPI.h>
#include <GD3.h>
#include "Icons2.h"

//#include <Adafruit_GFX.h>
//#include <Adafruit_NeoMatrix.h>
//#include <Adafruit_NeoPixel.h>

//Neopixel
//#define PIN            52
//#define NUMPIXELS      65

#define MAX_IMAGESc  149
#define MAX_IMAGES 149  
char directory[MAX_IMAGES][8];
int num_jpgs = 0;

// Como Matriz RGB
//Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(3, 15, PIN,
//  NEO_MATRIX_TOP     + NEO_MATRIX_RIGHT +
//  NEO_MATRIX_COLUMNS + NEO_MATRIX_PROGRESSIVE,
//  NEO_GRB            + NEO_KHZ800);
//Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int xico = 15, movimiento1=1, valores =3;
int entrada = 0, intenso=25;

int delta = 0;
int Numrects = 50;

int limsup = MAX_IMAGES * 26.5;

int picked;
int xTextJPG = 400 + 48;  
int NombreJPG = 10;//14; //w01.jpg en FT801_Riverdi
int RespaldoNombreJPG = NombreJPG;
int ymov= 152;//276; //funciona para almacenar la posición relativa del selector de archivos, ligado a 14, FT801

int estado=0;

int Transp = 75;   // transparencia en botones
int32_t LoopFlag = 0,wbutton,hbutton,tagval,tagoption;
char TX[50];  

int TxPDF=350;  //Datos de posición de la imagen de fondo del sistema de sensores de temperatura

//Panel izquierdo
int separacionpanel = 5;
int movx = -160, movxbase=-160, velocidadx = 10; 
//Panel izquierdo

//Panel derecho
int despPD = 0;  //el valor de XDbase=160; cuando es 1, cambia a 0.
int xDbase = 160, velPD=0;
//Panel derecho


// MSGEQ7 spectrum analyser 
 int Lectura;        // activar variable para las lecturas directas de la banda del MSGEQ7 seleccionada
 int Valor;          // ajuste de lectura para que quede dentro del marco de la gráfica
 
  const int maxlecturas = 35;  //Número de puntos almacenados para graficar

  int lectura[maxlecturas];  // base de datos actual
  int k,j;

// Diseño de marco para gráfica
int RectWidth = 178, RectHeight = 70;
int XGT=60, YGT=200;

//Posición base de la gráfica  
  int xinicial=XGT;
  int ybaseT=-2;
//Posición base de la gráfica  

  int DiamPT = 1;
  int separacion=3+(DiamPT*1.5);    //  
  
//Posición del listado de la base de datos
  int xTextoT = 85;
  int yTextoT = 48; 
//Posición del listado de la base de datos

// MSGEQ7 spectrum analyser 
//Millis en lugar de delay para gráfica lineal
long previousMillis = 0;        // will store last time was updated
long interval = 0;           // 
//long interval = 50;           // intervalo de lectura y actualización de gráfica, para que se aprecie bien en tiempo real a max velocidad
//long interval = 10000;           // intervalo de lectura y actualización de gráfica, al tiempo mas conveniente XD

int strobe = 25; //5  FT843   2  FT801/FT813 Riverdi
int res = 26;    //6  FT843   3  FT801/FT813 Riverdi

int left[7]; 
int band;

int sepY = 10, sepX = 20, largoX = 30;
int xi = 75, yi = 185; 
int segmentos = 14;
// MSGEQ7 spectrum analyser 

int Xreloj=250, Yreloj=136;
int movxR = -560;

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


//Set up Alarmas
//int HAlarma1=21, MAlarma1=10, SAlarma1=0;  //normal  Silvia
int HAlarma1=9, MAlarma1=0, SAlarma1=0;    //Al Autozone
//Set up Alarmas

//Gráfica de temperaturas

//SensorT 1
float T1, T1a, T1b, T1g, DT1, DT1g;
long previousMillis1 = 0;
long interval1 = 500;         
int TxPD=185;  //datos de desplazamiento del sensorT 1
//SensorT 1

//Gráfica de temperaturas
