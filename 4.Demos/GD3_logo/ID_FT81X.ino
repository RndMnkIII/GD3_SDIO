void Identif()
{
  if (FT_810_ENABLE==1){GD.cmd_text(225+DespX, 100, 15, OPT_CENTER, "FT810");}
  if (FT_811_ENABLE==1){GD.cmd_text(225+DespX, 100, 15, OPT_CENTER, "FT811");}
  if (FT_812_ENABLE==1){GD.cmd_text(225+DespX, 100, 15, OPT_CENTER, "FT812");}
  if (FT_813_ENABLE==1){GD.cmd_text(225+DespX, 100, 15, OPT_CENTER, "FT813");}
}  

void IdentifMCU(){
  if (MCU_Teensy3X==6){GD.cmd_text(225+DespX, 140, 28, OPT_CENTER, "Teensy 3.6");}
  if (MCU_Teensy3X==2){GD.cmd_text(225+DespX, 140, 28, OPT_CENTER, "Teensy 3.2");}
  if (MCU_Teensy3X==0){GD.cmd_text(225+DespX, 140, 28, OPT_CENTER, "Arduino");}
}
