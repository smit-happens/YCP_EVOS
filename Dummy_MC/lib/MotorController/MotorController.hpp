//***************************************************************
// MotorController.hpp
// Created 9-30-17

#ifndef __MOTORCONTROLLER_HPP_INCLUDED__
#define __MOTORCONTROLLER_HPP_INCLUDED__

#include <Arduino.h>
#include "MotorControllerRegisters.hpp"

class MotorController
{
public:
  MotorController(void);

  uint8_t testFunc(void);

};


#endif  //__MOTORCONTROLLER_HPP_INCLUDED__
