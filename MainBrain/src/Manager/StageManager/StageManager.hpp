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
#include "../../Model/Constants/Constants.hpp"


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

    //Logger instance
    Logger* logger;

    //Processing functions for the various devices
    void processCan(uint8_t* taskFlags);
    void processCooling(uint8_t* taskFlags);
    void processDash(uint8_t* taskFlags);
    void processGlcd(uint8_t* taskFlags);
    void processImd(uint8_t* taskFlags);
    void processOrion(uint8_t* taskFlags);
    void processPedal(uint32_t* eventFlags, uint8_t* taskFlags);
    void processSdCard(uint8_t* taskFlags);
    void processUnitek(uint8_t* taskFlags);
    void processBatlog(uint8_t* taskFlags);


    //for making sure that all the stages except the currently executing one needs to be reconfigured
    void resetAllStagesExcept(Stage nonResetStage);

};


#endif  //STAGEMANAGER_HPP
