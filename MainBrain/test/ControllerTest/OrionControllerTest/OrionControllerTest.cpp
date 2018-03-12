/**  OrionControllerTest manages all data processing for the Orion BMS
 *
 * OrionControllerTest.cpp
 * Created 2-2-18 By: Smitty
 *
 * A longer description.
 */

#include "OrionControllerTest.hpp"


//to see if the instance of the class has been initialized yet
OrionControllerTest* OrionControllerTest::_pInstance = NULL; 

/** 
 * @brief  Used to maintain the singleton format
 * @note   
 * @retval 
 */
OrionControllerTest* OrionControllerTest::getInstance()
{
    // Only allow one instance of class to be generated.
    if (!_pInstance)
        _pInstance = new OrionControllerTest();

    return _pInstance;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
OrionControllerTest::~OrionControllerTest(void)
{
    delete orionModel;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
void OrionControllerTest::init(void)
{
    orionModel = new Orion();
}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void OrionControllerTest::poll(void)
{

}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void OrionControllerTest::shutdown(void)
{
    
}