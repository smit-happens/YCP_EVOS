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
