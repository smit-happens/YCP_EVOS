/**  A one line description of the class.
 *
 * Button.cpp
 * Created 12-13-17  By: Smitty
 *
 * A longer description.
 */

#include "Button.hpp"


/** 
 * @brief  Button constructor
 */
Button::Button(void)
{

}


/** 
 * @brief  Identifying name for the Button
 * @note   This might need to be refactored into using some struct or something (similar to Light.cpp)
 * @retval Name of the particular Button
 */
String Button::getName(void)
{
  return "";
}


/** 
 * @brief  Current state of the Button (closed/open)
 * @note   
 * @retval 1 = closed; 0 = open
 */
int Button::getState(void)
{
  return 0;
}


/** 
 * @brief  Called from some edge interupt on the Button's reference pin
 * @note   
 * @retval None
 */
void Button::setState(void)
{

}