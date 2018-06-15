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

    //local instance of Logger
    logger = Logger::getInstance();

    timerList = new Timer[TIMER_NUM];
    timerList[0].limit = POLL_TIME_GLCD;
    timerList[1].limit = POLL_TIME_SDCARD;
    timerList[2].limit = POLL_TIME_PEDAL;
    timerList[3].limit = POLL_TIME_ORION;
    
    timerList[0].TFmask = TIMER_F_GLCD;
    timerList[1].TFmask = TIMER_F_SDCARD;
    timerList[2].TFmask = TIMER_F_PEDAL;
    timerList[3].TFmask = TIMER_F_ORION;

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
void StageManager::bootTest(uint32_t* eventFlags)
{
    //LCD (boot logo)
    //GlcdController::getInstance()->setNewState(); //should be handled by init now. 

    //Teensy SelfTest (internal functions if any)
    
    //SdCard check (read data, check if good)

    //Dash test (turn on all LEDS, user confirmation w/ encoder)
    LightController::getInstance()->test();

    //Unitek Boot/check if okay

    //Orion check if okay
    if(digitalReadFast(MB_BMS_STATUS) == HIGH)
    {
        logger->log("BOOT", "Orion error line", MSG_ERR);
        shutdown(ERR_ORION);
    }

    //IMD boot check
    if(digitalReadFast(MB_IMD_STATUS) == HIGH)
    {
        logger->log("BOOT", "IMD error line", MSG_ERR);
        shutdown(ERR_IMD);
    }
    
    //Cooling check if working
    

    //GLV batlog level check
    
    
    //assuming everything is okay
        //Notification: All systens go. Ready to Precharge

    //checking if the shutdown EF triggered
    if(*eventFlags & EF_SHUTDOWN)
    {
        shutdown(ERR_NONE);
    }
    else {
        currentStage = STAGE_STANDBY;
    }
}


/** 
 * @brief  EXTREMELY CRITICAL FUNCTIONS
 * @note   
 * @retval None
 */
void StageManager::shutdown(err_type err)
{
    //SCADA_OK signal to false
    digitalWriteFast(MB_SCADA_OK, LOW);

    //Resetting VAR1 precharge value to the "off" state
    CanController::getInstance()->sendUnitekWrite(REG_VAR1, 0x7F, 0xFF);

    logger->log("STAGE_CONFIG", "Stage: shutdown", MSG_LOG);

    //close SD card. TODO: shutdown other things?
    SdCardController::getInstance()->shutdown(); 
    GlcdController::getInstance()->setShutdownError(err);

    //turn off all dash lights except for Error lights
    LightController::getInstance()->turnNonErrorOff();


    //Halt system 
    while(1) {;}
}


