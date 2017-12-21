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

//declare variables

int Lc=128; //centre of left paddle
int Lt=Lc+12; //top of left paddle
int Lb=Lc-12; //bottom of left paddle

int Rc=128; //centre of right paddle
int Rt=Rc+12; //top of right paddle
int Rb=Rc-12; //bottom of right paddle


void loop(){

//plot box and paddles
//left side
line(0,0,0,Lb);
line(5,Lb,5,Lt);
line(0,Lt,0,255);

//top
line(0,255,255,255);

//right side
line(255,255,255,Rt);
line(252,Rt,252,Rb);
line(255,Rb,255,0);

//bottom
line(255,0,0,0);

}
