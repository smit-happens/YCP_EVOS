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

    //queue used for the main receiver of new CAN messages to be sorted later
    // mailbox = new Queue(sizeof(CAN_message_t), 20, FIFO);
    
    // //internal inboxes for the Unitek and Orion devices
    // inboxUnitek = new Queue(sizeof(uint8_t)*4, 20, FIFO);
    // inboxOrion = new Queue(sizeof(CAN_message_t), 20, FIFO);
}


/** 
 * @brief  Can destructor
 */
Can::~Can(void)
{

}


/** 
 * @brief  
 * @note   TODO: fill this out (if necessary)
 * @retval None
 */
void Can::update(void)
{
    
}



/** 
 * @brief  Called whenever a new CAN frame is received
 * @note   All CAN messages will be sent received from CAN port 1
 * @param  &frame:  CAN_message_t reference
 * @param  mailbox: Port message came on
 * @retval None
 */
void Can::gotFrame(CAN_message_t &frame, int mailbox)
{
    //TODO: message just came in, check ID and send data to Unitek or Orion
    //check id, store in orion or unitek queue, (maybe) set queueHasDataFlag

    //FIXME: TESTING CODE
    Serial.println("Entered CAN interrupt");
    Serial.println(frame.id, HEX);
    Serial.println(frame.buf[0], HEX);
    Serial.println(frame.buf[1], HEX);
    Serial.println(frame.buf[2], HEX);
    Serial.println(frame.buf[3], HEX);
    //FIXME: TESTING CODE
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


/** 
 * @brief  
 * @note   
 * @retval 
 */
// uint8_t* Can::getMail(void)
// {

// }


/** 
 * @brief  
 * @note   
 * @retval 
 */
// uint8_t* Can::getInboxUnitek(void)
// {
//     return inboxUnitek;
// }


/** 
 * @brief  
 * @note   
 * @retval true/false based on if there's anything 
 */
bool Can::checkInboxUnitek(void)
{
    return false;//!inboxUnitek->isEmpty();
}