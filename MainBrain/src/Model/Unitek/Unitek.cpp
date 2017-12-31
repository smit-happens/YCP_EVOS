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

}


/** 
 * @brief  RPM limit defined by the drivetrain subteam
 * @note   This will stay in the model b/c it can be modified
 * @retval Current RPM limit
 */
int Unitek::getRpmLimit(void)
{
    return RPM_LIMIT;
}


/** 
 * @brief  Max value is used in reference to speed % converting
 * @note   This might get shoved into the constants file since it won't change
 * @retval The maximum value in the Unitek (32,767)
 */
int Unitek::getMaxValue(void)
{
    return MAX_VALUE;
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
 * @brief  Handles the retrieval of the temperature and conversion to celsius
 * @note   TODO: handle the different temperature registers
 * @retval Temperature (in celcius) of the requested component in the Unitek
 */
float Unitek::getTemperature(void)
{
    return 0.0;
}


/** 
 * @brief  Retrieves the Warning bits in the combined error/warning register
 * @note   TODO: Call the same register as the getErrors() function but store different bits
 * @retval Warning bits
 */
uint16_t Unitek::getWarnings(void)
{
    return 0;
}


/** 
 * @brief  Retrieves the Error bits in the combined error/warning register
 * @note   TODO: Call the same register as the getErrors() function but store different bits
 * @retval Error bits
 */
uint16_t Unitek::getErrors(void)
{
    return 0;
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


/** 
 * @brief  
 * @note   TODO: implement this, aka partition out the CAN methods from MC data
 * @param  regID: 
 * @param  buf1: 
 * @param  buf2: 
 * @retval 
 */
int Unitek::setupCan(uint8_t regID, uint8_t buf1, uint8_t buf2)
{
    uint8_t extendedCan = 0;
    uint8_t idCan = 0x201;
    uint8_t lengthCan = 3;

    uint8_t buffer[3];

    if(regID == REG_READ)
    {
        //performing a read operation set buf[0] to READ command
        buffer[0] = REG_READ;
        buffer[1] = buf1;

        //default is 0 but can represent time (in ms) for polling
        buffer[2] = buf2;
    }
    else
    {
        //performing write opration
        buffer[0] = regID;

        //storing the value in byte flipped order
        buffer[2] = buf1;
        buffer[1] = buf2;
    }

    return 0;
}


