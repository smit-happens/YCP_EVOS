#ifndef __ENCODER_HPP_INCLUDED__
#define __ENCODER_HPP_INCLUDED__

#include <Arduino.h>

const uint8_t encoderPinA = 17;
const uint8_t encoderPinB = 18;

class Encoder
{
public:
  Encoder();

  int getIndex(void);

  void updateIndex(void);

  void doEncoderA(void);
  void doEncoderB(void);

  void isButtonPressed(void);

private:
  int index;
  int8_t cw, ccw;
  bool change;

  bool A_set;
  bool B_set;

  volatile int8_t encoderPos = 0;
};

#endif  //__ENCODER_HPP_INCLUDED__
