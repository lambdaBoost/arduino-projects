/*
 * https://www.instructables.com/id/Simple-Webserver-Using-Arduino-UNOMega-and-ESP8266/
 * http://www.martyncurrey.com/arduino-esp8266-web-server/
 * //if need to set eeprom fuse (probably dont need to since eeprom only clears when tiny is reprogrammed): https://dntruong.wordpress.com/2015/07/08/setting-and-reading-attiny85-fuses/
  Arduino Webserver using ESP8266


//DOES PRINTLN DO AWAY WITH NEED FOR /R/N? LOOKS LIKELY. POSSIBLY ADDRESS THIS
//CAN PROBABLY DO AWAY WITH THE ESPSEND AND SENDDATA METHODS AND JUST USE ESP8266.PRINT(LN) THROUGHOUT...SEE HOW IT GOES - LEAVE THEM IF WE HAVE THE MEMORY
 */

//requirements for accelerometer

#include<EEPROM.h>
#include <avr/sleep.h>
#include <avr/wdt.h>

//needs to be global
String api;


#include <SoftwareSerial.h>
#define Rx 10
#define Tx 11
#define ESP_en 1

SoftwareSerial esp8266(Rx,Tx); 


void setup()
{
  Serial.begin(9600);
  

  //Serial.begin(9600);    ///////For Serial monitor 
  esp8266.begin(9600); ///////ESP Baud rate

//start esp8266 in AP mode
  sendData(F("AT+RST\r\n"),1000); // reset module
  sendData(F("AT+CWMODE=2\r\n"),1000); // configure as access point
  sendData(F("AT+CIFSR\r\n"),1000); // get ip address
  sendData(F("AT+CIPMUX=1\r\n"),1000); // configure for multiple connections
  sendData(F("AT+CIPSERVER=1,80\r\n"),1000); // turn on server on port 80

  serveLoginPage(120000);

  sendData(F("AT+RST\r\n"),1000); // reset module
  sendData(F("AT+CWMODE=2\r\n"),1000); // configure as access point
  sendData(F("AT+CIFSR\r\n"),1000); // get ip address
  sendData(F("AT+CIPMUX=1\r\n"),1000); // configure for multiple connections
  sendData(F("AT+CIPSERVER=1,80\r\n"),1000); // turn on server on port 80

  serveLoginPage(120000);

  String id = EEPROM_readString(1);
  String pass = EEPROM_readString(128);
  api = EEPROM_readString(256);

//go to station mode and login using credentials
  sendData(F("AT+RST\r\n"),1000); // reset module
  sendData(F("AT\r\n"),1000);
  sendData(F("AT+CWMODE=1\r\n"),1000);
  sendData("AT+CWJAP=\""+ id +"\",\""+ pass +"\""+"\r\n",1000);
  delay(5000);



  
}


 
void loop()
{

    //setup_watchdog(6); //Setup watchdog to go off after 1sec
    //sleep_mode(); //Go to sleep! Wake up 1sec later and check water
  
   //getTempAndVcc();
   //updateAccelData();


}
 
  //////////////////////////////sends data from ESP to webpage///////////////////////////
 
 void espsend(String d,int conID)
         {
             String cipSend = " AT+CIPSEND=";
             cipSend += conID; 
             cipSend += ",";
             cipSend +=d.length();
             cipSend +="\r\n";
             sendData(cipSend,1000);
             sendData(d,1000); 
         }
         

//////////////gets the data from esp and displays in serial monitor///////////////////////         
String sendData(String command, const int timeout)
            {
                String response;
                esp8266.print(command);
                response = getResponse(timeout);
                return response;
            }
            
//gets response from esp8266            
String getResponse(const int timeout){
  long int time = millis();
  String response;
  while( (time+timeout) > millis())
                {
                   while(esp8266.available())
                      {
                         char c = esp8266.read(); // read the next character.
                         response+=c;
                      }  
                }
   return response;
}


