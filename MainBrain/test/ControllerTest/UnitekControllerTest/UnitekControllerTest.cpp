/**  Operates the logic around controlling the Unitek motor controller
 *
 * UnitekControllerTest.cpp
 * Created 12-23-17  By: Smitty
 *
 * A longer description.
 */

#include "UnitekControllerTest.hpp"


UnitekControllerTest::UnitekControllerTest(void)
{
    
}


/** 
 * @brief  Convert RPM to a compatible MC speed value
 * @note   The speed value represents a percentage from 0 to 0x7FFF
 *         That percentage represents the RPM from 0 to RPM_LIMIT (Ex: 7000)
 * @param  rpm: RPM value
 * @retval      Speed value for the MC
 */
void UnitekControllerTest::calculateSpeedValue(void)
{
    // float percentage = rpm / unitekModel->getRpmLimit();
    // return percentage * unitekModel->MAX_VALUE;
}


/** 
 * @brief  Convert a given MC speed value to RPM
 * @note   
 * @param  speedValue: Given from MC
 * @retval             RPM value
 */
void UnitekControllerTest::calculateRpm(void)
{
    // float percentage = (float)speedValue / unitekModel->MAX_VALUE;
    // return percentage * unitekModel->getRpmLimit();
}
