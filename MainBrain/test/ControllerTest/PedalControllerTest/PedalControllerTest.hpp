/**  Pedal controller class
 *
 * #include "PedalControllerTest.hpp"
 * Created 1-17-17 By: Smitty
 *
 * A longer description.
 */

#ifndef PEDALCONTROLLER_HPP
#define PEDALCONTROLLER_HPP

#include "../BaseControllerTest/BaseControllerTest.hpp"
#include "../../Model/BrakePedal/BrakePedal.hpp"
#include "../../Model/GasPedal/GasPedal.hpp"

//Error if there's an implausibility or a short in the wires
class PedalControllerTest : public BaseControllerTest
{
public:
    ~PedalControllerTest(void);

    static PedalControllerTest*   getInstance();

    void init(void);
    void poll(void);
    void shutdown(void);    //TODO: implement

    float getPercentageGas(void);
    bool isImplausibilityGas(void);

    float getPercentageBrake(void);
    bool isImplausibilityBrake(void);

private:
    //Private contstructor so that it can't be called
    PedalControllerTest() {};
    //copy constructor is private
    PedalControllerTest(PedalControllerTest const&) {};

    //static instance pointer
    static PedalControllerTest* _pInstance;

    //private instance of models
    BrakePedal* brakeModel;
    GasPedal* gasModel;

};


#endif  //PEDALCONTROLLER_HPP
