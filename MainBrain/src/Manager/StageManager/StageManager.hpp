/**  Manages the event handling functions in the superloop
 *
 * #include "StageManager.hpp"
 * Created 1-28-18 By: Smitty
 *
 * A longer description.
 */

#ifndef STAGEMANAGER_HPP
#define STAGEMANAGER_HPP

#include "../ControllerManager/ControllerManager.hpp"
#include "EventMasks.hpp"
#include "../../Model/Constants/TimeDelay.hpp"


class StageManager
{
public:

    enum Stage
    {
        BOOTUP,
        SELF_TEST,
        SUBSYSTEM_TEST,
        STANDBY,
        PRECHARGE,
        DRIVE,
        LAUNCH,
        SHUTDOWN
    };

    StageManager();

    //handles the various timers we'll be using and setting Task Flags (TFs) based on them
    uint16_t processTimers(void);

    //FIXME: TESTING CODE START
    void testLed1();
    void testLed2();
    void testLed3();
    void testLed4();
    //FIXME: TESTING CODE END

private:
    struct Timer {
        /* add name string field */
        int count;
        int limit;
        uint32_t TFmask;
    };
    
    Timer* timerList;

    //FIXME: TESTING CODE START
    bool LEDstate1 = false;
    bool LEDstate2 = false;
    bool LEDstate3 = false;
    bool LEDstate4 = false;
    //FIXME: TESTING CODE END

};


#endif  //STAGEMANAGER_HPP
