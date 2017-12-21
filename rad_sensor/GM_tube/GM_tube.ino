#include <SPI.h>

#define LOG_PERIOD 15000     //Logging period in milliseconds, recommended value 15000-60000.

#define MAX_PERIOD 60000    //Maximum logging period

unsigned long counts;             //variable for GM Tube events

unsigned long cpm;                 //variable for CPM

unsigned int multiplier;             //variable for calculation CPM in this sketch

unsigned long previousMillis;      //variable for time measurement

 

void tube_impulse(){               //procedure for capturing events from Geiger Kit

  counts++;

}



void setup(){                                               //setup procedure

  counts = 0;

  cpm = 0;

  multiplier = MAX_PERIOD / LOG_PERIOD;      //calculating multiplier, depend on your log period

  Serial.begin(9600);                                    // start serial monitor

 // uncommennt if you have time-out problem to connect with Radiation Logger
 //  delay(2000);
 //  Serial.write('0');                                      // sending zero to avoid connection time out with radiation logger
 //  delay(2000);
 //  Serial.write('0');                                     // sending zero to avoid connection time out with radiation logger

  pinMode(2, INPUT);                                   // set pin INT0 input for capturing GM Tube events

  digitalWrite(2, HIGH);                                 // turn on internal pullup resistors, solder C-INT on the PCB

  attachInterrupt(0, tube_impulse, FALLING);  //define external interrupts

}

 

void loop(){                                               //main cycle

  unsigned long currentMillis = millis();

  if(currentMillis - previousMillis > LOG_PERIOD){

    previousMillis = currentMillis;

    cpm = counts * multiplier;

        Serial.print(cpm);                              // send cpm data to Radiation Logger

        Serial.write(' ');                                // send null character to separate next data

    counts = 0;

  }

}


