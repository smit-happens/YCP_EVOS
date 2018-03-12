/**  Operates the logic around controlling the Unitek motor controller
 *
 * UnitekControllerTest.cpp
 * Created 12-23-17  By: Smitty
 *
 * A longer description.
 */

#include "UnitekControllerTest.hpp"


//to see if the instance of the class has been initialized yet
UnitekControllerTest* UnitekControllerTest::_pInstance = NULL; 

/** 
 * @brief  Used to maintain the singleton format
 * @note   
 * @retval 
 */
UnitekControllerTest* UnitekControllerTest::getInstance()
{
    // Only allow one instance of class to be generated.
    if (!_pInstance)
        _pInstance = new UnitekControllerTest();

    return _pInstance;
}


/** 
 * @brief  UnitekControllerTest destructor
 * @note   Delete any instantiated varibles/objects
 * @retval None
 */
UnitekControllerTest::~UnitekControllerTest(void)
{
    delete unitekModel;
}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void UnitekControllerTest::init(void)
{
    unitekModel = new Unitek();
}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void UnitekControllerTest::poll(void)
{

}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void UnitekControllerTest::shutdown(void)
{
    
}


/** 
 * @brief  Convert RPM to a compatible MC speed value
 * @note   The speed value represents a percentage from 0 to 0x7FFF
 *         That percentage represents the RPM from 0 to RPM_LIMIT (Ex: 7000)
 * @param  rpm: RPM value
 * @retval      Speed value for the MC
 */
int UnitekControllerTest::calculateSpeedValue(float rpm)
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
float UnitekControllerTest::calculateRpm(int speedValue)
{
    float percentage = (float)speedValue / unitekModel->MAX_VALUE;
    return percentage * unitekModel->getRpmLimit();
}
