
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



float AH=1;//Circle height(0 to 1)
unsigned char j=64;

  float Wmx0 = 128;
  float Wmx1=128;
  float Wmy0 =80;
  float Wmy1=240;
  
  float x=128;
  float y=128;

void loop() {


for (int Cc=0;Cc<628;Cc++){

  //blade 1
  int X1=0.7*x*(1+sin(0.01*Cc))+32;
  int Y1=0.7*y*(1+cos(0.01*Cc))+70;
  int X2=0.7*x*(1+sin(0.01*Cc+3.14))+32;
  int Y2=0.7*y*(1+cos(0.01*Cc+3.14))+70;
  
  //blade 2
  int X3=0.7*x*(1+sin((0.01*Cc)+1.56))+32;//1.56 is the phase difference (ie pi/2)
  int Y3=0.7*y*(1+cos((0.01*Cc)+1.56))+70;
  int X4=0.7*x*(1+sin((0.01*Cc+1.56)+3.14))+32;
  int Y4=0.7*y*(1+cos((0.01*Cc+1.56)+3.14))+70;
 
 
line(X1,Y1,X2,Y2);//blade 1
line(X3,Y3,X4,Y4);//blade 2


//tower
line(80,50,100,200);
line(100,200,156,200);
line(156,200,176,60);

//bike 1

//int b1Sx=0; //bike 1 horizontal displacement


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




int b21x=80;//bike 1 x coordinates
int b22x=110;
int b23x=110;
int b24x=80;
int b25x=110;
int b26x=140;
int b27x=110;
int b28x=140;
int b29x=105;
int b210x=110;

int b21y=15;//bike 1 y coordinates
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
  delayMicroseconds(40);
  
}

}
