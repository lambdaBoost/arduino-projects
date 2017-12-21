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
fastline(
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
                 delayMicroseconds(20);
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
  

void loop() {
  if (millis()<5000){

  for(int ESBC=255;ESBC>1;ESBC){
    //verticl elements
    fastline(50,1,50,254); //building side
     fastline(70,254,70,1); 
      fastline(90,1,90,254);
      fastline(92,254,92,1);  
      // fastline(110,1,110,254); 
        // fastline(130,254,130,1); 
          fastline(150,1,150,254);
          fastline(152,254,152,1);  
           fastline(170,1,170,254); 
            fastline(190,254,190,1); //building side
            
  //horizontal elements
  /*
  line(50,ESBC,190,ESBC);
   line(195,ESBC+50,50,ESBC+50);
    line(50,ESBC+100,195,ESBC+100);
     line(195,ESBC+150,50,ESBC+150);
       line(50,ESBC+200,195,ESBC+200);
         line(195,ESBC+250,50,ESBC+250);
 */
 ESBC=ESBC-4;
  }
  }
  
  
  if(millis()>5000 && millis()<8000){
   
  for(int ESBC=255;ESBC>1;ESBC){
    //scrolling building
    fastline(50,1,50,ESBC-40); //building side
    fastline(50,ESBC-40,70,ESBC-40);
    fastline(70,ESBC-40,70,ESBC-20);
    fastline(70,ESBC-20,95,ESBC-20);
    fastline(95,ESBC-20,95,ESBC);
    fastline(95,ESBC,155,ESBC);//roof
   
    fastline(120,ESBC,125,254);
    fastline(125,254,130,ESBC);//spire
    

    
    fastline(155,ESBC,155,ESBC-20);
    fastline(155,ESBC-20,180,ESBC-20);
    fastline(180,ESBC-20,180,ESBC-40);
    fastline(180,ESBC-40,200,ESBC-40);
    
        fastline(150,ESBC,150,1); //vertical internals
    fastline(130,1,130,ESBC);
        fastline(120,ESBC,120,1); //vertical internals
    fastline(110,1,110,ESBC);
        fastline(120,ESBC,120,1); //vertical internals
    fastline(90,1,90,ESBC);
    
   
    fastline(200,ESBC-40,200,1);
   

          
 ESBC=ESBC-2;
 if(millis()>8000){
   break;
 }
  }
  }
   
   if(millis()>8000 && millis()<12000){
     int ESBC=120;
     for(int HZ=1;HZ<512;HZ){
        fastline(50-(0.1*HZ),1,50-(0.1*HZ),ESBC-40-(0.1*HZ)); //building side
    fastline(50-(0.1*HZ),ESBC-40-(0.1*HZ),70-(0.1*HZ),ESBC-40-(0.1*HZ));
    fastline(70-(0.1*HZ),ESBC-40-(0.1*HZ),70-(0.1*HZ),ESBC-20-(0.1*HZ));
    fastline(70-(0.1*HZ),ESBC-20-(0.1*HZ),95-(0.1*HZ),ESBC-20-(0.1*HZ));
    fastline(95-(0.1*HZ),ESBC-20,95-(0.1*HZ),ESBC);
    fastline(95-(0.1*HZ),ESBC,155+(0.1*HZ),ESBC);//roof
   
    fastline(120-(0.02*HZ),ESBC,125-(0.02*HZ),254);
    fastline(125-(0.02*HZ),254,125+(0.02*HZ),254);
    fastline(125+(0.02*HZ),254,130+(0.02*HZ),ESBC);//spire
    
    
    fastline(155+(0.1*HZ),ESBC,155+(0.1*HZ),ESBC-20-(0.1*HZ));
    fastline(155+(0.1*HZ),ESBC-20-(0.1*HZ),180+(0.1*HZ),ESBC-20-(0.1*HZ));
    fastline(180+(0.1*HZ),ESBC-20-(0.1*HZ),180+(0.1*HZ),ESBC-40-(0.1*HZ));
    fastline(180+(0.1*HZ),ESBC-40-(0.1*HZ),200+(0.1*HZ),ESBC-40-(0.1*HZ));
    
        fastline(150+(0.1*HZ),ESBC,150+(0.1*HZ),1); //vertical internals
    fastline(130+(0.1*HZ),1,130+(0.1*HZ),ESBC);
        fastline(120-(0.1*HZ),ESBC,120-(0.1*HZ),1); //vertical internals
    fastline(110-(0.1*HZ),1,110-(0.1*HZ),ESBC);
        fastline(120-(0.1*HZ),ESBC,120-(0.1*HZ),1); //vertical internals
    fastline(90-(0.1*HZ),1,90-(0.1*HZ),ESBC);
    
   // fastline(200+(0.1*HZ),ESBC-80-(0.1*HZ),50-(0.1*HZ),ESBC-80-(0.1*HZ));//horizontal
   // fastline(50-(0.1*HZ),ESBC-120-(0.1*HZ),200+(0.1*HZ),ESBC-120-(0.1*HZ));//horizontal
   // fastline(200+(0.1*HZ),ESBC-40-(0.1*HZ),50-(0.1*HZ),ESBC-40-(0.1*HZ));//horizontal
    fastline(200+(0.1*HZ),ESBC-40-(0.1*HZ),200+(0.1*HZ),1);
   
   HZ=HZ+2;
   } 
   }
   
   if(millis()>12000){
          int ESBC=120;
          int HZ=520;
     
        fastline(50-(0.1*HZ),1,50-(0.1*HZ),ESBC-40-(0.1*HZ)); //building side
    fastline(50-(0.1*HZ),ESBC-40-(0.1*HZ),70-(0.1*HZ),ESBC-40-(0.1*HZ));
    fastline(70-(0.1*HZ),ESBC-40-(0.1*HZ),70-(0.1*HZ),ESBC-20-(0.1*HZ));
    fastline(70-(0.1*HZ),ESBC-20-(0.1*HZ),95-(0.1*HZ),ESBC-20-(0.1*HZ));
    fastline(95-(0.1*HZ),ESBC-20,95-(0.1*HZ),ESBC);
    fastline(95-(0.1*HZ),ESBC,155+(0.1*HZ),ESBC);//roof
   
    fastline(120-(0.02*HZ),ESBC,125-(0.02*HZ),254);
    fastline(125-(0.02*HZ),254,125+(0.02*HZ),254);
    fastline(125+(0.02*HZ),254,130+(0.02*HZ),ESBC);//spire
    
    //stick figure 1
      line(150,120,160,130);//legs
      line(160,130,170,120);
      line(160,130,160,140);//body
      line(160,140,170,130);//arms
      line(170,130,160,140);
      line(160,140,150,130);
      
    //head
       for(int NYH1=0;NYH1<256;NYH1++){
   PORTA=0.02*sinTab[NYH1]+158;//horizontal sin wave
  PORTB=0.02*sinTab[j++]+138;//vertical sin wave
  delayMicroseconds(8);
       }
       
  //stick figure 2
  line(170,130,180,140);//arm
      //head
       for(int NYH1=0;NYH1<256;NYH1++){
   PORTA=0.02*sinTab[NYH1]+178;//horizontal sin wave
  PORTB=0.02*sinTab[j++]+138;//vertical sin wave
  delayMicroseconds(8);
       }
  line(180,140,190,130);//arm
  line(190,130,180,140);//arm retrace
  line(180,140,180,130);//body
  line(180,130,190,120);//leg
  line(190,120,180,130);//leg retrace
  line(180,130,170,120);
    
    fastline(155+(0.1*HZ),ESBC,155+(0.1*HZ),ESBC-20-(0.1*HZ));
    fastline(155+(0.1*HZ),ESBC-20-(0.1*HZ),180+(0.1*HZ),ESBC-20-(0.1*HZ));
    fastline(180+(0.1*HZ),ESBC-20-(0.1*HZ),180+(0.1*HZ),ESBC-40-(0.1*HZ));
    fastline(180+(0.1*HZ),ESBC-40-(0.1*HZ),200+(0.1*HZ),ESBC-40-(0.1*HZ));
    
        fastline(150+(0.1*HZ),ESBC,150+(0.1*HZ),1); //vertical internals
    fastline(130+(0.1*HZ),1,130+(0.1*HZ),ESBC);
        fastline(120-(0.1*HZ),ESBC,120-(0.1*HZ),1); //vertical internals
    fastline(110-(0.1*HZ),1,110-(0.1*HZ),ESBC);
        fastline(120-(0.1*HZ),ESBC,120-(0.1*HZ),1); //vertical internals
    fastline(90-(0.1*HZ),1,90-(0.1*HZ),ESBC);
    
   // fastline(200+(0.1*HZ),ESBC-80-(0.1*HZ),50-(0.1*HZ),ESBC-80-(0.1*HZ));//horizontal
   // fastline(50-(0.1*HZ),ESBC-120-(0.1*HZ),200+(0.1*HZ),ESBC-120-(0.1*HZ));//horizontal
   // fastline(200+(0.1*HZ),ESBC-40-(0.1*HZ),50-(0.1*HZ),ESBC-40-(0.1*HZ));//horizontal
    fastline(200+(0.1*HZ),ESBC-40-(0.1*HZ),200+(0.1*HZ),1);
    
    
   
   
   
   }
}
