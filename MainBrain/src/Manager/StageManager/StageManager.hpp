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
    uint32_t processTimers(void);

private:
    struct Timer {
        int count;
        int limit;
        uint32_t TFmask;
    };
    
    Timer* timerList;

};


#endif  //STAGEMANAGER_HPP
