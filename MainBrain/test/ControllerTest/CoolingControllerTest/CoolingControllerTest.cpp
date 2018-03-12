/**  Cooling controller class
 *
 * CoolingControllerTest.cpp
 * Created 1-17-17 By: Smitty
 *
 * A longer description.
 */

#include "CoolingControllerTest.hpp"


//to see if the instance of the class has been initialized yet
CoolingControllerTest* CoolingControllerTest::_pInstance = NULL; 

/** 
 * @brief  Used to maintain the singleton format
 * @note   
 * @retval 
 */
CoolingControllerTest* CoolingControllerTest::getInstance()
{
    // Only allow one instance of class to be generated.
    if (!_pInstance)
        _pInstance = new CoolingControllerTest();

    return _pInstance;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
CoolingControllerTest::~CoolingControllerTest(void)
{
    delete coolingModel;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
void CoolingControllerTest::init(void)
{
    coolingModel = new CoolingSystem();
}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void CoolingControllerTest::poll(void)
{

}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void CoolingControllerTest::shutdown(void)
{
    
}


/** 
 * @brief  Radiator coolant input temperature
 * @note   Figure out the conversion from the raw data to Celcius
 * @retval Temperature of coolant input in Celsius
 */
float CoolingControllerTest::getRadiatorTempIn(void)
{
    return 0.0;
}


/** 
 * @brief  Radiator coolant output temperature
 * @note   Figure out the conversion from the raw data to Celcius
 * @retval Temperature of coolant output in Celsius
 */
float CoolingControllerTest::getRadiatorTempOut(void)
{
    return 0.0;
}