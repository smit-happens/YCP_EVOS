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
    display->setContrast(130);

    pinMode(MB_R, OUTPUT);
    pinMode(MB_G, OUTPUT);
    pinMode(MB_B, OUTPUT);
    
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

//displays the current mode selection on the GLCD in a graphical manner. There is a drop capital so that the mode is easily distinguishable
void Glcd::drawModeSelection(Stage stage)
{
    display->setFont(u8g2_font_profont29_tr);
    //display->clearBuffer(); //clear the screen
    display->setDrawColor(0); //clear the previous mode
    //how wide x tall should this box be?
    display->drawBox(MODE_START_X, MODE_START_Y-48, 65, 52);
    display->setDrawColor(1);
    switch(stage){
        case STAGE_STANDBY:
            display->drawStr(MODE_START_X, MODE_START_Y, "S");
            display->setFont(u8g2_font_profont12_tr);
            display->drawStr(MODE_START_X+14, MODE_START_Y, "tdby");
        break;
        case STAGE_PRECHARGE:
            display->drawStr(MODE_START_X, MODE_START_Y, "P");
            display->setFont(u8g2_font_profont12_tr);
            display->drawStr(MODE_START_X+14, MODE_START_Y, "re");
        break;
        case STAGE_ENERGIZED:
            display->drawStr(MODE_START_X, MODE_START_Y, "E");
            display->setFont(u8g2_font_profont12_tr);
            display->drawStr(MODE_START_X+14, MODE_START_Y, "nergize");
        break;
        case STAGE_DRIVING:
            display->drawStr(MODE_START_X, MODE_START_Y, "D");
            display->setFont(u8g2_font_profont12_tr);
            display->drawStr(MODE_START_X+14, MODE_START_Y, "rive");
        break;
        default: break;
    }
    dirtyBit = true;
}

void Glcd::flushGlcdBuffer(void)
{
    display->sendBuffer();
    dirtyBit = false;
}

void Glcd::clearGlcdBuffer(void)
{
    display->clearBuffer();
    dirtyBit = true;
}

bool Glcd::getDirtyBit(void)
{
    return dirtyBit;
}

//took out LV batt bar
void Glcd::drawBattBars(uint8_t lvBattPercent, uint8_t hvBattPercent)
{ 
    //clamp % to 0-100 range. 
    if(lvBattPercent < 0) {lvBattPercent = 0; }
    if(hvBattPercent < 0) {hvBattPercent = 0; }
    if(hvBattPercent > 100) {hvBattPercent = 100; }
    if(lvBattPercent > 100) {lvBattPercent = 100; }
   // int lvBarLength = ((BAR_LENGTH-2)*lvBattPercent) / 100;
    int hvBarLength = (float)(BAR_LENGTH-2)*((float)hvBattPercent/100.0);

    display->setDrawColor(0); //now drawing blank pixels, clear old bar
    display->drawRBox(BATT_BAR_START_X+1, HV_BAR_START_Y+3, BAR_LENGTH-2, HV_batt_height-4, 3);
   // display->drawRBox(BATT_BAR_START_X+1, LV_BAR_START_Y+3, BAR_LENGTH-2, LV_Batt_height-4, 3);
    display->setDrawColor(1); //draw black now
   if(hvBarLength > 2){
        display->drawRBox(BATT_BAR_START_X+1, HV_BAR_START_Y+3, hvBarLength, HV_batt_height-4, 3);
    }
    // else if(lvBarLength > 2) {
    //     display->drawRBox(BATT_BAR_START_X+1, LV_BAR_START_Y+3, hvBarLength, LV_Batt_height-4, 3);
    // }
    
   
    dirtyBit = true;
}

void Glcd::setupBattBars(){
    display->drawXBM(2, HV_BAR_START_Y, HV_batt_width, HV_batt_width, HV_batt_bits);
    //display->drawXBM(2, LV_BAR_START_Y, LV_Batt_width, LV_Batt_height, LV_Batt_bits);
    display->drawRFrame(BATT_BAR_START_X, HV_BAR_START_Y+2, BAR_LENGTH, HV_batt_height-2, 3);
   // display->drawRFrame(BATT_BAR_START_X, LV_BAR_START_Y+2, BAR_LENGTH, LV_Batt_height-2, 3);
    dirtyBit = true;
}

void Glcd::drawRpm(uint32_t pedalValue, uint32_t rpm) {
    display->setDrawColor(0);
    display->drawBox(RPM_START_X-1, RPM_START_Y-12, 80, 16);
    display->setDrawColor(1);
    char buf[50]; 
    sprintf(buf, "%lu | %lu", pedalValue, rpm);
    display->drawStr(RPM_START_X, RPM_START_Y, buf);
}

void Glcd::setupTempScreen(void)
{
    display->setFont(u8g2_font_profont12_tr);
    display->drawXBM(TEMP_LIST_START_X, TEMP_LIST_START_Y, HV_batt_width, HV_batt_height, HV_batt_bits);
    display->drawStr(TEMP_LIST_START_X+(TEMP_LIST_PADDING), TEMP_LIST_START_Y+(TEMP_LIST_TEXT_PADDING), "HV MAX: ");

    display->drawStr(TEMP_LIST_START_X+(TEMP_LIST_PADDING), TEMP_LIST_START_Y+(TEMP_LIST_TEXT_PADDING*2), "MC: ");

    display->drawStr(TEMP_LIST_START_X+(TEMP_LIST_PADDING), TEMP_LIST_START_Y+(TEMP_LIST_TEXT_PADDING*3), "Water: ");
    display->drawStr(TEMP_LIST_START_X+(TEMP_LIST_PADDING), TEMP_LIST_START_Y+(TEMP_LIST_TEXT_PADDING*4), "Motor: ");

    dirtyBit = true;
}

