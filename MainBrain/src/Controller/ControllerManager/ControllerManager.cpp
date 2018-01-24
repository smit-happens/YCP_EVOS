/**  Handles all the pointers of the controller singletons
 *
 * ControllerManager.cpp
 * Created 1-21-18 By: Smitty
 *
 * A longer description.
 */

#include "ControllerManager.hpp"

//Calling the constructor of each controller
//NOTE: Do NOT perform complex functions or anything harder than
//      memory allocation in constructor
UnitekController* ControllerManager::unitekC = new UnitekController();
CanController* ControllerManager::canC = new CanController();

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
CanController* ControllerManager::getCanC(void)
{
    return canC;
}


/** 
 * @brief  This is for singletons
 * @note   
 * @retval Pointer to the UnitekController
 */
UnitekController* ControllerManager::getUnitekC(void)
{
    return unitekC;
}