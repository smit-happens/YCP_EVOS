/**  Flags that represent various functions of the car's operation
 *
 * #include "Flags.hpp"
 * Created 03-18-18  By: Smitty
 *
 * A longer description.
 */

#ifndef FLAGS_HPP
#define FLAGS_HPP

#include <Arduino.h>


//General Event Flags for devices
const uint32_t EF_TIMER             = 0b1;   //The first event flag (EF) mask
const uint32_t EF_CAN               = 0b10;  //CAN EF mask
const uint32_t EF_COOLING           = 0b100;  //cooling EF mask
const uint32_t EF_DASH              = 0b1000;  //dash EF mask
const uint32_t EF_IMD               = 0b10000;  //Imd EF mask
const uint32_t EF_ORION             = 0b100000;  //Orion EF mask
const uint32_t EF_UNITEK            = 0b1000000;  //Unitek EF mask
const uint32_t EF_BATLOG            = 0b10000000;  //BatLog EF mask
const uint32_t EF_SHUTDOWN          = 0b100000000;  //Shutdown EF mask

//Timer flags (the equivalent of an event flag but triggered by a timer)
const uint32_t TIMER_F_GLCD         = 0b1 << 16;  //Glcd Timer mask
const uint32_t TIMER_F_SDCARD       = 0b10 << 16;  //SdCard Timer mask
const uint32_t TIMER_F_PEDAL        = 0b100 << 16;  //Pedal Timer mask
const uint32_t TIMER_F_ORION        = 0b1000 << 16;  //Orion Timer mask NOTE: this is for the temperature & charge checking on the HV batteries


//task flags (TF) for specific tasks a device can do
//TF for Dash
const uint8_t TF_DASH_PRECHARGE     = 0b1;
const uint8_t TF_DASH_RTD           = 0b10;
const uint8_t TF_DASH_SHUTDOWN      = 0b100;
const uint8_t TF_DASH_STANDBY       = 0b1000;
const uint8_t TF_DASH_WAYNE_WORLD   = 0b10000;
const uint8_t TF_DASH_ENCODER       = 0b100000;

//TF for CAN
const uint8_t TF_CAN_NEW_MAIL    = 0b1;
const uint8_t TF_CAN_SEND_PEDAL  = 0b10;

//TF for Unitek
const uint8_t TF_UNITEK_DONE_PRECHARGE  = 0b1;

//TF for Orion
const uint8_t TF_ORION_ERROR  = 0b1;


//as of right now, we have 4 levels of priority
//CRITICAL will be reserved for situations where the car had a critical error and needs to shut down
//HIGH, MEDIUM, LOW will be the various levels of importance of the various tasks, with safety having highest priority
enum Priority
{
    PRIORITY_CRITICAL,
    PRIORITY_HIGH,
    PRIORITY_MEDIUM,
    PRIORITY_LOW,
    NUM_PRIORITY
};


//this enum is used as an index in the lookup table and specifies each device for the car
enum DeviceName
{
    CAN,
    COOLING,
    DASH,
    GLCD,
    ORION,
    SDCARD,
    UNITEK,
    NUM_DEVICES //The number of devices, MAINTAIN AT END OF ENUM
};

#endif //FLAGS_HPP