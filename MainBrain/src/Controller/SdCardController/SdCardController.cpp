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
    
}

void SdCardController::onLogFiled(char* key, char* message,  msg_type type) {
    //TODO: Move to serial logger class. 
    Serial.print(key); 
    Serial.print("\t");
    Serial.print(message);
    Serial.print("\t");

    switch(type) {
        case MSG_ERR:
            Serial.print("ERR");
        break;
        case MSG_LOG:
            Serial.print("LOG");
        break;
        case MSG_WARN:
             Serial.print("WARN");
        break;
        case MSG_DEBUG:
             Serial.print("DEBUG");
        break;
        default:break;
    }

    Serial.println();
}