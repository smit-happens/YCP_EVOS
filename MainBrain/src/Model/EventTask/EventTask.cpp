/**  Event flag and task lookup
 *
 * Created 2-16-18 By: Shawn
 *

 * 
 */

#include "EventTask.hpp"

/** 
 * @brief  
 * @note   
 * @retval 
 */
EventTask::EventTask()
{
    //nothing to do as of right now, maybe in the future we can use this to initialize the table?
    for(int i = TIMER; i < NUM_DEVICES; i++)
    {
        deviceLookupTable[i] = {1, PRIORITY_HIGH};
    }
    // {
    //     {1, PRIORITY_HIGH}, //device TIMER
    //     {1, PRIORITY_HIGH}, //device CAN
    //     {1, PRIORITY_HIGH}, //device COOLING
    //     {1, PRIORITY_HIGH}, //device DASH
    //     {1, PRIORITY_HIGH}, //device GLCD
    //     {1, PRIORITY_HIGH}, //device IMD
    //     {1, PRIORITY_HIGH}, //device ORION
    //     {1, PRIORITY_HIGH}, //device PEDAL
    //     {1, PRIORITY_HIGH}, //device SDCARD
    //     {1, PRIORITY_HIGH}, //device UNITEK
    //     {1, PRIORITY_HIGH}, //device BATLOG
    //     {1, PRIORITY_HIGH}, //stage STANDBY
    //     {1, PRIORITY_HIGH}, //stage PRECHARGE
    //     {1, PRIORITY_HIGH}, //stage READYTODRIVE
    //     {1, PRIORITY_HIGH}, //stage LAUNCH
    //     {1, PRIORITY_HIGH} //stage SHUTDOWN
    // };
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
DeviceStatus EventTask::getDeviceStatus(DeviceName device)
{
    return deviceLookupTable[(int)device];
}


/** 
 * @brief  
 * @note   
 * @param  dev: 
 * @param  newEventFlag: 
 * @retval None
 */
void EventTask::incrementDeviceEventFlag(DeviceName device)
{
    deviceLookupTable[device].eventFlag++;
}


void EventTask::decrementDeviceEventFlag(DeviceName device)
{
    deviceLookupTable[device].eventFlag--;
}


/** 
 * @brief  
 * @note   
 * @param  dev: 
 * @param  newPriority: 
 * @retval None
 */
void EventTask::setDeviceEventPriority(DeviceName device, Priority newPriority)
{
    deviceLookupTable[device].devicePriority = newPriority;
}
