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