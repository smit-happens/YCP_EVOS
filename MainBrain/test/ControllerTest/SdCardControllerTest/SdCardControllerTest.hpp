/**  Only has knowledge about creating/editing csv files
 *
 * #include "SdCardControllerTest.hpp"
 * Created 10-02-17 By: Smitty
 *
 * A longer description.
 */

#ifndef SDCARDCONTROLLERTEST_HPP
#define SDCARDCONTROLLERTEST_HPP

#include "../BaseControllerTest/BaseControllerTest.hpp"

/**  
 * Example of possible log file:
 * ╔════════════════════════════╦══════════════╦═══════════════╦═════════════════════════════════════════════════════════╦═════╗
 * ║ Millis since program start ║ Category     ║ Calling Class ║ Message                                                 ║ ... ║
 * ╠════════════════════════════╬══════════════╬═══════════════╬═════════════════════════════════════════════════════════╬═════╣
 * ║ 1145                       ║ Notification ║ Unitek        ║ No errors/warnings found                                ║     ║
 * ╠════════════════════════════╬══════════════╬═══════════════╬═════════════════════════════════════════════════════════╬═════╣
 * ║ 1650                       ║ Warning      ║ Orion         ║ Average cell temperature of 45°C close to limit of 60°C ║     ║
 * ╠════════════════════════════╬══════════════╬═══════════════╬═════════════════════════════════════════════════════════╬═════╣
 * ║ 1776                       ║ Error        ║ CoolingSystem ║ Pump is not turned on!                                  ║     ║
 * ╠════════════════════════════╬══════════════╬═══════════════╬═════════════════════════════════════════════════════════╬═════╣
 * ║ ...                        ║ ...          ║ ...           ║ ...                                                     ║     ║
 * ╚════════════════════════════╩══════════════╩═══════════════╩═════════════════════════════════════════════════════════╩═════╝
 */

class SdCardControllerTest  : public BaseControllerTest
{
public:
    SdCardControllerTest(void);

private:
    //private instance of model
    // SdCard* sdCardModel;

};

#endif  //SDCARDCONTROLLERTEST_HPP
