
long previousMillis=0;
long interval=10;
long throttleInterval=1000;

void setup() {
  pinMode(3,OUTPUT);

  
}

void loop() {
  int i;
  int j;
  unsigned long currentMillis=millis();
  if(currentMillis<1000) {
    if (currentMillis - previousMillis > interval){
      previousMillis=currentMillis;
      i=currentMillis;
      analogWrite(3,20+(i/10));
    }
    }
    
   if(1000<currentMillis<2000) {
    if (currentMillis - previousMillis > interval){
      previousMillis=currentMillis;
      j=currentMillis/2;
      analogWrite(3,270-(0.15*j)); 
}
}

   if (currentMillis>2000 and currentMillis<50000){
     analogWrite(3,20);
   }
}
    
