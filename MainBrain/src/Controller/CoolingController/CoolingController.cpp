/**  Cooling controller class
 *
 * CoolingController.cpp
 * Created 1-17-17 By: Smitty
 *
 * A longer description.
 */

#include "CoolingController.hpp"


//to see if the instance of the class has been initialized yet
CoolingController* CoolingController::_pInstance = NULL; 

/** 
 * @brief  Used to maintain the singleton format
 * @note   
 * @retval 
 */
CoolingController* CoolingController::getInstance()
{
    // Only allow one instance of class to be generated.
    if (!_pInstance)
        _pInstance = new CoolingController();

    return _pInstance;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
CoolingController::~CoolingController(void)
{
    delete coolingModel;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
void CoolingController::init(void)
{
    coolingModel = new CoolingSystem();
}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void CoolingController::poll(void)
{

}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void CoolingController::shutdown(void)
{
    
}