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
 * @brief  Retrieves the evaluated Brake percentage
 * @note   Evaluate linear pedal potentiometer
 * @retval BrakePedal percentage
 */
float BrakePedal::getPercentage(void)
{
    return 0.0;
}


/** 
 * @brief  Retrieves the value of the Linear Potentiometer
 * @note   Will have to determine what is the range of return values
 * @retval Analog voltage sensed
 */
float BrakePedal::getLinValue(void)
{
    return 0.0;
}


/** 
 * @brief  Evaluates the brake pedal potentiometer
 * @note   Needs to check for shorts in wire and extrainious values
 * @retval True if there's an implausibility found, false if not
 */
bool BrakePedal::isImplausibility(void)
{
    return false;
}
