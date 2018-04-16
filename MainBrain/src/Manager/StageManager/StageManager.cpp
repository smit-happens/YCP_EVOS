/**  Manages the event handling functions in the superloop
 *
 * StageManager.cpp
 * Created 1-28-18 By: Smitty
 *
 * A longer description.
 */

#include "StageManager.hpp"



/** 
 * @brief  StageManager constructor
 */
StageManager::StageManager(void)
{
    //The first step when running is bootup
    currentStage = STAGE_BOOTTEST;
    
    //changing stage if any events trigger it
    changeStage = currentStage;

    timerList = new Timer[TIMER_NUM];
    timerList[0].limit = POLL_TIME_GLCD;
    timerList[1].limit = POLL_TIME_SDCARD;
    timerList[2].limit = POLL_TIME_PEDAL;
    
    timerList[0].TFmask = TIMER_F_GLCD;
    timerList[1].TFmask = TIMER_F_SDCARD;
    timerList[2].TFmask = TIMER_F_PEDAL;

    //initializing the variables in the Timer array
    for(int i = 0; i < TIMER_NUM; i++) 
    {
        //creating the individual mask for each timer
        timerList[i].count = 0;
    }
}


/** 
 * @brief  Handles the multiple timers running off of a single 1ms timer from main
 * @note   Might have to be fleshed out more
 * @retval uint32_t with each bit coresponding to which timers went off
 */
uint32_t StageManager::processTimers(void)
{
    //Goes through the array of timers to increment their count and store which ones popped
    for (int i = 0; i < TIMER_NUM; i++)
    {
        timerList[i].count++;
        if(timerList[i].count >= timerList[i].limit)
        {
            //store which timer popped
            timerTF |= timerList[i].TFmask;

            //resetting the count of the timer that just popped
            timerList[i].count = 0;
        }

    }

    return timerTF;
}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void StageManager::bootTest(void)
{
    //LCD (boot logo)
    GlcdController::getInstance()->justBarelyLogo();


    //Teensy SelfTest (internal functions if any)

    
    //SdCard check (read data, check if good)


    //Dash test (turn on all LEDS, user confirmation w/ encoder)
    LightController::getInstance()->test();


    //Unitek Boot/check if okay


    //Orion check if okay

    
    //Cooling check if working
    

    //GLV batlog level check
    
    
    //assuming everything is okay
        //Notification: All systens go. Ready to Precharge


    if(/* check for ShutdownEF*/ 1 )
    {
        currentStage = STAGE_STANDBY;
    }
    else
    {
        shutdown();
    }

}


/** 
 * @brief  EXTREMELY CRITICAL FUNCTIONS
 * @note   
 * @retval None
 */
void StageManager::shutdown(void)
{
    //SCADA_OK signal to false
    digitalWriteFast(MB_SCADA_OK, LOW);

    //Resetting VAR1 precharge value to the "off" state
    CanController::getInstance()->sendUnitekWrite(REG_VAR1, 0x7F, 0xFF);

    Logger::getInstance()->log("STAGE_MGR", "Stage: shutdown", MSG_LOG);

    //close SD card. TODO: shutdown other things?
    SdCardController::getInstance()->shutdown(); 

    //turn off all dash lights except for Error lights
    LightController::getInstance()->turnNonErrorOff();


    //Halt system 
    while(1) {;}
}


/** 
 * @brief  Contains the initial configuration steps for the standby stage
 * @note   
 * @retval None
 */
