void setup() {
Serial.begin(9600);
pinMode(A0,INPUT);
pinMode(A1,INPUT);
pinMode(A2,INPUT);

}

int AQ;
int MQ2;

void loop() {

AQ=analogRead(A1);
MQ2=analogRead(A2);
Serial.print("air quality, ");
Serial.println(AQ);
Serial.print("volatiles, ");
Serial.println(MQ2);
delay(1000);


}
