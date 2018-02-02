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



class StageManager
{
public:

    enum WorkflowStage
    {
        BOOTUP,
        SELF_TEST,
        SUBSYSTEM_TEST,
        STANDBY,
        PRECHARGE,
        DRIVE,
        SHUTDOWN
    };

    StageManager();

};


#endif  //STAGEMANAGER_HPP
