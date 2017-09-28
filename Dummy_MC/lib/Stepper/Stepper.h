#ifndef STEPPER_H
#define STEPPER_H

#include <Arduino.h>

// Pin assignments for the two H-bridges
#define STEPPER_COIL_PIN_A 29
#define STEPPER_COIL_PIN_B 30
#define STEPPER_COIL_PIN_C 31
#define STEPPER_COIL_PIN_D 32

class Stepper
{
public:
  Stepper();

  void spin(void);  
};

#endif
