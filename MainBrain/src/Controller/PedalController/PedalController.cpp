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
    delete gasBuffer;
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
    gasBuffer = new IntQueue(10);   //buffer of size 10
    brakeBuffer = new IntQueue(10);   //buffer of size 10

    // Determine resting position of pedals
    gasModel->setRawOrigin();
    brakeModel->setRawOrigin();
}


/** 
 * @brief  Read new values for brake and gas
 * @note   
 * @retval None
 */
void PedalController::poll(void)
{
    brakeModel->update();
    gasModel->update();
    gasBuffer->enqueue(gasModel->getRawValue());
    brakeBuffer->enqueue(brakeModel->getRawValue());
}


/** 
 * @brief  Retrieves the evaluated Gas percentage
 * @note   Values returned depend on the Analog Read Resolution being 13 bits!!
 * @retval GasPedal percentage (0.0 to 1.0)
 */
float PedalController::getPercentageGas(void)
{
    //calculate moving average
    float averageValue = (float)gasBuffer->getAverage();

    float percentageValue = (averageValue / (float)MAX_GAS_PEDAL);

    //tolerance for gas pedal and handles brake pressed
    if (percentageValue < 0.03 || getPercentageBrake() > 0)
    {
        percentageValue = 0;
    }

    return percentageValue; 
}


uint16_t PedalController::getRawGas(void)
{
    return gasModel->getRawValue(); 
}


/** 
 * @brief  Evaluates the two pedal potentiometers (Linear and Logarithmic)
 * @note   Needs to check for shorts in wire and extrainious values
 * @retval True if there's an implausibility found, false if not
 */
bool PedalController::isImplausibilityGas(void)
{
    /* Three implausibility conditions:
        1. Signal shorted to GND (signal < minValue)
        2. Signal shorted to Vcc (signal > maxValue)
        3. Potentiometer disconnected (signal < minValue)
    */
    
    return false;   // TODO: Implement
}


/** 
 * @brief  Retrieves the evaluated Brake percentage
 * @note   Evaluate linear pedal potentiometer
 * @retval BrakePedal percentage
 */
float PedalController::getPercentageBrake(void)
{
    //calculate moving average
    float averageValue = (float)brakeBuffer->getAverage();

    float percentageValue = (averageValue / (float)MAX_BRAKE_PEDAL);

    if (percentageValue < BRAKE_LIGHT_PERCENT)    //this number may need to be change on how the brake pot acts
    {
        percentageValue = 0;
    }

    return percentageValue; 
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
 * @brief  handles turning on/off the brake light
 * @note   
 * @retval None
 */
void PedalController::CheckBrakeLight(void)
{
    //checks if the brake pedal has been pressed far enough to turn on the brake light
    if(getPercentageBrake() > BRAKE_LIGHT_PERCENT)
        LightController::getInstance()->turnOn(LightController::LIGHT_BRAKE);
    else
        LightController::getInstance()->turnOff(LightController::LIGHT_BRAKE);
}