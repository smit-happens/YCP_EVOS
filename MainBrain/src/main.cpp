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
uint8_t globalTaskFlags [NUM_DEVICES] = { 0 };


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


void donePrechargeISR() {
    globalEventFlags              |= EF_UNITEK;
    globalTaskFlags[UNITEK]       |= TF_UNITEK_DONE_PRECHARGE;
}


//---------------------------------------------------------------
// Begin main function
int main(void)
{
    Serial.begin(9600);
    while (!Serial) {
        ; // wait for serial port to connect
    }

    Serial.println("Bootup stage");
    

    //Creating the controller singletons
    //Copying each controller location in memory
    CanController* canC         = CanController::getInstance();
    UnitekController* unitekC   = UnitekController::getInstance();
    OrionController* orionC     = OrionController::getInstance();
    CoolingController* coolingC = CoolingController::getInstance();
    DashController* dashC       = DashController::getInstance();
    LightController* lightC     = LightController::getInstance();
    GlcdController* glcdC       = GlcdController::getInstance();
    PedalController* pedalC     = PedalController::getInstance();
    SdCardController* sdCardC   = SdCardController::getInstance();
    BatlogController* batlogC   = BatlogController::getInstance();

    Logger* loggerC             = Logger::getInstance();
    
    
    //Calling init functions for each controller
    loggerC->init();
    canC->init();
    unitekC->init();
    orionC->init();
    coolingC->init();
    dashC->init();
    lightC->init();
    glcdC->init();
    pedalC->init();
    sdCardC->init();
    batlogC->init();

     loggerC->log("MAIN", "Bootup Begin", MSG_DEBUG);

    //local instance of the Stage manager class
    StageManager localStage = StageManager();


    //initialize the local and timer event flag variables
    uint32_t localEventFlags = 0;
    uint32_t timerEventFlags = 0;

    //initialize task flag array to zero
    uint8_t localTaskFlags[NUM_DEVICES] = { 0 };


    //Configure registers
    //Setting the analog read resolution to the maximum of the Teensy 3.6 (13 bit)
    analogReadResolution(13);
    //Teensy 3.6 analog write resolution needs to be set to 16 bit
    analogWriteResolution(16);

    //timer configuration
    //DO NOT START TIMERS HERE
    IntervalTimer myTimer;

    
    //attaching interrupts
    //Button interrupts
    attachInterrupt(MB_PRE_BTN, btnPrechargeISR, RISING);
    attachInterrupt(MB_RTD_BTN, btnRtdISR, RISING);
    attachInterrupt(MB_SHUTDOWN_BTN, btnShutdownISR, RISING);
    attachInterrupt(MB_STANDBY_BTN, btnStandbyISR, RISING);
    attachInterrupt(MB_WAYNE_BTN, btnWayneWorldISR, RISING);

    //Unitek interrupts
    attachInterrupt(MB_DONE_PRE, donePrechargeISR, FALLING);


    //initializing all the hardware
    localStage.bootTest();


    //Start 1ms timer (1000 usec)
    myTimer.begin(timerISR, 1000);

    // loggerC->log("MAIN", "Bootup Complete", MSG_DEBUG);

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

        //checking to see if we have new CAN messages to process
        if(canC->checkMail())
        {
            localEventFlags     |= EF_CAN;
            localTaskFlags[CAN] |= TF_CAN_NEW_MAIL;
        }

        interrupts();

        
        //transfering timer event flags to local EF
        localEventFlags |= timerEventFlags;


        //FIXME: handle Priorities better, right now we loop through them, later we want to handle CRITICAL prioritis first
        for(int priorityIterator = Priority::PRIORITY_CRITICAL; priorityIterator < Priority::NUM_PRIORITY; priorityIterator++)
        {
            localStage.currentStage = localStage.processStage((Priority)priorityIterator, &localEventFlags, localTaskFlags);

            //checking if we need to update the timers
            if(localEventFlags & EF_TIMER)
            {
                //bit shifting the timer Task Flags (TFs) to the upper half of the localEF var
                timerEventFlags |= localStage.processTimers();
                
                //clearing the EF so we don't trigger this again
                localEventFlags &= ~EF_TIMER;
            }
        }

    } //end of loop


    //SHUTDOWN function
    localStage.shutdown();


    return 0;
}

#endif
