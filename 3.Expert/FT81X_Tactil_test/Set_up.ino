void setup(){
  Serial.begin(9600);
  GD.begin();
  GD.cmd_setrotate(0);
   GD.play(0); //detiene sonido en altavoz
   //GD.self_calibrate();  
  //GD.wr(REG_PWM_DUTY, 75); 
  GD.cmd_loadimage(0, 0);
  GD.load("Imag1.jpg");
  MainMenu();
}
