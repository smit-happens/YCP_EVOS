/**  Trying out Platformio unit testing structure
 *
 * GasPedalTest.cpp
 * Created 3-11-18 By: Smitty
 *
 * In order to use unit testing functionality one needs to sign up for a basic platformio account
 * http://platformio.org/pricing students/teachers pay 4$ per month, not a bad idea to consider
 * if only for the semester
 */

#include <Arduino.h>
#include "../../src/Model/Model.hpp"
#include <unity.h>

#ifdef UNIT_TEST

// void setUp(void) 
// {
//     // set stuff up here
// }

// void tearDown(void) 
// {
//     // clean stuff up here
// }   

void test_setOrigin(void) 
{
    int linearVal = analogRead(MB_GAS_LIN);
    int logVal = analogRead(MB_GAS_LOG);

    GasPedal pedal;

    pedal.setOrigin();

    TEST_ASSERT_EQUAL(pedal.getLinValue(), linearVal);
    TEST_ASSERT_EQUAL(pedal.getLogValue(), logVal);
}


// void test_led_state_high(void) 
// {
//     digitalWrite(LED_BUILTIN, HIGH);
//     TEST_ASSERT_EQUAL(digitalRead(LED_BUILTIN), HIGH);
// }

// void test_led_state_low(void) 
// {
//     digitalWrite(LED_BUILTIN, LOW);
//     TEST_ASSERT_EQUAL(digitalRead(LED_BUILTIN), LOW);
// }


int main(void) 
{
    // NOTE!!! Wait for >2 secs
    // if board doesn't support software reset via Serial.DTR/RTS
    delay(2000);

    analogReadResolution(13);

    UNITY_BEGIN();    // IMPORTANT LINE!


    RUN_TEST(test_setOrigin);


    UNITY_END(); // stop unit testing

    return 0;
}


#endif
