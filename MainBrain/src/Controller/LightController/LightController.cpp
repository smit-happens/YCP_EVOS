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
    lights[RTD]         = new Light(MB_RTD_LED);
    lights[ERR_BMS]     = new Light(MB_BMS_LED);
    lights[ERR_Pedal]   = new Light(MB_PEDAL_LED);
    lights[ERR_Imd]     = new Light(MB_IMD_LED);
    lights[REVERSE]     = new Light(MB_REVERSE_LED);
    lights[WAYNE]       = new Light(MB_WAYNE_LED);
    lights[ENERGIZE]    = new Light(MB_ENERGIZE_LED);
    lights[BRAKE]       = new Light(MB_BRAKE_LIGHT);
}

void LightController::turnAllOn(void)
{
    for(int lightIterator = 0; lightIterator < LightId::NUM_LIGHTS; lightIterator++)
        lights[lightIterator]->turnOn();
}


void LightController::turnAllOff(void)
{
    for(int lightIterator = 0; lightIterator < LightId::NUM_LIGHTS; lightIterator++)
        lights[lightIterator]->turnOff();
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