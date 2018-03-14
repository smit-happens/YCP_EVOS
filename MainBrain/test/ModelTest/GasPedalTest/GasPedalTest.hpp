/**  Unit tests for the GasPedal model class
 *
 * GasPedalTest.cpp
 * Created 3-11-18 By: Smitty
 *
 */



#include "../BaseModelTest/BaseModelTest.hpp"


class GasPedalTest : public BaseModelTest
{
public:
    GasPedalTest() {};
    
    static void setOriginTest(void)
    {
        int linearVal = analogRead(MB_GAS_LIN);
        int logVal = analogRead(MB_GAS_LOG);

        GasPedal pedal;

        pedal.setOrigin();

        TEST_ASSERT_INT_WITHIN(100, pedal.getLinOrigin(), linearVal);
        TEST_ASSERT_INT_WITHIN(100, pedal.getLogOrigin(), logVal);
    };
};
