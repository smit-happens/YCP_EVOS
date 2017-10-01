//***************************************************************
// Stepper.hpp
// Created 9-27-17
//

#ifndef __STEPPER_HPP_INCLUDED__
#define __STEPPER_HPP_INCLUDED__

#include <Arduino.h>

// Pin assignments for the two H-bridges
const uint8_t STEPPER_COIL_PIN_A = 29;
const uint8_t STEPPER_COIL_PIN_B = 30;
const uint8_t STEPPER_COIL_PIN_C = 31;
const uint8_t STEPPER_COIL_PIN_D = 32;

class Stepper
{
public:
  Stepper();

  void spin(void);

  void setRpm(int rpm);
  int getRpm(void);
};

#endif  //__STEPPER_HPP_INCLUDED__
