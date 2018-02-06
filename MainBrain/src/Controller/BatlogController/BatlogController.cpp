/**  Handles any calculations or logical calculations involving the GLV batteries
 *
 * BatlogController.cpp
 * Created 2-6-18 By: Smitty
 *
 * A longer description.
 */

#include "BatlogController.hpp"
#include "../../Manager/ControllerManager/ControllerManager.hpp"



/** 
 * @brief  Orion constructor
 */
BatlogController::BatlogController(void)
{
    batlogModel = new Batlog();
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
BatlogController::~BatlogController(void)
{
    delete batlogModel;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
void BatlogController::init(void)
{

}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void BatlogController::poll(void)
{

}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void BatlogController::shutdown(void)
{
    
}