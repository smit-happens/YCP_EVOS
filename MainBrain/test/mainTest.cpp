/**  Trying out Platformio unit testing structure
 *
 * mainTest.cpp
 * Created 3-11-18 By: Smitty
 *
 * In order to use unit testing functionality one needs to sign up for a basic platformio account
 * http://platformio.org/pricing students/teachers pay 4$ per month, not a bad idea to consider
 * if only for the semester
 */

// #include "../src/Model/Model.hpp"
// #include <IntervalTimer.h>
// #include "Manager/StageManager/StageManager.hpp"
#include <Arduino.h>
#include <unity.h>
 
#ifdef UNIT_TEST

int main() {
    // NOTE!!! Wait for >2 secs if board doesn't support software reset via Serial.DTR/RTS
    delay(2000);
   
    UNITY_BEGIN();
    
    // tests here :)

    UNITY_END();

    return 0;
}

#endif
