/** Used to verify the functionality of the Power-On Reset (POR) and Low Voltage Detect (LVD) hardware inside of the Kinetis chip
 * 
 * main.cpp
 * Created Feb 21, 2018 by Patrick Hock
 * See chapter 17 https://cdn.sparkfun.com/datasheets/Dev/Arduino/Boards/K66P144M180SF5RMV2.pdf
 * 
 */

#include <kinetis.h>
#include <Arduino.h>



// System Reset Status Register 0 (RCM_SRS0) gives info about how resets are triggered


void resetInit(){
/*  To protect systems that must have LVD always
    on, configure the Power Mode Protection (PMPROT) register of the SMC module
    (SMC_PMPROT) to disallow any very low power or low leakage modes from being enabled. */
// POR and LVD are disabled in low power modes

//Disable all power modes other than "Normal Run"
SMC_PMPROT &=  ~(SMC_PMPROT_ALLS & SMC_PMPROT_AHSRUN & SMC_PMPROT_AVLLS & SMC_PMPROT_AVLP);


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

    resetInit();

    Serial.begin(9600);
    while (!Serial.available()){

    }

    

    Serial.print("SMC_PMPROT: ");
    Serial.print(SMC_PMPROT, BIN);

    Serial.print("\nPMC_LVDS1: ");
    Serial.print(PMC_LVDSC1, BIN);

    Serial.print("\nPMC_LVDS2: ");
    Serial.print(PMC_LVDSC2, BIN);


    

}


 