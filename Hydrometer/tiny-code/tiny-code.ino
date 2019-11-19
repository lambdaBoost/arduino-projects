/*
 * https://www.instructables.com/id/Simple-Webserver-Using-Arduino-UNOMega-and-ESP8266/
 * http://www.martyncurrey.com/arduino-esp8266-web-server/
 * //if need to set eeprom fuse (probably dont need to since eeprom only clears when tiny is reprogrammed): https://dntruong.wordpress.com/2015/07/08/setting-and-reading-attiny85-fuses/
  Arduino Webserver using ESP8266


//DOES PRINTLN DO AWAY WITH NEED FOR /R/N? LOOKS LIKELY. POSSIBLY ADDRESS THIS
//CAN PROBABLY DO AWAY WITH THE ESPSEND AND SENDDATA METHODS AND JUST USE ESP8266.PRINT(LN) THROUGHOUT...SEE HOW IT GOES - LEAVE THEM IF WE HAVE THE MEMORY
 */


#include <TinyWireM.h>
#define MMA8452_ADDRESS 0x1D
#include<EEPROM.h>
#include <avr/sleep.h>
#include <avr/wdt.h>
 
//Some of the registers of the MMA8452
//IF DESPERATE WE COULD MAKE THESE LOCAL
#define OUT_X_MSB 0x01
#define XYZ_DATA_CFG 0x0E
//#define WHO_AM_I 0x0D //THINK WE CAN DROP
#define CTRL_REG1 0x2A
 
//accelerometer sensitivity can be 2,4, or 8g. NOW HARD CODED AS 2
//#define GSCALE 2 
 
//store current accelerometer values for x,y,z axis - NOW STORING RAW DATA ONLY TO SAVE PROGRAM SPACE
//float currentAcc[3] = {0.0, 0.0, 0.0};
 int accelCount[3]; // Stores the 12-bit signed value


//needs to be global
String api;


#include <SoftwareSerial.h>
#define Rx 3
#define Tx 4
#define ESP_en 1

SoftwareSerial esp8266(Rx,Tx); 


