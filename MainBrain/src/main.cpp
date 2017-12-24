/**  A one line description of the class.
 *
 * main.cpp
 * Created 11-06-17 By: Smitty
 *
 * A longer description.
 */

// Testing unit Testing
#ifndef UNIT_TEST

#include <Arduino.h>
// #include <Encoder.h>     //TODO: Figure out if we're using this or not

#include "Model/Model.hpp"


//---------------------------------------------------------------
// Begin main function
int main(void)
{
    // Serial.begin(9600);

    // Object declarations
    // Unitek mctest;


    // using the builtin LED as a status light
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWriteFast(LED_BUILTIN, 1);


    //---------------------------------------------------------------
    // Begin main program loop
    while(1)
    {
        //TODO: Finish the startup state (Startup class?)
        //Teensy SelfTest     //What would this even be?
        //SD card initialize
        //subsystem checks (log status of each)
            //Dashboard
            //LCD (boot logo)
            //TS master switch through BMS/BSPD
            //Orion
            //Unitek
            //Cooling system
            //Alert: Turn cooling on
        //Notification: All systens go. Ready to Precharge
    }

    return 0;
}

#endif
