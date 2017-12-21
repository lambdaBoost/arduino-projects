void setup() {
pinMode(1,OUTPUT);
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);

digitalWrite(5,HIGH);

}

void loop() {
  
  
  //0
delay(1000);
digitalWrite(1,LOW);
digitalWrite(2,LOW);
digitalWrite(3,LOW);
digitalWrite(4,LOW);



//1
delay(1000);
digitalWrite(1,LOW);
digitalWrite(2,LOW);
digitalWrite(3,LOW);
digitalWrite(4,HIGH);


//2
delay(1000);
digitalWrite(1,LOW);
digitalWrite(2,LOW);
digitalWrite(3,HIGH);
digitalWrite(4,LOW);


// 3
delay(1000);
digitalWrite(1,LOW);
digitalWrite(2,LOW);
digitalWrite(3,HIGH);
digitalWrite(4,HIGH);




//4
delay(1000);
digitalWrite(1,LOW);
digitalWrite(2,HIGH);
digitalWrite(3,LOW);
digitalWrite(4,LOW);


//5
delay(1000);
digitalWrite(1,LOW);
digitalWrite(2,HIGH);
digitalWrite(3,LOW);
digitalWrite(4,HIGH);

//6
delay(1000);
digitalWrite(1,LOW);
digitalWrite(2,HIGH);
digitalWrite(3,HIGH);
digitalWrite(4,LOW);

//7
delay(1000);
digitalWrite(1,LOW);
digitalWrite(2,HIGH);
digitalWrite(3,HIGH);
digitalWrite(4,HIGH);


//8
delay(1000);
digitalWrite(1,HIGH);
digitalWrite(2,LOW);
digitalWrite(3,LOW);
digitalWrite(4,LOW);

//9
delay(1000);
digitalWrite(1,HIGH);
digitalWrite(2,LOW);
digitalWrite(3,LOW);
digitalWrite(4,HIGH);



}
