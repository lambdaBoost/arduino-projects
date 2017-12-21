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
 
 
unsigned char multiparabola[]=
{0	,
0	,
1	,
2	,
3	,
4	,
5	,
6	,
8	,
10	,
12	,
14	,
17	,
20	,
23	,
26	,
29	,
32	,
36	,
40	,
44	,
48	,
53	,
58	,
63	,
68	,
73	,
78	,
84	,
90	,
96	,
102	,
109	,
116	,
123	,
130	,
137	,
144	,
152	,
160	,
168	,
176	,
185	,
194	,
203	,
212	,
221	,
230	,
240	,
250	,
0	,
0	,
1	,
2	,
3	,
4	,
5	,
6	,
8	,
10	,
12	,
14	,
17	,
20	,
23	,
26	,
29	,
32	,
36	,
40	,
44	,
48	,
53	,
58	,
63	,
68	,
73	,
78	,
84	,
90	,
96	,
102	,
109	,
116	,
123	,
130	,
137	,
144	,
152	,
160	,
168	,
176	,
185	,
194	,
203	,
212	,
221	,
230	,
240	,
250	,
0	,
0	,
1	,
2	,
3	,
4	,
5	,
6	,
8	,
10	,
12	,
14	,
17	,
20	,
23	,
26	,
29	,
32	,
36	,
40	,
44	,
48	,
53	,
58	,
63	,
68	,
73	,
78	,
84	,
90	,
96	,
102	,
109	,
116	,
123	,
130	,
137	,
144	,
152	,
160	,
168	,
176	,
185	,
194	,
203	,
212	,
221	,
230	,
240	,
250	,
0	,
0	,
1	,
2	,
3	,
4	,
5	,
6	,
8	,
10	,
12	,
14	,
17	,
20	,
23	,
26	,
29	,
32	,
36	,
40	,
44	,
48	,
53	,
58	,
63	,
68	,
73	,
78	,
84	,
90	,
96	,
102	,
109	,
116	,
123	,
130	,
137	,
144	,
152	,
160	,
168	,
176	,
185	,
194	,
203	,
212	,
221	,
230	,
240	,
250	,
0	,
0	,
1	,
2	,
3	,
4	,
5	,
6	,
8	,
10	,
12	,
14	,
17	,
20	,
23	,
26	,
29	,
32	,
36	,
40	,
44	,
48	,
53	,
58	,
63	,
68	,
73	,
78	,
84	,
90	,
96	,
102	,
109	,
116	,
123	,
130	,
137	,
144	,
152	,
160	,
168	,
176	,
185	,
194	,
203	,
212	,
221	,
230	,
240	,
250	
};


unsigned char j=64;

int SHH=200; //sea height for diver

  //ground lines for plane
  int FLH1=120; //y coord fixed horizon line 1 (back)
  int FLH2=120;//y coord fixed horizon line 2 (front)
  
  int PL1x1=128;//perspective line 1 x
  int PL1x2=128;
   int PL2x1=155;//perspective line  x
  int PL2x2=138;
   int PL3x1=100;
  int PL3x2=118;
    int PL4x1=218;
  int PL4x2=158;
    int PL5x1=48;
  int PL5x2=98;
  int PL6x1=254;
  int PL6x2=194;
    int PL7x1=1;
  int PL7x2=60;
  
  
  
  
