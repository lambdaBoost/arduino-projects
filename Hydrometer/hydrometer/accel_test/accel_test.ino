/*
arduino library for mma8452 doesnt work with tinywirem. Most of the sensor code is therefore adapted from here https://codebender.cc/sketch:110954#Trinket%20MMA8451%20Test.ino 

MMA8451 ADDRESS SHOULD BE OK BUT IF DOESNT WORK, CHANGE TO 0x1C and tie A pin to gnd
note the code keeps referring to an mma8452 instead of mma8451. I think its ok and just a typo by the original author

pinout (physical pins on ATT85)

ATT85         MMA8451     Other                     ESP8266           temp sensor
pin5 (D0)         SDA
pin7 (D2)         SCL
pin6 (D1)                    test LED (temporary)       CH_PD         power
pin3 (D4)                                               rx
pin2 (D3/A3)                                            tx            data
pin1 (RST) - to 10k resistor
//use SoftwareSerial(d3,d4)
 use pin 6 connected to the shutdown pin on the esp8266 and the power pin of the temp sensor, via a NOT gate. This would allow for temp sensing when the esp8266 is shut down, but would disable the temp sensor to allow for serial communication when the esp8266 is active.
*/

#include < TinyWireM.h>
#include <SoftwareSerial.h>
#define MMA8452_ADDRESS 0x1D
 
#define TEST_LED 1
 
//Some of the registers of the MMA8452
#define OUT_X_MSB 0x01
#define XYZ_DATA_CFG 0x0E
#define WHO_AM_I 0x0D
#define CTRL_REG1 0x2A
 
//accelerometer sensitivity can be 2,4, or 8g
#define GSCALE 2 
 
//store current accelerometer values for x,y,z axis
float currentAcc[3] = {0.0, 0.0, 0.0};
const float threshold = 0.5; // set value from -1 to 1
 
void setup()
{
 pinMode(TEST_LED, OUTPUT);
 digitalWrite(TEST_LED, LOW);
 
 //Initialize the I2C communication bus
 TinyWireM.begin();
 
 //Test and initialize the MMA8452
 initMMA8452();
}
 
void loop()
{
 //Retrieve the current accelerometer readings
 updateAccelData();
 
 if(currentAcc[2] > threshold)
 {
 digitalWrite(TEST_LED, HIGH);
 }
 else
 {
 digitalWrite(TEST_LED, LOW);
 }

 delay(100);
}
 
//Test and initialize the accelerometer
void initMMA8452()
{
 //Read WHO_AM_I register. This is the first step to see if
 //communication can be estabilished with the MMA8452
 byte c = readRegister(WHO_AM_I);
 if(c == 0x2A)
 {
 //digitalWrite(TEST_LED, HIGH);
 }
 else
 {
 while(1);
 }
 
 //Must be in standby mode to change registers
 MMA8452Standby();
 
 //Set up full scale range to 2, 4, or 8g
 byte fsr = GSCALE;
 if(fsr > 8) fsr = 8; //Easy error check
 fsr >>= 2; //Neat trick, see page 22 of datasheet. 00 = 2G, 01 = 4A, 10 = 8G
 writeRegister(XYZ_DATA_CFG, fsr);
 
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
 int accelCount[3]; // Stores the 12-bit signed value
 
 readAccelData(accelCount); // Read the x/y/z adc values
 
 // Now we'll calculate the accleration value into actual g's
 float accelG[3]; // Stores the real accel value in g's
 for (byte i = 0; i < 3; i++)
 {
 // get actual g value, this depends on scale being set
 accelG[i] = (float) accelCount[i] / ((1<<12)/(2*GSCALE)); 
 
 // use a rolling filter
 currentAcc[i] = 0.95 * accelG[i] + currentAcc[i] * 0.05;
 }
}
 
// Reads accel data from the MMA8452
void readAccelData(int *destination)
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
 
 destination[i] = gCount; //Record this gCount into the 3 int array
 }
}
