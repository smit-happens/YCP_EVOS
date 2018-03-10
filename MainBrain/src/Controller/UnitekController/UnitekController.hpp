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
    ~UnitekController(void);

    static UnitekController*   getInstance();

    void init(void);
    void poll(void);
    void shutdown(void);    //TODO: implement

    int calculateSpeedValue(float rpm);
    float calculateRpm(int speedValue);
    uint16_t calculateSpeedSetPoint(float percent);

private:
    //Private contstructor so that it can't be called
    UnitekController() {};
    //copy constructor is private
    UnitekController(UnitekController const&) {};

    //static instance pointer
    static UnitekController* _pInstance;

    //private instance of model
    Unitek* unitekModel;
};


#endif  //UNITEKCONTROLLER_HPP
