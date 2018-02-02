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


const uint32_t CAN_MESSAGE_EF0 = 0b1;   //The first event flag (EF) mask



#endif  //EVENTMASKS_HPP
