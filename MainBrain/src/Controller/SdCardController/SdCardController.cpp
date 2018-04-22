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
void SdCardController::init(void)
{
    sdCardModel = new SdCard();
    //Logger::getInstance()->addSubscriber(_pInstance);
    noInterrupts(); //this must be atomic

    if(!sdCardModel->beginCard())
        Logger::getInstance()->log("SDCARD_C", "Could not Initalize SD card",  MSG_ERR);
    else
        Logger::getInstance()->log("SDCARD_C", "SD card Initalized",  MSG_LOG);

    //attempt to open sdfile
    if(!sdCardModel->openFile())
        Logger::getInstance()->log("SDCARD_C", "Could not Open SD file",  MSG_ERR);
    else
        Logger::getInstance()->log("SDCARD_C", "SD file opened",  MSG_LOG);

    setupLogFileHeader();

    Logger::getInstance()->log("SDCARD_C", sdCardModel->getFileName(), MSG_DEBUG);

    interrupts();
}


void SdCardController::setupLogFileHeader()
{
    char msg[50];
    strcpy(msg, "Millis");
    strcat(msg, DELIM);
    strcat(msg, "Calling Class");
    strcat(msg, DELIM);
    strcat(msg, "Message");
    strcat(msg, DELIM);
    strcat(msg, "Log Level");
    strcat(msg, DELIM);
    sdCardModel->writeMessage(msg);
}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void SdCardController::shutdown(void)
{
    //closing the sdcard file
    sdCardModel->closeFile();
    Logger::getInstance()->log("SDCARD_C", "SD card file closed.", MSG_LOG);    
}

void SdCardController::onLogFiled(const char* key, const char* message,  msg_type type) 
{
    //TODO: Log to SD Card file
    if(strcmp(key, "SD_CARD") == 0) {return;} // do not log any SD card messages to the SD card.

    if(sdCardModel->hasCardBegun() && sdCardModel->isFileOpen())
    {
        char msg[MSG_STR_BUF_LEN]; //FIXME: buffer overflow?
        bool writeOut = false;
        sprintf(msg, "%lu", millis()); //record time of log
        strcat(msg, DELIM);
        strcat(msg, key);
        strcat(msg, DELIM);
        strcat(msg, message);
        strcat(msg, DELIM);
        switch(type) 
        {
            case MSG_ERR:
                strcat(msg, "ERR");
                writeOut = true;
            break;
            case MSG_LOG:
                strcat(msg, "LOG");
            break;
            case MSG_WARN:
                strcat(msg, "WARN");
                writeOut = true;
            break;
            case MSG_DEBUG:
                strcat(msg, "DEBUG");
            break;
            default:break;
        }

        noInterrupts(); //write is atomic 
        sdCardModel->writeMessage(msg, writeOut);
        interrupts();
    }
}