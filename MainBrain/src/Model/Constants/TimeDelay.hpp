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


const int TIMER_NUM     = 3;    //number of timers in use

//Ready to drive Siren time
const int TIME_SIREN    = 2000;

//dash light test time
const int TIME_LIGHT    = 2000;

//GLCD polling delay
const int POLL_TIME_GLCD    = 500;

//SdCard logging delay
const int POLL_TIME_SDCARD  = 500;

//Pedal polling delay
const int POLL_TIME_PEDAL   = 100;


#endif  //TIMEDELAY_HPP
