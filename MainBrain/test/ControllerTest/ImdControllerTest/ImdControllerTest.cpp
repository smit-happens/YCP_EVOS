/**  IMD controller class
 *
 * ImdControllerTest.cpp
 * Created 1-17-17 By: Smitty
 *
 * A longer description.
 */

#include "ImdControllerTest.hpp"


//to see if the instance of the class has been initialized yet
ImdControllerTest* ImdControllerTest::_pInstance = NULL; 

/** 
 * @brief  Used to maintain the singleton format
 * @note   
 * @retval 
 */
ImdControllerTest* ImdControllerTest::getInstance()
{
    // Only allow one instance of class to be generated.
    if (!_pInstance)
        _pInstance = new ImdControllerTest();

    return _pInstance;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
ImdControllerTest::~ImdControllerTest(void)
{
    delete imdModel;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
void ImdControllerTest::init(void)
{
    imdModel = new Imd();
}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void ImdControllerTest::poll(void)
{

}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void ImdControllerTest::shutdown(void)
{
    
}