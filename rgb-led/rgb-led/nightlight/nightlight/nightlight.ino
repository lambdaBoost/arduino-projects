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
const int Red = 2;
const int Green = 0;
const int Blue = 1;
const int tempPin = A3;

volatile uint8_t* Port[] = {&OCR0A, &OCR0B, &OCR1B};
int Pin[] = {0, 1, 4};
int reading;
float voltage;
float temperature;
float red;
float blue;


void setup() {
  pinMode(Pin[Red], OUTPUT);
  pinMode(Pin[Green], OUTPUT);
  pinMode(Pin[Blue], OUTPUT);
}
// Sets colour Red=0 Green=1 Blue=2 to specified intensity 0 (off) to 255 (max)
void setColour (int colour, int intensity) {
  analogWrite(colour, 255- intensity);
}

void loop() {


reading = analogRead(tempPin);

voltage = reading *5.0;
voltage /=1024.0;

temperature = ((voltage-0.5) * 100); 

delay(20);

red = map(temperature,15,24,0,1024);
blue = 1024-red;


//gbr
setColour(0,0);
setColour(1,blue);
setColour(2,red);

//delay(1);

}


