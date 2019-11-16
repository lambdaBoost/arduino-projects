// http://www.theorycircuit.com/arduino-internal-temperature-sensor/
// Internal Temperature Sensor
// Example sketch for ATmega328 types.

//this may be the best option - it does voltage too!:
//https://21stdigitalhome.blogspot.com/2014/10/trinket-attiny85-internal-temperature.html


//also promising to code here and change to write to mux[3:0]:
//https://web.archive.org/web/20140207142918/http://www.narkidae.com/research/atmega-core-temperature-sensor/


//ALTERNATIVE AT CODE HERE:
//http://andrey.mikhalchuk.com/2011/06/20/reading-attiny854525-internal-temperature-sensor.html

float temp;

void setup()
{

}

void loop()
{
  // Show the temperature in degrees Celcius.
  temp=GetTemp();
  delay(1000);
}

double GetTemp(void)
{
  unsigned int wADC;
  double t;

  // The internal temperature has to be used
  // with the internal reference of 1.1V.
  // Channel 8 can not be selected with
  // the analogRead function yet.

  // Set the internal reference and mux.
  ADMUX = (_BV(REFS1) | _BV(REFS0) | _BV(MUX3));
  ADCSRA |= _BV(ADEN);  // enable the ADC

  delay(20);            // wait for voltages to become stable.

  ADCSRA |= _BV(ADSC);  // Start the ADC

  // Detect end-of-conversion
  while (bit_is_set(ADCSRA,ADSC));

  // Reading register "ADCW" takes care of how to read ADCL and ADCH.
  wADC = ADCW;

  // The offset of 324.31 could be wrong. It is just an indication.
  t = (wADC - 324.31 ) / 1.22;

  // The returned temperature is in degrees Celcius.
  return (t);
}

