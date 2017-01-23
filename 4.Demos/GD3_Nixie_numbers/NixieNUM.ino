void NixieNUM(int Numero, int NX, int NY)
{
  int NumeroD = Numero/10;            //decenas
  int NumeroU = Numero - NumeroD*10;  //unidades
  
  GD.Vertex2ii(NX + 50, NY, NumeroU);
  GD.Vertex2ii(NX, NY, NumeroD);
}
