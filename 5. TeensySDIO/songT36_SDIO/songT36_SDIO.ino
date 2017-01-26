#include <EEPROM.h>
#include <SPI.h>
#include <GD3.h>
#include "SdFat.h"

#define MUSICFILE   "mesmeriz.ima"
char texto[40];
int valor=0;
static StreamerSDIO stream;
SdFatSdioEX SD;
void setup()
{
  GD.begin();
  GD.cmd_setrotate(1);
  SD.begin();
  SD.chvol();
  stream.begin(MUSICFILE);
}

void loop()
{
  GD.cmd_gradient(0, 40, 0x282830,
                  0, 272, 0x606040);
  GD.cmd_text(240, 100, 31, OPT_CENTER, MUSICFILE);
  
  uint16_t val, range;
  stream.progress(val, range);
  GD.cmd_slider(30, 160, 420, 8, 0, val, range);
      sprintf(texto, "Feed: %d", valor); 
  GD.cmd_text(240, 140, 31, OPT_CENTER, texto);

  GD.swap();
  GD.finish();
  valor=stream.feed();

}
