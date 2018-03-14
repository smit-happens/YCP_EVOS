/**  OrionController manages all data processing for the Orion BMS
 *
 * OrionController.cpp
 * Created 2-2-18 By: Smitty
 *
 * A longer description.
 */

#include "OrionController.hpp"


//to see if the instance of the class has been initialized yet
OrionController* OrionController::_pInstance = NULL; 

/** 
 * @brief  Used to maintain the singleton format
 * @note   
 * @retval 
 */
OrionController* OrionController::getInstance()
{
    // Only allow one instance of class to be generated.
    if (!_pInstance)
        _pInstance = new OrionController();

    return _pInstance;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
OrionController::~OrionController(void)
{
    delete orionModel;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
void OrionController::init(void)
{
    orionModel = new Orion();
}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void OrionController::poll(void)
{

}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void OrionController::shutdown(void)
{
    
}

/** 
 * @brief  gets total pack voltage for 90% pre-charge setting
 * @note   need to determine output type of orion
 * @retval total voltage of all batteries
 */
float OrionController::getPackVoltage(void)
{
    return 0.0;
}