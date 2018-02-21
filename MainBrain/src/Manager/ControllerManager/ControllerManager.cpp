/**  Handles all the pointers of the controller singletons
 *
 * ControllerManager.cpp
 * Created 1-21-18 By: Smitty
 *
 * A longer description.
 */

#include "ControllerManager.hpp"

// Global static pointer used to ensure a single instance of this class
ControllerManager* ControllerManager::_pInstance = NULL; 


ControllerManager* ControllerManager::getInstance()
{
    // Only allow one instance of class to be generated.
    if (!_pInstance)
        _pInstance = new ControllerManager();

    return _pInstance;
}


void ControllerManager::initControllers(void)
{
    //Calling the constructor of each controller
    //NOTE: Do NOT perform complex functions or anything harder than
    //      memory allocation in constructor
    // batlogC = new BatlogController();
    // canC = new CanController();
    // coolingC = new CoolingController();
    // dashC = new DashController();
    // glcdC = new GlcdController();
    // imdC = new ImdController();
    // orionC = new OrionController();
    // pedalC = new PedalController();
    // sdCardC = new SdCardController();
    // unitekC = new UnitekController();
}


/** 
 * @brief  This is for singletons
 * @note   
 * @retval Pointer to the UnitekController
 */
BatlogController* ControllerManager::getBatlogC(void)
{
    return batlogC;
}


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