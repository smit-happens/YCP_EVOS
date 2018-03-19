/**  A one line description of the class.
 *
 * Unitek.cpp
 * Created 09-30-17 By: Smitty
 *
 * A longer description.
 */

#include "Unitek.hpp"


/** 
 * @brief  Unitek constructor
 */
Unitek::Unitek(void)
{
    rpmLimitReg_C8 = 6600; //0x19C8
}


/** 
 * @brief  Unitek destructor
 */
Unitek::~Unitek(void)
{

}


/** 
 * @brief  
 * @note   TODO: implement
 * @retval None
 */
void Unitek::update(void)
{
    
}


/** 
 * @brief  RPM limit defined by the drivetrain subteam
 * @note   This will stay in the model b/c it can be modified
 * @retval Current RPM limit
 */
int Unitek::getRpmLimit(void)
{
    return rpmLimitReg_C8;
}


/** 
 * @brief  Retrieves the current speed value we will set in the MC
 * @note   Might be used in order to monitor speed setpoint versus actual speed
 * @retval Current speed value set in the Unitek MC
 */
uint16_t Unitek::getSpeedValueForUnitek(void)
{
    return speedCmdValBeforeRampReg_0x31;
}


/** 
 * @brief  Sets the speed value register in the Unitek, or throws an exception (due to CAN?)
 * @note   Affected by the GasPedal class
 * @param  userSpeedVal: Requested speed value to set in Unitek (calculated by calculateSpeedSetPoint in CanController)
 * @retval None
 */
void Unitek::setSpeedValueForUnitek(uint16_t userSpeedVal)
{
    speedCmdValBeforeRampReg_0x31=userSpeedVal;
}

/** 
 * @brief  gets the current speed value from the MC
 * @note   used to measure rpms of motor and display to dash
 * @retval returns current value stored in MC for actual RPM
 */
uint16_t Unitek::getSpeedValueFromUnitek(void)
{
    return speedValRnReg_0x30;
}

/** 
 * @brief   sets the current speed value that is gathered from the MC
 * @note   will be used once a can message is recieved from the MC with an RPM value
 * @param  recSpeedValue: received speed value from MC (must be converted to RPMs)
 * @retval None
 */
void Unitek::setSpeedValueFromUnitek(uint16_t recRpmSpeedValue)
{
    speedValRnReg_0x30=recRpmSpeedValue;
}


/** 
 * @brief  Retrieves temperature limit of the motor
 * @note   If the temperature of the motor goes above this, it triggers the 
 * @retval Temperature limit register value (in untitek resolution) set in the REG_MTEMPLIM
 */
uint16_t Unitek::getTemperatureMotorLimit(void)
{
    return tempLimitMotorReg_0xA3;
}


/** 
 * @brief  stores temp limit of the motor
 * @note   stored in unitek resolution
 * @param  tempMotorLimit: received motor temp limit from can
 * @retval 
 */
void Unitek::setTemperatureMotorLimit(uint16_t tempMotorLimit)
{
    tempLimitMotorReg_0xA3=tempMotorLimit;
}


/** 
 * @brief  Retrieves temperature of the motor and converts to celsius
 * @note   
 * @retval Temperature (in unitek resolution) of the Emrax motor
 */
uint16_t Unitek::getTemperatureMotor(void)
{
    return tempMotorReg_0x49;
}


/** 
 * @brief  stores motor temp value
 * @note   stores in unitek resolution
 * @param  tempMotor: temp of motor that would be recieved from CAN
 * @retval None
 */
void Unitek::setTemperatureMotor(uint16_t tempMotor)
{
    tempMotorReg_0x49=tempMotor;
}


/** 
 * @brief  Retrieves temperature of the output water
 * @note   TODO: Ask Alec if this does what I think it does
 * @retval Temperature (in unitek resolution) of the output water from the internal radiator (I think)
 */
uint16_t Unitek::getTemperatureOutputStage(void)
{
    return tempOutputStageMCReg_0x4A;
}


/** 
 * @brief  stores temp of output stage 
 * @note   stores in unitek resolution
 * @param  tempOutputStage: 
 * @retval None
 */
void Unitek::setTemperatureOutputStage(uint16_t tempOutputStage)
{
    tempOutputStageMCReg_0x4A=tempOutputStage;
}


/** 
 * @brief  Retrieves temperature of the Unitek internals 
 * @note   
 * @retval Temperature (in unitek resolution) of the internals of the Unitek
 */
uint16_t Unitek::getTemperatureInterior(void)
{
    return tempInteriorMCReg_0x4B;
}


