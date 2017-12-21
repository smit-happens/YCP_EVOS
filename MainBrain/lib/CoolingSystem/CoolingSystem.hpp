/**  A one line description of the class.
 *
 * #include "CoolingSystem.hpp"
 * Created 12-20-17  By: Smitty
 *
 * A longer description.
 */

#ifndef COOLINGSYSTEM_HPP
#define COOLINGSYSTEM_HPP

#include <Arduino.h>

class CoolingSystem
{
public:
    CoolingSystem(void);

    float getRadiatorTempIn(void);
    float getRadiatorTempOut(void);

private:
    float getRadiatorTempInVal(void);
    float getRadiatorTempOutVal(void);
};


#endif  //COOLINGSYSTEM_HPP