//propellor parameters
  float prlx=128;//blade length
  float prly=128;//blade length

  //plane coordinates
  
  int p1x=40; //plane lower left wing - reference
  int p2x=p1x+68;
  int p3x=p1x+70;
  int p4x=p1x+104;
  int p5x=p1x+108;
  int p6x=p1x+176;
  int p7x=p1x+176;
  int p8x=p1x+108;
  int p9x=p1x+105;
  int p10x=p1x+125;
  int p11x=p1x+125;
  int p12x=p1x+104;
  int p13x=p1x+102;
  int p14x=p1x+90;
  int p15x=p1x+89;
  int p16x=p1x+91;
  int p17x=p1x+86;
  int p18x=p1x+88;
  int p19x=p1x+76;
  int p20x=p1x+74;
  int p21x=p1x+54;
  int p22x=p1x+54;
  int p23x=p1x+73;
  int p24x=p1x+70;
  int p25x=p1x;
  
  int p1y=150; //plane lower left wing - reference
  int p2y=p1y-2;
  int p3y=p1y-10;
  int p4y=p1y-10;
  int p5y=p1y-2;
  int p6y=p1y;
  int p7y=p1y+4;
  int p8y=p1y+4;
  int p9y=p1y+10;
  int p10y=p1y+10;
  int p11y=p1y+13;
  int p12y=p1y+13;
  int p13y=p1y+20;
  int p14y=p1y+20;
  int p15y=p1y+45;
  int p16y=p1y+45;
  int p17y=p1y+20;
  int p18y=p1y+22;
  int p19y=p1y+20;
  int p20y=p1y+13;
  int p21y=p1y+13;
  int p22y=p1y+10;
  int p23y=p1y+10;
  int p24y=p1y+4;
  int p25y=p1y+4;