void setup()
{

 //Initialize the I2C communication bus
 TinyWireM.begin();
 //Test and initialize the MMA8452
 initMMA8452();

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


  // Setup for internal temp and vcc measurement
  ADCSRA &= ~(_BV(ADATE) |_BV(ADIE)); // Clear auto trigger and interrupt enable
  ADCSRA |= _BV(ADEN);                // Enable AD and start conversion
  ADMUX = 0xF | _BV( REFS1 );         // ADC4 (Temp Sensor) and Ref voltage = 1.1V;
  delay(100);                         // Settling time min 1 ms, take 100 ms
  getADC();

  
}


 
void loop()
{

    //setup_watchdog(6); //Setup watchdog to go off after 1sec
    //sleep_mode(); //Go to sleep! Wake up 1sec later
  
   getTempAndVcc();
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






///////////////accelerometer functions


//Test and initialize the accelerometer
void initMMA8452()
{
 //Read WHO_AM_I register. This is the first step to see if
 //communication can be estabilished with the MMA8452
 //THINK WE CAN DO WITHOUT THIS
 /*
 byte c = readRegister(WHO_AM_I);
 if(c == 0x1A) ///changed from 0x2A
 {
 digitalWrite(TEST_LED, HIGH);
 delay(1000);
 digitalWrite(TEST_LED, LOW);
 }
 else
 {
 while(1);
 }
 */
 
 //Must be in standby mode to change registers
 MMA8452Standby();
 
 //Set up full scale range to 2, 4, or 8g
 /*
 byte fsr = 2;
 //if(fsr > 8) fsr = 8; //Easy error check - DONT NEED IT
 fsr >>= 2; //Neat trick, see page 22 of datasheet. 00 = 2G, 01 = 4A, 10 = 8G
 writeRegister(XYZ_DATA_CFG, fsr);
 */
 //ABSOLUTELY NOT SURE ABOUT THIS BUT THINK WE CAN REPLACE THE ABOVE WITH JUST THIS LINE (DEPENDS ON WHETHER THE BYTE() FUNCTION WORKS THE WAY i THINK IT DOES:
 writeRegister(XYZ_DATA_CFG, byte(00));
 
 //The default data rate is 800Hz and we don't modify it in this example code
 
 // Set to active to start reading
 MMA8452Active();
}
 
// Read a single byte from addressToRead and return it as a byte
byte readRegister(byte addressToRead)
{
 TinyWireM.beginTransmission(MMA8452_ADDRESS);
 TinyWireM.write(addressToRead);
 //endTransmission but keep the connection active (repeated start)
 TinyWireM.endTransmission(false); 
 
 //Ask for 1 byte, once done, bus is released by default
 TinyWireM.requestFrom(MMA8452_ADDRESS, 1); 
 
 while(!TinyWireM.available()) ; //Wait for the data to come back
 return TinyWireM.read(); //Return this one byte
}
 
// Read bytesToRead sequentially, starting at addressToRead into the dest byte array
void readRegisters(byte addressToRead, int bytesToRead, byte * dest)
{
 TinyWireM.beginTransmission(MMA8452_ADDRESS);
 TinyWireM.write(addressToRead);
 TinyWireM.endTransmission(false); //endTransmission but keep the connection active
 
 //Ask for bytes, once done, bus is released by default
 TinyWireM.requestFrom(MMA8452_ADDRESS, bytesToRead);
 //Hang out until we get the # of bytes we expect
 while(TinyWireM.available() < bytesToRead); 
 
 for(int x = 0 ; x < bytesToRead ; x++)
 dest[x] = TinyWireM.read();
}
 
// Writes a single byte (dataToWrite) into addressToWrite
void writeRegister(byte addressToWrite, byte dataToWrite)
{
 TinyWireM.beginTransmission(MMA8452_ADDRESS);
 TinyWireM.write(addressToWrite);
 TinyWireM.write(dataToWrite);
 TinyWireM.endTransmission(); //Stop transmitting
}
 
// Sets the MMA8452 to standby mode. It must be in standby to change most register settings
void MMA8452Standby()
{
 byte c = readRegister(CTRL_REG1);
 writeRegister(CTRL_REG1, c & ~(0x01)); //Clear the active bit to go into standby
}
 
// Sets the MMA8452 to active mode. Needs to be in this mode to output data
void MMA8452Active()
{
 byte c = readRegister(CTRL_REG1);
 writeRegister(CTRL_REG1, c | 0x01); //Set the active bit to begin detection
}
 
// Updates the accelCount array with current accel readings
void updateAccelData()
{

 byte rawData[6]; // x/y/z accel register data stored here
 
 readRegisters(OUT_X_MSB, 6, rawData); // Read the six raw data registers into data array
 
 // Loop to calculate 12-bit ADC and g value for each axis
 for(int i = 0; i < 3 ; i++)
 {
 //Combine the two 8 bit registers (MSB and LSB) into one 12-bit number
 int gCount = (rawData[i*2] << 8) | rawData[(i*2)+1];
 gCount >>= 4; //The registers are left align, here we right align the 12-bit integer
 
 // If the number is negative, we have to make it so manually (no 12-bit data type)
 if (rawData[i*2] > 0x7F)
 {
 // Transform into negative 2's complement #
 gCount = ~gCount + 1;
 gCount *= -1;
 }
 
 accelCount[i] = gCount; //Record this gCount into the 3 int array
}

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






////////////functions to read chip temp and vcc

// Calibration of the temperature sensor has to be changed for your own ATtiny85
// per tech note: http://www.atmel.com/Images/doc8108.pdf
float chipTemp(float raw) {
  const float chipTempOffset = 272.9;           // Your value here, it may vary 
  const float chipTempCoeff = 1.075;            // Your value here, it may vary
  return((raw - chipTempOffset) / chipTempCoeff);
}
 
// Common code for both sources of an ADC conversion
int getADC() {
  ADCSRA  |=_BV(ADSC);           // Start conversion
  while((ADCSRA & _BV(ADSC)));    // Wait until conversion is finished
  return ADC;
}


void getTempAndVcc(){
  int i;
  uint8_t vccIndex;
  float rawTemp, rawVcc;
  int t_celsius; 
  
  
  // Measure temperature
  ADCSRA |= _BV(ADEN);           // Enable AD and start conversion
  ADMUX = 0xF | _BV( REFS1 );    // ADC4 (Temp Sensor) and Ref voltage = 1.1V;
  delay(100);                    // Settling time min 1 ms, wait 100 ms

  rawTemp = (float)getADC();     // use next sample as initial average
  for (int i=2; i<2000; i++) {   // calculate running average for 2000 measurements
    rawTemp += ((float)getADC() - rawTemp) / float(i); 
  }  
  ADCSRA &= ~(_BV(ADEN));        // disable ADC  

  // Measure chip voltage (Vcc)
  ADCSRA |= _BV(ADEN);   // Enable ADC
  ADMUX  = 0x0c | _BV(REFS2);    // Use Vcc as voltage reference,
                                 //    bandgap reference as ADC input
  delay(100);                    // Settling time min 1 ms, there is
                                 //    time so wait 100 ms
  rawVcc = (float)getADC();      // use next sample as initial average
  for (int i=2; i<2000; i++) {   // calculate running average for 2000 measurements
    rawVcc += ((float)getADC() - rawVcc) / float(i);
  }
  ADCSRA &= ~(_BV(ADEN));        // disable ADC
  
  rawVcc = 1024 * 1.1f / rawVcc;
  //index 0..13 for vcc 1.7 ... 3.0
  vccIndex = min(max(17,(uint8_t)(rawVcc * 10)),30) - 17;   

  // Temperature compensation using the chip voltage 
  // with 3.0 V VCC is 1 lower than measured with 1.7 V VCC 
  t_celsius = (int)(chipTemp(rawTemp) + (float)vccIndex / 13);  
  
}


//Sets the watchdog timer to wake us up, but not reset
//0=16ms, 1=32ms, 2=64ms, 3=128ms, 4=250ms, 5=500ms
//6=1sec, 7=2sec, 8=4sec, 9=8sec
//From: http://interface.khm.de/index.php/lab/experiments/sleep_watchdog_battery/
void setup_watchdog(int timerPrescaler) {

  if (timerPrescaler > 9 ) timerPrescaler = 9; //Limit incoming amount to legal settings

  byte bb = timerPrescaler & 7; 
  if (timerPrescaler > 7) bb |= (1<<5); //Set the special 5th bit if necessary

  //This order of commands is important and cannot be combined
  MCUSR &= ~(1<<WDRF); //Clear the watch dog reset
  WDTCR |= (1<<WDCE) | (1<<WDE); //Set WD_change enable, set WD enable
  WDTCR = bb; //Set new watchdog timeout value
  WDTCR |= _BV(WDIE); //Set the interrupt enable, this will keep unit from resetting after each int
}
