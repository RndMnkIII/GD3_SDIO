//RndMnkIII  10/02/17
//Demostración de integración de la placa Teensy Audio Shield y la
//pantalla FT81x. Utiliza Teensy 3.5/3.6 con SDIO.
//Código fuente Audio shield basado en ejemplo del siguiente tutorial:
//https://hackaday.io/project/8292-microcontroller-audio-workshop-had-supercon-2015

//************************************************************************
//IMPORTANTE: LEER LO QUE SIGUE ANTES DE COMPILAR Y EJECUTAR ESTE CÓDIGO
//TIENE MODIFICACIONES IMPORTANTES DE HARDWARE Y LIBRERIAS DE TEENSY
//NECESITA LA ULTIMA MODIFICACION DE GD3_SDIO (10/02/17):
// https://github.com/RndMnkIII/GD3_SDIO
//************************************************************************
//Importante: pines SCK y MOSI utilizando configuraciones alternativas
//
//Para no interferir con el funcionamiento de la Audio Shield
//Se vuelve a la libreria SD.h, abandonando la SdFat.h por compatibilidad
//con la libreria de audio.
//
//Para utilizar la libreria Audio.h con la SDIO de las tarjetas Teensy 3.5/3.6.
//Modificar la libreria Audio.h:
//Añadir los siguientes defines:
//#define HAS_KINETIS_SDHC 1
//#define SIM_SCGC3 1
//#define SIM_SCGC3_SDHC 1
//Al archivo play_sd_wav.cpp en: C:\Arduino\hardware\teensy\avr\libraries\Audio
//y recompilar para utilizar SDIO. Depende de utilizar libreria SD.h


#include "arm_math.h" 
#include <math.h>
#include <EEPROM.h> 
#include <GD3.h>
#include <SD.h>
#include <SPI.h>
#include <Audio.h>
//#include "SdFat.h"
//SdFat SD;
#include "ColorRGB.h"
#include <SerialFlash.h>

#define PDNPin 24 //Para realizar POR

AudioPlaySdWav           playWav1;
// Use one of these 3 output types: Digital I2S, Digital S/PDIF, or Analog DAC
AudioOutputI2S           audioOutput;
//AudioOutputSPDIF       audioOutput;
//AudioOutputAnalog      audioOutput;
AudioConnection          patchCord1(playWav1, 0, audioOutput, 0);
AudioConnection          patchCord2(playWav1, 1, audioOutput, 1);
AudioControlSGTL5000     sgtl5000_1;
//SdFatSdioEX SD;
long prevmillis;
long currmillis;
long intervalo;
uint16_t palette[256];
uint16_t plasmaArray[160*96];

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 480;

int color; // stores the plasma value as integer value in range: 0-255
float32_t incAngulo=0;
float32_t rx2, ry2;
float32_t timeAnim=0.0f;
float32_t factorx, sqx, sqy, sqrtsums; //needed for precalculate values
float32_t inv16 = 1.0f / 64.0f; //avoids doing division, I think this add up a small speedup
float32_t inv32 = 1.0f / 128.0f; //avoids doing division, I think this add up a small speedup
float32_t inv8= 1.0f / 32.0f; //avoids doing division, I think this add up a small speedup
float32_t inv7 = 1.0f / 28.0f; //avoids doing division, I think this add up a small speedup
float32_t angulo;
int pos;
uint frms=0; //used to count rendered frames, useful for benchmarking and alternate rendered objects;
int intercambia=0;

void setup()
{

  //ft813 POR reset
  pinMode(PDNPin, OUTPUT);
  digitalWrite(PDNPin, HIGH);
  delay(20);
  digitalWrite(PDNPin, LOW);
  delay(20);
  digitalWrite(PDNPin, HIGH);
  delay(20);

  //establecemos pines alternativos para SPI
    SPI.setMOSI(7);
    SPI.setSCK(14);

  // Audio connections require memory to work.  For more
  // detailed information, see the MemoryAndCpuUsage example
  AudioMemory(8);
  GD.begin();
  GD.cmd_setrotate(1);
  delay(200);

  sgtl5000_1.enable();
  sgtl5000_1.volume(0.5);

    if (!(SD.begin(BUILTIN_SDCARD))) {
    // stop here, but print a message repetitively
    while (1) {
      delay(500);
    }
  }
       playWav1.play("SDTEST4.WAV");//de los archivos del tutorial de la audio shield
       //descargar de:
      delay(10);
      
      GD.Clear();
      GD.wr(REG_PWM_DUTY, 0x50); //ajuste brillo duty cycle 0x0-0x80
  GD.Begin(BITMAPS);
    // El bitmap original tiene 160x96pixeles en formato RGB565
  GD.BitmapSource(0);

  GD.BitmapLayout(RGB565, 160*2, 96);//EL line stride es de 160pixeles x 2 bytes por pixel
  GD.BitmapSizeH(1, 0); //como se va a escalar al ancho de pantalla de 800 pixeles (>511) se toma 1*(2^11) para el ancho
  GD.BitmapSize(BILINEAR, BORDER, BORDER, 800, 480);//segun la documentación de FTDI el ancho deberia ser 800-512=288 no 800


  GD.cmd_scale(F16(5), F16(5));
  GD.cmd_setmatrix();
  GD.Vertex2ii(0, 0);
  GD.swap();
  delay(100);

  //generate the palette
  ColorRGB colorRGB;
  for(int x = 0; x < 256; x++)
  {
    colorRGB.r = int(128.0 + 128 * sin(3.1415 * x / 32.0));
    colorRGB.g = int(128.0 + 128 * sin(3.1415 * x / 64.0));
    colorRGB.b = int(128.0 + 128 * sin(3.1415 * x / 128.0));
    palette[x] = RGBtoINT2(colorRGB);
  } 
}