void StageManager::configureStage(void)
{

    switch(currentStage)
    {
        // Entry condition: EVOS finishes subsystem testing
        // Exit condition:  Driver requests Precharging
        case STAGE_STANDBY:
        {
            //check to make sure this hasn't been ran before for this stage
            if(isStandbyConfigured == false)
            {
                //set variable to "configured"
                resetAllStagesExcept(STAGE_STANDBY);

                //TODO: Standby setup code
                //Serial.println("Standby Stage");
                Logger::getInstance()->log("STAGE_MGR", "Stage: Standby", MSG_LOG);

                //Resetting VAR1 precharge value to the "off" state
                CanController::getInstance()->sendUnitekWrite(REG_VAR1, 0x7F, 0xFF);

            }
        }
        break;

        
        // Entry condition: Driver requests Precharging
        // Exit condition:  Precharge done signal recieved from Unitek
        case STAGE_PRECHARGE:
        {
            //check to make sure this hasn't been ran before for this stage
            if(isPrechargeConfigured == false)
            {
                //set variable to "configured"
                resetAllStagesExcept(STAGE_PRECHARGE);

                //TODO: Precharge setup code
                //Serial.println("Precharge Stage");
                Logger::getInstance()->log("STAGE_MGR", "Stage: Precharge", MSG_LOG);

                //TODO: check for specific error in the future before setting high

                //Initiatiting the precharge process
                digitalWriteFast(MB_START_PRE, HIGH);

                //TODO: blink Energized Light to indicate to user that car is precharging

                //record the current time in milliseconds
                uint32_t currentTime = millis();

                //wait for precharge
                while((millis() - currentTime) < TIME_PRECHARGE)
                {;}
                
                float batteryVoltage = OrionController::getInstance()->getPackVoltage();
                // float batteryVoltage = 50.49;
                uint16_t numericVoltage = UnitekController::getInstance()->convertVoltageToNumeric(batteryVoltage);
                
                char buf[60]; //string buffer for sprintf
                // Serial.println(batteryVoltage);
                // Serial.print("full numeric: ");
                // Serial.println(numericVoltage);
                sprintf(buf, "Full Numeric battery voltage %d", numericVoltage);
                Logger::getInstance()->log("STAGE_MGR", buf, MSG_LOG);
                

                 numericVoltage *= 0.75;
                // Serial.print("75% numeric: ");
                // Serial.println(numericVoltage);

                sprintf(buf, "75 percent numeric battery voltage %d", numericVoltage);
                Logger::getInstance()->log("STAGE_MGR", buf, MSG_LOG);

                CanController::getInstance()->sendUnitekRead(REG_HVBUS);
                
                //record the current time in milliseconds
                currentTime = millis();

                //wait for 10 milliseconds for CAN message
                while((millis() - currentTime) < 10)
                {;}

                //"forcing" cancontroller to update unitek model
                CanController::getInstance()->distributeMail();

                if(UnitekController::getInstance()->getHvBusNumeric() < numericVoltage)
                {
                    //error state
                    shutdown();
                }

                //sending 0 to VAR1 in Unitek, indicating that precharge is done
                //Serial.println("Sending 0");
                Logger::getInstance()->log("STAGE_MGR", "Sending 0 to MC: Precharge complete", MSG_LOG);
                CanController::getInstance()->sendUnitekWrite(REG_VAR1, 0, 0);                

            }   
        }   
        break;


        // Entry condition: Precharge done signal recieved from Unitek
        // Exit condition:  Driver requests ready to drive
        case STAGE_ENERGIZED:
        {
            //check to make sure this hasn't been ran before for this stage
            if(isEnergizedConfigured == false)
            {
                //set variable to "configured"
                resetAllStagesExcept(STAGE_ENERGIZED);

                //TODO: Energized setup code
                //Serial.println("Energized Stage");
                Logger::getInstance()->log("STAGE_MGR", "Stage: Energized", MSG_LOG);

                //indicate to Driver that car is energized
                LightController::getInstance()->turnOn(LightController::LIGHT_ENERGIZE);
            }
        }
        break;


        // Entry condition: Driver requests ready to drive
        // Exit condition:  Driver requests standby
        case STAGE_DRIVING:
        {
            //check to make sure this hasn't been ran before for this stage
            if(isDrivingConfigured == false)
            {
                //set variable to "configured"
                resetAllStagesExcept(STAGE_DRIVING);

                //TODO: Driving setup code
                //Serial.println("Driving Stage");
                Logger::getInstance()->log("STAGE_MGR", "Stage: Driving", MSG_LOG);

                //Set Drive to high to go into 'Drive'
                digitalWriteFast(MB_DRIVE_EN, HIGH);

                //indicate to Driver that car is Ready to drive
                LightController::getInstance()->turnOn(LightController::LIGHT_RTD);

                //RTD sound
                DashController::getInstance()->playStartupSound();

            }
        }
        break;


        default:
            //shouldn't get here
        break;
    }

}


