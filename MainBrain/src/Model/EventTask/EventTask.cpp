/**  Event flag and task lookup
 *
 * Created 2-16-18 By: Shawn
 *

 * 
 */

#include "EventTask.hpp"
#include "Task.hpp"

/** 
 * @brief Initialize the lookup table for the devices
 * @note  Initialize the event flags and priorities for each of the devices
 * @retval 
 */
EventTask::EventTask()
{
    //This looping structure can be used to loop through the lookup table by using the DeviceName enumeration
    //in this example, each row of the table is being set to 0 for the event flag and high priority
    // for(int i = TIMER; i < NUM_DEVICES; i++)
    // {
    //     deviceLookupTable[i] = {0, PRIORITY_HIGH};
    // }


    //all device event flags will initially be set to 0 and all priorities are set to LOW except for SHUTDOWN
    //Event flags will be set by the interrupts so they will all be initially 0
    //TODO: change the priorities for each device to be what we want it to be
    //TODO: add a task array pointer to the DeviceStatus struct that will contain the other various specific tasks that a device will have
    deviceLookupTable[TIMER] = {0, PRIORITY_LOW};
    deviceLookupTable[CAN] = {0, PRIORITY_LOW};
    deviceLookupTable[COOLING] = {0, PRIORITY_LOW};
    deviceLookupTable[DASH] = {0, PRIORITY_LOW};
    deviceLookupTable[GLCD] = {0, PRIORITY_LOW};
    deviceLookupTable[IMD] = {0, PRIORITY_LOW};
    deviceLookupTable[ORION] = {0, PRIORITY_LOW};
    deviceLookupTable[PEDAL] = {0, PRIORITY_LOW};
    deviceLookupTable[SDCARD] = {0, PRIORITY_LOW};
    deviceLookupTable[UNITEK] = {0, PRIORITY_LOW};
    deviceLookupTable[BATLOG] = {0, PRIORITY_LOW};
    deviceLookupTable[STANDBY] = {0, PRIORITY_LOW};
    deviceLookupTable[PRECHARGE] = {0, PRIORITY_LOW};
    deviceLookupTable[READYTODRIVE] = {0, PRIORITY_LOW};
    deviceLookupTable[LAUNCH] = {0, PRIORITY_LOW};
    deviceLookupTable[SHUTDOWN] = {0, PRIORITY_CRITICAL};
}


/** 
 * @brief  returns the device status struct
 * @note   returns the device status struct based on the specific device that is passed in
 * @param  Device device - the specific device that is having its DeviceStatus being returned
 * @retval DeviceStatus of the specified device
 */
DeviceStatus EventTask::getDeviceStatus(DeviceName device)
{
    return deviceLookupTable[device];
}


/** 
 * @brief  Increment the event flag
 * @note   Increment the event flag for the specified device
 * @param  device: The specific device that is having its event flag incremented
 * @retval None
 */
void EventTask::incrementDeviceEventFlagCount(DeviceName device)
{
    deviceLookupTable[device].eventFlagCount++;
}

/** 
 * @brief  Decrement the event flag
 * @note   Decrement the event flag for the specified device
 * @param  device: the specific device that is having its event flag decremented
 * @retval None
 */
void EventTask::decrementDeviceEventFlagCount(DeviceName device)
{
    deviceLookupTable[device].eventFlagCount--;
}


/** 
 * @brief  set the event priority of the device
 * @note   set the event priority to the newPriority for the specific device
 * @param  device: the device that is having its priority modified
 * @param  newPriority: the new priority for the device
 * @retval None
 */
void EventTask::setDeviceEventPriority(DeviceName device, Priority newPriority)
{
    deviceLookupTable[device].devicePriority = newPriority;
}
