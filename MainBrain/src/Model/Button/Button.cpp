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
    //Dashboard buttons
    pinMode(MB_PRE_BTN, INPUT);
    pinMode(MB_RTD_BTN, INPUT);
    pinMode(MB_ENC_BTN, INPUT);
    pinMode(MB_WAYNE_BTN, INPUT);
    pinMode(MB_SHUTDOWN_BTN, INPUT);
    pinMode(MB_STANDBY_BTN, INPUT);

    //reverse switch
    pinMode(MB_REVERSE_SW, INPUT);
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