

void MP() //Menu principal
{
 while(1) {
  GD.ClearColorRGB(0x000020);  //fondo uniforme      
  GD.Clear();   
//  GD.cmd_gradient(0, 0, 0x0000ff, 0, 271, 0xc060000);       //afecta la carga de la imagen 15
  GD.get_inputs();

   //GD.SaveContext();    
   //  GD.Begin(BITMAPS);  //GD.Vertex2ii(0, 0);  
   //  GD.Vertex2ii((480-335), 0, 15);   //Carga imagen de fondo, PC1.jpg, el tamaño de la imagen interfiere con el gradiente, los iconos se dibujan sin problema
   //  CargaIconos(); 
   //GD.RestoreContext();   
    
  GD.SaveContext();
  //Panel izquierdo   
   GD.ColorA(150);  
   Poly po;   GD.ColorRGB(0x008B4B);
    if (movx==0){movx = 0;}else{movx = movx + velocidadx;}
   GD.Tag(1);   po.begin();  po.v(16*(0+movx),16*0);                    po.v(16*(140+movx),16*0);                   po.v(16*(80+movx),16*60);                po.v(16*(0+movx),16*60);  po.draw(); GD.Tag(255);
   GD.Tag(2);   po.begin();  po.v(16*(0+movx),16*60+separacionpanel);   po.v(16*(80+movx),16*60+separacionpanel);   po.v(16*(80+movx),16*110);                      po.v(16*(0+movx),16*110);    po.draw();  GD.Tag(255);
   GD.Tag(3);   po.begin();  po.v(16*(0+movx),16*110+separacionpanel);  po.v(16*(80+movx),16*110+separacionpanel);  po.v(16*(80+movx),16*160);                      po.v(16*(0+movx),16*160);    po.draw();  GD.Tag(255);
   GD.Tag(4);   po.begin();  po.v(16*(0+movx),16*160+separacionpanel);  po.v(16*(80+movx),16*160+separacionpanel);  po.v(16*(80+movx),16*212-(4*separacionpanel));  po.v(16*(0+movx),16*212-(4*separacionpanel)); po.draw(); GD.Tag(255);
   GD.Tag(5);   po.begin();  po.v(16*(0+movx),16*272);                  po.v(16*(140+movx),16*272);                 po.v(16*(80+movx),16*212);               po.v(16*(0+movx),16*212);    po.draw();  GD.Tag(255);
  //Panel izquierdo 

//   PanelDerecho();
  
   GD.ColorRGB(0x008B4B);
   xDbase = xDbase + velPD;
   if (xDbase==160){velPD=0;}
   if (xDbase==0){velPD=0;}   
   GD.Tag(10);    po.begin();  po.v(16*(340+xDbase),16*0);   po.v(16*(480+xDbase),16*0);   po.v(16*(480+xDbase),16*60);   po.v(16*(400+xDbase),16*60);  po.draw();  GD.Tag(10);
   GD.Tag(11);    po.begin();  po.v(16*(400+xDbase),16*60+separacionpanel);   po.v(16*(480+xDbase),16*60+separacionpanel);   po.v(16*(480+xDbase),16*110);    po.v(16*(400+xDbase),16*110);    po.draw();   GD.Tag(10);
   GD.Tag(12);    po.begin();  po.v(16*(400+xDbase),16*110+separacionpanel);  po.v(16*(480+xDbase),16*110+separacionpanel);  po.v(16*(480+xDbase),16*160);    po.v(16*(400+xDbase),16*160);    po.draw();   GD.Tag(10);
   GD.Tag(13);    po.begin();  po.v(16*(400+xDbase),16*160+separacionpanel);  po.v(16*(480+xDbase),16*160+separacionpanel);  po.v(16*(480+xDbase),16*212-(4*separacionpanel)); po.v(16*(400+xDbase),16*212-(4*separacionpanel)); po.draw();  GD.Tag(10);
   GD.Tag(14);    po.begin();  po.v(16*(340+xDbase),16*272);    po.v(16*(480+xDbase),16*272);   po.v(16*(480+xDbase),16*212);    po.v(16*(400+xDbase),16*212);    po.draw();  GD.Tag(10);
   
   GD.ColorA(255); 
  GD.RestoreContext();    





//   GD.ColorRGB(0xffffff);  GD.cmd_text(TxPD, 206, 18, 0, "xDbase= ");   GD.cmd_number(TxPD+80, 206, 18, OPT_RIGHTX | OPT_SIGNED, xDbase);   
//   GD.ColorRGB(0xffffff);  GD.cmd_text(TxPD, 206+20, 18, 0, "despPD= ");   GD.cmd_number(TxPD+80, 206+20, 18, OPT_RIGHTX | OPT_SIGNED, despPD);   
//   GD.ColorRGB(0xffffff);  GD.cmd_text(TxPD, 206+40, 18, 0, " velPD= ");   GD.cmd_number(TxPD+80, 206+40, 18, OPT_RIGHTX | OPT_SIGNED, velPD);   


    if (GD.inputs.tag==2)
       {delay(145); xDbase = 160; velPD=-10; movx = movxbase;
         // procesandoentorno1();
          //RespaldoNombreJPG = NombreJPG;
          //CargaJPG_iconos1(120);//iconos y PC1.jpg
        M2();
       }
    if (GD.inputs.tag==3){delay(145); xDbase = 160; velPD=-10; movx = movxbase;  M3();}
    if (GD.inputs.tag==4){delay(145); xDbase = 160; velPD=-10; movx = movxbase;  M4();}
    if (GD.inputs.tag==5)
       {delay(145); 
         despPD = despPD + 1;
         if (despPD==1){velPD=-10;}
         if (despPD>=2){despPD=0; velPD=10;}         
       }

    if (GD.inputs.tag==10)
        {delay(145); xDbase = 160; velPD=-10; movx = movxbase; 
         procesandoentorno();
         RespaldoNombreJPG = NombreJPG;
        // ReadJPGname();
         CargaJPG(NombreJPG);  //w01.jpg, FT801_Riverdi, solo carga una imagen para no afectar despliegue de imagenes adicionales
         M1();
        }  //Selector de imagen del analizador de espectro simple
    if (GD.inputs.tag==11){delay(145); xDbase = 160; velPD=-10; movx = movxbase;  M5();}
    if (GD.inputs.tag==12){delay(145); xDbase = 160; velPD=-10; movx = movxbase;  M6();}
    if (GD.inputs.tag==13){delay(145); xDbase = 160; velPD=-10; movx = movxbase;  M7();}    
    if (GD.inputs.tag==14)
       {delay(145); xDbase = 160; velPD=-10; movx = movxbase; 
         procesandoentorno();
         RespaldoNombreJPG = NombreJPG;
         //ReadJPGname();
         CargaJPG(NombreJPG);  //w01.jpg, FT801_Riverdi, solo carga una imagen para no afectar despliegue de imagenes adicionales
         Reloj();
        }     

 GD.swap();
 }
}
