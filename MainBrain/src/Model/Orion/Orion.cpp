/**  A one line description of the class.
 *
 * Orion.cpp
 * Created 10-24-17  By: Smitty
 *
 * A longer description.
 */

#include "Orion.hpp"

//TODO: Ask Micaiah about some of these functions and what's possible to retrieve from the Orion

/** 
 * @brief  Orion constructor
 */
Orion::Orion(void)
{

}


/** 
 * @brief  Retrieve total pack voltage from BMS
 * @note   TODO: Figure the range out from Micaiah
 * @retval Voltage value
 */
float Orion::getVoltageTotal(void)
{
    return 0.0;
}


/** 
 * @brief  
 * @note   
 * @retval Average voltage of all the cells in the pack
 */
float Orion::getVoltageAverage(void)
{
    return 0.0;
}


/** 
 * @brief  
 * @note   Possibly use this to see when the pack needs rebalancing
 * @retval 
 */
float Orion::getVoltageVariance(void)
{
    return 0.0;
}


/** 
 * @brief  Retrieves the min voltage value of all the cells
 * @note   
 * @retval 
 */
float Orion::getVoltageMin(void)
{
    return 0.0;
}


/** 
 * @brief  Retrieves the max voltage value of all the cells
 * @note   
 * @retval 
 */
float Orion::getVoltageMax(void)
{
    return 0.0;
}


/** 
 * @brief  
 * @note   Could be used in power calculations in addition to the Unitek calculations (I think)
 * @retval 
 */
float Orion::getAmperageTotal(void)
{
    return 0.0;
}


/** 
 * @brief  
 * @note   TODO: Is this average temperature? max? min?
 * @retval Temperature of (all?) the cells
 */
float Orion::getTemperature(void)
{
    return 0.0;
}


/** 
 * @brief  
 * @note   TODO: Is this possible?
 * @retval Cell number with the min voltage
 */
int Orion::getCellVoltageMin(void)
{
    return 0;
}


/** 
 * @brief  
 * @note   TODO: Is this possible?
 * @retval Cell number with the max voltage
 */
int Orion::getCellVoltageMax(void)
{
    return 0;
}