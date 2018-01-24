/**  Basic functions that all controllers will inherit
 *
 * BaseController.cpp
 * Created 1-21-18 By: Smitty
 *
 * A longer description.
 */

#include "BaseController.hpp"


/** 
 * @brief  BaseController constructor
 */
BaseController::BaseController(void)
{
    
}


/** 
 * @brief  Literally nothing happens
 * @note   
 * @retval None
 */
BaseController::~BaseController(void)
{
    
}


/** 
 * @brief  basic polling function
 * @note   
 * @retval None
 */
void BaseController::poll(void)
{
    Serial.print("Default display function");
}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void BaseController::display(void)
{
    Serial.println("Default display function");
}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void BaseController::shutdown(void)
{

}