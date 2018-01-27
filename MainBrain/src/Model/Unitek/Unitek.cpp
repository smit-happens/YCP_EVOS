/**  A one line description of the class.
 *
 * Unitek.cpp
 * Created 09-30-17 By: Smitty
 *
 * A longer description.
 */

#include "Unitek.hpp"

//TODO: separate this into the Unitek model and Unitek controller classes

/** 
 * @brief  Unitek constructor
 */
Unitek::Unitek(void)
{
    rpmLimit = 7000; //0xC8
}


/** 
 * @brief  RPM limit defined by the drivetrain subteam
 * @note   This will stay in the model b/c it can be modified
 * @retval Current RPM limit
 */
int Unitek::getRpmLimit(void)
{
    return rpmLimit;
}


/** 
 * @brief  Retrieves the current speed value set in the Unitek MC
 * @note   Might get called after setting the speed value as a confirmation step
 * @retval Current speed value set in the Unitek MC
 */
int Unitek::getSpeedValue(void)
{
    return 0;
}


/** 
 * @brief  Sets the speed value register in the Unitek, or throws an exception (due to CAN?)
 * @note   Affected by the GasPedal class
 * @param  userSpeedVal: Requested speed value to set in Unitek
 * @retval None
 */
void Unitek::setSpeedValue(int userSpeedVal)
{
    
}


/** 
 * @brief  Retrieves temperature limit of the motor and converts to celsius
 * @note   If the temperature of the motor goes above this, it triggers the 
 * @retval Temperature limit register value (in celcius) set in the REG_MTEMPLIM
 */
float Unitek::getTemperatureMotorLimit(void)
{
    return 0.0;
}


/** 
 * @brief  Retrieves temperature of the motor and converts to celsius
 * @note   
 * @retval Temperature (in celcius) of the Emrax motor
 */
float Unitek::getTemperatureMotor(void)
{
    return 0.0;
}


/** 
 * @brief  Retrieves temperature of the output water and converts to celsius
 * @note   TODO: Ask Alec if this does what I think it does
 * @retval Temperature (in celcius) of the output water from the internal radiator (I think)
 */
float Unitek::getTemperatureOutputStage(void)
{
    return 0.0;
}


/** 
 * @brief  Retrieves temperature of the Unitek internals and converts to celsius
 * @note   
 * @retval Temperature (in celcius) of the internals of the Unitek
 */
float Unitek::getTemperatureInterior(void)
{
    return 0.0;
}


/** 
 * @brief  Retrieves the stored Error bits in the combined error/warning register
 * @note   
 * @retval Error bits
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
 * @retval Warning bits
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
