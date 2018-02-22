/** Used to verify the functionality of the Power-On Reset (POR) and Low Voltage Detect (LVD) hardware inside of the Kinetis chip
 * 
 * main.cpp
 * Created Feb 21, 2018 by Patrick Hock
 * See chapter 17 https://cdn.sparkfun.com/datasheets/Dev/Arduino/Boards/K66P144M180SF5RMV2.pdf
 * 
 */

#include <kinetis.h>
#include <core_pins.h>
#include <Arduino.h>



// System Reset Status Register 0 (RCM_SRS0) gives info about how resets are triggered


void resetInit(){
/*  To protect systems that must have LVD always
    on, configure the Power Mode Protection (PMPROT) register of the SMC module
    (SMC_PMPROT) to disallow any very low power or low leakage modes from being enabled. */
// POR and LVD are disabled in low power modes

//Disable all power modes other than "Normal Run"
SMC_PMPROT &=  ~(SMC_PMPROT_ALLS | SMC_PMPROT_AHSRUN | SMC_PMPROT_AVLLS | SMC_PMPROT_AVLP);


// Enable LVD to trigger a reset when voltage is lower than the set threshold
//TODO: Figure out which LVD threshold we want
PMC_LVDSC1 |= PMC_LVDSC1_LVDRE;


/*LVW Flag (LVWF) may be 1 after power-on reset, therefore to use LVW interrupt function, 
 before enabling LVW Interrupt Enable (LVWIE), LVWF must be cleared by 
 writing LVW Acknowledge (LVWACK) first*/
PMC_LVDSC2 |= PMC_LVDSC2_LVWACK; 

// TODO: Figure out which LVW trip point we want
// Configure Low Voltage Warning (LVW) to trigger a hardware interrupt.
PMC_LVDSC2 |= PMC_LVDSC2_LVWIE;


}


int main(void){

    //resetInit();

    // Serial.begin(9600);
    while (!Serial.available()){

    }

    Serial.print("SMC_PMPROT: ");
    Serial.print(SMC_PMPROT, BIN);

    SMC_PMPROT &=  ~(SMC_PMPROT_ALLS | SMC_PMPROT_AHSRUN | SMC_PMPROT_AVLLS | SMC_PMPROT_AVLP);
    //SMC_PMPROT = 0;

    Serial.print("\nSMC_PMPROT: ");
    Serial.print(SMC_PMPROT, BIN);

    Serial.print("\nPMC_LVDS1: ");
    Serial.print(PMC_LVDSC1, BIN);

    PMC_LVDSC1 |= PMC_LVDSC1_LVDRE;

    Serial.print("\nPMC_LVDS1: ");
    Serial.print(PMC_LVDSC1, BIN);

    // GPIO Test Code
    // Pin 23 on Teensy is Port C Pin 2

    SIM_SCGC5 = SIM_SCGC5_PORTC;    // Enable clock to port C
    PORTC_PCR2 &= ~PORT_PCR_MUX_MASK;
    PORTC_PCR2 |= PORT_PCR_MUX(1);  // Set Pin 23 (PORT C Pin 2) to GPIO


    Serial.print("\nGPIOC_PDDR: ");
    Serial.print(GPIOC_PDDR, BIN);    

    GPIOC_PDDR |= 1ul << 2;   // Set pin 2 (port c) as output

    Serial.print("\nGPIOC_PDDR: "); 
    Serial.print(GPIOC_PDDR, BIN);


    while(1) {
    GPIOC_PTOR = 1ul << 2;
    delay(500); 
    
    }

}


 