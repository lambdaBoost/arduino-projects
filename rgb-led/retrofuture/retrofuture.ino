const int redPin = 11;
const int greenPin = 10;
const int bluePin = 9;

void setup() {

  setColourRgb(0,0,0);
}

void loop() {
  unsigned int rgbColour[3];


//start with blue
  rgbColour[0] = 0;
  rgbColour[1] = 0;
  rgbColour[2] = 255;  

  //increment green (left leg of triangle) go to 0,255,255
  for (int i=0 ; i<255 ; i++){

    setColourRgb(0,i,255);
    delay(5);
  }

  //increment red and decrement blue (go to 255,128,255)
  for (int i=0 ; i<255 ; i++){

    setColourRgb(i,255-(128* i/255) , 255); //second to 180
    delay(5);
  }

  //decrement green (go to 255,0,128) - note slower delay to keep in pink sector longer
  for (int i=128; i>0;i--){//180
    setColourRgb(255,i,127+i);
    delay(5);
  }

  //decrement red, increment blue (bottom leg of triangle) go to 0,0,255
  for (int i=0 ; i<255 ; i++){
    setColourRgb(255-i,0,128+(i/2));
    delay(5);
  }


 
  }


void setColourRgb(unsigned int red, unsigned int green, unsigned int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
 }
