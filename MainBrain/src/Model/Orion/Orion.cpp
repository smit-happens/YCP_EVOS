/**  A one line description of the class.
 *
 * Orion.cpp
 * Created 10-24-17  By: Smitty
 *
 * A longer description.
 */

#include "Orion.hpp"

/** 
 * @brief  Orion constructor
 */
Orion::Orion(void)
{
    pinMode(MB_BMS_STATUS, INPUT);
 
    data_0x420 = new CanData_0x420;
    data_0x421 = new CanData_0x421;
}


/** 
 * @brief  Orion destructor
 */
Orion::~Orion(void)
{

}


/** 
 * @brief  
 * @note   TODO: Determine if we will need an update function for this class. At this point it does not seem necessary since the controller will update the model with the poll function
 * @retval None
 */
void Orion::update(void)
{
    
}


//all of the get functions for the Orion Model
/** 
 * @brief  Retrieve state of charge of the pack as a percent
 * @note   Range is 0-100%
 * @retval State of charge of the pack
 */
float Orion::getStateOfCharge(void)
{
    return stateOfCharge;
}


/** 
 * @brief  Retrieve state of health of the pack as a percent
 * @note   Range is 0-100%
 * @retval State of health of the pack
 */
uint8_t Orion::getStateOfHealth(void)
{
    return stateOfHealth;
}


/** 
 * @brief  Retrieve highest cell temperature of the pack
 * @note   Range is 0-255 degrees Celcius
 * @retval Highest cell temperature in the pack
 */
uint8_t Orion::getHighestCellTemp(void)
{
    return highestCellTemp;
}


/** 
 * @brief  Retrieve average cell temperature of the pack
 * @note   Range is 0-255 degrees Celcius
 * @retval Average cell temperature for the pack
 */
uint8_t Orion::getAverageCellTemp(void)
{
    return averageCellTemp;
}


/** 
 * @brief  Retrieve max open cell voltage of the pack
 * @note   Range is 0-6.5535 volts
 * @retval Max open cell voltage value
 */
float Orion::getMaxOpenCellVoltage(void)
{
    return maxOpenCellVoltage;
}


/** 
 * @brief  Retrieve minimum open cell voltage of the pack
 * @note   Range is 0-6.5535 volts
 * @retval Min open cell voltage value
 */
float Orion::getMinOpenCellVoltage(void)
{
    return minOpenCellVoltage;
}


/** 
 * @brief  Retrieve the discharge current limit of the pack
 * @note   Range is 0-65535 amps
 * @retval Discharge current limit value
 */
uint16_t Orion::getPackDischargeCurrentLimit(void)
{
    return packDischargeCurrentLimit;
}


/** 
 * @brief  Retrieve total open pack voltage of the pack
 * @note   Range is 0-6553.5 volts
 * @retval Open voltage value of the pack
 */
float Orion::getPackOpenVoltage(void)
{
    return packOpenVoltage;
}


/** 
 * @brief  Retrieve the output current of the pack
 * @note   Range is 0-6553.5 amps
 * @retval Output current value of the pack
 */
float Orion::getPackCurrent(void)
{
    return packCurrent;
}


/** 
 * @brief  Retrieve average open cell voltage of the pack
 * @note   Range is 0-6.5335 volts
 * @retval Average open cell voltage value
 */
float Orion::getAverageOpenCellVoltage(void)
{
    return averageOpenCellVoltage;
}


//all set functions for the Orion Model


/** 
 * @brief  Set state of charge of the pack as a percent
 * @note   Range is 0-100%
 * @param  newStateOfCharge: The new state of charge for the pack
 * @retval None
 */
void Orion::setStateOfCharge(float newStateOfCharge)
{
    stateOfCharge = newStateOfCharge;
}


/** 
 * @brief  Set state of health of the pack as a percent
 * @note   Range is 0-100%
 * @param  newStateOfHealth: The new state of health for the pack
 * @retval None
 */
void Orion::setStateOfHealth(uint8_t newStateOfHealth)
{
    stateOfHealth = newStateOfHealth;
}


/** 
 * @brief  Set the highest cell temperature of the pack
 * @note   Range is 0-255 degrees Celcius
 * @param  newHighestCellTemp: The new state highest cell temperature in the pack
 * @retval None
 */
void Orion::setHighestCellTemp(uint8_t newHighestCellTemp)
{
    highestCellTemp = newHighestCellTemp;
}


/** 
 * @brief  Set the average cell temperature of the pack
 * @note   Range is 0-255 degrees Celcius
 * @param  newAverageCellTemp: The new average cell temperature for the pack
 * @retval None
 */
void Orion::setAverageCellTemp(uint8_t newAverageCellTemp)
{
    averageCellTemp = newAverageCellTemp;
}


/** 
 * @brief  Set the max open cell voltage for the pack
 * @note   Range is 0-6.5535 volts
 * @param  newMaxOpenCellVoltage: The new maximum open cell voltage in the pack 
 * @retval None
 */
void Orion::setMaxOpenCellVoltage(float newMaxOpenCellVoltage)
{
    maxOpenCellVoltage = newMaxOpenCellVoltage;
}


/** 
 * @brief  Set the minimum open cell voltage for the pack
 * @note   Range is 0-6.5535 volts
 * @param  newMinOpenCellVoltage: The new minimum open cell voltage in the pack
 * @retval None
 */
void Orion::setMinOpenCellVoltage(float newMinOpenCellVoltage)
{
    minOpenCellVoltage = newMinOpenCellVoltage;
}


/** 
 * @brief  Set the pack discharge current limit for the pack
 * @note   Range is 0-65535 amps
 * @param  newPackDischargeCurrentLimit: The new discharge current limit for the pack
 * @retval None
 */
void Orion::setPackDischargeCurrentLimit(uint16_t newPackDischargeCurrentLimit)
{
    packDischargeCurrentLimit = newPackDischargeCurrentLimit;
}


/** 
 * @brief  Set the open voltage of the pack
 * @note   Range is 0-6553.5 volts
 * @param  newPackOpenVoltage: The new open voltage value for the pack
 * @retval None
 */
void Orion::setPackOpenVoltage(float newPackOpenVoltage)
{
    packOpenVoltage = newPackOpenVoltage;
}


/** 
 * @brief  Set the value of pack output current
 * @note   Range is 0-6553.5 amps
 * @param  newPackCurrent: The new current output of the pack
 * @retval None
 */
void Orion::setPackCurrent(float newPackCurrent)
{
    packCurrent = newPackCurrent;
}


/** 
 * @brief  Set the value for the average open cell voltage of the pack
 * @note   Range is 0-6.5535 volts
 * @param  newAverageOpenCellVoltage: the new average open cell voltage of the pack 
 * @retval None
 */
void Orion::setAverageOpenCellVoltage(float newAverageOpenCellVoltage)
{
    averageOpenCellVoltage = newAverageOpenCellVoltage;
}