void CargaJPG(int ImagenID)
{
    GD.cmd_loadimage(0, 0);
    GD.load(getdir(directory, ImagenID)); 
}  

void CargaJPG_iconos(int ImagenID)
{
  LOAD_ASSETS0();
  GD.BitmapHandle(15);
  GD.cmd_loadimage(ASSETS_END, 0);
  GD.load(getdir(directory, ImagenID));   
}  

void CargaJPG_iconos1(int ImagenID)
{
  LOAD_ASSETS0();  
  GD.BitmapHandle(15);
  GD.cmd_loadimage(ASSETS_END, 0);
  //GD.load("zx20.jpg");  //si lo carga XD  480x156  
  GD.load("PC1.jpg");  //si lo carga XD  335x272
}  


