/**  Cooling controller class
 *
 * #include "CoolingControllerTest.hpp"
 * Created 1-17-17 By: Smitty
 *
 * A longer description.
 */

#ifndef COOLINGCONTROLLERTEST_HPP
#define COOLINGCONTROLLERTEST_HPP

#include "../BaseControllerTest/BaseControllerTest.hpp"


class CoolingControllerTest : public BaseControllerTest
{
public:
    CoolingControllerTest();

    //TODO: test these
    float getRadiatorTempIn(void);
    float getRadiatorTempOut(void);
    
private:

    //private instance of model
    // CoolingSystem* coolingModel;
};


#endif  //COOLINGCONTROLLERTEST_HPP
