/**  Handles the setup and usage of the built in RTC
 *
 * #include "Rtc.hpp"
 * Created 1-14-18  By: Smitty
 *
 * https://www.pjrc.com/teensy/td_libs_Time.html
 */


#ifndef RTC_HPP
#define RTC_HPP

#include <Arduino.h>
#include <TimeLib.h>

//Might need additional methods to flesh out all the functionality



class Rtc
{
public:
    Rtc(void);

    /** 
     * Drafting up possible functions
     * 
     * getDate()
     * getTime()
     * getDateTime()
     * 
     * 
     */

private:
    //static allows for use of private functions
    //See here: http://www.learncpp.com/cpp-tutorial/812-static-member-functions/
    static time_t getTeensy3Time(void);
};


#endif  //RTC_HPP
