void readMSGEQ7()
{
 digitalWrite(res, HIGH);
 digitalWrite(res, LOW);
 for(band=0; band <7; band++)
 {
  digitalWrite(strobe,LOW); 
  delayMicroseconds(30);  
  left[band] = analogRead(8); 
  digitalWrite(strobe,HIGH); 
 }
}


void Analizador()
{
    while(1) {
    GD.Clear();
    GD.Begin(BITMAPS);
    GD.Vertex2ii(0, 0);
  
// Diseño de marco para gráfica
  GD.ColorA(255); //color solido      
  GD.ColorRGB(0x202020);
     GD.LineWidth(1 * 16);
     GD.Begin(RECTS);

    GD.get_inputs();

    GD.ColorA(75); //transparencia     
    GD.ColorRGB(255,255,255);   //Color del texto
    GD.cmd_text(xi, yi+7, 16, 0, " 63          400   1000  2500  6250  16000 Hz");  // GD.cmd_text(402, 10, 16, OPT_CENTER, "Quad-MSGEQ7");     
    GD.cmd_text(xi+54, yi+7, 16, 0, "160");        
   
    GD.ColorA(40); //transparencia
    GD.ColorRGB(0x00ff00);  // GD.cmd_text(402, 10, 16, OPT_CENTER, "Quad-MSGEQ7");
    GD.LineWidth(1 * 16);
    GD.Begin(LINES);
       marcadoresverticales();
       marcadoreshorizontales();
    GD.ColorA(255); //color solido      
// Diseño de marco para gráfica
  
     readMSGEQ7();    
     Baseactual2();     //  Gráfica lineal   
     GD.ColorA(255); //color solido           
     barrasVSegmentadas();  
 
    GD.Tag(225); 
    GD.cmd_button(5, 5, 50, 35, 26, 0,  "M1");        GD.Tag(255);
    if (GD.inputs.tag==225){movx = movxbase; M1();}
      
    GD.swap();
 }  
}


void barrasVSegmentadas()
{
  GD.Begin(LINES);
  GD.LineWidth(35);
  GD.ColorRGB(0xffffff);   //color de los segmentos

    for (int j = 0; j < band; j++) 
      { 
      int dato = map(left[j], 0, 1023, 0, segmentos);
      for (int i = 0; i < dato; i++) 
        { 
         GD.Vertex2ii(xi+(j*largoX+j*sepX), yi - (i*sepY)); // inicio
         GD.Vertex2ii(xi+((j+1)*largoX+j*sepX), yi - (i*sepY)); //  fin   
        }
      }  
}


void fondografica()
{
    GD.Vertex2f((XGT) * 16, (YGT-35) * 16);	//Esquina superior izquierda
    GD.Vertex2f((XGT+374) * 16, (YGT) * 16);	//esquina inferior derecha
  
    GD.Vertex2f(XGT * 16, (YGT) * 16);	                //Esquina superior izquierda
    GD.Vertex2f((XGT+140) * 16, (YGT+RectHeight) * 16);	//esquina inferior derecha
}  

void marcadoresverticales()
{
    for (int k=0; k<15; k++)
     {    
	GD.Vertex2f((XGT+(k*10)) * 16, YGT* 16);	//starting coordinates
	GD.Vertex2f((XGT+(k*10)) * 16, (YGT+RectHeight) * 16);  //ending coordinates
     }  
}

void marcadoreshorizontales()
{
    for (int k=0; k<8; k++)
     {    
	GD.Vertex2f((XGT) * 16, (YGT+(k*10))* 16);	//starting coordinates
	GD.Vertex2f((XGT+140) * 16, (YGT+(k*10)) * 16);  //ending coordinates
     }     
}
// Diseño de marco para gráfica


void Arraydatos2()
{

  for (j=0; j<4; j++)  //Puedes usar cualquier intervalo entre 0 y maxlecturas   XD XD, solo muestra del 0-4 
     {  
      GD.ColorRGB(0,255,0);
      sprintf(TX,"%02d", j);  GD.cmd_text(xTextoT, (yTextoT+15*j), 16, 0, TX);   sprintf(TX,"%02d", lectura[j]); GD.cmd_text(xTextoT+25, (yTextoT+15*j), 16, 0, TX);   
     }

}


void insertadatos1()  //En Baseactual()  ---->    convertida en función XD
{
// Esta función debe recorrer los datos hacia atrás y luego insertará el dato actual al final de la lista
//  La base nueva corresponde a la base previa -1 dato
  unsigned long currentMillis = millis();        
  if(currentMillis - previousMillis > interval)
  {
    // save the last time 
    previousMillis = currentMillis;       
  
    for (j=0; j<maxlecturas-1; j++)
      {
        lectura[j]=lectura[j+1];   // genera la base de datos previa, recorriendo un dato hacia atrás
      }      
    LecturaMSGEQ7();  //Toma la lectura actual del sensor
    lectura[maxlecturas-1] = Valor;       //base de maxlecturas puntos
  } //usa millis en lugar de delay XD XD XD para actualizar la gráficaT
}



void Baseactual2()  // lineas
{
//lee la base de datos actual  

//Gráfica lineal      
     GD.ColorRGB(0xFF,0xff,0x00);
     GD.Begin(LINE_STRIP);
    for (j=0; j<maxlecturas; j++)
     {    
        GD.Vertex2f(((j*separacion)+xinicial+2) * 16, (272+(ybaseT)-(lectura[j])) * 16);
     }

    lectura[maxlecturas-1] = Valor;  
    sprintf(TX,"%02d", lectura[maxlecturas-1]); GD.cmd_text(41, 110, 16, 0, TX);  //Presenta lectura actual
    sprintf(TX,"%04d", Lectura); GD.cmd_text(25, 136, 16, 0, TX);      GD.cmd_text(402, 10, 16, OPT_CENTER, "Quad-MSGEQ7");       
     j=0;  //al salir deja j=0 para empezar la matriz en (0,0)
     insertadatos1();  //Inserta la lectura actual en la base previa XD --->Mediante función XD
}

void LecturaMSGEQ7()
{
 // readMSGEQ7();
  Lectura=left[2];  //solo el canal seleccionado
//  Lectura=(left[0]+left[1]+left[2]+left[3]+left[4]+left[5]+left[6])/7;  //promedio
  Valor=Lectura/15;  //ajuste para que el gráfico quede dentro de la ventana
}


void lineabaseMSGEQ7()
{
  for (int k=0; k<maxlecturas; k++)
      {
       LecturaMSGEQ7();
        lectura[k] = Valor;  
      }        
  k = maxlecturas;    // al salir de la linea base XD siempre será i = maxlecturas  
}
