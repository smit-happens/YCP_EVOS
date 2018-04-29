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
    setNewMode(MODE_BEGIN);
}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void GlcdController::poll(void)
{
    if(mode == MODE_DASH) 
    {
        glcdModel->drawBattBars(0, 95);
    }
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



void GlcdController::setNewMode(DispMode theMode) 
{ //TODO: Clear screen buffer!
    mode = theMode;
    switch(mode) 
    {
        case MODE_DASH:
            setupDashMode();
        break;
        case MODE_ERR:
            //TODO: draw errors
        break;
        case MODE_BEGIN:
            //draw accept screen
            justBarelyLogo();
        break;
        case MODE_TEMP:
            //TODO: Draw temperatures  
        break;
        default: break; 
    }
}

GlcdController::DispMode GlcdController::advanceMode() 
{
    switch(mode) 
    {
        case MODE_DASH:
            setNewMode(MODE_TEMP);
        break;
        case MODE_ERR:
            //do nothing
        break;
        case MODE_BEGIN:
            setNewMode(MODE_BEGIN);
        break;
        case MODE_TEMP:
            setNewMode(MODE_DASH);  
        break;
        default: break; 
    }
}


void GlcdController::setNewState(Stage stage) {
    //Logger::getInstance()->log("GLCD_Controller", "Setting Mode", MSG_DEBUG);
    if(mode == MODE_DASH){ //TODO: set mode here? or just display if already in dash?
        glcdModel->drawModeSelection(stage);
        setupDashMode(); //screen reset we need to re-setup the dash
    }  else if(mode == MODE_BEGIN && stage == STAGE_STANDBY) {
        glcdModel->clearAllErrors();
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
    glcdModel->drawOkIcon();
    glcdModel->drawErrors(ERR_ALL);
    glcdModel->flushGlcdBuffer();
    
    analogWrite(MB_B, 65535);
    analogWrite(MB_G, 65535);
    analogWrite(MB_R, 65535);
}

void GlcdController::onLogFiled(const char* key, const char* message,  msg_type type) {
    //TODO: print messages to screen
}