/**  Represents the Model of a CAN message
 *
 * Can.cpp
 * Created 09-30-17  By: Smitty
 *
 * A longer description.
 */

#include "Can.hpp"


/** 
 * @brief  Can constructor
 */
Can::Can(void)
{

}


/** 
 * @brief  Prints out a given MC CAN frame
 * @note   TODO: generalize this for MC and Orion (use CAN id)
 * @param  &frame:  CAN_message_t reference
 * @param  mailbox: Port to listen to
 * @retval None
 */
void Can::printFrame(CAN_message_t &frame, int mailbox)
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
 * @brief  Called whenever a new CAN frame is received
 * @note   All CAN messages will be sent received from mailbox 1 (CAN port 1) 
 * @param  &frame:  CAN_message_t reference
 * @param  mailbox: Port to listen on
 * @retval None
 */
void Can::gotFrame(CAN_message_t &frame, int mailbox)
{
  printFrame(frame, mailbox);
}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void sendUnitek(void)
{
    //Can1.write(CAN_message_t stuff);
}


/** 
 * @brief  
 * @note   
 * @param  &frame: 
 * @param  mailbox: 
 * @retval None
 */
void readUnitek(CAN_message_t &frame)
{

}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void sendOrion(void)
{

}


/** 
 * @brief  
 * @note   
 * @param  &frame: 
 * @param  mailbox: 
 * @retval None
 */
void readOrion(CAN_message_t &frame)
{

}