void Glcd::drawTemps(uint8_t HV_max, uint8_t Unitek_temp, uint8_t Motor_temp, uint8_t water_temp)
{
    display->setDrawColor(0);
    display->drawBox(TEMP_LIST_TEMP_X-1, TEMP_LIST_START_Y, 25, TEMP_LIST_START_Y+(TEMP_LIST_TEXT_PADDING*4)+1);
    display->setDrawColor(1);
    char buf[8]; 
    sprintf(buf, "%d C", HV_max);
    display->drawStr(TEMP_LIST_TEMP_X, TEMP_LIST_START_Y+(TEMP_LIST_TEXT_PADDING), buf);
    sprintf(buf, "%d C", Unitek_temp);
    display->drawStr(TEMP_LIST_TEMP_X, TEMP_LIST_START_Y+(TEMP_LIST_TEXT_PADDING*2), buf);
    sprintf(buf, "%d C", Motor_temp);
    display->drawStr(TEMP_LIST_TEMP_X, TEMP_LIST_START_Y+(TEMP_LIST_TEXT_PADDING*3), buf);
    sprintf(buf, "%d C", water_temp);
    display->drawStr(TEMP_LIST_TEMP_X, TEMP_LIST_START_Y+(TEMP_LIST_TEXT_PADDING*4), buf);

    dirtyBit = true;
}

void Glcd::showShutdownLogo(void)
{
    display->clearBuffer();
    display->drawXBM(0, 0, Shutdown_width, Shutdown_height, Shutdown_bits);
    display->setFont(u8g2_font_profont12_tr);
    display->drawStr(35, 15, "Power Cycle Req.");
    dirtyBit = true;
}

void Glcd::drawOkIcon(void) 
{
      display->drawXBM(OK_ICON_X, OK_ICON_Y, OK_icon_width, OK_icon_height, OK_icon_bits);
      dirtyBit = true;
}

void Glcd::drawSDIcon(void) 
{
      display->drawXBM(SD_ICON_X, SD_ICON_Y, SDCard_width, SDCard_height, SDCard_bits);
      dirtyBit = true;
}


void Glcd::drawErrors(err_type err) 
{
    if(err == ERR_NONE) {return;}
    display->drawXBM(ERR_START_X, ERR_START_Y, o_fok_width, o_fok_height, o_fok_bits);
    switch(err) 
    {
        case ERR_ORION:
            display->drawXBM(ERR_START_X+(ERR_PADDING), ERR_START_Y, HV_batt_width, HV_batt_height, HV_batt_bits);
            display->drawXBM(ERR_START_X+(ERR_PADDING*2), ERR_START_Y, BMS_ERR_width, BMS_ERR_height, BMS_ERR_bits);
        break;
        case ERR_IMD:
            display->drawXBM(ERR_START_X+(ERR_PADDING*3), ERR_START_Y, IMD_ERR_width, IMD_ERR_height, IMD_ERR_bits);
        break;
        case ERR_TMP:
            display->drawXBM(ERR_START_X+(ERR_PADDING*4), ERR_START_Y, water_temp_width, water_temp_height, water_temp_bits);
        case ERR_UNITEK:
            display->drawXBM(ERR_START_X+(ERR_PADDING*5), ERR_START_Y, MC_ERR_width, MC_ERR_height, MC_ERR_bits);
        break;
        case ERR_ALL:
            display->drawXBM(ERR_START_X+(ERR_PADDING), ERR_START_Y, HV_batt_width, HV_batt_height, HV_batt_bits);
            display->drawXBM(ERR_START_X+(ERR_PADDING*2), ERR_START_Y, BMS_ERR_width, BMS_ERR_height, BMS_ERR_bits);
            display->drawXBM(ERR_START_X+(ERR_PADDING*3), ERR_START_Y, IMD_ERR_width, IMD_ERR_height, IMD_ERR_bits);
            display->drawXBM(ERR_START_X+(ERR_PADDING*4), ERR_START_Y, water_temp_width, water_temp_height, water_temp_bits);
            display->drawXBM(ERR_START_X+(ERR_PADDING*5), ERR_START_Y, MC_ERR_width, MC_ERR_height, MC_ERR_bits);
        break;
        default: break;
    }
    dirtyBit = true;
}

void Glcd::clearAllErrors(void)
{
    display->setDrawColor(0);
    display->drawBox(ERR_START_X, ERR_START_Y, ERR_START_Y+(ERR_PADDING*6), 18);
    dirtyBit = true;
    display->setDrawColor(1);
}

void Glcd::setBacklightRgb(int r, int g, int b)
{
    analogWrite(MB_R, r);
    analogWrite(MB_G, g);
    analogWrite(MB_B, b);
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
    display->sendBuffer(); //this is ok since we're in start
}