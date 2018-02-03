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
volatile uint32_t globalEventFlags = 0;




//FIXME: TESTING CODE
void timerISR() {
    globalEventFlags |= TIMER_EF0;
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

    StageManager localStage = StageManager();

    //The first step when running is bootup
    StageManager::WorkflowStage excecutingStep = StageManager::BOOTUP;

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
        int timerCAN = 0;
        int timerCooling = 0;
        int timerDash = 0;
        int timerGLCD = 0;
        
    //FIXME: TESTING CODE START
    pinMode(23, OUTPUT);
    pinMode(22, OUTPUT);
    pinMode(21, OUTPUT);
    pinMode(20, OUTPUT);

    bool LEDstate1 = false;
    bool LEDstate2 = false;
    bool LEDstate3 = false;
    bool LEDstate4 = false;
    //FIXME: TESTING CODE END

    if(/* check for ShutdownEF*/ 1 )
    {
        excecutingStep = StageManager::SELF_TEST;
    }
    else
    {
        excecutingStep = StageManager::SHUTDOWN;
    }



    if(excecutingStep == StageManager::SELF_TEST)
    {
        //Teensy SelfTest (internal functions)
        //SdCard check (read data, check if good)
        //Dash test (turn on all LEDS, user confirmation w/ encoder)


        if(/* check for ShutdownEF*/ 1 )
        {
            excecutingStep = StageManager::SUBSYSTEM_TEST;
        }
        else
        {
            excecutingStep = StageManager::SHUTDOWN;
        }
    }


    if(excecutingStep == StageManager::SUBSYSTEM_TEST)
    {
        
        //Unitek check if okay
        //Orion check if okay
        //Cooling check if working
        //GLV battery level check
        


        if(/* check for ShutdownEF*/ 1 )
        {
            excecutingStep = StageManager::STANDBY;
        }
        else
        {
            excecutingStep = StageManager::SHUTDOWN;
        }
    }


    //Start timers (1000 usec)
    myTimer.begin(timerISR, 1000);


    //---------------------------------------------------------------
    // Begin main program Super Loop
    while(excecutingStep != StageManager::SHUTDOWN)
    {
        while(excecutingStep == StageManager::STANDBY)
        {
            noInterrupts();
            //Volatile operation for transferring flags from ISRs to local main
            localEventFlags |= globalEventFlags;
            globalEventFlags = 0;
            interrupts();

            
            //FIXME: TESTING CODE START
            if(localEventFlags && TIMER_EF0)
            {
                timerCAN++;
                timerCooling++;
                timerDash++;
                timerGLCD++;

                if(timerCAN >= LED_1_POLL)
                {
                    localEventFlags |= CAN_EF1;
                    timerCAN = 0;

                }
                if(timerCooling >= LED_2_POLL)
                {
                    localEventFlags |= COOLING_EF2;
                    timerCooling = 0;
                }
                if(timerDash >= LED_3_POLL)
                {
                    localEventFlags |= DASH_EF3;
                    timerDash = 0;
                }
                if(timerGLCD >= LED_4_POLL)
                {
                    localEventFlags |= GLCD_EF4;
                    timerGLCD = 0;
                }
                

                localEventFlags &= ~TIMER_EF0;
            }

            if(localEventFlags && CAN_EF1)
            {
                
                digitalWriteFast(23, LEDstate1);

                LEDstate1 = !LEDstate1;

                localEventFlags &= ~CAN_EF1;
            }

            if(localEventFlags && COOLING_EF2)
            {
                
                digitalWriteFast(22, LEDstate2);

                LEDstate2 = !LEDstate2;

                localEventFlags &= ~COOLING_EF2;
            }

            if(localEventFlags && DASH_EF3)
            {
                
                digitalWriteFast(21, LEDstate3);

                LEDstate3 = !LEDstate3;

                localEventFlags &= ~DASH_EF3;
            }

            if(localEventFlags && GLCD_EF4)
            {
                
                digitalWriteFast(20, LEDstate4);

                LEDstate4 = !LEDstate4;

                localEventFlags &= ~GLCD_EF4;
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

        while(excecutingStep == StageManager::DRIVE)
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
