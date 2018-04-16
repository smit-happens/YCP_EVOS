/**  Operates the logic around controlling the Unitek motor controller
 *
 * UnitekControllerTest.cpp
 * Created 12-23-17  By: Smitty
 *
 * A longer description.
 */

#include "UnitekControllerTest.hpp"


void test_Unitek_Some_Functionality(void) {
    TEST_ASSERT_EQUAL(1, 1);
}

/** 
 * @brief  Main Function for this test class.
 * @note   
 * @retval Always returns 0
 */
int UnitekControllerTest(){
    // NOTE!!! Wait for >2 secs if board doesn't support software reset via Serial.DTR/RTS
    delay(2000);
    UNITY_BEGIN();

    RUN_TEST(test_Unitek_Some_Functionality);

    UNITY_END();

    return 0;
}

// UnitekControllerTest :: UnitekControllerTest(void) {
//     // necessary delay
//     delay(2000);

// }