void Grafico1V(int G1X, int G1Y)
{
//Pasan 5 segundos y toma una nueva lectura, entonces se procesa la gráfica
  unsigned long currentMillis1 = millis();        
  if(currentMillis1 - previousMillis1 > interval1)
  {
    previousMillis1 = currentMillis1;       

    LecturaSensor1();
    T1b = T1;
    DT1 = T1b - T1a;
    if (DT1>0){DT1g=1;}else{if (DT1<0){DT1g=-1;}else{DT1g=0;}}  //determina el intervalo de suavizado
  } //usa millis en lugar de delay XD XD XD 
//Pasan 5 segundos y toma una nueva lectura, entonces se procesa la gráfica
//  Procesamiento1();
//  Procesamiento1V();
//           textoXV, textoYV, tamañoletra
  Procesamiento1V(225, 223, 18, G1X, G1Y);
}
