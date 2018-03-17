/**  LightController manages all the lights and light states
 *
 * LightController.cpp
 * Created 2-25-18 By: Smitty
 *
 * A longer description.
 */

#include "LightController.hpp"


//to see if the instance of the class has been initialized yet
LightController* LightController::_pInstance = NULL; 

/** 
 * @brief  Used to maintain the singleton format
 * @note   
 * @retval 
 */
LightController* LightController::getInstance()
{
    // Only allow one instance of class to be generated.
    if (!_pInstance)
        _pInstance = new LightController();

    return _pInstance;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
LightController::~LightController(void)
{
    delete light;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
void LightController::init(void)
{
    light = new Light();
}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void LightController::poll(void)
{

}