/**  A one line description of the class.
 *
 * #include "OrionTest.hpp"
 * Created 10-24-17  By: Smitty
 *
 * A longer description.
 */

#ifndef ORIONTEST_HPP
#define ORIONTEST_HPP

#include "../BaseModelTest/BaseModelTest.hpp"
#include "../../../src/Model/Constants/RegistersOrion.hpp"

class OrionTest : public BaseModelTest
{
public:
    OrionTest(void);
    ~OrionTest(void);

    void update(void);

    float getVoltageTotal(void);
    float getVoltageAverage(void);
    float getVoltageVariance(void);
    float getVoltageMin(void);
    float getVoltageMax(void);
    
    float getAmperageTotal(void);

    int getVoltageMinCell(void);
    int getVoltageMaxCell(void);

    float getTemperature(void);
};


#endif  //ORIONTEST_HPP
