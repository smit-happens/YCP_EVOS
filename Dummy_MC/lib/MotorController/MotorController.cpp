/**  A one line description of the class.
 *
 * MotorController.cpp
 * Created 09-30-17 By: Smitty
 *
 * A longer description.
 */

#include "MotorController.hpp"


/**
 * MotorController constructor
 */
MotorController::MotorController(void)
{

}


/**
 * Just a test function
 * @return  Hex value of REG_READ
 */
uint8_t MotorController::testFunc(void)
{
  return REG_READ;
}


// TODO: implement this, aka partition out the CAN methods from MC data
// CAN_message_t MotorController::setupMCMessage(uint8_t regID, uint8_t buf1 = 0x00, uint8_t buf2 = 0x00, bool stopPolling = false)
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
