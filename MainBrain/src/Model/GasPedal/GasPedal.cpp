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
    //initializing the values of the gasPedal
    _linValue = 0;
    _logValue = 0;
}


/** 
 * @brief  GasPedal destructor
 */
GasPedal::~GasPedal(void)
{

}


/** 
 * @brief  Retrieves and stores the value of the 2 gas Potentiometers
 * @note   
 * @retval None
 */
void GasPedal::update(void)
{
    _linValue = analogRead(MB_GAS_LIN);
    _logValue = analogRead(MB_GAS_LOG);
}



void GasPedal::setOrigin(void)
{
    _linOrigin = analogRead(MB_GAS_LIN);
    _logOrigin = analogRead(MB_GAS_LOG);
}


/** 
 * @brief  Retrieves the value of the Linear Potentiometer
 * @note   value of 0-8195
 * @retval Analog voltage sensed
 */
uint16_t GasPedal::getLinValue(void)
{
    return _linValue;
}


/** 
 * @brief  Retrieves the value of the Logarithmic Potentiometer
 * @note   value of 0-8195
 * @retval Analog voltage sensed
 */
uint16_t GasPedal::getLogValue(void)
{
    return _logValue;
}

/** 
 * @brief  Retrieves the origin of the Linear Potentiometer
 * @note   value of 0-8195
 * @retval Analog voltage sensed at origin (zero position)
 */
uint16_t GasPedal::getLinOrigin(void)
{
    return _linOrigin;
}


/** 
 * @brief  Retrieves the origin of the Logarithmic Potentiometer
 * @note   value of 0-8195
 * @retval Analog voltage sensed at origin (zero position)
 */
uint16_t GasPedal::getLogOrigin(void)
{
    return _logOrigin;
}