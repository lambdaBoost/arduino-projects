/* Three PWM Outputs */

/*
pink-blue themed rgb led theme powered by attiny 85
includes low battery warning for use on lipo batteries

wireup as follows

attiny pin (1-8)    to
2                   battery +
3                   LED B
4                   GND
5                   LED R
6                   LED G
8                   5V

assume the LED pins go R-GND-G-B

*/

// ATtiny85 outputs
const int Red = 0;
const int Green = 1;
const int Blue = 2;
const int voltagePin = A3;

volatile uint8_t* Port[] = {&OCR0A, &OCR0B, &OCR1B};
int Pin[] = {0, 1, 4};

void setup() {
  pinMode(Pin[Red], OUTPUT);
  pinMode(Pin[Green], OUTPUT);
  pinMode(Pin[Blue], OUTPUT);
  pinMode(voltagePin, INPUT);
  // Configure counter/timer0 for fast PWM on PB0 and PB1
  TCCR0A = 3<<COM0A0 | 3<<COM0B0 | 3<<WGM00;
  TCCR0B = 0<<WGM02 | 3<<CS00; // Optional; already set
  // Configure counter/timer1 for fast PWM on PB4
  GTCCR = 1<<PWM1B | 3<<COM1B0;
  TCCR1 = 3<<COM1A0 | 7<<CS10;
}

// Sets colour Red=0 Green=1 Blue=2 to specified intensity 0 (off) to 255 (max)
void setColour (int colour, int intensity) {
  *Port[colour] = intensity;
}

void loop() {

int batteryVoltage = analogRead(voltagePin);

if(batteryVoltage >= 696){ //3.4V

//start with blue
  setColour(0,0);
  setColour(1,0);
  setColour(2,255);

  //increment green (left leg of triangle) go to 0,255,255
  for (int i=0 ; i<255 ; i++){

  setColour(0,0);
  setColour(1,i);
  setColour(2,255);

   delay(5);
  }

  //increment red and decrement blue (go to 255,128,255)
  for (int i=0 ; i<255 ; i++){

  setColour(0,i);
  setColour(1,255-(128* i/255));
  setColour(2,255);

   delay(5);
  }

  //decrement green (go to 255,0,128) - note slower delay to keep in pink sector longer
  for (int i=128; i>0;i--){

  setColour(0,255);
  setColour(1,i);
  setColour(2,127+i);

  delay(5);
  }

  //decrement red, increment blue (bottom leg of triangle) go to 0,0,255
  for (int i=0 ; i<255 ; i++){

  setColour(0,255-i);
  setColour(1,0);
  setColour(2,128+(i/2));

    delay(5);
  }

}

else{
  setColour(0,0);
  setColour(1,255);
  setColour(2,0);
}
}


