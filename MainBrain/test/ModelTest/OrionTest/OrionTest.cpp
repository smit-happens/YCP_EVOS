/**  A one line description of the class.
 *
 * OrionTest.cpp
 * Created 3-12-18  By: Smitty
 *
 * A longer description.
 */

#include "OrionTest.hpp"

//TODO: Ask Micaiah about some of these functions and what's possible to retrieve from the OrionTest

/** 
 * @brief  OrionTest constructor
 */
OrionTest::OrionTest(void)
{
    pinMode(MB_BMS_STATUS, INPUT);
}


/** 
 * @brief  OrionTest destructor
 */
OrionTest::~OrionTest(void)
{

}


/** 
 * @brief  
 * @note   TODO: implement
 * @retval None
 */
void OrionTest::update(void)
{
    
}


/** 
 * @brief  Retrieve total pack voltage from BMS
 * @note   TODO: Figure the range out from Micaiah
 * @retval Voltage value
 */
float OrionTest::getVoltageTotal(void)
{
    return 0.0;
}


/** 
 * @brief  
 * @note   
 * @retval Average voltage of all the cells in the pack
 */
float OrionTest::getVoltageAverage(void)
{
    return 0.0;
}


/** 
 * @brief  
 * @note   Possibly use this to see when the pack needs rebalancing
 * @retval 
 */
float OrionTest::getVoltageVariance(void)
{
    return 0.0;
}


/** 
 * @brief  Retrieves the min voltage value of all the cells
 * @note   
 * @retval 
 */
float OrionTest::getVoltageMin(void)
{
    return 0.0;
}


/** 
 * @brief  Retrieves the max voltage value of all the cells
 * @note   
 * @retval 
 */
float OrionTest::getVoltageMax(void)
{
    return 0.0;
}


/** 
 * @brief  
 * @note   Could be used in power calculations in addition to the Unitek calculations (I think)
 * @retval 
 */
float OrionTest::getAmperageTotal(void)
{
    return 0.0;
}


/** 
 * @brief  
 * @note   TODO: Is this average temperature? max? min?
 * @retval Temperature of (all?) the cells
 */
float OrionTest::getTemperature(void)
{
    return 0.0;
}


/** 
 * @brief  
 * @note   TODO: Is this possible?
 * @retval Cell number with the min voltage
 */
int OrionTest::getVoltageMinCell(void)
{
    return 0;
}


/** 
 * @brief  
 * @note   TODO: Is this possible?
 * @retval Cell number with the max voltage
 */
int OrionTest::getVoltageMaxCell(void)
{
    return 0;
}