/**  Handles the logic around setting up and sending CAN messages
 *
 * CanControllerTest.cpp
 * Created 1-4-18  By: Smitty
 *
 * A longer description.
 */

#include "CanControllerTest.hpp"


//to see if the instance of the class has been initialized yet
CanControllerTest* CanControllerTest::_pInstance = NULL; 

/** 
 * @brief  Used to maintain the singleton format
 * @note   
 * @retval 
 */
CanControllerTest* CanControllerTest::getInstance()
{
    // Only allow one instance of class to be generated.
    if (!_pInstance)
        _pInstance = new CanControllerTest();

    return _pInstance;
}


/** 
 * @brief  CanControllerTest destructor
 * @note   Delete any instantiated varibles/objects
 * @retval None
 */
CanControllerTest::~CanControllerTest(void)
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
void CanControllerTest::init(void)
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
void CanControllerTest::poll(void)
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
void CanControllerTest::sendUnitekRead(uint8_t regId, uint8_t pollTime = 0)
{
    //initializing and constructing the CAN message for the Unitek
    CAN_message_t unitekMessage;

    unitekMessage.id = canModel->UNITEKSENDID;
    unitekMessage.len = 3;
    unitekMessage.buf[0] = REG_READ;
    unitekMessage.buf[1] = regId;
    unitekMessage.buf[2] = pollTime;

    //FIXME: polling is not implemented yet
    if(pollTime != 0)
        canModel->send(unitekMessage);

    //Debug print statements
    Serial.print(unitekMessage.id);
    Serial.print(unitekMessage.buf[0]);
    Serial.print(unitekMessage.buf[1]);
    Serial.print(unitekMessage.buf[2]);
}

/** 
 * @brief  formats and sends unitek can message to change the value of a register
 * @note   
 * @param  regID: register you want to change the value of
 * @param  buf1: lower 8 bits of value
 * @param  buf2: upper 8 bits of value
 * @retval None
 */
void CanControllerTest::sendUnitekWrite(uint8_t regID, uint8_t buf1, uint8_t buf2){
    //intializing and constructing the CAN message 
    CAN_message_t canMessage;

    canMessage.id=canModel->UNITEKSENDID;
    canMessage.len=3;
    canMessage.buf[0]=regID;
    canMessage.buf[1]=buf2;
    canMessage.buf[2]=buf1;

    // canModel.
    canModel->send(canMessage);

    //Debug print statements
    Serial.print(canMessage.id);
    Serial.print(canMessage.buf[0]);
    Serial.print(canMessage.buf[1]);
    Serial.print(canMessage.buf[2]);
}


// /** 
//  * @brief  
//  * @note   TODO: Have this work for Unitek and Orion
//  * @retval 
//  */
// int CanControllerTest::parse(void)
// {
//     return 0;
// }