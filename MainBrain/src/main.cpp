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
#include "Controller/ControllerManager/ControllerManager.hpp"
#include "Model/Constants/EventMasks.hpp"

//global variable that all the ISRs will flag for their respective event to run
static volatile uint32_t globalEventFlags = 0;

enum WorkflowStage
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
    while (!Serial) {
        ; // wait for serial port to connect
    }

    //initialize the local event flag variable
    uint32_t localEventFlags = 0;

    //creating the singletons and copying the location in memory
    CanController* canC = ControllerManager::getCanC();
    UnitekController* unitekC = ControllerManager::getUnitekC();

    //The first step when running is bootup
    WorkflowStage excecutingStep = BOOTUP;

    // using the builtin LED as a status light
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWriteFast(LED_BUILTIN, 1);

    //BOOTUP function
    if(excecutingStep == BOOTUP)
    {
        //SD card init function
        canC->init();
        unitekC->init();
    }


    if(excecutingStep == SELF_TEST)
    {
        //SELF_TEST function
            //Teensy SelfTest
    }

    //---------------------------------------------------------------
    // Begin main program Super Loop
    while(excecutingStep != SHUTDOWN)
    {
        while(excecutingStep == STANDBY)
        {
            noInterrupts();
            //Volatile operation for transferring flags from ISRs to local main
            localEventFlags = globalEventFlags;
            interrupts();

            //standby stuff
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

            //should perform polling of subsystems 
            //to see if we're still okay for transition to drive
        }

        while(excecutingStep == DRIVE)
        {
            noInterrupts();
            //Volatile operation for transferring flags from ISRs to local main
            localEventFlags = globalEventFlags;
            interrupts();
            
            //Driving stuff


        }   //end of super loop ------------------------------------------------------
    }

    //SHUTDOWN function

    return 0;
}

#endif
