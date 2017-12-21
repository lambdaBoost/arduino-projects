void setup(){
  DDRA =255;
  DDRB=255;
}


void
line(
        uint8_t y0,
        uint8_t x0,
        uint8_t y1,
        uint8_t x1
       
)
{
        int dx, dy, sx, sy;

        if (x0 < x1)
        {
                dx = x1 - x0;
                sx = 1;
        } else {
                dx = x0 - x1;
                sx = -1;
        }

        if (y0 < y1)
        {
                dy = y1 - y0;
                sy = 1;
        } else {
                dy = y0 - y1;
                sy = -1;
        }

        int err = dx - dy;

        while (1)
        {
                PORTB = x0;
                PORTA = y0;

                if (x0 == x1 && y0 == y1)
                        break;

                int e2 = 2 * err;
                if (e2 > -dy)
                {
                        err = err - dy;
                        x0 += sx;
                }
                if (e2 < dx)
                {
                        err = err + dx;
                        y0 += sy;
                }
                delayMicroseconds(40);
        }
}


unsigned char sinTab[]=
{ 
 127,130,133,136,139,143,146,149,152,155,158,161,164,167,170,173,176,178,181,184,187,190,192,195,198,200,203,205,208,210,212,215,217,219,221,223,225,227,229,231,233,234,236,238,239,240,
  242,243,244,245,247,248,249,249,250,251,252,252,253,253,253,254,254,254,254,254,254,254,253,253,253,252,252,251,250,249,249,248,247,245,244,243,242,240,239,238,236,234,233,231,229,227,225,223,
  221,219,217,215,212,210,208,205,203,200,198,195,192,190,187,184,181,178,176,173,170,167,164,161,158,155,152,149,146,143,139,136,133,130,127,124,121,118,115,111,108,105,102,99,96,93,90,87,84,81,78,
  76,73,70,67,64,62,59,56,54,51,49,46,44,42,39,37,35,33,31,29,27,25,23,21,20,18,16,15,14,12,11,10,9,7,6,5,5,4,3,2,2,1,1,1,0,0,0,0,0,0,0,1,1,1,2,2,3,4,5,5,6,7,9,10,11,12,14,15,16,18,20,21,23,25,27,29,31,
  33,35,37,39,42,44,46,49,51,54,56,59,62,64,67,70,73,76,78,81,84,87,90,93,96,99,102,105,108,111,115,118,121,124
 };

unsigned char j=64;


