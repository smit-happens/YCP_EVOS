/**  LightControllerTest manages all the lights and light states
 *
 * LightControllerTest.cpp
 * Created 2-25-18 By: Smitty
 *
 * A longer description.
 */

#include "LightControllerTest.hpp"


//to see if the instance of the class has been initialized yet
LightControllerTest* LightControllerTest::_pInstance = NULL; 

/** 
 * @brief  Used to maintain the singleton format
 * @note   
 * @retval 
 */
LightControllerTest* LightControllerTest::getInstance()
{
    // Only allow one instance of class to be generated.
    if (!_pInstance)
        _pInstance = new LightControllerTest();

    return _pInstance;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
LightControllerTest::~LightControllerTest(void)
{
    delete light;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
void LightControllerTest::init(void)
{
    light = new Light();
}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void LightControllerTest::poll(void)
{

}