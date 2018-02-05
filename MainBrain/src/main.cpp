/**  A one line description of the class.
 *
 * main.cpp
 * Created 11-06-17 By: Smitty
 *
 * A longer description.
 */

// Unit Testing gaurd
#ifndef UNIT_TEST

#include <IntervalTimer.h>
#include "Manager/StageManager/StageManager.hpp"

//global variable that all the ISRs will flag for their respective event to run
volatile uint16_t globalEventFlags = 0;


//Start of ISR declarations

void timerISR() {
    globalEventFlags |= EF0_TIMER;
}



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

    StageManager localStage = StageManager();

    //The first step when running is bootup
    StageManager::Stage excecutingStage = StageManager::BOOTUP;

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

        
    //FIXME: TESTING CODE START
    pinMode(23, OUTPUT);
    pinMode(22, OUTPUT);
    pinMode(21, OUTPUT);
    pinMode(20, OUTPUT);
    //FIXME: TESTING CODE END

    if(/* check for ShutdownEF*/ 1 )
    {
        excecutingStage = StageManager::SELF_TEST;
    }
    else
    {
        excecutingStage = StageManager::SHUTDOWN;
    }



    if(excecutingStage == StageManager::SELF_TEST)
    {
        //Teensy SelfTest (internal functions)
        //SdCard check (read data, check if good)
        //Dash test (turn on all LEDS, user confirmation w/ encoder)


        if(/* check for ShutdownEF*/ 1 )
        {
            excecutingStage = StageManager::SUBSYSTEM_TEST;
        }
        else
        {
            excecutingStage = StageManager::SHUTDOWN;
        }
    }


    if(excecutingStage == StageManager::SUBSYSTEM_TEST)
    {
        
        //Unitek check if okay
        //Orion check if okay
        //Cooling check if working
        //GLV battery level check
        


        if(/* check for ShutdownEF*/ 1 )
        {
            excecutingStage = StageManager::STANDBY;
        }
        else
        {
            excecutingStage = StageManager::SHUTDOWN;
        }
    }


    //Start timers (1000 usec)
    myTimer.begin(timerISR, 1000);


    //---------------------------------------------------------------
    // Begin main program Super Loop
    while(excecutingStage != StageManager::SHUTDOWN)
    {
        if(excecutingStage == StageManager::STANDBY)
        {
            noInterrupts();
            //Volatile operation for transferring flags from ISRs to local main
            localEventFlags |= globalEventFlags;
            globalEventFlags = 0;
            interrupts();

            //Timer EF check
            if(localEventFlags && EF0_TIMER)
            {
                //bit shifting the timer Task Flags (TFs) to the upper half of the localEF var
                localEventFlags |= localStage.processTimers() << 16;

                // Serial.print("localEventFlags: ");
                // Serial.println(localEventFlags, BIN);
                
                //clearing the EF so we don't trigger this again
                localEventFlags &= ~EF0_TIMER;
            }


            //FIXME: TESTING CODE START

            //checking the upper bits of th LocalEF var
            if(localEventFlags && (0x0001 << 16))
            {
                localStage.testLed1();
                localEventFlags &= ~(0x0001 << 16);
            }

            if(localEventFlags && (0x0002 << 16))
            {
                localStage.testLed2();
                localEventFlags &= ~(0x0002 << 16);
                
            }

            if(localEventFlags && (0x0004 << 16))
            {
                localStage.testLed3();
                localEventFlags &= ~(0x0004 << 16);
                
            }

            if(localEventFlags && (0x0008 << 16))
            {
                localStage.testLed4();
                localEventFlags &= ~(0x0008 << 16);
                
            }


            //FIXME: TESTING CODE END


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

        if(excecutingStage == StageManager::DRIVE)
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
