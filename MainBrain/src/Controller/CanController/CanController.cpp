/**  Handles the logic around setting up and sending CAN messages
 *
 * CanController.cpp
 * Created 1-4-18  By: Smitty
 *
 * A longer description.
 */

#include "CanController.hpp"


/** 
 * @brief  CanController constructor
 */
CanController::CanController(void)
{

}


/** 
 * @brief  CanController destructor
 * @note   Delete any instantiated varibles/objects
 * @retval None
 */
CanController::~CanController(void)
{

}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void CanController::init(void)
{

}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void CanController::display(void)
{

}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void CanController::poll(void)
{

}


/** 
 * @brief  
 * @note   TODO: implement this the correct way
 * @param  regID: 
 * @param  buf1: 
 * @param  buf2: 
 * @retval 
 */
int CanController::messageSetup(uint8_t regID, uint8_t buf1, uint8_t buf2)
{
    uint8_t extendedCan = 0;
    uint16_t idCan = 0x201;
    uint8_t lengthCan = 3;

    uint8_t buffer[3];

    if(regID == 0)
    {
        //performing a read operation set buf[0] to READ command
        buffer[0] = 0;
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


/** 
 * @brief  
 * @note   TODO: Have this work for Unitek and Orion
 * @retval 
 */
int CanController::messageParse(void)
{
    return 0;
}