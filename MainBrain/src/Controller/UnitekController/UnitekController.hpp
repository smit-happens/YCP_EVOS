/**  Operates the logic around controlling the Unitek motor controller
 *
 * #include "UnitekController.hpp"
 * Created 12-23-17  By: Smitty
 *
 * A longer description.
 */


#ifndef UNITEKCONTROLLER_HPP
#define UNITEKCONTROLLER_HPP

#include "../BaseController/BaseController.hpp"
#include "../../Model/Unitek/Unitek.hpp"


class UnitekController : public BaseController
{
public:
    UnitekController(void);
    ~UnitekController(void);

    void init(void);
    void poll(void);
    void display(void);     //TODO: implement
    void shutdown(void);    //TODO: implement

    int calculateSpeedValue(float rpm);
    float calculateRpm(int speedValue);

private:
    Unitek* unitek;
};


#endif  //UNITEKCONTROLLER_HPP
