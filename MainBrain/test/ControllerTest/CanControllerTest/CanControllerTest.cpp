/**  Handles the logic around setting up and sending CAN messages
 *
 * CanControllerTest.cpp
 * Created 1-4-18  By: Smitty
 *
 * A longer description.
 */

#include "CanControllerTest.hpp"

CanControllerTest::CanControllerTest(void)
{

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
    // CAN_message_t unitekMessage;

    // unitekMessage.id = canModel->UNITEKSENDID;
    // unitekMessage.len = 3;
    // unitekMessage.buf[0] = REG_READ;
    // unitekMessage.buf[1] = regId;
    // unitekMessage.buf[2] = pollTime;

    // //FIXME: polling is not implemented yet
    // if(pollTime != 0)
    //     canModel->send(unitekMessage);
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
    // CAN_message_t canMessage;

    // canMessage.id=canModel->UNITEKSENDID;
    // canMessage.len=3;
    // canMessage.buf[0]=regID;
    // canMessage.buf[1]=buf2;
    // canMessage.buf[2]=buf1;

    // // canModel.
    // canModel->send(canMessage);
}
