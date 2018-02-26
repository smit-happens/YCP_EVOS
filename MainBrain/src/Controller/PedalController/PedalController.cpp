/**  Pedal controller class
 *
 * PedalController.cpp
 * Created 1-17-17 By: Smitty
 *
 * A longer description.
 */

#include "PedalController.hpp"


//to see if the instance of the class has been initialized yet
PedalController* PedalController::_pInstance = NULL; 

/** 
 * @brief  Used to maintain the singleton format
 * @note   
 * @retval 
 */
PedalController* PedalController::getInstance()
{
    // Only allow one instance of class to be generated.
    if (!_pInstance)
        _pInstance = new PedalController();

    return _pInstance;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
PedalController::~PedalController(void)
{
    delete brakeModel;
    delete gasModel;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
void PedalController::init(void)
{
    brakeModel = new BrakePedal();
    gasModel = new GasPedal();
}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void PedalController::poll(void)
{

}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void PedalController::shutdown(void)
{
    
}