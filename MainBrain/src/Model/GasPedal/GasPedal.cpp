/**  A one line description of the class.
 *
 * GasPedal.cpp
 * Created 11-09-17 By: Smitty
 *
 * A longer description.
 */

#include "GasPedal.hpp"


/** 
 * @brief  GasPedal constructor
 */
GasPedal::GasPedal(void)
{
    
}


/** 
 * @brief  Retrieves the evaluated Gas percentage
 * @note   
 * @retval GasPedal percentage
 */
float GasPedal::getPercentage(void)
{
    return 0.0;
}


/** 
 * @brief  Retrieves the value of the Linear Potentiometer
 * @note   Will have to determine what is the range of return values
 * @retval Analog voltage sensed
 */
float GasPedal::getLinValue(void)
{
    return 0.0;
}


/** 
 * @brief  Retrieves the value of the Logarithmic Potentiometer
 * @note   Will have to determine what is the range of return values
 * @retval Analog voltage sensed
 */
float GasPedal::getLogValue(void)
{
    return 0.0;
}


/** 
 * @brief  Evaluates the two pedal potentiometers (Linear and Logarithmic)
 * @note   Needs to check for shorts in wire and extrainious values
 * @retval True if there's an implausibility found, false if not
 */
bool GasPedal::isImplausibility(void)
{
    return false;
}