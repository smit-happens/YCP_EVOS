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
    //initialized in the base pedal class
}


/** 
 * @brief  GasPedal destructor
 */
GasPedal::~GasPedal(void)
{

}


/** 
 * @brief  Retrieves and stores the value of the gas Potentiometer
 * @note   
 * @retval None
 */
void GasPedal::update(void)
{
    _rawValue = analogRead(MB_GAS_LIN);
}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void GasPedal::setRawOrigin(void)
{
    _rawOrigin = analogRead(MB_GAS_LIN);
}
