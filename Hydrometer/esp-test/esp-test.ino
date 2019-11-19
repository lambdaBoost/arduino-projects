#include <SoftwareSerial.h>
#define RX 10
#define TX 11
int sensorPin = 0;
String AP = "SSID";       // CHANGE ME
String PASS = "WIFI-PASS"; // CHANGE ME
String API = "API-KEY";   // CHANGE ME
String HOST = "api.thingspeak.com";
String PORT = "80";
String field = "field1";
int countTrueCommand;
int countTimeCommand; 
boolean found = false; 
int valSensor = 1;
SoftwareSerial esp8266(RX,TX); 
 
  
void setup() {
  Serial.begin(9600);
  esp8266.begin(9600);
  //DONT NEED IF WIFIMANAGER WORKS
  sendCommand("AT",5,"OK");
  sendCommand("AT+CWMODE=1",5,"OK");
  sendCommand("AT+CWJAP=\""+ AP +"\",\""+ PASS +"\"",20,"OK");
  
  
}
void loop() {
 valSensor = getSensorData();
 String getData = "GET /update?api_key="+ API +"&"+ field +"="+String(valSensor);
sendCommand("AT+CIPMUX=1",5,"OK");
 //sendCommand("AT+CIPSTART=0,\"TCP\",\""+ HOST +"\","+ PORT,15,"OK");
 //instead of string concats do these commands manually
 esp8266.print("AT+CIPSTART=0,\"TCP\",\"");
 esp8266.print(HOST);
 esp8266.print("\",");
 esp8266.printnl(PORT);
 
 //sendCommand("AT+CIPSEND=0," +String(getData.length()+4),4,">");
 esp8266.print("AT+CIPSEND=0,");
 esp8266.println(String(getData.length()+4)+API.length() + field.length()+22);///

 //esp8266.println(getData);delay(1500);countTrueCommand++;
 esp8266.print("GET /update?api_key=");
 esp8266.print(API);
 esp8266.print("&");
 esp8266.print(field);
 esp8266.print("=");
 esp8266.println(String(valSensor));
 sendCommand("AT+CIPCLOSE=0",5,"OK");
}
int getSensorData(){
  
  int reading = analogRead(sensorPin);  
 
 // converting that reading to voltage, for 3.3v arduino use 3.3
 float voltage = reading * 5;
 voltage /= 1024.0; 

 float temperatureC = (voltage - 0.5) * 100 ;  //converting from 10 mv per degree wit 500 mV offset
                                               //to degrees ((voltage - 500mV) times 100)
 return temperatureC;
 
 //return random(1000);
}
void sendCommand(String command, int maxTime, char readReplay[]) {
  Serial.print(countTrueCommand);
  Serial.print(". at command => ");
  Serial.print(command);
  Serial.print(" ");
  while(countTimeCommand < (maxTime*1))
  {
    esp8266.println(command);//at+cipsend
    if(esp8266.find(readReplay))//ok
    {
      found = true;
      break;
    }
  
    countTimeCommand++;
  }
  
  if(found == true)
  {
    Serial.println("OYI");
    countTrueCommand++;
    countTimeCommand = 0;
  }
  
  if(found == false)
  {
    Serial.println("Fail");
    countTrueCommand = 0;
    countTimeCommand = 0;
  }
  
  found = false;
 }

