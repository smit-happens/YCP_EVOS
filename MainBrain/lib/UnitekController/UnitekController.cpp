/**  A one line description of the class.
 *
 * UnitekController.cpp
 * Created 09-30-17 By: Smitty
 *
 * A longer description.
 */

#include "UnitekController.hpp"


/** 
 * @brief  UnitekController constructor
 */
UnitekController::UnitekController(void)
{

}


/** 
 * @brief  Convert RPM to a compatible MC speed value
 * @note   The speed value represents a percentage from 0 to 0x7FFF
 *         That percentage represents the RPM from 0 to RPM_LIMIT (Ex: 7000)
 * @param  rpm: RPM value
 * @retval      Speed value for the MC
 */
int UnitekController::calculateSpeedValue(int rpm)
{
    float percentage = (float)rpm/RPM_LIMIT;
    return percentage*MAX_VAL;
}


/** 
 * @brief  Convert a given MC speed value to RPM
 * @note   
 * @param  speedValue: Given from MC
 * @retval             RPM value
 */
int UnitekController::calculateRpm(int speedValue)
{
    float percentage = (float)speedValue/MAX_VAL;
    return percentage*RPM_LIMIT;
}


/** 
 * @brief  Handles the Precharging logic
 * @note   
 * @retval 0 for success, -1 for error
 */
int precharge(void)
{
    return 0;
}

// TODO: implement this, aka partition out the CAN methods from MC data
// CAN_message_t UnitekController::setupMCMessage(uint8_t regID, uint8_t buf1 = 0x00, uint8_t buf2 = 0x00, bool stopPolling = false)
// {
//   CAN_message_t tx;
//
//   tx.ext = 0;
//   tx.id = 0x201;
//   tx.len = 3;
//
//   if(regID == REG_READ)
//   {
//     //performing a read operation set buf[0] to READ command
//     tx.buf[0] = REG_READ;
//     tx.buf[1] = buf1;
//
//     //default is 0 but can represent time (in ms) for polling
//     tx.buf[2] = buf2;
//
//     //deactivates polling
//     if(stopPolling)
//     {
//       tx.buf[2] = REG_HALTPOLL;
//     }
//   }
//   else
//   {
//     //performing write opration
//     tx.buf[0] = regID;
//
//     //storing the value in byte flipped order
//     tx.buf[2] = buf1;
//     tx.buf[1] = buf2;
//   }
//
//   return tx;
// }
