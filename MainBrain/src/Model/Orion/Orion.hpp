/**  A one line description of the class.
 *
 * #include "Orion.hpp"
 * Created 10-24-17  By: Smitty
 *
 * A longer description.
 */

#ifndef ORION_HPP
#define ORION_HPP

#include <Arduino.h>
#include "OrionRegisters.hpp"

class Orion
{
public:
    Orion(void);

    float getVoltageTotal(void);
    float getVoltageAverage(void);
    float getVoltageVariance(void);
    float getVoltageMin(void);
    float getVoltageMax(void);
    
    float getAmperageTotal(void);

    float getTemperature(void);

    int parseCan(void);

};


#endif  //ORION_HPP