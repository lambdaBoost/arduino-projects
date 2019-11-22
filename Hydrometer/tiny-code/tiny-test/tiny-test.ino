#include <SoftwareSerial.h>
#include<TinyWireM.h>
//#include<EEPROM.h>
#define RX 3
#define TX 4
int countTrueCommand;
int countTimeCommand;
boolean found = false;
int accelCount[3]; // Stores the 12-bit signed value

//String PASS;
//String SID;
//String API;

SoftwareSerial esp8266(RX, TX);

//Some of the registers of the MMA8452
//IF DESPERATE WE COULD MAKE THESE LOCAL
#define OUT_X_MSB 0x01
#define XYZ_DATA_CFG 0x0E
//#define WHO_AM_I 0x0D //THINK WE CAN DROP
#define CTRL_REG1 0x2A
#define MMA8452_ADDRESS 0x1D


void setup()
{

  //initMMA8452();

  //Serial.begin(9600);
  esp8266.begin(9600);


/*
  SID=EEPROM_readString(1);
  PASS=EEPROM_readString(100);
  API=EEPROM_readString(200);
  */

  connectToWifi();



}


void loop()
{

  int temp = getTempandVcc(true);
  int vcc = getTempandVcc(false);

  sendData(temp, F("field1"));
  sendData(vcc, F("field2"));
  //updateAccelData();
  //sendData(accelCount[0], F("field3"));
  //sendData(accelCount[1], F("field4"));
  //sendData(accelCount[2], F("field5"));
}


void connectToWifi(){

  esp8266.println("AT+RST"); // reset module
  delay(10000);
  sendCommand("AT", 5, "OK", true);
  delay(2000);
  // sendCommand(F("AT+CWMODE=1"),5,"OK",true);
  //delay(2000);
  //sendCommand("AT+CWJAP=\""+ SSID +"\",\""+ PASS +"\"",20,"OK",false);
  sendCommand(F("AT+CWJAP=\"SSID\",\"PASS\""), 20, "OK", true);
  delay(5000);
}


void sendCommand(String command, int maxTime, char readReplay[], bool led) {
  //Serial.print(countTrueCommand);
  //Serial.print(". at command => ");
  //Serial.print(command);
  //Serial.print(" ");
  while (countTimeCommand < (maxTime * 1))
  {
    esp8266.println(command);//at+cipsend
    if (esp8266.find(readReplay)) //ok
    {
      found = true;
      break;
    }

    countTimeCommand++;
  }

  if (found == true )
  {
    //Serial.println("OYI");
    countTrueCommand++;
    countTimeCommand = 0;

  }

  if (found == false)
  {
    //Serial.println("Fail");
    countTrueCommand = 0;
    countTimeCommand = 0;
  }

  found = false;
}






////////////////send a single sensor reading to thingspeak
void sendData(int val, String field) {

  //char v_buffer[10];
  //String sensorValue=dtostrf(val,0,5,v_buffer);

  String sensorValue = String(val);

  String API = F("API");
  String HOST = F("api.thingspeak.com");
  String PORT = F("80");

  //String getData = "GET /update?api_key=API&field1="+String(valSensor); //String(valSensor)
  sendCommand(F("AT+CIPMUX=1"), 5, "OK", false);
  delay(2000);

  //sendCommand("AT+CIPSTART=0,\"TCP\",\""+ HOST +"\","+ PORT,15,"OK");
  boolean led = false;
  while (countTimeCommand < (5 * 1))
  {
    esp8266.print(F("AT+CIPSTART=0,\"TCP\",\""));
    esp8266.print(HOST);
    esp8266.print(F("\","));
    esp8266.println(PORT);
    if (esp8266.find("OK")) //ok
    {
      found = true;
      break;
    }

    countTimeCommand++;
  }

  if (found == true )
  {
    //Serial.println("OYI");
    countTrueCommand++;
    countTimeCommand = 0;

/*
    if (led == true) {
      digitalWrite(ledPin, HIGH);
      delay(1000);
      digitalWrite(ledPin, LOW);
    }
    */

  }

  if (found == false)
  {
    //Serial.println("Fail");
    countTrueCommand = 0;
    countTimeCommand = 0;
  }

  found = false;



  delay(5000);

  //works ok as is
  //sendCommand("AT+CIPSEND=0," +String(getData.length()+4),4,">");
  esp8266.print("AT+CIPSEND=0,");
  esp8266.println(String(4 + API.length() + field.length() + 22 + sensorValue.length())); ///
  delay(5000);


  //send command
  //esp8266.println(getData);delay(1500);countTrueCommand++;
  led = true;
  while (countTimeCommand < (5 * 1))
  { esp8266.print(F("GET /update?api_key="));
    esp8266.print(API);
    esp8266.print(F("&"));
    esp8266.print(field);
    esp8266.print(F("="));
    esp8266.println(sensorValue);

    if (esp8266.find("OK")) //ok
    {
      found = true;
      break;
    }

    countTimeCommand++;
  }

  if (found == true )
  {
    //Serial.println("OYI");
    countTrueCommand++;
    countTimeCommand = 0;

  }

  if (found == false)
  {
    //Serial.println("Fail");
    countTrueCommand = 0;
    countTimeCommand = 0;
  }

  found = false;


  delay(5000);
  sendCommand(F("AT+CIPCLOSE=0"), 5, "OK", false);

}


