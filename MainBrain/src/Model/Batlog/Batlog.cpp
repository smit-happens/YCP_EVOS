/**  Monitors the GLV battery level
 *
 * Batlog.cpp
 * Created 2-6-18  By: Smitty
 *
 * A longer description.
 */

#include "Batlog.hpp"


/** 
 * @brief  Batlog constructor
 */
Batlog::Batlog(void)
{
    _batteryValue = 0;
}


/** 
 * @brief  Batlog destructor
 */
Batlog::~Batlog(void)
{
    
}


/** 
 * @brief  Retrieves and stores the value of the GLV battery voltage
 * @note   
 * @retval None
 */
void Batlog::update(void)
{
    _batteryValue = analogRead(MB_BAT_MEASURE);
}