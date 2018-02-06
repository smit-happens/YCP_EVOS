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
//FIXME: in order to handle more events going off, might have to do the priority partitioning soon


const uint16_t EF_TIMER            = 0b1;   //The first event flag (EF) mask
const uint16_t EF_CAN              = 0b10;  //CAN EF mask
const uint16_t EF_COOLING          = 0b100;  //cooling EF mask
const uint16_t EF_DASH             = 0b1000;  //dash EF mask
const uint16_t EF_GLCD             = 0b10000;  //Glcd EF mask
const uint16_t EF_IMD              = 0b100000;  //Imd EF mask
const uint16_t EF_ORION            = 0b1000000;  //Orion EF mask
const uint16_t EF_PEDAL            = 0b10000000;  //Pedal EF mask
const uint16_t EF_SDCARD           = 0b100000000;  //SdCard EF mask
const uint16_t EF_UNITEK           = 0b1000000000;  //Unitek EF mask
const uint16_t EF_BATLOG           = 0b10000000000;  //BatLog EF mask
const uint16_t EF_STANDBY          = 0b100000000000;  //Shutdown EF mask
const uint16_t EF_PRECHARGE        = 0b1000000000000;  //Shutdown EF mask
const uint16_t EF_READYTODRIVE     = 0b10000000000000;  //Shutdown EF mask
const uint16_t EF_LAUNCH           = 0b100000000000000;  //Shutdown EF mask
const uint16_t EF_SHUTDOWN         = 0b1000000000000000;  //Shutdown EF mask

#endif  //EVENTMASKS_HPP
