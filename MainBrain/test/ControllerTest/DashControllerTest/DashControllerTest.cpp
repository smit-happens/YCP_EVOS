/**  DashControllerTest manages all the buttons and forms of user feedback/input to the EV
 *
 * DashControllerTest.cpp
 * Created 1-17-17 By: Smitty
 *
 * A longer description.
 */

#include "DashControllerTest.hpp"


//to see if the instance of the class has been initialized yet
DashControllerTest* DashControllerTest::_pInstance = NULL; 

/** 
 * @brief  Used to maintain the singleton format
 * @note   
 * @retval 
 */
DashControllerTest* DashControllerTest::getInstance()
{
    // Only allow one instance of class to be generated.
    if (!_pInstance)
        _pInstance = new DashControllerTest();

    return _pInstance;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
DashControllerTest::~DashControllerTest(void)
{
    // delete buttons
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
void DashControllerTest::init(void)
{

}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void DashControllerTest::poll(void)
{

}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void DashControllerTest::shutdown(void)
{
    
}