void Choise(){
    if (GD.inputs.tag==1){
         delay(140); group1 = group1 + 1;  group2 = 0;  group3 = 0;  group4 = 0;  group5 = 0;  group6 = 0;  group7 = 0;  group8 = 0;
         if (group1 == 2){group1 = 0;}
     }      

    if (GD.inputs.tag==2){
         delay(140);  group2 = group2 + 1;  group1 = 0;  group3 = 0;  group4 = 0;  group5 = 0;  group6 = 0;  group7 = 0;  group8 = 0;
         if (group2 == 2){group2 = 0;}
     } 

    if (GD.inputs.tag==3){
         delay(140);  group3 = group3 + 1;  group1 = 0;  group2 = 0;  group4 = 0;  group5 = 0;  group6 = 0;  group7 = 0;  group8 = 0;
         if (group3 == 2){group3 = 0;}
     }      

    if (GD.inputs.tag==4){
         delay(140);  group4 = group4 + 1;  group1 = 0;  group2 = 0;  group3 = 0;  group5 = 0;  group6 = 0;  group7 = 0;  group8 = 0;
         if (group4 == 2){group4 = 0;}
     } 

    if (GD.inputs.tag==5){
         delay(140); group5 = group5 + 1;  group1 = 0;  group2 = 0;  group3 = 0;  group4 = 0;  group6 = 0;  group7 = 0;  group8 = 0;
         if (group5 == 2){group5 = 0;}
     }      

    if (GD.inputs.tag==6){
         delay(140);  group6 = group6 + 1;  group1 = 0;  group2 = 0;  group3 = 0;  group4 = 0;  group5 = 0;  group7 = 0;  group8 = 0;
         if (group6 == 2){group6 = 0;}
     } 

    if (GD.inputs.tag==7){
         delay(140);  group7 = group7 + 1;  group1 = 0;  group2 = 0;  group3 = 0;  group4 = 0;  group5 = 0;  group6 = 0;  group8 = 0;
         if (group7 == 2){group7 = 0;}
     }      

    if (GD.inputs.tag==8){
         delay(140);  group8 = group8 + 1;  group1 = 0;  group2 = 0;  group3 = 0;  group4 = 0;  group5 = 0;  group6 = 0;  group7 = 0;
         if (group8 == 2){group8 = 0;}
     }

    if (GD.inputs.tag==89){
         delay(140);  
          GD.cmd_loadimage(0, 0);
          GD.load("V1.png");
     }
          
}

