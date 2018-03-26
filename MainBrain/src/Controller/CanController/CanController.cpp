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
    //TODO: remove this
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
 * @retval None
 */
void CanController::poll(void)
{
    //TODO: implement this
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

    unitekMessage.id = canModel->UNITEKSENDID;
    unitekMessage.len = 3;
    unitekMessage.buf[0] = REG_READ;
    unitekMessage.buf[1] = regId;
    unitekMessage.buf[2] = pollTime;

    //FIXME: polling is not implemented yet
    //if(pollTime != 0)     see Unitek Can manual page 14, buf[2] needs to be 0 for one read
    canModel->send(unitekMessage);

    //Debug print statements
    Serial.print(unitekMessage.id, HEX);
    Serial.print(unitekMessage.buf[0], HEX);
    Serial.print(unitekMessage.buf[1], HEX);
    Serial.println(unitekMessage.buf[2], HEX);
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

    canMessage.id=canModel->UNITEKSENDID;
    canMessage.len=3;
    canMessage.buf[0]=regId;
    canMessage.buf[1]=buf2;
    canMessage.buf[2]=buf1;

    // canModel.
    canModel->send(canMessage);

    //Debug print statements
    Serial.print(canMessage.id, HEX);
    Serial.print(canMessage.buf[0], HEX);
    Serial.print(canMessage.buf[1], HEX);
    Serial.println(canMessage.buf[2], HEX);
}
