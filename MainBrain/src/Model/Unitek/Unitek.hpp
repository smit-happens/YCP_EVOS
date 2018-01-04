/**  A one line description of the class.
 *
 * #include Unitek.hpp
 * Created 09-30-17 By: Smitty
 *
 * A longer description.
 */

#ifndef UNITEK_HPP
#define UNITEK_HPP

#include <Arduino.h>
#include "UnitekRegisters.hpp"



class Unitek
{
public:
    Unitek(void);

    int getRpmLimit(void);  //All these get..() functions might be combined into a struct or something in the future
    int getMaxValue(void);

    int getSpeedValue(void);
    void setSpeedValue(int userSpeedVal);

    float getTemperature(void); //TODO: handle the different temperature registers

    uint16_t getWarnings(void);
    uint16_t getErrors(void);

    //FIXME: any get...() method that returns void, needs to have work done on its return type
    void getDigitalPort(void);  //TODO: create struct for the connections in the digital port
    void setDigitalPort(void);  //TODO: Modify for whatever implimentation of the digital port


    int PrechargeStart(void);
    int PrechargeDone(void);

    int driveStart(void);       //should throw an error based on any bad status from the Unitek
    int driveDone(void);        //for when the user doesn't want to completely shut off the car

    void pollingStart(void);
    void pollingStop(void);


    private:
        const int RPM_LIMIT = 7000; //0xC8
        const int MAX_VALUE = 32767;  //0x7FFF

};


#endif  //UNITEK_HPP