/** 
 * @brief  Contains the initial configuration steps for any stage
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
                Logger::getInstance()->log("STAGE_MGR", "Stage: Standby", MSG_LOG);
                GlcdController::getInstance()->setNewState(STAGE_STANDBY);

                //go out of driving state
                digitalWriteFast(MB_DRIVE_EN, LOW);

                //Resetting VAR1 precharge value to the "off" state
                CanController::getInstance()->sendUnitekWrite(REG_VAR1, 0x7F, 0xFF);

                //setting the Dash lights correctly 
                LightController::getInstance()->turnOff(LightController::LIGHT_RTD);
                LightController::getInstance()->turnOff(LightController::LIGHT_ENERGIZE);

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
                Logger::getInstance()->log("STAGE_MGR", "Stage: Precharge", MSG_LOG);
                GlcdController::getInstance()->setNewState(STAGE_PRECHARGE);

                //TODO: check for specific error in the future before setting high

                //Initiatiting the precharge process
                digitalWriteFast(MB_START_PRE, HIGH);

                //record the current time in milliseconds
                uint32_t currentTime = millis();

                //wait for precharge
                while((millis() - currentTime) < TIME_PRECHARGE)
                {;}
                
                // float batteryVoltage = OrionController::getInstance()->getPackVoltage();
                float batteryVoltage = 200.0;   //hard coded to fix battery issues
                uint16_t numericVoltage = UnitekController::getInstance()->convertVoltageToNumeric(batteryVoltage);
                
                char buf[60]; //string buffer for sprintf
                
                sprintf(buf, "Full Numeric battery voltage %d", numericVoltage);
                logger->log("STAGE_CONFIG", buf, MSG_LOG);
                
                numericVoltage *= 0.75;

                sprintf(buf, "75 percent numeric battery voltage %d", numericVoltage);
                logger->log("STAGE_CONFIG", buf, MSG_LOG);

                CanController::getInstance()->sendUnitekRead(REG_HVBUS);
                
                //record the current time in milliseconds
                currentTime = millis();

                //wait for 10 milliseconds for CAN message
                while((millis() - currentTime) < 10)
                {;}

                //"forcing" cancontroller to update unitek model
                CanController::getInstance()->distributeMail();

                sprintf(buf, "Current HV-bus numeric voltage %d", UnitekController::getInstance()->getHvBusNumeric());
                logger->log("STAGE_CONFIG", buf, MSG_LOG);

                if(UnitekController::getInstance()->getHvBusNumeric() < numericVoltage)
                {
                    sprintf(buf, "Expected HV-bus numeric voltage: %d, actual is: %d", numericVoltage, UnitekController::getInstance()->getHvBusNumeric());
                    logger->log("UNITEK", buf, MSG_ERR);

                    //error state
                    shutdown(ERR_UNITEK);
                }

                //sending 0 to VAR1 in Unitek, indicating that precharge is done
                logger->log("STAGE_CONFIG", "Sending 0 to MC: Precharge complete", MSG_LOG);
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
                Logger::getInstance()->log("STAGE_MGR", "Stage: Energized", MSG_LOG);
                GlcdController::getInstance()->setNewState(STAGE_ENERGIZED);


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
                GlcdController::getInstance()->setNewState(STAGE_DRIVING);


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
Stage StageManager::processStage(Priority urgencyLevel, uint32_t* eventFlags, uint8_t* taskFlags)
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
                shutdown(ERR_NONE);
            }


            if(*eventFlags & EF_IMD)
            {
                processImd(taskFlags);
                
                //clearing the EF so we don't trigger this again
                *eventFlags &= ~EF_IMD;
            }
        }
        break;

        
        case PRIORITY_HIGH:
        {
            if(*eventFlags & EF_CAN)
            {
                processCan(taskFlags);
                
                //clearing the EF so we don't trigger this again
                *eventFlags &= ~EF_CAN;
            }


            if(*eventFlags & EF_UNITEK)
            {
                processUnitek(taskFlags);
                
                //clearing the EF so we don't trigger this again
                *eventFlags &= ~EF_UNITEK;
            }


            if(*eventFlags & EF_ORION)
            {
                processOrion(taskFlags);
                
                //clearing the EF so we don't trigger this again
                *eventFlags &= ~EF_ORION;
            }
        }
        break;


        case PRIORITY_MEDIUM:
        {
            if(*eventFlags & EF_COOLING)
            {
                processCooling(taskFlags);
                
                //clearing the EF so we don't trigger this again
                *eventFlags &= ~EF_COOLING;
            }


            if(*eventFlags & EF_BATLOG)
            {
                processBatlog(taskFlags);
                
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
            if(*eventFlags & TIMER_F_ORION)
            {
                processOrion(taskFlags);

                *eventFlags &= ~TIMER_F_ORION;
            }


            if(*eventFlags & TIMER_F_PEDAL)
            {
                processPedal(eventFlags, taskFlags);

                *eventFlags &= ~TIMER_F_PEDAL;
            }


            if(*eventFlags & TIMER_F_GLCD)
            {
                processGlcd(taskFlags);
                
                //clearing the EF so we don't trigger this again
                *eventFlags &= ~TIMER_F_GLCD;
            }


            if(*eventFlags & TIMER_F_SDCARD)
            {
                processSdCard(taskFlags);
                
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
void StageManager::processCan(uint8_t* taskFlags)
{
    if(taskFlags[CAN] & TF_CAN_NEW_MAIL)
    {
        CanController::getInstance()->distributeMail();

        taskFlags[CAN] &= ~TF_CAN_NEW_MAIL;
    }

    //checks in driving stage
    if(currentStage == STAGE_DRIVING)
    {
        //send pedal value over CAN if the timer popped
        if(taskFlags[CAN] & TF_CAN_SEND_PEDAL)
        {
            //set RPM Setpoint in MC
            float pedalPercent = PedalController::getInstance()->getPercentageGas();    //get percentage that the gas pedal is pressed
            // uint16_t rawGas = PedalController::getInstance()->getRawGas();              //get raw gas at the same time
            uint16_t numericSpeedSetPoint = UnitekController::getInstance()->calculateSpeedSetPoint(pedalPercent);   //calculates speed to send to MC from 0-32767

            //this is called 100 times every second, have this code execute 2 times a second
            // if(logCanPedalInterval % 50 == 0)
            // {
            //     //interval reset
            //     logCanPedalInterval = 0;

            //     //for sprintf
            //     char buf[80];

            //     // sprintf(buf, "Calculated numericSpeedSetPoint %d, pedalPercent: %.5f", numericSpeedSetPoint, pedalPercent);
            //     sprintf(buf, "raw_pedal: %d, pedalPercent: %.4f", rawGas, pedalPercent);
            //     logger->log("PEDAL", buf, MSG_DEBUG);
            // }

            //send the speed over CAN to the MC (param: speed value register, upper 8 bits of numeric speed, lower 8 bits of numeric speed)
            CanController::getInstance()->sendUnitekWrite(REG_SPEEDVAL, (uint8_t)(numericSpeedSetPoint >> 8), numericSpeedSetPoint);

            //clearing the TF for sending pedal values
            taskFlags[CAN] &= ~TF_CAN_SEND_PEDAL;
        }

        //TODO: add function to poll unitek so we update our local pedal value
    }

}


/** 
 * @brief  
 * @note   
 * @retval 
 */
