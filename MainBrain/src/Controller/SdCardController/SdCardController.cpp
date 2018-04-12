/**  Only has knowledge about creating/editing csv files
 *
 * SdCardController.cpp
 * Created 1-13-17 By: Smitty
 *
 * A longer description.
 */

#include "SdCardController.hpp"



//to see if the instance of the class has been initialized yet
SdCardController* SdCardController::_pInstance = NULL; 

/** 
 * @brief  Used to maintain the singleton format
 * @note   
 * @retval 
 */
SdCardController* SdCardController::getInstance()
{
    // Only allow one instance of class to be generated.
    if (!_pInstance)
        _pInstance = new SdCardController();

    return _pInstance;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
SdCardController::~SdCardController(void)
{
    delete sdCardModel;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
void SdCardController::init(void)
{
    sdCardModel = new SdCard();
    Logger::getInstance()->addSubscriber(_pInstance);
    
    noInterrupts(); //this must be atomic
    sdCardModel->beginCard();
    sdCardModel->openFile();
    sdCardModel->writeMessage("Milis | Calling Class | Message | Log Level");
    interrupts();
}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void SdCardController::poll(void)
{

}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void SdCardController::shutdown(void)
{
    //TODO: close sdcard file off. 
    sdCardModel->closeFile();
}

void SdCardController::onLogFiled(const char* key, const char* message,  msg_type type) 
{
    //TODO: Log to SD Card file
    if(sdCardModel->hasCardBegun() && sdCardModel->isFileOpen()){
        char msg[100];
        sprintf(msg, "%lu|", millis()); //record time of log
        strcat(msg, key);
        strcat(msg, "|");
        strcat(msg, message);
        strcat(msg, "|");
        switch(type) {
            case MSG_ERR:
                strcat(msg, "ERR");
            break;
            case MSG_LOG:
                strcat(msg, "LOG");
            break;
            case MSG_WARN:
                strcat(msg, "WARN");
            break;
            case MSG_DEBUG:
                strcat(msg, "DEBUG");
            break;
            default:break;
        }
        noInterrupts(); //write is atomic 
        sdCardModel->writeMessage(msg);
        interrupts();
    }
}