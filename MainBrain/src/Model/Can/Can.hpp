/**  Represents the Model of a CAN message
 *
 * #include "Can.hpp"
 * Created 09-30-17  By: Smitty
 *
 * A longer description.
 */

#ifndef CAN_HPP
#define CAN_HPP

#include <Arduino.h>
#include <FlexCAN.h>



class Can : public CANListener
{
public:
    const int UNITEKREADID = 0x181;
    const int UNITEKSENDID = 0x201;

    // const int ORIONREADID = 0x840;   //Micaiah - "i think it's the same"
    const int ORIONSENDID = 0x840;

    Can();

    //overrides the parent version
    void gotFrame(CAN_message_t &frame, int mailbox);

    //Send the CAN message on the Wire
    void send(CAN_message_t message);

private:
    //CAN port the Teensy will be using
    const int canMailbox = 1;
};


#endif  //CAN_HPP
