/**  Handles the logic around setting up and sending CAN messages
 *
 * CanController.cpp
 * Created 1-4-18  By: Smitty
 *
 * A longer description.
 */

#include "CanController.hpp"


//to see if the instance of the class has been initialized yet
CanController* CanController::_pInstance = NULL; 

/** 
 * @brief  Used to maintain the singleton format
 * @note   
 * @retval 
 */
CanController* CanController::getInstance()
{
    // Only allow one instance of class to be generated.
    if (!_pInstance)
        _pInstance = new CanController();

    return _pInstance;
}


/** 
 * @brief  CanController destructor
 * @note   Delete any instantiated varibles/objects
 * @retval None
 */
CanController::~CanController(void)
{
    canModel->detachGeneralHandler();
    Can1.detachObj(canModel);
}


/** 
 * @brief  All the complex configuration setup goes here
 * @note   
 * @retval None
 */
void CanController::init(void)
{
    //creating the local CAN model
    canModel = new Can();

    Can1.attachObj(canModel);
    canModel->attachGeneralHandler();
}


/** 
 * @brief  
 * @note   
 * @retval true if we have mail to process
 */
bool CanController::checkMail(void)
{
    return canModel->checkMailVolatile();
}


/** 
 * @brief  Processes and stores the CAN messages until the queue is empty
 * @note   
 * @retval None
 */
void CanController::distributeMail(void)
{
    noInterrupts();
    //transfering CAN messages to non volatile queue
    canModel->storeMail();
    interrupts();

    CAN_message_t canMessage;

    while(!canModel->localMailbox->isEmpty())
    {
        canMessage = canModel->localMailbox->dequeue();

        if(canMessage.id == canModel->ORIONID1)
        {
            // Serial.println("Storing Orion message 0x420");
            OrionController::getInstance()->updateModelMessage_0x420(canMessage.buf);
        }
        else if(canMessage.id == canModel->ORIONID2)
        {
            // Serial.println("Storing Orion message 0x421");
            OrionController::getInstance()->updateModelMessage_0x421(canMessage.buf);
        }
        else if(canMessage.id == canModel->UNITEKREADID)
        {
            //only thing we have to read/store for now
            if(canMessage.buf[0] == REG_HVBUS)
            {
                UnitekController::getInstance()->storeVoltageHvBus(canMessage.buf);
            }

            //error/warning reg
            if(canMessage.buf[0] == REG_ERROR)
            {
                uint16_t errorValue=(canMessage.buf[4]<<8) || canMessage.buf[3];
                uint16_t warningValue=(canMessage.buf[2]<<8) || canMessage.buf[1];
                UnitekController::getInstance()->storeErrorReg(errorValue);
                UnitekController::getInstance()->storeWarningReg(warningValue);
            }
        }


    }
}


/** 
 * @brief  Formats and sends a Unitek CAN message to read the value of a register
 * @note   Add polling if we care about that later
 * @param  regId:    Register ID that you want the value of
 * @param  pollTime: Time for polling interval (or REG_HALTPOLL)
 * @retval None
 */
void CanController::sendUnitekRead(const int regId, uint8_t pollTime)
{
    //initializing and constructing the CAN message for the Unitek
    CAN_message_t unitekMessage;

    unitekMessage.ext = 0;
    unitekMessage.id = canModel->UNITEKSENDID;
    unitekMessage.len = 3;
    unitekMessage.buf[0] = REG_READ;
    unitekMessage.buf[1] = regId;
    unitekMessage.buf[2] = pollTime;

    //FIXME: polling is not implemented yet
    //if(pollTime != 0)     see Unitek Can manual page 14, buf[2] needs to be 0 for one read
    canModel->send(unitekMessage);
}

/** 
 * @brief  formats and sends unitek can message to change the value of a register
 * @note   
 * @param  regID: register you want to change the value of
 * @param  buf1: lower 8 bits of value
 * @param  buf2: upper 8 bits of value
 * @retval None
 */
void CanController::sendUnitekWrite(const int regId, uint8_t buf1, uint8_t buf2){
    //intializing and constructing the CAN message 
    CAN_message_t canMessage;

    canMessage.ext = 0;
    canMessage.id = canModel->UNITEKSENDID;
    canMessage.len = 3;
    canMessage.buf[0] = regId;
    canMessage.buf[1] = buf2;
    canMessage.buf[2] = buf1;

    canModel->send(canMessage);
}
