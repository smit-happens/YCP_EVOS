/**  Event masks for each interupt
 *
 * #include EventMasks.hpp
 * Created 1-26-18 By: Smitty
 *
 * THERE SHOULD NEVER BE TWO OF THE SAME MASKS
 * would cause interupts to go unserviced and unexpected behavior
 * 
 */

#ifndef EVENTMASKS_HPP
#define EVENTMASKS_HPP

#include <Arduino.h>

//TODO: account for EFs of differing levels of severity by organizing them into
//      categories like EF_Servere, EF_Normal, EF_Low


const uint32_t EF0_TIMER            = 0b1;   //The first event flag (EF) mask
const uint32_t EF1_CAN              = 0b10;  //CAN EF mask
const uint32_t EF2_COOLING          = 0b100;  //cooling EF mask
const uint32_t EF3_DASH             = 0b1000;  //dash EF mask
const uint32_t EF4_GLCD             = 0b10000;  //Glcd EF mask
const uint32_t EF5_IMD              = 0b100000;  //Imd EF mask
const uint32_t EF6_ORION            = 0b1000000;  //Orion EF mask
const uint32_t EF7_PEDAL            = 0b10000000;  //Pedal EF mask
const uint32_t EF8_SDCARD           = 0b100000000;  //SdCard EF mask
const uint32_t EF9_UNITEK           = 0b1000000000;  //Unitek EF mask
const uint32_t EF10_BATLOG          = 0b10000000000;  //BatLog EF mask
const uint32_t EF11_STANDBY         = 0b100000000000;  //Shutdown EF mask
const uint32_t EF12_PRECHARGE       = 0b1000000000000;  //Shutdown EF mask
const uint32_t EF13_READYTODRIVE    = 0b10000000000000;  //Shutdown EF mask
const uint32_t EF14_LAUNCH          = 0b100000000000000;  //Shutdown EF mask
const uint32_t EF15_SHUTDOWN        = 0b1000000000000000;  //Shutdown EF mask

#endif  //EVENTMASKS_HPP
