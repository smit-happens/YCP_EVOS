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
        STAGE_TEST,
        STAGE_STANDBY,
        STAGE_PRECHARGE,
        STAGE_ENERGIZED,
        STAGE_DRIVING,
        STAGE_LAUNCH,
        STAGE_SHUTDOWN
    };

    //used to determine if a stage needs to be configured or not
    bool isStandbyConfigured = false;
    bool isPrechargeConfigured = false;
    bool isEnergizedConfigured = false;
    bool isDrivingConfigured = false;
    bool isLaunchConfigured = false;

    StageManager();

    //handles the various timers we'll be using and setting Task Flags (TFs) based on them
    uint32_t processTimers(Stage currentStage);

    //handles the excecution of the various stages
    Stage processEventsStandby(uint32_t &localEventFlags, Priority urgencyLevel);
    Stage processEventsPrecharge(uint32_t &localEventFlags, Priority urgencyLevel);
    Stage processEventsEnergized(uint32_t &localEventFlags, Priority urgencyLevel);
    Stage processEventsDriving(uint32_t &localEventFlags, Priority urgencyLevel);

    //contains code that is executed once at the beginning of a stage
    void configureStandby(void);
    void configurePrecharge(void);
    void configureEnergized(void);
    void configureDriving(void);
    void configureLaunch(void);

    //for correctly setting the next stage based off the current one
    // void transitionStageToFrom(Stage nextStage, Stage currentStage);


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

    //for making sure that all the stages except the currently executing one needs to be reconfigured
    void resetAllStagesExcept(Stage currentStage);

};


#endif  //STAGEMANAGER_HPP
