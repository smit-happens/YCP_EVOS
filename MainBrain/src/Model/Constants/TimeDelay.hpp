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

//Ready to drive Siren time
const int TIME_SIREN    = 2000;

//dash light test time
const int TIME_LIGHT    = 2000;

//waiting period for precharging Unitek
const int TIME_PRECHARGE    = 666;


//GLCD polling delay
const int POLL_TIME_GLCD    = 300;

//SdCard logging delay
const int POLL_TIME_SDCARD  = 500;

//Pedal polling delay
const int POLL_TIME_PEDAL   = 10;

//Orion polling delay for battery charge and temperature
const int POLL_TIME_ORION   = 1000;

#endif  //TIMEDELAY_HPP
