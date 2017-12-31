/**  Operates the logic around controlling the Unitek motor controller
 *
 * #include "UnitekController.hpp"
 * Created 12-23-17  By: Smitty
 *
 * A longer description.
 */

#ifndef UNITEKCONTROLLER_HPP
#define UNITEKCONTROLLER_HPP

#include "../../Model/Unitek/Unitek.hpp"


class UnitekController
{
public:
    UnitekController(void);

    int calculateSpeedValue(float rpm);
    float calculateRpm(int speedValue);

    int parseCan(void);

private:
    Unitek unitek;

};


#endif  //UNITEKCONTROLLER_HPP
