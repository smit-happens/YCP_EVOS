/**  A one line description of the class.
 *
 * #include "BrakePedal.hpp"
 * Created 12-20-17 By: Smitty
 *
 * A longer description.
 */

#ifndef BRAKEPEDAL_HPP
#define BRAKEPEDAL_HPP

#include <Arduino.h>
#include "../Constants/Port.hpp"

//Maybe have states the pedal can be in, since it has the chance
//of causing an error if there's an implausibility or a short in
//the wires

class BrakePedal
{
public:
    BrakePedal();

    float getPercentage(void);
    bool isImplausibility(void);

private:
    float getLinValue(void);
};

#endif  //BRAKEPEDAL_HPP