void setup() {
  DDRA=255;
  DDRB=255;
  
}

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

void loop() {
  for(int F=1;F<180;F++){
  for(int G=F;G>1;G--){
    PORTA=-2*parabola[G];
    PORTB=G;
    delayMicroseconds(8);
  }
  delay(10);
  }
  
    

}