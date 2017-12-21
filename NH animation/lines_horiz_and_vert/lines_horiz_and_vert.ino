void setup(){
  DDRA =255;
  DDRB=255;
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
 line_vert(64, 64, 128);
    line_vert(196, 64, 128);
    line_horiz(64, 64, 128);
    line_horiz(64, 196, 128);
}
