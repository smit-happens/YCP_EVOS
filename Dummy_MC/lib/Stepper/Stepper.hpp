/**  A one line description of the class.
 *
 * #include Stepper.hpp
 * Created 09-27-17 By: Smitty
 *
 * A longer description.
 */

#ifndef STEPPER_HPP
#define STEPPER_HPP

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

#endif  //STEPPER_HPP
