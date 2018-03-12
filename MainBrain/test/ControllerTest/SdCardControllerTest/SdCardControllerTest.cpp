/**  Only has knowledge about creating/editing csv files
 *
 * SdCardControllerTest.cpp
 * Created 1-13-17 By: Smitty
 *
 * A longer description.
 */

#include "SdCardControllerTest.hpp"


//to see if the instance of the class has been initialized yet
SdCardControllerTest* SdCardControllerTest::_pInstance = NULL; 

/** 
 * @brief  Used to maintain the singleton format
 * @note   
 * @retval 
 */
SdCardControllerTest* SdCardControllerTest::getInstance()
{
    // Only allow one instance of class to be generated.
    if (!_pInstance)
        _pInstance = new SdCardControllerTest();

    return _pInstance;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
SdCardControllerTest::~SdCardControllerTest(void)
{
    delete sdCardModel;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
void SdCardControllerTest::init(void)
{
    sdCardModel = new SdCard();
}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void SdCardControllerTest::poll(void)
{

}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void SdCardControllerTest::shutdown(void)
{
    
}