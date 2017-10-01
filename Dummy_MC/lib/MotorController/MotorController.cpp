/**  A one line description of the class.
 *
 * MotorController.cpp
 * Created 09-30-17 By: Smitty
 *
 * A longer description.
 */

#include "MotorController.hpp"


//---------------------------------------------------------------
//CanController constructor
MotorController::MotorController(void)
{

}


uint8_t MotorController::testFunc(void)
{
  return REG_READ;
}
