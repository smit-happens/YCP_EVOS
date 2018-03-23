/**  Handles the logic around setting up and sending CAN messages
 *
 * #include "CanControllerTest.hpp"
 * Created 1-4-18  By: Smitty
 *
 * A longer description.
 */


#ifndef CANCONTROLLERTEST_HPP
#define CANCONTROLLERTEST_HPP

#include "../BaseControllerTest/BaseControllerTest.hpp"



class CanControllerTest : public BaseControllerTest
{
public:
    CanControllerTest();

    //Format and pass the CAN message to the CAN model to put out on the wire
    void sendUnitekRead(uint8_t regId, uint8_t pollTime);   //send a register read message
    void sendUnitekWrite(uint8_t regID, uint8_t buf1, uint8_t buf2);    //send a register write message

    void sendOrion(void);    //TODO: implement this based on testing done with Micaiah

    void parse(void);
   
};


#endif  //CANCONTROLLERTEST_HPP
