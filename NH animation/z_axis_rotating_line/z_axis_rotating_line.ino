void setup() {
    DDRA=255;
    DDRB=255;
}

uint8_t sinTab[]=
{ 
128,131,134,137,140,143,146,149,152,155,158,162,165,167,170,173,176,179,182,185,188,190,193,196,198,201,203,206,208,211,213,215,218,220,222,224,226,228,230,232,234,235,237,238,240,241,243,244,
245,246,248,249,250,250,251,252,253,253,254,254,254,255,255,255,255,255,255,255,254,254,254,253,253,252,251,250,250,249,248,246,245,244,243,241,240,238,237,235,234,232,230,228,226,224,222,220,
218,215,213,211,208,206,203,201,198,196,193,190,188,185,182,179,176,173,170,167,165,162,158,155,152,149,146,143,140,137,134,131,128,124,121,118,115,112,109,106,103,100,97,93,90,88,85,82,
79,76,73,70,67,65,62,59,57,54,52,49,47,44,42,40,37,35,33,31,29,27,25,23,21,20,18,17,15,14,12,11,10,9,7,6,5,5,4,3,2,2,1,1,1,0,0,0,
0,0,0,0,1,1,1,2,2,3,4,5,5,6,7,9,10,11,12,14,15,17,18,20,21,23,25,27,29,31,33,35,37,40,42,44,47,49,52,54,57,59,62,65,67,70,73,76,
79,82,85,88,90,93,97,100,103,106,109,112,115,118,121,124,128
 };
 
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
                delayMicroseconds(20);//rotation speed (may need to do this some other way)
        }
}

  uint8_t x[]={50,100,100,50};
  uint8_t y[]={50,50,100,100};
 
   uint8_t X[]={70,120,120,70};
  uint8_t Y[]={70,70,120,120};
 
void loop() {
  

  for(int i=0;i<256;i++){

    line((0.0038*sinTab[i]-0.0038*sinTab[i+128])*x[0])+((x[0])/2),y[0],0.0038*sinTab[i]*x[1]+((x[0])/2),y[1]);//horizontal - need to multiply by sin and add centrepoint for x coordinates
    line((0.0038*sinTab[i]-0.0038*sinTab[i+128])*x[1]+(x[0])/2),y[1],0.0038*sinTab[i]*x[2]+(x[0]/2),y[2]);//vertical - need to multiply by sin and add  half of startpoint for x coordinates
    line((0.0038*sinTab[i]-0.0038*sinTab[i+128])*x[2])+((x[0])/2),y[2],0.0038*sinTab[i]*x[3]+((x[0])/2),y[3]);//horizontal
    line((0.0038*sinTab[i]-0.0038*sinTab[i+128])*x[3]+(x[0])/2),y[3],0.0038*sinTab[i]*x[0]+(x[0]/2),y[0]);
    //delayMicroseconds(8);//affecs speed but high values give a dot
 
 line((0.0038*sinTab[i]-0.0038*sinTab[i+128])*X[0])+((X[0])/2),Y[0],0.0038*sinTab[i]*X[1]+((X[0])/2),Y[1]);//horizontal - need to multiply by sin and add centrepoint for x coordinates
    line((0.0038*sinTab[i]-0.0038*sinTab[i+128])*X[1]+(X[0])/2),Y[1],0.0038*sinTab[i]*X[2]+(X[0]/2),Y[2]);//vertical - need to multiply by sin and add  half of startpoint for x coordinates
    line((0.0038*sinTab[i]-0.0038*sinTab[i+128])*X[2])+((X[0])/2),Y[2],0.0038*sinTab[i]*X[3]+((X[0])/2),Y[3]);//horizontal
    line((0.0038*sinTab[i]-0.0038*sinTab[i+128])*X[3]+(X[0])/2),Y[3],0.0038*sinTab[i]*X[0]+(X[0]/2),Y[0]);
    delayMicroseconds(8);

  }
    
  
}
  
  /*uint8_t x[]=
  {50,100,100,50};
  
  uint8_t y[]=
  {50,50,100,100};
  
    uint8_t X[]=
  {70,120,120,70};
  
  uint8_t Y[]=
  {70,70,120,120};
  
  uint8_t XA[]={0,0,0,0};
  
 for(unsigned char i=0;i<255;i++){
  XA[i]=X[i]*0.0039*sinTab[i]+95; 
 //delayMicroseconds(8);
  //front square
  line(x[0],y[0],x[1],y[1]);//H
  line(x[1],y[1],x[2],y[2]);//V
  line(x[2],y[2],x[3],y[3]);//H
  line(x[3],y[3],x[0],y[0]);//V
  
  //back square
   line(XA[0],Y[0],XA[1],Y[1]);//H
  line(XA[1],Y[1],XA[2],Y[2]);//V
  line(XA[2],Y[2],XA[3],Y[3]);//H
  line(XA[3],Y[3],XA[0],Y[0]);//V
 }

}*/
