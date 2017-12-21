void setup(){
  DDRA =255;
  DDRB=255;
}

void circle(float AH, float AV, uint8_t p, uint8_t q){

for(float ii=0;ii<6.28;ii=ii+0.05){

  
  PORTA= (AH*128*sin(ii))+127+p;
 
  PORTB= (AV*128*cos(ii))+127+q;
  
  delayMicroseconds(40);

}
}

void loop() {
  circle(0.5,0.5,0,0);
  }

