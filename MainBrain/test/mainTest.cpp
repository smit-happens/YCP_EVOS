/**  Trying out Platformio unit testing structure
 *
 * mainTest.cpp
 * Created 3-11-18 By: Smitty
 *
 * In order to use unit testing functionality one needs to sign up for a basic platformio account
 * http://platformio.org/pricing students/teachers pay 4$ per month, not a bad idea to consider
 * if only for the semester
 */

#include <Arduino.h>
#include <unity.h>

#include "ModelTest/GasPedalTest/GasPedalTest.hpp"

#ifdef UNIT_TEST


int main() {
    // NOTE!!! Wait for >2 secs
    // if board doesn't support software reset via Serial.DTR/RTS
    delay(2000);

    analogReadResolution(13);

    GasPedalTest testGas;

    UNITY_BEGIN();
    
    RUN_TEST(testGas.setOrigin);

    UNITY_END();

    return 0;
}


#endif
