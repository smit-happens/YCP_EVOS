/**  A one line description of the class.
 *
 * main.cpp
 * Created 11-06-17 By: Smitty
 *
 * A longer description.
 */

// Unit Testing gaurd
#ifndef UNIT_TEST

#include <Arduino.h>
#include "Manager/Manager.hpp"

//global variable that all the ISRs will flag for their respective event to run
uint16_t globalEventFlags = 0;

enum workflowStage
{
    BOOTUP,
    SELF_TEST,
    SUBSYSTEM_TEST,
    STANDBY,
    DRIVE,
    SHUTDOWN
};


//---------------------------------------------------------------
// Begin main function
int main(void)
{
    Serial.begin(9600);

    //initialize the local event 
    uint32_t localEventFlags = 0;

    //creating the singletons and copying the location in memory
    CanController* canC = Manager::getCanC();
    UnitekController* unitekC = Manager::getUnitekC();

    //The first step when running is bootup
    workflowStage ExcecutingStep = BOOTUP;

    // using the builtin LED as a status light
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWriteFast(LED_BUILTIN, 1);

    //BOOTUP function
        //SD card init function
        canC->init();
        unitekC->init();

    //SELF_TEST function
        //Teensy SelfTest

    //SUBSYSTEM_TEST function
        //subsystem checks (log status of each)

        //Dashboard
        //LCD (boot logo)
        //TS master switch through BMS/BSPD
        //Orion
        //Unitek
        //Cooling system
            //Warning: Turn cooling on

        //Notification: All systens go. Ready to Precharge
            //wait for precharge button


    //---------------------------------------------------------------
    // Begin main program Super Loop
    while(1)
    {
        noInterrupts();
        // localEventFlags = globalEventFlags;
        interrupts();

        if(ExcecutingStep == STANDBY)
        {
            //standby stuff
            //should perform polling of subsystems 
            //to see if we're still okay for transition to drive

        }


        if(ExcecutingStep == DRIVE)
        {
            //Driving stuff

        }

    }   //end of super loop ------------------------------------------------------

    //SHUTDOWN function

    return 0;
}

#endif
