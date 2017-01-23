void M1base()
{

 while(1) {
//   GD.ClearColorRGB(0xFFA500);  //fondo uniforme            
   GD.Clear();      
//   GD.cmd_gradient(0, 0, 0xFFA500, 0, 271, 0xc060000);     
   GD.cmd_gradient(0, 0, 0x002510, 0, 271, 0xc060000);     
   GD.get_inputs();

  GD.SaveContext(); 
   Panel();
   GD.Tag(11);  Insignia();  GD.Tag(255); 
  GD.RestoreContext();  

      
    if (GD.inputs.tag==11){
        delay(145);
         if(despPD==0){xDbase=160; despPD=0; velPD=0;}
         movx = movxbase;
         MP();
      }      
 GD.swap();
 }
}  

void M1()
{
//  procesandolista();  
//  ReadJPGname();  //Procesa la lista de nombres de archivos jpg
  while(1)
  {
    GD.Clear();
    GD.Begin(BITMAPS);  GD.Vertex2ii(0, 0); 

GD.SaveContext();
   GD.LineWidth(48);   GD.Begin(RECTS);   GD.ColorRGB(0xcccccc);   GD.ColorA(105);
   GD.Vertex2f(16*345, 16*0);
   GD.Vertex2f(16*455, 16*272);
GD.RestoreContext();
  
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

//   GD.Tag(204);  Insignia();  GD.Tag(255); 
   GD.ColorA(255); 
  GD.RestoreContext();  

    showdir1(directory, num_jpgs, ymov, -1);
    GD.ColorRGB(0xffffff);  GD.cmd_text(120, 255, 18, OPT_RIGHTX, getdir(directory, NombreJPG));  //Nombre del archivo jpg seleccionado

if (NombreJPG==12){valores = 1;}else{if (NombreJPG==96){valores = 2;}else{valores = 3;}}
switch (valores)
    {
      case 1:
        Cheapy1(0,0,255);
        break;
      case 2:
        Cylon1(255,0,0);
        break;
      case 3:
     //   pixels.clear();
        break;
    }


   picked = GD.inputs.tag;  
    if ((picked>=1) && (picked<=MAX_IMAGES)) 
        {
         procesandoentorno();
         NombreJPG = picked-1; 
         CargaJPG(NombreJPG);
        }     
   GD.Tag(255);


    if (GD.inputs.tag==201){
          ymov = ymov + 8; 
          if (ymov>= limsup){ymov=-272;}
      }

   if (GD.inputs.tag==202){
          ymov = ymov - 8; 
          if (ymov<=-272){ymov=limsup;}
      }
      
    if (GD.inputs.tag==203){
       //    pixels.clear(); pixels.show(); movx = movxbase; //GD.cmd_fgcolor(0x954500);
           GD.cmd_fgcolor(0x008A4B);  //este comando de color previo al menu donde se usará, evita tirones en la gráfica lineal del analizador XD
           Analizador();
      }      
   GD.Tag(255);      
   
    if (GD.inputs.tag==204){
        delay(145);
         if(despPD==0){xDbase=160; despPD=0; velPD=0;}
         movx = movxbase;
         
         procesandolista();
        // ReadJPGname();
         CargaJPG_iconos1(120);           
         
         MP();
      }         
      
    GD.ColorRGB(0xffffff);  plotfloat(175, 255, NombreJPG, 1, 18);  plotfloat(280, 255, ymov, 1, 18);
  //  pixels.show();
    GD.swap();
  }
}

void Cheapy1(int CR, int CG, int CB) 
{
 //    pixels.setPixelColor(30, pixels.Color(CR,CG,CB));  pixels.setPixelColor(31, pixels.Color(CR,CG,CB)); pixels.setPixelColor(32, pixels.Color(CR,CG,CB));
 //    pixels.setPixelColor(15, pixels.Color(CR,CG,CB));  pixels.setPixelColor(16, pixels.Color(CR,CG,CB)); pixels.setPixelColor(17, pixels.Color(CR,CG,CB));
 //    pixels.setPixelColor(0, pixels.Color(CR,CG,CB));   pixels.setPixelColor(1, pixels.Color(CR,CG,CB));  pixels.setPixelColor(2, pixels.Color(CR,CG,CB));
     
  //   pixels.setPixelColor(42, pixels.Color(CR,CG,CB));  pixels.setPixelColor(43, pixels.Color(CR,CG,CB)); pixels.setPixelColor(44, pixels.Color(CR,CG,CB));
  //   pixels.setPixelColor(27, pixels.Color(CR,CG,CB));  pixels.setPixelColor(28, pixels.Color(CR,CG,CB)); pixels.setPixelColor(29, pixels.Color(CR,CG,CB));
 //    pixels.setPixelColor(12, pixels.Color(CR,CG,CB));   pixels.setPixelColor(13, pixels.Color(CR,CG,CB));  pixels.setPixelColor(14, pixels.Color(CR,CG,CB)); //pixels.show();     
}


void Cylon1(int CR, int CG, int CB) 
{
 if (xico==15){movimiento1=1;}   //extremo izquierdo
 if (xico==29){movimiento1=-1;}  //extremo derecho
 // pixels.clear();
 // pixels.setPixelColor(xico+15, pixels.Color(CR,CG,CB));    
 // pixels.setPixelColor(xico, pixels.Color(CR,CG,CB));
//  pixels.setPixelColor(xico-15, pixels.Color(CR,CG,CB));
  xico=xico+movimiento1;
} 
