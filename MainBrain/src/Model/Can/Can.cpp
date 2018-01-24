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
    //initializing the CAN port at 500k baud
    Can1.begin(500000);
}


// void Can::printFrame(CAN_message_t &frame, int mailbox)
// {
//     Serial.print("This just in!\n");
//     Serial.print("ID: 0x");
//     Serial.print(frame.id, HEX);

//     //Print regID from buf[0] (only for unitek)
//     Serial.print(" RegID: 0x");
//     Serial.print(frame.buf[0], HEX);

//     //Print value from register in reverse byte order
//     Serial.print(" Data: 0x");
//     Serial.print(frame.buf[2], HEX);
//     Serial.print(frame.buf[1], HEX);
// }


/** 
 * @brief  Called whenever a new CAN frame is received
 * @note   All CAN messages will be sent received from mailbox 1 (CAN port 1) 
 * @param  &frame:  CAN_message_t reference
 * @param  mailbox: Port message came on
 * @retval None
 */
void Can::gotFrame(CAN_message_t &frame, int mailbox)
{
    //TODO: message just came in, check ID and send data to Unitek or Orion
    //check id, store in orion or unitek queue, (maybe) set queueHasDataFlag
}


/** 
 * @brief  Sends a CAN message out on the wire
 * @note   
 * @retval None
 */
void Can::send(CAN_message_t message)
{
    Can1.write(message);
}
