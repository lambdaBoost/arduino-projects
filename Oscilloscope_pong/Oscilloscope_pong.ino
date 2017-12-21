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

void zeroright(){
  line(108,250,126,250);
  line(126,250,126,225);
  line(126,225,108,225);
  line(108,225,108,250);
}

void oneright(){
  line(116,250,116,225);
}

void tworight(){
  line(108,250,126,250);
  line(126,250,126,237);
  line(126,237,108,237);
  line(108,237,108,225);
  line(108,225,128,225);
}

void threeright(){
  line(108,250,126,250);
  line(126,250,126,237);
  line(126,237,108,237);
  line(108,237,126,237);
  line(126,237,126,225);
  line(126,225,108,225);
}

void fourright(){
  line(116,225,116,250);
  line(116,250,108,237);
  line(108,237,126,237);
}

void fiveright(){
  line(126,250,108,250);
  line(108,250,108,237);
  line(108,237,126,237);
  line(126,237,126,225);
  line(126,225,108,225);
}

void sixright(){
  line(108,237,126,237);
  line(126,237,126,225);
  line(126,225,108,225);
  line(108,225,108,250);
  line(108,250,126,250);
}

void sevenright(){
  line(108,250,126,250);
  line(126,250,108,225);
}

void eightright(){
  line(108,250,126,250);
  line(126,250,126,225);
  line(126,225,108,225);
  line(108,225,108,250);
  line(108,250,108,237);
  line(108,237,126,237);
}

void nineright(){
  line(108,225,126,225);
  line(126,225,126,250);
  line(126,250,108,250);
  line(108,250,108,237);
  line(108,237,126,237);
  
}

void zeroleft(){
  line(130,250,148,250);
  line(148,250,148,225);
  line(148,225,130,225);
  line(130,225,130,250);
}

void oneleft(){
  line(140,250,140,225);
}

void twoleft(){
  line(130,250,148,250);
  line(148,250,148,237);
  line(148,237,130,237);
  line(130,237,130,225);
  line(130,225,148,225);
}

void threeleft(){
  line(130,250,148,250);
  line(148,250,148,237);
  line(148,237,130,237);
  line(130,237,148,237);
  line(148,237,148,225);
  line(148,225,130,225);
}

void fourleft(){
  line(138,225,138,250);
  line(138,250,130,237);
  line(130,237,148,237);
}

void fiveleft(){
  line(148,250,130,250);
  line(130,250,130,237);
  line(130,237,148,237);
  line(148,237,148,225);
  line(148,225,130,225);
}

void sixleft(){
  line(130,237,148,237);
  line(148,237,148,225);
  line(148,225,130,225);
  line(130,225,130,250);
  line(130,250,148,250);
}

void sevenleft(){
  line(130,250,148,250);
  line(148,250,130,225);
}

void eightleft(){
  line(130,250,148,250);
  line(148,250,148,225);
  line(148,225,130,225);
  line(130,225,130,250);
  line(130,250,130,237);
  line(130,237,148,237);
}

void nineleft(){
  line(130,225,148,225);
  line(148,225,148,250);
  line(148,250,130,250);
  line(130,250,130,237);
  line(130,237,148,237);
  
}

//declare variables

int Lc=128; //centre of left paddle


int Rc=128; //centre of right paddle


int Bx=128; //ball x coordinate
int By=128; //ball y coordinate
float Bvy=0.2;// ball vertical speed
float Bvx=4; //ball horizontal speed

//paddle velocities
int Lv=3;
int Rv=3;

//Score
int LS=0; //left score
int RS=0; //right score

