/**  A one line description of the class.
 *
 * CoolingSystemTest.cpp
 * Created 3-12-18  By: Smitty
 *
 * A longer description.
 */

#include "CoolingSystemTest.hpp"


/** 
 * @brief  CoolingSystemTest constructor
 */
CoolingSystemTest::CoolingSystemTest(void)
{
    //Cooling pump control
    pinMode(MB_PUMP_CTRL, OUTPUT);

    //initializing the temperature values
    _inletTemperature  = 0;
    _outletTemperature = 0;
}


/** 
 * @brief  CoolingSystemTest destructor
 */
CoolingSystemTest::~CoolingSystemTest(void)
{

}


/** 
 * @brief  Retrieves and stores the value of the 2 temperature sensors
 * @note   
 * @retval None
 */
void CoolingSystemTest::update(void)
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
uint16_t CoolingSystemTest::getInletValue(void)
{
    return _inletTemperature;
}


/** 
 * @brief  Retrieves raw analog coolant input value from port
 * @note   Might just combine this into the getRadiatorTempIn/Out depending on how
 *         much math is needed or if the raw value is even necessary 
 * @retval Raw sensor value
 */
uint16_t CoolingSystemTest::getOutletValue(void)
{
    return _outletTemperature;
}
