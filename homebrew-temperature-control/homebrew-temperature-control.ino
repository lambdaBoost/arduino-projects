#include <TM1637Display.h>
#include <OneWire.h> 
#include <DallasTemperature.h>


#define CLK 4
#define DIO 3
#define RELAY 1
#define TMP 0
#define DISP_TOGGLE 5 
#define PC_STATUS 6
#define TMPCTRL A1

//relay only cycles if temperature is outside the target +- range. Not as good as PID but honetly it doesnt matter for this application
float TARGETTEMP = 20;
float MARGIN = 0.25; //acceptable temperature margin (use if we dont us PID control)

float Aref = 1.0759; // temp calibration | change in small 0.000x steps to the actual Aref voltage of ---YOUR--- Arduino for accurate temp readings

//array to store temperatures for smoothing
const int numReadings = 100;

int targetTempRaw;
int oldTargetTempRaw;

// Create display object of type TM1637Display:
TM1637Display display(CLK, DIO);

//onewire instance to communicate with sensor
OneWire oneWire(TMP); 

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

void setup() {
  
  // Clear the display:
 // display.clear();
 // delay(1000);
 analogReference(INTERNAL); // use the internal ~1.1volt reference | change (INTERNAL) to (INTERNAL1V1) for a Mega
 pinMode(RELAY, OUTPUT);
 pinMode(TMPCTRL,INPUT);
 pinMode(DISP_TOGGLE, OUTPUT);
 pinMode(PC_STATUS, INPUT)

  // Start up the onewire library 
 sensors.begin(); 

}



//TAKE MULTIPLE READINGS FOR SMOOTHING
void loop() {

  display.setBrightness(0x0f);
  oldTargetTempRaw = targetTempRaw;
  
  targetTempRaw = analogRead(TMPCTRL);
  targetTemp = targetTempRaw/25 //gives range to 40C


  float totalTemp=0;
  for(int i=0; i<numReadings; i++){
    sensors.requestTemperatures(); // Send the command to get temperature reading
    float temperatureC = sensors.getTempCByIndex(0);
    totalTemp+=temperatureC;
  }

  float smoothedTemp = totalTemp/numReadings;
  

  
  if(DISP_TOGGLE){
    display.showNumberDecEx(smoothedTemp*100,0b01000000,false,4,0);
  }
  else{
    display.showNumberDecEx(targetTemp*100,0b01000000,false,4,0);
  }

//TODO - CHANGE TO TURN PC ON AND OFF
  if(smoothedTemp > TARGETTEMP+MARGIN){ //turn off
    digitalWrite(RELAY, HIGH);
  }
  else if (smoothedTemp < TARGETTEMP-MARGIN){ //turn on
    digitalWrite(RELAY, LOW);
  }

  
  
  delay(1000);

  
}
