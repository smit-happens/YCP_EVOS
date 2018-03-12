/**  Unit tests for the GasPedal model class
 *
 * GasPedalTest.cpp
 * Created 3-11-18 By: Smitty
 *
 */

#include "GasPedalTest.hpp"



/** 
 * @brief  GasPedal constructor
 */
GasPedalTest::GasPedalTest(void)
{

}


/** 
 * @brief  unit test for setOrigin
 * @note   
 * @retval None
 */
void GasPedalTest::setOrigin(void) 
{
    int linearVal = analogRead(MB_GAS_LIN);
    int logVal = analogRead(MB_GAS_LOG);

    GasPedal pedal;

    pedal.setOrigin();

    TEST_ASSERT_EQUAL(pedal.getLinValue(), linearVal);
    TEST_ASSERT_EQUAL(pedal.getLogValue(), logVal);
}
