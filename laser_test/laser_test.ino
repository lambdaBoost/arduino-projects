void setup() {
  pinMode(8,OUTPUT);
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
          digitalWrite(8,HIGH);
                PORTB = x0;
                PORTA = y0;

                if (x0 == x1 && y0 == y1)
                        break;
                        digitalWrite(8,LOW);

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




void loop() {

//line(50,50,150,150);
//line(150,50,50,150);
digitalWrite(8,HIGH);
delayMicroseconds(40);
digitalWrite(8,LOW);
delayMicroseconds(40);
}
