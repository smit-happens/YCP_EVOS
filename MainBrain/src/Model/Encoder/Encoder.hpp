/**  A one line description of the class.
 *
 * #include "Encoder.hpp"
 * Created XX-XX-17 By: Smitty
 *
 * A longer description.
 */

#ifndef ENCODERHANDLER_HPP
#define ENCODERHANDLER_HPP

#include <Arduino.h>

const uint8_t encoderPinA = 17;
const uint8_t encoderPinB = 18;

class Encoder
{
public:
  Encoder();

  int getIndex(void);

  void updateIndex(int menuLength);

  void doEncoderA(void);
  void doEncoderB(void);


private:
  int index;
  int8_t cw, ccw;
  bool change;

  bool A_set;
  bool B_set;

  volatile int8_t encoderPos = 0;
};

#endif  //ENCODERHANDLER_HPP
