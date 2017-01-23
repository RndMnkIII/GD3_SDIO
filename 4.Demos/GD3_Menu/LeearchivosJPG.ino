void ReadJPGname()
{
    int j = 0;
    dirent de;
    GD.__end();
    do {
      GD.SD.rdn((byte*)&de, GD.SD.o_root + j * 32, sizeof(de));
      if ((0x20 < de.name[0]) && (de.name[0] < 0x80)) {
        if (memcmp(de.ext, "JPG", 3) == 0) {
          if (num_jpgs < MAX_IMAGES) {
            char *pd = directory[num_jpgs++];
            byte i;
            for (i = 0; i < 8 && de.name[i] != ' '; i++)
              *pd++ = tolower(de.name[i]);
            if (i != 8)
              *pd = 0;
          }
        }
      }
      j++;
    } while (de.name[0]);
    GD.resume();  
}  

