void setup() {
  Serial.begin(9600);
  pinMode(3,OUTPUT);

}

void loop() {
  int sensorval=analogRead(2);
  float voltage=(sensorval/1024)*3;
 digitalWrite(3,HIGH);
 delay(1000);
 Serial.print(voltage);
 Serial.print("    ");
 delay(1000);
 digitalWrite(3,LOW);
 delay(1000);
 Serial.print(voltage);
 Serial.print("    ");
 delay(1000);
 }

