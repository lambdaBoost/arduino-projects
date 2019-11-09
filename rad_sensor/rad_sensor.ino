//TO MAKE A NEW TXT FILE JUST DECLARE THE NEW FILENAME IN MYFILE (IN SETUP AND AFTER LOOP IS DECLARED)
/*CONNECTIONS:
 * SD card attached to SPI bus as follows:
 ** DI - pin 11
 ** DO - pin 12
 ** CLK - pin 13
 ** CS - pin 10
 **TEMP SENSOR - A0
*/
//#include <SPI.h>
#include <SD.h>

//GM SETUP
#define LOG_PERIOD 60000    //Logging period in milliseconds, recommended value 15000-60000.

#define MAX_PERIOD 60000    //Maximum logging period

unsigned long counts;             //variable for GM Tube events

unsigned long cpm;                 //variable for CPM

unsigned int multiplier;             //variable for calculation CPM in this sketch

unsigned long previousMillis;      //variable for time measurement

 

void tube_impulse(){               //procedure for capturing events from Geiger Kit

  counts++;

}







int sensorPin = 0;//temp sensor
 
File myFile;

void setup()
{
  Serial.begin(9600);
  Serial.print("Initializing SD card...");
  // On the Ethernet Shield, CS is pin 4. It's set as an output by default.
  // Note that even if it's not used as the CS pin, the hardware SS pin 
  // (10 on most Arduino boards, 53 on the Mega) must be left as an output 
  // or the SD library functions will not work. 
   pinMode(10, OUTPUT);
   pinMode(A1,INPUT);
   pinMode(A2,INPUT);
 
  if (!SD.begin(10)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");
 
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  myFile = SD.open("temp.txt", FILE_WRITE);
 
  // if the file opened okay, confirm:
  if (myFile) {
    Serial.print("SD file opened OK");

  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }

  //GM SETUP:
    counts = 0;

  cpm = 0;

  multiplier = MAX_PERIOD / LOG_PERIOD;      //calculating multiplier, depend on your log period
   pinMode(2, INPUT);                                   // set pin INT0 input for capturing GM Tube events

  digitalWrite(2, HIGH);                                 // turn on internal pullup resistors, solder C-INT on the PCB

  attachInterrupt(0, tube_impulse, FALLING);  //define external interrupts
}

int AQ;//AIR QUALITY
int MQ2;//MQ2 VOLATILE GAS SENSOR
 
void loop()
{
  unsigned long currentMillis = millis();

  myFile = SD.open("temp.txt", FILE_WRITE);

  //TEMPERATURE SENSOR
   //getting the voltage reading from the temperature sensor
 int reading = analogRead(sensorPin);  
 
 // converting that reading to voltage, for 3.3v arduino use 3.3
 float voltage = reading * 5.0;
 voltage /= 1024.0; 
 
 // now print out the temperature
 float temperatureC = (voltage - 0.5) * 100 ;  


//VOLATILE GAS SENSOR (MQ2)

MQ2=analogRead(A2);

//AIR QUALITY SENSOR
AQ=analogRead(A1);

 //WRITE DATA TO FILE
   // if the file opened okay, write to it:
 //    if(currentMillis - previousMillis > LOG_PERIOD){
  //     previousMillis = currentMillis;
cpm = counts * multiplier;
     
  if (myFile) {

    //PRINT SENSOR READINGS
    Serial.print("millis, ");
    Serial.println(millis());
    
    Serial.print("degreesC, ");
    Serial.println(temperatureC);
    
    Serial.print("air quality, ");
    Serial.println(AQ);

    Serial.print("volatiles, ");
    Serial.println(MQ2);

    Serial.print("cpm, ");                              // send cpm data to Radiation Logger
    Serial.println(cpm);

    Serial.println(" ");
    

    //WRITE TO FILE
    myFile.print("millis, ");
    myFile.println(millis());
    
    myFile.print("degreesC, ");
    myFile.println(temperatureC);

    myFile.print("air quality, ");
    myFile.println(AQ);

    myFile.print("volatiles, ");
    myFile.println(MQ2);

    myFile.print("cpm, ");                              // send cpm data to Radiation Logger
    myFile.println(cpm);

    myFile.println(" ");

    counts = 0;
    

  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
  myFile.close();
    // }
    delay(60000);
}