void loop(){



//determine paddle coordinates
int Lt=Lc+16; //top of left paddle
int Lb=Lc-16; //bottom of left paddle
int Rt=Rc+16; //top of right paddle
int Rb=Rc-16; //bottom of right paddle
  
//DELETE THIS - puts paddles in auto mode
Lc=Lc+Lv;
Rc=Rc-Rv;

if(Lc+16>252){
  Lv=Lv*-1;
}

if(Lc-16<2){
  Lv=Lv*-1;
}

if(Rc+16>252){
  Rv=Rv*-1;
}

if(Rc-16<2){
  Rv=Rv*-1;
}

//plot box and paddles
//left side
line(0,0,0,Lb);
line(5,Lb,5,Lt);
line(0,Lt,0,255);

//top
line(0,255,255,255);

//right side
line(255,255,255,Rt);
line(250,Rt,250,Rb);
line(255,Rb,255,0);

//bottom
line(255,0,128,0);

//centreline
line(128,0,128,8);
line(128,16,128,24);
line(128,32,128,40);
line(128,48,128,56);
line(128,64,128,72);
line(128,80,128,88);
line(128,96,128,104);
line(128,112,128,120);
line(128,128,128,136);
line(128,144,128,152);
line(128,160,128,168);
line(128,176,128,184);
line(128,192,128,200);
line(128,208,128,216);
line(128,224,128,232);
line(128,240,128,248);

//bottom
line(128,0,0,0);

//plot ball
line(Bx-1,By-1,Bx+1,By-1);
line(Bx+1,By-1, Bx+1, By+1);
line(Bx+1,By+1,Bx-1,By+1);
line(Bx-1,By+1,Bx-1,By-1);

Bx=Bx+Bvx;
By=By+Bvy;

//bounce off right wall if paddle  present
if(Bx>250 & By<=Rt & By>=(Rc+12)){
  Bvx=-1*Bvx;
  Bvy=Bvy+4;
}

if(Bx>250 & By<(Rc+12) & By>=(Rc+8)){
  Bvx=-1*Bvx;
  Bvy=Bvy+3;
}

if(Bx>250 & By<(Rc+8) & By>=(Rc+4)){
  Bvx=-1*Bvx;
  Bvy=Bvy+2;
}

if(Bx>250 & By<(Rc+4) & By>=(Rc)){
  Bvx=-1*Bvx;
  Bvy=Bvy+1;
}

if(Bx>250 & By<(Rc) & By>=(Rc-4)){
  Bvx=-1*Bvx;
  Bvy=Bvy-1;
}

if(Bx>250 & By<(Rc-4) & By>=(Rc-8)){
  Bvx=-1*Bvx;
  Bvy=Bvy-2;
}

if(Bx>250 & By<(Rc-8) & By>=(Rc-12)){
  Bvx=-1*Bvx;
  Bvy=Bvy-3;
}

if(Bx>250 & By<(Rc-12) & By>=(Rc-16)){
  Bvx=-1*Bvx;
  Bvy=Bvy-4;
}

//return to centre if right paddle not present
if(Bx>250 & (By>Rt || By<Rb)){
  Bx=128;
  By=128;
  Bvy=random(-2,2); //assign random vertical speed to serve
  RS=RS+1; //right score +1
}

//bounce off left wall if paddle  present
if(Bx<5 & By<=Lt & By>=(Lc+12)){
  Bvx=-1*Bvx;
  Bvy=Bvy+4;
}

if(Bx<5 & By<(Lc+12) & By>=(Lc+8)){
  Bvx=-1*Bvx;
  Bvy=Bvy+3;
}

if(Bx<5 & By<(Lc+8) & By>=(Lc+4)){
  Bvx=-1*Bvx;
  Bvy=Bvy+2;
}

if(Bx<5 & By<(Lc+4) & By>=(Lc)){
  Bvx=-1*Bvx;
  Bvy=Bvy+1;
}

if(Bx<5 & By<(Lc) & By>=(Lc-4)){
  Bvx=-1*Bvx;
  Bvy=Bvy-1;
}

if(Bx<5 & By<(Lc-4) & By>=(Lc-8)){
  Bvx=-1*Bvx;
  Bvy=Bvy-2;
}

if(Bx<5 & By<(Lc-8) & By>=(Lc-12)){
  Bvx=-1*Bvx;
  Bvy=Bvy-3;
}

if(Bx<5 & By<(Lc-12) & By>=(Lc-16)){
  Bvx=-1*Bvx;
  Bvy=Bvy-4;
}



//return to centre if left paddle not present
if(Bx<5 & (By<Lb || By>Lt)){
  Bx=128;
  By=128;
  Bvy=random(-2,2); //random vertical velocity for serve
  LS=LS+1; //increase score
}

//bounce off top
if(By>243){
  Bvy=-1*Bvy;
}

//bounce off bottom
if(By<3){
  Bvy=-1*Bvy;
}

//scores
if(LS==0){
  zeroleft();
}

if(LS==1){
  oneleft();
}

if(LS==2){
  twoleft();
}

if(LS==3){
  threeleft();
}

if(LS==4){
  fourleft();
}

if(LS==5){
  fiveleft();
}

if(LS==6){
  sixleft();
}

if(LS==7){
  sevenleft();
}

if(LS==8){
  eightleft();
}

if(LS==9){
  nineleft();
}

if(RS==0){
  zeroright();
}

if(RS==1){
  oneright();
}

if(RS==2){
  tworight();
}

if(RS==3){
  threeright();
}

if(RS==4){
  fourright();
}

if(RS==5){
  fiveright();
}

if(RS==6){
  sixright();
}

if(RS==7){
  sevenright();
}

if(RS==8){
  eightright();
}

if(RS==9){
  nineright();
}



}
