/**  Handles the logic around setting up and sending CAN messages
 *
 * #include "CanController.hpp"
 * Created 1-4-18  By: Smitty
 *
 * A longer description.
 */


#ifndef CANCONTROLLER_HPP
#define CANCONTROLLER_HPP

#include "../../Model/Can/Can.hpp"

//Might need additional methods to flesh out all the functionality

class CanController
{
public:
    CanController(void);

    //TODO: figure out the input/return parameters
    int messageSetup(uint8_t regID, uint8_t buf1, uint8_t buf2);
    int messageParse(void);
    int messageSend(void);

};


#endif  //CANCONTROLLER_HPP
