void setup() {
  DDRA=255;
  DDRB=255;
  
}


void
line_diagonal(
        int x0,
        int y0,
        int x1,
        int y1
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
        }
}


void
line_vert(
        int x0,
        int y0,
        int w
)
{       
        PORTA = x0;
        PORTB = y0;
        
        for (int i = 0 ; i < w ; i++)
                PORTB++;
}

void    
line_horiz(
        int x0,
        int y0,
        int h
)       
{       
        PORTA = x0;
        PORTB = y0;
        
        for (int i = 0 ; i < h ; i++)
                PORTA++;
}

void loop(){
  
  line_horiz(0,200,255);
  line_diagonal(0,0,255,255);

}
