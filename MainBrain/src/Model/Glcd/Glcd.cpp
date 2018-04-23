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
    // U8G2_ST7565_LM6059_F_4W_SW_SPI u8g2(U8G2_R0, MB_SCLK, MB_SID, MB_CS, MB_A0, MB_RST);
    display = new U8G2_ST7565_LM6059_F_4W_SW_SPI(U8G2_R0, MB_SCLK, MB_SID, MB_CS, MB_A0, MB_RST);
    // initialize the glcd and set the contrast to 0x18
    display->begin();
    display->clearBuffer();
    display->setFont(u8g2_font_ncenB14_tr);
    display->drawStr(0,20,"Hello World!");
    display->sendBuffer();
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

void Glcd::showShutdownLogo(void)
{
    display->clearBuffer();
    display->drawXBM(46, 5, Shutdown_width, Shutdown_height, Shutdown_bits);
    display->sendBuffer();
}

/** 
 * @brief  displays image of "Just Barely" on the screen
 * @note   
 * @retval None
 */
void Glcd::showBootLogo(void)
{
    // draw the bitmap
    // display->clear();
    // display->drawbitmap(0, 0, JustBarelyLogo, 128, 64, BLACK);
    // display->display();
    
    display->clearBuffer();
    display->drawXBM(0, 0, Just_Barely_width, Just_Barely_height, Just_Barely_bits);
    // display->setFont(u8g2_font_ncenB14_tr);
    // display->drawStr(0,20,"SPLASH SCREEN");
    display->sendBuffer();
}