/**  Handles the setup and usage of the built in RTC
 *
 * Rtc.cpp
 * Created 1-14-18  By: Smitty
 *
 * A longer description.
 */

#include "Rtc.hpp"


/** 
 * @brief  Rtc constructor
 */
Rtc::Rtc(void)
{
    // set the Time library to use Teensy 3.0's RTC to keep time
    setSyncProvider(&Rtc::getTeensy3Time);
}


/** 
 * @brief  Required to have the Time library use Teensy3 hardware rtc
 * @note   
 * @retval time_t object
 */
time_t Rtc::getTeensy3Time(void)
{
    return Teensy3Clock.get();
}

