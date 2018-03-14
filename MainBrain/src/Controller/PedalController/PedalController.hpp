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

//Error if there's an implausibility or a short in the wires
class PedalController : public BaseController
{
public:
    ~PedalController(void);

    static PedalController*   getInstance();

    void init(void);
    void poll(void);
    void shutdown(void);    //TODO: implement

    float getPercentageGas(void);
    bool isImplausibilityGas(void);

    float getPercentageBrake(void);
    bool isImplausibilityBrake(void);

private:
    //Private contstructor so that it can't be called
    PedalController() {};
    //copy constructor is private
    PedalController(PedalController const&) {};


    //Only the Pedal Controller cares about the origin of the pedals
    float gasOrigin;
    int brakeOrigin;

    //static instance pointer
    static PedalController* _pInstance;

    //private instance of models
    BrakePedal* brakeModel;
    GasPedal* gasModel;



};


#endif  //PEDALCONTROLLER_HPP
