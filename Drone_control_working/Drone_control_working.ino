int buf=0;
int xcoordinate=0;
int ycoordinate=0;

long previousMillis=0;
long interval=10;
long throttleInterval=1000;
int throttlePin=3;
int yawPin=5;
int pitchPin=6;
int rollPin=11;

void setup() {
  Serial.begin(9600);
  pinMode(throttlePin,OUTPUT);

  
}

void loop() {
 /* 
  //read serial data and print coordinates of drone on screen
  if (Serial.available() > 0) {
        readCoordinates();
        //delay(2);    //9600 baud rate is slower than the arduino clock speed this delay removes problems
        //if(Serial.available() == 0){ //this is where you would move the arm to a coordinate I just print them.
            Serial.print(xcoordinate);
            Serial.print(",");
            Serial.println(ycoordinate);
        //}
    }
  */
  
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
    
 //define read coordinates object to get coordinates from serial port   
 void readCoordinates(){
    byte character = Serial.read(); //read the first byte on serial
    if(character != 10 && character != ','){ //newline(10) and , are special
        buf = buf*10;
        buf += (int)(character - '0'); //these two lines turn the string into an integer
    } else if(character == ','){
        xcoordinate = buf; //after a comma the buffer has the x coordinate
        buf = 0;
    } else {
        ycoordinate = buf; //after a space the buffer has the y coordinate
        buf = 0;
    }
}
