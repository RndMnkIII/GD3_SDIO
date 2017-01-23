void setup() {
  
  Wire.begin();
  // set the initial time here:
  // DS3231 seconds, minutes, hours, day, date, month, year
   //setDS3231time(30,52,17,3,10,11,15);   //  day 3 =  Martes     //comentar cuando el tiempo den DS3231 esté asignado
  
  pinMode(res, OUTPUT); 
  pinMode(strobe, OUTPUT); 
  digitalWrite(res,LOW); 
  digitalWrite(strobe,HIGH);   
  
  Serial.begin(9600);
  GD.begin();
   GD.cmd_setrotate(0);
  GD.play(0); //detiene sonido en altavoz
  //GD.self_calibrate();  //FT801 Riverdi
  //GD.wr(REG_PWM_DUTY, 95);  //0-128  backlight Gameduino 2
  
 //Neopixel
//  matrix.begin();
//  pixels.begin();
//Neopixel
  clearMatrix();

  // initialize digital pin 51 as an output for rele
//  pinMode(51, OUTPUT);
//  digitalWrite(51, HIGH);   // RELE-OFF, led-on

//  procesandoentorno();
//  GD.cmd_loadimage(0, 0);  
//  GD.load("w01.jpg");  //FT801_Riverdi

    procesandolista();
    
  LOAD_ASSETS0();  
  GD.BitmapHandle(15);
  GD.cmd_loadimage(ASSETS_END, 0);
  GD.load("PC1.jpg");  //si lo carga XD  335x272    
    
    ReadJPGname();
//    CargaJPG_iconos1(120);   
//    CargaJPG(NombreJPG);  //w01.jpg, FT801_Riverdi
  
 MP();
}

void clearMatrix()
{
  for (int i=0; i<=64; i++)
  {
   // pixels.setPixelColor(i, pixels.Color(0,0,0));
   // pixels.show();      
  }
}
