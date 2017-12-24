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
 * @brief  Max value is used in reference to speed % converting
 * @note   This might get shoved into the constants file since it won't change
 * @retval The maximum value in the Unitek (32,767)
 */
int Unitek::getMaxValue(void)
{
    return MAX_VALUE;
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
 * @brief  Handles the Precharging logic
 * @note   
 * @retval 0 for success, -1 for error
 */
int PrechargeStart(void)
{
    return 0;
}


// TODO: implement this, aka partition out the CAN methods from MC data
int Unitek::setupCan(uint8_t regID, uint8_t buf1, uint8_t buf2, bool polling)
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

        //deactivates polling
        if(polling)
        {
            buffer[2] = REG_HALTPOLL;
        }
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


int Unitek::parseCan()
{
  // uint canId = 0x181;
  return 0;
}
