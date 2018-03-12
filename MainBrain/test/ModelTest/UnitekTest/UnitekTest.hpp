/**  A one line description of the class.
 *
 * #include UnitekTest.hpp
 * Created 10-24-17 By: Smitty
 *
 * A longer description.
 */

#ifndef UNITEKTEST_HPP
#define UNITEKTEST_HPP

#include "../BaseModelTest/BaseModelTest.hpp"
#include "../Constants/RegistersUnitek.hpp"


class UnitekTest : public BaseModelTest
{
public:
    UnitekTest(void);
    ~UnitekTest(void);

    void update(void);

    int getRpmLimit(void);

    int getSpeedValue(void);
    void setSpeedValue(int userSpeedVal);

    float getTemperatureMotorLimit(void);   //These functions might require a convertToCelsius() funct
    float getTemperatureMotor(void);
    float getTemperatureOutputStage(void);
    float getTemperatureInterior(void);

    // ErrorReg_0x8F getErrorReg_0x8F(void);
    // void setErrorReg_0x8F(uint16_t input);

    // WarningReg_0x8F getWarningReg_0x8F(void);
    // void setWarningReg_0x8F(uint16_t input);

    // StateReg_0x40 getStateReg_0x40(void);
    // void setStateReg_0x40(uint32_t input);

    // ModeReg_0xD8 getModeReg_0xD8(void);
    // void setModeReg_0xD8(uint16_t input);

    //FIXME: any get...() method that returns void, needs to have work done on its return type
    void getDigitalPort(void);  //TODO: create struct for the connections in the digital port
    void setDigitalPort(void);  //TODO: Modify for whatever implimentation of the digital port


    int PrechargeStart(void);
    int PrechargeDone(void);

    int driveStart(void);       //should throw an error based on any bad status from the UnitekTest
    int driveDone(void);        //for when the user doesn't want to completely shut off the car

    void pollingStart(void);
    void pollingStop(void);

private:
    //this could be changed through CAN but for now it's just set here
    int rpmLimitReg_C8;
    
    //internal variables that are segmented in order to address the individual bits of their register
    // ErrorReg_0x8F   errorReg_0x8F;
    // WarningReg_0x8F warningReg_0x8F;
    // StateReg_0x40   stateReg_0x40;
    // ModeReg_0xD8    modeReg_0xD8;


    //Internal variables to store the data locally from the UnitekTest
    bool     I_RunReg_0xE8;                 //Lazy
    uint8_t  goStatusReg_0xE3;              //Lazy
    uint16_t hvBusVoltageReg_0xEB;          //Active
    uint16_t speedCmdValBeforeRampReg_0x31; //Active
    uint16_t speedValRnReg_0x30;            //Active
    uint16_t tempMotorReg_0x49;             //Active
    uint16_t tempOutputStageMCReg_0x4A;     //Active
    uint16_t tempInteriorMCReg_0x4B;        //Active

};


#endif  //UNITEKTEST_HPP
