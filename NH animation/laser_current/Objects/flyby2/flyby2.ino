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
  
  for(int PFC=1;PFC<255;PFC++){//probeflyby counter
  
  //draw mountain
 // line(10,20,40,30);
  //line(40,30,30,20);
  //line(30,20,70,40);
  line(70,40,40,30);
  line(40,30,50,70);
  line(50,70,80,90);
  line(80,90,120,60);//4-13
  line(120,60,70,40);//13-14
  line(70,40,50,70);//line 14-3
  line(50,70,120,60);//3-13
  line(120,60,130,95);//13-16
  line(130,95,80,90);//16-4
  line(80,90,100,160);//4-5
  line(100,160,130,150);//5-6
  line(130,150,80,90);//6-4
  line(80,90,130,95);//4-16
  line(130,95,130,150);//16-6
  line(130,150,200,60);//6-8
  line(200,60,150,10);//8-12
  line(150,10,210,30);//12-11
  line(210,30,200,60);//11-8
  line(200,60,170,130);//8-7
  line(170,130,130,150);//7-6
  line(130,150,130,95);//6-16
  line(130,95,200,60);//16-8
  line(200,60,220,70);//8-9
  line(220,70,210,30);//9-11
  line(210,30,220,70);//11-9
  line(220,70,250,40);//9-10
  line(250,40,210,30);//10-11
  line(210,30,150,10);//11-12
  line(150,10,130,95);//12-16
  line(130,95,120,60);//16-13
  line(120,60,150,10);//13-12
  line(150,10,75,30);//12-15
  line(75,30,30,20);//12-15
  
   
   //PROBE   
   for(int PFBC=1;PFBC<255;PFBC++){
   PORTA=0.02*sinTab[PFBC]+PFC;//horizontal sin wave
  PORTB=0.02*sinTab[j++]+200;//vertical sin wave
  delayMicroseconds(8);
   }
  }
}
  
  
