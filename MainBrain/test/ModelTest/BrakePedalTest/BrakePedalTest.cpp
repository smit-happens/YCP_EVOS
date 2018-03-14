/**  A one line description of the class.
 *
 * BrakePedalTest.cpp
 * Created 3-12-18 By: Smitty
 *
 * A longer description.
 */

#include "BrakePedalTest.hpp"


/** 
 * @brief  BrakePedalTest constructor
 */
BrakePedalTest::BrakePedalTest(void)
{
    //FIXME: will have to enable this eventually, commented out to keep pin 13 as a status light
    // pinMode(MB_BRAKE_OVERTRAVEL, INPUT);

    _linValue = 0;
}


/** 
 * @brief  BrakePedalTest destructor
 */
BrakePedalTest::~BrakePedalTest(void)
{

}


/** 
 * @brief  Retrieves and stores the value of the brake Linear Potentiometer
 * @note   
 * @retval None
 */
void BrakePedalTest::update(void)
{
    _linValue = analogRead(MB_BRAKE);
}


/** 
 * @brief  Retrieves the value of the Linear Potentiometer
 * @note   value of 0-8195
 * @retval Analog voltage sensed
 */
uint16_t BrakePedalTest::getLinValue(void)
{
    return _linValue;
}
