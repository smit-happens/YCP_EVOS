//***************************************************************
// MotorController.cpp
// Created 9-30-17

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