void loop(){
   //frame 3
   for(unsigned char C1=1;C1<45;C1++){//C1 is loop counter for runner - when max value reached, cycle complete
 if(5>C1){
 line(20,25,30,20);//right foot
 line(30,20,20,60);//right shin
 line(20,60,60,100);//right thigh
 line(60,100,90,50);//left thigh
 line(90,50,125,60);//left shin
 line(125,60,135,60);//left foot
 line(60,100,40,150);//body
 line(40,150,90,160);//upper left arm
 line(90,160,110,140);//lower left arm
 line(40,150,20,110);//upper right arm
 line(20,110,0,150);//lower right arm
 
  for(int i=0;i<256;i++){
    PORTA=0.1*sinTab[i]+25;//horizontal sin wave
  PORTB=0.1*sinTab[j++]+150;//vertical sin wave
  delayMicroseconds(20);//delay between points
   
  }
  
    }
    
  //frame 1

  if(10>C1>5){//number of times to draw this frame before switching to next (ie, determines frame length
  line(50,20,60,30);//right foot
 line(60,30,30,70);//right shin
 line(30,70,60,100);//right thigh
 line(60,100,80,60);//left thigh
 line(80,60,120,35);//left shin
 line(120,35,110,20);//left foot
 line(60,100,40,150);//body
 line(40,150,90,150);//upper left arm
 line(90,150,110,110);//lower left arm
 line(40,150,40,110);//upper right arm
 line(40,110,5,150);//lower right arm
 
  for(int i=0;i<256;i++){
    PORTA=0.1*sinTab[i]+25;//horizontal sin wave
  PORTB=0.1*sinTab[j++]+150;//vertical sin wave
  delayMicroseconds(20);//delay between points
  }
 
  }
   
   
  //frame 7
 if(15>C1 && C1>10){
 line(50,20,60,20);//right foot
 line(60,20,35,60);//right shin
 line(35,60,60,100);//right thigh
 line(60,100,55,70);//left thigh
 line(55,70,100,75);//left shin
 line(100,75,100,65);//left foot
 line(60,100,40,150);//body
 line(40,150,90,120);//upper left arm
 line(90,120,35,105);//lower left arm
 line(40,150,80,110);//upper right arm
 line(80,110,25,115);//lower right arm
 
  for(int i=0;i<256;i++){
    PORTA=0.1*sinTab[i]+25;//horizontal sin wave
  PORTB=0.1*sinTab[j++]+150;//vertical sin wave
  delayMicroseconds(20);//delay between points
}
}

       //frame 5
 if(20>C1 && C1>15){
 line(60,25,70,30);//right foot
 line(70,30,50,65);//right shin
 line(50,65,60,100);//right thigh
 line(60,100,30,75);//left thigh
 line(30,75,80,50);//left shin
 line(80,50,80,40);//left foot
 line(60,100,40,150);//body
 line(40,150,80,130);//upper left arm
 line(80,130,55,120);//lower left arm
 line(40,150,30,120);//upper right arm
 line(30,120,10,115);//lower right arm
 
  for(int i=0;i<256;i++){
    PORTA=0.1*sinTab[i]+25;//horizontal sin wave
  PORTB=0.1*sinTab[j++]+150;//vertical sin wave
  delayMicroseconds(20);//delay between points

}
    
}

   if(25>C1 && C1>20){
    //frame 2
   line(50,20,60,20);//right foot
 line(60,20,30,50);//right shin
 line(30,50,60,100);//right thigh
 line(60,100,60,60);//left thigh
 line(60,60,120,65);//left shin
 line(120,65,120,55);//left foot
 line(60,100,40,150);//body
 line(40,150,80,120);//upper left arm
 line(80,120,40,110);//lower left arm
 line(40,150,70,115);//upper right arm
 line(70,115,20,125);//lower right arm
 
  for(int i=0;i<256;i++){
    PORTA=0.1*sinTab[i]+25;//horizontal sin wave
  PORTB=0.1*sinTab[j++]+150;//vertical sin wave
  delayMicroseconds(20);//delay between points
   
  }
    }
    
  //frame 7
 if(30>C1 && C1>25){
 line(50,20,60,20);//right foot
 line(60,20,35,60);//right shin
 line(35,60,60,100);//right thigh
 line(60,100,55,70);//left thigh
 line(55,70,100,75);//left shin
 line(100,75,100,65);//left foot
 line(60,100,40,150);//body
 line(40,150,90,120);//upper left arm
 line(90,120,35,105);//lower left arm
 line(40,150,80,110);//upper right arm
 line(80,110,25,115);//lower right arm
 
  for(int i=0;i<256;i++){
    PORTA=0.1*sinTab[i]+25;//horizontal sin wave
  PORTB=0.1*sinTab[j++]+150;//vertical sin wave
  delayMicroseconds(20);//delay between points
}
}


   //frame 5
 if(35>C1 && C1>30){
 line(60,25,70,30);//right foot
 line(70,30,50,65);//right shin
 line(50,65,60,100);//right thigh
 line(60,100,30,75);//left thigh
 line(30,75,80,50);//left shin
 line(80,50,80,40);//left foot
 line(60,100,40,150);//body
 line(40,150,80,130);//upper left arm
 line(80,130,55,120);//lower left arm
 line(40,150,30,120);//upper right arm
 line(30,120,10,115);//lower right arm
 
  for(int i=0;i<256;i++){
    PORTA=0.1*sinTab[i]+25;//horizontal sin wave
  PORTB=0.1*sinTab[j++]+150;//vertical sin wave
  delayMicroseconds(20);//delay between points

}
    
}

  
 //frame 6
 if(40>C1 && C1>35){
 line(40,20,50,25);//right foot
 line(50,25,20,70);//right shin
 line(20,70,60,100);//right thigh
 line(60,100,70,65);//left thigh
 line(70,65,100,30);//left shin
 line(100,30,100,20);//left foot
 line(60,100,40,150);//body
 line(40,150,90,150);//upper left arm
 line(90,150,100,110);//lower left arm
 line(40,150,20,110);//upper right arm
 line(20,110,0,150);//lower right arm
 
  for(int i=0;i<256;i++){
    PORTA=0.1*sinTab[i]+25;//horizontal sin wave
  PORTB=0.1*sinTab[j++]+150;//vertical sin wave
  delayMicroseconds(20);//delay between points
}
}
  //frame 1

  if(45>C1>40){//number of times to draw this frame before switching to next (ie, determines frame length
  line(50,20,60,30);//right foot
 line(60,30,30,70);//right shin
 line(30,70,60,100);//right thigh
 line(60,100,80,60);//left thigh
 line(80,60,120,35);//left shin
 line(120,35,110,20);//left foot
 line(60,100,40,150);//body
 line(40,150,90,150);//upper left arm
 line(90,150,110,110);//lower left arm
 line(40,150,40,110);//upper right arm
 line(40,110,5,150);//lower right arm
 
  for(int i=0;i<256;i++){
    PORTA=0.1*sinTab[i]+25;//horizontal sin wave
  PORTB=0.1*sinTab[j++]+150;//vertical sin wave
  delayMicroseconds(20);//delay between points
  }
 
  }
  

  



  
   

    




 
 
   /* 
  //frame 4
 if(40>C1 && C1>30){
 line(10,25,20,20);//right foot
 line(20,20,30,60);//right shin
 line(30,60,60,100);//right thigh
 line(60,100,90,50);//left thigh
 line(90,50,135,60);//left shin
 line(135,60,140,55);//left foot
 line(60,100,40,150);//body
 line(40,150,80,155);//upper left arm
 line(80,155,110,135);//lower left arm
 line(40,150,20,110);//upper right arm
 line(20,110,0,150);//lower right arm
 
  for(int i=0;i<256;i++){
    PORTA=0.1*sinTab[i]+25;//horizontal sin wave
  PORTB=0.1*sinTab[j++]+150;//vertical sin wave
  delayMicroseconds(20);//delay between points
   
  }
  
    }








 //frame 8
 if(80>C1 && C1>70){
 line(20,25,25,20);//right foot
 line(25,20,40,75);//right shin
 line(40,75,60,100);//right thigh
 line(60,100,75,70);//left thigh
 line(75,70,120,80);//left shin
 line(120,80,120,70);//left foot
 line(60,100,40,150);//body
 line(40,150,90,160);//upper left arm
 line(90,160,110,150);//lower left arm
 line(40,150,30,120);//upper right arm
 line(30,120,15,150);//lower right arm
 
  for(int i=0;i<256;i++){
    PORTA=0.1*sinTab[i]+25;//horizontal sin wave
  PORTB=0.1*sinTab[j++]+150;//vertical sin wave
  delayMicroseconds(20);//delay between points
}
}*/
}
}





