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
    Logger::getInstance()->addSubscriber(_pInstance);
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


/** 
 * @brief  Displays the just barely logo
 * @note   
 * @retval None
 */
void GlcdController::justBarelyLogo(void)
{

    glcdModel->showBootLogo();

    for(int i =0; i<65535; i++)
    {
        analogWrite(MB_B, i);
        delayMicroseconds(10);
    }
    
    for(int i =0; i<65535; i++)
    {
        analogWrite(MB_G, i);
        delayMicroseconds(10);
    }

    for(int i =0; i<65535; i++)
    {
        analogWrite(MB_R, i);
        delayMicroseconds(10);
    }
}

void GlcdController::onLogFiled(const char* key, const char* message,  msg_type type) {
    //TODO: print messages to screen
}