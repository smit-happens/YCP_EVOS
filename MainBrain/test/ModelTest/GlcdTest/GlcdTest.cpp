/**  Display model class
 *
 * GlcdTest.cpp
 * Created 3-12-18 By: Smitty
 *
 * A longer description.
 */

#include "GlcdTest.hpp"


/** 
 * @brief  GlcdTest constructor
 */
GlcdTest::GlcdTest(void)
{
    display = new ST7565(MB_SID, MB_SCLK, MB_A0, MB_RST, MB_CS);
    
    // initialize the glcd and set the contrast to 0x18
    display->begin(0x18);
    display->clear();

    // draw the bitmap
    // glcd.drawbitmap(0, 0, JustBarelyLogo, 128, 64, BLACK);
    // glcd.display();
}


/** 
 * @brief  GlcdTest destructor
 */
GlcdTest::~GlcdTest(void)
{
    delete display;
}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void GlcdTest::update(void)
{

}