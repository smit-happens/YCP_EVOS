//***************************************************************
// Stepper.cpp
// Created 9-27-17
//
#include "Stepper.h"


//---------------------------------------------------------------
//Stepper constructor
Stepper::Stepper(void)
{
  pinMode(STEPPER_COIL_PIN_A, OUTPUT);
  pinMode(STEPPER_COIL_PIN_B, OUTPUT);
  pinMode(STEPPER_COIL_PIN_C, OUTPUT);
  pinMode(STEPPER_COIL_PIN_D, OUTPUT);

  digitalWriteFast(STEPPER_COIL_PIN_A, 1);
  digitalWriteFast(STEPPER_COIL_PIN_B, 1);
  digitalWriteFast(STEPPER_COIL_PIN_C, 1);
  digitalWriteFast(STEPPER_COIL_PIN_D, 1);

  //Setting the stepper's inital state
  digitalWriteFast(STEPPER_COIL_PIN_B, 0);
  digitalWriteFast(STEPPER_COIL_PIN_D, 0);
}


//---------------------------------------------------------------
//Spins the motor
//TODO add arguements for rpm
void Stepper::spin(void)
{
  digitalWriteFast(STEPPER_COIL_PIN_D, 1);
  digitalWriteFast(STEPPER_COIL_PIN_C, 0);
  delay(3);

  digitalWriteFast(STEPPER_COIL_PIN_B, 1);
  digitalWriteFast(STEPPER_COIL_PIN_A, 0);
  delay(3);

  digitalWriteFast(STEPPER_COIL_PIN_C, 1);
  digitalWriteFast(STEPPER_COIL_PIN_D, 0);
  delay(3);

  digitalWriteFast(STEPPER_COIL_PIN_A, 1);
  digitalWriteFast(STEPPER_COIL_PIN_B, 0);
  delay(3);
}
