//char TX[60];
int Hdec = 1;  

void AjusteAlarmas()
{
 byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;

while (1) {
  // retrieve data from DS3231
 // readDS3231time(&second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month,&year);    

  GD.get_inputs();
    
  GD.Clear();
 GD.SaveContext();  
  GD.ColorMask(1,1,1,0);  //reloj transparente  
      //   Design1();
  GD.ColorMask(0,0,0,1);  //reloj transparente
  GD.BlendFunc(ONE, ONE_MINUS_SRC_ALPHA);  //reloj transparente
  GD.Begin(POINTS);//reloj transparente
  GD.PointSize(16*120);//reloj transparente
  GD.Vertex2ii(136,136);//reloj transparente
  GD.BlendFunc(ZERO, ONE_MINUS_SRC_ALPHA);  //reloj transparente
  GD.PointSize(16*110);//reloj transparente
  GD.Vertex2ii(136,136);//reloj transparente

  GD.BlendFunc(ONE, ONE_MINUS_SRC_ALPHA);  //reloj transparente
   Alarma1(hour,minute,second);
   GD.cmd_clock(136,136,130,OPT_NOTICKS|OPT_NOBACK,hour,minute,second,0);//reloj transparente



    GD.ColorMask(1,1,1,0);//reloj transparente
    GD.BlendFunc(DST_ALPHA, ONE);//reloj transparente
    GD.ColorRGB(0x00f000);//reloj cara interna transparente, lineas transparentes    

    GD.Begin(RECTS);      //reloj transparente
    GD.Vertex2ii(0,0);//reloj transparente
    GD.Vertex2ii(480,272);//reloj transparente

  GD.RestoreContext();

    GD.ColorRGB(0xFFFFFF);
    sprintf(TX,  "%02d:%02d", hour, minute); // hh mm --- crea hora
    GD.cmd_text(225, 11, 30, 0, TX);   

    GD.cmd_fgcolor(0x00ff00); //color del boton    GD.ColorRGB(0x000000); //color del texto del boton
   // GD.Tag(TAG_BUTTON1); //0-254. 255 inactiva entrada tactil
    GD.Tag(6);    GD.cmd_button(392, 12, 40, 30, 26, 0,  "MP");        GD.Tag(255);

    GD.cmd_fgcolor(0xff0000);   GD.ColorRGB(0xffffff);     GD.cmd_text(370, 75, 26, OPT_CENTERX, "Alarma");

    sprintf(TX,"%02d", HAlarma1); 
    GD.Tag(7);    GD.cmd_button(300, 95, 40, 30, 29, 0,  TX);        GD.Tag(255);
    
    sprintf(TX,"%02d", MAlarma1); 
    GD.Tag(8);    GD.cmd_button(350, 95, 40, 30, 29, 0,  TX);        GD.Tag(255);    
    
    sprintf(TX,"%02d", SAlarma1); 
    GD.Tag(9);    GD.cmd_button(400, 95, 40, 30, 29, 0,  TX);        GD.Tag(255);        

    if (GD.inputs.tag==7){delay(125); HAlarma1 = HAlarma1+1;
        if (HAlarma1==24){HAlarma1=0;} 
     }
    if (GD.inputs.tag==8){delay(125); MAlarma1 = MAlarma1+1;
        if (MAlarma1==60){MAlarma1=0;}   
     }    
    if (GD.inputs.tag==9){delay(125); SAlarma1 = SAlarma1+5;
        if (SAlarma1>=60){SAlarma1=0;}     
     }

    GD.cmd_fgcolor(0xffff00);     GD.ColorRGB(0xff0000);
    GD.Tag(10);    GD.cmd_button(392, 135, 40, 30, 29, 0,  "A1");        GD.Tag(255);    

    if (GD.inputs.tag==10){delay(125); 
       clearMatrix();  Interno(0,0,100);  // pixels.show();           
      HAlarma1=21; MAlarma1=10; SAlarma1=0;  //normal  Silvia
     }

    GD.cmd_fgcolor(0x0000ff);   
    GD.Tag(11);    GD.cmd_button(342, 135, 40, 30, 26, 0,  "");        GD.Tag(255);    
    if (GD.inputs.tag==11){
       clearMatrix();
       Interno(0,0,100); // pixels.show();       
    }    


    GD.cmd_fgcolor(0xffff00);   
    GD.Tag(12);    GD.cmd_button(392, 175, 40, 30, 29, 0,  "A2");        GD.Tag(255);    

    if (GD.inputs.tag==12){delay(125); 
       clearMatrix();  Interno(0,0,100);  // pixels.show();           
      HAlarma1=9; MAlarma1=0; SAlarma1=0;  //normal  Silvia
     }


    GD.cmd_fgcolor(0xffffff);   
    GD.Tag(13);    GD.cmd_button(342, 175, 40, 30, 29, 0,  "H");        GD.Tag(255);    

    if (GD.inputs.tag==13){delay(125); 
       clearMatrix();  Interno(0,0,100);  // pixels.show();           
      HAlarma1=hour; MAlarma1=minute; SAlarma1=second;  //Hora actual
     }


    GD.cmd_fgcolor(0xffffff);   
    GD.Tag(14);    GD.cmd_button(292, 215, 40, 30, 26, 0,  "A-on");        GD.Tag(255);    

    if (GD.inputs.tag==14){delay(125); 
        digitalWrite(51, LOW);    // RELE ENCENDIDO
//        delay(250);              
//        digitalWrite(51, HIGH);   // RELE APAGADO
//        delay(7500);
     }


    GD.cmd_fgcolor(0xffffff);   
    GD.Tag(15);    GD.cmd_button(342, 215, 40, 30, 26, 0,  "A-off");        GD.Tag(255);    

    if (GD.inputs.tag==15){delay(125); 
        clearMatrix();   Interno(0,0,100);  //pixels.show();
//        digitalWrite(51, LOW);    // RELE ENCENDIDO
//        delay(250);              
        digitalWrite(51, HIGH);   // RELE APAGADO
//        delay(7500);
     }



    if (GD.inputs.tag==6){
        delay(145);
        clearMatrix();   Interno(0,0,100); // pixels.show();

        if(despPD==0){xDbase=160; despPD=0; velPD=0;}
          movx = movxbase;  
          movxR = -560;

         procesandolista();
        // ReadJPGname();
         CargaJPG_iconos1(120);                     
          
         MP();
      }

    
  GD.swap();
  }
}

void Alarma1(int Hor, int Minu, int Segu){
 if (Hor==HAlarma1){
   if (Minu==MAlarma1){
     if (Segu==SAlarma1){
         digitalWrite(51, LOW);    // RELE AUDIO ENCENDIDO
         Interno1(200,0,0);  //pixels.show();
         GD.play(CAROUSEL, 70);  //SONIDO CONTINUO  
          delay(500);
         GD.play(0); //DETIENE SONIDO               
        digitalWrite(51, HIGH);   // RELE AUDIO APAGADO         
      }
    }
  }
}

void Hora()
{
   GD.cmd_number(380, 13, 28, 2|OPT_CENTER, hour);     GD.cmd_text(395, 12, 26, OPT_CENTER, ":");
   GD.cmd_number(410, 13, 28, 2|OPT_CENTER, minute);   GD.cmd_text(425, 12, 27, OPT_CENTER, ":");
   GD.cmd_number(440, 13, 28, 2|OPT_CENTER, second);   
}  
