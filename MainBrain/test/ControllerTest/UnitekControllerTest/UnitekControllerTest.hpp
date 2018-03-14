/**  Operates the logic around controlling the Unitek motor controller
 *
 * #include "UnitekControllerTest.hpp"
 * Created 12-23-17  By: Smitty
 *
 * A longer description.
 */


#ifndef UNITEKCONTROLLERTEST_HPP
#define UNITEKCONTROLLERTEST_HPP

#include "../BaseControllerTest/BaseControllerTest.hpp"


class UnitekControllerTest : public BaseControllerTest
{
public:
    UnitekControllerTest(void);

    void calculateSpeedValue(void);
    void calculateRpm(void);

private:
    //private instance of model
    // Unitek* unitekModel;
};


#endif  //UNITEKCONTROLLERTEST_HPP
