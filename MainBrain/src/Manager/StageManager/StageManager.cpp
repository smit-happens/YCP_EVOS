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
    timerList = new Timer[TIMER_NUM];
    timerList[0].limit = LED_1_POLL;
    timerList[1].limit = LED_2_POLL;
    timerList[2].limit = LED_3_POLL;
    timerList[3].limit = LED_4_POLL;

    for(int i = 0; i < TIMER_NUM; i++) 
    {
        timerList[i].TFmask = 1 << i;
    }
}

/** 
 * @brief  Handles the multiple timers running off of a single 1ms timer from main
 * @note   
 * @retval uint16_t with each bit coresponding to which timers went off
 */
uint16_t StageManager::processTimers(void)
{
    //FIXME: maybe move this into the private portion of the class
    uint16_t timerTF = 0;

    //TODO: verify on hardware

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

//FIXME: TESTING CODE START

void StageManager::testLed1(void)
{
    digitalWriteFast(23, LEDstate1);
    LEDstate1 = !LEDstate1;
}

void StageManager::testLed2(void)
{
    digitalWriteFast(22, LEDstate2);
    LEDstate2 = !LEDstate2;
}

void StageManager::testLed3(void)
{
    digitalWriteFast(21, LEDstate3);
    LEDstate3 = !LEDstate3;
}

void StageManager::testLed4(void)
{
    digitalWriteFast(20, LEDstate4);
    LEDstate4 = !LEDstate4;
}

//FIXME: TESTING CODE END