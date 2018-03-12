/**  Handles any calculations or logical calculations involving the GLV batteries
 *
 * BatlogControllerTest.cpp
 * Created 2-6-18 By: Smitty
 *
 * A longer description.
 */

#include "BatlogControllerTest.hpp"


//to see if the instance of the class has been initialized yet
BatlogControllerTest* BatlogControllerTest::_pInstance = NULL; 

/** 
 * @brief  Used to maintain the singleton format
 * @note   
 * @retval 
 */
BatlogControllerTest* BatlogControllerTest::getInstance()
{
    // Only allow one instance of class to be generated.
    if (!_pInstance)
        _pInstance = new BatlogControllerTest();

    return _pInstance;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
BatlogControllerTest::~BatlogControllerTest(void)
{
    delete batlogModel;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
void BatlogControllerTest::init(void)
{
    batlogModel = new Batlog();
}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void BatlogControllerTest::poll(void)
{

}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void BatlogControllerTest::shutdown(void)
{
    
}