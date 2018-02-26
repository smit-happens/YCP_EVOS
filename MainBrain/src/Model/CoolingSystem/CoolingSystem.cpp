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

    //initializing the tempurature values
    _inletTempurature  = 0;
    _outletTempurature = 0;
}


/** 
 * @brief  CoolingSystem destructor
 */
CoolingSystem::~CoolingSystem(void)
{

}


/** 
 * @brief  Retrieves and stores the value of the 2 tempurature sensors
 * @note   
 * @retval None
 */
void CoolingSystem::update(void)
{
    _inletTempurature  = analogRead(MB_RAD_INLET_TEMP);
    _outletTempurature = analogRead(MB_RAD_OUTLET_TEMP);
}


/** 
 * @brief  Retrieves raw analog coolant output value from port
 * @note   Might just combine this into the getRadiatorTempIn/Out depending on how
 *         much math is needed or if the raw value is even necessary  
 * @retval Raw sensor value
 */
uint16_t CoolingSystem::getInletValue(void)
{
    return _inletTempurature;
}


/** 
 * @brief  Retrieves raw analog coolant input value from port
 * @note   Might just combine this into the getRadiatorTempIn/Out depending on how
 *         much math is needed or if the raw value is even necessary 
 * @retval Raw sensor value
 */
uint16_t CoolingSystem::getOutletValue(void)
{
    return _outletTempurature;
}
