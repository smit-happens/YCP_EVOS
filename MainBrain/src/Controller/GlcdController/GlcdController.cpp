/**  Display controller class
 *
 * GlcdController.cpp
 * Created 1-5-17 By: Smitty
 *
 * A longer description.
 */

#include "GlcdController.hpp"
#include "../../Manager/ControllerManager/ControllerManager.hpp"



/** 
 * @brief  GlcdController constructor
 */
GlcdController::GlcdController(void)
{
    glcdModel = new Glcd();
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
GlcdController::~GlcdController(void)
{
    delete glcdModel;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
void GlcdController::init(void)
{

}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void GlcdController::poll(void)
{

}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void GlcdController::shutdown(void)
{
    
}