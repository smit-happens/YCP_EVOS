/**  OrionController manages all data processing for the Orion BMS
 *
 * OrionController.cpp
 * Created 2-2-18 By: Smitty
 *
 * A longer description.
 */

#include "OrionController.hpp"
#include "../../Manager/ControllerManager/ControllerManager.hpp"



/** 
 * @brief  Orion constructor
 */
OrionController::OrionController(void)
{
    orionModel = new Orion();
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
OrionController::~OrionController(void)
{
    delete orionModel;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
void OrionController::init(void)
{

}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void OrionController::poll(void)
{

}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void OrionController::shutdown(void)
{
    
}