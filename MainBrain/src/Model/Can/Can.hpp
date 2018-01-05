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

const int UNITEKREADID = 0x181;
const int UNITEKSENDID = 0x201;

// const int ORIONREADID = 0x181;   //not decided yet
const int ORIONSENDID = 0x840;

class Can : public CANListener
{
public:
    Can();

    void printFrame(CAN_message_t &frame, int mailbox);

    //overrides the parent version
    void gotFrame(CAN_message_t &frame, int mailbox);

    // Unitek/Orion functions should later be combined but for right now this is easier (I hope)
    void sendUnitek(void);
    void readUnitek(CAN_message_t &frame);

    void sendOrion(void);
    void readOrion(CAN_message_t &frame);
};


#endif  //CAN_HPP
