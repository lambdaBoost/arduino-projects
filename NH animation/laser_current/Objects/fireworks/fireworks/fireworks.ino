void setup() {
  DDRA=255;
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
 
 unsigned char cosTab[]=
 {128,131,134,137,140,143,146,149,152,155,158,162,165,167,170,173,176,179,182,185,188,190,193,196,198,201,203,206,208,211,213,215,
218,220,222,224,226,228,230,232,234,235,237,238,240,241,243,244,245,246,248,249,250,250,251,252,253,253,254,254,254,255,255,255,
255,255,255,255,254,254,254,253,253,252,251,250,250,249,248,246,245,244,243,241,240,238,237,235,234,232,230,228,226,224,222,220,
218,215,213,211,208,206,203,201,198,196,193,190,188,185,182,179,176,173,170,167,165,162,158,155,152,149,146,143,140,137,134,131,
128,124,121,118,115,112,109,106,103,100,97,93,90,88,85,82,79,76,73,70,67,65,62,59,57,54,52,49,47,44,42,40,
37,35,33,31,29,27,25,23,21,20,18,17,15,14,12,11,10,9,7,6,5,5,4,3,2,2,1,1,1,0,0,0,
0,0,0,0,1,1,1,2,2,3,4,5,5,6,7,9,10,11,12,14,15,17,18,20,21,23,25,27,29,31,33,35,
37,40,42,44,47,49,52,54,57,59,62,65,67,70,73,76,79,82,85,88,90,93,97,100,103,106,109,112,115,118,121,124,
128,131,134,137,140,143,146,149,152,155,158,162,165,167,170,173,176,179,182,185,188,190,193,196,198,201,203,206,208,211,213,215,
218,220,222,224,226,228,230,232,234,235,237,238,240,241,243,244,245,246,248,249,250,250,251,252,253,253,254,254,254,255,255,255,
255,255,255,255,254,254,254,253,253,252,251,250,250,249,248,246,245,244,243,241,240,238,237,235,234,232,230,228,226,224,222,220,
218,215,213,211,208,206,203,201,198,196,193,190,188,185,182,179,176,173,170,167,165,162,158,155,152,149,146,143,140,137,134,131,
128,124,121,118,115,112,109,106,103,100,97,93,90,88,85,82,79,76,73,70,67,65,62,59,57,54,52,49,47,44,42,40,
37,35,33,31,29,27,25,23,21,20,18,17,15,14,12,11,10,9,7,6,5,5,4,3,2,2,1,1,1,0,0,0,
0,0,0,0,1,1,1,2,2,3,4,5,5,6,7,9,10,11,12,14,15,17,18,20,21,23,25,27,29,31,33,35,
37,40,42,44,47,49,52,54,57,59,62,65,67,70,73,76,79,82,85,88,90,93,97,100,103,106,109,112,115,118,121,124,
 };

unsigned char full_parabola[]=
{5,9,13,17,21,24,28,32,36,39,43,46,50,54,57,61,64,67,71,74,78,81,84,87,91,94,97,100,103,106,109,112,115,118,121,124,127,129,132,135,138,
140,143,146,148,151,153,156,158,161,163,165,168,170,172,175,177,179,181,183,185,187,190,192,193,195,197,199,201,203,205,206,208,210,211,213,215,216,218,219,221,
222,224,225,226,228,229,230,231,233,234,235,236,237,238,239,240,241,242,243,244,245,245,246,247,247,248,249,249,250,251,251,252,252,252,253,253,253,254,254,254,
254,255,255,255,255,255,255,255,255,255,255,255,254,254,254,254,253,253,253,252,252,252,251,251,250,249,249,248,247,247,246,245,245,244,243,242,241,240,239,238,
237,236,235,234,233,231,230,229,228,226,225,224,222,221,219,218,216,215,213,211,210,208,206,205,203,201,199,197,195,193,192,190,187,185,183,181,179,177,175,172,
170,168,165,163,161,158,156,153,151,148,146,143,140,138,135,132,129,127,124,121,118,115,112,109,106,103,100,97,94,91,87,84,81,78,74,71,67,64,61,57,54,
50,46,43,39,36,32,28,24,21,17,13,9,5};

unsigned char parabola[] =
{
0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,2,2,2,2,2,3,3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,7,
7,7,8,8,8,9,9,10,10,10,11,11,12,12,12,13,13,14,14,15,15,16,16,17,17,18,18,19,19,20,20,21,22,22,23,23,24,25,25,26,
26,27,28,28,29,30,30,31,32,33,33,34,35,35,36,37,38,39,39,40,41,42,42,43,44,45,46,47,48,48,49,50,51,52,53,54,55,56,57,57,
58,59,60,61,62,63,64,65,66,67,68,69,70,71,73,74,75,76,77,78,79,80,81,82,84,85,86,87,88,89,91,92,93,94,95,97,98,99,100,102,
103,104,105,107,108,109,111,112,113,115,116,117,119,120,121,123,124,125,127,128,130,131,133,134,135,137,138,140,141,143,144,146,147,149,150,152,153,155,157,158,
160,161,163,165,166,168,169,171,173,174,176,178,179,181,183,184,186,188,189,191,193,195,196,198,200,202,203,205,207,209,211,212,214,216,218,220,222,223,225,227,
229,231,233,235,237,239,241,243,245,246,248,250	
};

void loop(){
  
  digitalWrite(8,HIGH);
    //FIREWORK 1
  for(int FWC=250;FWC>1;FWC--){//OUTER COUNTER TO DETERMINE MOVEMENT
   for(int FW=250;FW>FWC;FW--){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=210-0.8*parabola[FW];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=0.5*FW+100;//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
  
  }
  
  //LEG 1
  for(int EXC=250;EXC>0;EXC--){//OUTER COUNTER TO DETERMINE MOVEMENT
   for(int EX1=250;EX1>EXC;EX1){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=190+0.2*full_parabola[EX1];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=(0.2*EX1)+50;//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    EX1=EX1-4;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
  
  //LEG 2
     for(int EX2=250;EX2>EXC;EX2){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=190+0.2*full_parabola[EX2];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=-(0.2*EX2)+145;//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    EX2=EX2-4;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
   
   //LEG 3
        for(int EX3=250;EX3>EXC;EX3){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=190+0.2*full_parabola[EX3];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=(95);//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    EX3=EX3-4;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
   
  //LEG 4
     for(int EX4=150;EX4>EXC;EX4){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=160+0.2*full_parabola[EX4];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=-(0.3*EX4)+145;//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    EX4=EX4-3;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
   
   //LEG 5
     for(int EX5=150;EX5>EXC;EX5){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=160+0.2*full_parabola[EX5];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=(0.3*EX5)+40;//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    EX5=EX5-3;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }

  }

  
    //FIREWORK 2
    for(int FWC2=250;FWC2>1;FWC2--){
   for(int FW2=250;FW2>FWC2;FW2--){  //parabola takes one rotation to get to full extent as it's length is determined by k
    PORTB=180-0.75*parabola[FW2];
    PORTA=-0.5*FW2-130;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
  }
  
  //LEG 1
  for(int EXC=250;EXC>0;EXC--){//OUTER COUNTER TO DETERMINE MOVEMENT
   for(int EX1=250;EX1>EXC;EX1){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=190+0.2*full_parabola[EX1];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=(0.2*EX1)+80;//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    EX1=EX1-4;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
  
  //LEG 2
     for(int EX2=250;EX2>EXC;EX2){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=190+0.2*full_parabola[EX2];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=-(0.2*EX2)+175;//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    EX2=EX2-4;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
   
   //LEG 3
        for(int EX3=250;EX3>EXC;EX3){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=190+0.2*full_parabola[EX3];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=(125);//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    EX3=EX3-4;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
   
  //LEG 4
     for(int EX4=150;EX4>EXC;EX4){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=160+0.2*full_parabola[EX4];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=-(0.3*EX4)+170;//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    EX4=EX4-3;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
   
   //LEG 5
     for(int EX5=150;EX5>EXC;EX5){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=160+0.2*full_parabola[EX5];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=(0.3*EX5)+85;//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    EX5=EX5-3;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }

  }
  
  
    //FIREWORK 3
    for(int FWC2=250;FWC2>1;FWC2--){
   for(int FW2=250;FW2>FWC2;FW2--){  //parabola takes one rotation to get to full extent as it's length is determined by k
    PORTB=180-0.55*parabola[FW2];
    PORTA=-0.5*FW2-120;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
  }
  
  //LEG 1
  for(int EXC=250;EXC>0;EXC--){//OUTER COUNTER TO DETERMINE MOVEMENT
   for(int EX1=250;EX1>EXC;EX1){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=160+0.2*full_parabola[EX1];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=(0.2*EX1)+80;//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    EX1=EX1-4;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
  
  //LEG 2
     for(int EX2=250;EX2>EXC;EX2){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=160+0.2*full_parabola[EX2];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=-(0.2*EX2)+175;//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    EX2=EX2-4;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
   
   //LEG 3
        for(int EX3=250;EX3>EXC;EX3){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=160+0.2*full_parabola[EX3];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=(125);//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    EX3=EX3-4;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
   
  //LEG 4
     for(int EX4=150;EX4>EXC;EX4){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=130+0.2*full_parabola[EX4];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=-(0.3*EX4)+170;//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    EX4=EX4-3;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
   
   //LEG 5
     for(int EX5=150;EX5>EXC;EX5){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=130+0.2*full_parabola[EX5];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=(0.3*EX5)+85;//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    EX5=EX5-3;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }

  }
  
      //FIREWORK 4
    for(int FWC2=250;FWC2>1;FWC2--){
   for(int FW2=250;FW2>FWC2;FW2--){  //parabola takes one rotation to get to full extent as it's length is determined by k
    PORTB=220-0.9*parabola[FW2];
    PORTA=0.3*FW2+100;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
  }
  
  //LEG 1
  for(int EXC=250;EXC>0;EXC--){//OUTER COUNTER TO DETERMINE MOVEMENT
   for(int EX1=250;EX1>EXC;EX1){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=190+0.2*full_parabola[EX1];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=(0.2*EX1)+60;//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    EX1=EX1-4;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
  
  //LEG 2
     for(int EX2=250;EX2>EXC;EX2){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=190+0.2*full_parabola[EX2];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=-(0.2*EX2)+155;//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    EX2=EX2-4;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
   
   //LEG 3
        for(int EX3=250;EX3>EXC;EX3){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=190+0.2*full_parabola[EX3];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=(105);//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    EX3=EX3-4;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
   
  //LEG 4
     for(int EX4=150;EX4>EXC;EX4){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=160+0.2*full_parabola[EX4];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=-(0.3*EX4)+150;//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    EX4=EX4-3;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
   
   //LEG 5
     for(int EX5=150;EX5>EXC;EX5){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=160+0.2*full_parabola[EX5];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=(0.3*EX5)+65;//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    EX5=EX5-3;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }

  }
  
    
        //FIREWORK 5 (DOUBLE LAUNCH)
    for(int FWC2=250;FWC2>1;FWC2--){
   
      for(int FW2=250;FW2>FWC2;FW2--){  //parabola takes one rotation to get to full extent as it's length is determined by k
    PORTB=220-0.9*parabola[FW2];
    PORTA=0.3*FW2+100;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
   
   
   //FIREWORK 6 (DOUBLE LAUNCH)
     for(int FW3=250;FW3>FWC2;FW3--){  //parabola takes one rotation to get to full extent as it's length is determined by k
    PORTB=220-0.9*parabola[FW3];
    PORTA=-0.3*FW3-100;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
   
  }

  
  //LEG 1
  
  for(int EXC=250;EXC>0;EXC--){//OUTER COUNTER TO DETERMINE MOVEMENT
   for(int EX1=250;EX1>EXC;EX1){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=200+0.2*full_parabola[EX1];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=(0.2*EX1)+110;//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    EX1=EX1-4;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
   
      for(int EX1=250;EX1>EXC;EX1){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=190+0.2*full_parabola[EX1];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=(0.2*EX1)+60;//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    EX1=EX1-4;
    delayMicroseconds(20);//speed of parabola - may need adjusting
    
   }
  
  //LEG 2
     for(int EX2=250;EX2>EXC;EX2){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=200+0.2*full_parabola[EX2];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=-(0.2*EX2)+205;//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    EX2=EX2-4;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
   
        for(int EX2=250;EX2>EXC;EX2){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=190+0.2*full_parabola[EX2];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=-(0.2*EX2)+155;//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    EX2=EX2-4;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
   
   //LEG 3
        for(int EX3=250;EX3>EXC;EX3){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=200+0.2*full_parabola[EX3];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=(155);//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    EX3=EX3-4;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
   
   
           for(int EX3=250;EX3>EXC;EX3){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=190+0.2*full_parabola[EX3];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=(105);//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    EX3=EX3-4;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
   
  //LEG 4
     for(int EX4=150;EX4>EXC;EX4){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=170+0.2*full_parabola[EX4];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=-(0.3*EX4)+200;//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    EX4=EX4-3;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
   
       for(int EX4=150;EX4>EXC;EX4){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=160+0.2*full_parabola[EX4];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=-(0.3*EX4)+150;//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    EX4=EX4-3;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
   
   //LEG 5
     for(int EX5=150;EX5>EXC;EX5){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=170+0.2*full_parabola[EX5];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=(0.3*EX5)+105;//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    EX5=EX5-3;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
   
        for(int EX5=150;EX5>EXC;EX5){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=160+0.2*full_parabola[EX5];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=(0.3*EX5)+65;//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    EX5=EX5-3;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }

  }
  /*
      //FIREWORK  7
    for(int FWC2=250;FWC2>1;FWC2--){
   for(int FW2=250;FW2>FWC2;FW2--){  //parabola takes one rotation to get to full extent as it's length is determined by k
    PORTB=220-0.8*parabola[FW2];
    PORTA=-0.3*FW2-120;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
  }
  
    
        //FIREWORK 8 (TRIPLE LAUNCH)
    for(int FWC2=250;FWC2>1;FWC2--){
   
      for(int FW2=250;FW2>FWC2;FW2--){  //parabola takes one rotation to get to full extent as it's length is determined by k
    PORTB=180-0.7*parabola[FW2];
    PORTA=0.3*FW2+130;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
   //FIREWORK 9 (TRIPLE LAUNCH)
     for(int FW3=250;FW3>FWC2;FW3--){  //parabola takes one rotation to get to full extent as it's length is determined by k
    PORTB=180-0.7*parabola[FW3];
    PORTA=-0.3*FW3-70;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
   
    for(int FW4=250;FW4>FWC2;FW4--){  //parabola takes one rotation to get to full extent as it's length is determined by k
    PORTB=220-0.9*parabola[FW4];
    PORTA=0.5*FW4+130;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
   
  }
  */
  }
