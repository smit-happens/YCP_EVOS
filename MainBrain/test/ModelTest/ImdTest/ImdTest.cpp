/**  IMD == Insulation Monitoring Device
 *
 * ImdTest.cpp
 * Created 3-12-18  By: Smitty
 *
 * A longer description.
 */

#include "ImdTest.hpp"


/** 
 * @brief  ImdTest constructor
 */
ImdTest::ImdTest(void)
{
    pinMode(MB_IMD_STATUS, INPUT);
}


/** 
 * @brief  ImdTest destructor
 */
ImdTest::~ImdTest(void)
{

}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void ImdTest::update(void)
{
    
}


/** 
 * @brief  Current stored state of the IMD
 * @note   
 * @retval true = bad; false = good
 */
bool ImdTest::isTriggered(void)
{
  return false;
}


/** 
 * @brief  Called from some rising edge interupt on the IMD_STATUS pin
 * @note   
 * @retval None
 */
void ImdTest::trigger(void)
{

}