void BarrasV2(int PX, int PY, int Maxbar, int largobarra2, int NRbar, int IDBar, float VDP, float VDN, int CR, int CG, int CB)
{
  GD.Begin(LINES);
  GD.LineWidth(50);

for(int ki = 0; ki < Maxbar+1; ki++) 
       { 
          GD.ColorRGB(0x101010);
          GD.Vertex2f((PX+(sepX*ki))*16,(PY)*16);
          GD.Vertex2f((PX+(sepX*ki))*16,(PY+largobarra2)*16);
       }


//39
   if(datoB[IDBar]<=Maxbar-NRbar){
    for(int ii = 0; ii < datoB[IDBar]; ii++) 
       { 
          GD.ColorRGB(0xffffff);
          GD.Vertex2f((PX+(sepX*ii))*16,(PY)*16);
          GD.Vertex2f((PX+(sepX*ii))*16,(PY+largobarra2)*16);
       }}

   if(datoB[IDBar]>=Maxbar-NRbar){
    for(int ii = 0; ii < Maxbar-NRbar; ii++) 
       { 
          GD.ColorRGB(0xffffff);
          GD.Vertex2f((PX+(sepX*ii))*16,(PY)*16);
          GD.Vertex2f((PX+(sepX*ii))*16,(PY+largobarra2)*16);
       }
       
    for(int k = Maxbar-NRbar; k < datoB[IDBar]; k++) 
       { 
          //GD.ColorRGB(0xff0000);
          GD.ColorRGB(CR,CG,CB);
          GD.Vertex2f((PX+(sepX*k))*16,(PY)*16);
          GD.Vertex2f((PX+(sepX*k))*16,(PY+largobarra2)*16);
          GD.ColorRGB(0xffffff);
       }       
       
       }

       datoB[IDBar]= datoB[IDBar]+velXB[IDBar]; 
       if (datoB[IDBar]>=Maxbar+1){velXB[IDBar]=VDN;}
       if (datoB[IDBar]<=0){datoB[IDBar]=0; velXB[IDBar]=VDP;}
}
