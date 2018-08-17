const int redPin = 11;
const int greenPin = 10;
const int bluePin = 9;

void setup() {

  setColourRgb(0,0,0);
}

void loop() {
  unsigned int rgbColour[3];


  rgbColour[0] = 0;
  rgbColour[1] = 0;
  rgbColour[2] = 255;  

  // Choose the colours to increment and decrement.
  for (int decColour = 0; decColour < 3; decColour += 1) {
    int incColour = decColour == 2 ? 0 : decColour + 1;

    // cross-fade the two colours.
    for(int i = 0; i < 255; i += 1) {
      rgbColour[decColour] -= 1;
      rgbColour[incColour] += 1;
      
      setColourRgb(rgbColour[0], rgbColour[1], rgbColour[2]);
      delay(50);
    }
  }
}

void setColourRgb(unsigned int red, unsigned int green, unsigned int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
 }
