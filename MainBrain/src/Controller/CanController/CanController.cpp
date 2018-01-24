/**  Handles the logic around setting up and sending CAN messages
 *
 * CanController.cpp
 * Created 1-4-18  By: Smitty
 *
 * A longer description.
 */

#include "CanController.hpp"
#include "../../Manager/Manager.hpp"


/** 
 * @brief  CanController constructor
 */
CanController::CanController(void)
{
    
}


/** 
 * @brief  CanController destructor
 * @note   Delete any instantiated varibles/objects
 * @retval None
 */
CanController::~CanController(void)
{
    //This causes a warning: deleting object of polymorphic class type 'Can' 
    //which has non-virtual destructor might cause undefined behaviour
    //delete canModel;
}


/** 
 * @brief  All the complex configuration setup goes here
 * @note   
 * @retval None
 */
void CanController::init(void)
{
    //creating the local CAN model
    canModel = new Can;

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
void CanController::sendUnitekRead(uint8_t regId, uint8_t pollTime = 0)
{
    //initializing and constructing the CAN message for the Unitek
    CAN_message_t unitekMessage;

    unitekMessage.id = canModel->ORIONSENDID;
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


// /** 
//  * @brief  
//  * @note   TODO: Have this work for Unitek and Orion
//  * @retval 
//  */
// int CanController::messageParse(void)
// {
//     return 0;
// }