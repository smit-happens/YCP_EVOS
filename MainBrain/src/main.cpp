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
uint8_t* globalTaskFlags = new uint8_t[NUM_DEVICES];


//Start of ISR declarations
void timerISR() {
    globalEventFlags |= EF_TIMER;
}


//setting the appropiate event and task flags for Precharge btn press
void btnPrechargeISR() {
    globalEventFlags      |= EF_DASH;
    globalTaskFlags[DASH] |= TF_DASH_PRECHARGE;
}


//setting the appropiate event and task flags for Ready to drive (RTD) btn press
void btnRtdISR() {
    globalEventFlags      |= EF_DASH;
    globalTaskFlags[DASH] |= TF_DASH_RTD;
}


//setting the appropiate event and task flags for Shutdown btn press
void btnShutdownISR() {
    globalEventFlags      |= EF_DASH;
    globalTaskFlags[DASH] |= TF_DASH_SHUTDOWN;
}


//setting the appropiate event and task flags for standby btn press
void btnStandbyISR() {
    globalEventFlags      |= EF_DASH;
    globalTaskFlags[DASH] |= TF_DASH_STANDBY;
}


//setting the appropiate event and task flags for Wayne World btn press
void btnWayneWorldISR() {
    globalEventFlags      |= EF_DASH;
    globalTaskFlags[DASH] |= TF_DASH_WAYNE_WORLD;
}


//---------------------------------------------------------------
// Begin main function
int main(void)
{
    Serial.begin(9600);
    // while (!Serial) {
    //     ; // wait for serial port to connect
    // }

    Serial.println("Bootup stage");

    //Bootup stage functions (any var declared in an if/else falls out of scope afterward)

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
    localStage.currentStage = StageManager::STAGE_BOOTTEST;


    //initialize the local and timer event flag variables
    uint32_t localEventFlags = 0;
    uint32_t timerEventFlags = 0;

    //initialize array to zero
    uint8_t* localTaskFlags = new uint8_t[NUM_DEVICES];

    //Configure registers
    //Setting the analog read resolution to the maximum of the Teensy 3.6 (13 bit)
    analogReadResolution(13);

    //timer configuration
    //DO NOT START TIMERS HERE
    IntervalTimer myTimer;

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

    //attaching interrupts
    //Button interrupts
    attachInterrupt(MB_PRE_BTN, btnPrechargeISR, RISING);
    attachInterrupt(MB_RTD_BTN, btnRtdISR, RISING);
    attachInterrupt(MB_SHUTDOWN_BTN, btnShutdownISR, RISING);
    attachInterrupt(MB_STANDBY_BTN, btnStandbyISR, RISING);
    attachInterrupt(MB_WAYNE_BTN, btnWayneWorldISR, RISING);

    //Dashboard
        //LCD (boot logo)
        // dashC->

        //Teensy SelfTest (internal functions if any)
        
        //SdCard check (read data, check if good)
        //Dash test (turn on all LEDS, user confirmation w/ encoder)
        lightC->test();

        //Unitek check if okay
        //Orion check if okay
        //Cooling check if working
        //GLV batlog level check
        
        //assuming everything is okay
            //Notification: All systens go. Ready to Precharge

    if(/* check for ShutdownEF*/ 1 )
    {
        localStage.currentStage = StageManager::STAGE_STANDBY;
    }
    else
    {
        localStage.currentStage = StageManager::STAGE_SHUTDOWN;
    }


    //Start 1ms timer (1000 usec)
    myTimer.begin(timerISR, 1000);


    //---------------------------------------------------------------
    // Begin main program Super Loop
    while(localStage.currentStage != StageManager::STAGE_SHUTDOWN)
    {
        noInterrupts();
        //Volatile operation for transferring flags from ISRs to local main
        localEventFlags |= globalEventFlags;
        globalEventFlags = 0;
        
        //clearing global task flags for every device
        for(int i = 0; i < DeviceName::NUM_DEVICES; i++ )
        {
            localTaskFlags[i] |= globalTaskFlags[i];
            globalTaskFlags[i] = 0;
        }

        interrupts();

        //FIXME: handle Priorities better, right now we loop through them, later we want to handle CRITICAL prioritis first
        for(int priorityIterator = Priority::PRIORITY_CRITICAL; priorityIterator < Priority::PRIORITY_LOW; priorityIterator++)
        {
            localStage.currentStage = localStage.processStage((Priority)priorityIterator, &localEventFlags, localTaskFlags);

            //checking if we need to update the timers
            if(localEventFlags && EF_TIMER)
            {
                //bit shifting the timer Task Flags (TFs) to the upper half of the localEF var
                timerEventFlags |= localStage.processTimers();
                
                //clearing the EF so we don't trigger this again
                localEventFlags &= ~EF_TIMER;
            }
        }

        //All low priority events are handled by the timer event flags
        localStage.processStage(Priority::PRIORITY_LOW, &timerEventFlags, localTaskFlags);

    } //end of loop


    //SHUTDOWN function
        //EXTREMELY CRITICAL FUNCTIONS, no looping here
        //close out SdCard logs
        //SCADA_OK signal to false


    return 0;
}

#endif
