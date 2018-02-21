/**  Event flag/task lookup table
 *
 * Created 2-16-18 By: Shawn
 *
 * 
 */

#ifndef EVENTTASK_HPP
#define EVENTTASK_HPP

#include <Arduino.h>

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
    bool eventFlag;
    
    // int eventFlagCount;

    //TODO: this is a pointer to a task array and will be specific to the device
    //int* taskArray;

    //priority of the device event being handled
    Priority devicePriority;
};


//this enum is used as an index in the lookup table and specifies each device for the car
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
    SHUTDOWN,
    NUM_DEVICES //The number of devices, MAINTAIN AT END OF ENUM
};


class EventTask
{
public:
    EventTask();
    ~EventTask(void);

    DeviceStatus getDeviceStatus(DeviceName device);

    bool getDeviceEventFlag(DeviceName device);
    bool* getAllDeviceEventFlag(void);
    void setAllDeviceEventFlag(bool* flags);
    void assertDeviceEventFlag(DeviceName device);
    void clearDeviceEventFlag(DeviceName device);
    void clearAllDeviceEventFlag(void);

    // void incrementDeviceEventFlagCount(DeviceName device);
    // void decrementDeviceEventFlagCount(DeviceName device);
    void setDeviceEventPriority(DeviceName device, Priority newPriority);

private: 
    DeviceStatus deviceLookupTable[NUM_DEVICES];

};

#endif  //EVENTTASK_HPP
