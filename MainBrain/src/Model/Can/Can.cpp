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
    volatileMailbox = new Queue();
    localMailbox = new Queue();
}


/** 
 * @brief  Can destructor
 */
Can::~Can(void)
{
    delete volatileMailbox;
    delete localMailbox;
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
    //TODO: message just came in, store it and set EF/TF 

    volatileMailbox->enqueue(frame);

    //FIXME: TESTING CODE
    // Serial.println("Entered CAN interrupt");
    // Serial.println(frame.id, HEX);
    // Serial.println(frame.buf[0], HEX);
    // Serial.println(frame.buf[1], HEX);
    // Serial.println(frame.buf[2], HEX);
    // Serial.println(frame.buf[3], HEX);
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


void Can::storeMail(void)
{
    while(!volatileMailbox->isEmpty())
    {
        localMailbox->enqueue(volatileMailbox->dequeue()); 
    }
}


/** 
 * @brief  
 * @note   
 * @retval true/false based on if there's anything in the "inbox"
 */
bool Can::checkMailVolatile(void)
{
    return !volatileMailbox->isEmpty();
}