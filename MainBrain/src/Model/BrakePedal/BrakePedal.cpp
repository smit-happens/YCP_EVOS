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
    pinMode(MB_BRAKE_OVERTRAVEL, INPUT);
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
    _rawValue = analogRead(MB_BRAKE);
}


/** 
 * @brief  Retrieves and stores the origin of the Linear Potentiometer
 * @note   
 * @retval None
 */
void BrakePedal::setRawOrigin(void)
{
    _rawOrigin = analogRead(MB_BRAKE);
}
