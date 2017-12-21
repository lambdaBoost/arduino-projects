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

int linex1=50;
int linex2=150;
int linex3=150;
float linex3a=150;//any vertex which dissapears offscreen needs a corresponding 'a vertex'

int liney1=50;
int liney2=50;
int liney3=150;

void loop(){//loop for if everything on screen
  
  for(int lc=1;lc<250;lc++){
  
    while (liney3<251){
  line(linex1,liney1,linex2,liney2);
   line(linex2,liney2,linex3,liney3);
    line(linex3,liney3,linex1,liney1);
   
  liney1++;
  liney2++;
  liney3++;
  
 
    }
    
   if (liney3>250){//loop for lines going offscreen
      line(linex1,liney1,linex2,liney2);
   line(linex2,liney2,linex3,250);
    line(linex3a,250,linex1,liney1);
    
     liney1++;
  liney2++;
  liney3=251;
  
   linex3a=linex3a-1;//the -1 must be changed to alter the 'rate of disapearance'
   }
    
}
}
