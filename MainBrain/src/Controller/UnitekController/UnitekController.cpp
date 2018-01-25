/**  Operates the logic around controlling the Unitek motor controller
 *
 * UnitekController.cpp
 * Created 12-23-17  By: Smitty
 *
 * A longer description.
 */

#include "UnitekController.hpp"
#include "../ControllerManager/ControllerManager.hpp"


/** 
 * @brief  UnitekController constructor
 */
UnitekController::UnitekController(void)
{
    unitekModel = new Unitek();
}


/** 
 * @brief  UnitekController destructor
 * @note   Delete any instantiated varibles/objects
 * @retval None
 */
UnitekController::~UnitekController(void)
{
    delete unitekModel;
}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void UnitekController::init(void)
{
    //FIXME: TESTING CODE
    uint16_t temp = 0b1101'0000'0000'0000;
    unitekModel->setErrors(temp);
    Serial.print("Error / Warning bits: ");
    Serial.print(unitekModel->getErrors().errorBits.badParam);
    //FIXME: TESTING CODE
}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void UnitekController::poll(void)
{

}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void UnitekController::shutdown(void)
{
    
}


/** 
 * @brief  Convert RPM to a compatible MC speed value
 * @note   The speed value represents a percentage from 0 to 0x7FFF
 *         That percentage represents the RPM from 0 to RPM_LIMIT (Ex: 7000)
 * @param  rpm: RPM value
 * @retval      Speed value for the MC
 */
int UnitekController::calculateSpeedValue(float rpm)
{
    float percentage = rpm / unitekModel->getRpmLimit();
    return percentage * unitekModel->MAX_VALUE;
}


/** 
 * @brief  Convert a given MC speed value to RPM
 * @note   
 * @param  speedValue: Given from MC
 * @retval             RPM value
 */
float UnitekController::calculateRpm(int speedValue)
{
    float percentage = (float)speedValue / unitekModel->MAX_VALUE;
    return percentage * unitekModel->getRpmLimit();
}
