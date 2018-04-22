/**  Handles the hardware level functions of the SdFat library
 *
 * SdCardTest.cpp
 * Created 10-24-17  By: Smitty
 *
 * A longer description.
 */

#include "SdCardTest.hpp"

//FIXME: rip out all the demo code and put into functions

/** 
 * @brief  SdCardTest constructor
 */
SdCardTest::SdCardTest(void)
{
    storageCard = new SdFatSdioEX();
}
