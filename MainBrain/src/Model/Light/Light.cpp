/**  A one line description of the class.
 *
 * Light.cpp
 * Created 12-15-17  By: Smitty
 *
 * A longer description.
 */

#include "Light.hpp"


/** 
 * @brief  Light constructor
 */
Light::Light(void)
{
    //initializing the dash lights
    pinMode(MB_BRAKE_LIGHT, OUTPUT);
    pinMode(MB_SCADA_OK, OUTPUT);
    pinMode(MB_RTD_LED, OUTPUT);
    pinMode(MB_BMS_LED, OUTPUT);
    pinMode(MB_PEDAL_LED, OUTPUT);
    pinMode(MB_IMD_LED, OUTPUT);
    pinMode(MB_REVERSE_LED, OUTPUT);
    pinMode(MB_WAYNE_LED, OUTPUT);

}


/** 
 * @brief  Identifying name for the Light
 * @note   This might need to be refactored into using some struct or something
 * @retval Name of the particular Light
 */
String Light::getName(void)
{
    return "";
}


/** 
 * @brief  Current state of the Light (on/off)
 * @note   
 * @retval 1 = ON; 0 = OFF
 */
int Light::getState(void)
{
  return 0;
}


/** 
 * @brief  For turning a Light on/off based on bool input
 * @note   
 * @retval None
 */
void Light::setState(bool)
{

}


void Light::turnOnAll(void)
{
    
}