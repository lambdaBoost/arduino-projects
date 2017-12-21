void setup(){
  DDRA =255;
  DDRB=255;
  Serial.begin(9600);
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


 int Cx1=0;//X counter
 int Cx2=0;//X2 counter


void wrappedLine(int X1, int Y1, int X2, int Y2) {
 
 int DX=X2-X1; 
 int DY=Y2-Y1;
float  M=DY/DX; //gradient
 

  
  if(X1%256==0){//counts number of times X1 leaves frame from side
    Cx1++;
  }
  if(X2%256==0){//as above for X2
    Cx2++;
  }

  if(Cx2>Cx1){//if line leaves right frame
    line(X1,Y1,255,Y1+(((Cx1*256)-X1)*M));
    line(1,Y1+(((Cx1*256)-X1)*M),X2,Y2);
  }

  if(Cx1==Cx2){//if line in frame
    line(X1,Y1,X2,Y2);
  }

  if(Cx1>Cx2){//if line leaves left frame
    
    line(1,Y1+(((Cx1*256)-X1)*M),X2,Y2);
    line(X1,Y1,255,Y1+(((Cx1*256)-X1)*M)); 
    
  }
}


int Sx=120;
int Sy=120;

void loop(){


wrappedLine(Sx,Sy,Sx+50,Sy+50);
Sx=Sx+1;

}

