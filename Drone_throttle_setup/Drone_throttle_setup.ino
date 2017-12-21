
long previousMillis=0;
long interval=10;
long throttleInterval=1000;
int throttlePin=3;
int yawPin=5;
int pitchPin=6;
int rollPin=11;

void setup() {
  pinMode(throttlePin,OUTPUT);

  
}

void loop() {
  int i;
  int j;
  unsigned long currentMillis=millis();
  if(currentMillis<3000){
    analogWrite(throttlePin,61);
  }
  
  if(3000<currentMillis and currentMillis<4000) {
    if (currentMillis - previousMillis > interval){
      previousMillis=currentMillis;
      i=currentMillis;
      analogWrite(throttlePin,(0.072*i-155));
    }
    }
    
   if(4000<currentMillis and currentMillis<5000) {  //reset first number to 6000 andsecond to 8000
    analogWrite(throttlePin,133);
  }

  if(5000<currentMillis and currentMillis<6000) {
    if (currentMillis - previousMillis > interval){
      previousMillis=currentMillis;
      i=currentMillis;
      analogWrite(throttlePin,493-(0.072*i)); 
  }
  }

   if (currentMillis>6000 and currentMillis<10000){
     analogWrite(throttlePin,61);
   }
   if(currentMillis>10000 and currentMillis<50000){
     analogWrite(throttlePin,133);
   }
   
}
    
