/*
 * Safety System Integration
 * YCP FSAE Formula Electric Car Team 2017
 * Patrick Hock
 * July 30 2017
 * 
 * For now, this is mostly test code. Follows similar structure to the
 * Super Dooper Looper 
 */
#include "TimerOne.h"

#define BSPD_ERR_LED  33
#define BSPD_IN 23
#define ACCEL_IN 32

// Super loop variable to track which interrupts have occurred
uint8_t glblIntTrack = 0; 


int main(void)
{
  // Setup code. Initializes I/O pins and enables interrupts
  pinMode(BSPD_ERR_LED, OUTPUT);  // Sets pin 33 as an output
  pinMode(BSPD_IN, INPUT);  // Sets pin 23 as input
  attachInterrupt(digitalPinToInterrupt(BSPD_IN), ISR_BSPD_Fault, RISING);
  int lclIntTrack;

  // Following is test code for Accelerator pedal position sensing
  Timer1.initialize(10000);  // Sets a 10ms period for the timer
  Timer1.attachInterrupt(ISR_ADC_TIMER);
  int adcValue;
  
  Serial.begin(9600); // Starts 9600 baud serial connection for ADC reading
  delay(500);
  
  // Super dooper looper
  while(1)
  {
    /*
     * All interrupts must be disabled while copying the global interrupt tracker to 
     * the local variable. After interrupts are re-enabled, any interrupts that occur
     * while this loop is executing will be handled on the next iteration of the loop
     * 
     * Bit 0 is BSPD error interrupt, bit 1 is ADC timer interrupt
     */
     
    noInterrupts(); // disables all interrupts
    
    lclIntTrack = glblIntTrack;
    glblIntTrack = 0;
    
    interrupts();   // re-enables interrupts

    
    // Check for BSPD Error
    if(bitRead(lclIntTrack, 0))
    {
      digitalWrite(BSPD_ERR_LED, HIGH);
      bitWrite(lclIntTrack, 0, 0);    // Resets the "interrupt flag" for BSPD Error
    }


    // Check for timer pop
    if(bitRead(lclIntTrack, 1))
    {
      adcValue = analogRead(ACCEL_IN);
      adcValue = 100 * adcValue / 1024;
      Serial.println(adcValue);
      bitWrite(lclIntTrack, 1, 0);    // Resets the "interrupt flag" for Timer pop
    }

    
  }
}


void ISR_BSPD_Fault()
{
  /*
   * updates bit 0 of the glblIntTrack to indicate that a BSPD 
   * error has occurred
   */
  
  bitWrite(glblIntTrack, 0, 1); // Sets "interrupt flag" for BSPD error

}



void ISR_ADC_TIMER()
{
  /*
   * Updates bit 1 of glblIntTrack to indicate that timer has overflowed
   */
   
   bitWrite(glblIntTrack, 1, 1);  // Sets flag for ADC timer

}

