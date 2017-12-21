//hookup first LED to pin 0 and second LED to pin 1
//hookup power supply to pin 2
//use the Rpi 3.3v pin as vref
//make a voltage divider to devide the input signal

void setup() {
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(1,OUTPUT);
  pinMode(0,OUTPUT);

}

void loop() {
int  voltsmain=analogRead(2);
int volts3.3=analogRead(3);
int ratio=volts3.3/voltsmain; //this is the ratio of the input voltage to the 3.3v pin
  
  if (ratio > //highest quartile){
  analogWrite(0,150);
  analogWrite(1,150);
}

if (//middle < ratio <highest quartile){
  analogWrite(0,150);
  analogWrite(1,0);
  }

if(//lowest quartile<ratio<middle){
  analogWrite(0,0);
  analogWrite(1,1);
 }

if(ratio<lowest quartile){
  analogWrite(0,0);
  analogWrite(1,1);
}


}
