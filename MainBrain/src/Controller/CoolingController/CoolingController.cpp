/**  Cooling controller class
 *
 * CoolingController.cpp
 * Created 1-17-17 By: Smitty
 *
 * A longer description.
 */

#include "CoolingController.hpp"
// #include "../../Manager/ControllerManager/ControllerManager.hpp"



/** 
 * @brief  CoolingController constructor
 */
CoolingController::CoolingController(void)
{
    coolingModel = new CoolingSystem();
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
CoolingController::~CoolingController(void)
{
    delete coolingModel;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
void CoolingController::init(void)
{

}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void CoolingController::poll(void)
{

}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void CoolingController::shutdown(void)
{
    
}