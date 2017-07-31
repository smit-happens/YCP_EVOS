/*
 * Safety System Integration
 * YCP FSAE Formula Electric Car Team 2017
 * Patrick Hock
 * July 30 2017
 * 
 * For now, this is mostly test code. 
 * Getting familiar with Arduino.
 * This program will blink an LED external to the Teensy.
 */
 
#define BSPD_ERR_LED  33
#define BSPD_IN 23
uint8_t interruptTracker = 0;

void setup() {
  
  pinMode(BSPD_ERR_LED, OUTPUT);  // Sets pin 33 as an output
  pinMode(BSPD_IN, INPUT);  // Sets pin 23 as input

  attachInterrupt(digitalPinToInterrupt(BSPD_IN), BSPD_Fault, RISING);
  
}

void loop() {
 
// Check for BSPD Error
if(bitRead(interruptTracker, 0))
{
  digitalWrite(BSPD_ERR_LED, HIGH);
  bitWrite(interruptTracker, 0, 0);    // Resets the "interrupt flag" for BSPD Error
}

}

void BSPD_Fault()
{
  noInterrupts();

  // changes bit 0 to a one so that Loop() can handle the error
  
  bitWrite(interruptTracker, 0, 1); // Sets "interrupt flag" for BSPD error
  
  interrupts();
  
  return;
}


