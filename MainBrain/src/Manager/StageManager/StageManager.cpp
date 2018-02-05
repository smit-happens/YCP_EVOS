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
        Serial.print("timerList item ");
        Serial.print(i);
        Serial.print(": ");
        Serial.println(timerList[i].TFmask);
    }
}

/** 
 * @brief  Handles the multiple timers running off of a single 1ms timer from main
 * @note   
 * @retval uint32_t representing the TaskFlags for various timers that went off
 */
uint32_t StageManager::processTimers(void)
{
    uint32_t timerTF = 0;

    //TODO: finish this

    for (int i = 0; i < TIMER_NUM; i++)
    {
        timerList[i].count++;
        if(timerList[i].count >= timerList[i].limit)
        {
            timerTF |= timerList[i].TFmask;
        }

    }
    return timerTF;
}

/*
    bool LEDstate1 = false;
    bool LEDstate2 = false;
    bool LEDstate3 = false;
    bool LEDstate4 = false;

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
            */