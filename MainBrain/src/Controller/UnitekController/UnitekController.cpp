/**  Operates the logic around controlling the Unitek motor controller
 *
 * UnitekController.cpp
 * Created 12-23-17  By: Smitty
 *
 * A longer description.
 */

#include "UnitekController.hpp"


//to see if the instance of the class has been initialized yet
UnitekController* UnitekController::_pInstance = NULL; 

/** 
 * @brief  Used to maintain the singleton format
 * @note   
 * @retval 
 */
UnitekController* UnitekController::getInstance()
{
    // Only allow one instance of class to be generated.
    if (!_pInstance)
        _pInstance = new UnitekController();

    return _pInstance;
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
    unitekModel = new Unitek();
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

/** 
 * @brief  calculate numeric speed value to send to the MC
 * @note   percent will be calculate by getPercentageGas() in PedalController
 * @param  percent: is the gas pedal percentage pressed
 * @retval 16 bit value that will be sent over CAN to control motor
 */
uint16_t UnitekController::calculateSpeedSetPoint(float percent)
{
    float rpmSetPoint=(float)32767*percent;
    return (int)rpmSetPoint;
}
