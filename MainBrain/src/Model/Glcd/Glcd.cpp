/**  Display model class
 *
 * Glcd.cpp
 * Created 10-01-17 By: Smitty
 *
 * A longer description.
 */

#include "Glcd.hpp"


/** 
 * @brief  Glcd constructor
 */
Glcd::Glcd(void)
{
    display = new ST7565(MB_SID, MB_SCLK, MB_A0, MB_RST, MB_CS);
    
    // initialize the glcd and set the contrast to 0x18
    display->begin(0x18);
    display->clear();
}



/** 
 * @brief  Glcd destructor
 */
Glcd::~Glcd(void)
{
    delete display;
}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void Glcd::update(void)
{

}


/** 
 * @brief  displays image of "Just Barely" on the screen
 * @note   
 * @retval None
 */
void Glcd::showBootLogo(void)
{
    // draw the bitmap
    display->clear();
    display->drawbitmap(0, 0, JustBarelyLogo, 128, 64, BLACK);
    display->display();
}