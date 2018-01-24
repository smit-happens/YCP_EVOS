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


class CanController : public BaseController
{
public:
    CanController(void);
    ~CanController(void);

    void init(void);
    void poll(void);

    //TODO: figure out the input/return parameters
    int messageSetup(uint8_t regID, uint8_t buf1, uint8_t buf2);
    int messageParse(void);
    int messageSend(void);

private:
    Can* canModel;
};


#endif  //CANCONTROLLER_HPP
