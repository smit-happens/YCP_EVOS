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
#include <IntervalTimer.h>
#include "Controller/ControllerManager/ControllerManager.hpp"
#include "Model/Constants/EventMasks.hpp"

//global variable that all the ISRs will flag for their respective event to run
volatile uint32_t globalEventFlags = 0;


enum WorkflowStage
{
    BOOTUP,
    SELF_TEST,
    SUBSYSTEM_TEST,
    STANDBY,
    PRECHARGE,
    DRIVE,
    SHUTDOWN
};

//FIXME: TESTING CODE
void canISR() {
    globalEventFlags |= CAN_MESSAGE_EF0;
    // CAN_MESSAGE_EF0_CNT++;   //not worrying about counting right now
}
//FIXME: TESTING CODE



//---------------------------------------------------------------
// Begin main function
int main(void)
{
    Serial.begin(9600);
    // while (!Serial) {
    //     ; // wait for serial port to connect
    // }

    //initialize the local event flag variable
    uint32_t localEventFlags = 0;

    //creating the singletons and copying the location in memory
    // CanController* canC = ControllerManager::getCanC();
    // UnitekController* unitekC = ControllerManager::getUnitekC();

    //The first step when running is bootup
    WorkflowStage excecutingStep = BOOTUP;

    // using the builtin LED as a status light
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWriteFast(LED_BUILTIN, 1);


    //BOOTUP functions
        //Calling init functions for each controller
        // canC->init();
        // unitekC->init();

        //Configure registers
        //Brownout configuration

        //timer configuration
            //DO NOT START TIMERS HERE
        IntervalTimer myTimer;
        

    if(/* check for ShutdownEF*/ 1 )
    {
        excecutingStep = SELF_TEST;
    }
    else
    {
        excecutingStep = SHUTDOWN;
    }



    if(excecutingStep == SELF_TEST)
    {
        //Teensy SelfTest (internal functions)
        //SdCard check (read data, check if good)
        //Dash test (turn on all LEDS, user confirmation w/ encoder)


        if(/* check for ShutdownEF*/ 1 )
        {
            excecutingStep = SUBSYSTEM_TEST;
        }
        else
        {
            excecutingStep = SHUTDOWN;
        }
    }


    if(excecutingStep == SUBSYSTEM_TEST)
    {
        
        //Unitek check if okay
        //Orion check if okay
        //Cooling check if working
        //GLV battery level check
        


        if(/* check for ShutdownEF*/ 1 )
        {
            excecutingStep = STANDBY;
        }
        else
        {
            excecutingStep = SHUTDOWN;
        }
    }


    //Start timers
    myTimer.begin(canISR, 300000);


    //---------------------------------------------------------------
    // Begin main program Super Loop
    while(excecutingStep != SHUTDOWN)
    {
        while(excecutingStep == STANDBY)
        {
            noInterrupts();
            //Volatile operation for transferring flags from ISRs to local main
            localEventFlags |= globalEventFlags;
            globalEventFlags = 0;
            interrupts();

            
            //FIXME: TESTING CODE
            if(localEventFlags && CAN_MESSAGE_EF0)
            {
                if (Serial)
                {
                    Serial.println("sent CAN");
                }
                localEventFlags &= !CAN_MESSAGE_EF0;
            }

            //FIXME: TESTING CODE


            //Polling of subsystems (log status of each)
                //See if we're still good for transition to drive

            //Dashboard
                //LCD (boot logo)
            //TS master switch through BMS
            //Orion
            //Unitek
            //Cooling system
                //Warning: Turn cooling on

            //Notification: All systens go. Ready to Precharge
                //check for PrechargeEF
        }

        while(excecutingStep == DRIVE)
        {
            noInterrupts();
            //Volatile operation for transferring flags from ISRs to local main
            localEventFlags |= globalEventFlags;
            globalEventFlags = 0;
            interrupts();
            
            //Driving stuff



        }   //end of super loop ------------------------------------------------------
    }

    //SHUTDOWN function
        //EXTREMELY CRITICAL FUNCTIONS, no looping here
        //close out SdCard logs
        //SCADA_OK signal to false


    return 0;
}

#endif
