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
#include "EventMasks.hpp"


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
    // uint16_t processTimers(void);
    uint16_t processTimers(void);

    //the following functions might eventually take a TF as an input param
    uint16_t processCan(void);
    uint16_t processCooling(void);
    uint16_t processDash(void);
    uint16_t processGlcd(void);
    uint16_t processImd(void);
    uint16_t processOrion(void);
    uint16_t processPedal(void);
    uint16_t processSdCard(void);
    uint16_t processUnitek(void);
    uint16_t processBatlog(void);
    uint16_t processStandby(void);
    uint16_t processPrecharge(void);
    uint16_t processReadyToDrive(void);
    uint16_t processLaunch(void);
    uint16_t processShutdown(void);



private:
    struct Timer {
        /* add name string field */
        int count;
        int limit;
        uint32_t TFmask;
    };
    
    Timer* timerList;
    uint16_t timerTF = 0;



};


#endif  //STAGEMANAGER_HPP
