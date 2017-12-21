/**  A one line description of the class.
 *
 * CoolingSystem.cpp
 * Created 12-20-17  By: Smitty
 *
 * A longer description.
 */

#include "CoolingSystem.hpp"


/** 
 * @brief  CoolingSystem constructor
 */
CoolingSystem::CoolingSystem(void)
{

}


/** 
 * @brief  Radiator coolant input temperature
 * @note   Figure out the conversion from the raw data to Celcius
 * @retval Temperature of coolant input in Celsius
 */
float CoolingSystem::getRadiatorTempIn(void)
{
    return 0.0;
}


/** 
 * @brief  Radiator coolant output temperature
 * @note   Figure out the conversion from the raw data to Celcius
 * @retval Temperature of coolant output in Celsius
 */
float CoolingSystem::getRadiatorTempOut(void)
{
    return 0.0;
}


/** 
 * @brief  Retrieves raw analog coolant input value from port
 * @note   Might just combine this into the getRadiatorTempIn/Out depending on how
 *         much math is needed or if the raw value is even necessary 
 * @retval Raw sensor value
 */
float CoolingSystem::getRadiatorTempInVal(void)
{
    return 0.0;
}


/** 
 * @brief  Retrieves raw analog coolant output value from port
 * @note   Might just combine this into the getRadiatorTempIn/Out depending on how
 *         much math is needed or if the raw value is even necessary  
 * @retval Raw sensor value
 */
float CoolingSystem::getRadiatorTempOutVal(void)
{
    return 0.0;
}