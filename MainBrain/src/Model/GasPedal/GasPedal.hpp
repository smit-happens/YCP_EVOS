/**  A one line description of the class.
 *
 * #include "GasPedal.hpp"
 * Created 11-09-17 By: Smitty
 *
 * A longer description.
 */

#ifndef GASPEDAL_HPP
#define GASPEDAL_HPP

#include <Arduino.h>

//Maybe have states the pedal can be in, since it has the chance
//of causing an error if there's an implausibility or a short in
//the wires

class GasPedal
{
public:
    GasPedal();

    float getPercentage(void);
    bool isImplausibility(void);

private:
    float getLogValue(void);
    float getLinValue(void);
};

#endif  //GASPEDAL_HPP
