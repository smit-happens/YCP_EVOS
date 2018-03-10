/**  Pedal controller class
 *
 * PedalController.cpp
 * Created 1-17-17 By: Smitty
 *
 * A longer description.
 */

#include "PedalController.hpp"


//to see if the instance of the class has been initialized yet
PedalController* PedalController::_pInstance = NULL; 

/** 
 * @brief  Used to maintain the singleton format
 * @note   
 * @retval 
 */
PedalController* PedalController::getInstance()
{
    // Only allow one instance of class to be generated.
    if (!_pInstance)
        _pInstance = new PedalController();

    return _pInstance;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
PedalController::~PedalController(void)
{
    delete brakeModel;
    delete gasModel;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
void PedalController::init(void)
{
    brakeModel = new BrakePedal();
    gasModel = new GasPedal();
}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void PedalController::poll(void)
{

}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void PedalController::shutdown(void)
{
    
}


/** 
 * @brief  Retrieves the evaluated Gas percentage
 * @note   
 * @retval GasPedal percentage
 */
float PedalController::getPercentageGas(void)
{
    gasModel->update();
    float potValue=(float)gasModel->getLinValue();
    float rpmPercent=potValue/(float)1023;
    return rpmPercent;
}


/** 
 * @brief  Evaluates the two pedal potentiometers (Linear and Logarithmic)
 * @note   Needs to check for shorts in wire and extrainious values
 * @retval True if there's an implausibility found, false if not
 */
bool PedalController::isImplausibilityGas(void)
{
    return false;
}


/** 
 * @brief  Retrieves the evaluated Brake percentage
 * @note   Evaluate linear pedal potentiometer
 * @retval BrakePedal percentage
 */
float PedalController::getPercentageBrake(void)
{
    return 0.0;
}


/** 
 * @brief  Evaluates the brake pedal potentiometer
 * @note   Needs to check for shorts in wire and extrainious values
 * @retval True if there's an implausibility found, false if not
 */
bool PedalController::isImplausibilityBrake(void)
{
    return false;
}