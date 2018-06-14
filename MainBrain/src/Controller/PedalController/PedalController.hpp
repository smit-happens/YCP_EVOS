/**  Pedal controller class
 *
 * #include "PedalController.hpp"
 * Created 1-17-17 By: Smitty
 *
 * A longer description.
 */

#ifndef PEDALCONTROLLER_HPP
#define PEDALCONTROLLER_HPP

#include "../BaseController/BaseController.hpp"
#include "../../Model/BrakePedal/BrakePedal.hpp"
#include "../../Model/GasPedal/GasPedal.hpp"
#include "../LightController/LightController.hpp"
#include "../../Model/Queue/IntQueue.hpp"

class PedalController : public BaseController
{
public:
    ~PedalController(void);

    static PedalController*   getInstance();

    void init(void);
    void poll(void);

    float getPercentageGas(void);
    uint getRawGas(void);
    bool isImplausibilityGas(void);

    float getPercentageBrake(void);
    bool isImplausibilityBrake(void);

    void CheckBrakeLight(void);

private:
    //Private contstructor so that it can't be called
    PedalController() {};
    //copy constructor is private
    PedalController(PedalController const&) {};

    //static instance pointer
    static PedalController* _pInstance;

    //private instance of models
    BrakePedal* brakeModel;
    GasPedal* gasModel;

    IntQueue* gasBuffer;

};


#endif  //PEDALCONTROLLER_HPP
