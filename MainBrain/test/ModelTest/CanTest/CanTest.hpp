/**  Represents the Model of a CAN message
 *
 * #include "CanTest.hpp"
 * Created 3-12-18  By: Smitty
 *
 * A longer description.
 */

#ifndef CANTEST_HPP
#define CANTEST_HPP

#include <FlexCAN.h>
// #include <cppQueue.h>

#include "../BaseModelTest/BaseModelTest.hpp"


class CanTest : public CANListener, public BaseModelTest
{
public:
    CanTest(void);
    ~CanTest(void);

    void update(void);

    //overrides the parent version
    void gotFrame(CAN_message_t &frame, int mailbox);

    //Send the CAN message on the Wire
    void send(CAN_message_t message);

    //TODO: implement getMail function that will return a list (of some data type) for the
    //controller to sort through
    uint8_t* getMail(void);

    //get/set functions that will handle the storage of the data for each of the CAN devices
    uint8_t* getInboxUnitek(void);
    void setInboxUnitek(uint8_t* canData[]);

    //getInboxOrion();
    //setInboxOrion();


    //function that UnitekC/OrionC will call in order to see if there exists any new messages for it
    bool checkInboxUnitek(void);
    bool checkInboxOrion(void);

private:
    //CAN port the Teensy will be using
    const int canMailbox = 1;
};


#endif  //CANTEST_HPP
