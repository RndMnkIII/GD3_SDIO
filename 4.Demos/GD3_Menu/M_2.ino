void M2base() //Temperaturas-PC
{
 while(1) {
//   GD.ClearColorRGB(0xffff00);  //fondo uniforme            
   GD.Clear();      
//   GD.cmd_gradient(0, 0, 0xFFA500, 0, 271, 0xc060000);     
   GD.cmd_gradient(0, 0, 0x002510, 0, 271, 0xc060000);   
   GD.get_inputs();
 
  GD.SaveContext(); 
   Panel();
  GD.RestoreContext();  
 
   GD.ColorRGB(0xff0000); //color del texto del boton
   GD.Tag(7); GD.cmd_button(352, 12, 40, 30, 28, 0,  "MP");  GD.Tag(255);
    if (GD.inputs.tag==7){
        delay(145);
         if(despPD==0){xDbase=160; despPD=0; velPD=0;}
         movx = movxbase;        
         MP();
      }
 GD.swap();
 }
}  

void M2_panelizq_base() //Temperaturas-PC
{
 while(1) {
   GD.Clear();   GD.cmd_gradient(0, 0, 0x002510, 0, 271, 0xc060000);   
   GD.get_inputs();
 
  GD.SaveContext(); 
//   Panel();
  GD.ColorA(115);  
  Poly po;
   GD.ColorRGB(0x008A4B);
  //Panel izquierdo
  if (movx==0){movx = 0;}else{movx = movx + velocidadx;}  
   GD.Tag(204);  po.begin();  po.v(16*(0+movx),16*0);                     po.v(16*(140+movx),16*0);                   po.v(16*(80+movx),16*60);                po.v(16*(0+movx),16*60);  po.draw();  GD.Tag(255);  
   GD.Tag(201);  po.begin();  po.v(16*(0+movx),16*60+separacionpanel);   po.v(16*(80+movx),16*60+separacionpanel);   po.v(16*(80+movx),16*110);                      po.v(16*(0+movx),16*110);    po.draw();  GD.Tag(255);  
   GD.Tag(202);  po.begin();  po.v(16*(0+movx),16*110+separacionpanel);  po.v(16*(80+movx),16*110+separacionpanel);  po.v(16*(80+movx),16*160);                      po.v(16*(0+movx),16*160);    po.draw();  GD.Tag(255);  
   GD.Tag(203);  po.begin();  po.v(16*(0+movx),16*160+separacionpanel);  po.v(16*(80+movx),16*160+separacionpanel);  po.v(16*(80+movx),16*212-(4*separacionpanel));  po.v(16*(0+movx),16*212-(4*separacionpanel)); po.draw();  GD.Tag(255);  
   po.begin();  po.v(16*(0+movx),16*272);                  po.v(16*(140+movx),16*272);                 po.v(16*(80+movx),16*212);               po.v(16*(0+movx),16*212);    po.draw();
  //Panel izquierdo   

   GD.ColorA(255);   
   
   
  GD.RestoreContext();  
 
   GD.ColorRGB(0xff0000); //color del texto del boton
   GD.Tag(7); GD.cmd_button(352, 12, 40, 30, 28, 0,  "MP");  GD.Tag(255);
    if (GD.inputs.tag==7){
        delay(145);
         if(despPD==0){xDbase=160; despPD=0; velPD=0;}
         movx = movxbase;        
         MP();
      }
 GD.swap();
 }
}  

int movxFondo, MXf;