void playFile(const char *filename)
{
  //Serial.print("Playing file: ");
  //Serial.println(filename);

  // Start playing the file.  This sketch continues to
  // run while the file plays.
  playWav1.play(filename);

  // A brief delay for the library read WAV info
  delay(10);

  while (playWav1.isPlaying()) {
  }
}

void draw(void)
{
  //GD.Begin(POINTS);
 
  for(float32_t y = 0; y < 96; y+=1.0)//speed up by drawing interlaced half width screen
    for(float32_t x = 0; x < 160; x+=1.0) //speed up by drawing interlaced half width screen
    {
      arm_sqrt_f32(((x-rx2)*(x-rx2)+(y-ry2)*(y-ry2)+1), &sqrtsums);

      color=int(128.0 + (128.0 * arm_sin_f32((x+timeAnim) * inv16)) +
                128.0 + (128.0 * arm_sin_f32((y-timeAnim) * inv8))  + 
                128.0 + (128.0 * arm_sin_f32((x+y+timeAnim) * inv32)) +
                128.0 + (128.0 * arm_sin_f32(sqrtsums * inv7)) )>>2; 

       plasmaArray[(int)(y*160+x)]=palette[color];


  }

  //copiar array a la ft
  SPI.beginTransaction(settingsT36);
  //UTILIZAMOS TECNICA DOBLE BUFFER
   if(intercambia == 0)  GD.cmd_memwrite(0, 30720L);
   else GD.cmd_memwrite(0x7800, 30720L);

  uint32_t valor=0;
  for (int i = 0; i < 15360;  i+=2) {
    valor=plasmaArray[i]+(plasmaArray[i+1]<<16);
    GD.cmd32(valor);
  }
   visualizaBuffer();
   intercambia=(intercambia==0?1:0);//UTILIZAMOS TECNICA DOBLE BUFFER
  SPI.endTransaction();
}

void loop()
{
    
    angulo=(incAngulo * 2.0 * PI)/360.0;//Convertir de grados a radianes
    //rotar punto (800,240) alrededor de (400,240)
    //p'x = cos(theta) * (px-ox) - sin(theta) * (py-oy) + ox
    rx2 = arm_cos_f32(angulo) * (400.0) + 400.0; 
    //p'y = sin(theta) * (px-ox) + cos(theta) * (py-oy) + oy
    ry2 = arm_sin_f32(angulo) * 400.0 + 240.0;
    timeAnim+=3.2f;

    draw();
    
    pos-=4;
    if (pos < -400) pos=1100;
    if(timeAnim > 1000000.0) timeAnim=0.0;
    incAngulo+=0.025;
    if(incAngulo > 360.0) incAngulo=0.0;
}

void visualizaBuffer(void)
{
  //GD.Clear();

  GD.Begin(BITMAPS);
  // El bitmap original tiene 160x96pixeles en formato RGB565

  //UTILIZAMOS TECNICA DOBLE BUFFER
  if(!(intercambia == 0)) GD.BitmapSource(0x7800); //UTILIZAMOS TECNICA DOBLE BUFFER
  else GD.BitmapSource(0x0);
  //GD.BitmapLayoutH(1,0);
  GD.BitmapLayout(RGB565, 160*2, 96);//EL line stride es de 160pixeles x 2 bytes por pixel
  GD.BitmapSizeH(1, 0); //como se va a escalar al ancho de pantalla de 800 pixeles (>511) se toma 1*(2^11) para el ancho
  GD.BitmapSize(BILINEAR, BORDER, BORDER, 800, 480);//segun la documentación de FTDI el ancho deberia ser 800-512=288 no 800


  GD.cmd_scale(F16(5), F16(5));
  GD.cmd_setmatrix();
  GD.Vertex2ii(0, 0);
  GD.swap();
}

