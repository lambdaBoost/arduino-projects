
const int switchPin = 2;
const int motorPin1 = 3;
const int motorPin2 = 4;
const int enablePin = 9;

int  buttonState;

void  setup() {
 Serial.begin(9600);
 
 pinMode(switchPin, INPUT);
 
 pinMode(motorPin1, OUTPUT);
 pinMode(motorPin2, OUTPUT);
 pinMode(enablePin, OUTPUT);
 
 digitalWrite(enablePin, LOW);
 digitalWrite(motorPin1, HIGH);
 digitalWrite(motorPin2, LOW);   
}

void  loop() {
 // read the state of the pushbutton value:
 buttonState = digitalRead(switchPin);

 // check if the pushbutton is pressed.
 // if it is, the buttonState is HIGH:
 if (buttonState == HIGH) {     
   // turn motor on:    
   Serial.println("Button pressed");
   digitalWrite(enablePin, HIGH);
 } 
 else {
   // turn motor off:
   Serial.println("Button not pressed");
   digitalWrite(enablePin, LOW);
 }  
}

