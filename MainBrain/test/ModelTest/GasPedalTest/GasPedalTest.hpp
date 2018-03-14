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
        int PedalVal = analogRead(MB_GAS_LIN);

        GasPedal pedal;

        pedal.setRawOrigin();

        TEST_ASSERT_INT_WITHIN(100, pedal.getRawOrigin(), PedalVal);
    };
};
