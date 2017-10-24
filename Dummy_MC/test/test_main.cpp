/**  Trying out Platformio unit testing structure
 *
 * test_main.cpp
 * Created 10-24-17 By: Smitty
 *
 * In order to use unit testing functionality one needs to sign up for a basic platformio account
 * http://platformio.org/pricing students/teachers pay 3$ per month, not a bad idea to consider
 * if only for the semester
 */

// #include <Arduino.h>
// #include <unity.h>
//
// #ifdef UNIT_TEST

// void setUp(void) {
// // set stuff up here
// }

// void tearDown(void) {
// // clean stuff up here
// }

// void test_led_builtin_pin_number(void) {
//     TEST_ASSERT_EQUAL(LED_BUILTIN, 13);
// }
//
// void test_led_state_high(void) {
//     digitalWrite(LED_BUILTIN, HIGH);
//     TEST_ASSERT_EQUAL(digitalRead(LED_BUILTIN), HIGH);
// }
//
// void test_led_state_low(void) {
//     digitalWrite(LED_BUILTIN, LOW);
//     TEST_ASSERT_EQUAL(digitalRead(LED_BUILTIN), LOW);
// }
//
// int main() {
//   // NOTE!!! Wait for >2 secs
//   // if board doesn't support software reset via Serial.DTR/RTS
//   delay(2000);
//
//   UNITY_BEGIN();    // IMPORTANT LINE!
//   RUN_TEST(test_led_builtin_pin_number);
//
//   pinMode(LED_BUILTIN, OUTPUT);
//
//   uint8_t i = 0;
//   uint8_t max_blinks = 5;
//
//   while(1) {
//     if (i < max_blinks)
//     {
//       RUN_TEST(test_led_state_high);
//       delay(500);
//       RUN_TEST(test_led_state_low);
//       delay(500);
//       i++;
//     }
//     else if (i == max_blinks) {
//       UNITY_END(); // stop unit testing
//     }
//   }
//
//   return 0;
// }
//
//
// #endif
