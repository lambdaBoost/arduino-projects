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


float A=0; //ship rotation angle
int Ax[]={random(0,100),random(150,250),
          random(0,100), random(150,250),
          random(150,250), random(150,250)}; //x coordinates of asteroids
int Ay[]={random(0,100),random(0,100),
          random(150,250), random(150,250),
          random(150,250), random(150,250)}; //y coordinates of asteroids

//GENERATE 3 RANDOM ASTEROIDS
int Ac1x=Ax[1]; //centre x of asteroid 1
int Ac1y=Ay[1]; //centre y of asteroid 1

int Ac2x=Ax[2]; //centre x of asteroid 2
int Ac2y=Ay[2]; //centre y of asteroid 2

int Ac3x=Ax[3]; //centre x of asteroid 3
int Ac3y=Ay[3]; //centre y of asteroid 3


float A1xv=random(-3,3); //asteroid 1 x speed
float A1yv=random(-3,3); //asteroid 1 y speed

float A2xv=random(-2,2); //asteroid 2 x speed
float A2yv=random(-3,3); //asteroid 2 y speed

float A3xv=random(-3,3); //asteroid 3 x speed
float A3yv=random(-3,3); //asteroid 3 y speed


void loop() {
//ship coordinates
int Scx=128; //shipcentre x
int Scy=128; //ship centre y

int Sfx=Scx+(8*sin(A)); //ship front x
int Sfy=Scy+(8*cos(A)); //ship front y

int Sbx=Scx+(4*sin(A+3.14)); //ship back x
int Sby=Scy+(4*cos(A+3.14)); //ship back y

int Srx=Scx+(8*sin(A+2.5)); //ship right x
int Sry=Scy+(8*cos(A+2.5)); //ship right y

int Slx=Scx+(8*sin(A+3.8)); //ship left x
int Sly=Scy+(8*cos(A+3.8)); //ship left y

//plot ship
line(Sfx,Sfy,Srx,Sry); //ship front right line
line(Srx,Sry,Sbx,Sby); //ship rear right line
line(Sbx,Sby,Slx,Sly); //ship rear left line
line(Slx,Sly,Sfx,Sfy); //ship front left line

//ADD FUNCTION FOR IF BUTTON PRESSED, CHANGE A



//plot asteroid 1
line(Ac1x+20,Ac1y+5,Ac1x+20,Ac1y-10);
line(Ac1x+20,Ac1y-10,Ac1x+5,Ac1y-10);
line(Ac1x+5,Ac1y-10,Ac1x+5,Ac1y-5);
line(Ac1x+5,Ac1y-5,Ac1x-10,Ac1y-12);
line(Ac1x-10,Ac1y-12,Ac1x-20,Ac1y);
line(Ac1x-20,Ac1y,Ac1x-5,Ac1y+5);
line(Ac1x-5,Ac1y+5,Ac1x-15,Ac1y+10);
line(Ac1x-15,Ac1y+10, Ac1x-5,Ac1y+20);
line( Ac1x-5,Ac1y+20,Ac1x+10,Ac1y+20);
line(Ac1x+10,Ac1y+20,Ac1x+20,Ac1y+5);

Ac1x=Ac1x+A1xv;//move in x direction
Ac1y=Ac1y+A1yv;//move in y direction

//plot asteroid 2
line(Ac2x+20,Ac2y+5,Ac2x+20,Ac2y-10);
line(Ac2x+20,Ac2y-10,Ac2x+5,Ac2y-10);
line(Ac2x+5,Ac2y-10,Ac2x+5,Ac2y-5);
line(Ac2x+5,Ac2y-5,Ac2x-10,Ac2y-12);
line(Ac2x-10,Ac2y-12,Ac2x-20,Ac2y);
line(Ac2x-20,Ac2y,Ac2x-5,Ac2y+5);
line(Ac2x-5,Ac2y+5,Ac2x-15,Ac2y+10);
line(Ac2x-15,Ac2y+10,Ac2x-5,Ac2y+20);
line( Ac2x-5,Ac2y+20,Ac2x+10,Ac2y+20);
line(Ac2x+10,Ac2y+20,Ac2x+20,Ac2y+5);

Ac2x=Ac2x+A2xv;//move in x direction
Ac2y=Ac2y+A2yv;//move in y direction


//plot asteroid 3
line(Ac3x+20,Ac3y+5,Ac3x+20,Ac3y-10);
line(Ac3x+20,Ac3y-10,Ac3x+5,Ac3y-10);
line(Ac3x+5,Ac3y-10,Ac3x+5,Ac3y-5);
line(Ac3x+5,Ac3y-5,Ac3x-10,Ac3y-12);
line(Ac3x-10,Ac3y-12,Ac3x-20,Ac3y);
line(Ac3x-20,Ac3y,Ac3x-5,Ac3y+5);
line(Ac3x-5,Ac3y+5,Ac3x-15,Ac3y+10);
line(Ac3x-15,Ac3y+10,Ac3x-5,Ac3y+20);
line( Ac3x-5,Ac3y+20,Ac3x+10,Ac3y+20);
line(Ac3x+10,Ac3y+20,Ac3x+20,Ac3y+5);

Ac3x=Ac3x+A3xv;//move in x direction
Ac3y=Ac3y+A3yv;//move in y direction

}
