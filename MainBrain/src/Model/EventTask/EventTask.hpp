/**  Event flag/task lookup table
 *
 * Created 2-16-18 By: Shawn
 *
 * 
 */

#ifndef EVENTTASK_HPP
#define EVENTTASK_HPP

#include <Arduino.h>

//TODO: account for EFs of differing levels of severity by organizing them into
//      categories like EF_Servere, EF_Normal, EF_Low
//FIXME: in order to handle more events going off, might have to do the priority partitioning soon


//as of right now, we have 4 levels of priority
//CRITICAL will be reserved for situations where the car had a critical error and needs to shut down
//HIGH, MEDIUM, LOW will be the various levels of importance of the various tasks, with safety having highest priority
enum Priority
{
    PRIORITY_CRITICAL,
    PRIORITY_HIGH,
    PRIORITY_MEDIUM,
    PRIORITY_LOW
};


//this will contain the event flag, a pointer to a task array for the specific device, and an event priority
struct DeviceStatus
{
    int eventFlag;
    //this is a pointer to a task array and will be specific to the device
    //int* taskArray;
    //priority of the device event being handled
    Priority devicePriority;
};




//this enum is used as an index in the 
enum DeviceName
{
    TIMER,
    CAN,
    COOLING,
    DASH,
    GLCD,
    IMD,
    ORION,
    PEDAL,
    SDCARD,
    UNITEK,
    BATLOG,
    STANDBY,
    PRECHARGE,
    READYTODRIVE,
    LAUNCH,
    SHUTDOWN
};
static DeviceStatus deviceLookupTable[] =
{
    {1, PRIORITY_HIGH}, //device TIMER
    {1, PRIORITY_HIGH}, //device CAN
    {1, PRIORITY_HIGH}, //device COOLING
    {1, PRIORITY_HIGH}, //device DASH
    {1, PRIORITY_HIGH}, //device GLCD
    {1, PRIORITY_HIGH}, //device IMD
    {1, PRIORITY_HIGH}, //device ORION
    {1, PRIORITY_HIGH}, //device PEDAL
    {1, PRIORITY_HIGH}, //device SDCARD
    {1, PRIORITY_HIGH}, //device UNITEK
    {1, PRIORITY_HIGH}, //device BATLOG
    {1, PRIORITY_HIGH}, //stage STANDBY
    {1, PRIORITY_HIGH}, //stage PRECHARGE
    {1, PRIORITY_HIGH}, //stage READYTODRIVE
    {1, PRIORITY_HIGH}, //stage LAUNCH
    {1, PRIORITY_HIGH} //stage SHUTDOWN
};

class EventTask
{
public:
    EventTask();
    ~EventTask(void);

    DeviceStatus getDeviceStatus(DeviceName device);
    void incrementDeviceEventFlag(DeviceName device);
    void decrementDeviceEventFlag(DeviceName device);
    void setDeviceEventPriority(DeviceName device, Priority newPriority);



    /**  
     * 
     * 
     * 
     */
private:      
};



#endif  //EVENTTASK_HPP
