/**  Trying out Platformio unit testing structure
 *
 * mainTest.cpp
 * Created 3-11-18 By: Smitty
 *
 * In order to use unit testing functionality one needs to sign up for a basic platformio account
 * http://platformio.org/pricing students/teachers pay 4$ per month, not a bad idea to consider
 * if only for the semester
 */


#ifdef UNIT_TEST

// #include "ModelTest/ModelTest.hpp"

#include "ModelTest/GasPedalTest/GasPedalTest.hpp"

int main() {
    // NOTE!!! Wait for >2 secs
    // if board doesn't support software reset via Serial.DTR/RTS
    delay(2000);

    analogReadResolution(13);

    GasPedalTest* testGas = new GasPedalTest();

    UNITY_BEGIN();
    
    RUN_TEST(testGas->setOriginTest);

    UNITY_END();

    return 0;
}


#endif
