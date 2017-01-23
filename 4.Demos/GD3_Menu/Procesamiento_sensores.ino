void Procesamiento1(){
 GD.ColorRGB(0xffffff);  GD.cmd_text(TxPD, 206, 18, 0, " T1a= ");   plotfloat(TxPD+85, 206, T1a, 1, 18);        
 GD.ColorRGB(0xffffff);  GD.cmd_text(TxPD, 206+20, 18, 0, " T1b= ");   plotfloat(TxPD+85, 206+20, T1b, 1, 18);      
 GD.ColorRGB(0xffffff);  GD.cmd_text(TxPD, 206+20+20, 18, 0, "DT1g= ");   plotfloat(TxPD+85, 206+20+20, DT1g, 1, 18);        

   if (T1g==T1b){T1g=T1b;}else{T1g = T1g + DT1g;}  //modifica Tg hasta alcanzar valor estable nuevo igual a Tb
   
 GD.ColorRGB(0xffffff);  GD.cmd_text(TxPD, 206-20, 18, 0, "T1g= ");   plotfloat(TxPD+85, 206-20, T1g, 1, 18);  //graficar T1g

//Escala
 GD.SaveContext();
  GD.ColorRGB(255, 255, 255); 
  GD.Begin(LINES);
  GD.LineWidth(25);

//  Escala vertical
   GD.Vertex2ii(80, 200); GD.Vertex2ii(90, 200);          //   0C
   GD.Vertex2ii(85, 200-10); GD.Vertex2ii(90, 200-10);    //  10C    
   GD.Vertex2ii(85, 200-20); GD.Vertex2ii(90, 200-20);    //  20C       
   GD.Vertex2ii(85, 200-30); GD.Vertex2ii(90, 200-30);    //  30C       
   GD.Vertex2ii(85, 200-40); GD.Vertex2ii(90, 200-40);    //  40C    
   GD.Vertex2ii(80, 200-50); GD.Vertex2ii(90, 200-50);    //  50C       
   GD.Vertex2ii(85, 200-60); GD.Vertex2ii(90, 200-60);    //  60C    
   GD.Vertex2ii(85, 200-70); GD.Vertex2ii(90, 200-70);    //  70C    
   GD.Vertex2ii(85, 200-80); GD.Vertex2ii(90, 200-80);    //  80C    
   GD.Vertex2ii(85, 200-90); GD.Vertex2ii(90, 200-90);    //  90C       
   GD.Vertex2ii(80, 200-100); GD.Vertex2ii(90, 200-100);  // 100C
//  Escala vertical

//  Escala horizontal  
   GD.Vertex2ii(100, 60); GD.Vertex2ii(100, 50);          //   0C   
   GD.Vertex2ii(110, 60); GD.Vertex2ii(110, 55);          //  10C   
   GD.Vertex2ii(120, 60); GD.Vertex2ii(120, 55);          //  20C   
   GD.Vertex2ii(130, 60); GD.Vertex2ii(130, 55);          //  30C   
   GD.Vertex2ii(140, 60); GD.Vertex2ii(140, 55);          //  40C      
   GD.Vertex2ii(150, 60); GD.Vertex2ii(150, 50);          //  50C  
   GD.Vertex2ii(160, 60); GD.Vertex2ii(160, 55);          //  60C      
   GD.Vertex2ii(170, 60); GD.Vertex2ii(170, 55);          //  70C      
   GD.Vertex2ii(180, 60); GD.Vertex2ii(180, 55);          //  80C      
   GD.Vertex2ii(190, 60); GD.Vertex2ii(190, 55);          //  90C         
   GD.Vertex2ii(200, 60); GD.Vertex2ii(200, 50);          // 100C      
//  Escala horizontal  

 GD.RestoreContext();
//Escala

//Lectura
 GD.SaveContext();
  GD.ColorRGB(255, 255, 0); 
  GD.Begin(POINTS);
  GD.PointSize(16 * 4);
   GD.Vertex2ii(103, 200-T1g);
 GD.RestoreContext();

 GD.SaveContext();
  GD.ColorRGB(255, 0, 0); 
  GD.Begin(LINES);
  GD.LineWidth(20);
   GD.Vertex2ii(88, 200-T1g); GD.Vertex2ii(103, 200-T1g); 
   GD.Vertex2ii(103, 200); GD.Vertex2ii(103, 200-T1g);    
 GD.RestoreContext();

 GD.SaveContext();
  GD.ColorRGB(255, 255, 0); 
  GD.Begin(POINTS);
  GD.PointSize(16 * 4);
   GD.Vertex2ii(100+T1g, 75);
 GD.RestoreContext();

 GD.SaveContext();
  GD.ColorRGB(255, 0, 0); 
  GD.Begin(LINES);
  GD.LineWidth(20);
   GD.Vertex2ii(100+T1g, 75); GD.Vertex2ii(100+T1g, 60); 
   GD.Vertex2ii(100, 75); GD.Vertex2ii(100+T1g, 75);    
 GD.RestoreContext();

//Lectura 
 
//luego de procesar la gráfica 
 T1a = T1g;  
}


