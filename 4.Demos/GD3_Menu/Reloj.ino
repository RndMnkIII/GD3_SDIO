int ajusteR=200; 

void Reloj()
{
 byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;  
 while(1) {
 // readDS3231time(&second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month,&year);       
    GD.Clear();
    GD.Begin(BITMAPS);

 GD.SaveContext();  
   GD.get_inputs();

   Poly po;    

   if (movxR==0){movxR = 0;}else{movxR = movxR + velocidadx;}
   GD.SaveContext();  
   GD.ColorMask(1,1,1,0);  //reloj transparente  
   GD.Vertex2ii(0, 0);        
      
   GD.ColorMask(0,0,0,1);  //reloj transparente
   GD.BlendFunc(ONE, ONE_MINUS_SRC_ALPHA);  //reloj transparente
   GD.Begin(POINTS);//reloj transparente
   GD.PointSize(16*120);//reloj transparente
   GD.Vertex2ii(Xreloj+movxR,Yreloj);//reloj transparente
  
   GD.BlendFunc(ZERO, ONE_MINUS_SRC_ALPHA);  //reloj transparente
   GD.PointSize(16*110);//reloj transparente
   GD.Vertex2ii(Xreloj+movxR,Yreloj);//reloj transparente

   GD.BlendFunc(ONE, ONE_MINUS_SRC_ALPHA);  //reloj transparente

    GD.cmd_clock(Xreloj+movxR,Yreloj,130,OPT_NOTICKS|OPT_NOBACK,hour,minute,second,0);//reloj transparente
  //GD.cmd_clock(Xreloj+movxR,Yreloj,130,OPT_NOTICKS|OPT_NOBACK,4,15,30,0);//reloj transparente con hora fija

    Alarma1(hour,minute,second);

    GD.ColorMask(1,1,1,0);//reloj transparente
    GD.BlendFunc(DST_ALPHA, ONE);//reloj transparente
    GD.ColorRGB(0x00f000);//reloj cara interna transparente, lineas transparentes    

  po.begin();  po.v(16*(Xreloj-ajusteR+140+movxR),16*0);  po.v(16*(Xreloj-ajusteR+300+movxR),16*0);  po.v(16*(Xreloj-ajusteR+360+movxR),16*60);  po.v(16*(Xreloj-ajusteR+360+movxR),16*212);
               po.v(16*(Xreloj-ajusteR+300+movxR),16*272);  po.v(16*(Xreloj-ajusteR+140+movxR),16*272);  po.v(16*(Xreloj-ajusteR+80+movxR),16*212);  po.v(16*(Xreloj-ajusteR+80+movxR),16*60);
  po.draw();    
  GD.RestoreContext();

    GD.ColorRGB(0xFFFFFF);
    sprintf(TX,  "%02d:%02d", hour, minute); // hh mm --- crea hora
    GD.cmd_text(TxPD+30+movxR, 190, 30, 0, TX);   
    //GD.cmd_number(TxPD+80+movxR, 206, 30, OPT_RIGHTX | OPT_SIGNED, hour);

    GD.ColorRGB(0x8B0000);
    sprintf(TX,  "%02d:%02d", HAlarma1, MAlarma1); // hh mm --- alarma
    GD.cmd_text(TxPD+50+movxR, 14, 26, 0, TX);
 
  GD.SaveContext(); 
   GD.ColorA(150);  
   GD.ColorRGB(0x008B4B);
   if (movx==0){movx = 0;}else{movx = movx + velocidadx;}
   GD.Tag(1);   po.begin();  po.v(16*(0+movx),16*0);                    po.v(16*(140+movx),16*0);                   po.v(16*(80+movx),16*60);                po.v(16*(0+movx),16*60);  po.draw(); GD.Tag(255);
   GD.Tag(2);   po.begin();  po.v(16*(0+movx),16*60+separacionpanel);   po.v(16*(80+movx),16*60+separacionpanel);   po.v(16*(80+movx),16*110);                      po.v(16*(0+movx),16*110);    po.draw();  GD.Tag(255);
   GD.Tag(3);   po.begin();  po.v(16*(0+movx),16*110+separacionpanel);  po.v(16*(80+movx),16*110+separacionpanel);  po.v(16*(80+movx),16*160);                      po.v(16*(0+movx),16*160);    po.draw();  GD.Tag(255);
   GD.Tag(4);   po.begin();  po.v(16*(0+movx),16*160+separacionpanel);  po.v(16*(80+movx),16*160+separacionpanel);  po.v(16*(80+movx),16*212-(4*separacionpanel));  po.v(16*(0+movx),16*212-(4*separacionpanel)); po.draw(); GD.Tag(255);
   GD.Tag(5);   po.begin();  po.v(16*(0+movx),16*272);                  po.v(16*(140+movx),16*272);                 po.v(16*(80+movx),16*212);               po.v(16*(0+movx),16*212);    po.draw();  GD.Tag(255);
  GD.RestoreContext();  
 
    if (GD.inputs.tag==1){
        delay(145);
         if(despPD==0){xDbase=160; despPD=0; velPD=0;}
          movx = movxbase;  
          movxR = -560;

         procesandolista();
        // ReadJPGname();
         CargaJPG_iconos1(120);                     
          
         MP();
      }
      
    if (GD.inputs.tag==2){
        delay(145);

         procesandolista();
        // ReadJPGname();
         CargaJPG_iconos1(120);                     
          
        AjusteAlarmas();
      }      
 GD.swap();
 }
} 