void StageManager::processCooling(uint8_t* taskFlags)
{
    //insert code here that executes for any stage


}


/** 
 * @brief  
 * @note   
 * @param  currentStage: 
 * @param  tasks: 
 * @retval 
 */
void StageManager::processDash(uint8_t* taskFlags)
{
    //shutdown check performed for any stage
    if(taskFlags[DASH] & TF_DASH_SHUTDOWN)
    {
        //user wants to halt the system
        shutdown(ERR_NONE);
    }

    if(taskFlags[DASH] & TF_DASH_ENCODER)
    {
        logger->log("STAGE_MGR", "Dash - TF_DASH_ENCODER", MSG_DEBUG);
        
        GlcdController::getInstance()->advanceMode();
    
        taskFlags[DASH] &= ~TF_DASH_ENCODER;
    }


    //checks in standby stage
    if(currentStage == STAGE_STANDBY)
    {
        //precharge button is pressed
        if(taskFlags[DASH] & TF_DASH_PRECHARGE)
        {
            logger->log("DASH", "Dash - TF_DASH_PRECHARGE", MSG_DEBUG);

            //change stage to precharging
            changeStage = STAGE_PRECHARGE;
        
            taskFlags[DASH] &= ~TF_DASH_PRECHARGE;
        }
    }

    //checks in energized stage
    if(currentStage == STAGE_ENERGIZED)
    {
        if(taskFlags[DASH] & TF_DASH_RTD)
        {
            logger->log("DASH", "Dash - TF_DASH_RTD", MSG_DEBUG);
            
            //Changing the stage
            changeStage = STAGE_DRIVING;

            //Clearing event flag
            taskFlags[DASH] &= ~TF_DASH_RTD;
        }
    }

    //checks in everything but standby stage
    if(currentStage != STAGE_STANDBY)
    {
        if(taskFlags[DASH] & TF_DASH_STANDBY)
        {
            logger->log("DASH", "Dash - TF_DASH_STANDBY", MSG_DEBUG);
            
            //Changing the stage
            changeStage = STAGE_STANDBY;

            //Clearing event flag
            taskFlags[DASH] &= ~TF_DASH_STANDBY;
        }
    }

}


/** 
 * @brief  
 * @note   
 * @retval 
 */