void Procesamiento1Vbase(){
// GD.ColorRGB(0xffffff);  GD.cmd_text(TxPD, 206, 18, 0, " T1a= ");   plotfloat(TxPD+85, 206, T1a, 1, 18);        
// GD.ColorRGB(0xffffff);  GD.cmd_text(TxPD, 206+20, 18, 0, " T1b= ");   plotfloat(TxPD+85, 206+20, T1b, 1, 18);      
// GD.ColorRGB(0xffffff);  GD.cmd_text(TxPD, 206+20+20, 18, 0, "DT1g= ");   plotfloat(TxPD+85, 206+20+20, DT1g, 1, 18);        

   if (T1g==T1b){T1g=T1b;}else{T1g = T1g + DT1g;}  //modifica Tg hasta alcanzar valor estable nuevo igual a Tb
   
 GD.ColorRGB(0xffffff);  GD.cmd_text(TxPD, 206-20, 18, 0, "T1g= ");   plotfloat(TxPD+85, 206-20, T1g, 1, 18);  //graficar T1g

//Escala
 GD.SaveContext();
  GD.ColorRGB(255, 255, 255); 
  GD.Begin(LINES);
  GD.LineWidth(25);

//  Escala vertical
   GD.Vertex2ii(80, 200); GD.Vertex2ii(90, 200);          //   0C
   GD.Vertex2ii(85, 200-10); GD.Vertex2ii(90, 200-10);    //  10C    
   GD.Vertex2ii(85, 200-20); GD.Vertex2ii(90, 200-20);    //  20C       
   GD.Vertex2ii(85, 200-30); GD.Vertex2ii(90, 200-30);    //  30C       
   GD.Vertex2ii(85, 200-40); GD.Vertex2ii(90, 200-40);    //  40C    
   GD.Vertex2ii(80, 200-50); GD.Vertex2ii(90, 200-50);    //  50C       
   GD.Vertex2ii(85, 200-60); GD.Vertex2ii(90, 200-60);    //  60C    
   GD.Vertex2ii(85, 200-70); GD.Vertex2ii(90, 200-70);    //  70C    
   GD.Vertex2ii(85, 200-80); GD.Vertex2ii(90, 200-80);    //  80C    
   GD.Vertex2ii(85, 200-90); GD.Vertex2ii(90, 200-90);    //  90C       
   GD.Vertex2ii(80, 200-100); GD.Vertex2ii(90, 200-100);  // 100C
//  Escala vertical

 GD.RestoreContext();
//Escala

//Lectura
 GD.SaveContext();
  GD.ColorRGB(255, 255, 0); 
  GD.Begin(POINTS);
  GD.PointSize(16 * 4);
   GD.Vertex2ii(103, 200-T1g);
 GD.RestoreContext();

 GD.SaveContext();
  GD.ColorRGB(255, 0, 0); 
  GD.Begin(LINES);
  GD.LineWidth(20);
   GD.Vertex2ii(88, 200-T1g); GD.Vertex2ii(103, 200-T1g); 
   GD.Vertex2ii(103, 200); GD.Vertex2ii(103, 200-T1g);    
 GD.RestoreContext();

//luego de procesar la gráfica 
 T1a = T1g;  
//Lectura  
}

