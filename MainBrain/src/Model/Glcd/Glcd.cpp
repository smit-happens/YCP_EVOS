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
    //display = new ST7565(MB_SID, MB_SCLK, MB_A0, MB_RST, MB_CS);
    U8G2_ST7565_LM6059_F_4W_SW_SPI u8g2(U8G2_R0, MB_SCLK, MB_SID, MB_CS, MB_A0, MB_RST);
    // initialize the glcd and set the contrast to 0x18
    u8g2.begin();
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_ncenB14_tr);
    u8g2.drawStr(0,20,"Hello World!");
    u8g2.sendBuffer();
}



/** 
 * @brief  Glcd destructor
 */
Glcd::~Glcd(void)
{
    //delete display;
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
    //display->clear();
    //display->drawbitmap(0, 0, JustBarelyLogo, 128, 64, BLACK);
    //display->display();
}