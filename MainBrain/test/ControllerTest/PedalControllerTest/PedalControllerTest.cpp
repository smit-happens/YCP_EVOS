/**  Pedal controller class
 *
 * PedalControllerTest.cpp
 * Created 1-17-17 By: Smitty
 *
 * A longer description.
 */

#include "PedalControllerTest.hpp"


PedalControllerTest::PedalControllerTest(void)
{
    
}


/** 
 * @brief  Retrieves the evaluated Gas percentage
 * @note   
 * @retval GasPedal percentage
 */
float PedalControllerTest::getPercentageGas(void)
{
    return 0.0;
}


/** 
 * @brief  Evaluates the two pedal potentiometers (Linear and Logarithmic)
 * @note   Needs to check for shorts in wire and extrainious values
 * @retval True if there's an implausibility found, false if not
 */
bool PedalControllerTest::isImplausibilityGas(void)
{
    return false;
}


/** 
 * @brief  Retrieves the evaluated Brake percentage
 * @note   Evaluate linear pedal potentiometer
 * @retval BrakePedal percentage
 */
float PedalControllerTest::getPercentageBrake(void)
{
    return 0.0;
}


/** 
 * @brief  Evaluates the brake pedal potentiometer
 * @note   Needs to check for shorts in wire and extrainious values
 * @retval True if there's an implausibility found, false if not
 */
bool PedalControllerTest::isImplausibilityBrake(void)
{
    return false;
}