void M2baseT() //Temperaturas-PC
{
//  LOAD_ASSETS0();  
//  GD.BitmapHandle(15);
//  GD.cmd_loadimage(ASSETS_END, 0);
//  GD.load("PC1.jpg");  //si lo carga XD  335x272
  
 while(1) {
   GD.ClearColorRGB(0x001000);  //fondo uniforme     
    GD.Clear();   
  //  GD.cmd_gradient(0, 0, 0x002510, 0, 271, 0xc060000);  //no es compatible con la carga posterior de imagenes
   
//   GD.SaveContext();    
//    GD.Begin(BITMAPS);  //GD.Vertex2ii(0, 0);  
//    GD.Vertex2ii((480-335), 0, 15);   //Carga imagen de fondo, PC1.jpg
    
  //  CargaIconos();
    
   // GD.Vertex2ii(0, 45, 0);
   // GD.Vertex2ii(0, 93, 1);
   // GD.Vertex2ii(0, 141, 2);
   // GD.Vertex2ii(0, 189, 3);
    
   // GD.Vertex2ii(60, 45, 4);
   // GD.Vertex2ii(60, 93, 5);
   // GD.Vertex2ii(60, 141, 6);
   // GD.Vertex2ii(60, 189, 7);
    
   // GD.Vertex2ii(120, 45, 8);
   // GD.Vertex2ii(120, 93, 9);
   // GD.Vertex2ii(120, 141, 10);
   // GD.Vertex2ii(120, 189, 11);
    
   // GD.Vertex2ii(180, 45, 12);
   // GD.Vertex2ii(180, 93, 13);     
 //  GD.RestoreContext();   
  
   GD.get_inputs();
 
  GD.SaveContext(); 
//   Panel();
  GD.ColorA(115);  
  
  Poly po;
   GD.ColorRGB(0x008A4B);
  //Panel izquierdo
  if (movx==0){movx = 0;}else{movx = movx + velocidadx;}  
   GD.Tag(204);  po.begin();  po.v(16*(0+movx),16*0);                     po.v(16*(140+movx),16*0);                   po.v(16*(80+movx),16*60);                po.v(16*(0+movx),16*60);  po.draw();  GD.Tag(255);  
   GD.Tag(201);  po.begin();  po.v(16*(0+movx),16*60+separacionpanel);   po.v(16*(80+movx),16*60+separacionpanel);   po.v(16*(80+movx),16*110);                      po.v(16*(0+movx),16*110);    po.draw();  GD.Tag(255);  
   GD.Tag(202);  po.begin();  po.v(16*(0+movx),16*110+separacionpanel);  po.v(16*(80+movx),16*110+separacionpanel);  po.v(16*(80+movx),16*160);                      po.v(16*(0+movx),16*160);    po.draw();  GD.Tag(255);  
   GD.Tag(203);  po.begin();  po.v(16*(0+movx),16*160+separacionpanel);  po.v(16*(80+movx),16*160+separacionpanel);  po.v(16*(80+movx),16*212-(4*separacionpanel));  po.v(16*(0+movx),16*212-(4*separacionpanel)); po.draw();  GD.Tag(255);  
   po.begin();  po.v(16*(0+movx),16*272);                  po.v(16*(140+movx),16*272);                 po.v(16*(80+movx),16*212);               po.v(16*(0+movx),16*212);    po.draw();
  //Panel izquierdo   
  
    movxFondo = movx;   MXf = (480-(160+movxFondo)*2.1);  //Al ingresar= MXf va de 480 a 144
    
  GD.ColorA(255);   
  GD.RestoreContext();  
  
   GD.SaveContext();    
    GD.Begin(BITMAPS);  //GD.Vertex2ii(0, 0);  
    GD.Vertex2ii(MXf, 0, 15);   //Carga imagen de fondo, PC1.jpg
   GD.RestoreContext();   

   GD.ColorRGB(0xffffff);  GD.cmd_text(TxPD, 206, 18, 0, "MXf= ");   GD.cmd_number(TxPD+80, 206, 18, OPT_RIGHTX | OPT_SIGNED, MXf); 
   GD.ColorRGB(0xffffff);  GD.cmd_text(TxPD, 206+20, 18, 0, "MXf0= ");   GD.cmd_number(TxPD+80, 206+20, 18, OPT_RIGHTX | OPT_SIGNED, 480);     
 
    if (GD.inputs.tag==204){
        delay(145);
         if(despPD==0){xDbase=160; despPD=0; velPD=0;}
         movx = movxbase; 
         MP();
      }
 GD.swap();
 }
}  

void M2() //Temperaturas-PC
{
 LecturaSensor1();  T1a = T1; T1g = T1a;  //Primer lectura del sensorT 1
  
 while(1) {
   GD.ClearColorRGB(0x001000);  //fondo uniforme     
   GD.Clear();   
   GD.get_inputs();
 
   GD.SaveContext(); 
   GD.ColorA(115);  

  Poly po;
  GD.ColorRGB(0x008A4B);
  //Panel izquierdo
  if (movx==0){movx = 0;}else{movx = movx + velocidadx;}  
   GD.Tag(204);  po.begin();  po.v(16*(0+movx),16*0);                     po.v(16*(140+movx),16*0);                   po.v(16*(80+movx),16*60);                po.v(16*(0+movx),16*60);  po.draw();  GD.Tag(255);  
   GD.Tag(201);  po.begin();  po.v(16*(0+movx),16*60+separacionpanel);   po.v(16*(80+movx),16*60+separacionpanel);   po.v(16*(80+movx),16*110);                      po.v(16*(0+movx),16*110);    po.draw();  GD.Tag(255);  
   GD.Tag(202);  po.begin();  po.v(16*(0+movx),16*110+separacionpanel);  po.v(16*(80+movx),16*110+separacionpanel);  po.v(16*(80+movx),16*160);                      po.v(16*(0+movx),16*160);    po.draw();  GD.Tag(255);  
   GD.Tag(203);  po.begin();  po.v(16*(0+movx),16*160+separacionpanel);  po.v(16*(80+movx),16*160+separacionpanel);  po.v(16*(80+movx),16*212-(4*separacionpanel));  po.v(16*(0+movx),16*212-(4*separacionpanel)); po.draw();  GD.Tag(255);  
   po.begin();  po.v(16*(0+movx),16*272);                  po.v(16*(140+movx),16*272);                 po.v(16*(80+movx),16*212);               po.v(16*(0+movx),16*212);    po.draw();
  //Panel izquierdo   
  
  GD.ColorA(255);   
  GD.RestoreContext();  

   movxFondo = movx;   MXf = (480-(160+movxFondo)*2.1);  //Al ingresar= MXf va de 480 a 144  
   
   GD.SaveContext();    
    GD.Begin(BITMAPS);  //GD.Vertex2ii(0, 0);  
    GD.Vertex2ii(MXf, 0, 15);   //Carga imagen de fondo, PC1.jpg
   GD.RestoreContext();   

   GD.ColorRGB(0xffffff);  GD.cmd_text(TxPDF, 206, 18, 0, "MXf= ");   GD.cmd_number(TxPDF+80, 206, 18, OPT_RIGHTX | OPT_SIGNED, MXf); 
   GD.ColorRGB(0xffffff);  GD.cmd_text(TxPDF, 206+20, 18, 0, "MXf0= ");   GD.cmd_number(TxPDF+80, 206+20, 18, OPT_RIGHTX | OPT_SIGNED, 480);     

//   Grafico1V(80,200);  //Gráfico vertical sensorT1
   Grafico1V(105,190);  //Gráfico vertical sensorT1
   
 
    if (GD.inputs.tag==204){
        delay(145);
         if(despPD==0){xDbase=160; despPD=0; velPD=0;}
         movx = movxbase; 
         MP();
      }
  GD.swap();
 }
}