void StageManager::processGlcd(uint8_t* taskFlags)
{
    //glcd view display updating
    GlcdController::getInstance()->poll(); //will flush buffer if required.
    return;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
void StageManager::processImd(uint8_t* taskFlags)
{
    //TODO: have this drop to standby rather than shutdown, but that's TBD
    logger->log("IMD", "IMD Error", MSG_ERR);

    //activate the error light
    LightController::getInstance()->turnOn(LightController::LIGHT_ERR_IMD);

    //required to shutdown based on error
    shutdown(ERR_IMD);

}


/** 
 * @brief  Process the Orion BMS data
 * @note   Process the Orion data for error conditions
 * @retval 0
 */
void StageManager::processOrion(uint8_t* taskFlags)
{
    //TODO: have this drop to standby rather than shutdown, but that's TBD    
    //checking the status of the Orion error line during any stage
    if(taskFlags[ORION] & TF_ORION_ERROR)
    {
        //logging the error
        logger->log("ORION", "ORION ERROR", MSG_ERR);

        //indicating to the driver that an orion error has occured
        LightController::getInstance()->turnOn(LightController::LIGHT_ERR_BMS);

        //required to shutdown based on error
        shutdown(ERR_ORION);
    }


    //performing the HV charge and temperature checking during all the stages except for standby
    if(currentStage != STAGE_STANDBY)
    {
        //first check for pack state of charge issues
        // float packSOC = OrionController::getInstance()->getStateOfCharge();

        char buf[60]; //string buffer for sprintf
                
        // //if the pack is greater than 20% and less than 25%, change the view on the GLCD to notify the driver
        // if(packSOC > 20 && packSOC <= 25)
        // {
        //     //the GLCD will update with a change on the user interface for the driver to know the battery is getting low
        //     //GLCD_warnSocLow()
            
        //     //logging the percent
        //     sprintf(buf, "Pack SoC getting low: %.2f percent", packSOC);
        //     Logger::getInstance()->log("ORION", buf, MSG_WARN);
        // }
        // //if the pack is greater than 15% and less than 20%, cut the max RPM to 1000 to conserve power and be able to return to the original location without pulling as much power
        // else if(packSOC > 15 && packSOC <= 20)
        // {
        //     //set the speed calculation factor to 8 which will make the max rpm sent be 6600/8 = 825 rpms
        //     UnitekController::getInstance()->storeSpeedCalculationFactor(8);
            
        //     //logging the percent
        //     sprintf(buf, "Pack SoC very low: %.2f percent, limp mode engaged", packSOC);
        //     Logger::getInstance()->log("ORION", buf, MSG_WARN);
        // }
        // //if the pack is at 15%, shut off the tractive system and continually flash the Orion error light until the GLV system is shut off
        // else if(packSOC <= 15)
        // {
        //     sprintf(buf, "Battery SOC at %.2f percent, shutting off tractive system", packSOC);
        //     Logger::getInstance()->log("ORION", buf, MSG_ERR);
        //     //shut down the car immediately
        //     shutdown(ERR_ORION);
        // }
        // else
        // {
        //     //battery is still at a good charge percentage so there is nothing to do
        // }

        //second check for pack temperature issues
        uint8_t highestTempOfPack = OrionController::getInstance()->getHighestCellTemp();
        //if the highest temperature in the pack is greater than 60 degrees celcius, shut off the car
        if(highestTempOfPack > MAXCELLTEMPERATURECELCIUS)
        {
            //log the high temperature value
            sprintf(buf, "Cell temp too high: %d", highestTempOfPack);
            Logger::getInstance()->log("ORION", buf, MSG_ERR);
            shutdown(ERR_ORION);
        }
    }
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
void StageManager::processPedal(uint32_t* eventFlags, uint8_t* taskFlags)
{
    //polling the pedals updating the model    
    PedalController::getInstance()->poll();   

    //seeing if we need to turn on the brake light
    PedalController::getInstance()->CheckBrakeLight();


    if(currentStage == STAGE_DRIVING)
    {
        //need to send pedal value over CAN
        *eventFlags |= EF_CAN;

        //taskflag setting for sending the gas pedal value to unitek
        taskFlags[CAN] |= TF_CAN_SEND_PEDAL;
    }
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
void StageManager::processSdCard(uint8_t* taskFlags)
{
    //insert code here that executes for any stage

}


/** 
 * @brief  
 * @note   
 * @retval 
 */

void StageManager::processUnitek(uint8_t* taskFlags)
{
    //need to update error/warning reg prior to checking for errors
    CanController::getInstance()->sendUnitekRead(REG_ERROR);
                
    //record the current time in milliseconds
    uint32_t startTime = millis();

    //wait for 10 milliseconds for CAN message
    while((millis() - startTime) < 10)
    {;}

    //"forcing" cancontroller to update unitek model
    CanController::getInstance()->distributeMail();

    //check if shutdown is needed
    if(UnitekController::getInstance()->checkErrorWarningForShutdown())
    {
        logger->log("UNITEK", "Error in MC. Shutdown Required", MSG_ERR);
        shutdown(ERR_UNITEK);
    }


    //STAGE SPECIFIC PROCESSES
    if(currentStage == STAGE_PRECHARGE)
    {
        if(taskFlags[UNITEK] & TF_UNITEK_DONE_PRECHARGE)
        {
            //Changing the stage
            changeStage = STAGE_ENERGIZED;

            //Clearing event flag
            taskFlags[UNITEK] &= ~TF_UNITEK_DONE_PRECHARGE;
            logger->log("UNITEK", "Precharge task complete", MSG_LOG);
        }
    }

}


/** 
 * @brief  
 * @note   
 * @retval 
 */
void StageManager::processBatlog(uint8_t* taskFlags)
{
    //insert code here that executes for any stage

    //TODO: analog read MB_BAT_MEASURE and store in model

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
            logger->log("STAGE_MGR", "Started configuring STAGE_STANDBY", MSG_LOG);
            isStandbyConfigured = true;
        }
        break;

        
        //Precharge stage is configured
        case Stage::STAGE_PRECHARGE:
        {
            logger->log("STAGE_MGR", "Started configuring STAGE_PRECHARGE", MSG_LOG);
            isPrechargeConfigured = true;
        }
        break;


        //Energized stage is configured
        case Stage::STAGE_ENERGIZED:
        {
            logger->log("STAGE_MGR", "Started configuring STAGE_ENERGIZED", MSG_LOG);    
            isEnergizedConfigured = true;
        }
        break;


        //Driving stage is configured
        case Stage::STAGE_DRIVING:
        {
            logger->log("STAGE_MGR", "Started configuring STAGE_DRIVING", MSG_LOG);            
            isDrivingConfigured = true;
        }
        break;


        default:
            //shouldn't get here
        break;
    }
}
