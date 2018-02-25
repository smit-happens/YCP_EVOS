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
volatile uint8_t  globalTaskFlags[NUM_DEVICES];


//Start of ISR declarations
void timerISR() {
    globalEventFlags |= EF_TIMER;
}



//---------------------------------------------------------------
// Begin main function
int main(void)
{
    // Serial.begin(9600);
    // while (!Serial) {
    //     ; // wait for serial port to connect
    // }

    // Serial.print("program started");


    //Creating the controller singletons
    //Copying each controller location in memory
    CanController* canC         = CanController::getInstance();
    UnitekController* unitekC   = UnitekController::getInstance();
    OrionController* orionC     = OrionController::getInstance();
    CoolingController* coolingC = CoolingController::getInstance();
    DashController* dashC       = DashController::getInstance();
    LightController* lightC     = LightController::getInstance();
    ImdController* imdC         = ImdController::getInstance();
    GlcdController* glcdC       = GlcdController::getInstance();
    PedalController* pedalC     = PedalController::getInstance();
    SdCardController* sdCardC   = SdCardController::getInstance();
    BatlogController* batlogC   = BatlogController::getInstance();

    //local instance of the Stage manager class
    StageManager localStage = StageManager();

    //The first step when running is bootup
    StageManager::Stage excecutingStage = StageManager::STAGE_BOOTUP;

    //EventTask instance
    EventTask deviceTasks = EventTask();


    //initialize the local and timer event flag variables
    uint32_t localEventFlags = 0;
    uint32_t timerEventFlags = 0;

    // using the builtin LED as a status light (for now)
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWriteFast(LED_BUILTIN, 1);


    //Bootup stage functions (anything var declared in an if/else falls out of scope afterward)
        //Calling init functions for each controller
        canC->init();
        unitekC->init();
        orionC->init();
        coolingC->init();
        dashC->init();
        lightC->init();
        imdC->init();
        glcdC->init();
        pedalC->init();
        sdCardC->init();
        batlogC->init();

        //Configure registers
            //Brownout configuration

        //timer configuration
            //DO NOT START TIMERS HERE
        IntervalTimer myTimer;

        //Dashboard
            //LCD (boot logo)

        if(/* check for ShutdownEF*/ 1 )
        {
            excecutingStage = StageManager::STAGE_SELF_TEST;
        }
        else
        {
            excecutingStage = StageManager::STAGE_SHUTDOWN;
        }


    //excecuting all the self test oriented functions
    if(excecutingStage == StageManager::STAGE_SELF_TEST)
    {
        //Teensy SelfTest (internal functions)
        //SdCard check (read data, check if good)
        //Dash test (turn on all LEDS, user confirmation w/ encoder)

        if(/* check for ShutdownEF*/ 1 )
        {
            excecutingStage = StageManager::STAGE_SUBSYSTEM_TEST;
        }
        else
        {
            excecutingStage = StageManager::STAGE_SHUTDOWN;
        }
    }


    //Executing all the subsystem test oriented functions
    if(excecutingStage == StageManager::STAGE_SUBSYSTEM_TEST)
    {
        
        //Unitek check if okay
        //Orion check if okay
        //Cooling check if working
        //GLV batlog level check
        
        //assuming everything is okay
            //Notification: All systens go. Ready to Precharge

        if(/* check for ShutdownEF*/ 1 )
        {
            excecutingStage = StageManager::STAGE_STANDBY;
        }
        else
        {
            excecutingStage = StageManager::STAGE_SHUTDOWN;
        }
    }


    //Start 1ms timer (1000 usec)
    myTimer.begin(timerISR, 1000);


    //---------------------------------------------------------------
    // Begin main program Super Loop
    while(excecutingStage != StageManager::STAGE_SHUTDOWN)
    {
        noInterrupts();
        //Volatile operation for transferring flags from ISRs to local main
        localEventFlags |= globalEventFlags;
        globalEventFlags = 0;

        //Transfer global tasks to local tasks
        deviceTasks.setAllTaskFlags(globalTaskFlags);
        interrupts();

        //for every stage, we check what events need to be handled with varying priority levels
        //FIXME: handle Priorities better, right now we loop through them, later we want to handle CRITICAL prioritis first
        switch(excecutingStage)
        {
            case StageManager::STAGE_STANDBY:

                //looping through the events of varying priorities
                for(int priorityIterator = Priority::PRIORITY_CRITICAL; priorityIterator < Priority::PRIORITY_LOW; priorityIterator++)
                {
                    excecutingStage = localStage.processEventsStandby(localEventFlags, (Priority)priorityIterator);

                    //checking if we need to update the timers
                    if(localEventFlags && EF_TIMER)
                    {
                        //bit shifting the timer Task Flags (TFs) to the upper half of the localEF var
                        timerEventFlags |= localStage.processTimers(excecutingStage);
                        
                        //clearing the EF so we don't trigger this again
                        localEventFlags &= ~EF_TIMER;
                    }
                }

                //All low priority events are handled by the timer event flags
                localStage.processEventsStandby(timerEventFlags, Priority::PRIORITY_LOW);

            break;


            case StageManager::STAGE_PRECHARGE:

                for(int priorityIterator = Priority::PRIORITY_CRITICAL; priorityIterator < Priority::PRIORITY_LOW; priorityIterator++)
                {
                    localStage.processEventsPrecharge(localEventFlags, (Priority)priorityIterator);

                    //checking if we need to update the timers
                    if(localEventFlags && EF_TIMER)
                    {
                        //bit shifting the timer Task Flags (TFs) to the upper half of the localEF var
                        timerEventFlags |= localStage.processTimers(excecutingStage);
                        
                        //clearing the EF so we don't trigger this again
                        localEventFlags &= ~EF_TIMER;
                    }
                }

                localStage.processEventsPrecharge(timerEventFlags, Priority::PRIORITY_LOW);

            break;


            case StageManager::STAGE_ENERGIZED:

                for(int priorityIterator = Priority::PRIORITY_CRITICAL; priorityIterator < Priority::PRIORITY_LOW; priorityIterator++)
                {
                    localStage.processEventsEnergized(localEventFlags, (Priority)priorityIterator);

                    //checking if we need to update the timers
                    if(localEventFlags && EF_TIMER)
                    {
                        //bit shifting the timer Task Flags (TFs) to the upper half of the localEF var
                        timerEventFlags |= localStage.processTimers(excecutingStage);
                        
                        //clearing the EF so we don't trigger this again
                        localEventFlags &= ~EF_TIMER;
                    }
                }
                
                localStage.processEventsEnergized(timerEventFlags, Priority::PRIORITY_LOW);

            break;


            case StageManager::STAGE_DRIVING:

                for(int priorityIterator = Priority::PRIORITY_CRITICAL; priorityIterator < Priority::PRIORITY_LOW; priorityIterator++)
                {
                    localStage.processEventsDriving(localEventFlags, (Priority)priorityIterator);

                    //checking if we need to update the timers
                    if(localEventFlags && EF_TIMER)
                    {
                        //bit shifting the timer Task Flags (TFs) to the upper half of the localEF var
                        timerEventFlags |= localStage.processTimers(excecutingStage);
                        
                        //clearing the EF so we don't trigger this again
                        localEventFlags &= ~EF_TIMER;
                    }
                }
                
                localStage.processEventsDriving(timerEventFlags, Priority::PRIORITY_LOW);

            break;


            default:

                //shouldn't get here

            break;

        }   //end of super loop ------------------------------------------------------
    }

    //SHUTDOWN function
        //EXTREMELY CRITICAL FUNCTIONS, no looping here
        //close out SdCard logs
        //SCADA_OK signal to false


    return 0;
}

#endif
