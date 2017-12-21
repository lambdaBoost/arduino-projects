void setup() {
  DDRA =255;
  DDRB=255;
}

void loop() {
float i=1;
  PORTA=64*sin(i);
  PORTB=64*cos(i);
  delayMicroseconds(40);
}

