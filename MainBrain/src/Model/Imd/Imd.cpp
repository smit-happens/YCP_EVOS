/**  IMD == Insulation Monitoring Device
 *
 * Imd.cpp
 * Created 12-20-17  By: Smitty
 *
 * A longer description.
 */

#include "Imd.hpp"


/** 
 * @brief  Imd constructor
 */
Imd::Imd(void)
{
    pinMode(MB_IMD_STATUS, INPUT);
}


/** 
 * @brief  Imd destructor
 */
Imd::~Imd(void)
{

}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void Imd::update(void)
{
    
}


/** 
 * @brief  Current stored state of the IMD
 * @note   
 * @retval true = bad; false = good
 */
bool Imd::isTriggered(void)
{
  return false;
}


/** 
 * @brief  Called from some rising edge interupt on the IMD_STATUS pin
 * @note   
 * @retval None
 */
void Imd::trigger(void)
{

}