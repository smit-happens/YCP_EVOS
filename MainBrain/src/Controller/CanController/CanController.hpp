/**  Handles the logic around setting up and sending CAN messages
 *
 * #include "CanController.hpp"
 * Created 1-4-18  By: Smitty
 *
 * A longer description.
 */


#ifndef CANCONTROLLER_HPP
#define CANCONTROLLER_HPP

#include "../BaseController/BaseController.hpp"
#include "../../Model/Can/Can.hpp"
#include "../../Model/Constants/RegistersOrion.hpp"
#include "../../Model/Constants/RegistersUnitek.hpp"


class CanController : public BaseController
{
public:
    ~CanController(void);

    static CanController*   getInstance();

    void init(void);
    void poll(void);

    // void display(void);

    //TODO: implement the process mail function for sorting and striping the CAN id out of messages
    //void processMail();

    //Format and pass the CAN message to the CAN model to put out on the wire
    void sendUnitekRead(uint8_t regId, uint8_t pollTime);   //send a register read message
    void sendUnitekWrite(uint8_t regID, uint8_t buf1, uint8_t buf2);    //send a register write message

    void sendOrion(void);    //TODO: implement this based on testing done with Micaiah

    void parse(void);

private:
    //Private contstructor so that it can't be called
    CanController() {};
    //copy constructor is private
    CanController(CanController const&) {};

    //static instance pointer
    static CanController* _pInstance;

    //private instance of model
    Can* canModel;
    
};


#endif  //CANCONTROLLER_HPP
