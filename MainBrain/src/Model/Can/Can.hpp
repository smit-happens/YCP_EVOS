/**  Represents the Model of a CAN message
 *
 * #include "Can.hpp"
 * Created 09-30-17  By: Smitty
 *
 * A longer description.
 */

#ifndef CAN_HPP
#define CAN_HPP

#include <FlexCAN.h>
#include "../Queue/Queue.hpp"
#include "../BaseModel/BaseModel.hpp"
#include "../Constants/Flags.hpp"


class Can : public CANListener, public BaseModel
{
public:
    const uint32_t UNITEKREADID = 0x181;
    const uint32_t UNITEKSENDID = 0x201;

    const uint32_t ORIONID1 = 0x420;
    const uint32_t ORIONID2 = 0x421;

    Queue* localMailbox;

    Can(void);
    ~Can(void);
    

    //overrides the parent version
    void gotFrame(CAN_message_t &frame, int mailbox);

    //Send the CAN message on the Wire
    void send(CAN_message_t message);

    void storeMail(void);

    bool checkMailVolatile(void);

private:
    //CAN port the Teensy will be using
    const int canMailbox = 1;

    //queue variables that will be used for the Unitek and Orion devices
    Queue* volatileMailbox;
};


#endif  //CAN_HPP
