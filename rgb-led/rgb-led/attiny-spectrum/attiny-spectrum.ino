/* Three PWM Outputs */

// ATtiny85 outputs
const int Red = 0;
const int Green = 1;
const int Blue = 2;

volatile uint8_t* Port[] = {&OCR0A, &OCR0B, &OCR1B};
int Pin[] = {0, 1, 4};

void setup() {
  pinMode(Pin[Red], OUTPUT);
  pinMode(Pin[Green], OUTPUT);
  pinMode(Pin[Blue], OUTPUT);
  // Configure counter/timer0 for fast PWM on PB0 and PB1
  TCCR0A = 3<<COM0A0 | 3<<COM0B0 | 3<<WGM00;
  TCCR0B = 0<<WGM02 | 3<<CS00; // Optional; already set
  // Configure counter/timer1 for fast PWM on PB4
  GTCCR = 1<<PWM1B | 3<<COM1B0;
  TCCR1 = 3<<COM1A0 | 7<<CS10;
}

// Sets colour Red=0 Green=1 Blue=2 to specified intensity 0 (off) to 255 (max)
void SetColour (int colour, int intensity) {
  *Port[colour] = 255 - intensity;
}

void loop() {
  for (int colour=0; colour<3; colour++) {
    SetColour((colour+2) % 3, 0);
    for (int i=0; i <= 255; i++) {
      SetColour((colour+1) % 3, i);
      SetColour(colour, 255-i);
      delay(25);
    }
  }
}
