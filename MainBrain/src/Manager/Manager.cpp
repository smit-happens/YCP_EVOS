/**  Handles all the pointers of the singletons
 *
 * Manager.cpp
 * Created 1-21-18 By: Smitty
 *
 * A longer description.
 */

#include "Manager.hpp"

//Calling the constructor of each controller
//NOTE: Do NOT perform complex functions or anything harder than
//      memory allocation in constructor
UnitekController* Manager::unitekC = new UnitekController();
CanController* Manager::canC = new CanController();

/** 
 * TODO: Initialize the pointers for the other controllers 
 * PedalController* Manager::pedalC = new PedalController();
 * 
 * 
 */


/** 
 * @brief  This is for singletons
 * @note   
 * @retval Pointer to the CanController
 */
CanController* Manager::getCanC(void)
{
    return canC;
}


/** 
 * @brief  This is for singletons
 * @note   
 * @retval Pointer to the UnitekController
 */
UnitekController* Manager::getUnitekC(void)
{
    return unitekC;
}