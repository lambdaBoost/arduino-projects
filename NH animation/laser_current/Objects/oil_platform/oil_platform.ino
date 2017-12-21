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

void loop() {
  
  
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

}
}
