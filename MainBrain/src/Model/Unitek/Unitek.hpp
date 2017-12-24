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


//TODO: Precharge pins (RFE, RTD, RUN)

class Unitek
{
public:
    Unitek(void);

    int getRpmLimit(void);  //All these get..() functions might be combined into a struct or something in the future
    int getMaxValue(void);

    int getSpeedValue(void);
    int setSpeedValue(void);

    float getTemperature(void); //TODO: handle the different temperature registers

    uint16_t getWarnings(void);
    uint16_t getErrors(void);

    //NOTE: any get...() method that returns void, needs to have work done on its return type
    void getDigitalPort(void);  //TODO: create struct for the connections in the digital port
    void setDigitalPort(void);  //Needs to be modified for whatever implimentation of the digital port


    void PrechargeStart(void);
    void PrechargeDone(void);

    void enableDrive(void);     //should throw an error based on any bad status from the Unitek

    void pollingStart(void);
    void pollingDone(void);


    //TODO: implement to construct CAN message
    int setupCan(uint8_t regID, uint8_t buf1, uint8_t buf2, bool polling);

    int parseCan(void);

    private:
        const int RPM_LIMIT = 7000; //0xC8
        const int MAX_VALUE = 32767;  //0x7FFF

};


#endif  //UNITEK_HPP
