/**  A one line description of the class.
 *
 * #include "EncoderHandler.hpp"
 * Created XX-XX-17 By: Smitty
 *
 * A longer description.
 */

#ifndef ENCODERHANDLER_HPP
#define ENCODERHANDLER_HPP

#include <Arduino.h>

const uint8_t encoderPinA = 17;
const uint8_t encoderPinB = 18;
const uint8_t buttonPin = 20;

class EncoderHandler
{
public:
  EncoderHandler();

  int getIndex(void);

  void updateIndex(int menuLength);

  void doEncoderA(void);
  void doEncoderB(void);

  void pressButton(void);
  bool isButtonPressed(void);

private:
  int index;
  int8_t cw, ccw;
  bool change;

  bool A_set;
  bool B_set;

  volatile int8_t encoderPos = 0;
  volatile bool buttonState = false;
};

#endif  //ENCODERHANDLER_HPP
