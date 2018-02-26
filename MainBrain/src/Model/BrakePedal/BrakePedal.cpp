/**  A one line description of the class.
 *
 * BrakePedal.cpp
 * Created 12-20-17 By: Smitty
 *
 * A longer description.
 */

#include "BrakePedal.hpp"


/** 
 * @brief  BrakePedal constructor
 */
BrakePedal::BrakePedal(void)
{
    //FIXME: will have to enable this eventually, commented out to keep pin 13 as a status light
    // pinMode(MB_BRAKE_OVERTRAVEL, INPUT);

    _linValue = 0;
}


/** 
 * @brief  BrakePedal destructor
 */
BrakePedal::~BrakePedal(void)
{

}


/** 
 * @brief  Retrieves and stores the value of the brake Linear Potentiometer
 * @note   
 * @retval None
 */
void BrakePedal::update(void)
{
    _linValue = analogRead(MB_BRAKE);
}


/** 
 * @brief  Retrieves the value of the Linear Potentiometer
 * @note   value of 0-8195
 * @retval Analog voltage sensed
 */
uint16_t BrakePedal::getLinValue(void)
{
    return _linValue;
}
