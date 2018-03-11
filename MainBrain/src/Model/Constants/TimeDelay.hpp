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
const int LED_3_POLL    = 400;
const int LED_4_POLL    = 800;

//Ready to drive Siren time
const int TIME_SIREN    = 2000;

#endif  //TIMEDELAY_HPP
