/**  Pedal controller class
 *
 * #include "PedalControllerTest.hpp"
 * Created 1-17-17 By: Smitty
 *
 * A longer description.
 */

#ifndef PEDALCONTROLLERTEST_HPP
#define PEDALCONTROLLERTEST_HPP

#include "../BaseControllerTest/BaseControllerTest.hpp"

//Error if there's an implausibility or a short in the wires
class PedalControllerTest : public BaseControllerTest
{
public:
    PedalControllerTest(void);

    float getPercentageGas(void);
    bool isImplausibilityGas(void);

    float getPercentageBrake(void);
    bool isImplausibilityBrake(void);

private:
    //private instance of models
    // BrakePedal* brakeModel;
    // GasPedal* gasModel;

};


#endif  //PEDALCONTROLLERTEST_HPP
