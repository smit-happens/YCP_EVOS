/**  A one line description of the class.
 *
 * UnitekTest.cpp
 * Created 10-24-17 By: Smitty
 *
 * A longer description.
 */

#include "UnitekTest.hpp"


/** 
 * @brief  UnitekTest constructor
 */
UnitekTest::UnitekTest(void)
{
    rpmLimitReg_C8 = 6600; //0x19C8
}


/** 
 * @brief  UnitekTest destructor
 */
UnitekTest::~UnitekTest(void)
{

}


/** 
 * @brief  
 * @note   TODO: implement
 * @retval None
 */
void UnitekTest::update(void)
{
    
}


/** 
 * @brief  RPM limit defined by the drivetrain subteam
 * @note   This will stay in the model b/c it can be modified
 * @retval Current RPM limit
 */
int UnitekTest::getRpmLimit(void)
{
    return rpmLimitReg_C8;
}


/** 
 * @brief  Retrieves the current speed value set in the UnitekTest MC
 * @note   Might get called after setting the speed value as a confirmation step
 * @retval Current speed value set in the UnitekTest MC
 */
int UnitekTest::getSpeedValue(void)
{
    return 0;
}


/** 
 * @brief  Sets the speed value register in the UnitekTest, or throws an exception (due to CAN?)
 * @note   Affected by the GasPedal class
 * @param  userSpeedVal: Requested speed value to set in UnitekTest
 * @retval None
 */
void UnitekTest::setSpeedValue(int userSpeedVal)
{
    
}


/** 
 * @brief  Retrieves temperature limit of the motor and converts to celsius
 * @note   If the temperature of the motor goes above this, it triggers the 
 * @retval Temperature limit register value (in celsius) set in the REG_MTEMPLIM
 */
float UnitekTest::getTemperatureMotorLimit(void)
{
    return 0.0;
}


/** 
 * @brief  Retrieves temperature of the motor and converts to celsius
 * @note   
 * @retval Temperature (in celsius) of the Emrax motor
 */
float UnitekTest::getTemperatureMotor(void)
{
    return 0.0;
}


/** 
 * @brief  Retrieves temperature of the output water and converts to celsius
 * @note   TODO: Ask Alec if this does what I think it does
 * @retval Temperature (in celsius) of the output water from the internal radiator (I think)
 */
float UnitekTest::getTemperatureOutputStage(void)
{
    return 0.0;
}


/** 
 * @brief  Retrieves temperature of the UnitekTest internals and converts to celsius
 * @note   
 * @retval Temperature (in celsius) of the internals of the UnitekTest
 */
float UnitekTest::getTemperatureInterior(void)
{
    return 0.0;
}


/** 
 * @brief  Retrieves the stored Error bits in the combined error/warning register
 * @note   
 * @retval ErrorReg_0x8F
 */
ErrorReg_0x8F UnitekTest::getErrorReg_0x8F(void)
{
    return errorReg_0x8F;
}


/** 
 * @brief  Stores the given Error bits in the error section of the error/warning register
 * @note   
 * @param  input: uint16_t containing the error bits
 * @retval None
 */
void UnitekTest::setErrorReg_0x8F(uint16_t input)
{
    errorReg_0x8F.raw = input;
}


/** 
 * @brief  Retrieves the Warning bits in the combined error/warning register
 * @note   
 * @retval WarningReg_0x8F
 */
WarningReg_0x8F UnitekTest::getWarningReg_0x8F(void)
{
    return warningReg_0x8F;
}


/** 
 * @brief  Stores the given Warning bits in the warning section of the error/warning register
 * @note   
 * @param  input: 
 * @retval None
 */
void UnitekTest::setWarningReg_0x8F(uint16_t input)
{
    warningReg_0x8F.raw = input;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
StateReg_0x40 UnitekTest::getStateReg_0x40(void)
{
    return stateReg_0x40;
}


/** 
 * @brief  
 * @note   
 * @param  input: 32bit value representing the State bits
 * @retval None
 */
void UnitekTest::setStateReg_0x40(uint32_t input)
{
    stateReg_0x40.raw = input;
}


/** 
 * @brief  
 * @note   
 * @retval ModeReg_0xD8
 */
ModeReg_0xD8 UnitekTest::getModeReg_0xD8(void)
{
    return modeReg_0xD8;
}


/** 
 * @brief  
 * @note   
 * @param  input:  16bit value representing bits in the Mode register
 * @retval None
 */
void UnitekTest::setModeReg_0xD8(uint16_t input)
{
    modeReg_0xD8.raw = input;
}


/** 
 * @brief  Retrieves the status of the in/output pins on the digital connection to the UnitekTest MC
 * @note   TODO: create struct for the connections in the digital port
 * @retval None
 */
void UnitekTest::getDigitalPort(void)
{

}


/** 
 * @brief  
 * @note   //TODO: Modify for whatever implimentation of the digital port
 * @retval None
 */
void UnitekTest::setDigitalPort(void)
{

}


/** 
 * @brief  Handles the Precharging logic
 * @note   Change return value to void and throw exceptions that the calling function would have to handle
 * @retval Success or failure (1 or 0)
 */
int UnitekTest::PrechargeStart(void)
{
    return 0;
}


/** 
 * @brief  Called from rising edge interrupt on the DONE_PRE pin
 * @note   Success exception? If that even exists
 * @retval Success or failure (1 or 0)
 */
int UnitekTest::PrechargeDone(void)
{
    return 0;
}


/** 
 * @brief  Called when the RTD_BTN is pressed and all the checks pass
 * @note   TODO: Figure out the calling functions for this method (btn? Controller?)
 * @retval Success or failure (1 or 0)
 */
int UnitekTest::driveStart(void)
{
    return 0;
}


/** 
 * @brief  Take the car from drive to idle state
 * @note   This will most likely be one of the last things we work on
 * @retval Success or failure (1 or 0)
 */
int UnitekTest::driveDone(void)
{
    return 0;
}


/** 
 * @brief  Initiates the polling of a certain register in the UnitekTest
 * @note   TODO: Have to figure out form of input (register & polling period?)
 * @retval None
 */
void UnitekTest::pollingStart(void)
{

}


/** 
 * @brief  Stops the polling of a certain register in the UnitekTest
 * @note   TODO: Throw exception if the register to stop polling isn't polling?
 * @retval None
 */
void UnitekTest::pollingStop(void)
{

}
