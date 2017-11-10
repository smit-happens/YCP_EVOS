/**  A one line description of the class.
 *
 * CanController.cpp
 * Created 09-30-17  By: Smitty
 *
 * A longer description.
 */

#include "CanController.hpp"


/** 
 * @brief  CanController constructor
 */
CanController::CanController(void)
{

}


/** 
 * @brief  Prints out a given MC CAN frame
 * @note   TODO: generalize this for MC and Orion (use CAN id)
 * @param  &frame:  CAN_message_t reference
 * @param  mailbox: Port to listen to
 * @retval None
 */
void CanController::printFrame(CAN_message_t &frame, int mailbox)
{
  Serial.print("This just in!\n");
  Serial.print("ID: 0x");
  Serial.print(frame.id, HEX);

  //Print regID from buf[0]
  Serial.print(" RegID: 0x");
  Serial.print(frame.buf[0], HEX);

  //Print value from register in reverse byte order
  Serial.print(" Data: 0x");
  Serial.print(frame.buf[2], HEX);
  Serial.print(frame.buf[1], HEX);

  Serial.write('\n');
}


/** 
 * @brief  Called whenever a new CAN frame is recieved
 * @note   
 * @param  &frame:  CAN_message_t reference
 * @param  mailbox: Port to listen to
 * @retval None
 */
void CanController::gotFrame(CAN_message_t &frame, int mailbox)
{
  printFrame(frame, mailbox);
}


//TODO: Function to construct CAN message given ID and data
// should be able to work for BMS and MC easily
