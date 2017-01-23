//#include <EEPROM.h>
#include <SPI.h>
#include <GD3.h>

#include "spect.h"

char TX[50];  //datos a texto
int Lectura;        // activar variable para las lecturas directas de la banda del MSGEQ7 seleccionada
int Valor;          // ajuste de lectura para que quede dentro del marco de la gráfica
 
 //Lista de capturas de datos
//  const int maxlecturas = 13;   // La base solo tiene 13 puntos que van de 0 al 12   y funcionan de acuerdo a lo que habías imaginado XD XD XD
//  const int maxlecturas = 20;   // La base solo tiene 21 puntos que van de 0 al 19   y funcionan de acuerdo a lo que habías imaginado XD XD XD  
//  const int maxlecturas = 30;   // La base solo tiene 31 puntos que van de 0 al 29   y funcionan de acuerdo a lo que habías imaginado XD XD XD  

  const int maxlecturas = 35;  //ya puedes seleccionar los que quieras XD  
//  const int maxlecturas = 75;  //ya puedes seleccionar los que quieras XD  

  int lectura[maxlecturas];  // base de datos actual
  int k,j;


//Posición base de la gráfica  
  int xinicial=160;
  int ybaseT=-2;
//Posición base de la gráfica  

  int DiamPT = 1;
//int separacion=10+(DiamPT*1.5);   //10 para las pruebas
//  int separacion=5+(DiamPT*1.5);    // funciona con 30 datos para que ajuste al marco de la gráfica
  int separacion=3+(DiamPT*1.5);    //  
  
//Posición del listado de la base de datos
  int xTextoT = 375;
  int yTextoT = 10;  
//Posición del listado de la base de datos

//Millis en lugar de delay para gráfica lineal
long previousMillis = 0;        // will store last time was updated
long interval = 0;           // 
//long interval = 5000;           // 
//long interval = 1000;           // 
//long interval = 50;           // intervalo de lectura y actualización de gráfica, para que se aprecie bien en tiempo real a max velocidad
//long interval = 10000;           // intervalo de lectura y actualización de gráfica, al tiempo mas conveniente XD


// MSGEQ7 spectrum analyser 
int strobe = 25; 
int res = 26; 

int left[7], R[7]; 
int band;

int sepY = 10, sepX = 20, largoX = 30;
int xi = 75, yi = 185; 
int segmentos = 14;

