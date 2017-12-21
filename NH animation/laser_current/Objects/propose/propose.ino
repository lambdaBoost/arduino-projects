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

void
line_vert(
        uint8_t x0,
        uint8_t y0,
        uint8_t w
)
{       
        PORTA = x0;
        PORTB = y0;
        for (int i = 0 ; i < w ; i++)
                PORTB++;
                 delayMicroseconds(8);
}

void    
line_horiz(
        uint8_t x0,
        uint8_t y0,
        uint8_t h
)       
{       
        PORTA = x0;
        PORTB = y0;
        
        for (int i = 0 ; i < h ; i++)
                PORTA++;
                 delayMicroseconds(8);
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

int PBD=40; //probe depth

//probe FRONT x coordinate variables
int Pxa=-20;
int Pxb=10;
int Pxc=10;
int Pxd=-10;
int Pxe=10;
int Pxea=-10;
int Pxf=60;
int Pxg=60;
int Pxh=-60;
int Pxi=-60;

//probe FRONT x coordinates
int Px1=120;//centrepoint
int Px1a=Px1+Pxa;//starting point on probe
int Px2=Px1+Pxb;
int Px3=Px1+Pxc;
int Px4=Px1+Pxd;
int Px5=Px1+Pxe;
int Px5a=Px1+Pxea;
int Px6=Px1+Pxf;
int Px7=Px1+Pxg;
int Px8=Px1+Pxh;
int Px9=Px1+Pxi;


  //propose left figure xcoordinate variables (start positions)
int pclx0=0;//datum
int pclx1=30;
int pclx2=60;
int pclx3=30;
int pclx3a=45;
int pclx3b=15;
int pclx4=60;
int pclx5=0;
int pclx6=30;
int phpx=30;//head x position

//propose left figure y coordinate variables
int pcly0=0;//datum
int pcly1=70;
int pcly2=0;
int pcly3=120;
int pcly3a=100;
int pcly3b=100;
int pcly4=80;
int pcly5=80;
int pcly6=140;
int phpy=130;//head y position
  

void loop(){

  
  //propose right figure xcoordinate variables (start positions)
int pcrx0=0;//datum
int pcrx1=15;//knee
int pcrx2=30;
int pcrx3=45;//knee
int pcrx4=60;
int pcrx5=30;
int pcrx6=45;
int pcrx7=60;
int pcrx8=15;
int pcrx9=0;
int phprx=138;//head x position

//propose right figure y coordinate variables
int pcry0=0;//datum
int pcry1=30;
int pcry2=70;
int pcry3=30;
int pcry4=0;
int pcry5=120;
int pcry6=95;
int pcry7=70;
int pcry8=95;
int pcry9=70;
int phpry=130;//head y position


if(millis()<1500){
  for(int PCC=1;255;PCC++){
    int PCLX0=10; //datum for left figure (left foot)
    int PCLY0=10;//y datum for left figure
    int PCRX0=120;//xdatum for right figure
    int PCRY0=10;//y datum for right figure
    
    
    
    //determine coordinates of left figure
    int PCLX1=PCLX0+pclx1;
     int PCLX2=PCLX0+pclx2;
       int PCLX3=PCLX0+pclx3;
       int PCLX3a=PCLX0+pclx3a;
       int PCLX3b=PCLX0+pclx3b;
     int PCLX4=PCLX0+pclx4;
     int PCLX5=PCLX0+pclx5;
     int PCLX6=PCLX0+pclx6;
   
   int PCLY1=PCLY0+pcly1;
   int PCLY2=PCLY0+pcly2;
   int PCLY3=PCLY0+pcly3;
   int PCLY3a=PCLY0+pcly3a;
   int PCLY3b=PCLY0+pcly3b;
   int PCLY4=PCLY0+pcly4;
   int PCLY5=PCLY0+pcly5;
   int PCLY6=PCLY0+pcly6;
   
   //plot left figure
   line(PCLX0,PCLY0,PCLX1,PCLY1);
   line(PCLX1,PCLY1,PCLX2,PCLY2);
    line(PCLX2,PCLY2,PCLX1,PCLY1);//leg retrace
   line(PCLX1,PCLY1,PCLX3,PCLY3);//body
   line(PCLX3,PCLY3,PCLX3a,PCLY3a);
   line(PCLX3a,PCLY3a,PCLX4,PCLY4);
   line(PCLX4,PCLY4,PCLX3a,PCLY3a);//arm retrace
   line(PCLX3a,PCLY3a,PCLX3,PCLY3);
   line(PCLX3,PCLY3,PCLX3b,PCLY3b);//arm
   line(PCLX3b,PCLY3b,PCLX5,PCLY5);
   line(PCLX5,PCLY5,PCLX3b,PCLY3b);//arm retrace
   line(PCLX3b,PCLY3b,PCLX3,PCLY3);
   
   //left figure head
   for(int lhc=0;lhc<256;lhc++){
   PORTA=0.1*sinTab[lhc]+phpx;//horizontal sin wave
  PORTB=0.1*sinTab[j++]+phpy;//vertical sin wave
  delayMicroseconds(8);
   }
   
   //retrace to ground
      line(PCLX3,PCLY3,PCLX1,PCLY1);
   line(PCLX1,PCLY1,PCLX2,PCLY2);
   
       //determine coordinates of right figure
    int PCRX1=PCRX0+pcrx1;
     int PCRX2=PCRX0+pcrx2;
       int PCRX3=PCRX0+pcrx3;
     int PCRX4=PCRX0+pcrx4;
     int PCRX5=PCRX0+pcrx5;
     int PCRX6=PCRX0+pcrx6;
      int PCRX7=PCRX0+pcrx7;
     int PCRX8=PCRX0+pcrx8;
     int PCRX9=PCRX0+pcrx9;
   
   int PCRY1=PCRY0+pcry1;
   int PCRY2=PCRY0+pcry2;
   int PCRY3=PCRY0+pcry3;
   int PCRY4=PCRY0+pcry4;
   int PCRY5=PCRY0+pcry5;
   int PCRY6=PCRY0+pcry6;
    int PCRY7=PCRY0+pcry7;
   int PCRY8=PCRY0+pcry8;
   int PCRY9=PCRY0+pcry9;
   
   
   //plot RIGHT figure
   line(PCRX0,PCRY0,PCRX1,PCRY1);
   line(PCRX1,PCRY1,PCRX2,PCRY2);
    line(PCRX2,PCRY2,PCRX3,PCRY3);
   line(PCRX3,PCRY3,PCRX4,PCRY4);
   line(PCRX4,PCRY4,PCRX3,PCRY3);//leg retrace to knee
    line(PCRX3,PCRY3,PCRX2,PCRY2);//leg retrace to body
   line(PCRX2,PCRY2,PCRX5,PCRY5);//body
    line(PCRX5,PCRY5,PCRX6,PCRY6);
     line(PCRX6,PCRY6,PCRX7,PCRY7);
    line(PCRX7,PCRY7,PCRX6,PCRY6);//retrace to elbow
     line(PCRX6,PCRY6,PCRX5,PCRY5);//retrace to body
      line(PCRX5,PCRY5,PCRX8,PCRY8);
       line(PCRX8,PCRY8,PCRX9,PCRY9);
     line(PCRX9,PCRY9,PCRX8,PCRY8);//retrace to elbow
      line(PCRX8,PCRY8,PCRX5,PCRY5);
   
   //right figure head
   for(int rhc=0;rhc<256;rhc++){
   PORTA=0.1*sinTab[rhc]+phprx;//horizontal sin wave
  PORTB=0.1*sinTab[j++]+phpry;//vertical sin wave
  delayMicroseconds(8);
   }
   
   //retrace
   line(PCRX5,PCRY5,PCRX2,PCRY2);
   line(PCRX2,PCRY2,PCRX1,PCRY1);
   line(PCRX1,PCRY1,PCRX0,PCRY0);
   
   //move figure

   
        pcry2=pcry2-1;
        pcrx1=pcrx1-0.1;//front knee
        pcrx3=pcrx3-0.002;//back knee
        pcry3=pcry3-0.0005;
        pcry5=pcry5-1;//top body
        pcry6=pcry6-1;//elbows
        pcrx7=pcrx7-2;
                pcrx8=pcrx8-0;
        pcry8=pcry8-1;
        pcry9=pcry9+1;
        pcrx9=pcrx9-1+1;
        pcry7=pcry7+1;
        phpry=phpry-1;//head

   
 if(pcry3<5){
   break;
 }
  }
  }
  
  if(4500>millis() && millis()>1500){
    for(int PCC=1;255;PCC++){
        int PCLX0=10; //datum for left figure (left foot)
    int PCLY0=10;//y datum for left figure
    int PCRX0=120;//xdatum for right figure
    int PCRY0=10;//y datum for right figure
    
 //determine coordinates of left figure
    int PCLX1=PCLX0+pclx1;
     int PCLX2=PCLX0+pclx2;
       int PCLX3=PCLX0+pclx3;
       int PCLX3a=PCLX0+pclx3a;
       int PCLX3b=PCLX0+pclx3b;
     int PCLX4=PCLX0+pclx4;
     int PCLX5=PCLX0+pclx5;
     int PCLX6=PCLX0+pclx6;
   
   int PCLY1=PCLY0+pcly1;
   int PCLY2=PCLY0+pcly2;
   int PCLY3=PCLY0+pcly3;
   int PCLY3a=PCLY0+pcly3a;
   int PCLY3b=PCLY0+pcly3b;
   int PCLY4=PCLY0+pcly4;
   int PCLY5=PCLY0+pcly5;
   int PCLY6=PCLY0+pcly6;
   
   //plot left figure
   line(PCLX0,PCLY0,PCLX1,PCLY1);
   line(PCLX1,PCLY1,PCLX2,PCLY2);
    line(PCLX2,PCLY2,PCLX1,PCLY1);//leg retrace
   line(PCLX1,PCLY1,PCLX3,PCLY3);//body
   line(PCLX3,PCLY3,PCLX3a,PCLY3a);
   line(PCLX3a,PCLY3a,PCLX4,PCLY4);
   line(PCLX4,PCLY4,PCLX3a,PCLY3a);//arm retrace
   line(PCLX3a,PCLY3a,PCLX3,PCLY3);
   line(PCLX3,PCLY3,PCLX3b,PCLY3b);//arm
   line(PCLX3b,PCLY3b,PCLX5,PCLY5);
   line(PCLX5,PCLY5,PCLX3b,PCLY3b);//arm retrace
   line(PCLX3b,PCLY3b,PCLX3,PCLY3);
   
   //left figure head
   for(int lhc=0;lhc<256;lhc++){
   PORTA=0.1*sinTab[lhc]+phpx;//horizontal sin wave
  PORTB=0.1*sinTab[j++]+phpy;//vertical sin wave
  delayMicroseconds(8);
   }
   
   //retrace to ground
      line(PCLX3,PCLY3,PCLX1,PCLY1);
   line(PCLX1,PCLY1,PCLX2,PCLY2);
   
   
       //determine coordinates of right figure
    int PCRX1=PCRX0+pcrx1;
     int PCRX2=PCRX0+pcrx2;
       int PCRX3=PCRX0+pcrx3;
     int PCRX4=PCRX0+pcrx4;
     int PCRX5=PCRX0+pcrx5;
     int PCRX6=PCRX0+pcrx6;
      int PCRX7=PCRX0+pcrx7;
     int PCRX8=PCRX0+pcrx8;
     int PCRX9=PCRX0+pcrx9;
   
   int PCRY1=PCRY0+pcry1;
   int PCRY2=PCRY0+pcry2;
   int PCRY3=PCRY0+pcry3;
   int PCRY4=PCRY0+pcry4;
   int PCRY5=PCRY0+pcry5;
   int PCRY6=PCRY0+pcry6;
    int PCRY7=PCRY0+pcry7;
   int PCRY8=PCRY0+pcry8;
   int PCRY9=PCRY0+pcry9;
   
   
   //plot RIGHT figure
   line(PCRX0,PCRY0,PCRX1,PCRY1);
   line(PCRX1,PCRY1,PCRX2,PCRY2);
    line(PCRX2,PCRY2,PCRX3,PCRY3);
   line(PCRX3,PCRY3,PCRX4,PCRY4);
   line(PCRX4,PCRY4,PCRX3,PCRY3);//leg retrace to knee
    line(PCRX3,PCRY3,PCRX2,PCRY2);//leg retrace to body
   line(PCRX2,PCRY2,PCRX5,PCRY5);//body
    line(PCRX5,PCRY5,PCRX6,PCRY6);
     line(PCRX6,PCRY6,PCRX7,PCRY7);
    line(PCRX7,PCRY7,PCRX6,PCRY6);//retrace to elbow
     line(PCRX6,PCRY6,PCRX5,PCRY5);//retrace to body
      line(PCRX5,PCRY5,PCRX8,PCRY8);
       line(PCRX8,PCRY8,PCRX9,PCRY9);
     line(PCRX9,PCRY9,PCRX8,PCRY8);//retrace to elbow
      line(PCRX8,PCRY8,PCRX5,PCRY5);
   
   //right figure head
   for(int rhc=0;rhc<256;rhc++){
   PORTA=0.1*sinTab[rhc]+phprx;//horizontal sin wave
  PORTB=0.1*sinTab[j++]+phpry;//vertical sin wave
  delayMicroseconds(8);
   }
   
   //retrace
   line(PCRX5,PCRY5,PCRX2,PCRY2);
   line(PCRX2,PCRY2,PCRX1,PCRY1);
   line(PCRX1,PCRY1,PCRX0,PCRY0);
   
     //move arms
 // pclx3b=pclx3b+1;
 // pcly5=pcly5+1;
  pcly4=pcly4+1;
  pclx4=pclx4-(PCC/20);
  
  pcly5=pcly5+1;
  pclx3b=pclx3b+(PCC/20);
  pclx5=pclx5+(PCC/20);
  
if(millis()>5500){
  break;
}
  
  }
  

  }
  
  if(millis()>5500 && millis()<7000){
     for(int PCC=1;255;PCC++){
        int PCLX0=10; //datum for left figure (left foot)
    int PCLY0=10;//y datum for left figure
    int PCRX0=120;//xdatum for right figure
    int PCRY0=10;//y datum for right figure
    
 //determine coordinates of left figure
    int PCLX1=PCLX0+pclx1;
     int PCLX2=PCLX0+pclx2;
       int PCLX3=PCLX0+pclx3;
       int PCLX3a=PCLX0+pclx3a;
       int PCLX3b=PCLX0+pclx3b;
     int PCLX4=PCLX0+pclx4;
     int PCLX5=PCLX0+pclx5;
     int PCLX6=PCLX0+pclx6;
   
   int PCLY1=PCLY0+pcly1;
   int PCLY2=PCLY0+pcly2;
   int PCLY3=PCLY0+pcly3;
   int PCLY3a=PCLY0+pcly3a;
   int PCLY3b=PCLY0+pcly3b;
   int PCLY4=PCLY0+pcly4;
   int PCLY5=PCLY0+pcly5;
   int PCLY6=PCLY0+pcly6;
   
   //plot left figure
   line(PCLX0,PCLY0,PCLX1,PCLY1);
   line(PCLX1,PCLY1,PCLX2,PCLY2);
    line(PCLX2,PCLY2,PCLX1,PCLY1);//leg retrace
   line(PCLX1,PCLY1,PCLX3,PCLY3);//body
   line(PCLX3,PCLY3,PCLX3a,PCLY3a);
   line(PCLX3a,PCLY3a,PCLX4,PCLY4);
   line(PCLX4,PCLY4,PCLX3a,PCLY3a);//arm retrace
   line(PCLX3a,PCLY3a,PCLX3,PCLY3);
   line(PCLX3,PCLY3,PCLX3b,PCLY3b);//arm
   line(PCLX3b,PCLY3b,PCLX5,PCLY5);
   line(PCLX5,PCLY5,PCLX3b,PCLY3b);//arm retrace
   line(PCLX3b,PCLY3b,PCLX3,PCLY3);
   
   //left figure head
   for(int lhc=0;lhc<256;lhc++){
   PORTA=0.1*sinTab[lhc]+phpx;//horizontal sin wave
  PORTB=0.1*sinTab[j++]+phpy;//vertical sin wave
  delayMicroseconds(8);
   }
   
   //retrace to ground
      line(PCLX3,PCLY3,PCLX1,PCLY1);
   line(PCLX1,PCLY1,PCLX2,PCLY2);
   
   
       //determine coordinates of right figure
    int PCRX1=PCRX0+pcrx1;
     int PCRX2=PCRX0+pcrx2;
       int PCRX3=PCRX0+pcrx3;
     int PCRX4=PCRX0+pcrx4;
     int PCRX5=PCRX0+pcrx5;
     int PCRX6=PCRX0+pcrx6;
      int PCRX7=PCRX0+pcrx7;
     int PCRX8=PCRX0+pcrx8;
     int PCRX9=PCRX0+pcrx9;
   
   int PCRY1=PCRY0+pcry1;
   int PCRY2=PCRY0+pcry2;
   int PCRY3=PCRY0+pcry3;
   int PCRY4=PCRY0+pcry4;
   int PCRY5=PCRY0+pcry5;
   int PCRY6=PCRY0+pcry6;
    int PCRY7=PCRY0+pcry7;
   int PCRY8=PCRY0+pcry8;
   int PCRY9=PCRY0+pcry9;
   
   
   //plot RIGHT figure
   line(PCRX0,PCRY0,PCRX1,PCRY1);
   line(PCRX1,PCRY1,PCRX2,PCRY2);
    line(PCRX2,PCRY2,PCRX3,PCRY3);
   line(PCRX3,PCRY3,PCRX4,PCRY4);
   line(PCRX4,PCRY4,PCRX3,PCRY3);//leg retrace to knee
    line(PCRX3,PCRY3,PCRX2,PCRY2);//leg retrace to body
   line(PCRX2,PCRY2,PCRX5,PCRY5);//body
    line(PCRX5,PCRY5,PCRX6,PCRY6);
     line(PCRX6,PCRY6,PCRX7,PCRY7);
    line(PCRX7,PCRY7,PCRX6,PCRY6);//retrace to elbow
     line(PCRX6,PCRY6,PCRX5,PCRY5);//retrace to body
      line(PCRX5,PCRY5,PCRX8,PCRY8);
       line(PCRX8,PCRY8,PCRX9,PCRY9);
     line(PCRX9,PCRY9,PCRX8,PCRY8);//retrace to elbow
      line(PCRX8,PCRY8,PCRX5,PCRY5);
   
   //right figure head
   for(int rhc=0;rhc<256;rhc++){
   PORTA=0.1*sinTab[rhc]+phprx;//horizontal sin wave
  PORTB=0.1*sinTab[j++]+phpry;//vertical sin wave
  delayMicroseconds(8);
   }
   
   //retrace
   line(PCRX5,PCRY5,PCRX2,PCRY2);
   line(PCRX2,PCRY2,PCRX1,PCRY1);
   line(PCRX1,PCRY1,PCRX0,PCRY0);
   
   if(millis()>7000){
     break;
   }
     }
  }
  
  
  
  if(millis()>7000 && millis()<10000){
         for(int PCC=1;255;PCC++){
        int PCLX0=10; //datum for left figure (left foot)
    int PCLY0=10;//y datum for left figure
    int PCRX0=120;//xdatum for right figure
    int PCRY0=10;//y datum for right figure
    
 //determine coordinates of left figure
    int PCLX1=PCLX0+pclx1;
     int PCLX2=PCLX0+pclx2;
       int PCLX3=PCLX0+pclx3;
       int PCLX3a=PCLX0+pclx3a;
       int PCLX3b=PCLX0+pclx3b;
     int PCLX4=PCLX0+pclx4;
     int PCLX5=PCLX0+pclx5;
     int PCLX6=PCLX0+pclx6;
   
   int PCLY1=PCLY0+pcly1;
   int PCLY2=PCLY0+pcly2;
   int PCLY3=PCLY0+pcly3;
   int PCLY3a=PCLY0+pcly3a;
   int PCLY3b=PCLY0+pcly3b;
   int PCLY4=PCLY0+pcly4;
   int PCLY5=PCLY0+pcly5;
   int PCLY6=PCLY0+pcly6;
   
   //plot left figure
   line(PCLX0,PCLY0,PCLX1,PCLY1);
   line(PCLX1,PCLY1,PCLX2,PCLY2);
    line(PCLX2,PCLY2,PCLX1,PCLY1);//leg retrace
   line(PCLX1,PCLY1,PCLX3,PCLY3);//body
   line(PCLX3,PCLY3,PCLX3a,PCLY3a);
   line(PCLX3a,PCLY3a,PCLX4,PCLY4);
   line(PCLX4,PCLY4,PCLX3a,PCLY3a);//arm retrace
   line(PCLX3a,PCLY3a,PCLX3,PCLY3);
   line(PCLX3,PCLY3,PCLX3b,PCLY3b);//arm
   line(PCLX3b,PCLY3b,PCLX5,PCLY5);
   line(PCLX5,PCLY5,PCLX3b,PCLY3b);//arm retrace
   line(PCLX3b,PCLY3b,PCLX3,PCLY3);
   
   //left figure head
   for(int lhc=0;lhc<256;lhc++){
   PORTA=0.1*sinTab[lhc]+phpx;//horizontal sin wave
  PORTB=0.1*sinTab[j++]+phpy;//vertical sin wave
  delayMicroseconds(8);
   }
   
   //speech bubble
   
      for(int lhc2=0;lhc2<256;lhc2++){
   PORTA=0.45*sinTab[lhc2]+phpx-20;//horizontal sin wave
  PORTB=0.25*sinTab[j++]+phpy+45;//vertical sin wave
  delayMicroseconds(8);
   }
   
   //writing
   line(100,180,100,205);//Y
   line(100,205,115,220);
   line(115,220,100,205);
   line(100,205,85,225);
   line(75,215,75,190);//E
   line(75,190,60,190);
   line(60,190,75,190);
   line(75,190,75,202);
   line(75,202,60,202);
   line(60,202,75,202);
   line(75,202,75,215);
   line(75,215,60,215);
   line(30,215,60,215);//S
   line(60,215,60,200);
   line(60,200,30,200);
   line(30,200,30,190);
   line(30,190,60,190);
   
   //retrace to ground
      line(PCLX3,PCLY3,PCLX1,PCLY1);
   line(PCLX1,PCLY1,PCLX2,PCLY2);
   
   
       //determine coordinates of right figure
    int PCRX1=PCRX0+pcrx1;
     int PCRX2=PCRX0+pcrx2;
       int PCRX3=PCRX0+pcrx3;
     int PCRX4=PCRX0+pcrx4;
     int PCRX5=PCRX0+pcrx5;
     int PCRX6=PCRX0+pcrx6;
      int PCRX7=PCRX0+pcrx7;
     int PCRX8=PCRX0+pcrx8;
     int PCRX9=PCRX0+pcrx9;
   
   int PCRY1=PCRY0+pcry1;
   int PCRY2=PCRY0+pcry2;
   int PCRY3=PCRY0+pcry3;
   int PCRY4=PCRY0+pcry4;
   int PCRY5=PCRY0+pcry5;
   int PCRY6=PCRY0+pcry6;
    int PCRY7=PCRY0+pcry7;
   int PCRY8=PCRY0+pcry8;
   int PCRY9=PCRY0+pcry9;
   
   
   //plot RIGHT figure
   line(PCRX0,PCRY0,PCRX1,PCRY1);
   line(PCRX1,PCRY1,PCRX2,PCRY2);
    line(PCRX2,PCRY2,PCRX3,PCRY3);
   line(PCRX3,PCRY3,PCRX4,PCRY4);
   line(PCRX4,PCRY4,PCRX3,PCRY3);//leg retrace to knee
    line(PCRX3,PCRY3,PCRX2,PCRY2);//leg retrace to body
   line(PCRX2,PCRY2,PCRX5,PCRY5);//body
    line(PCRX5,PCRY5,PCRX6,PCRY6);
     line(PCRX6,PCRY6,PCRX7,PCRY7);
    line(PCRX7,PCRY7,PCRX6,PCRY6);//retrace to elbow
     line(PCRX6,PCRY6,PCRX5,PCRY5);//retrace to body
      line(PCRX5,PCRY5,PCRX8,PCRY8);
       line(PCRX8,PCRY8,PCRX9,PCRY9);
     line(PCRX9,PCRY9,PCRX8,PCRY8);//retrace to elbow
      line(PCRX8,PCRY8,PCRX5,PCRY5);
   
   //right figure head
   for(int rhc=0;rhc<256;rhc++){
   PORTA=0.1*sinTab[rhc]+phprx;//horizontal sin wave
  PORTB=0.1*sinTab[j++]+phpry;//vertical sin wave
  delayMicroseconds(8);
   }
   
   //retrace
   line(PCRX5,PCRY5,PCRX2,PCRY2);
   line(PCRX2,PCRY2,PCRX1,PCRY1);
   line(PCRX1,PCRY1,PCRX0,PCRY0);
   
   if(millis()>10000){
     break;
   }
     }
  }
  
 if(millis()>10000){
            for(int PCC=1;255;PCC++){
        int PCLX0=10; //datum for left figure (left foot)
    int PCLY0=10;//y datum for left figure
    int PCRX0=120;//xdatum for right figure
    int PCRY0=10;//y datum for right figure
    
 //determine coordinates of left figure
    int PCLX1=PCLX0+pclx1;
     int PCLX2=PCLX0+pclx2;
       int PCLX3=PCLX0+pclx3;
       int PCLX3a=PCLX0+pclx3a;
       int PCLX3b=PCLX0+pclx3b;
     int PCLX4=PCLX0+pclx4;
     int PCLX5=PCLX0+pclx5;
     int PCLX6=PCLX0+pclx6;
   
   int PCLY1=PCLY0+pcly1;
   int PCLY2=PCLY0+pcly2;
   int PCLY3=PCLY0+pcly3;
   int PCLY3a=PCLY0+pcly3a;
   int PCLY3b=PCLY0+pcly3b;
   int PCLY4=PCLY0+pcly4;
   int PCLY5=PCLY0+pcly5;
   int PCLY6=PCLY0+pcly6;
   
   //plot left figure
   line(PCLX0,PCLY0,PCLX1,PCLY1);
   line(PCLX1,PCLY1,PCLX2,PCLY2);
    line(PCLX2,PCLY2,PCLX1,PCLY1);//leg retrace
   line(PCLX1,PCLY1,PCLX3,PCLY3);//body
   line(PCLX3,PCLY3,PCLX3a,PCLY3a);
   line(PCLX3a,PCLY3a,PCLX4,PCLY4);
   line(PCLX4,PCLY4,PCLX3a,PCLY3a);//arm retrace
   line(PCLX3a,PCLY3a,PCLX3,PCLY3);
   line(PCLX3,PCLY3,PCLX3b,PCLY3b);//arm
   line(PCLX3b,PCLY3b,PCLX5,PCLY5);
   line(PCLX5,PCLY5,PCLX3b,PCLY3b);//arm retrace
   line(PCLX3b,PCLY3b,PCLX3,PCLY3);
   
   //left figure head
   for(int lhc=0;lhc<256;lhc++){
   PORTA=0.1*sinTab[lhc]+phpx;//horizontal sin wave
  PORTB=0.1*sinTab[j++]+phpy;//vertical sin wave
  delayMicroseconds(8);
   }
   
   //speech bubble
   
      for(int lhc2=0;lhc2<256;lhc2++){
   PORTA=0.45*sinTab[lhc2]+phpx-20;//horizontal sin wave
  PORTB=0.25*sinTab[j++]+phpy+45;//vertical sin wave
  delayMicroseconds(8);
   }
   
   //writing
   line(100,180,100,205);//Y
   line(100,205,115,220);
   line(115,220,100,205);
   line(100,205,85,225);
   line(75,215,75,190);//E
   line(75,190,60,190);
   line(60,190,75,190);
   line(75,190,75,202);
   line(75,202,60,202);
   line(60,202,75,202);
   line(75,202,75,215);
   line(75,215,60,215);
   line(30,215,60,215);//S
   line(60,215,60,200);
   line(60,200,30,200);
   line(30,200,30,190);
   line(30,190,60,190);
   
   //retrace to ground
      line(PCLX3,PCLY3,PCLX1,PCLY1);
   line(PCLX1,PCLY1,PCLX2,PCLY2);
   
   
       //determine coordinates of right figure
    int PCRX1=PCRX0+pcrx1;
     int PCRX2=PCRX0+pcrx2;
       int PCRX3=PCRX0+pcrx3;
     int PCRX4=PCRX0+pcrx4;
     int PCRX5=PCRX0+pcrx5;
     int PCRX6=PCRX0+pcrx6;
      int PCRX7=PCRX0+pcrx7;
     int PCRX8=PCRX0+pcrx8;
     int PCRX9=PCRX0+pcrx9-10;
   
   int PCRY1=PCRY0+pcry1;
   int PCRY2=PCRY0+pcry2;
   int PCRY3=PCRY0+pcry3;
   int PCRY4=PCRY0+pcry4;
   int PCRY5=PCRY0+pcry5;
   int PCRY6=PCRY0+pcry6;
    int PCRY7=PCRY0+pcry7+50;
   int PCRY8=PCRY0+pcry8;
   int PCRY9=PCRY0+pcry9+50;
   
   
   //plot RIGHT figure
   line(PCRX0,PCRY0,PCRX1,PCRY1);
   line(PCRX1,PCRY1,PCRX2,PCRY2);
    line(PCRX2,PCRY2,PCRX3,PCRY3);
   line(PCRX3,PCRY3,PCRX4,PCRY4);
   line(PCRX4,PCRY4,PCRX3,PCRY3);//leg retrace to knee
    line(PCRX3,PCRY3,PCRX2,PCRY2);//leg retrace to body
   line(PCRX2,PCRY2,PCRX5,PCRY5);//body
    line(PCRX5,PCRY5,PCRX7,PCRY7);//arm
     line(PCRX7,PCRY7,PCRX5,PCRY5);//retrace to body
      line(PCRX5,PCRY5,PCRX9,PCRY9);
     line(PCRX9,PCRY9,PCRX5,PCRY5);//retrace
   
   //right figure head
   for(int rhc=0;rhc<256;rhc++){
   PORTA=0.1*sinTab[rhc]+phprx;//horizontal sin wave
  PORTB=0.1*sinTab[j++]+phpry;//vertical sin wave
  delayMicroseconds(8);
   }
   
   //retrace
   line(PCRX5,PCRY5,PCRX2,PCRY2);
   line(PCRX2,PCRY2,PCRX1,PCRY1);
   line(PCRX1,PCRY1,PCRX0,PCRY0);
   

     }
 }
}
