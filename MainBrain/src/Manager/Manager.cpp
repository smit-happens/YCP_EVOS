/**  Handles all the pointers of the singletons
 *
 * Manager.cpp
 * Created 1-21-18 By: Smitty
 *
 * A longer description.
 */

#include "Manager.hpp"


/** 
 * @brief  
 * @note   
 * @retval Pointer to the CanController
 */
CanController* Manager::getCanC(void)
{
    return canC;
}


/** 
 * @brief  
 * @note   
 * @retval Pointer to the UnitekController
 */
UnitekController* Manager::getUnitekC(void)
{
    return unitekC;
}