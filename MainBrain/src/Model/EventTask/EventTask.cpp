/**  Task Flag lookup
 *
 * Created 2-16-18 By: Shawn
 *
 * 
 */

#include "EventTask.hpp"

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
    //     taskTable[i] = {0, PRIORITY_HIGH};
    // }
}


/** 
 * @brief  destructor
 * @note   
 * @retval 
 */
EventTask::~EventTask()
{

}


/** 
 * @brief  returns the device status struct
 * @note   returns the device status struct based on the specific device that is passed in
 * @param  Device device - the specific device that is having its DeviceStatus being returned
 * @retval DeviceStatus of the specified device
 */
uint8_t EventTask::getTaskFlags(DeviceName name)
{
    return taskTable[name];
}


/** 
 * @brief  
 * @note   
 * @param  
 * @retval None
 */
void EventTask::setAllTaskFlags(uint8_t taskList[])
{
    //iterating through the possible event flags
    for(int i = TIMER; i < NUM_DEVICES; i++)
    {
        if(taskList[i])
        {
            taskTable[i] |= taskList[i];
        }
    }
}


/** 
 * @brief  
 * @note   
 * @param  taskList[]: 
 * @retval None
 */
void EventTask::setAllTaskFlags(volatile uint8_t taskList[])
{
    //iterating through the possible event flags
    for(int i = TIMER; i < NUM_DEVICES; i++)
    {
        if(taskList[i])
        {
            taskTable[i] |= taskList[i];
        }
    }
}


/** 
 * @brief  Used to clear a specific task
 * @note   
 * @param  name: 
 * @param  task: 
 * @retval None
 */
void EventTask::clearTaskFlag(DeviceName name, uint8_t task)
{
    taskTable[name] &= ~task;

}


    void EventTask::clearAllDeviceTaskFlags(DeviceName name)
{
    taskTable[name] = 0;
}


/** 
 * @brief  Increment the event flag
 * @note   Increment the event flag for the specified device
 * @param  device: The specific device that is having its event flag incremented
 * @retval None
 */
// void EventTask::incrementDeviceEventFlagCount(DeviceName device)
// {
//     taskTable[device].eventFlagCount++;
// }

/** 
 * @brief  Decrement the event flag
 * @note   Decrement the event flag for the specified device
 * @param  device: the specific device that is having its event flag decremented
 * @retval None
 */
// void EventTask::decrementDeviceEventFlagCount(DeviceName device)
// {
//     taskTable[device].eventFlagCount--;
// }
