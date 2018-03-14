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


const int TIMER_NUM     = 2;    //number of timers in use

const int LED_1_POLL    = 100;
const int LED_2_POLL    = 200;

//Ready to drive Siren time
const int TIME_SIREN    = 2000;

//Pedal polling delay
const int TIME_GAS_POLL    = 100;


#endif  //TIMEDELAY_HPP