//serve the login page for a specified time period
void serveLoginPage(int timeLimit){

  while(millis() < timeLimit){
  int connectionId;//0 by default
    if(esp8266.available())
  
  {
    /////////////////////Recieving from web browser
    
    if(esp8266.find("+IPD,"))
    {
     delay(300);
     connectionId = esp8266.read()-48;
     
   
     
     if(esp8266.find("ID="))
     { 
     //String rsp = decodeURL(getResponse(2000)); //can only do this if we manage to find nearly 2k more program space
     String rsp = getResponse(2000);

      //EXTRACT CREDENTIALS USING indexof() and substring()
      int id_idx = rsp.indexOf("&");
      int pass_start_idx = rsp.indexOf("=")+1;//first letter of password
      int pass_end_idx = rsp.indexOf("&API");//last letter of password
      int API_end_idx = rsp.indexOf(" HT");

      String id= rsp.substring(0,id_idx);    
      String pass = rsp.substring(pass_start_idx,pass_end_idx);
      String API = rsp.substring(pass_end_idx+5,API_end_idx);

      //WRITE TO EEPROM 
      EEPROM_writeString(1, id);
      EEPROM_writeString(128, pass);
      EEPROM_writeString(256, API); 

     delay(1000);
      break;
     }
     
     
   
    /////////////////////Sending data to browser
    //else

      espsend(F("<form>ID<br><input type=\"text\" name=\"ID\"><br>PASS<br><input type=\"text\" name=\"PASS\"><br>API<br><input type=\"text\" name=\"API\"><input type=\"submit\" value=\"Submit\"></form>"),connectionId);
    
     
     String closeCommand = "AT+CIPCLOSE=";  ////////////////close the socket connection////esp command 
     closeCommand+=connectionId; //
     closeCommand+="\r\n";
     sendData(closeCommand,3000);
     //esp8266.print(closeCommand);
     
     
    }
  }
}
return;
}





///////////EEPROM functions
void EEPROM_writeString(int add,String data)
{
  int _size = data.length();
  int i;
  for(i=0;i<_size;i++)
  {
    EEPROM.update(add+i,data[i]);
  }
  EEPROM.update(add+_size,'\0');   //Add termination null character for String Data

}

 

String EEPROM_readString(int add)
{
  int i;
  char data[50]; //Max 50 Bytes - may need to optimise this if dynamic memory becomes an issue
  int len=0;
  unsigned char k;
  k=EEPROM.read(add);
  while(k != '\0' && len<500)   //Read until null character
  {    
    k=EEPROM.read(add+len);
    data[len]=k;
    len++;
  }
  data[len]='\0';
  return String(data);
}



//decodes percent encoding on returned form
//uses nearly 2k program space with all chars included (!) since the replace function is huge
//CHANGE TO LOOKUP TABLE
/*String decodeURL(String urlChars)
{
  urlChars.replace("+",   " ");
  urlChars.replace("%20", " ");
  urlChars.replace("%21", "!");
  urlChars.replace("%22", String(char('\"')));
  urlChars.replace("%23", "#");
  urlChars.replace("%24", "$");
  urlChars.replace("%25", "%");
  urlChars.replace("%26", "&");
  urlChars.replace("%27", String(char(39)));
  urlChars.replace("%28", "(");
  urlChars.replace("%29", ")");
  urlChars.replace("%2A", "*");
  urlChars.replace("%2B", "+");
  urlChars.replace("%2C", ",");
  urlChars.replace("%2D", "-");
  urlChars.replace("%2E", ".");
  urlChars.replace("%2F", "/");
  urlChars.replace("%3A", ":");
  urlChars.replace("%3B", ";");
  urlChars.replace("%3C", "<");
  urlChars.replace("%3D", "=");
  urlChars.replace("%3E", ">");
  urlChars.replace("%3F", "?");
  urlChars.replace("%40", "@");
  urlChars.replace("%5B", "[");
  urlChars.replace("%5C", String(char(65)));
  urlChars.replace("%5D", "]");
  urlChars.replace("%5E", "^");
  urlChars.replace("%5F", "_");
  urlChars.replace("%60", "`");
   
  return urlChars;
}*/





