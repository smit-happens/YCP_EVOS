/**  Basic functions that all models will inherit
 *
 * #include "BaseModel.hpp"
 * Created 2-26-18  By: Smitty
 *
 * A longer description.
 */

#include "BaseModel.hpp"


/** 
 * @brief  BaseModel constructor
 */
BaseModel::BaseModel(void)
{
    
}


/** 
 * @brief  
 * @note   
 * @retval None
 */
BaseModel::~BaseModel(void)
{
    
}


/** 
 * @brief  Literally nothing happens
 * @note   
 * @retval None
 */
void BaseModel::update(void)
{
    Serial.println("Default update function");
}
