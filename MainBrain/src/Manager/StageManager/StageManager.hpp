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
#include "../../Model/Constants/Flags.hpp"


class StageManager
{
public:

    //current stage that we're processing
    Stage currentStage;

    //used to determine if a stage needs to be configured or not
    bool isStandbyConfigured = false;
    bool isPrechargeConfigured = false;
    bool isEnergizedConfigured = false;
    bool isDrivingConfigured = false;

    StageManager();

    //handles the various timers we'll be using and setting Task Flags (TFs) based on them
    uint32_t processTimers(void);

    //Boot for each device
    void bootTest(uint32_t* eventFlags);

    void shutdown(void);

    //contains code that is executed once at the beginning of a stage
    void configureStage(void);

    //handles the excecution of the various stages
    Stage processStage(Priority urgencyLevel, uint32_t* eventFlags, uint8_t* taskFlags);


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

    Stage changeStage;


    //Processing functions for the various devices
    uint32_t processCan(uint8_t* taskFlags);
    uint32_t processCooling(void);
    uint32_t processDash(uint8_t* taskFlags);
    uint32_t processGlcd(void);
    uint32_t processImd(void);
    uint32_t processOrion(void);
    void processPedal(uint32_t* eventFlags, uint8_t* taskFlags);
    uint32_t processSdCard(void);
    uint32_t processUnitek(uint8_t* taskFlags);
    uint32_t processBatlog(void);


    //for making sure that all the stages except the currently executing one needs to be reconfigured
    void resetAllStagesExcept(Stage nonResetStage);

};


#endif  //STAGEMANAGER_HPP
