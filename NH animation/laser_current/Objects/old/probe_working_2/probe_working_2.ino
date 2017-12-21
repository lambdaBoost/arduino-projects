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

//probe front working y coordinates variables
int Pya=30;
int Pyb=30;
int Pyc=80;
int Pyd=80;
int Pye=30;
int Pyf=-60;
int Pyg=-60;
int Pyh=-60;
int Pyi=-30;


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

//probe FRONT y coordinates
int Py1=150;//centrepoint
int Py1a=Py1+Pya;//starting point on probe
int Py2=Py1+Pyb;
int Py3=Py1+Pyc;
int Py4=Py1+Pyd;
int Py5=Py1+Pye;
int Py6=Py1+Pyf;
int Py7=Py1+Pyg;
int Py8=Py1+Pyh;
int Py9=Py1+Pyi;



void loop() {
  
  
  //front side
for (int NHPC=1;NHPC<628;NHPC){

  //probe FRONT moving coordinates
  int Pxar=Pxa*cos(0.01*NHPC);//cos function rotates
int Pxbr=Pxb*cos(0.01*NHPC);
int Pxcr=Pxc*cos(0.01*NHPC);
int Pxdr=Pxd*cos(0.01*NHPC);
int Pxer=Pxe*cos(0.01*NHPC);
int Pxear=Pxea*cos(0.01*NHPC);
int Pxfr=Pxf*cos(0.01*NHPC);
int Pxgr=Pxg*cos(0.01*NHPC);
int Pxhr=Pxh*cos(0.01*NHPC);
int Pxir=Pxi*cos(0.01*NHPC);

//probe REAR moving x coordinates



//x coordinates after rotation
int Px1=120;//centrepoint
int Px1ar=Px1+Pxar;//starting point on probe
int Px2r=Px1+Pxbr;
int Px3r=Px1+Pxcr;
int Px4r=Px1+Pxdr;
int Px5r=Px1+Pxer;
int Px5ar=Px1+Pxear;
int Px6r=Px1+Pxfr;
int Px7r=Px1+Pxgr;
int Px8r=Px1+Pxhr;
int Px9r=Px1+Pxir;

//x coordinates of rear after rotation
int Px1arr=Px1+PBD*sin(0.01*NHPC);//addition varies x position of rear relative to front to simulate rotation
int Px2rr=Px2r+PBD*sin(0.01*NHPC);
int Px3rr=Px3r+PBD*sin(0.01*NHPC);
int Px4rr=Px4r+PBD*sin(0.01*NHPC);
int Px5rr=Px5r+PBD*sin(0.01*NHPC);
int Px5arr=Px5ar+PBD*sin(0.01*NHPC);
int Px6rr=Px6r+PBD*sin(0.01*NHPC);
int Px7rr=Px7r+PBD*sin(0.01*NHPC);
int Px8rr=Px8r+PBD*sin(0.01*NHPC);
int Px9rr=Px9r+PBD*sin(0.01*NHPC);

  
  //plot probe front
  
line(Px1ar,Py1a,Px2r,Py2);//top line - go clockwise from here//HORIZONTAL
line(Px2r,Py2,Px3r,Py3);//left upright on RTG//VERTICAL
line(Px3r,Py3,Px4r,Py4);//HORIZONTAL
line(Px4r,Py4,Px5ar,Py5);//VERTICAL
line(Px5r,Py5,Px6r,Py6);//INCLINED
line(Px6r,Py6,Px7r,Py7);//VERTICAL
line(Px7r,Py7,Px8r,Py8);//bottom line//HORIZONTAL
line(Px8r,Py8,Px9r,Py9);//VERTICAL
line(Px9r,Py9,Px1ar,Py1a);//INCLINED


//plot probe rear
line(Px1arr,180,Px2rr,180);//top line - go clockwise from here//HORIZONTAL
line(Px2rr,180,Px3rr,230);//left upright on RTG//VERTICAL
line(Px3rr,230,Px4rr,230);//HORIZONTAL
line(Px4rr,230,Px5arr,180);//VERTICAL
line(Px5rr,180,Px6rr,120);//INCLINED
line(Px6rr,90,Px7rr,120);//VERTICAL
line(Px7rr,90,Px8rr,90);//bottom line//HORIZONTAL
line(Px8rr,90,Px9rr,120);//VERTICAL
line(Px9rr,120,Px1arr,180);//INCLINED

//PLOT DIAGONALS
line(Px1ar,180,Px1arr,180);
line(Px2r,180,Px2rr,180);
line(Px3r,230,Px2rr,230);
line(Px4r,230,Px2rr,230);
line(Px5r,180,Px5rr,180);
line(Px6r,90,Px6rr,90);
line(Px7r,90,Px7rr,90);
line(Px8r,90,Px8rr,90);
line(Px9r,120,Px9rr,120);

    for(int i=0;i<256;i++){
    PORTA=(0.35*cos(0.01*NHPC)*sinTab[i])+((1-(0.35*cos(0.01*NHPC)))*128)-10;//horizontal sin wave
  PORTB=0.35*sinTab[j++]+90;//vertical sin wave
  delayMicroseconds(20);//delay between points
  }

NHPC=NHPC+4;

}

/*
//rear side
line(110,190,150,190);//top line - go clockwise from here
line(120,190,120,190);//left upright on RTG
line(120,240,140,240);
line(140,190,140,240);
line(150,190,190,130);
line(190,100,190,130);
line(70,100,190,100);//bottom line
line(70,100,70,130);
line(70,130,100,180);


//diagonal connections
line(100,180,110,190);
line(110,180,120,190);
line(110,230,120,240);
line(130,180,140,190);
line(130,230,140,240);
line(140,180,150,190);
line(180,120,190,130);
line(180,90,190,100);
line(60,90,70,100);
line(60,120,70,130);

//antenna booms
line(115,135,115,155);
line(115,135,130,120);
line(115,135,95,120);


for(int i=0;i<256;i++){
    PORTA=0.4*sinTab[i]+65;//horizontal sin wave
  PORTB=0.4*sinTab[j++]+80;//vertical sin wave
  delayMicroseconds(8);//delay between points
    }
*/
}
