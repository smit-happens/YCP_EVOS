/**  Central location of all the times for polling the timer driven devices
 *
 * #include TimeDelay.hpp
 * Created 12-19-17 By: Smitty
 * 
 * All times are in milliSeconds
 */

#ifndef TIMEDELAY_HPP
#define TIMEDELAY_HPP

#include <Arduino.h>


const int TIMER_NUM     = 4;    //number of timers in use

const int LED_1_POLL    = 100;
const int LED_2_POLL    = 200;
const int LED_3_POLL    = 250;
const int LED_4_POLL    = 500;




#endif  //TIMEDELAY_HPP