////////////functions to read chip temp and vcc

// Calibration of the temperature sensor has to be changed for your own ATtiny85
// per tech note: http://www.atmel.com/Images/doc8108.pdf
float chipTemp(float raw) {
  const float chipTempOffset = 272.9;           // Your value here, it may vary
  const float chipTempCoeff = 1.075;            // Your value here, it may vary
  return ((raw - chipTempOffset) / chipTempCoeff);
}

// Common code for both sources of an ADC conversion
int getADC() {
  ADCSRA  |= _BV(ADSC);          // Start conversion
  while ((ADCSRA & _BV(ADSC)));   // Wait until conversion is finished
  return ADC;
}


float getTempandVcc(bool temp) {
  int i;
  uint8_t vccIndex;
  float rawTemp;
  float rawVcc;
  float t_celsius;


  // Measure temperature
  ADCSRA |= _BV(ADEN);           // Enable AD and start conversion
  ADMUX = 0xF | _BV( REFS1 );    // ADC4 (Temp Sensor) and Ref voltage = 1.1V;
  delay(100);                    // Settling time min 1 ms, wait 100 ms

  rawTemp = (float)getADC();     // use next sample as initial average
  for (int i = 2; i < 2000; i++) { // calculate running average for 2000 measurements
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
  for (int i = 2; i < 2000; i++) { // calculate running average for 2000 measurements
    rawVcc += ((float)getADC() - rawVcc) / float(i);
  }
  ADCSRA &= ~(_BV(ADEN));        // disable ADC

  rawVcc = 1024 * 1.1f / rawVcc;
  //index 0..13 for vcc 1.7 ... 3.0
  vccIndex = min(max(17, (uint8_t)(rawVcc * 10)), 30) - 17;

   // Temperature compensation using the chip voltage
  // with 3.0 V VCC is 1 lower than measured with 1.7 V VCC
  //t_celsius = (int)(chipTemp(rawTemp) + (float)vccIndex / 13);
  t_celsius = (chipTemp(rawTemp) + (float)vccIndex / 13);

  if(temp==true){
  return (int) 100*t_celsius;
  }
  else{
    return (int) 100*rawVcc;
  }

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

  while (!TinyWireM.available()) ; //Wait for the data to come back
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
  while (TinyWireM.available() < bytesToRead);

  for (int x = 0 ; x < bytesToRead ; x++)
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
  for (int i = 0; i < 3 ; i++)
  {
    //Combine the two 8 bit registers (MSB and LSB) into one 12-bit number
    int gCount = (rawData[i * 2] << 8) | rawData[(i * 2) + 1];
    gCount >>= 4; //The registers are left align, here we right align the 12-bit integer

    // If the number is negative, we have to make it so manually (no 12-bit data type)
    if (rawData[i * 2] > 0x7F)
    {
      // Transform into negative 2's complement #
      gCount = ~gCount + 1;
      gCount *= -1;
    }

    accelCount[i] = gCount; //Record this gCount into the 3 int array
  }

}



/*
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


*/

