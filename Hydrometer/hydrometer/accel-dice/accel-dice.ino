/**************
@file     dice.ino
@author   F. Sleeman
Parts of this code was used or modified from the Adafruit 8x8 LED matrix and MMA8451 breakout board example code.

SHOULD BE ABLE TO COMBINE WITH EXISTING CODE TO GET IT WORKING
*****************/

#include <Wire.h>

#define HT16K33_BLINK_CMD 0x80
#define HT16K33_BLINK_DISPLAYON 0x01
#define HT16K33_BLINK_OFF 0
#define HT16K33_BLINK_2HZ  1
#define HT16K33_BLINK_1HZ  2
#define HT16K33_BLINK_HALFHZ  3
#define HT16K33_CMD_BRIGHTNESS 0xE0

#define MMA8451_REG_OUT_X_MSB     0x01
#define MMA8451_REG_SYSMOD        0x0B
#define MMA8451_REG_WHOAMI        0x0D
#define MMA8451_REG_XYZ_DATA_CFG  0x0E
#define MMA8451_REG_PL_STATUS     0x10
#define MMA8451_REG_PL_CFG        0x11
#define MMA8451_REG_CTRL_REG1     0x2A
#define MMA8451_REG_CTRL_REG2     0x2B
#define MMA8451_REG_CTRL_REG4     0x2D
#define MMA8451_REG_CTRL_REG5     0x2E

#define MMA8451_PL_PUF            0
#define MMA8451_PL_PUB            1
#define MMA8451_PL_PDF            2
#define MMA8451_PL_PDB            3
#define MMA8451_PL_LRF            4
#define MMA8451_PL_LRB            5
#define MMA8451_PL_LLF            6
#define MMA8451_PL_LLB            7

#define MMA8451_DEFAULT_ADDRESS       (0x1D)    // if A is GND, its 0x1C
#define LED_MATRIX_DEFAULT_ADDRESS    (0x70)

uint8_t matrix[10][8] = {

  { 0x03, 0x84, 0x84, 0x84, 0x84, 0x84, 0x03, 0x00 }, //0
  { 0x01, 0x81, 0x01, 0x01, 0x01, 0x01, 0x83, 0x00 }, //1
  { 0x03, 0x84, 0x04, 0x02, 0x01, 0x80, 0x87, 0x00 }, //2
  { 0x03, 0x84, 0x04, 0x07, 0x04, 0x84, 0x03, 0x00 }, //3
  { 0x84, 0x84, 0x84, 0x87, 0x04, 0x04, 0x04, 0x00 }, //4 
  { 0x87, 0x80, 0x80, 0x83, 0x04, 0x04, 0x83, 0x00 }, //5
  { 0x03, 0x84, 0x80, 0x83, 0x84, 0x84, 0x03, 0x00 }, //6
  { 0x87, 0x04, 0x04, 0x02, 0x02, 0x01, 0x01, 0x00 }, //7
  { 0x03, 0x84, 0x84, 0x03, 0x84, 0x84, 0x03, 0x00 }, //8
  { 0x03, 0x84, 0x84, 0x07, 0x04, 0x04, 0x04, 0x00 }, //9
};



void setup() {
  Wire.begin(); 
  Wire.beginTransmission(LED_MATRIX_DEFAULT_ADDRESS);
  Wire.write(0x21);  // turn on oscillator
  Wire.endTransmission();
  Wire.beginTransmission(LED_MATRIX_DEFAULT_ADDRESS);  
  Wire.write(HT16K33_BLINK_CMD | HT16K33_BLINK_DISPLAYON | (HT16K33_BLINK_OFF << 1)); 
  Wire.endTransmission();
  Wire.beginTransmission(LED_MATRIX_DEFAULT_ADDRESS);
  Wire.write(HT16K33_CMD_BRIGHTNESS | 1);
  Wire.endTransmission();  

  
  //mma_begin();
  if (! mma_begin()) {    // FIXME - can I get away not using this?
    while (1);
  }
  writeDisplay();
}

uint8_t number = 0;
uint8_t last_orientation = 0;
uint8_t random_value = 0;
void loop() {  
  uint8_t counter = 0;
  uint8_t limit = 0;  
  while(limit < 250) {
    uint8_t orientation = mma_getOrientation();
    if(orientation != last_orientation) { 
      counter = counter + 1;
      random_value = random_value + limit + orientation;
    }
    last_orientation = orientation;
    limit = limit + 1;
  }
  if(counter > 4) {    
    number = random_value % 10;
    writeDisplay();
  }
}

uint8_t mma_begin() {
  
  /* Check connection */
  uint8_t deviceid = mma_readRegister8(MMA8451_REG_WHOAMI);
  if (deviceid != 0x1A) { return false; }

  mma_writeRegister8(MMA8451_REG_CTRL_REG2, 0x40); // reset

  while (mma_readRegister8(MMA8451_REG_CTRL_REG2) & 0x40);

  // DRDY on INT1
  mma_writeRegister8(MMA8451_REG_CTRL_REG4, 0x01);
  mma_writeRegister8(MMA8451_REG_CTRL_REG5, 0x01);

  // Turn on orientation config
  mma_writeRegister8(MMA8451_REG_PL_CFG, 0x40);

  // Activate at max rate, low noise mode
  mma_writeRegister8(MMA8451_REG_CTRL_REG1, 0x01 | 0x04);
  return true;
}

static inline uint8_t mma_getOrientation(void) {
  return mma_readRegister8(MMA8451_REG_PL_STATUS) & 0x07;
}

void mma_writeRegister8(uint8_t reg, uint8_t value) {
  Wire.beginTransmission(MMA8451_DEFAULT_ADDRESS);
  mma_i2cwrite((uint8_t)reg);
  mma_i2cwrite((uint8_t)(value));
  Wire.endTransmission();
}
uint8_t mma_readRegister8(uint8_t reg) {
    Wire.beginTransmission(MMA8451_DEFAULT_ADDRESS);
    mma_i2cwrite(reg);
    Wire.endTransmission(false); // MMA8451 + friends uses repeated start!!
    Wire.requestFrom(MMA8451_DEFAULT_ADDRESS, 1);
    return (mma_i2cread());
}

static inline uint8_t mma_i2cread(void) {
  return Wire.read();
}

static inline void mma_i2cwrite(uint8_t x) {
  Wire.write((uint8_t)x);
}

void writeDisplay() {
  Wire.beginTransmission(LED_MATRIX_DEFAULT_ADDRESS);
  Wire.write((uint8_t)0x00); // start at address $00
  for (uint8_t i=0; i<8; i++) {    
    Wire.write( matrix[number][i] & 0xFF);    
    Wire.write( matrix[number][i] >> 8); 
  }
  Wire.endTransmission();  
}
