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
 * @brief  PedalController Deconstructor
 * @note   
 * @retval none
 */
PedalController::~PedalController(void)
{
    delete brakeModel;
    delete gasModel;
}


/** 
 * @brief  
 * @note   
 * @retval none
 */
void PedalController::init(void)
{
    // Initialize models
    brakeModel = new BrakePedal();
    gasModel = new GasPedal();

    // Determine resting position of gas pedal
    //gasModel->setOrigin;
    gasModel->setOrigin();
    gasOrigin = getOriginGas();


}


/** 
 * @brief  Read new values for brake and gas
 * @note   
 * @retval None
 */
void PedalController::poll(void)
{
    gasModel->update();
    brakeModel->update();
}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void PedalController::shutdown(void)
{
    //TODO: Implement
}


/** 
 * @brief  Retrieves the evaluated Gas percentage
 * @note   Values returned depend on the Analog Read Resolution being 13 bits!!
 * @retval GasPedal percentage
 */
float PedalController::getPercentageGas(void)
{
    gasModel->update();
    uint16_t linValue = gasModel->getLinValue();
    float rpmPercent=float(linValue)/(float)8191;   //8191 is 2^13-1 or resolution of analog read once changed to 13 bits
    return rpmPercent;
}


/** 
 * @brief  Evaluates the two pedal potentiometers (Linear and Logarithmic)
 * @note   Needs to check for shorts in wire and extrainious values
 * @retval True if there's an implausibility found, false if not
 */
bool PedalController::isImplausibilityGas(void)
{
    return false;   // TODO: Implement
}


/** 
 * @brief  Retrieves the evaluated Brake percentage
 * @note   Evaluate linear pedal potentiometer
 * @retval BrakePedal percentage
 */
float PedalController::getPercentageBrake(void)
{
    return 0.0; //TODO: Implement
}


/** 
 * @brief  Evaluates the brake pedal potentiometer
 * @note   Needs to check for shorts in wire and extrainious values
 * @retval True if there's an implausibility found, false if not
 */
bool PedalController::isImplausibilityBrake(void)
{
    return false;   //TODO: Implement
}


/** 
 * @brief  Executed once to calculate the origin of the gas pedal in percent
 * @note   getPercentageGas() calculates the pedal position and subtracts the origin calculated here
 * @retval origin value of the gas pedal in percent
 */
float PedalController::getOriginGas() {
    uint16_t gasLinOrigin = gasModel->getLinOrigin();
    uint16_t gasLogOrigin = gasModel->getLogOrigin();



    return 0.0; //TODO: Implement
}