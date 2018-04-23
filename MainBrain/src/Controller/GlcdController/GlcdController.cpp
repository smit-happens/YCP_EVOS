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
    //Logger::getInstance()->addSubscriber(_pInstance);
    glcdModel = new Glcd();
    mode = MODE_DASH; //start the mode off at dashboard
}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void GlcdController::poll(void)
{
    //glcdModel->drawBattBars(30, 60);
    if(glcdModel->getDirtyBit()){
        glcdModel->flushGlcdBuffer();
    }
}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void GlcdController::shutdown(void)
{
    glcdModel->showShutdownLogo();
}


void GlcdController::setNewState(Stage stage) {
    //Logger::getInstance()->log("GLCD_Controller", "Setting Mode", MSG_DEBUG);
    if(mode == MODE_DASH){ //TODO: set mode here? or just display if already in dash?
        glcdModel->drawModeSelection(stage);
        setupDashMode(); //screen reset we need to re-setup the dash
    
    } 
}

void GlcdController::setupDashMode()
{
    glcdModel->setupBattBars(); //screen cleared we need to resetup the dash
    glcdModel->drawBattBars(30, 60);
}

/** 
 * @brief  Displays the just barely logo
 * @note   
 * @retval None
 */
void GlcdController::justBarelyLogo(void)
{

    glcdModel->showBootLogo();

    analogWrite(MB_B, 65535);
    analogWrite(MB_G, 65535);
    analogWrite(MB_R, 65535);

    // for(int i =0; i<65535; i++)
    // {
    //     analogWrite(MB_B, i);
    //     delayMicroseconds(10);
    // }
    
    // for(int i =0; i<65535; i++)
    // {
    //     analogWrite(MB_G, i);
    //     delayMicroseconds(10);
    // }

    // for(int i =0; i<65535; i++)
    // {
    //     analogWrite(MB_R, i);
    //     delayMicroseconds(10);
    // }
}

void GlcdController::onLogFiled(const char* key, const char* message,  msg_type type) {
    //TODO: print messages to screen
}