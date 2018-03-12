/**  Display controller class
 *
 * GlcdControllerTest.cpp
 * Created 1-5-17 By: Smitty
 *
 * A longer description.
 */

#include "GlcdControllerTest.hpp"


//to see if the instance of the class has been initialized yet
GlcdControllerTest* GlcdControllerTest::_pInstance = NULL; 

/** 
 * @brief  Used to maintain the singleton format
 * @note   
 * @retval 
 */
GlcdControllerTest* GlcdControllerTest::getInstance()
{
    // Only allow one instance of class to be generated.
    if (!_pInstance)
        _pInstance = new GlcdControllerTest();

    return _pInstance;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
GlcdControllerTest::~GlcdControllerTest(void)
{
    delete glcdModel;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
void GlcdControllerTest::init(void)
{
    glcdModel = new Glcd();
}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void GlcdControllerTest::poll(void)
{

}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void GlcdControllerTest::shutdown(void)
{
    
}