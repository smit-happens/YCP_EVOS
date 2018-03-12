/**  A one line description of the class.
 *
 * #include "BrakePedalTest.hpp"
 * Created 3-12-18 By: Smitty
 *
 * A longer description.
 */

#ifndef BRAKEPEDALTEST_HPP
#define BRAKEPEDALTEST_HPP

#include "../BaseModelTest/BaseModelTest.hpp"

//Maybe have states the pedal can be in, since it has the chance
//of causing an error if there's an implausibility or a short in
//the wires

class BrakePedalTest : public BaseModelTest
{
public:
    BrakePedalTest();
    ~BrakePedalTest(void);

    void update(void);

    uint16_t getLinValue(void);

private:
    uint16_t _linValue;
};

#endif  //BRAKEPEDALTEST_HPP