/** 
 * @brief  Handles the event and task flags for each device
 * @note   
 * @param  urgencyLevel: 
 * @param  eventFlags: 
 * @param  taskFlags: 
 * @retval 
 */
StageManager::Stage StageManager::processStage(Priority urgencyLevel, uint32_t* eventFlags, uint8_t* taskFlags)
{
    configureStage();
    
    //if any of the processing functions change the stage, we don't want it affecting the other processing events
    changeStage = currentStage;

    switch(urgencyLevel)
    {
        case PRIORITY_CRITICAL:
        {
            if(*eventFlags & EF_SHUTDOWN)
            {
                shutdown();
                
                //clearing the EF so we don't trigger this again
                *eventFlags &= ~EF_SHUTDOWN;
            }


            if(*eventFlags & EF_IMD)
            {
                processImd();
                
                //clearing the EF so we don't trigger this again
                *eventFlags &= ~EF_IMD;
            }
        }
        break;

        
        case PRIORITY_HIGH:
        {
            if(*eventFlags & EF_CAN)
            {
                *eventFlags |= processCan(taskFlags);
                
                //clearing the EF so we don't trigger this again
                *eventFlags &= ~EF_CAN;
            }


            if(*eventFlags & EF_UNITEK)
            {
                *eventFlags |= processUnitek(taskFlags);
                
                //clearing the EF so we don't trigger this again
                *eventFlags &= ~EF_UNITEK;
            }


            if(*eventFlags & EF_ORION)
            {
                processOrion();
                
                //clearing the EF so we don't trigger this again
                *eventFlags &= ~EF_ORION;
            }
        }
        break;


        case PRIORITY_MEDIUM:
        {
             if(*eventFlags & EF_COOLING)
            {
                processCooling();
                
                //clearing the EF so we don't trigger this again
                *eventFlags &= ~EF_COOLING;
            }


            if(*eventFlags & EF_BATLOG)
            {
                processBatlog();
                
                //clearing the EF so we don't trigger this again
                *eventFlags &= ~EF_BATLOG;
            }


            if(*eventFlags & EF_DASH)
            {
                processDash(taskFlags);

                //clearing the EF so we don't trigger this again
                *eventFlags &= ~EF_DASH;
            }
        }
        break;


        case PRIORITY_LOW:
        {
            if(*eventFlags & TIMER_F_PEDAL)
            {
                // Serial.println("pedal event");

                processPedal(eventFlags, taskFlags);

                *eventFlags &= ~TIMER_F_PEDAL;
            }

            if(*eventFlags & TIMER_F_GLCD)
            {
                processGlcd();
                
                //clearing the EF so we don't trigger this again
                *eventFlags &= ~TIMER_F_GLCD;
            }


            if(*eventFlags & TIMER_F_SDCARD)
            {
                processSdCard();
                
                //clearing the EF so we don't trigger this again
                *eventFlags &= ~TIMER_F_SDCARD;
            }
        }
        break;


        default:
            //shouldn't get here (for NUM_PRIORITY ENUM)
        break;

    } //End switch

    return changeStage;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
uint32_t StageManager::processCan(uint8_t* taskFlags)
{
    //code here is executed for any stage


    if(taskFlags[CAN] & TF_CAN_NEW_MAIL)
    {
        // Serial.println("New CAN mail task");

        CanController::getInstance()->distributeMail();

        taskFlags[CAN] &= ~TF_CAN_NEW_MAIL;
    }

    //executed for only the driving stage
    if(currentStage == STAGE_DRIVING)
    {
        //TODO: send pedal value over CAN
        if(taskFlags[CAN] & TF_CAN_SEND_PEDAL)
        {
            //set RPM Setpoint in MC
            float pedalPercent = PedalController::getInstance()->getPercentageGas();  //get percentage that the gas pedal is pressed
            uint16_t numericSpeedSetPoint = UnitekController::getInstance()->calculateSpeedSetPoint(pedalPercent);   //calculates speed to send to MC from 0-32767

            Serial.println(numericSpeedSetPoint);

            //send the speed over CAN to the MC (param: speed value register, upper 8 bits of numeric speed, lower 8 bits of numeric speed)
            CanController::getInstance()->sendUnitekWrite(REG_SPEEDVAL, (uint8_t)(numericSpeedSetPoint >> 8), numericSpeedSetPoint);
            // CanController::getInstance()->sendUnitekWrite(REG_VAR2, (uint8_t)(numericSpeedSetPoint >> 8), numericSpeedSetPoint);

            taskFlags[CAN] &= ~TF_CAN_SEND_PEDAL;
        }
    }

    return 0;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
uint32_t StageManager::processCooling(void)
{
    //insert code here that executes for any stage


    return 0;
}


/** 
 * @brief  
 * @note   
 * @param  currentStage: 
 * @param  tasks: 
 * @retval 
 */
uint32_t StageManager::processDash(uint8_t* taskFlags)
{
    //shutdown check performed for any stage
    if(taskFlags[DASH] & TF_DASH_SHUTDOWN)
    {
        //user wants to halt the system
        shutdown();

        taskFlags[DASH] &= ~TF_DASH_SHUTDOWN;
    }

    switch(currentStage){
        case STAGE_STANDBY:
        {
            //precharge button is pressed
            if(taskFlags[DASH] & TF_DASH_PRECHARGE)
            {
                //Serial.println("Dash - Precharge btn press");
                Logger::getInstance()->log("STAGE_MGR", "Dash - Precharge btn press", MSG_LOG);

                //change stage to precharging
                changeStage = STAGE_PRECHARGE;
            
                taskFlags[DASH] &= ~TF_DASH_PRECHARGE;
            }
        }
        break;


        case STAGE_PRECHARGE:
        {

        }
        break;


        case STAGE_ENERGIZED:
        {
            if(taskFlags[DASH] & TF_DASH_RTD)
            {
                //Serial.println("Dash - RTD Drive task");
                Logger::getInstance()->log("STAGE_MGR", "Dash- RTD Drive task", MSG_LOG);
                
                //Changing the stage
                changeStage = STAGE_DRIVING;

                //Clearing event flag
                taskFlags[DASH] &= ~TF_DASH_RTD;
            }

        }
        break;


        case STAGE_DRIVING:
        {
            
        }
        break;


        default:
            //shouldn't get here
        break;
    }

    return 0;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
uint32_t StageManager::processGlcd(void)
{
    //glcd view display updating

    return 0;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
uint32_t StageManager::processImd(void)
{    
    //this will only have like one thing that happens if called
    //TODO: add in IMD event handling 

    LightController::getInstance()->turnOn(LightController::LIGHT_ERR_IMD);

    shutdown();

    return 0;

}

/** 
 * @brief  Process the Orion BMS data
 * @note   Process the Orion data for error conditions
 * @retval 0
 */
uint32_t StageManager::processOrion(void)
{
    //first check for pack state of charge issues
    float packSOC = OrionController::getInstance()->getStateOfCharge();
    //if the pack is greater than 20% and less than 25%, change the view on the GLCD to notify the driver
    if(packSOC > 20 && packSOC <= 25)
    {
        //the GLCD will update with a change on the user interface for the 
        //GLCD_warnSocLow()
    }
    //if the pack is greater than 15% and less than 20%, cut the max RPM to 1000 to conserve power and be able to return to the original location without pulling as much power
    else if(packSOC > 15 && packSOC <= 20)
    {
        UnitekController::getInstance()->storeRpmLimit(1000);
    }
    //if the pack is at 15%, shut off the tractive system and continually flash the Orion error light until the GLV system is shut off
    else if(packSOC <= 15)
    {
        //shut down the car immediately
        StageManager::shutdown();
    }
    else
    {
        //battery is still at a good charge percentage so there is nothing to do
    }

    //second check for pack temperature issues
    //third check for the cell delta being too large
    //fourth check for the low cell voltage being too low

    return 0;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
void StageManager::processPedal(uint32_t* eventFlags, uint8_t* taskFlags)
{
    //insert code here that executes for any stage

    if(currentStage == STAGE_DRIVING)
    {
        //read and store the pedal value
        //set the apropiate can ef and tf for sending the value to the unitek

        // Serial.println("Pedal polling");

        PedalController::getInstance()->poll();

        *eventFlags |= EF_CAN;

        //taskflag setting for pedal value sending
        taskFlags[CAN] |= TF_CAN_SEND_PEDAL;
    }

}


/** 
 * @brief  
 * @note   
 * @retval 
 */
uint32_t StageManager::processSdCard(void)
{
    //insert code here that executes for any stage

    return 0;
}

/** 
 * @brief  
 * @note   
 * @retval 
 */

uint32_t StageManager::processUnitek(uint8_t* taskFlags)
{
    //PROCESSES FOR ANY STAGE

    //check unitek error and warning registers to determine if shutdown is needed
    // CanController::getInstance()->sendUnitekRead(REG_ERROR, 0);
    // delay(200);     //need to delay so MC has time to return CAN message, not sure of correct time
    // CAN_message_t errorReg;
    // Can1.read(errorReg);        //read error and warning reg and store values in errorReg
    // uint16_t errorValue=(errorReg.buf[4]<<8) || errorReg.buf[3];    //seperates error reg value
    // uint16_t warningValue=(errorReg.buf[2]<<8) || errorReg.buf[1];  //seperates warning reg value
    // UnitekController::getInstance()->storeErrorReg(errorValue);     //stores error value in unitek model
    // UnitekController::getInstance()->storeWarningReg(warningValue); //stores warning value in unitek model

    //check if shutdown is needed
    if(UnitekController::getInstance()->checkErrorWarningForShutdown() == true)
    {
        //Serial.println("Problem in MC. Shutdown Required.");
        Logger::getInstance()->log("STAGE_MGR", "Error in MC. Shutdown Required", MSG_ERR);
        return EF_SHUTDOWN;
    }


    //STAGE SPECIFIC PROCESSES
    switch(currentStage){
        case STAGE_STANDBY:
        {
            
        }
        break;


        case STAGE_PRECHARGE:
        {
              if(taskFlags[UNITEK] & TF_UNITEK_DONE_PRECHARGE)
            {
                //Changing the stage
                changeStage = STAGE_ENERGIZED;

                //Clearing event flag
                taskFlags[UNITEK] &= ~TF_UNITEK_DONE_PRECHARGE;
               Logger::getInstance()->log("STAGE_MGR", "Precharge task complete", MSG_LOG);
            }
        }
        break;


        case STAGE_ENERGIZED:
        {
 
        }
        break;


        case STAGE_DRIVING:
        {
            
        }
        break;


        default:
            //shouldn't get here
        break;
    }

    return 0;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
uint32_t StageManager::processBatlog(void)
{
    //insert code here that executes for any stage

    //TODO: analog read MB_BAT_MEASURE and store in model
    

    return 0;
}


/** 
 * @brief  
 * @note   
 * @param  currentStage: 
 * @retval None
 */
void StageManager::resetAllStagesExcept(Stage nonResetStage)
{
    //initially setting all the stage configurations to false, then "enabling" the current Stage
    isStandbyConfigured = false;
    isPrechargeConfigured = false;
    isEnergizedConfigured = false;
    isDrivingConfigured = false;


    //checking which stage we're currently in (same as which stage is configured correctly)
    switch(nonResetStage)
    {
        //Standby stage is configured
        case Stage::STAGE_STANDBY:
        {
            isStandbyConfigured = true;
        }
        break;

        
        //Precharge stage is configured
        case Stage::STAGE_PRECHARGE:
        {
            //Serial.println("configuring precharging");
            Logger::getInstance()->log("STAGE_MGR", "Started configuring precharge", MSG_LOG);
            isPrechargeConfigured = true;
        }
        break;


        //Energized stage is configured
        case Stage::STAGE_ENERGIZED:
        {
            isEnergizedConfigured = true;
        }
        break;


        //Driving stage is configured
        case Stage::STAGE_DRIVING:
        {
            isDrivingConfigured = true;
        }
        break;


        default:
            //shouldn't get here
        break;
    }
}
