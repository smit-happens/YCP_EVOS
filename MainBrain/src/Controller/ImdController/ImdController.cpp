/**  IMD controller class
 *
 * ImdController.cpp
 * Created 1-17-17 By: Smitty
 *
 * A longer description.
 */

#include "ImdController.hpp"
#include "../../Manager/ControllerManager/ControllerManager.hpp"



/** 
 * @brief  ImdController constructor
 */
ImdController::ImdController(void)
{
    imdModel = new Imd();
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
ImdController::~ImdController(void)
{
    delete imdModel;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
void ImdController::init(void)
{

}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void ImdController::poll(void)
{

}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void ImdController::shutdown(void)
{
    
}