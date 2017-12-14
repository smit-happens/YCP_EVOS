/**  A one line description of the class.
 *
 * #include Watchdog.hpp
 * Created 11-06-17 By: Smitty
 *
 * Implemented based off the code found here: https://github.com/adafruit/Adafruit_SleepyDog
 */

#ifndef WATCHDOG_HPP
#define WATCHDOG_HPP

#include <kinetis.h>

class Watchdog
{
public:
    Watchdog(): setting(0) {}

    // Enable the watchdog timer to reset the machine after a period of time
    // without any calls to reset().
    //
    // The actual period (in milliseconds) before a watchdog timer reset is
    // returned.
    int enable(int maxPeriodMS = 0);

    // Reset or 'kick' the watchdog timer to prevent a reset of the device.
    void reset();

    // Completely disable the watchdog timer.
    void disable();

private:
    int setting;
};

#endif    //WATCHDOG_HPP
