/**  Manages the event handling functions in the superloop
 *
 * #include "StageManager.hpp"
 * Created 1-28-18 By: Smitty
 *
 * A longer description.
 */

#ifndef STAGEMANAGER_HPP
#define STAGEMANAGER_HPP

#include "../../Controller/Controller.hpp"
#include "../../Model/Constants/TimeDelay.hpp"
#include "../../Model/EventTask/EventTask.hpp"


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
    // uint32_t processTimers(void);
    uint32_t processTimers(void);

    //the following functions might eventually take a TF as an input param
    uint32_t processCan(void);
    uint32_t processCooling(void);
    uint32_t processDash(void);
    uint32_t processGlcd(void);
    uint32_t processImd(void);
    uint32_t processOrion(void);
    uint32_t processPedal(void);
    uint32_t processSdCard(void);
    uint32_t processUnitek(void);
    uint32_t processBatlog(void);
    uint32_t processStandby(void);
    uint32_t processPrecharge(void);
    uint32_t processReadyToDrive(void);
    uint32_t processLaunch(void);
    uint32_t processShutdown(void);



private:
    struct Timer {
        /* add name string field */
        int count;
        int limit;
        uint32_t TFmask;
    };
    
    Timer* timerList;
    uint32_t timerTF = 0;


};


#endif  //STAGEMANAGER_HPP
