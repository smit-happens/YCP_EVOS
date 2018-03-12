/**  Represents the Model of a CAN message
 *
 * CanTest.cpp
 * Created 3-12-18  By: Smitty
 *
 * A longer description.
 */

#include "CanTest.hpp"

/** 
 * @brief  CanTest constructor
 */
CanTest::CanTest(void)
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
 * @brief  CanTest destructor
 */
CanTest::~CanTest(void)
{
    // delete mailbox;
    // delete inboxUnitek;
    // delete inboxOrion;
}


/** 
 * @brief  
 * @note   TODO: fill this out (if necessary)
 * @retval None
 */
void CanTest::update(void)
{
    
}



/** 
 * @brief  Called whenever a new CAN frame is received
 * @note   All CAN messages will be sent received from mailbox 1 (CAN port 1) 
 * @param  &frame:  CAN_message_t reference
 * @param  mailbox: Port message came on
 * @retval None
 */
void CanTest::gotFrame(CAN_message_t &frame, int mailbox)
{
    //TODO: message just came in, check ID and send data to Unitek or Orion
    //check id, store in orion or unitek queue, (maybe) set queueHasDataFlag
    //globalEventFlags = 0;
    //FIXME: TESTING CODE
    // Serial.println("Entered CAN interrupt");
    // Serial.println(frame.buf[0]);
    // Serial.println(frame.buf[1]);
    // Serial.println(frame.buf[2]);
    // Serial.println(frame.buf[3]);
    //FIXME: TESTING CODE
}


/** 
 * @brief  Sends a CAN message out on the wire
 * @note   
 * @retval None
 */
void CanTest::send(CAN_message_t message)
{
    Can1.write(message);
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
// uint8_t* CanTest::getMail(void)
// {

// }


/** 
 * @brief  
 * @note   
 * @retval 
 */
// uint8_t* CanTest::getInboxUnitek(void)
// {
//     return inboxUnitek;
// }


/** 
 * @brief  
 * @note   
 * @retval true/false based on if there's anything 
 */
bool CanTest::checkInboxUnitek(void)
{
    return false;//!inboxUnitek->isEmpty();
}