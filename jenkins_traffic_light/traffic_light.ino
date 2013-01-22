/*
  Traffic Light
  Turns on an LED on if its get an byte input from serial device
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int ledGreen = 13;
int ledYellow = 10;
int ledRed = 7;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(ledGreen, OUTPUT);     
  pinMode(ledYellow, OUTPUT);   
  pinMode(ledRed, OUTPUT);   
  Serial.begin(9600);
}

void reset() {
  digitalWrite(ledGreen, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(ledYellow, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(ledRed, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);  
}
  
void setFail() {
  digitalWrite(ledRed, HIGH);   
}

void setSuccess() {
  digitalWrite(ledGreen, HIGH);   
}

void setBuild() {
  digitalWrite(ledYellow, HIGH);   
}

void switchLight(char incomingChar) {
  reset();
  
  if (incomingChar == 's') {
    setSuccess();
  } else if (incomingChar == 'b') {
    setBuild();
  } else if (incomingChar == 'f') {
    setFail();
  }
  
  delay(1000);
}

// the loop routine runs over and over again forever:
void loop() {
  if (Serial.available() > 0) {
    char incomingChar = Serial.read();
    switchLight(incomingChar);
  }  
}
