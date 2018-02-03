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


const uint32_t TIMER_EF0    = 0b1;   //The first event flag (EF) mask
const uint32_t CAN_EF1      = 0b10;  //CAN EF mask
const uint32_t COOLING_EF2  = 0b100;  //cooling EF mask
const uint32_t DASH_EF3     = 0b1000;  //dash EF mask
const uint32_t GLCD_EF4     = 0b10000;  //Glcd EF mask
const uint32_t IMD_EF5      = 0b100000;  //Imd EF mask
const uint32_t ORION_EF6    = 0b1000000;  //Orion EF mask
const uint32_t PEDAL_EF7    = 0b10000000;  //Pedal EF mask
const uint32_t SDCARD_EF8   = 0b100000000;  //SdCard EF mask
const uint32_t UNITEK_EF9   = 0b1000000000;  //Unitek EF mask



#endif  //EVENTMASKS_HPP