void loop(){
  digitalWrite(8,HIGH);
  
  if(millis()<2000){
   //need to add  sea surface, 
//frame 1
line(50,100,120,90);//body
line(120,90,160,100);//top calf
line(160,100,200,110);//top shin
line(120,90,160,80);//bottom calf
line(160,80,200,70);//bottom shin
line(50,100,70,80);//bottom (near) upper arm
line(70,80,90,90);//bottom lower arm
line(50,100,70,100);//top (far) upper arm
line(70,100,90,85);//top lower arm
line(110,95,108,110);//cylinder bottom
line(108,110,60,115);//cylinder length
line(60,115,57,107);//cylinder top
line(57,107,60,101);//cylinder top
line(60,101,56,97);//cyliner top

  for(int i=0;i<256;i++){
    PORTA=0.1*sinTab[i]+25;//horizontal sin wave
  PORTB=0.1*sinTab[j++]+90;//vertical sin wave
  delayMicroseconds(20);//delay between points
  }
  
  //sea surface
  for(int swc=1;swc<314;swc++){
     PORTA=0.8*swc;
   PORTB=10*sin(0.1*swc)+200;
  }
  
    for(int i=0;i<256;i++){
    PORTA=0.05*sinTab[i]+25;//horizontal sin wave
  PORTB=0.05*sinTab[j++]+120;//vertical sin wave
  delayMicroseconds(20);//delay between points
  }

//frame 2
line(50,100,120,90);//body
line(120,90,160,95);//top calf
line(160,95,200,100);//top shin
line(120,90,160,85);//bottom calf
line(160,85,200,80);//bottom shin
line(50,100,70,80);//bottom (near) upper arm
line(70,80,90,90);//bottom lower arm
line(50,100,70,100);//top (far) upper arm
line(70,100,90,85);//top lower arm
line(110,95,108,110);//cylinder bottom
line(108,110,60,115);//cylinder length
line(60,115,57,107);//cylinder top
line(57,107,60,101);//cylinder top
line(60,101,56,97);//cyliner top

  for(int i=0;i<256;i++){
    PORTA=0.1*sinTab[i]+25;//horizontal sin wave
  PORTB=0.1*sinTab[j++]+90;//vertical sin wave
  delayMicroseconds(20);//delay between points
  }
  
    //sea surface
  for(int swc=1;swc<314;swc++){
     PORTA=0.8*swc;
   PORTB=10*sin(0.1*(swc+50))+200;
  }
  
      for(int i=0;i<256;i++){
    PORTA=0.05*sinTab[i]+25;//horizontal sin wave
  PORTB=0.05*sinTab[j++]+140;//vertical sin wave
  delayMicroseconds(20);//delay between points
      }
//frame 3 - mid scissor
line(50,100,120,90);//body
line(120,90,160,85);//top calf
line(160,85,200,80);//top shin
line(120,90,160,85);//bottom calf
line(160,85,200,80);//bottom shin
line(50,100,70,80);//bottom (near) upper arm
line(70,80,90,90);//bottom lower arm
line(50,100,70,100);//top (far) upper arm
line(70,100,90,85);//top lower arm
line(110,95,108,110);//cylinder bottom
line(108,110,60,115);//cylinder length
line(60,115,57,107);//cylinder top
line(57,107,60,101);//cylinder top
line(60,101,56,97);//cyliner top

  for(int i=0;i<256;i++){
    PORTA=0.1*sinTab[i]+25;//horizontal sin wave
  PORTB=0.1*sinTab[j++]+90;//vertical sin wave
  delayMicroseconds(20);//delay between points
  }
  
      //sea surface
  for(int swc=1;swc<314;swc++){
     PORTA=0.8*swc;
   PORTB=10*sin(0.1*(swc+100))+200;
  }
  
      for(int i=0;i<256;i++){
    PORTA=0.05*sinTab[i]+25;//horizontal sin wave
  PORTB=0.05*sinTab[j++]+160;//vertical sin wave
  delayMicroseconds(20);//delay between points
      }
//frame 4
line(50,100,120,90);//body
line(120,90,160,95);//top calf
line(160,95,200,100);//top shin
line(120,90,160,85);//bottom calf
line(160,85,200,80);//bottom shin
line(50,100,70,80);//bottom (near) upper arm
line(70,80,90,90);//bottom lower arm
line(50,100,70,100);//top (far) upper arm
line(70,100,90,85);//top lower arm
line(110,95,108,110);//cylinder bottom
line(108,110,60,115);//cylinder length
line(60,115,57,107);//cylinder top
line(57,107,60,101);//cylinder top
line(60,101,56,97);//cyliner top

  for(int i=0;i<256;i++){
    PORTA=0.1*sinTab[i]+25;//horizontal sin wave
  PORTB=0.1*sinTab[j++]+90;//vertical sin wave
  delayMicroseconds(20);//delay between points
  }
  
      //sea surface
  for(int swc=1;swc<314;swc++){
     PORTA=0.8*swc;
   PORTB=10*sin(0.1*(swc+150))+200;
  }
  
      for(int i=0;i<256;i++){
    PORTA=0.05*sinTab[i]+25;//horizontal sin wave
  PORTB=0.05*sinTab[j++]+180;//vertical sin wave
  delayMicroseconds(20);//delay between points
      }
  
//frame 5
line(50,100,120,90);//body
line(120,90,160,100);//top calf
line(160,100,200,110);//top shin
line(120,90,160,80);//bottom calf
line(160,80,200,70);//bottom shin
line(50,100,70,80);//bottom (near) upper arm
line(70,80,90,90);//bottom lower arm
line(50,100,70,100);//top (far) upper arm
line(70,100,90,85);//top lower arm
line(110,95,108,110);//cylinder bottom
line(108,110,60,115);//cylinder length
line(60,115,57,107);//cylinder top
line(57,107,60,101);//cylinder top
line(60,101,56,97);//cyliner top

  for(int i=0;i<256;i++){
    PORTA=0.1*sinTab[i]+25;//horizontal sin wave
  PORTB=0.1*sinTab[j++]+90;//vertical sin wave
  delayMicroseconds(20);//delay between points
  }
  
      //sea surface
  for(int swc=1;swc<314;swc++){
     PORTA=0.8*swc;
   PORTB=10*sin(0.1*(swc+200))+200;
  }
      for(int i=0;i<256;i++){
    PORTA=0.05*sinTab[i]+25;//horizontal sin wave
  PORTB=0.05*sinTab[j++]+200;//vertical sin wave
  delayMicroseconds(20);//delay between points
  }
  }
//transition fom waves to flat

if(millis()>2000 && millis()<3000){
       for(int WH=100;WH>0;WH){
    for(int swc=1;swc<314;swc++){
     PORTA=0.8*swc;
   PORTB=0.1*WH*sin(0.1*swc)+SHH;
   
    }
   WH=WH-2;//DECREASE WAVE HEIGHT
   SHH=SHH-1;//MOVE HORIZON DOWN
  }

}

//transition up to plane scene
if(millis()>3000 && millis()<8500){

  //horizon lines
  
 for(int HCC=1;HCC=118;HCC--){//horizon line counter to move horizon lines down 
  line(1,FLH1,254,FLH1);
  line(1,FLH2,254,FLH2);
  
    line(PL1x2,FLH1,PL1x1,FLH2);
   line(PL2x2,FLH1,PL2x1,FLH2);
   line(PL3x2,FLH1,PL3x1,FLH2);
    line(PL4x2,FLH1,PL4x1,FLH2);
     line(PL5x2,FLH1,PL5x1,FLH2);
      line(PL6x2,FLH1,PL6x1,FLH2);
       line(PL7x2,FLH1,PL7x1,FLH2);
       FLH2--;//moved front of image down with each loop
       if(millis()>8500){
         break;
       }
}
}

if(millis()>8500){
  
   
  for(int Hl=250;Hl>0;Hl--){//Hl is counter for horizon line
    
  //draw fixed horizon lines
  line(1,1,254,1);
  line(1,120,254,120);

  //draw moving horizon lines
  line(1,0.48*(250-multiparabola[Hl]),254,0.48*(250-multiparabola[Hl]));//250 - y inverts parabola. 0.5 defines horizon y coordinate  
    line(254,0.48*(250-multiparabola[Hl-12]),1,0.48*(250-multiparabola[Hl-12]));//need to multiply counter by 1.25 (reciprocal of 1-cycle stage) so it finishes at same time as loop finishes
  line(1,0.48*(250-multiparabola[Hl-25]),254,0.48*(250-multiparabola[Hl-25]));
  line(254,0.48*(250-multiparabola[Hl-37]),1,0.48*(250-multiparabola[Hl-37]));
  //line(1,0.48*(250-multiparabola[Hl-43]),254,0.48*(250-multiparabola[Hl-43]));//seems to work better with this one taken out
  
  //draw perspective lines
  line(128,1,128,120);
  line(138,120,155,1);
  line(100,1,118,120);
  line(158,120,218,1);
  line(48,1,98,120);
  line(194,120,254,30);
  line(1,30,60,120);
  
  
//draw plane
line(p1x,p1y,p2x,p2y);
line(p2x,p2y,p3x,p3y);
line(p3x,p3y,p4x,p4y);
line(p4x,p4y,p5x,p5y);
line(p5x,p5y,p6x,p6y);
line(p6x,p6y,p7x,p7y);
line(p7x,p7y,p8x,p8y);
line(p8x,p8y,p9x,p9y);
line(p9x,p9y,p10x,p10y);
line(p10x,p10y,p11x,p11y);
line(p11x,p11y,p12x,p12y);
line(p12x,p12y,p13x,p13y);
line(p13x,p13y,p14x,p14y);
line(p14x,p14y,p15x,p15y);
line(p15x,p15y,p16x,p16y);
line(p16x,p16y,p17x,p17y);
line(p18x,p18y,p19x,p19y);
line(p19x,p19y,p20x,p20y);
line(p20x,p20y,p21x,p21y);
line(p21x,p21y,p22x,p22y);
line(p22x,p22y,p23x,p23y);
line(p23x,p23y,p24x,p24y);
line(p24x,p24y,p25x,p25y);
line(p25x,p25y,p1x,p1y);


//draw prop
  //blade 1
  int PRX1=0.27*prlx*(1+sin(0.4*Hl))+95;
  int PRY1=0.27*prly*(1+cos(0.4*Hl))+120;
  int PRX2=0.27*prlx*(1+sin(0.4*Hl+3.14))+95;
  int PRY2=0.27*prly*(1+cos(0.4*Hl+3.14))+120;
  
  //blade 2
  int PRX3=0.27*prlx*(1+sin((0.4*Hl)+1.56))+95;//1.56 is the phase difference (ie pi/2)
  int PRY3=0.27*prly*(1+cos((0.4*Hl)+1.56))+120;
  int PRX4=0.27*prlx*(1+sin((0.4*Hl+1.56)+3.14))+95;
  int PRY4=0.27*prly*(1+cos((0.4*Hl+1.56)+3.14))+120;
 
 
line(PRX1,PRY1,PRX2,PRY2);//blade 1
line(PRX3,PRY3,PRX4,PRY4);//blade 2


  }
  
}
}
      