void Procesamiento1V(int TXV, int TYV, int TSV, int XG, int YG){
// GD.ColorRGB(0xffffff);  GD.cmd_text(TXV, TYV, TSV, 0, " T1a= ");   plotfloat(TXV+50, TYV, T1a, 1, TSV);        
// GD.ColorRGB(0xffffff);  GD.cmd_text(TXV, TYV+20, TSV, 0, " T1b= ");   plotfloat(TXV+50, TYV+20, T1b, 1, TSV);      
// GD.ColorRGB(0xffffff);  GD.cmd_text(TXV, TYV+20+20, TSV, 0, "DT1g= ");   plotfloat(TXV+50, TYV+20+20, DT1g, 1, TSV);        

   if (T1g==T1b){T1g=T1b;}else{T1g = T1g + DT1g;}  //modifica Tg hasta alcanzar valor estable nuevo igual a Tb
   
 GD.ColorRGB(0xffffff);  GD.cmd_text(TXV, TYV-20, TSV, 0, "T1= ");   plotfloat(TXV+50, TYV-20, T1g, 1, TSV);  //graficar T1g

//Escala
 GD.SaveContext();
  GD.ColorRGB(255, 255, 255); 
  GD.Begin(LINES);
  GD.LineWidth(25);

//  Escala vertical
   GD.Vertex2ii(XG, YG); GD.Vertex2ii(XG+10, YG);          //   0C
   GD.Vertex2ii(XG+5, YG-10); GD.Vertex2ii(XG+10, YG-10);    //  10C    
   GD.Vertex2ii(XG+5, YG-20); GD.Vertex2ii(XG+10, YG-20);    //  20C       
   GD.Vertex2ii(XG+5, YG-30); GD.Vertex2ii(XG+10, YG-30);    //  30C       
   GD.Vertex2ii(XG+5, YG-40); GD.Vertex2ii(XG+10, YG-40);    //  40C    
   GD.Vertex2ii(XG+0, YG-50); GD.Vertex2ii(XG+10, YG-50);    //  50C       
   GD.Vertex2ii(XG+5, YG-60); GD.Vertex2ii(XG+10, YG-60);    //  60C    
   GD.Vertex2ii(XG+5, YG-70); GD.Vertex2ii(XG+10, YG-70);    //  70C    
   GD.Vertex2ii(XG+5, YG-80); GD.Vertex2ii(XG+10, YG-80);    //  80C    
   GD.Vertex2ii(XG+5, YG-90); GD.Vertex2ii(XG+10, YG-90);    //  90C       
   GD.Vertex2ii(XG, YG-100); GD.Vertex2ii(XG+10, YG-100);  // 100C
//  Escala vertical

 GD.RestoreContext();
//Escala

//Lectura
 GD.SaveContext();
  GD.ColorRGB(255, 255, 0); 
  GD.Begin(POINTS);
  GD.PointSize(16 * 4);
   GD.Vertex2ii(XG+23, YG-T1g);
 GD.RestoreContext();

 GD.SaveContext();
  GD.ColorRGB(255, 0, 0); 
  GD.Begin(LINES);
  GD.LineWidth(20);
   GD.Vertex2ii(XG+8, YG-T1g); GD.Vertex2ii(XG+23, YG-T1g); 
   GD.Vertex2ii(XG+23, YG); GD.Vertex2ii(XG+23, YG-T1g);    
 GD.RestoreContext();

//luego de procesar la gráfica 
 T1a = T1g;  
//Lectura  
}
