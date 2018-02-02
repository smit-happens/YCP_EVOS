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
CanController* ControllerManager::canC = new CanController();
CoolingController* ControllerManager::coolingC = new CoolingController();
DashController* ControllerManager::dashC = new DashController();
GlcdController* ControllerManager::glcdC = new GlcdController();
ImdController* ControllerManager::imdC = new ImdController();
OrionController* ControllerManager::orionC = new OrionController();
PedalController* ControllerManager::pedalC = new PedalController();
SdCardController* ControllerManager::sdCardC = new SdCardController();
UnitekController* ControllerManager::unitekC = new UnitekController();


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
 * @retval Pointer to the CoolingController
 */
CoolingController* ControllerManager::getCoolingC(void)
{
    return coolingC;
}


/** 
 * @brief  This is for singletons
 * @note   
 * @retval Pointer to the DashController
 */
DashController* ControllerManager::getDashC(void)
{
    return dashC;
}


/** 
 * @brief  This is for singletons
 * @note   
 * @retval Pointer to the GlcdController
 */
GlcdController* ControllerManager::getGlcdC(void)
{
    return glcdC;
}


/** 
 * @brief  This is for singletons
 * @note   
 * @retval Pointer to the ImdController
 */
ImdController* ControllerManager::getImdC(void)
{
    return imdC;
}


/** 
 * @brief  This is for singletons
 * @note   
 * @retval Pointer to the OrionController
 */
OrionController* ControllerManager::getOrionC(void)
{
    return orionC;
}


/** 
 * @brief  This is for singletons
 * @note   
 * @retval Pointer to the PedalController
 */
PedalController* ControllerManager::getPedalC(void)
{
    return pedalC;
}


/** 
 * @brief  This is for singletons
 * @note   
 * @retval Pointer to the SdCardController
 */
SdCardController* ControllerManager::getSdCardC(void)
{
    return sdCardC;
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