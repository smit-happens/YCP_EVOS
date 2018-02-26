/**  Display controller class
 *
 * GlcdController.cpp
 * Created 1-5-17 By: Smitty
 *
 * A longer description.
 */

#include "GlcdController.hpp"


//to see if the instance of the class has been initialized yet
GlcdController* GlcdController::_pInstance = NULL; 

/** 
 * @brief  Used to maintain the singleton format
 * @note   
 * @retval 
 */
GlcdController* GlcdController::getInstance()
{
    // Only allow one instance of class to be generated.
    if (!_pInstance)
        _pInstance = new GlcdController();

    return _pInstance;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
GlcdController::~GlcdController(void)
{
    delete glcdModel;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
void GlcdController::init(void)
{
    glcdModel = new Glcd();
}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void GlcdController::poll(void)
{

}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void GlcdController::shutdown(void)
{
    
}