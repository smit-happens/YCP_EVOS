/**  Monitors the GLV battery level
 *
 * BatlogTest.cpp
 * Created 3-12-18  By: Smitty
 *
 * A longer description.
 */

#include "BatlogTest.hpp"


/** 
 * @brief  BatlogTest constructor
 */
BatlogTest::BatlogTest(void)
{
    _batteryValue = 0;
}


/** 
 * @brief  Retrieves and stores the value of the GLV battery voltage
 * @note   
 * @retval None
 */
void BatlogTest::update(void)
{
    _batteryValue = analogRead(MB_BAT_MEASURE);
}