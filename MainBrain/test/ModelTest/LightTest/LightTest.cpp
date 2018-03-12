/**  A one line description of the class.
 *
 * LightTest.cpp
 * Created 3-12-18  By: Smitty
 *
 * A longer description.
 */

#include "LightTest.hpp"


/** 
 * @brief  LightTest constructor
 */
LightTest::LightTest(void)
{
    //initializing the dash lights
    pinMode(MB_RTD_LED, OUTPUT);
    pinMode(MB_BMS_LED, OUTPUT);
    pinMode(MB_PEDAL_LED, OUTPUT);
    pinMode(MB_IMD_LED, OUTPUT);
    pinMode(MB_REVERSE_LED, OUTPUT);
    pinMode(MB_WAYNE_LED, OUTPUT);
    pinMode(MB_ENERGIZE_LED, OUTPUT);

    //brake light
    pinMode(MB_BRAKE_LIGHT, OUTPUT);

}


/** 
 * @brief  LightTest destructor
 */
LightTest::~LightTest(void)
{

}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void LightTest::update(void)
{
    
}


/** 
 * @brief  Identifying name for the LightTest
 * @note   This might need to be refactored into using some struct or something
 * @retval Name of the particular LightTest
 */
String LightTest::getName(void)
{
    return "";
}


/** 
 * @brief  Current state of the LightTest (on/off)
 * @note   
 * @retval 1 = ON; 0 = OFF
 */
int LightTest::getState(void)
{
  return 0;
}


/** 
 * @brief  For turning a LightTest on/off based on bool input
 * @note   
 * @retval None
 */
void LightTest::setState(bool)
{

}


void LightTest::turnOnAll(void)
{
    
}