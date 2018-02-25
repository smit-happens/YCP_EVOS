/**  Event flag/task lookup table
 *
 * Created 2-16-18 By: Shawn
 *
 * 
 */

#ifndef EVENTTASK_HPP
#define EVENTTASK_HPP

#include <Arduino.h>


const uint32_t EF_TIMER            = 0b1;   //The first event flag (EF) mask
const uint32_t EF_CAN              = 0b10;  //CAN EF mask
const uint32_t EF_COOLING          = 0b100;  //cooling EF mask
const uint32_t EF_DASH             = 0b1000;  //dash EF mask
const uint32_t EF_IMD              = 0b10000;  //Imd EF mask
const uint32_t EF_ORION            = 0b100000;  //Orion EF mask
const uint32_t EF_UNITEK           = 0b1000000;  //Unitek EF mask
const uint32_t EF_BATLOG           = 0b10000000;  //BatLog EF mask
const uint32_t EF_SHUTDOWN           = 0b100000000;  //Shutdown EF mask


//Timer event flags
const uint32_t EF_GLCD             = 0b1;  //Glcd EF mask
const uint32_t EF_PEDAL            = 0b10;  //Pedal EF mask
const uint32_t EF_SDCARD           = 0b100;  //SdCard EF mask


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

    uint8_t getTaskFlags(DeviceName name);


    void setAllTaskFlags(uint8_t taskList[]);
    void setAllTaskFlags(volatile uint8_t taskList[]);

    void clearTaskFlag(DeviceName name, uint8_t task);
    void clearAllTaskFlags(DeviceName name);

    // void incrementDeviceEventFlagCount(DeviceName device);
    // void decrementDeviceEventFlagCount(DeviceName device);

private: 
    uint8_t taskTable[NUM_DEVICES];

};

#endif  //EVENTTASK_HPP
