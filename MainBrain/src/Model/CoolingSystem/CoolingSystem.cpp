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
    //Cooling pump control
    pinMode(MB_PUMP_CTRL, OUTPUT);

    //initializing the temperature values
    _inletTemperature  = 0;
    _outletTemperature = 0;
}


/** 
 * @brief  CoolingSystem destructor
 */
CoolingSystem::~CoolingSystem(void)
{

}


/** 
 * @brief  Retrieves and stores the value of the 2 temperature sensors
 * @note   
 * @retval None
 */
void CoolingSystem::update(void)
{
    _inletTemperature  = analogRead(MB_RAD_INLET_TEMP);
    _outletTemperature = analogRead(MB_RAD_OUTLET_TEMP);
}


/** 
 * @brief  Retrieves raw analog coolant output value from port
 * @note   Might just combine this into the getRadiatorTempIn/Out depending on how
 *         much math is needed or if the raw value is even necessary  
 * @retval Raw sensor value
 */
uint16_t CoolingSystem::getInletValue(void)
{
    return _inletTemperature;
}


/** 
 * @brief  Retrieves raw analog coolant input value from port
 * @note   Might just combine this into the getRadiatorTempIn/Out depending on how
 *         much math is needed or if the raw value is even necessary 
 * @retval Raw sensor value
 */
uint16_t CoolingSystem::getOutletValue(void)
{
    return _outletTemperature;
}
