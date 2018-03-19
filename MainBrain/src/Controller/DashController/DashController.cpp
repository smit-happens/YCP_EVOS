/**  DashController manages all the buttons and forms of user feedback/input to the EV
 *
 * DashController.cpp
 * Created 1-17-17 By: Smitty
 *
 * A longer description.
 */

#include "DashController.hpp"


//to see if the instance of the class has been initialized yet
DashController* DashController::_pInstance = NULL; 

/** 
 * @brief  Used to maintain the singleton format
 * @note   
 * @retval 
 */
DashController* DashController::getInstance()
{
    // Only allow one instance of class to be generated.
    if (!_pInstance)
        _pInstance = new DashController();

    return _pInstance;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
DashController::~DashController(void)
{
    delete buttons;
    delete screen;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
void DashController::init(void)
{
    buttons = new Button();
    screen = new Glcd();
    siren = new Siren();
}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void DashController::poll(void)
{

}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void DashController::shutdown(void)
{
    
}