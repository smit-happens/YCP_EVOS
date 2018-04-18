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

    //percent = (current pedal value - origin pedal value)/((2^13-1) - origin pedal value)
    // float percentageValue = ((float)gasModel->getRawValue() - (float)gasModel->getRawOrigin()) / (MAX_ANALOGREAD - (float)gasModel->getRawOrigin());    
    float percentageValue = ((float)gasModel->getRawValue()) / MAX_ANALOGREAD;

    //TODO: uncomment this stuff and fix this
    // char buf[30];           //output buffer for sprintf
    // sprintf(buf, "Bootup begin at %lu ms", bootStart);
    // loggerC->log("PEDAL", buf, MSG_LOG);

    //tolerance for gas pedal and handles brake pressed
    // if (percentageValue<=2 || PedalController::getPercentageBrake()>0){
    if (percentageValue <= 2)
    {
        percentageValue = 0;
    }

    return percentageValue; 
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
    brakeModel->update();

    float percentageValue = ((float)brakeModel->getRawValue()) / MAX_ANALOGREAD;

    if (percentageValue<=2)    //this number may need to be change on how the brake pot acts
    {
        percentageValue=0;
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
