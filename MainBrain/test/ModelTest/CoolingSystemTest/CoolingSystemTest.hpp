/**  A one line description of the class.
 *
 * #include "CoolingSystemTest.hpp"
 * Created 3-12-18  By: Smitty
 *
 * A longer description.
 */

#ifndef COOLINGSYSTEMTEST_HPP
#define COOLINGSYSTEMTEST_HPP

#include "../BaseModelTest/BaseModelTest.hpp"

class CoolingSystemTest : public BaseModelTest
{
public:
    CoolingSystemTest(void);
    ~CoolingSystemTest(void);

    void update(void);

    uint16_t getInletValue(void);
    uint16_t getOutletValue(void);

    //TODO: add functions for operation of pump control

private:
    uint16_t _inletTemperature;
    uint16_t _outletTemperature;
};


#endif  //COOLINGSYSTEMTEST_HPP