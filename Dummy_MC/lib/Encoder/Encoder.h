#include <Arduino.h>

#define encoderPinA  17
#define encoderPinB  18

class Encoder
{
public:
  Encoder();

  int getIndex(void);

  void updateIndex(void);

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
