static char *getdir(char directory[MAX_IMAGES][8], int i)
{
  static char nm[8 + 1 + 3 + 1];
  nm[8] = 0;
  strncpy(nm, directory[i], 8);
  strcat(nm, ".jpg");
  return nm;
}

int colorselecto; //codifica el color proveniente del menu principal, en este caso: LeenombreJPG()

static void showdir1(char directory[MAX_IMAGES][8], int num_jpgs, int yb, int sel)
{
  GD.ColorA(0xff);  //GD.ColorRGB(0x000000);
  for (int j = 0; j < num_jpgs; j++) {
    int y = 26 * j - yb;
    if ((-50 < y) && (y < 272)) {
      colorselecto= j;  if (colorselecto==NombreJPG){GD.ColorRGB(0xff0000);}else{GD.ColorRGB(0x000000);}   //Resalta el nombre de la imagen en uso en el menu principal, en este caso: LeenombreJPG()
      GD.Tag(1 + j);   GD.cmd_text(xTextJPG, y + 15+delta, 18, OPT_RIGHTX, getdir(directory, j));             
      
      
    }
  }
}

