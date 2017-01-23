void M7() 
{
 while(1) {
   GD.ClearColorRGB(0x250025);  //fondo uniforme           
   GD.Clear();   //GD.cmd_gradient(0, 0, 0x000000, 0, 271, 0xc060000);   
   GD.get_inputs();
 
  GD.SaveContext(); 
//   Panel();
  GD.ColorA(115);  
  Poly po;
   GD.ColorRGB(0x008A4B);
  //Panel izquierdo
  if (movx==0){movx = 0;}else{movx = movx + velocidadx;}  
   GD.Tag(204);  po.begin();  po.v(16*(0+movx),16*0);                     po.v(16*(140+movx),16*0);                   po.v(16*(80+movx),16*60);                po.v(16*(0+movx),16*60);  po.draw();  GD.Tag(255);  
   GD.Tag(201);  po.begin();  po.v(16*(0+movx),16*60+separacionpanel);   po.v(16*(80+movx),16*60+separacionpanel);   po.v(16*(80+movx),16*110);                      po.v(16*(0+movx),16*110);    po.draw();  GD.Tag(255);  
   GD.Tag(202);  po.begin();  po.v(16*(0+movx),16*110+separacionpanel);  po.v(16*(80+movx),16*110+separacionpanel);  po.v(16*(80+movx),16*160);                      po.v(16*(0+movx),16*160);    po.draw();  GD.Tag(255);  
   GD.Tag(203);  po.begin();  po.v(16*(0+movx),16*160+separacionpanel);  po.v(16*(80+movx),16*160+separacionpanel);  po.v(16*(80+movx),16*212-(4*separacionpanel));  po.v(16*(0+movx),16*212-(4*separacionpanel)); po.draw();  GD.Tag(255);  
   po.begin();  po.v(16*(0+movx),16*272);                  po.v(16*(140+movx),16*272);                 po.v(16*(80+movx),16*212);               po.v(16*(0+movx),16*212);    po.draw();
  //Panel izquierdo   

   GD.ColorA(255);   
   
   
  GD.RestoreContext();  
 
    if (GD.inputs.tag==204){
        delay(145);
         if(despPD==0){xDbase=160; despPD=0; velPD=0;}
         movx = movxbase;        
         MP();
      }
 GD.swap();
 }
}