/** 
 * @brief  stores temperature of unitek internals
 * @note   stores in unitek resolution
 * @param  tempInterior: internal temp resturned from MC via CAN
 * @retval None
 */
void Unitek::setTemperatureInterior(uint16_t tempInterior)
{
    tempInteriorMCReg_0x4B=tempInterior
}

/** 
 * @brief  gets current hv bus measurement
 * @note   this is in Unitek resolution (0-32767)
 * @retval current HV voltage
 */
uint16_t Unitek::getVoltageHvBus(void)
{
    return hvBusVoltageReg_0xEB;
}

/** 
 * @brief  sets new voltage of HV bus
 * @note   this is in unitek resolution (0-32767)
 * @param  hvBusVoltage: new HV bus value returned from CAN
 * @retval 
 */
void Unitek::setVoltageHvBus(uint16_t hvBusVoltage)
{
    hvBusVoltageReg_0xEB=hvBusVoltage;
}


/** 
 * @brief  Retrieves the stored Error bits in the combined error/warning register
 * @note   
 * @retval ErrorReg_0x8F
 */
ErrorReg_0x8F Unitek::getErrorReg_0x8F(void)
{
    return errorReg_0x8F;
}


/** 
 * @brief  Stores the given Error bits in the error section of the error/warning register
 * @note   
 * @param  input: uint16_t containing the error bits
 * @retval None
 */
void Unitek::setErrorReg_0x8F(uint16_t input)
{
    errorReg_0x8F.raw = input;
}


/** 
 * @brief  Retrieves the Warning bits in the combined error/warning register
 * @note   
 * @retval WarningReg_0x8F
 */
WarningReg_0x8F Unitek::getWarningReg_0x8F(void)
{
    return warningReg_0x8F;
}


/** 
 * @brief  Stores the given Warning bits in the warning section of the error/warning register
 * @note   
 * @param  input: 
 * @retval None
 */
void Unitek::setWarningReg_0x8F(uint16_t input)
{
    warningReg_0x8F.raw = input;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
StateReg_0x40 Unitek::getStateReg_0x40(void)
{
    return stateReg_0x40;
}


/** 
 * @brief  
 * @note   
 * @param  input: 32bit value representing the State bits
 * @retval None
 */
void Unitek::setStateReg_0x40(uint32_t input)
{
    stateReg_0x40.raw = input;
}


/** 
 * @brief  
 * @note   
 * @retval ModeReg_0xD8
 */
ModeReg_0xD8 Unitek::getModeReg_0xD8(void)
{
    return modeReg_0xD8;
}


/** 
 * @brief  
 * @note   
 * @param  input:  16bit value representing bits in the Mode register
 * @retval None
 */
void Unitek::setModeReg_0xD8(uint16_t input)
{
    modeReg_0xD8.raw = input;
}


/** 
 * @brief  Retrieves the status of the in/output pins on the digital connection to the Unitek MC
 * @note   TODO: create struct for the connections in the digital port
 * @retval None
 */
void Unitek::getDigitalPort(void)
{

}


/** 
 * @brief  
 * @note   //TODO: Modify for whatever implimentation of the digital port
 * @retval None
 */
void Unitek::setDigitalPort(void)
{

}


/** 
 * @brief  Handles the Precharging logic
 * @note   Change return value to void and throw exceptions that the calling function would have to handle
 * @retval Success or failure (1 or 0)
 */
int Unitek::PrechargeStart(void)
{
    return 0;
}


/** 
 * @brief  Called from rising edge interrupt on the DONE_PRE pin
 * @note   Success exception? If that even exists
 * @retval Success or failure (1 or 0)
 */
int Unitek::PrechargeDone(void)
{
    return 0;
}


/** 
 * @brief  Called when the RTD_BTN is pressed and all the checks pass
 * @note   TODO: Figure out the calling functions for this method (btn? Controller?)
 * @retval Success or failure (1 or 0)
 */
int Unitek::driveStart(void)
{
    return 0;
}


/** 
 * @brief  Take the car from drive to idle state
 * @note   This will most likely be one of the last things we work on
 * @retval Success or failure (1 or 0)
 */
int Unitek::driveDone(void)
{
    return 0;
}


/** 
 * @brief  Initiates the polling of a certain register in the Unitek
 * @note   TODO: Have to figure out form of input (register & polling period?)
 * @retval None
 */
void Unitek::pollingStart(void)
{

}


/** 
 * @brief  Stops the polling of a certain register in the Unitek
 * @note   TODO: Throw exception if the register to stop polling isn't polling?
 * @retval None
 */
void Unitek::pollingStop(void)
{

}
