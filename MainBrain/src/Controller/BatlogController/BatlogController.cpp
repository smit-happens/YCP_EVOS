/**  Handles any calculations or logical calculations involving the GLV batteries
 *
 * BatlogController.cpp
 * Created 2-6-18 By: Smitty
 *
 * A longer description.
 */

#include "BatlogController.hpp"


//to see if the instance of the class has been initialized yet
BatlogController* BatlogController::_pInstance = NULL; 

/** 
 * @brief  Used to maintain the singleton format
 * @note   
 * @retval 
 */
BatlogController* BatlogController::getInstance()
{
    // Only allow one instance of class to be generated.
    if (!_pInstance)
        _pInstance = new BatlogController();

    return _pInstance;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
BatlogController::~BatlogController(void)
{
    delete batlogModel;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
void BatlogController::init(void)
{
    batlogModel = new Batlog();
}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void BatlogController::poll(void)
{

}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void BatlogController::shutdown(void)
{
    
}