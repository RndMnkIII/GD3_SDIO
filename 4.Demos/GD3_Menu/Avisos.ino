void procesandoentorno1()
{
  GD.ClearColorRGB(0x103000);  
  GD.Clear();
  GD.ColorRGB(0xffffff);  
    GD.cmd_text((480/ 2), (272 / 2), 27,   OPT_CENTERX, "Procesando entorno visual...");
    GD.cmd_number((480 / 2)-(480 / 13), (272 / 2)+(272 / 18), 27, 0, 480);
    GD.cmd_number((480 / 2)+(480 / 80), (272 / 2)+(272 / 18), 27, 0, 272);
    GD.cmd_text(480 / 2, (272 / 2)+(272 / 18), 27, OPT_CENTERX, "x");        
    
  GD.SaveContext();
     GD.Begin(BITMAPS);
     GD.Vertex2ii(210, 140, 2);
  GD.RestoreContext();              
  GD.swap(); 
}  

void procesandoentorno()
{
  GD.ClearColorRGB(0x103000);  
  GD.Clear();
  GD.ColorRGB(0xffffff);  
    GD.cmd_text((480 / 2), (272 / 2), 27,   OPT_CENTERX, "Procesando entorno visual...");
    GD.cmd_number((480 / 2)-(480 / 13), (272 / 2)+(272 / 18), 27, 0, 480);
    GD.cmd_number((480 / 2)+(480 / 80), (272 / 2)+(272 / 18), 27, 0, 272);
    GD.cmd_text(480 / 2, (272 / 2)+(272 / 18), 27, OPT_CENTERX, "x");    
  GD.swap(); 
}  

void procesandolista()
{
  GD.ClearColorRGB(0x103000);  
  GD.Clear();
  GD.ColorRGB(0xffffff);  
    GD.cmd_text((480 / 2), (272 / 2), 27,   OPT_CENTERX, "Cargando sistema...");
    GD.cmd_number((480 / 2)-(480 / 13), (272 / 2)+(272 / 18), 27, 0, 480);
    GD.cmd_number((480 / 2)+(480 / 80), (272 / 2)+(272 / 18), 27, 0, 272);
    GD.cmd_text(480 / 2, (272 / 2)+(272 / 18), 27, OPT_CENTERX, "x");        
  GD.swap(); 
}

void espera()
{
  GD.ClearColorRGB(0x000025); //fondo de pantalla
  GD.Clear();
    GD.ColorA(255);  
    GD.cmd_text(240, 120, 26,   OPT_CENTERX, "Procesando entorno visual...");    
  GD.swap(); 
}
