
void setup() {
  DDRA=255;
  DDRB=255;
  


}

void loop() {
 PORTA=0;
 PORTB=0;
 
 delayMicroseconds(50);
 
 PORTA=180;
 PORTB=180;
 
 delayMicroseconds(50);

}
