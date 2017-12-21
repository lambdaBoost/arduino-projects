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


unsigned char sinTab[]=
{ 
 127,130,133,136,139,143,146,149,152,155,158,161,164,167,170,173,176,178,181,184,187,190,192,195,198,200,203,205,208,210,212,215,217,219,221,223,225,227,229,231,233,234,236,238,239,240,
  242,243,244,245,247,248,249,249,250,251,252,252,253,253,253,254,254,254,254,254,254,254,253,253,253,252,252,251,250,249,249,248,247,245,244,243,242,240,239,238,236,234,233,231,229,227,225,223,
  221,219,217,215,212,210,208,205,203,200,198,195,192,190,187,184,181,178,176,173,170,167,164,161,158,155,152,149,146,143,139,136,133,130,127,124,121,118,115,111,108,105,102,99,96,93,90,87,84,81,78,
  76,73,70,67,64,62,59,56,54,51,49,46,44,42,39,37,35,33,31,29,27,25,23,21,20,18,16,15,14,12,11,10,9,7,6,5,5,4,3,2,2,1,1,1,0,0,0,0,0,0,0,1,1,1,2,2,3,4,5,5,6,7,9,10,11,12,14,15,16,18,20,21,23,25,27,29,31,
  33,35,37,39,42,44,46,49,51,54,56,59,62,64,67,70,73,76,78,81,84,87,90,93,96,99,102,105,108,111,115,118,121,124
 };

unsigned char j=64;

void loop(){
  
  line(5,80,5,90);//pedestal right upright
  line(5,90,250,90);//pedestal horizontal
  line(250,90,250,80);//pedestal left upright
  
  //left minaret
  line(245,90,245,200);//left minaret left upright
  line(245,200,240,205);//minaret indent
  line(240,205,248,210);
  line(248,210,238,220);
  line(238,220,238,235);//minaret pinnacle
  line(238,235,238,220);//pinnacle retrace
  line(238,220,230,210);
  line(230,210,235,205);
  line(235,205,235,200);//minaret indent end
  line(235,200,235,90);//left minaret right upright
  
  line(220,90,220,150);//left minaret left upright
  line(220,150,215,155);//minaret indent
  line(215,155,223,160);
  line(223,160,213,170);
  line(213,170,213,180);//minaret pinnacle
  line(213,180,213,170);//pinnacle retrace
  line(213,170,210,160);
  line(210,160,220,150);//would expect 155 as y2 but looks better with 150
  line(215,150,215,150);//minaret indent end
  line(215,150,215,90);//left minaret right upright
  
  //middle bit
  line(185,90,185,160);// left upright
  line(185,160,155,160);// roof left
  line(155,160,155,170);//left roof upright
  
  line(155,170,165,180);//dome (left side next few lines)
  line(165,180,170,190);//5
  line(170,190,170,195);//4
  line(170,195,160,205);//3
  line(160,205,140,215);//2
  line(140,215,130,230);//1
  line(130,230,123,235);//pinnacle
  line(123,235,115,215);//1
  line(115,215,90,205);//2
  line(90,205,80,195);//3
  line(80,195,80,190);//4
  line(80,190,85,180);//5
  line(85,180,95,170);//end of dome

  line(95,170,95,160);//right roof upright
  line(95,160,65,160);//roof right
  line(65,160,65,90);//right upright
  
  //right centre minaret
    line(35,90,35,150);//left minaret left upright
  line(35,150,30,155);//minaret indent
  line(30,155,38,160);
  line(38,160,28,170);
  line(28,170,28,180);//minaret pinnacle
  line(28,180,28,170);//pinnacle retrace
  line(28,170,25,160);
  line(25,160,35,150);//would expect 155 as y2 but looks better with 150
  line(35,150,30,150);//minaret indent end
  line(30,150,30,90);//left minaret right upright


  //right minaret
  line(12,90,12,200);//left minaret left upright
  line(12,200,10,205);//minaret indent
  line(10,205,18,210);
  line(18,210,8,220);
  line(8,220,8,235);//minaret pinnacle
  line(8,235,8,220);//pinnacle retrace
  line(8,220,0,210);
  line(0,210,5,205);
  line(5,205,5,200);//minaret indent end
  line(5,200,5,90);//left minaret right upright
  
  //alex
           for(int i=0;i<256;i++){
    PORTA=0.05*sinTab[i]+82;//horizontal sin wave
  PORTB=0.05*sinTab[j++]+77;//vertical sin wave
  delayMicroseconds(8);//delay between points
    }
  line(88,60,100,20);//right leg
  line(88,60,80,20);//left leg
  line(90,80,90,50);//body
  line(90,80,71,45);//right arm
  line(90,80,110,50);//left arm
  
  //Hannah
  line(110,50,125,74);//right arm
  line(125,74,145,50);//left arm
  line(118,74,118,60);//body
  line(118,65,140,20);//left leg
  line(118,65,117,20);//right leg
  line(137,35,115,35);//skirt //COULD DO WITH GETTING RID OF LINE TO THIS
         for(int i=0;i<256;i++){
    PORTA=0.05*sinTab[i]+112;//horizontal sin wave
  PORTB=0.05*sinTab[j++]+74;//vertical sin wave
  delayMicroseconds(8);//delay between points
    }
    
    
  

}
