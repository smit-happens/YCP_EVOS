/**  IMD controller class
 *
 * ImdController.cpp
 * Created 1-17-17 By: Smitty
 *
 * A longer description.
 */

#include "ImdController.hpp"


//to see if the instance of the class has been initialized yet
ImdController* ImdController::_pInstance = NULL; 

/** 
 * @brief  Used to maintain the singleton format
 * @note   
 * @retval 
 */
ImdController* ImdController::getInstance()
{
    // Only allow one instance of class to be generated.
    if (!_pInstance)
        _pInstance = new ImdController();

    return _pInstance;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
ImdController::~ImdController(void)
{
    delete imdModel;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
void ImdController::init(void)
{
    imdModel = new Imd();
}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void ImdController::poll(void)
{

}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void ImdController::shutdown(void)
{
    
}