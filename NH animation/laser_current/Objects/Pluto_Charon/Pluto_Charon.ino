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

unsigned char j=64; // circle phase counter
unsigned char R=64;//independent phase counter

//probe x coordinate variables
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

//probe x coordinates
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





void loop() {
  for(int PLCH=1;PLCH<255;PLCH++){
  digitalWrite(8,HIGH);
  //pluto
  for(int i=0;i<256;i++){
    PORTA=0.5*sinTab[i]+125;//horizontal sin wave
  PORTB=0.5*sinTab[j++]+60;//vertical sin wave
  delayMicroseconds(8);//delay between points
    }
  
 /* //pluto equator  
     for(int i=0;i<256;i++){
    PORTA=0.48*sinTab[i]+125;//horizontal sin wave
  PORTB=0.05*sinTab[j++]+120;//vertical sin wave
  delayMicroseconds(20);//delay between points
    }*/
   
   //pluto meridian
        for(int i=0;i<256;i++){
    PORTA=0.08*sinTab[i]+175;//horizontal sin wave
  PORTB=0.5*sinTab[j++]+63;//vertical sin wave
  delayMicroseconds(8);//delay between points
    }
    
     //pluto longditude lines
        for(int i=0;i<256;i++){
    PORTA=0.3*sinTab[i]+145;//horizontal sin wave
  PORTB=0.5*sinTab[j++]+63;//vertical sin wave
  delayMicroseconds(8);//delay between points
    }
   
   
   //charon 
   for(int i=0;i<256;i++){
    PORTA=0.25*sinTab[i];//horizontal sin wave
  PORTB=0.25*sinTab[j++]+160;//vertical sin wave
  delayMicroseconds(8);//delay between points
    }
    
    //charon equator
       for(int i=0;i<256;i++){
    PORTA=0.25*sinTab[i]+3;//horizontal sin wave
  PORTB=0.05*sinTab[j++]+185;//vertical sin wave
  delayMicroseconds(8);//delay between points
    }
    
       //PROBE   
   for(int PCFB=1;PCFB<255;PCFB++){
   PORTA=0.02*sinTab[PCFB]+PLCH;//horizontal sin wave
  PORTB=0.02*sinTab[R++]+100;//vertical sin wave
  delayMicroseconds(8);
   }
}

}
  
