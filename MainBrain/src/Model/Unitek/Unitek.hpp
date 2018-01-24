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
    //this could be changed through CAN but for now it's just set here
    int rpmLimit;
    
    //correlates to REG_ERROR
    struct ErrorWarningReg
    {
        //section of the error/warning register that stores errors
        struct ErrorBits
        {
            uint8_t badParam        : 1;
            uint8_t powerFault      : 1;
            uint8_t rfeFault        : 1;
            uint8_t busTimeout      : 1;
            uint8_t feedback        : 1;
            uint8_t powerVoltage    : 1;
            uint8_t motorTemp       : 1;
            uint8_t deviceTemp      : 1;
            uint8_t overVoltage     : 1;
            uint8_t iPeak           : 1;
            uint8_t raceAway        : 1;
            uint8_t user            : 1;
            uint8_t i2R             : 1;
            uint8_t reserve         : 1;
            uint8_t hwFail          : 1;
            uint8_t ballast         : 1;
        };
        //section of the error/warning register that stores warnings
        struct WarningBits
        {
            uint8_t warning0        : 1;
            uint8_t illegalStatus   : 1;
            uint8_t warning2        : 1;
            uint8_t blankFields     : 2;
            uint8_t powerVoltage    : 1;
            uint8_t motorTemp       : 1;
            uint8_t deviceTemp      : 1;
            uint8_t overVoltage     : 1;
            uint8_t iPeak           : 1;
            uint8_t blankFields1    : 2;
            uint8_t i2R             : 1;
            uint8_t blankFields2    : 2;
            uint8_t ballast         : 1;
        };
    };

    //correlates to REG_DPORT for the states of the digital port
    struct ModeReg
    {
        uint8_t limit1      : 1;
        uint8_t limit2      : 1;
        uint8_t dIn1        : 1;
        uint8_t dIn2        : 1;
        uint8_t frgRun      : 1;
        uint8_t rfe         : 1;
        uint8_t blankFields : 2;
        uint8_t dOut1       : 1;
        uint8_t dOut2       : 1;
        uint8_t btb         : 1;
        uint8_t go          : 1;
        uint8_t dOut3       : 1;
        uint8_t dOut4       : 1;
        uint8_t brk1        : 1;
    };

    //Internal variables to store the data locally from the Unitek
    bool     runStatus;         //Lazy
    uint8_t  goStatus;          //Lazy
    uint16_t hvBusVoltage;      //Active
    uint16_t speedVal;          //Active
    uint16_t speedValRn;        //Active
    uint16_t tempMotor;         //Active
    uint16_t tempOutputStageMC; //Active
    uint16_t tempInteriorMC;    //Active

};


#endif  //UNITEK_HPP
