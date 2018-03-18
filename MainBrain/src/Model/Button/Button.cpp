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