void readMSGEQ7()
{
 digitalWrite(res, HIGH);
 digitalWrite(res, LOW);
 for(band=0; band <7; band++)
 {
  digitalWrite(strobe,LOW); 
  delayMicroseconds(25);  
  left[band] = analogRead(8); 
  R[band] = analogRead(9);   
  digitalWrite(strobe,HIGH); 
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

// MSGEQ7 spectrum analyser 

void LecturaMSGEQ7()
{
 // readMSGEQ7();
  Lectura=left[1];  //canal selecciionado
 // Lectura=(left[0]+left[1]+left[2]+left[3]+left[4]+left[5]+left[6])/7;  //canal seleccionado
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


void setup()
{
  pinMode(res, OUTPUT); 
  pinMode(strobe, OUTPUT); 
  digitalWrite(res,LOW); 
  digitalWrite(strobe,HIGH); 
  lineabaseMSGEQ7();  //Solo genera la linea base  
  
  Serial.begin(9600);
  GD.begin();
  GD.cmd_setrotate(0);
  

// Assets e imagen de fondo
 LOAD_ASSETSsp1();   //im1.h, miniaturas de 480px a 100px
  GD.BitmapHandle(15);
  GD.cmd_loadimage(ASSETS_END, 0);
  GD.load("HMI2.jpg");  //si lo carga XD  800x480
// Assets e imagen de fondo 


  menuPrincipal();
}

void loop(){}

int DeltaXR=250;

int XbaseD= 15, Xdelta=30;

void fondopantalla()
{
 //GD.Vertex2ii(0, 0, 15);  //fondo de pantalla

  GD.Vertex2ii(XbaseD+Xdelta*0, 300, map(left[0],0,1024,0,15)); 
  GD.Vertex2ii(XbaseD+Xdelta*1, 300, map(left[1],0,1024,0,15)); 
  GD.Vertex2ii(XbaseD+Xdelta*2, 300, map(left[2],0,1024,0,15));   
  GD.Vertex2ii(XbaseD+Xdelta*3, 300, map(left[3],0,1024,0,15)); 
  GD.Vertex2ii(XbaseD+Xdelta*4, 300, map(left[4],0,1024,0,15));
  GD.Vertex2ii(XbaseD+Xdelta*5, 300, map(left[5],0,1024,0,15));
  GD.Vertex2ii(XbaseD+Xdelta*6, 300, map(left[6],0,1024,0,15));   

GD.SaveContext();
   GD.VertexTranslateX(16*260);
   GD.Vertex2ii(500-180, 300, map(R[0],0,1024,0,15)); 
   GD.Vertex2ii(500-150, 300, map(R[1],0,1024,0,15));   
   GD.Vertex2ii(500-120, 300, map(R[2],0,1024,0,15));      
   GD.Vertex2ii(500-90, 300, map(R[3],0,1024,0,15));    
   GD.Vertex2ii(500-60, 300, map(R[4],0,1024,0,15));
   GD.Vertex2ii(500-30, 300, map(R[5],0,1024,0,15));   
   GD.Vertex2ii(500, 300, map(R[6],0,1024,0,15));   
GD.RestoreContext();   

   GD.VertexTranslateX(16*140); //centra elementos restantes
  
// Diseño de marco/fondo para gráfica
  GD.ColorA(75); //transperencia

     GD.ColorRGB(255,0,0);   //Color del texto     
     GD.cmd_text(240, 12, 28, OPT_CENTER, "Spectrum shield");     
     
     GD.ColorRGB(255,255,255);   //Color del texto
     GD.cmd_text(xi, yi+8, 16, 0, " 63          400   1000  2500  6250  16000 Hz");      
     GD.cmd_text(xi+55, yi+8, 16, 0, "160");     

  
  GD.ColorA(40); //transperencia  
  GD.ColorRGB(0x00ff00);
     GD.LineWidth(1 * 16);
     GD.Begin(LINES);
       marcadoresverticales();
       marcadoreshorizontales();
  GD.ColorA(255); //color solido      
// Diseño de marco para gráfica
}  

int option = 0;

void seleccion()
{
  if (option==0){GD.cmd_button(5, 5, 50, 35, 26, 0,  "MP");}        //boton 3D
  if (option==1){GD.cmd_button(5, 5, 50, 35, 26, OPT_FLAT,  "PM");} //boton plano
}  


void menuPrincipal()
{
  GD.cmd_fgcolor(0x954500); //color del boton
 
  do{
    GD.Clear();
    GD.Begin(BITMAPS); 
     readMSGEQ7();  
     fondopantalla();
     Baseactual2();     //  Gráfica lineal     
     barrasVSegmentadas();  

    GD.get_inputs();      
  
    GD.swap();
  }
  while(1);
}


// Diseño de marco para gráfica
int RectWidth = 178, RectHeight = 70;
int XGT=157, YGT=200;

void fondografica()
{
    GD.Vertex2f(XGT * 16, (YGT) * 16);	                        //Esquina superior izquierda
    GD.Vertex2f((XGT+RectWidth) * 16, (YGT+RectHeight) * 16);	//esquina inferior derecha
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
  for (j=0; j<13; j++)  //Puedes usar cualquier intervalo entre 0 y maxlecturas   XD XD, solo muestra del 0-12 
     {  
      GD.ColorRGB(0,255,0);
      sprintf(TX,"%02d", j);          GD.cmd_text(xTextoT, (yTextoT+15*j), 16, 0, TX);
      sprintf(TX,"%02d", lectura[j]); GD.cmd_text(xTextoT+40, (yTextoT+15*j), 16, 0, TX);   
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
     GD.ColorRGB(0xFF,0xFF,0xFF);//set the color of the point to white
     GD.Begin(LINE_STRIP);
    for (j=0; j<maxlecturas; j++)
     {    
        GD.Vertex2f(((j*separacion)+xinicial) * 16, (272+(ybaseT)-(lectura[j])) * 16);
     }

    lectura[maxlecturas-1] = Valor;  GD.ColorRGB(255,255,0); sprintf(TX,"%02d", lectura[maxlecturas-1]); GD.cmd_text(318, 240, 26, 0, TX);  //Presenta lectura actual
    GD.ColorRGB(0,255,0); sprintf(TX,"%04d", Lectura); GD.cmd_text(305, 225, 16, 0, TX);      
    j=0;  //al salir deja j=0 para empezar la matriz en (0,0)
    
     insertadatos1();  //Inserta la lectura actual en la base previa XD --->Mediante función XD
}
