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
    const int MAX_VALUE = 32767;  //0x7FFF

    Unitek(void);

    int getRpmLimit(void);

    int getSpeedValue(void);
    void setSpeedValue(int userSpeedVal);

    float getTemperatureMotorLimit(void);   //These functions might require a convertToCelsius() funct
    float getTemperatureMotor(void);
    float getTemperatureOutputStage(void);
    float getTemperatureInterior(void);

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
    int rpmLimit;

};


#endif  //UNITEK_HPP
