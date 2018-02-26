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
#include "../Constants/RegistersUnitek.hpp"


//Bits in the error/warning register that store errors
struct ErrorBits
{
    uint8_t BadParam        : 1;    //bit 0
    uint8_t PowerFault      : 1;
    uint8_t RfeFault        : 1;
    uint8_t BusTimeout      : 1;
    uint8_t Feedback        : 1;
    uint8_t PowerVoltage    : 1;
    uint8_t MotorTemp       : 1;
    uint8_t DeviceTemp      : 1;
    uint8_t OverVoltage     : 1;
    uint8_t IPeak           : 1;
    uint8_t RaceAway        : 1;
    uint8_t User            : 1;
    uint8_t I2R             : 1;
    uint8_t Reserve         : 1;
    uint8_t HwFail          : 1;
    uint8_t Ballast         : 1;    //bit 15
};


//Bits in the error/warning register that store warnings
struct WarningBits
{
    uint8_t Warning0        : 1;    //bit 0
    uint8_t IllegalStatus   : 1;
    uint8_t Warning2        : 1;
    uint8_t                 : 2;    //unlabelled bits in the register
    uint8_t PowerVoltage    : 1;
    uint8_t MotorTemp       : 1;
    uint8_t DeviceTemp      : 1;
    uint8_t OverVoltage     : 1;
    uint8_t IPeak           : 1;
    uint8_t                 : 2;    //unlabelled bits in the register
    uint8_t I2R             : 1;
    uint8_t                 : 2;    //unlabelled bits in the register
    uint8_t Ballast         : 1;    //bit 15
};


//represents bits in REG_STATE
struct StateBits
{
    uint8_t Ena             : 1;    //bit 0
    uint8_t NcR0            : 1;
    uint8_t LimPlus         : 1;
    uint8_t LimMinus        : 1;
    uint8_t Ok              : 1;
    uint8_t Icns            : 1;
    uint8_t T_Nlim          : 1;
    uint8_t P_N             : 1;
    uint8_t N_I             : 1;
    uint8_t LessThanPt1     : 1;
    uint8_t Rsw             : 1;
    uint8_t Cal0            : 1;
    uint8_t Cal             : 1;
    uint8_t Tol             : 1;
    uint8_t Rdy             : 1;
    uint8_t Brk             : 1;
    uint8_t SignMag         : 1;
    uint8_t Nclip           : 1;
    uint8_t NclipPlus       : 1;
    uint8_t NclipMinus      : 1;
    uint8_t Ird_Dig         : 1;
    uint8_t Iuse_rched      : 1;
    uint8_t Ird_N           : 1;
    uint8_t Ird_Ti          : 1;
    uint8_t Ird_Tir         : 1;
    uint8_t lessThan2Hz     : 1;
    uint8_t Ird_Tm          : 1;
    uint8_t Ird_Ana         : 1;
    uint8_t Iwcns           : 1;
    uint8_t Rfe_Pulse       : 1;
    uint8_t Vacant          : 1;
    uint8_t HndWhl          : 1;   //bit 31
};


//correlates to REG_DPORT for the states of the digital port
struct ModeBits
{
    uint8_t Limit1          : 1;    //bit 0
    uint8_t Limit2          : 1;
    uint8_t DIn1            : 1;
    uint8_t DIn2            : 1;
    uint8_t FrgRun          : 1;
    uint8_t Rfe             : 1;
    uint8_t                 : 2;    //unlabelled bits in the register
    uint8_t DOut1           : 1;
    uint8_t DOut2           : 1;
    uint8_t Btb             : 1;
    uint8_t Go              : 1;
    uint8_t DOut3           : 1;
    uint8_t DOut4           : 1;
    uint8_t Brk1            : 1;    //bit 15
};


//correlates to lower byte in REG_ERROR
typedef union
{
    //section of the error/warning register that stores errors
    uint16_t raw;
    struct ErrorBits errorBits;

} ErrorReg_0x8F;


//correlates to upper byte in REG_ERROR
typedef union
{
    //section of the error/warning register that stores warnings
    uint16_t raw;
    struct WarningBits warningBits;
    
} WarningReg_0x8F;


typedef union
{
    //All 32 state register bits
    uint32_t raw;
    struct StateBits stateBits;
    
} StateReg_0x40;


typedef union
{
    //16 bit mode register represents the outputs of the digital port on the MC
    uint16_t raw;
    struct ModeBits modeBits;
    
} ModeReg_0xD8;


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

    ErrorReg_0x8F getErrorReg_0x8F(void);
    void setErrorReg_0x8F(uint16_t input);

    WarningReg_0x8F getWarningReg_0x8F(void);
    void setWarningReg_0x8F(uint16_t input);

    StateReg_0x40 getStateReg_0x40(void);
    void setStateReg_0x40(uint32_t input);

    ModeReg_0xD8 getModeReg_0xD8(void);
    void setModeReg_0xD8(uint16_t input);

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
    
    //internal variables that are segmented in order to address the individual bits of their register
    ErrorReg_0x8F   errorReg_0x8F;
    WarningReg_0x8F warningReg_0x8F;
    StateReg_0x40   stateReg_0x40;
    ModeReg_0xD8    modeReg_0xD8;


    //Internal variables to store the data locally from the Unitek
    bool     I_RunReg_0xE8;                 //Lazy
    uint8_t  goStatusReg_0xE3;              //Lazy
    uint16_t hvBusVoltageReg_0xEB;          //Active
    uint16_t speedCmdValBeforeRampReg_0x31; //Active
    uint16_t speedValRnReg_0x30;            //Active
    uint16_t tempMotorReg_0x49;             //Active
    uint16_t tempOutputStageMCReg_0x4A;     //Active
    uint16_t tempInteriorMCReg_0x4B;        //Active

};


#endif  //UNITEK_HPP
