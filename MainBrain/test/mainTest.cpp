/**  Trying out Platformio unit testing structure
 *
 * mainTest.cpp
 * Created 3-11-18 By: Smitty
 *
 * In order to use unit testing functionality one needs to sign up for a basic platformio account
 * http://platformio.org/pricing students/teachers pay 4$ per month, not a bad idea to consider
 * if only for the semester
 */


#include "../src/Model/Model.hpp"
#include <unity.h>

#ifdef UNIT_TEST

/** 
 * @brief  Tests port constants file. Intended to alert the team of unintentionally changed port constants
 * @note   Do not edit this test to make tests pass when port constants file is changed...
 * @retval None
 */
void test_port_constants(void) {

    // Safety Subsystems
    TEST_ASSERT_EQUAL(MB_IMD_STATUS, 28);
    TEST_ASSERT_EQUAL(MB_BMS_STATUS, 29);

    // I2C
    TEST_ASSERT_EQUAL(MB_I2C_SCL, 57);
    TEST_ASSERT_EQUAL(MB_I2C_SDA, 56);

    // SPI
    TEST_ASSERT_EQUAL(MB_SPI_CS1, 43);
    TEST_ASSERT_EQUAL(MB_SPI_CS0, 54);
    TEST_ASSERT_EQUAL(MB_SPI_SCK, 53);
    TEST_ASSERT_EQUAL(MB_SPI_MOSI, 52);
    TEST_ASSERT_EQUAL(MB_SPI_MISO, 51);

    // Pedals
    TEST_ASSERT_EQUAL(MB_BRAKE_OVERTRAVEL, 13);
    TEST_ASSERT_EQUAL(MB_BRAKE_LIGHT, 37);
    TEST_ASSERT_EQUAL(MB_BRAKE, 16);
    TEST_ASSERT_EQUAL(MB_GAS_LIN, 15);
    TEST_ASSERT_EQUAL(MB_GAS_LOG, 14);

    // TSCB / Motor controller logic
    TEST_ASSERT_EQUAL(MB_SCADA_OK, 23);
    TEST_ASSERT_EQUAL(MB_DRIVE_EN, 22);
    TEST_ASSERT_EQUAL(MB_START_PRE, 21);
    TEST_ASSERT_EQUAL(MB_DONE_PRE, 20);
    TEST_ASSERT_EQUAL(MB_DOUT2, 19);
    TEST_ASSERT_EQUAL(MB_BTB, 18);
    TEST_ASSERT_EQUAL(MB_SPARE, 17);

    // GLCD
    TEST_ASSERT_EQUAL(MB_SID, 8);
    TEST_ASSERT_EQUAL(MB_SCLK, 9);
    TEST_ASSERT_EQUAL(MB_A0, 10);
    TEST_ASSERT_EQUAL(MB_RST, 11);
    TEST_ASSERT_EQUAL(MB_CS, 12);
    TEST_ASSERT_EQUAL(MB_R, 7);
    TEST_ASSERT_EQUAL(MB_G, 6);
    TEST_ASSERT_EQUAL(MB_B, 4);

    // Dashboard
    TEST_ASSERT_EQUAL(MB_PRE_BTN, 47);
    TEST_ASSERT_EQUAL(MB_RTD_BTN, 45);
    TEST_ASSERT_EQUAL(MB_ENC_BTN, 27);
    TEST_ASSERT_EQUAL(MB_WAYNE_BTN, 32);
    TEST_ASSERT_EQUAL(MB_SHUTDOWN_BTN, 44);
    TEST_ASSERT_EQUAL(MB_STANDBY_BTN, 46);
    TEST_ASSERT_EQUAL(MB_REVERSE_SW, 41);
    TEST_ASSERT_EQUAL(MB_ENC_PINA, 26);
    TEST_ASSERT_EQUAL(MB_ENC_PINB, 25);
    TEST_ASSERT_EQUAL(MB_RTD_LED, 0);
    TEST_ASSERT_EQUAL(MB_BMS_LED, 1);
    TEST_ASSERT_EQUAL(MB_PEDAL_LED, 2);
    TEST_ASSERT_EQUAL(MB_IMD_LED, 3);
    TEST_ASSERT_EQUAL(MB_REVERSE_LED, 5);
    TEST_ASSERT_EQUAL(MB_WAYNE_LED, 24);
    TEST_ASSERT_EQUAL(MB_ENERGIZE_LED, 31);
    TEST_ASSERT_EQUAL(MB_SIREN, 30);

    // CAN
    TEST_ASSERT_EQUAL(MB_CAN_TX, 33);
    TEST_ASSERT_EQUAL(MB_CAN_RX, 34);

    // Cooling
    TEST_ASSERT_EQUAL(MB_PUMP_CTRL, 48);
    TEST_ASSERT_EQUAL(MB_RAD_INLET_TEMP, A16);
    TEST_ASSERT_EQUAL(MB_RAD_OUTLET_TEMP, A17);

    // Batlog
    TEST_ASSERT_EQUAL(MB_BAT_MEASURE, A24);

}
int main() {
    // NOTE!!! Wait for >2 secs if board doesn't support software reset via Serial.DTR/RTS
    delay(2000);
   
    UNITY_BEGIN();
    
    RUN_TEST(test_port_constants);

    UNITY_END();

    return 0;
}


#endif
