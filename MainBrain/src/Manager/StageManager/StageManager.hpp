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
        STAGE_BOOTUP,
        STAGE_SELF_TEST,
        STAGE_SUBSYSTEM_TEST,
        STAGE_STANDBY,
        STAGE_PRECHARGE,
        STAGE_ENERGIZED,
        STAGE_DRIVING,
        STAGE_LAUNCH,
        STAGE_SHUTDOWN
    };

    StageManager();

    //handles the various timers we'll be using and setting Task Flags (TFs) based on them
    uint32_t processTimers(Stage currentStage);

    Stage processStandbyEvents(uint32_t &localEventFlags, Priority urgencyLevel);
    Stage processPrechargeEvents(uint32_t &localEventFlags, Priority urgencyLevel);
    Stage processEnergizedEvents(uint32_t &localEventFlags, Priority urgencyLevel);
    Stage processDrivingEvents(uint32_t &localEventFlags, Priority urgencyLevel);



private:
    struct Timer {
        /* add name string field */
        int count;
        int limit;
        uint32_t TFmask;
    };
    
    Timer* timerList;
    uint32_t timerTF = 0;

    //Processing functions for the various devices
    //TODO: Might eventually take a TF as an input param
    uint32_t processCan(Stage currentStage);
    uint32_t processCooling(Stage currentStage);
    uint32_t processDash(Stage currentStage);
    uint32_t processGlcd(Stage currentStage);
    uint32_t processImd(Stage currentStage);
    uint32_t processOrion(Stage currentStage);
    uint32_t processPedal(Stage currentStage);
    uint32_t processSdCard(Stage currentStage);
    uint32_t processUnitek(Stage currentStage);
    uint32_t processBatlog(Stage currentStage);
    uint32_t processStandby(Stage currentStage);
    uint32_t processPrecharge(Stage currentStage);
    uint32_t processReadyToDrive(Stage currentStage);
    uint32_t processLaunch(Stage currentStage);
    uint32_t processShutdown(Stage currentStage);

};


#endif  //STAGEMANAGER_HPP
