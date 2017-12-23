/**  BSPD == Brake System Plausibility Device
 *
 * Bspd.cpp
 * Created 12-20-17  By: Smitty
 *
 * A longer description.
 */

#include "Bspd.hpp"


/** 
 * @brief  Bspd constructor
 */
Bspd::Bspd(void)
{

}


/** 
 * @brief  Current stored state of the BSPD
 * @note   
 * @retval true = bad; false = good
 */
bool Bspd::isTriggered(void)
{
  return false;
}


/** 
 * @brief  Called from some rising edge interupt on the BSPD_STATUS pin
 * @note   
 * @retval None
 */
void Bspd::trigger(void)
{

}