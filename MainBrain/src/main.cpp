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


enum workflowStage
{
    BOOTUP,
    SELF_TEST,
    SUBSYSTEM_TEST,
    DRIVE,
    SHUTDOWN
};


//---------------------------------------------------------------
// Begin main function
int main(void)
{
    Serial.begin(9600);

    //creating the singletons and copying the location in memory
    CanController* canC = Manager::getCanC();
    UnitekController* unitekC = Manager::getUnitekC();

    //The first step when running is bootup
    workflowStage ExcecutingStep = BOOTUP;

    // using the builtin LED as a status light
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWriteFast(LED_BUILTIN, 1);


    //---------------------------------------------------------------
    // Begin main program loop
    while(1)
    {
        noInterrupts();
        // localEventFlags
        interrupts();

        switch(ExcecutingStep)
        {
            case BOOTUP:
            {
                //SD card init function
                canC->init();
                unitekC->init();

                if(/* Condition is met */ 1 )
                    ExcecutingStep = SELF_TEST;

                break;
            }


            case SELF_TEST:
            {
                //Teensy SelfTest

                break;
            }


            case SUBSYSTEM_TEST:
            {
                //subsystem checks (log status of each)

                //Dashboard
                //LCD (boot logo)
                //TS master switch through BMS/BSPD
                //Orion
                //Unitek
                //Cooling system
                    //Alert: Turn cooling on

                //Notification: All systens go. Ready to Precharge
                    //wait for precharge button

                break;
            }


            case DRIVE:
            {
                //Driving stuff

                break;
            }


            case SHUTDOWN:
            {
                //Shutdown stuff

                break;
            }
        }   //end of switch

        

    }

    return 0;
}

#endif
