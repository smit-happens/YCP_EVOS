/**  LightController manages all the lights and light states
 *
 * LightController.cpp
 * Created 2-25-18 By: Smitty
 *
 * A longer description.
 */

#include "LightController.hpp"


//to see if the instance of the class has been initialized yet
LightController* LightController::_pInstance = NULL; 

/** 
 * @brief  Used to maintain the singleton format
 * @note   
 * @retval 
 */
LightController* LightController::getInstance()
{
    // Only allow one instance of class to be generated.
    if (!_pInstance)
        _pInstance = new LightController();

    return _pInstance;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
LightController::~LightController(void)
{
    for(int lightIterator = 0; lightIterator < LightId::NUM_LIGHTS; lightIterator++)
        delete lights[lightIterator];
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
void LightController::init(void)
{
    //initializing all the lights on the car
    lights[LIGHT_RTD]         = new Light(MB_RTD_LED);
    lights[LIGHT_ERR_BMS]     = new Light(MB_BMS_LED);
    lights[LIGHT_ERR_PEDAL]   = new Light(MB_PEDAL_LED);
    lights[LIGHT_ERR_IMD]     = new Light(MB_IMD_LED);
    lights[LIGHT_REVERSE]     = new Light(MB_REVERSE_LED);
    lights[LIGHT_WAYNE]       = new Light(MB_WAYNE_LED);
    lights[LIGHT_ENERGIZE]    = new Light(MB_ENERGIZE_LED);
    lights[LIGHT_BRAKE]       = new Light(MB_BRAKE_LIGHT);
}


/** 
 * @brief  Turns on all the lights on the Dash
 * @note   
 * @retval None
 */
void LightController::turnAllOn(void)
{
    for(int lightIterator = 0; lightIterator < LightId::NUM_LIGHTS; lightIterator++)
        lights[lightIterator]->turnOn();
}


/** 
 * @brief  Turns off all the lights on the Dash
 * @note   
 * @retval None
 */
void LightController::turnAllOff(void)
{
    for(int lightIterator = 0; lightIterator < LightId::NUM_LIGHTS; lightIterator++)
        lights[lightIterator]->turnOff();
}


/** 
 * @brief  On shutdown, we want the error lights to stay on (if any were triggered)
 * @note   
 * @retval 
 */
void LightController::turnNonErrorOff(void)
{
    lights[LIGHT_RTD]->turnOff();
    lights[LIGHT_REVERSE]->turnOff();
    lights[LIGHT_WAYNE]->turnOff();
    lights[LIGHT_ENERGIZE]->turnOff();
    lights[LIGHT_BRAKE]->turnOff();
}

/** 
 * @brief  Turns off a specific light
 * @note   
 * @param  lightChoice: 
 * @retval None
 */
void LightController::turnOn(LightId lightChoice)
{
    lights[lightChoice]->turnOn();
}


/** 
 * @brief  Turns off a specific light
 * @note   
 * @param  lightChoice: 
 * @retval None
 */
void LightController::turnOff(LightId lightChoice)
{
    lights[lightChoice]->turnOff();
}


void LightController::test(void)
{
    //make sure the lights are off first, just in case
    turnAllOff();

    //record the current time in milliseconds
    uint32_t currentTime = millis();

    //turn all the lights on
    turnAllOn();

    //wait for 2 seconds
    while((millis() - currentTime) < TIME_LIGHT)
    {
        ;
    }

    turnAllOff();

}