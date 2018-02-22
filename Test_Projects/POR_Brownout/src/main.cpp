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
SMC_PMPROT = (SMC_PMPROT & !SMC_PMPROT_ALLS & !SMC_PMPROT_AHSRUN & !SMC_PMPROT_AVLLS & SMC_PMPROT_AVLP);


// Enable LVD to trigger a reset


}


int main(void){

    resetInit();
    Serial.begin(9600);


}


