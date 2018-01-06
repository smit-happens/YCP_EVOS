/**  Display model class
 *
 * Glcd.cpp
 * Created 10-01-17 By: Smitty
 *
 * A longer description.
 */

#include "Glcd.hpp"


ST7565 display(SID, SCLK, RS, _RST, _CS);


/** 
 * @brief  Glcd constructor
 */
Glcd::Glcd(void)
{
    // initialize the glcd and set the contrast to 0x18
    display.begin(0x18);
    display.clear();

    // draw the bitmap
    // glcd.drawbitmap(0, 0, JustBarelyLogo, 128, 64, BLACK);
    // glcd.display();
}
