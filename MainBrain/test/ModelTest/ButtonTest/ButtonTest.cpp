/**  A one line description of the class.
 *
 * ButtonTest.cpp
 * Created 3-12-18  By: Smitty
 *
 * A longer description.
 */

#include "ButtonTest.hpp"


/** 
 * @brief  ButtonTest constructor
 */
ButtonTest::ButtonTest(void)
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
 * @brief  ButtonTest destructor
 */
ButtonTest::~ButtonTest(void)
{
    
}


/** 
 * @brief  
 * @note   TODO: fill this out
 * @retval None
 */
void ButtonTest::update(void)
{
    
}


/** 
 * @brief  Identifying name for the ButtonTest
 * @note   This might need to be refactored into using some struct or something (similar to Light.cpp)
 * @retval Name of the particular ButtonTest
 */
String ButtonTest::getName(void)
{
  return "";
}


/** 
 * @brief  Current state of the ButtonTest (closed/open)
 * @note   
 * @retval 1 = closed; 0 = open
 */
int ButtonTest::getState(void)
{
  return 0;
}


/** 
 * @brief  Called from some edge interupt on the ButtonTest's reference pin
 * @note   
 * @retval None
 */
void ButtonTest::setState(void)
{

}