
#include <PGMWrap.h>
#include <avr/pgmspace.h>

const uint8_p image[] PROGMEM ={
  1,0,1,0};

int k;
int A;

void setup() {
Serial.begin(9600);

}

void loop() {

for(k=0;k<4;k++){
  A=image[k];
  Serial.print(A);
}
}


