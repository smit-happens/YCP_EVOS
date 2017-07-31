/*
 * Safety System Integration
 * YCP FSAE Formula Electric Car Team 2017
 * Patrick Hock
 * July 30 2017
 * 
 * For now, this is mostly test code. Follows similar structure to the
 * Super Dooper Looper 
 */


#define BSPD_ERR_LED  33
#define BSPD_IN 23

// Super loop variable to track which interrupts have occurred
uint8_t globalInterruptTracker = 0; 


int main(void)
{
  // Setup code. Initializes I/O pins and enables interrupts
  pinMode(BSPD_ERR_LED, OUTPUT);  // Sets pin 33 as an output
  pinMode(BSPD_IN, INPUT);  // Sets pin 23 as input
  attachInterrupt(digitalPinToInterrupt(BSPD_IN), BSPD_Fault, RISING);

  int localInterruptTracker;
  
  // Super dooper looper
  while(1)
  {
    /*
     * All interrupts must be disabled while copying the global interrupt tracker to 
     * the local variable. After interrupts are re-enabled, any interrupts that occur
     * while this loop is executing will be handled on the next iteration of the loop
     */
    noInterrupts(); // disables all interrupts
    
    localInterruptTracker = globalInterruptTracker;
    globalInterruptTracker = 0;
    
    interrupts();   // re-enables interrupts

    
    // Check for BSPD Error
    if(bitRead(localInterruptTracker, 0))
    {
      digitalWrite(BSPD_ERR_LED, HIGH);
      bitWrite(localInterruptTracker, 0, 0);    // Resets the "interrupt flag" for BSPD Error
    }
    
  }
}

void BSPD_Fault()
{
  /*
   * updates bit 0 of the globalInterruptTracker to indicate that a BSPD 
   * error has occurred
   */
  
  bitWrite(globalInterruptTracker, 0, 1); // Sets "interrupt flag" for BSPD error

  return;
}
