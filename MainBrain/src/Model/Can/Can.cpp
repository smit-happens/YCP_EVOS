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
