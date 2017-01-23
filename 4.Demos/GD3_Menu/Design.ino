void Panel()
{
  GD.ColorA(150);  
  Poly po;
  //GD.ColorRGB(0x639BA0);
   GD.ColorRGB(0x008A4B);
  //Panel izquierdo
  if (movx==0){movx = 0;}else{movx = movx + velocidadx;}  
   po.begin();  po.v(16*(0+movx),16*0);                     po.v(16*(140+movx),16*0);                   po.v(16*(80+movx),16*60);                po.v(16*(0+movx),16*60);  po.draw();
   po.begin();  po.v(16*(0+movx),16*60+separacionpanel);   po.v(16*(80+movx),16*60+separacionpanel);   po.v(16*(80+movx),16*110);                      po.v(16*(0+movx),16*110);    po.draw();
   po.begin();  po.v(16*(0+movx),16*110+separacionpanel);  po.v(16*(80+movx),16*110+separacionpanel);  po.v(16*(80+movx),16*160);                      po.v(16*(0+movx),16*160);    po.draw();
   po.begin();  po.v(16*(0+movx),16*160+separacionpanel);  po.v(16*(80+movx),16*160+separacionpanel);  po.v(16*(80+movx),16*212-(4*separacionpanel));  po.v(16*(0+movx),16*212-(4*separacionpanel)); po.draw();
   po.begin();  po.v(16*(0+movx),16*272);                  po.v(16*(140+movx),16*272);                 po.v(16*(80+movx),16*212);               po.v(16*(0+movx),16*212);    po.draw();
  //Panel izquierdo   
  
   GD.ColorA(255);    
}

int x0insig=250, y0insig=25;
int x1insig=x0insig+70, y1insig=y0insig;
int x2insig=x1insig, y2insig=y0insig+25;
int x3insig=x0insig+25, y3insig=y2insig;  


void Insignia()
{
  GD.ColorA(150);  
  Poly po;
  GD.ColorRGB(0x00ffff);
   po.begin();  po.v(16*(x0insig),16*(y0insig));  po.v(16*(x1insig),16*(y1insig));  po.v(16*(x2insig),16*(y2insig)); po.v(16*(x3insig),16*(y3insig));  po.draw();
}

void PanelDerecho()
{
  Poly po;
  GD.ColorRGB(0x00ffff);
   xDbase = xDbase + velPD;
   if (xDbase==160){velPD=0;}
   if (xDbase==0){velPD=0;}   
    po.begin();  po.v(16*(340+xDbase),16*0);   po.v(16*(480+xDbase),16*0);   po.v(16*(480+xDbase),16*60);   po.v(16*(400+xDbase),16*60);  po.draw();
    po.begin();  po.v(16*(400+xDbase),16*60+separacionpanel);   po.v(16*(480+xDbase),16*60+separacionpanel);   po.v(16*(480+xDbase),16*110);    po.v(16*(400+xDbase),16*110);    po.draw();   
    po.begin();  po.v(16*(400+xDbase),16*110+separacionpanel);  po.v(16*(480+xDbase),16*110+separacionpanel);  po.v(16*(480+xDbase),16*160);    po.v(16*(400+xDbase),16*160);    po.draw();
    po.begin();  po.v(16*(400+xDbase),16*160+separacionpanel);  po.v(16*(480+xDbase),16*160+separacionpanel);  po.v(16*(480+xDbase),16*212-(4*separacionpanel)); po.v(16*(400+xDbase),16*212-(4*separacionpanel)); po.draw();          
    po.begin();  po.v(16*(340+xDbase),16*272);    po.v(16*(480+xDbase),16*272);   po.v(16*(480+xDbase),16*212);    po.v(16*(400+xDbase),16*212);    po.draw();
}  


