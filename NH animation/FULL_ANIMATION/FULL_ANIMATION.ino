void setup() {
  DDRA=255;
  DDRB=255;
  pinMode(9,OUTPUT);
  
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


void
fastline(
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
                 delayMicroseconds(20);
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
 
 unsigned char cosTab[]=
 {128,131,134,137,140,143,146,149,152,155,158,162,165,167,170,173,176,179,182,185,188,190,193,196,198,201,203,206,208,211,213,215,
218,220,222,224,226,228,230,232,234,235,237,238,240,241,243,244,245,246,248,249,250,250,251,252,253,253,254,254,254,255,255,255,
255,255,255,255,254,254,254,253,253,252,251,250,250,249,248,246,245,244,243,241,240,238,237,235,234,232,230,228,226,224,222,220,
218,215,213,211,208,206,203,201,198,196,193,190,188,185,182,179,176,173,170,167,165,162,158,155,152,149,146,143,140,137,134,131,
128,124,121,118,115,112,109,106,103,100,97,93,90,88,85,82,79,76,73,70,67,65,62,59,57,54,52,49,47,44,42,40,
37,35,33,31,29,27,25,23,21,20,18,17,15,14,12,11,10,9,7,6,5,5,4,3,2,2,1,1,1,0,0,0,
0,0,0,0,1,1,1,2,2,3,4,5,5,6,7,9,10,11,12,14,15,17,18,20,21,23,25,27,29,31,33,35,
37,40,42,44,47,49,52,54,57,59,62,65,67,70,73,76,79,82,85,88,90,93,97,100,103,106,109,112,115,118,121,124,
128,131,134,137,140,143,146,149,152,155,158,162,165,167,170,173,176,179,182,185,188,190,193,196,198,201,203,206,208,211,213,215,
218,220,222,224,226,228,230,232,234,235,237,238,240,241,243,244,245,246,248,249,250,250,251,252,253,253,254,254,254,255,255,255,
255,255,255,255,254,254,254,253,253,252,251,250,250,249,248,246,245,244,243,241,240,238,237,235,234,232,230,228,226,224,222,220,
218,215,213,211,208,206,203,201,198,196,193,190,188,185,182,179,176,173,170,167,165,162,158,155,152,149,146,143,140,137,134,131,
128,124,121,118,115,112,109,106,103,100,97,93,90,88,85,82,79,76,73,70,67,65,62,59,57,54,52,49,47,44,42,40,
37,35,33,31,29,27,25,23,21,20,18,17,15,14,12,11,10,9,7,6,5,5,4,3,2,2,1,1,1,0,0,0,
0,0,0,0,1,1,1,2,2,3,4,5,5,6,7,9,10,11,12,14,15,17,18,20,21,23,25,27,29,31,33,35,
37,40,42,44,47,49,52,54,57,59,62,65,67,70,73,76,79,82,85,88,90,93,97,100,103,106,109,112,115,118,121,124,
 };
 
 
 
unsigned char full_parabola[]=
{5,9,13,17,21,24,28,32,36,39,43,46,50,54,57,61,64,67,71,74,78,81,84,87,91,94,97,100,103,106,109,112,115,118,121,124,127,129,132,135,138,
140,143,146,148,151,153,156,158,161,163,165,168,170,172,175,177,179,181,183,185,187,190,192,193,195,197,199,201,203,205,206,208,210,211,213,215,216,218,219,221,
222,224,225,226,228,229,230,231,233,234,235,236,237,238,239,240,241,242,243,244,245,245,246,247,247,248,249,249,250,251,251,252,252,252,253,253,253,254,254,254,
254,255,255,255,255,255,255,255,255,255,255,255,254,254,254,254,253,253,253,252,252,252,251,251,250,249,249,248,247,247,246,245,245,244,243,242,241,240,239,238,
237,236,235,234,233,231,230,229,228,226,225,224,222,221,219,218,216,215,213,211,210,208,206,205,203,201,199,197,195,193,192,190,187,185,183,181,179,177,175,172,
170,168,165,163,161,158,156,153,151,148,146,143,140,138,135,132,129,127,124,121,118,115,112,109,106,103,100,97,94,91,87,84,81,78,74,71,67,64,61,57,54,
50,46,43,39,36,32,28,24,21,17,13,9,5};


unsigned char parabola[] =
{
0	,
0	,
0	,
0	,
0	,
0	,
0	,
0	,
0	,
0	,
1	,
1	,
1	,
1	,
1	,
1	,
1	,
1	,
1	,
2	,
2	,
2	,
2	,
2	,
3	,
3	,
3	,
3	,
3	,
4	,
4	,
4	,
4	,
5	,
5	,
5	,
5	,
6	,
6	,
6	,
7	,
7	,
7	,
8	,
8	,
8	,
9	,
9	,
10	,
10	,
10	,
11	,
11	,
12	,
12	,
12	,
13	,
13	,
14	,
14	,
15	,
15	,
16	,
16	,
17	,
17	,
18	,
18	,
19	,
19	,
20	,
20	,
21	,
22	,
22	,
23	,
23	,
24	,
25	,
25	,
26	,
26	,
27	,
28	,
28	,
29	,
30	,
30	,
31	,
32	,
33	,
33	,
34	,
35	,
35	,
36	,
37	,
38	,
39	,
39	,
40	,
41	,
42	,
42	,
43	,
44	,
45	,
46	,
47	,
48	,
48	,
49	,
50	,
51	,
52	,
53	,
54	,
55	,
56	,
57	,
57	,
58	,
59	,
60	,
61	,
62	,
63	,
64	,
65	,
66	,
67	,
68	,
69	,
70	,
71	,
73	,
74	,
75	,
76	,
77	,
78	,
79	,
80	,
81	,
82	,
84	,
85	,
86	,
87	,
88	,
89	,
91	,
92	,
93	,
94	,
95	,
97	,
98	,
99	,
100	,
102	,
103	,
104	,
105	,
107	,
108	,
109	,
111	,
112	,
113	,
115	,
116	,
117	,
119	,
120	,
121	,
123	,
124	,
125	,
127	,
128	,
130	,
131	,
133	,
134	,
135	,
137	,
138	,
140	,
141	,
143	,
144	,
146	,
147	,
149	,
150	,
152	,
153	,
155	,
157	,
158	,
160	,
161	,
163	,
165	,
166	,
168	,
169	,
171	,
173	,
174	,
176	,
178	,
179	,
181	,
183	,
184	,
186	,
188	,
189	,
191	,
193	,
195	,
196	,
198	,
200	,
202	,
203	,
205	,
207	,
209	,
211	,
212	,
214	,
216	,
218	,
220	,
222	,
223	,
225	,
227	,
229	,
231	,
233	,
235	,
237	,
239	,
241	,
243	,
245	,
246	,
248	,
250	
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


float AH=1;//Circle width(0 to 1)
float AV=1;//circle height
unsigned char j=64;
unsigned char cj=64;
float EPY=0;//position of earth during flyaway phase
float EPX=0;

  //tetrahedron starting points
  float CTx =128;//centre of base of tetrahedon 
  float t1x=80;
  float t2x=80;
  float t3x=80;
  float t4x=CTx;
  
  float CTy=100; //centre of base
  float t1y=30;
  float t2y=30;
  float t3y=30;
  float t4y=200;
  
  
  
  
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
  
  //windmill parameters
    float Wmx0 = 128;
  float Wmx1=128;
  float Wmy0 =80;
  float Wmy1=240;
  
  float Blx=128;//blade length
  float Bly=128;//blade length




//oil platform x coordinates
int ORX1=60;//lower right leg - datum
int ORX2=ORX1+10;
int ORX3=ORX1-10;
int ORX4=ORX1-10;
int ORX5=ORX1+40;
int ORX6=ORX1+40;
int ORX7=ORX1+100;
int ORX8=ORX1+100;
int ORX9=ORX1+105;
int ORX10=ORX1+110;
int ORX11=ORX1+112;
int ORX12=ORX1+122;
int ORX13=ORX1+132;
int ORX14=ORX1+135;
int ORX15=ORX1+145;
int ORX16=ORX1+145;
int ORX17=ORX1+160;
int ORX18=ORX1+180;
int ORX19=ORX1+194;
int ORX20=ORX1+170;
int ORX21=ORX1+145;
int ORX22=ORX1+145;
int ORX23=ORX1+125;
int ORX24=ORX1+135;

//oil platform y coordinates
int ORY1=20;//datum
int ORY2=ORY1+40;
int ORY3=ORY1+40;
int ORY4=ORY1+180;
int ORY5=ORY1+180;
int ORY6=ORY1+100;
int ORY7=ORY1+100;
int ORY8=ORY1+120;
int ORY9=ORY1+150;
int ORY10=ORY1+180;
int ORY11=ORY1+210;
int ORY12=ORY1+180;
int ORY13=ORY1+150;
int ORY14=ORY1+130;
int ORY15=ORY1+130;
int ORY16=ORY1+110;
int ORY17=ORY1+120;
int ORY18=ORY1+130;
int ORY19=ORY1+127;
int ORY20=ORY1+110;
int ORY21=ORY1+90;
int ORY22=ORY1+40;
int ORY23=ORY1+40;
int ORY24=ORY1;

//helicopter x coordinates
float HEXX=50;//DATUM
//VARIABLES
float hexx1=-25;
float hexx2=-5;
float hexx3=+15;
float hexx4=+30;
float hexx5=+10;
float hexx6=-15;
float hexx6a=-20;
float hexx6b=-50;
float hexx6c=26;
float hexx7=-35;
float hexx8=-45;

//helicopter y coordinates
float HEXY=180;//DATUM
float hexyy1=-30;
float hexyy2=-40;
float hexyy3=-35;
float hexyy4=-5;
float hexyy5=25;
float hexyy6=35;
float hexyy6a=45;
float hexyy6b=40;
float hexyy6c=55;
float hexyy7=20;
float hexyy8=0;


  //propose left figure xcoordinate variables (start positions)
int pclx0=0;//datum
int pclx1=30;
int pclx2=60;
int pclx3=30;
int pclx3a=45;
int pclx3b=15;
int pclx4=60;
int pclx5=0;
int pclx6=30;
int phpx=30;//head x position

//propose left figure y coordinate variables
int pcly0=0;//datum
int pcly1=70;
int pcly2=0;
int pcly3=120;
int pcly3a=100;
int pcly3b=100;
int pcly4=80;
int pcly5=80;
int pcly6=140;
int phpy=130;//head y position
  
unsigned char R=64;//independent phase counter
int PBD=40; //probe depth

//probe FRONT x coordinate variables
int Pxa=-20;
int Pxb=10;
int Pxc=10;
int Pxd=-10;
int Pxe=10;
int Pxea=-10;
int Pxf=60;
int Pxg=60;
int Pxh=-60;
int Pxi=-60;

//probe FRONT x coordinates
int Px1=120;//centrepoint
int Px1a=Px1+Pxa;//starting point on probe
int Px2=Px1+Pxb;
int Px3=Px1+Pxc;
int Px4=Px1+Pxd;
int Px5=Px1+Pxe;
int Px5a=Px1+Pxea;
int Px6=Px1+Pxf;
int Px7=Px1+Pxg;
int Px8=Px1+Pxh;
int Px9=Px1+Pxi;

void loop(){
  
  
  digitalWrite(9,HIGH);
  
  
  
  if(millis()<10000){
    PORTA=128;
    PORTB=128;
  }
  
  if(millis()>10000 && millis()<15000){
  for(int intro2=64;intro2>1;intro2--){
  for(int intro=1;intro<255;intro++){
    PORTB=128;
    PORTA=intro;
    delayMicroseconds(16*intro2);
  }
  }
  }
  
  if(millis()>15000 && millis()<25000){
    
    for(int i=0;i<256;i++){//stationary circle
  PORTA=sinTab[i];//horizontal sin wave
  PORTB=AH*sinTab[j++];//vertical sin wave
  delayMicroseconds(8);
}
  }
  
  
  
  
  
  //FLYBY 1
for(int k=0;k<128;k++){//counter to define amplitude
  float A=0.0039*cosTab[k]-0.0039*cosTab[k+128];//defines amplitude (varies sinusoidally with a 1/2 sin wave per cycle)
  if(millis()<36000 && millis()>25000){
  for(int i=0;i<256;i++){
  PORTA=(A*sinTab[i])+((1-A)*128);//horizontal sin wave
  PORTB=AH*sinTab[j++];//vertical sin wave
  delayMicroseconds(8);//delay between points
  

  
  }
   line(15,200,235,200);
line(255,127,0,127);
line(15,54,235,54);
 
for(int i=0;i<256;i++){//stationary circle
  PORTA=sinTab[i];//horizontal sin wave
  PORTB=AH*sinTab[j++];//vertical sin wave
  delayMicroseconds(8);
}
}
   if (millis()>32500 && millis()<36000){//period with moving parabola
  for(int G=2*k;G>1;G--){  //parabola takes one rotation to get to full extent as it's length is determined by k
    PORTA=-4*parabola[G]-20;
    PORTB=G+108;
    delayMicroseconds(120);//speed of parabola - may need adjusting
  
  }
  delayMicroseconds(8);
}

if (millis()>36000 && millis()<48000){//period with fixed parabola
  for(int g=1;g<125;g++){  //max value of g determines max reach of parabola
    PORTA=-4*parabola[g]-20; //sign defines orientation, first multiple determines 'flatness', constant defines x start position
    PORTB=g+108;  //constant determines y starting position
    delayMicroseconds(80);//this delay is crucial to ensure parabola is drawn properly (not sure why)
  }
  
  for(int i=0;i<256;i++){//stationary circle
  PORTA=AV*sinTab[i]+EPY;//horizontal sin wave
  PORTB=AH*sinTab[j++]+EPX;//vertical sin wave
  delayMicroseconds(8);
}

  delayMicroseconds(8);
AH=AH-0.003;
AV=AV-0.003;
EPY=EPY+0.7;
EPX=EPX+0.3;

if(millis()>40000 && millis()<48000){
    for(int MN=0;MN<256;MN++){//stationary circle
  PORTA=0.3*AV*sinTab[MN]+(1.2*EPY)-120;//horizontal sin wave
  PORTB=0.3*AH*sinTab[j++]+EPX+30;//vertical sin wave
  delayMicroseconds(8);
}
}

   }

}

if(millis()>48000 && millis()<50000){
  PORTA=128;
  PORTB=128;
}

//TETRAHEDRON

if(millis()>50000 && millis()<51000){
  
   for (int Tc=1;Tc<128;Tc++){//Tetrahedron counter (=2pi*100)
  int  T1x=CTx+t1x*(sin(0.01*Tc));//define dynamic points
   int T2x=CTx+t2x*(sin(0.01*(Tc+209)));//ad phase difference (in this case 1/3 of loop)
   int T3x=CTx+t3x*(sin(0.01*(Tc+418)));
    
   int T1y=CTy+t1y*(cos(0.01*Tc));
   int T2y=CTy+t2y*(cos(0.01*(Tc+209)));
   int T3y=CTy+t3y*(cos(0.01*(Tc+418)));
   //int T4y=CTy+t4y*(cos(0.01*Tc));//can use this to give vertical rotation
    
    //draw tetrahedron
    line(T1x,T1y,T2x,T2y);
    line(T2x,T2y,T3x,T3y);
    line(T3x,T3y,T1x,T1y);
    line(T1x,T1y,CTx,t4y);
    line(T2x,T2y,CTx,t4y);
    line(T3x,T3y,CTx,t4y);
    
  }
 
}
  
  
  
  //RUNNER
  if(millis()>51000 && millis()<65000){
    
    //frame 3
   for(unsigned char C1=1;C1<45;C1++){//C1 is loop counter for runner - when max value reached, cycle complete
 if(5>C1){
 line(20,25,30,20);//right foot
 line(30,20,20,60);//right shin
 line(20,60,60,100);//right thigh
 line(60,100,90,50);//left thigh
 line(90,50,125,60);//left shin
 line(125,60,135,60);//left foot
 line(60,100,40,150);//body
 line(40,150,90,160);//upper left arm
 line(90,160,110,140);//lower left arm
 line(40,150,20,110);//upper right arm
 line(20,110,0,150);//lower right arm
 
  for(int i=0;i<256;i++){
    PORTA=0.1*sinTab[i]+25;//horizontal sin wave
  PORTB=0.1*sinTab[j++]+150;//vertical sin wave
  delayMicroseconds(20);//delay between points
   
  }
  
    }
    
  //frame 1

  if(10>C1>5){//number of times to draw this frame before switching to next (ie, determines frame length
  line(50,20,60,30);//right foot
 line(60,30,30,70);//right shin
 line(30,70,60,100);//right thigh
 line(60,100,80,60);//left thigh
 line(80,60,120,35);//left shin
 line(120,35,110,20);//left foot
 line(60,100,40,150);//body
 line(40,150,90,150);//upper left arm
 line(90,150,110,110);//lower left arm
 line(40,150,40,110);//upper right arm
 line(40,110,5,150);//lower right arm
 
  for(int i=0;i<256;i++){
    PORTA=0.1*sinTab[i]+25;//horizontal sin wave
  PORTB=0.1*sinTab[j++]+150;//vertical sin wave
  delayMicroseconds(20);//delay between points
  }
 
  }
   
   
  //frame 7
 if(15>C1 && C1>10){
 line(50,20,60,20);//right foot
 line(60,20,35,60);//right shin
 line(35,60,60,100);//right thigh
 line(60,100,55,70);//left thigh
 line(55,70,100,75);//left shin
 line(100,75,100,65);//left foot
 line(60,100,40,150);//body
 line(40,150,90,120);//upper left arm
 line(90,120,35,105);//lower left arm
 line(40,150,80,110);//upper right arm
 line(80,110,25,115);//lower right arm
 
  for(int i=0;i<256;i++){
    PORTA=0.1*sinTab[i]+25;//horizontal sin wave
  PORTB=0.1*sinTab[j++]+150;//vertical sin wave
  delayMicroseconds(20);//delay between points
}
}

       //frame 5
 if(20>C1 && C1>15){
 line(60,25,70,30);//right foot
 line(70,30,50,65);//right shin
 line(50,65,60,100);//right thigh
 line(60,100,30,75);//left thigh
 line(30,75,80,50);//left shin
 line(80,50,80,40);//left foot
 line(60,100,40,150);//body
 line(40,150,80,130);//upper left arm
 line(80,130,55,120);//lower left arm
 line(40,150,30,120);//upper right arm
 line(30,120,10,115);//lower right arm
 
  for(int i=0;i<256;i++){
    PORTA=0.1*sinTab[i]+25;//horizontal sin wave
  PORTB=0.1*sinTab[j++]+150;//vertical sin wave
  delayMicroseconds(20);//delay between points

}
    
}

   if(25>C1 && C1>20){
    //frame 2
   line(50,20,60,20);//right foot
 line(60,20,30,50);//right shin
 line(30,50,60,100);//right thigh
 line(60,100,60,60);//left thigh
 line(60,60,120,65);//left shin
 line(120,65,120,55);//left foot
 line(60,100,40,150);//body
 line(40,150,80,120);//upper left arm
 line(80,120,40,110);//lower left arm
 line(40,150,70,115);//upper right arm
 line(70,115,20,125);//lower right arm
 
  for(int i=0;i<256;i++){
    PORTA=0.1*sinTab[i]+25;//horizontal sin wave
  PORTB=0.1*sinTab[j++]+150;//vertical sin wave
  delayMicroseconds(20);//delay between points
   
  }
    }
    
  //frame 7
 if(30>C1 && C1>25){
 line(50,20,60,20);//right foot
 line(60,20,35,60);//right shin
 line(35,60,60,100);//right thigh
 line(60,100,55,70);//left thigh
 line(55,70,100,75);//left shin
 line(100,75,100,65);//left foot
 line(60,100,40,150);//body
 line(40,150,90,120);//upper left arm
 line(90,120,35,105);//lower left arm
 line(40,150,80,110);//upper right arm
 line(80,110,25,115);//lower right arm
 
  for(int i=0;i<256;i++){
    PORTA=0.1*sinTab[i]+25;//horizontal sin wave
  PORTB=0.1*sinTab[j++]+150;//vertical sin wave
  delayMicroseconds(20);//delay between points
}
}


   //frame 5
 if(35>C1 && C1>30){
 line(60,25,70,30);//right foot
 line(70,30,50,65);//right shin
 line(50,65,60,100);//right thigh
 line(60,100,30,75);//left thigh
 line(30,75,80,50);//left shin
 line(80,50,80,40);//left foot
 line(60,100,40,150);//body
 line(40,150,80,130);//upper left arm
 line(80,130,55,120);//lower left arm
 line(40,150,30,120);//upper right arm
 line(30,120,10,115);//lower right arm
 
  for(int i=0;i<256;i++){
    PORTA=0.1*sinTab[i]+25;//horizontal sin wave
  PORTB=0.1*sinTab[j++]+150;//vertical sin wave
  delayMicroseconds(20);//delay between points

}
    
}

  
 //frame 6
 if(40>C1 && C1>35){
 line(40,20,50,25);//right foot
 line(50,25,20,70);//right shin
 line(20,70,60,100);//right thigh
 line(60,100,70,65);//left thigh
 line(70,65,100,30);//left shin
 line(100,30,100,20);//left foot
 line(60,100,40,150);//body
 line(40,150,90,150);//upper left arm
 line(90,150,100,110);//lower left arm
 line(40,150,20,110);//upper right arm
 line(20,110,0,150);//lower right arm
 
  for(int i=0;i<256;i++){
    PORTA=0.1*sinTab[i]+25;//horizontal sin wave
  PORTB=0.1*sinTab[j++]+150;//vertical sin wave
  delayMicroseconds(20);//delay between points
}
}
  //frame 1

  if(45>C1>40){//number of times to draw this frame before switching to next (ie, determines frame length
  line(50,20,60,30);//right foot
 line(60,30,30,70);//right shin
 line(30,70,60,100);//right thigh
 line(60,100,80,60);//left thigh
 line(80,60,120,35);//left shin
 line(120,35,110,20);//left foot
 line(60,100,40,150);//body
 line(40,150,90,150);//upper left arm
 line(90,150,110,110);//lower left arm
 line(40,150,40,110);//upper right arm
 line(40,110,5,150);//lower right arm
 
  for(int i=0;i<256;i++){
    PORTA=0.1*sinTab[i]+25;//horizontal sin wave
  PORTB=0.1*sinTab[j++]+150;//vertical sin wave
  delayMicroseconds(20);//delay between points
  }
 
  }
   }
  }
  
  
  
  
  //DIVER
   
  if(millis()>65000 && millis()<80000){
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

if(millis()>80000 && millis()<81000){
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
if(millis()>81000 && millis()<82000){

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
       if(millis()>82000){
         break;
       }
}
}

if(millis()>82000 && millis() <105000){
  
   
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
    
    
    
    
    
// SCOTLAND MAP

if(millis()>105000 && millis()<120000){
  
  line(15,5,35,15);
  line(35,15,60,5);
  line(60,5,85,15);
  line(85,15,60,12);
  line(60,12,63,20);
  line(63,20,50,30);
  line(50,30,75,40);
  line(75,40,50,45);
  line(50,45,10,110);
  line(10,110,15,120);
  line(15,120,65,130);
  line(65,130,115,120);
  line(115,120,70,160);
  line(70,160,75,180);
  line(75,180,160,170);
  line(160,170,180,180);
  line(180,180,190,140);
  line(190,140,210,160);
  line(210,160,215,155);
  line(215,155,193,130);
  line(193,130,230,90);
  line(230,90,208,90);
  line(208,90,200,105);
  line(200,105,200,90);
  line(200,90,225,70);
  line(225,70,220,65);
  line(220,65,200,85);
  line(200,85,195,75);
  line(195,75,215,60);
  line(215,60,212,58);
  line(212,58,190,70);
  line(190,70,200,55);
  line(200,55,180,35);
  line(180,35,210,15);
  line(210,15,200,5);
}




//AMSTERDAM
if(millis()>120000 && millis()<130000){
  

for (int Cc=0;Cc<228;Cc++){ //!!!!!628

  //blade 1
  int BLX1=0.7*Blx*(1+sin(0.01*Cc))+32;
  int BLY1=0.7*Bly*(1+cos(0.01*Cc))+70;
  int BLX2=0.7*Blx*(1+sin(0.01*Cc+3.14))+32;
  int BLY2=0.7*Bly*(1+cos(0.01*Cc+3.14))+70;
  
  //blade 2
  int BLX3=0.7*Blx*(1+sin((0.01*Cc)+1.56))+32;//1.56 is the phase difference (ie pi/2)
  int BLY3=0.7*Bly*(1+cos((0.01*Cc)+1.56))+70;
  int BLX4=0.7*Blx*(1+sin((0.01*Cc+1.56)+3.14))+32;
  int BLY4=0.7*Bly*(1+cos((0.01*Cc+1.56)+3.14))+70;
 
 
line(BLX1,BLY1,BLX2,BLY2);//blade 1
line(BLX3,BLY3,BLX4,BLY4);//blade 2


//tower
line(80,50,100,200);
line(100,200,128,220);
line(128,220,156,200);
line(156,200,176,60);



//bike 1

int b11x=10;//bike 1 x coordinates
int b12x=40;
int b13x=40;
int b14x=10;
int b15x=40;
int b16x=70;
int b17x=40;
int b18x=70;
int b19x=35;
int b110x=40;

int b11y=15;//bike 1 y coordinates
int b12y=15;
int b13y=40;
int b14y=15;
int b15y=15;
int b16y=40;
int b17y=40;
int b18y=40;
int b19y=57;
int b110y=40;


//bike frame
line(b11x+Cc/3,b11y,b12x+Cc/3,b12y);//divisor under Cc gives bike distance and speed
line(b12x+Cc/3,b12y,b13x+Cc/3,b13y);
line(b13x+Cc/3,b13y,b14x+Cc/3,b14y);
line(b14x+Cc/3,b14y,b15x+Cc/3,b15y);
line(b15x+Cc/3,b15y,b16x+Cc/3,b16y);
line(b16x+Cc/3,b16y,b17x+Cc/3,b17y);
line(b18x+Cc/3,b18y,b19x+Cc/3,b19y);
line(b19x+Cc/3,b19y,b110x+Cc/3,b110y);

//FRONT WHEEL
         for(int Bw1=0;Bw1<256;Bw1){
    PORTA=0.08*sinTab[Bw1]+57+Cc/3;//horizontal sin wave
   PORTB=0.08*sinTab[j]+10;//vertical sin wave
  delayMicroseconds(8);//delay between points
  Bw1=Bw1+4;//increment by 2 to reduce time on wheel
  j=j+4;

    }
    //backwheel
         for(int Fw1=0;Fw1<256;Fw1){
    PORTA=0.08*sinTab[Fw1]+7+Cc/3;//horizontal sin wave
   PORTB=0.08*sinTab[j]+10;//vertical sin wave
  delayMicroseconds(8);//delay between points
  Fw1=Fw1+4;
  j=j+4;
         }
  
  for(int Fw1=0;Fw1<256;Fw1){
    PORTA=0.05*sinTab[Fw1]+38+Cc/3;//horizontal sin wave
   PORTB=0.05*sinTab[j]+57;//vertical sin wave
  delayMicroseconds(8);//delay between points
  Fw1=Fw1+4;
  j=j+4;
  }
    
    
    
 //bike 2




int b21x=80;//bike 2 x coordinates
int b22x=110;
int b23x=110;
int b24x=80;
int b25x=110;
int b26x=140;
int b27x=110;
int b28x=140;
int b29x=105;
int b210x=110;

int b21y=15;//bike 2 y coordinates
int b22y=15;
int b23y=40;
int b24y=15;
int b25y=15;
int b26y=40;
int b27y=40;
int b28y=40;
int b29y=57;
int b210y=40;


//bike frame
line(b21x+Cc/3,b21y,b22x+Cc/3,b22y);//divisor under Cc gives bike distance and speed
line(b22x+Cc/3,b22y,b23x+Cc/3,b23y);
line(b23x+Cc/3,b23y,b24x+Cc/3,b24y);
line(b24x+Cc/3,b24y,b25x+Cc/3,b25y);
line(b25x+Cc/3,b25y,b26x+Cc/3,b26y);
line(b26x+Cc/3,b26y,b27x+Cc/3,b27y);
line(b28x+Cc/3,b28y,b29x+Cc/3,b29y);
line(b29x+Cc/3,b29y,b210x+Cc/3,b210y);

//FRONT WHEEL
         for(int Bw1=0;Bw1<256;Bw1){
    PORTA=0.08*sinTab[Bw1]+127+Cc/3;//horizontal sin wave
   PORTB=0.08*sinTab[j]+10;//vertical sin wave
  delayMicroseconds(8);//delay between points
  Bw1=Bw1+4;//increment by 2 to reduce time on wheel
  j=j+4;

    }
    //backwheel
         for(int Fw1=0;Fw1<256;Fw1){
    PORTA=0.08*sinTab[Fw1]+77+Cc/3;//horizontal sin wave
   PORTB=0.08*sinTab[j]+10;//vertical sin wave
  delayMicroseconds(8);//delay between points
  Fw1=Fw1+4;
  j=j+4;
         }
  //head
  for(int Fw1=0;Fw1<256;Fw1){
    PORTA=0.05*sinTab[Fw1]+108+Cc/3;//horizontal sin wave
   PORTB=0.05*sinTab[j]+57;//vertical sin wave
  delayMicroseconds(8);//delay between points
  Fw1=Fw1+4;
  j=j+4;
  }

//cyclist 1 legs
int Bk1x=55;
int Bk2x=40;
int Bk1y=30;
int Bk2y=15;

int Bk1yh=38; //raised knee position

//plot leg for cyclist 1
if(Cc%6 < 3 ){
  line(b13x-10+Cc/3,b13y,Bk1x+Cc/3,Bk1y);//plots leg low only if modulo (Cc/6)<3 ; ie changes every 3 frames
  line(Bk1x+Cc/3,Bk1y,Bk2x+Cc/3,Bk2y);
}

if(Cc%6 > 3 ){
  line(b13x-10+Cc/3,b13y,Bk1x+Cc/3,Bk1yh);//plots leg high only if modulo (Cc/6)<3 ; ie changes every 3 frames
  line(Bk1x+Cc/3,Bk1yh,Bk2x+Cc/3,Bk2y);
}


//cyclist 2 legs
int Bk21x=125;
int Bk22x=110;
int Bk21y=30;
int Bk22y=15;

int Bk21yh=38; //raised knee position

//plot leg for cyclist 1
if(Cc%6 > 3 ){
  line(b23x-10+Cc/3,b23y,Bk21x+Cc/3,Bk21y);//plots leg low only if modulo (Cc/6)<3 ; ie changes every 3 frames
  line(Bk21x+Cc/3,Bk21y,Bk22x+Cc/3,Bk22y);
}

if(Cc%6 < 3 ){
  line(b23x-10+Cc/3,b23y,Bk21x+Cc/3,Bk21yh);//plots leg high only if modulo (Cc/6)<3 ; ie changes every 3 frames
  line(Bk21x+Cc/3,Bk21yh,Bk22x+Cc/3,Bk22y);
}


  delayMicroseconds(40);
  
}
}




//OIL PLATFORM
if(millis()>130000 && millis()<148000){
     
  
for(int HZC=9999;HZC>1;HZC--){//heli zoom counter

//COORDINATES
int hex1=HEXX+hexx1;
int hex2=HEXX+hexx2;
int hex3=HEXX+hexx3;
int hex4=HEXX+hexx4;
int hex5=HEXX+hexx5;
int hex6=HEXX+hexx6;
int hex6a=HEXX+hexx6a;
int hex6b=HEXX+hexx6b;
int hex6c=HEXX+hexx6c;
int hex7=HEXX+hexx7;
int hex8=HEXX+hexx8;



//coordinates y
int hexy1=HEXY+hexyy1;
int hexy2=HEXY+hexyy2;
int hexy3=HEXY+hexyy3;
int hexy4=HEXY+hexyy4;
int hexy5=HEXY+hexyy5;
int hexy6=HEXY+hexyy6;
int hexy6a=HEXY+hexyy6a;
int hexy6b=HEXY+hexyy6b;
int hexy6c=HEXY+hexyy6c;
int hexy7=HEXY+hexyy7;
int hexy8=HEXY+hexyy8;

  //draw oil platform
  line(ORX1,ORY1,ORX2,ORY2);
   line(ORX2,ORY2,ORX3,ORY3);
 line(ORX3,ORY3,ORX4,ORY4);
  line(ORX4,ORY4,ORX5,ORY5);
   line(ORX5,ORY5,ORX6,ORY6);
    line(ORX6,ORY6,ORX7,ORY7);
  line(ORX7,ORY7,ORX8,ORY8);
 line(ORX8,ORY8,ORX9,ORY9);
  line(ORX9,ORY9,ORX10,ORY10);
  line(ORX9,ORY9,ORX13,ORY13);
   line(ORX10,ORY10,ORX11,ORY11);
  line(ORX10,ORY10,ORX12,ORY12);
    line(ORX11,ORY11,ORX12,ORY12);
  line(ORX12,ORY12,ORX13,ORY13);
   line(ORX13,ORY13,ORX14,ORY14);
    line(ORX14,ORY14,ORX15,ORY15);
     line(ORX15,ORY15,ORX16,ORY16);
  line(ORX16,ORY16,ORX17,ORY17);
   line(ORX17,ORY17,ORX18,ORY18);
    line(ORX18,ORY18,ORX19,ORY19);
     line(ORX18,ORY18,ORX20,ORY20);
     line(ORX19,ORY19,ORX20,ORY20);
      line(ORX20,ORY20,ORX17,ORY17);
      line(ORX20,ORY20,ORX21,ORY21);
  line(ORX21,ORY21,ORX22,ORY22);
   line(ORX22,ORY22,ORX23,ORY23);
    line(ORX23,ORY23,ORX24,ORY24);
    line(ORX24,ORY24,ORX2,ORY2); 
     line(ORX2,ORY2,ORX23,ORY23);
      line(ORX23,ORY23,ORX1,ORY1);
      
 for(int ors=1;ors<314;ors++){
   PORTA=0.8*ors;
   PORTB=10*sin(0.1*ors)+20;
   ors=ors+4;  //reduces flicker rate
   

         
 }
//NEED TO SORT OUT HELICOPTER
   //draw helicopter
   line(hex1,hexy1,hex2,hexy2);
    line(hex2,hexy2,hex3,hexy3);
     line(hex3,hexy3,hex4,hexy4);
      line(hex4,hexy4,hex5,hexy5);
       line(hex5,hexy5,hex6,hexy6);
        line(hex6,hexy6,hex6a,hexy6a);
        line(hex6a,hexy6a,hex6b,hexy6b);
        line(hex6b,hexy6b,hex6c,hexy6c);
        line(hex6c,hexy6c,hex6a,hexy6a);
        line(hex6a,hexy6a,hex6,hexy6);
        line(hex6,hexy6,hex7,hexy7);
         line(hex7,hexy7,hex8,hexy8);
          line(hex8,hexy8,hex1,hexy1);
          
hexx1=hexx1*0.0001*HZC;
hexx2=hexx2*0.0001*HZC;
hexx3=hexx3*0.0001*HZC;
hexx4=hexx4*0.0001*HZC;
hexx5=hexx5*0.0001*HZC;
hexx6=hexx6*0.0001*HZC;
hexx6a=hexx6a*0.0001*HZC;
hexx6b=hexx6b*0.0001*HZC;
hexx6c=hexx6c*0.0001*HZC;
hexx7=hexx7*0.0001*HZC;
hexx8=hexx8*0.0001*HZC;

hexyy1=hexyy1*0.0001*HZC;
hexyy2=hexyy2*0.0001*HZC;
hexyy3=hexyy3*0.0001*HZC;
hexyy4=hexyy4*0.0001*HZC;
hexyy5=hexyy5*0.0001*HZC;
hexyy6=hexyy6*0.0001*HZC;
hexyy6a=hexyy6a*0.0001*HZC;
hexyy6b=hexyy6b*0.0001*HZC;
hexyy6c=hexyy6c*0.0001*HZC;
hexyy7=hexyy7*0.0001*HZC;
hexyy8=hexyy8*0.0001*HZC;

//move heli
HEXX=HEXX+0.1;
HEXY=HEXY+0.1;

if(millis()>148000){
  break;
}

}
}




//NEW YORK
  if (millis()>148000 && millis()<153000){

  for(int ESBC=255;ESBC>1;ESBC){
    //verticl elements
    fastline(50,1,50,254); //building side
     fastline(70,254,70,1); 
      fastline(90,1,90,254);
      fastline(92,254,92,1);  
      // fastline(110,1,110,254); 
        // fastline(130,254,130,1); 
          fastline(150,1,150,254);
          fastline(152,254,152,1);  
           fastline(170,1,170,254); 
            fastline(190,254,190,1); //building side
            
  //horizontal elements
  /*
  line(50,ESBC,190,ESBC);
   line(195,ESBC+50,50,ESBC+50);
    line(50,ESBC+100,195,ESBC+100);
     line(195,ESBC+150,50,ESBC+150);
       line(50,ESBC+200,195,ESBC+200);
         line(195,ESBC+250,50,ESBC+250);
 */
 ESBC=ESBC-4;
  }
  }
  
  
  if(millis()>153000 && millis()<156000){
   
  for(int ESBC=255;ESBC>1;ESBC){
    //scrolling building
    fastline(50,1,50,ESBC-40); //building side
    fastline(50,ESBC-40,70,ESBC-40);
    fastline(70,ESBC-40,70,ESBC-20);
    fastline(70,ESBC-20,95,ESBC-20);
    fastline(95,ESBC-20,95,ESBC);
    fastline(95,ESBC,155,ESBC);//roof
   
    fastline(120,ESBC,125,254);
    fastline(125,254,130,ESBC);//spire
    

    
    fastline(155,ESBC,155,ESBC-20);
    fastline(155,ESBC-20,180,ESBC-20);
    fastline(180,ESBC-20,180,ESBC-40);
    fastline(180,ESBC-40,200,ESBC-40);
    
        fastline(150,ESBC,150,1); //vertical internals
    fastline(130,1,130,ESBC);
        fastline(120,ESBC,120,1); //vertical internals
    fastline(110,1,110,ESBC);
        fastline(120,ESBC,120,1); //vertical internals
    fastline(90,1,90,ESBC);
    
   
    fastline(200,ESBC-40,200,1);
   

          
 ESBC=ESBC-2;
 if(millis()>156000){
   break;
 }
  }
  }
   
   if(millis()>156000 && millis()<160000){
     int ESBC=120;
     for(int HZ=1;HZ<512;HZ){
        fastline(50-(0.1*HZ),1,50-(0.1*HZ),ESBC-40-(0.1*HZ)); //building side
    fastline(50-(0.1*HZ),ESBC-40-(0.1*HZ),70-(0.1*HZ),ESBC-40-(0.1*HZ));
    fastline(70-(0.1*HZ),ESBC-40-(0.1*HZ),70-(0.1*HZ),ESBC-20-(0.1*HZ));
    fastline(70-(0.1*HZ),ESBC-20-(0.1*HZ),95-(0.1*HZ),ESBC-20-(0.1*HZ));
    fastline(95-(0.1*HZ),ESBC-20,95-(0.1*HZ),ESBC);
    fastline(95-(0.1*HZ),ESBC,155+(0.1*HZ),ESBC);//roof
   
    fastline(120-(0.02*HZ),ESBC,125-(0.02*HZ),254);
    fastline(125-(0.02*HZ),254,125+(0.02*HZ),254);
    fastline(125+(0.02*HZ),254,130+(0.02*HZ),ESBC);//spire
    
    
    fastline(155+(0.1*HZ),ESBC,155+(0.1*HZ),ESBC-20-(0.1*HZ));
    fastline(155+(0.1*HZ),ESBC-20-(0.1*HZ),180+(0.1*HZ),ESBC-20-(0.1*HZ));
    fastline(180+(0.1*HZ),ESBC-20-(0.1*HZ),180+(0.1*HZ),ESBC-40-(0.1*HZ));
    fastline(180+(0.1*HZ),ESBC-40-(0.1*HZ),200+(0.1*HZ),ESBC-40-(0.1*HZ));
    
        fastline(150+(0.1*HZ),ESBC,150+(0.1*HZ),1); //vertical internals
    fastline(130+(0.1*HZ),1,130+(0.1*HZ),ESBC);
        fastline(120-(0.1*HZ),ESBC,120-(0.1*HZ),1); //vertical internals
    fastline(110-(0.1*HZ),1,110-(0.1*HZ),ESBC);
        fastline(120-(0.1*HZ),ESBC,120-(0.1*HZ),1); //vertical internals
    fastline(90-(0.1*HZ),1,90-(0.1*HZ),ESBC);
    
   // fastline(200+(0.1*HZ),ESBC-80-(0.1*HZ),50-(0.1*HZ),ESBC-80-(0.1*HZ));//horizontal
   // fastline(50-(0.1*HZ),ESBC-120-(0.1*HZ),200+(0.1*HZ),ESBC-120-(0.1*HZ));//horizontal
   // fastline(200+(0.1*HZ),ESBC-40-(0.1*HZ),50-(0.1*HZ),ESBC-40-(0.1*HZ));//horizontal
    fastline(200+(0.1*HZ),ESBC-40-(0.1*HZ),200+(0.1*HZ),1);
   
   HZ=HZ+2;
   } 
   }
   
   if(millis()>160000 && millis()<168000){
          int ESBC=120;
          int HZ=520;
     
        fastline(50-(0.1*HZ),1,50-(0.1*HZ),ESBC-40-(0.1*HZ)); //building side
    fastline(50-(0.1*HZ),ESBC-40-(0.1*HZ),70-(0.1*HZ),ESBC-40-(0.1*HZ));
    fastline(70-(0.1*HZ),ESBC-40-(0.1*HZ),70-(0.1*HZ),ESBC-20-(0.1*HZ));
    fastline(70-(0.1*HZ),ESBC-20-(0.1*HZ),95-(0.1*HZ),ESBC-20-(0.1*HZ));
    fastline(95-(0.1*HZ),ESBC-20,95-(0.1*HZ),ESBC);
    fastline(95-(0.1*HZ),ESBC,155+(0.1*HZ),ESBC);//roof
   
    fastline(120-(0.02*HZ),ESBC,125-(0.02*HZ),254);
    fastline(125-(0.02*HZ),254,125+(0.02*HZ),254);
    fastline(125+(0.02*HZ),254,130+(0.02*HZ),ESBC);//spire
    
    //stick figure 1
      line(150,120,160,130);//legs
      line(160,130,170,120);
      line(160,130,160,140);//body
      line(160,140,170,130);//arms
      line(170,130,160,140);
      line(160,140,150,130);
      
    //head
       for(int NYH1=0;NYH1<256;NYH1++){
   PORTA=0.02*sinTab[NYH1]+158;//horizontal sin wave
  PORTB=0.02*sinTab[j++]+138;//vertical sin wave
  delayMicroseconds(8);
       }
       
  //stick figure 2
  line(170,130,180,140);//arm
      //head
       for(int NYH1=0;NYH1<256;NYH1++){
   PORTA=0.02*sinTab[NYH1]+178;//horizontal sin wave
  PORTB=0.02*sinTab[j++]+138;//vertical sin wave
  delayMicroseconds(8);
       }
  line(180,140,190,130);//arm
  line(190,130,180,140);//arm retrace
  line(180,140,180,130);//body
  line(180,130,190,120);//leg
  line(190,120,180,130);//leg retrace
  line(180,130,170,120);
    
    fastline(155+(0.1*HZ),ESBC,155+(0.1*HZ),ESBC-20-(0.1*HZ));
    fastline(155+(0.1*HZ),ESBC-20-(0.1*HZ),180+(0.1*HZ),ESBC-20-(0.1*HZ));
    fastline(180+(0.1*HZ),ESBC-20-(0.1*HZ),180+(0.1*HZ),ESBC-40-(0.1*HZ));
    fastline(180+(0.1*HZ),ESBC-40-(0.1*HZ),200+(0.1*HZ),ESBC-40-(0.1*HZ));
    
        fastline(150+(0.1*HZ),ESBC,150+(0.1*HZ),1); //vertical internals
    fastline(130+(0.1*HZ),1,130+(0.1*HZ),ESBC);
        fastline(120-(0.1*HZ),ESBC,120-(0.1*HZ),1); //vertical internals
    fastline(110-(0.1*HZ),1,110-(0.1*HZ),ESBC);
        fastline(120-(0.1*HZ),ESBC,120-(0.1*HZ),1); //vertical internals
    fastline(90-(0.1*HZ),1,90-(0.1*HZ),ESBC);
    
   // fastline(200+(0.1*HZ),ESBC-80-(0.1*HZ),50-(0.1*HZ),ESBC-80-(0.1*HZ));//horizontal
   // fastline(50-(0.1*HZ),ESBC-120-(0.1*HZ),200+(0.1*HZ),ESBC-120-(0.1*HZ));//horizontal
   // fastline(200+(0.1*HZ),ESBC-40-(0.1*HZ),50-(0.1*HZ),ESBC-40-(0.1*HZ));//horizontal
    fastline(200+(0.1*HZ),ESBC-40-(0.1*HZ),200+(0.1*HZ),1);
   }




//PROPOSE

//if(millis()>168000){
  
  
  
  //propose right figure xcoordinate variables (start positions)
int pcrx0=0;//datum
int pcrx1=15;//knee
int pcrx2=30;
int pcrx3=45;//knee
int pcrx4=60;
int pcrx5=30;
int pcrx6=45;
int pcrx7=60;
int pcrx8=15;
int pcrx9=0;
int phprx=138;//head x position

//propose right figure y coordinate variables
int pcry0=0;//datum
int pcry1=30;
int pcry2=70;
int pcry3=30;
int pcry4=0;
int pcry5=120;
int pcry6=95;
int pcry7=70;
int pcry8=95;
int pcry9=70;
int phpry=130;//head y position


if(millis()<169500 && millis()>168000){
  for(int PCC=1;255;PCC++){
    int PCLX0=10; //datum for left figure (left foot)
    int PCLY0=10;//y datum for left figure
    int PCRX0=120;//xdatum for right figure
    int PCRY0=10;//y datum for right figure
    
    
    
    //determine coordinates of left figure
    int PCLX1=PCLX0+pclx1;
     int PCLX2=PCLX0+pclx2;
       int PCLX3=PCLX0+pclx3;
       int PCLX3a=PCLX0+pclx3a;
       int PCLX3b=PCLX0+pclx3b;
     int PCLX4=PCLX0+pclx4;
     int PCLX5=PCLX0+pclx5;
     int PCLX6=PCLX0+pclx6;
   
   int PCLY1=PCLY0+pcly1;
   int PCLY2=PCLY0+pcly2;
   int PCLY3=PCLY0+pcly3;
   int PCLY3a=PCLY0+pcly3a;
   int PCLY3b=PCLY0+pcly3b;
   int PCLY4=PCLY0+pcly4;
   int PCLY5=PCLY0+pcly5;
   int PCLY6=PCLY0+pcly6;
   
   //plot left figure
   line(PCLX0,PCLY0,PCLX1,PCLY1);
   line(PCLX1,PCLY1,PCLX2,PCLY2);
    line(PCLX2,PCLY2,PCLX1,PCLY1);//leg retrace
   line(PCLX1,PCLY1,PCLX3,PCLY3);//body
   line(PCLX3,PCLY3,PCLX3a,PCLY3a);
   line(PCLX3a,PCLY3a,PCLX4,PCLY4);
   line(PCLX4,PCLY4,PCLX3a,PCLY3a);//arm retrace
   line(PCLX3a,PCLY3a,PCLX3,PCLY3);
   line(PCLX3,PCLY3,PCLX3b,PCLY3b);//arm
   line(PCLX3b,PCLY3b,PCLX5,PCLY5);
   line(PCLX5,PCLY5,PCLX3b,PCLY3b);//arm retrace
   line(PCLX3b,PCLY3b,PCLX3,PCLY3);
   
   //left figure head
   for(int lhc=0;lhc<256;lhc++){
   PORTA=0.1*sinTab[lhc]+phpx;//horizontal sin wave
  PORTB=0.1*sinTab[j++]+phpy;//vertical sin wave
  delayMicroseconds(8);
   }
   
   //retrace to ground
      line(PCLX3,PCLY3,PCLX1,PCLY1);
   line(PCLX1,PCLY1,PCLX2,PCLY2);
   
       //determine coordinates of right figure
    int PCRX1=PCRX0+pcrx1;
     int PCRX2=PCRX0+pcrx2;
       int PCRX3=PCRX0+pcrx3;
     int PCRX4=PCRX0+pcrx4;
     int PCRX5=PCRX0+pcrx5;
     int PCRX6=PCRX0+pcrx6;
      int PCRX7=PCRX0+pcrx7;
     int PCRX8=PCRX0+pcrx8;
     int PCRX9=PCRX0+pcrx9;
   
   int PCRY1=PCRY0+pcry1;
   int PCRY2=PCRY0+pcry2;
   int PCRY3=PCRY0+pcry3;
   int PCRY4=PCRY0+pcry4;
   int PCRY5=PCRY0+pcry5;
   int PCRY6=PCRY0+pcry6;
    int PCRY7=PCRY0+pcry7;
   int PCRY8=PCRY0+pcry8;
   int PCRY9=PCRY0+pcry9;
   
   
   //plot RIGHT figure
   line(PCRX0,PCRY0,PCRX1,PCRY1);
   line(PCRX1,PCRY1,PCRX2,PCRY2);
    line(PCRX2,PCRY2,PCRX3,PCRY3);
   line(PCRX3,PCRY3,PCRX4,PCRY4);
   line(PCRX4,PCRY4,PCRX3,PCRY3);//leg retrace to knee
    line(PCRX3,PCRY3,PCRX2,PCRY2);//leg retrace to body
   line(PCRX2,PCRY2,PCRX5,PCRY5);//body
    line(PCRX5,PCRY5,PCRX6,PCRY6);
     line(PCRX6,PCRY6,PCRX7,PCRY7);
    line(PCRX7,PCRY7,PCRX6,PCRY6);//retrace to elbow
     line(PCRX6,PCRY6,PCRX5,PCRY5);//retrace to body
      line(PCRX5,PCRY5,PCRX8,PCRY8);
       line(PCRX8,PCRY8,PCRX9,PCRY9);
     line(PCRX9,PCRY9,PCRX8,PCRY8);//retrace to elbow
      line(PCRX8,PCRY8,PCRX5,PCRY5);
   
   //right figure head
   for(int rhc=0;rhc<256;rhc++){
   PORTA=0.1*sinTab[rhc]+phprx;//horizontal sin wave
  PORTB=0.1*sinTab[j++]+phpry;//vertical sin wave
  delayMicroseconds(8);
   }
   
   //retrace
   line(PCRX5,PCRY5,PCRX2,PCRY2);
   line(PCRX2,PCRY2,PCRX1,PCRY1);
   line(PCRX1,PCRY1,PCRX0,PCRY0);
   
   //move figure

   
        pcry2=pcry2-1;
        pcrx1=pcrx1-0.1;//front knee
        pcrx3=pcrx3-0.002;//back knee
        pcry3=pcry3-0.0005;
        pcry5=pcry5-1;//top body
        pcry6=pcry6-1;//elbows
        pcrx7=pcrx7-2;
                pcrx8=pcrx8-0;
        pcry8=pcry8-1;
        pcry9=pcry9+1;
        pcrx9=pcrx9-1+1;
        pcry7=pcry7+1;
        phpry=phpry-1;//head

   
 if(pcry3<5){
   break;
 }
  }
  }
  
  if(173000>millis() && millis()>169500){
    for(int PCC=1;255;PCC++){
        int PCLX0=10; //datum for left figure (left foot)
    int PCLY0=10;//y datum for left figure
    int PCRX0=120;//xdatum for right figure
    int PCRY0=10;//y datum for right figure
    
 //determine coordinates of left figure
    int PCLX1=PCLX0+pclx1;
     int PCLX2=PCLX0+pclx2;
       int PCLX3=PCLX0+pclx3;
       int PCLX3a=PCLX0+pclx3a;
       int PCLX3b=PCLX0+pclx3b;
     int PCLX4=PCLX0+pclx4;
     int PCLX5=PCLX0+pclx5;
     int PCLX6=PCLX0+pclx6;
   
   int PCLY1=PCLY0+pcly1;
   int PCLY2=PCLY0+pcly2;
   int PCLY3=PCLY0+pcly3;
   int PCLY3a=PCLY0+pcly3a;
   int PCLY3b=PCLY0+pcly3b;
   int PCLY4=PCLY0+pcly4;
   int PCLY5=PCLY0+pcly5;
   int PCLY6=PCLY0+pcly6;
   
   //plot left figure
   line(PCLX0,PCLY0,PCLX1,PCLY1);
   line(PCLX1,PCLY1,PCLX2,PCLY2);
    line(PCLX2,PCLY2,PCLX1,PCLY1);//leg retrace
   line(PCLX1,PCLY1,PCLX3,PCLY3);//body
   line(PCLX3,PCLY3,PCLX3a,PCLY3a);
   line(PCLX3a,PCLY3a,PCLX4,PCLY4);
   line(PCLX4,PCLY4,PCLX3a,PCLY3a);//arm retrace
   line(PCLX3a,PCLY3a,PCLX3,PCLY3);
   line(PCLX3,PCLY3,PCLX3b,PCLY3b);//arm
   line(PCLX3b,PCLY3b,PCLX5,PCLY5);
   line(PCLX5,PCLY5,PCLX3b,PCLY3b);//arm retrace
   line(PCLX3b,PCLY3b,PCLX3,PCLY3);
   
   //left figure head
   for(int lhc=0;lhc<256;lhc++){
   PORTA=0.1*sinTab[lhc]+phpx;//horizontal sin wave
  PORTB=0.1*sinTab[j++]+phpy;//vertical sin wave
  delayMicroseconds(8);
   }
   
   //retrace to ground
      line(PCLX3,PCLY3,PCLX1,PCLY1);
   line(PCLX1,PCLY1,PCLX2,PCLY2);
   
   
       //determine coordinates of right figure
    int PCRX1=PCRX0+pcrx1;
     int PCRX2=PCRX0+pcrx2;
       int PCRX3=PCRX0+pcrx3;
     int PCRX4=PCRX0+pcrx4;
     int PCRX5=PCRX0+pcrx5;
     int PCRX6=PCRX0+pcrx6;
      int PCRX7=PCRX0+pcrx7;
     int PCRX8=PCRX0+pcrx8;
     int PCRX9=PCRX0+pcrx9;
   
   int PCRY1=PCRY0+pcry1;
   int PCRY2=PCRY0+pcry2;
   int PCRY3=PCRY0+pcry3;
   int PCRY4=PCRY0+pcry4;
   int PCRY5=PCRY0+pcry5;
   int PCRY6=PCRY0+pcry6;
    int PCRY7=PCRY0+pcry7;
   int PCRY8=PCRY0+pcry8;
   int PCRY9=PCRY0+pcry9;
   
   
   //plot RIGHT figure
   line(PCRX0,PCRY0,PCRX1,PCRY1);
   line(PCRX1,PCRY1,PCRX2,PCRY2);
    line(PCRX2,PCRY2,PCRX3,PCRY3);
   line(PCRX3,PCRY3,PCRX4,PCRY4);
   line(PCRX4,PCRY4,PCRX3,PCRY3);//leg retrace to knee
    line(PCRX3,PCRY3,PCRX2,PCRY2);//leg retrace to body
   line(PCRX2,PCRY2,PCRX5,PCRY5);//body
    line(PCRX5,PCRY5,PCRX6,PCRY6);
     line(PCRX6,PCRY6,PCRX7,PCRY7);
    line(PCRX7,PCRY7,PCRX6,PCRY6);//retrace to elbow
     line(PCRX6,PCRY6,PCRX5,PCRY5);//retrace to body
      line(PCRX5,PCRY5,PCRX8,PCRY8);
       line(PCRX8,PCRY8,PCRX9,PCRY9);
     line(PCRX9,PCRY9,PCRX8,PCRY8);//retrace to elbow
      line(PCRX8,PCRY8,PCRX5,PCRY5);
   
   //right figure head
   for(int rhc=0;rhc<256;rhc++){
   PORTA=0.1*sinTab[rhc]+phprx;//horizontal sin wave
  PORTB=0.1*sinTab[j++]+phpry;//vertical sin wave
  delayMicroseconds(8);
   }
   
   //retrace
   line(PCRX5,PCRY5,PCRX2,PCRY2);
   line(PCRX2,PCRY2,PCRX1,PCRY1);
   line(PCRX1,PCRY1,PCRX0,PCRY0);
   
     //move arms
 // pclx3b=pclx3b+1;
 // pcly5=pcly5+1;
  pcly4=pcly4+1;
  pclx4=pclx4-(PCC/20);
  
  pcly5=pcly5+1;
  pclx3b=pclx3b+(PCC/20);
  pclx5=pclx5+(PCC/20);
  
if(millis()>173000){
  break;
}
  
  }
  

  }
  
  if(millis()>173000 && millis()<175000){
     for(int PCC=1;255;PCC++){
        int PCLX0=10; //datum for left figure (left foot)
    int PCLY0=10;//y datum for left figure
    int PCRX0=120;//xdatum for right figure
    int PCRY0=10;//y datum for right figure
    
 //determine coordinates of left figure
    int PCLX1=PCLX0+pclx1;
     int PCLX2=PCLX0+pclx2;
       int PCLX3=PCLX0+pclx3;
       int PCLX3a=PCLX0+pclx3a;
       int PCLX3b=PCLX0+pclx3b;
     int PCLX4=PCLX0+pclx4;
     int PCLX5=PCLX0+pclx5;
     int PCLX6=PCLX0+pclx6;
   
   int PCLY1=PCLY0+pcly1;
   int PCLY2=PCLY0+pcly2;
   int PCLY3=PCLY0+pcly3;
   int PCLY3a=PCLY0+pcly3a;
   int PCLY3b=PCLY0+pcly3b;
   int PCLY4=PCLY0+pcly4;
   int PCLY5=PCLY0+pcly5;
   int PCLY6=PCLY0+pcly6;
   
   //plot left figure
   line(PCLX0,PCLY0,PCLX1,PCLY1);
   line(PCLX1,PCLY1,PCLX2,PCLY2);
    line(PCLX2,PCLY2,PCLX1,PCLY1);//leg retrace
   line(PCLX1,PCLY1,PCLX3,PCLY3);//body
   line(PCLX3,PCLY3,PCLX3a,PCLY3a);
   line(PCLX3a,PCLY3a,PCLX4,PCLY4);
   line(PCLX4,PCLY4,PCLX3a,PCLY3a);//arm retrace
   line(PCLX3a,PCLY3a,PCLX3,PCLY3);
   line(PCLX3,PCLY3,PCLX3b,PCLY3b);//arm
   line(PCLX3b,PCLY3b,PCLX5,PCLY5);
   line(PCLX5,PCLY5,PCLX3b,PCLY3b);//arm retrace
   line(PCLX3b,PCLY3b,PCLX3,PCLY3);
   
   //left figure head
   for(int lhc=0;lhc<256;lhc++){
   PORTA=0.1*sinTab[lhc]+phpx;//horizontal sin wave
  PORTB=0.1*sinTab[j++]+phpy;//vertical sin wave
  delayMicroseconds(8);
   }
   
   //retrace to ground
      line(PCLX3,PCLY3,PCLX1,PCLY1);
   line(PCLX1,PCLY1,PCLX2,PCLY2);
   
   
       //determine coordinates of right figure
    int PCRX1=PCRX0+pcrx1;
     int PCRX2=PCRX0+pcrx2;
       int PCRX3=PCRX0+pcrx3;
     int PCRX4=PCRX0+pcrx4;
     int PCRX5=PCRX0+pcrx5;
     int PCRX6=PCRX0+pcrx6;
      int PCRX7=PCRX0+pcrx7;
     int PCRX8=PCRX0+pcrx8;
     int PCRX9=PCRX0+pcrx9;
   
   int PCRY1=PCRY0+pcry1;
   int PCRY2=PCRY0+pcry2;
   int PCRY3=PCRY0+pcry3;
   int PCRY4=PCRY0+pcry4;
   int PCRY5=PCRY0+pcry5;
   int PCRY6=PCRY0+pcry6;
    int PCRY7=PCRY0+pcry7;
   int PCRY8=PCRY0+pcry8;
   int PCRY9=PCRY0+pcry9;
   
   
   //plot RIGHT figure
   line(PCRX0,PCRY0,PCRX1,PCRY1);
   line(PCRX1,PCRY1,PCRX2,PCRY2);
    line(PCRX2,PCRY2,PCRX3,PCRY3);
   line(PCRX3,PCRY3,PCRX4,PCRY4);
   line(PCRX4,PCRY4,PCRX3,PCRY3);//leg retrace to knee
    line(PCRX3,PCRY3,PCRX2,PCRY2);//leg retrace to body
   line(PCRX2,PCRY2,PCRX5,PCRY5);//body
    line(PCRX5,PCRY5,PCRX6,PCRY6);
     line(PCRX6,PCRY6,PCRX7,PCRY7);
    line(PCRX7,PCRY7,PCRX6,PCRY6);//retrace to elbow
     line(PCRX6,PCRY6,PCRX5,PCRY5);//retrace to body
      line(PCRX5,PCRY5,PCRX8,PCRY8);
       line(PCRX8,PCRY8,PCRX9,PCRY9);
     line(PCRX9,PCRY9,PCRX8,PCRY8);//retrace to elbow
      line(PCRX8,PCRY8,PCRX5,PCRY5);
   
   //right figure head
   for(int rhc=0;rhc<256;rhc++){
   PORTA=0.1*sinTab[rhc]+phprx;//horizontal sin wave
  PORTB=0.1*sinTab[j++]+phpry;//vertical sin wave
  delayMicroseconds(8);
   }
   
   //retrace
   line(PCRX5,PCRY5,PCRX2,PCRY2);
   line(PCRX2,PCRY2,PCRX1,PCRY1);
   line(PCRX1,PCRY1,PCRX0,PCRY0);
   
   if(millis()>175000){
     break;
   }
     }
  }
  
  
  
  if(millis()>175000 && millis()<178000){
         for(int PCC=1;255;PCC++){
        int PCLX0=10; //datum for left figure (left foot)
    int PCLY0=10;//y datum for left figure
    int PCRX0=120;//xdatum for right figure
    int PCRY0=10;//y datum for right figure
    
 //determine coordinates of left figure
    int PCLX1=PCLX0+pclx1;
     int PCLX2=PCLX0+pclx2;
       int PCLX3=PCLX0+pclx3;
       int PCLX3a=PCLX0+pclx3a;
       int PCLX3b=PCLX0+pclx3b;
     int PCLX4=PCLX0+pclx4;
     int PCLX5=PCLX0+pclx5;
     int PCLX6=PCLX0+pclx6;
   
   int PCLY1=PCLY0+pcly1;
   int PCLY2=PCLY0+pcly2;
   int PCLY3=PCLY0+pcly3;
   int PCLY3a=PCLY0+pcly3a;
   int PCLY3b=PCLY0+pcly3b;
   int PCLY4=PCLY0+pcly4;
   int PCLY5=PCLY0+pcly5;
   int PCLY6=PCLY0+pcly6;
   
   //plot left figure
   line(PCLX0,PCLY0,PCLX1,PCLY1);
   line(PCLX1,PCLY1,PCLX2,PCLY2);
    line(PCLX2,PCLY2,PCLX1,PCLY1);//leg retrace
   line(PCLX1,PCLY1,PCLX3,PCLY3);//body
   line(PCLX3,PCLY3,PCLX3a,PCLY3a);
   line(PCLX3a,PCLY3a,PCLX4,PCLY4);
   line(PCLX4,PCLY4,PCLX3a,PCLY3a);//arm retrace
   line(PCLX3a,PCLY3a,PCLX3,PCLY3);
   line(PCLX3,PCLY3,PCLX3b,PCLY3b);//arm
   line(PCLX3b,PCLY3b,PCLX5,PCLY5);
   line(PCLX5,PCLY5,PCLX3b,PCLY3b);//arm retrace
   line(PCLX3b,PCLY3b,PCLX3,PCLY3);
   
   //left figure head
   for(int lhc=0;lhc<256;lhc++){
   PORTA=0.1*sinTab[lhc]+phpx;//horizontal sin wave
  PORTB=0.1*sinTab[j++]+phpy;//vertical sin wave
  delayMicroseconds(8);
   }
   
   //speech bubble
   
      for(int lhc2=0;lhc2<256;lhc2++){
   PORTA=0.45*sinTab[lhc2]+phpx-20;//horizontal sin wave
  PORTB=0.25*sinTab[j++]+phpy+45;//vertical sin wave
  delayMicroseconds(8);
   }
   
   //writing
   line(100,180,100,205);//Y
   line(100,205,115,220);
   line(115,220,100,205);
   line(100,205,85,225);
   line(75,215,75,190);//E
   line(75,190,60,190);
   line(60,190,75,190);
   line(75,190,75,202);
   line(75,202,60,202);
   line(60,202,75,202);
   line(75,202,75,215);
   line(75,215,60,215);
   line(30,215,60,215);//S
   line(60,215,60,200);
   line(60,200,30,200);
   line(30,200,30,190);
   line(30,190,60,190);
   
   //retrace to ground
      line(PCLX3,PCLY3,PCLX1,PCLY1);
   line(PCLX1,PCLY1,PCLX2,PCLY2);
   
   
       //determine coordinates of right figure
    int PCRX1=PCRX0+pcrx1;
     int PCRX2=PCRX0+pcrx2;
       int PCRX3=PCRX0+pcrx3;
     int PCRX4=PCRX0+pcrx4;
     int PCRX5=PCRX0+pcrx5;
     int PCRX6=PCRX0+pcrx6;
      int PCRX7=PCRX0+pcrx7;
     int PCRX8=PCRX0+pcrx8;
     int PCRX9=PCRX0+pcrx9;
   
   int PCRY1=PCRY0+pcry1;
   int PCRY2=PCRY0+pcry2;
   int PCRY3=PCRY0+pcry3;
   int PCRY4=PCRY0+pcry4;
   int PCRY5=PCRY0+pcry5;
   int PCRY6=PCRY0+pcry6;
    int PCRY7=PCRY0+pcry7;
   int PCRY8=PCRY0+pcry8;
   int PCRY9=PCRY0+pcry9;
   
   
   //plot RIGHT figure
   line(PCRX0,PCRY0,PCRX1,PCRY1);
   line(PCRX1,PCRY1,PCRX2,PCRY2);
    line(PCRX2,PCRY2,PCRX3,PCRY3);
   line(PCRX3,PCRY3,PCRX4,PCRY4);
   line(PCRX4,PCRY4,PCRX3,PCRY3);//leg retrace to knee
    line(PCRX3,PCRY3,PCRX2,PCRY2);//leg retrace to body
   line(PCRX2,PCRY2,PCRX5,PCRY5);//body
    line(PCRX5,PCRY5,PCRX6,PCRY6);
     line(PCRX6,PCRY6,PCRX7,PCRY7);
    line(PCRX7,PCRY7,PCRX6,PCRY6);//retrace to elbow
     line(PCRX6,PCRY6,PCRX5,PCRY5);//retrace to body
      line(PCRX5,PCRY5,PCRX8,PCRY8);
       line(PCRX8,PCRY8,PCRX9,PCRY9);
     line(PCRX9,PCRY9,PCRX8,PCRY8);//retrace to elbow
      line(PCRX8,PCRY8,PCRX5,PCRY5);
   
   //right figure head
   for(int rhc=0;rhc<256;rhc++){
   PORTA=0.1*sinTab[rhc]+phprx;//horizontal sin wave
  PORTB=0.1*sinTab[j++]+phpry;//vertical sin wave
  delayMicroseconds(8);
   }
   
   //retrace
   line(PCRX5,PCRY5,PCRX2,PCRY2);
   line(PCRX2,PCRY2,PCRX1,PCRY1);
   line(PCRX1,PCRY1,PCRX0,PCRY0);
   
   if(millis()>178000){
     break;
   }
     }
  }
  
 if(millis()>178000 && millis()<184000){
            for(int PCC=1;255;PCC++){
        int PCLX0=10; //datum for left figure (left foot)
    int PCLY0=10;//y datum for left figure
    int PCRX0=120;//xdatum for right figure
    int PCRY0=10;//y datum for right figure
    
 //determine coordinates of left figure
    int PCLX1=PCLX0+pclx1;
     int PCLX2=PCLX0+pclx2;
       int PCLX3=PCLX0+pclx3;
       int PCLX3a=PCLX0+pclx3a;
       int PCLX3b=PCLX0+pclx3b;
     int PCLX4=PCLX0+pclx4;
     int PCLX5=PCLX0+pclx5;
     int PCLX6=PCLX0+pclx6;
   
   int PCLY1=PCLY0+pcly1;
   int PCLY2=PCLY0+pcly2;
   int PCLY3=PCLY0+pcly3;
   int PCLY3a=PCLY0+pcly3a;
   int PCLY3b=PCLY0+pcly3b;
   int PCLY4=PCLY0+pcly4;
   int PCLY5=PCLY0+pcly5;
   int PCLY6=PCLY0+pcly6;
   
   //plot left figure
   line(PCLX0,PCLY0,PCLX1,PCLY1);
   line(PCLX1,PCLY1,PCLX2,PCLY2);
    line(PCLX2,PCLY2,PCLX1,PCLY1);//leg retrace
   line(PCLX1,PCLY1,PCLX3,PCLY3);//body
   line(PCLX3,PCLY3,PCLX3a,PCLY3a);
   line(PCLX3a,PCLY3a,PCLX4,PCLY4);
   line(PCLX4,PCLY4,PCLX3a,PCLY3a);//arm retrace
   line(PCLX3a,PCLY3a,PCLX3,PCLY3);
   line(PCLX3,PCLY3,PCLX3b,PCLY3b);//arm
   line(PCLX3b,PCLY3b,PCLX5,PCLY5);
   line(PCLX5,PCLY5,PCLX3b,PCLY3b);//arm retrace
   line(PCLX3b,PCLY3b,PCLX3,PCLY3);
   
   //left figure head
   for(int lhc=0;lhc<256;lhc++){
   PORTA=0.1*sinTab[lhc]+phpx;//horizontal sin wave
  PORTB=0.1*sinTab[j++]+phpy;//vertical sin wave
  delayMicroseconds(8);
   }
   
   //speech bubble
   
      for(int lhc2=0;lhc2<256;lhc2++){
   PORTA=0.45*sinTab[lhc2]+phpx-20;//horizontal sin wave
  PORTB=0.25*sinTab[j++]+phpy+45;//vertical sin wave
  delayMicroseconds(8);
   }
   
   //writing
   line(100,180,100,205);//Y
   line(100,205,115,220);
   line(115,220,100,205);
   line(100,205,85,225);
   line(75,215,75,190);//E
   line(75,190,60,190);
   line(60,190,75,190);
   line(75,190,75,202);
   line(75,202,60,202);
   line(60,202,75,202);
   line(75,202,75,215);
   line(75,215,60,215);
   line(30,215,60,215);//S
   line(60,215,60,200);
   line(60,200,30,200);
   line(30,200,30,190);
   line(30,190,60,190);
   
   //retrace to ground
      line(PCLX3,PCLY3,PCLX1,PCLY1);
   line(PCLX1,PCLY1,PCLX2,PCLY2);
   
   
       //determine coordinates of right figure
    int PCRX1=PCRX0+pcrx1;
     int PCRX2=PCRX0+pcrx2;
       int PCRX3=PCRX0+pcrx3;
     int PCRX4=PCRX0+pcrx4;
     int PCRX5=PCRX0+pcrx5;
     int PCRX6=PCRX0+pcrx6;
      int PCRX7=PCRX0+pcrx7;
     int PCRX8=PCRX0+pcrx8;
     int PCRX9=PCRX0+pcrx9-10;
   
   int PCRY1=PCRY0+pcry1;
   int PCRY2=PCRY0+pcry2;
   int PCRY3=PCRY0+pcry3;
   int PCRY4=PCRY0+pcry4;
   int PCRY5=PCRY0+pcry5;
   int PCRY6=PCRY0+pcry6;
    int PCRY7=PCRY0+pcry7+50;
   int PCRY8=PCRY0+pcry8;
   int PCRY9=PCRY0+pcry9+50;
   
   
   //plot RIGHT figure
   line(PCRX0,PCRY0,PCRX1,PCRY1);
   line(PCRX1,PCRY1,PCRX2,PCRY2);
    line(PCRX2,PCRY2,PCRX3,PCRY3);
   line(PCRX3,PCRY3,PCRX4,PCRY4);
   line(PCRX4,PCRY4,PCRX3,PCRY3);//leg retrace to knee
    line(PCRX3,PCRY3,PCRX2,PCRY2);//leg retrace to body
   line(PCRX2,PCRY2,PCRX5,PCRY5);//body
    line(PCRX5,PCRY5,PCRX7,PCRY7);//arm
     line(PCRX7,PCRY7,PCRX5,PCRY5);//retrace to body
      line(PCRX5,PCRY5,PCRX9,PCRY9);
     line(PCRX9,PCRY9,PCRX5,PCRY5);//retrace
   
   //right figure head
   for(int rhc=0;rhc<256;rhc++){
   PORTA=0.1*sinTab[rhc]+phprx;//horizontal sin wave
  PORTB=0.1*sinTab[j++]+phpry;//vertical sin wave
  delayMicroseconds(8);
   }
   
   //retrace
   line(PCRX5,PCRY5,PCRX2,PCRY2);
   line(PCRX2,PCRY2,PCRX1,PCRY1);
   line(PCRX1,PCRY1,PCRX0,PCRY0);
   
if(millis()>184000){
  break;
}
     }
 }





//INDIA
if(millis()>184000  && millis()<195000){
  
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
    
  
  
  
//FIREWORKS

if(millis()>195000 && millis()<205000){
    
  digitalWrite(8,HIGH);
    //FIREWORK 1
  for(int FWC=250;FWC>1;FWC--){//OUTER COUNTER TO DETERMINE MOVEMENT
   for(int FW=250;FW>FWC;FW--){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=210-0.8*parabola[FW];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=0.5*FW+100;//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
  
  }
  
  //LEG 1
  for(int EXC=250;EXC>0;EXC--){//OUTER COUNTER TO DETERMINE MOVEMENT
   for(int EX1=250;EX1>EXC;EX1){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=190+0.2*full_parabola[EX1];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=(0.2*EX1)+50;//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    EX1=EX1-4;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
  
  //LEG 2
     for(int EX2=250;EX2>EXC;EX2){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=190+0.2*full_parabola[EX2];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=-(0.2*EX2)+145;//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    EX2=EX2-4;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
   
   //LEG 3
        for(int EX3=250;EX3>EXC;EX3){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=190+0.2*full_parabola[EX3];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=(95);//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    EX3=EX3-4;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
   
  //LEG 4
     for(int EX4=150;EX4>EXC;EX4){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=160+0.2*full_parabola[EX4];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=-(0.3*EX4)+145;//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    EX4=EX4-3;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
   
   //LEG 5
     for(int EX5=150;EX5>EXC;EX5){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=160+0.2*full_parabola[EX5];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=(0.3*EX5)+40;//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    EX5=EX5-3;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }

  }

  
    //FIREWORK 2
    for(int FWC2=250;FWC2>1;FWC2--){
   for(int FW2=250;FW2>FWC2;FW2--){  //parabola takes one rotation to get to full extent as it's length is determined by k
    PORTB=180-0.75*parabola[FW2];
    PORTA=-0.5*FW2-130;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
  }
  
  //LEG 1
  for(int EXC=250;EXC>0;EXC--){//OUTER COUNTER TO DETERMINE MOVEMENT
   for(int EX1=250;EX1>EXC;EX1){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=190+0.2*full_parabola[EX1];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=(0.2*EX1)+80;//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    EX1=EX1-4;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
  
  //LEG 2
     for(int EX2=250;EX2>EXC;EX2){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=190+0.2*full_parabola[EX2];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=-(0.2*EX2)+175;//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    EX2=EX2-4;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
   
   //LEG 3
        for(int EX3=250;EX3>EXC;EX3){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=190+0.2*full_parabola[EX3];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=(125);//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    EX3=EX3-4;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
   
  //LEG 4
     for(int EX4=150;EX4>EXC;EX4){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=160+0.2*full_parabola[EX4];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=-(0.3*EX4)+170;//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    EX4=EX4-3;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
   
   //LEG 5
     for(int EX5=150;EX5>EXC;EX5){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=160+0.2*full_parabola[EX5];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=(0.3*EX5)+85;//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    EX5=EX5-3;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }

  }
  
  
    //FIREWORK 3
    for(int FWC2=250;FWC2>1;FWC2--){
   for(int FW2=250;FW2>FWC2;FW2--){  //parabola takes one rotation to get to full extent as it's length is determined by k
    PORTB=180-0.55*parabola[FW2];
    PORTA=-0.5*FW2-120;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
  }
  
  //LEG 1
  for(int EXC=250;EXC>0;EXC--){//OUTER COUNTER TO DETERMINE MOVEMENT
   for(int EX1=250;EX1>EXC;EX1){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=160+0.2*full_parabola[EX1];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=(0.2*EX1)+80;//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    EX1=EX1-4;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
  
  //LEG 2
     for(int EX2=250;EX2>EXC;EX2){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=160+0.2*full_parabola[EX2];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=-(0.2*EX2)+175;//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    EX2=EX2-4;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
   
   //LEG 3
        for(int EX3=250;EX3>EXC;EX3){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=160+0.2*full_parabola[EX3];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=(125);//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    EX3=EX3-4;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
   
  //LEG 4
     for(int EX4=150;EX4>EXC;EX4){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=130+0.2*full_parabola[EX4];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=-(0.3*EX4)+170;//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    EX4=EX4-3;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
   
   //LEG 5
     for(int EX5=150;EX5>EXC;EX5){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=130+0.2*full_parabola[EX5];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=(0.3*EX5)+85;//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    EX5=EX5-3;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }

  }
  
      //FIREWORK 4
    for(int FWC2=250;FWC2>1;FWC2--){
   for(int FW2=250;FW2>FWC2;FW2--){  //parabola takes one rotation to get to full extent as it's length is determined by k
    PORTB=220-0.9*parabola[FW2];
    PORTA=0.3*FW2+100;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
  }
  
  //LEG 1
  for(int EXC=250;EXC>0;EXC--){//OUTER COUNTER TO DETERMINE MOVEMENT
   for(int EX1=250;EX1>EXC;EX1){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=190+0.2*full_parabola[EX1];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=(0.2*EX1)+60;//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    EX1=EX1-4;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
  
  //LEG 2
     for(int EX2=250;EX2>EXC;EX2){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=190+0.2*full_parabola[EX2];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=-(0.2*EX2)+155;//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    EX2=EX2-4;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
   
   //LEG 3
        for(int EX3=250;EX3>EXC;EX3){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=190+0.2*full_parabola[EX3];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=(105);//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    EX3=EX3-4;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
   
  //LEG 4
     for(int EX4=150;EX4>EXC;EX4){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=160+0.2*full_parabola[EX4];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=-(0.3*EX4)+150;//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    EX4=EX4-3;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
   
   //LEG 5
     for(int EX5=150;EX5>EXC;EX5){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=160+0.2*full_parabola[EX5];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=(0.3*EX5)+65;//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    EX5=EX5-3;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }

  }
  
    
        //FIREWORK 5 (DOUBLE LAUNCH)
    for(int FWC2=250;FWC2>1;FWC2--){
   
      for(int FW2=250;FW2>FWC2;FW2--){  //parabola takes one rotation to get to full extent as it's length is determined by k
    PORTB=220-0.9*parabola[FW2];
    PORTA=0.3*FW2+100;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
   
   
   //FIREWORK 6 (DOUBLE LAUNCH)
     for(int FW3=250;FW3>FWC2;FW3--){  //parabola takes one rotation to get to full extent as it's length is determined by k
    PORTB=220-0.9*parabola[FW3];
    PORTA=-0.3*FW3-100;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
   
  }

  
  //LEG 1
  
  for(int EXC=250;EXC>0;EXC--){//OUTER COUNTER TO DETERMINE MOVEMENT
   for(int EX1=250;EX1>EXC;EX1){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=200+0.2*full_parabola[EX1];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=(0.2*EX1)+110;//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    EX1=EX1-4;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
   
      for(int EX1=250;EX1>EXC;EX1){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=190+0.2*full_parabola[EX1];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=(0.2*EX1)+60;//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    EX1=EX1-4;
    delayMicroseconds(20);//speed of parabola - may need adjusting
    
   }
  
  //LEG 2
     for(int EX2=250;EX2>EXC;EX2){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=200+0.2*full_parabola[EX2];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=-(0.2*EX2)+205;//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    EX2=EX2-4;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
   
        for(int EX2=250;EX2>EXC;EX2){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=190+0.2*full_parabola[EX2];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=-(0.2*EX2)+155;//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    EX2=EX2-4;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
   
   //LEG 3
        for(int EX3=250;EX3>EXC;EX3){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=200+0.2*full_parabola[EX3];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=(155);//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    EX3=EX3-4;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
   
   
           for(int EX3=250;EX3>EXC;EX3){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=190+0.2*full_parabola[EX3];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=(105);//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    EX3=EX3-4;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
   
  //LEG 4
     for(int EX4=150;EX4>EXC;EX4){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=170+0.2*full_parabola[EX4];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=-(0.3*EX4)+200;//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    EX4=EX4-3;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
   
       for(int EX4=150;EX4>EXC;EX4){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=160+0.2*full_parabola[EX4];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=-(0.3*EX4)+150;//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    EX4=EX4-3;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
   
   //LEG 5
     for(int EX5=150;EX5>EXC;EX5){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=170+0.2*full_parabola[EX5];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=(0.3*EX5)+105;//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    EX5=EX5-3;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }
   
        for(int EX5=150;EX5>EXC;EX5){  //INNER COUNTER TO DETERMINE PARABOLA SHAPE/SIZE
    PORTB=160+0.2*full_parabola[EX5];//MULTIPLE DETERMINES HEIGHT, INTEGER DETERMINES POSITION
    PORTA=(0.3*EX5)+65;//MULTIPLE DETERMINES WIDTH. SIGN DETERMINES DIRECTION
    EX5=EX5-3;
    delayMicroseconds(20);//speed of parabola - may need adjusting
   }

  }
}
  
  
  
  //New horizons image
  if(millis()>205000 && millis()<220000){
      
  //front side
for (int NHPC=1;NHPC<628;NHPC){

  //probe FRONT moving coordinates
  int Pxar=Pxa*cos(0.01*NHPC);//cos function rotates
int Pxbr=Pxb*cos(0.01*NHPC);
int Pxcr=Pxc*cos(0.01*NHPC);
int Pxdr=Pxd*cos(0.01*NHPC);
int Pxer=Pxe*cos(0.01*NHPC);
int Pxear=Pxea*cos(0.01*NHPC);
int Pxfr=Pxf*cos(0.01*NHPC);
int Pxgr=Pxg*cos(0.01*NHPC);
int Pxhr=Pxh*cos(0.01*NHPC);
int Pxir=Pxi*cos(0.01*NHPC);

//probe REAR moving x coordinates



//x coordinates after rotation
int Px1=120;//centrepoint
int Px1ar=Px1+Pxar;//starting point on probe
int Px2r=Px1+Pxbr;
int Px3r=Px1+Pxcr;
int Px4r=Px1+Pxdr;
int Px5r=Px1+Pxer;
int Px5ar=Px1+Pxear;
int Px6r=Px1+Pxfr;
int Px7r=Px1+Pxgr;
int Px8r=Px1+Pxhr;
int Px9r=Px1+Pxir;

//x coordinates of rear after rotation
int Px1arr=Px1+PBD*sin(0.01*NHPC);//addition varies x position of rear relative to front to simulate rotation
int Px2rr=Px2r+PBD*sin(0.01*NHPC);
int Px3rr=Px3r+PBD*sin(0.01*NHPC);
int Px4rr=Px4r+PBD*sin(0.01*NHPC);
int Px5rr=Px5r+PBD*sin(0.01*NHPC);
int Px5arr=Px5ar+PBD*sin(0.01*NHPC);
int Px6rr=Px6r+PBD*sin(0.01*NHPC);
int Px7rr=Px7r+PBD*sin(0.01*NHPC);
int Px8rr=Px8r+PBD*sin(0.01*NHPC);
int Px9rr=Px9r+PBD*sin(0.01*NHPC);

  
  //plot probe front
  
line(Px1ar,180,Px2r,180);//top line - go clockwise from here//HORIZONTAL
line(Px2r,180,Px3r,230);//left upright on RTG//VERTICAL
line(Px3r,230,Px4r,230);//HORIZONTAL
line(Px4r,230,Px5ar,180);//VERTICAL
line(Px5r,180,Px6r,120);//INCLINED
line(Px6r,90,Px7r,120);//VERTICAL
line(Px7r,90,Px8r,90);//bottom line//HORIZONTAL
line(Px8r,90,Px9r,120);//VERTICAL
line(Px9r,120,Px1ar,180);//INCLINED


//plot probe rear
line(Px1arr,180,Px2rr,180);//top line - go clockwise from here//HORIZONTAL
line(Px2rr,180,Px3rr,230);//left upright on RTG//VERTICAL
line(Px3rr,230,Px4rr,230);//HORIZONTAL
line(Px4rr,230,Px5arr,180);//VERTICAL
line(Px5rr,180,Px6rr,120);//INCLINED
line(Px6rr,90,Px7rr,120);//VERTICAL
line(Px7rr,90,Px8rr,90);//bottom line//HORIZONTAL
line(Px8rr,90,Px9rr,120);//VERTICAL
line(Px9rr,120,Px1arr,180);//INCLINED

//PLOT DIAGONALS
line(Px1ar,180,Px1arr,180);
line(Px2r,180,Px2rr,180);
line(Px3r,230,Px2rr,230);
line(Px4r,230,Px2rr,230);
line(Px5r,180,Px5rr,180);
line(Px6r,90,Px6rr,90);
line(Px7r,90,Px7rr,90);
line(Px8r,90,Px8rr,90);
line(Px9r,120,Px9rr,120);

    for(int i=0;i<256;i++){
    PORTA=(0.35*cos(0.01*NHPC)*sinTab[i])+((1-(0.35*cos(0.01*NHPC)))*128)-10;//horizontal sin wave
  PORTB=0.35*sinTab[j++]+90;//vertical sin wave
  delayMicroseconds(20);//delay between points
  }

NHPC=NHPC+4;

}

}
  
  
  
  //PLUTO FLYBY
  if(millis()>220000 && millis()<234000){
     for(int PLCH=1;PLCH<255;PLCH++){
  digitalWrite(8,HIGH);
  //pluto
  for(int i=0;i<256;i++){
    PORTA=0.5*sinTab[i]+125;//horizontal sin wave
  PORTB=0.5*sinTab[j++]+60;//vertical sin wave
  delayMicroseconds(8);//delay between points
    }
  
 /* //pluto equator  
     for(int i=0;i<256;i++){
    PORTA=0.48*sinTab[i]+125;//horizontal sin wave
  PORTB=0.05*sinTab[j++]+120;//vertical sin wave
  delayMicroseconds(20);//delay between points
    }*/
   
   //pluto meridian
        for(int i=0;i<256;i++){
    PORTA=0.08*sinTab[i]+175;//horizontal sin wave
  PORTB=0.5*sinTab[j++]+63;//vertical sin wave
  delayMicroseconds(8);//delay between points
    }
    
     //pluto longditude lines
        for(int i=0;i<256;i++){
    PORTA=0.3*sinTab[i]+145;//horizontal sin wave
  PORTB=0.5*sinTab[j++]+63;//vertical sin wave
  delayMicroseconds(8);//delay between points
    }
   
   
   //charon 
   for(int i=0;i<256;i++){
    PORTA=0.25*sinTab[i];//horizontal sin wave
  PORTB=0.25*sinTab[j++]+160;//vertical sin wave
  delayMicroseconds(8);//delay between points
    }
    
    //charon equator
       for(int i=0;i<256;i++){
    PORTA=0.25*sinTab[i]+3;//horizontal sin wave
  PORTB=0.05*sinTab[j++]+185;//vertical sin wave
  delayMicroseconds(8);//delay between points
    }
    
       //PROBE   
   for(int PCFB=1;PCFB<255;PCFB++){
   PORTA=0.02*sinTab[PCFB]+PLCH;//horizontal sin wave
  PORTB=0.02*sinTab[R++]+100;//vertical sin wave
  delayMicroseconds(8);
   }
     }
}
 




//FLYBY2

if (millis()>234000 && millis()<250000){
  
   
  for(int PFC=1;PFC<255;PFC++){//probeflyby counter
  
  //draw mountain
 // line(10,20,40,30);
  //line(40,30,30,20);
  //line(30,20,70,40);
  line(70,40,40,30);
  line(40,30,50,70);
  line(50,70,80,90);
  line(80,90,120,60);//4-13
  line(120,60,70,40);//13-14
  line(70,40,50,70);//line 14-3
  line(50,70,120,60);//3-13
  line(120,60,130,95);//13-16
  line(130,95,80,90);//16-4
  line(80,90,100,160);//4-5
  line(100,160,130,150);//5-6
  line(130,150,80,90);//6-4
  line(80,90,130,95);//4-16
  line(130,95,130,150);//16-6
  line(130,150,200,60);//6-8
  line(200,60,150,10);//8-12
  line(150,10,210,30);//12-11
  line(210,30,200,60);//11-8
  line(200,60,170,130);//8-7
  line(170,130,130,150);//7-6
  line(130,150,130,95);//6-16
  line(130,95,200,60);//16-8
  line(200,60,220,70);//8-9
  line(220,70,210,30);//9-11
  line(210,30,220,70);//11-9
  line(220,70,250,40);//9-10
  line(250,40,210,30);//10-11
  line(210,30,150,10);//11-12
  line(150,10,130,95);//12-16
  line(130,95,120,60);//16-13
  line(120,60,150,10);//13-12
  line(150,10,75,30);//12-15
  line(75,30,30,20);//12-15
  
   
   //PROBE   
   for(int PFBC=1;PFBC<255;PFBC++){
   PORTA=0.02*sinTab[PFBC]+PFC;//horizontal sin wave
  PORTB=0.02*sinTab[j++]+200;//vertical sin wave
  delayMicroseconds(8);
   }
  }
}

}

