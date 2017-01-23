//#include <EEPROM.h>
#include <SPI.h>
#include <GD3.h>

#include "logogd3.h"

void setup()
{
  Serial.begin(9600);
  GD.begin();
  GD.cmd_setrotate(0);
  LOAD_ASSETS1();  
}

byte clamp255(int x)
{
  if (x < 0)
    return 0;
  if (255 < x)
    return 255;
  return x;
}

struct xy {
  int x, y;
};

//#define NSTARS 256
#define NSTARS 512

int DespX=150, DespY=90;

void loop()
{
  byte fade;
  xy stars[NSTARS];
  for (int i = 0; i < NSTARS; i++) {
    stars[i].x = GD.random(16 * 800);
    stars[i].y = GD.random(16 * 480);
  }

  for (int t = 0; t < 464; t++) {
    GD.cmd_gradient(0, 0, 0x120000, 0, 480, 0x480000);
    GD.BlendFunc(SRC_ALPHA, ONE);
    GD.Begin(POINTS);
    for (int i = 0; i < NSTARS; i++) {
      GD.ColorA(64 + (i >> 2));
      GD.PointSize(8 + (i >> 5));
      GD.Vertex2f(stars[i].x, stars[i].y);
      // stars drift left, then wrap around
      stars[i].x -= 1 + (i >> 5);
      if (stars[i].x < -256) {
        stars[i].x += (16 * 800);
        stars[i].y = GD.random(16 * 480);
      }
    }
    GD.RestoreContext();
    GD.Begin(BITMAPS);

    // Main logo fades up from black
    fade = clamp255(5 * (t - 15));
    GD.ColorRGB(fade, fade, fade);
    //GD.Vertex2ii(302, 75, L0_HANDLE, 0);
     //GD.Vertex2ii(270+DespX, 155+DespY, L2_HANDLE, 0);
     GD.Vertex2ii(DespX+240 - L1_WIDTH/2, 65+DespY, L1_HANDLE, 0);    
    GD.RestoreContext();

    // The '3' and its glow
    fade = clamp255(8 * (t - 120));
    GD.ColorA(fade);   GD.ColorRGB(fade, fade, 0);
    GD.Vertex2ii(270+DespX, 155+DespY, L2_HANDLE, 0);
    
    GD.SaveContext();
    GD.cmd_romfont(15,32);  GD.ColorRGB(fade, fade, 0);
     Identif();
    //GD.Vertex2ii(302, 75, L0_HANDLE, 0);
    GD.RestoreContext();   
     IdentifMCU();
    fade = clamp255(5 * (t - 144));

    // The text fades up. Its glow is a full-screen bitmap
    fade = clamp255(8 * (t - 160));
    GD.ColorA(fade);

    fade = clamp255(5 * (t - 184));
    GD.BlendFunc(SRC_ALPHA, ONE);
    GD.ColorA(fade);
    GD.ColorRGB(85,85,85);

    // Fade to white at the end by drawing a white rectangle on top
    fade = clamp255(5 * (t - 400));
    GD.ColorA(fade);
    GD.Begin(RECTS);
    GD.Vertex2ii(0, 0, 0, 0);
    GD.Vertex2ii(800, 480, 0, 0);
    GD.swap();
  }
}
