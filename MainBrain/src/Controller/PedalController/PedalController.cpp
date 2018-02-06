/**  Pedal controller class
 *
 * PedalController.cpp
 * Created 1-17-17 By: Smitty
 *
 * A longer description.
 */

#include "PedalController.hpp"
#include "../../Manager/ControllerManager/ControllerManager.hpp"



/** 
 * @brief  PedalController constructor
 */
PedalController::PedalController(void)
{
    brakeModel = new BrakePedal();
    gasModel = new GasPedal();
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
PedalController::~PedalController(void)
{
    delete brakeModel;
    delete gasModel;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
void PedalController::init(void)
{

}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void PedalController::poll(void)
{

}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void PedalController::shutdown(void)
{
    
}