void setup()
{
  Serial.begin(9600);
  GD.begin();
  GD.cmd_setrotate(0);

  hello();
  delay(2500);
  MCircular();
}
