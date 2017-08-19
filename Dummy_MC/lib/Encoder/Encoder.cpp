//***************************************************************
// Encoder.cpp
//
#include "Encoder.h"


//---------------------------------------------------------------
//Encoder constructor
Encoder::Encoder(void)
{
  index = 0;
  cw = 0;
  ccw = 0;
  change = false;
  A_set = false;
  B_set = false;

  pinMode(encoderPinA, INPUT);
  pinMode(encoderPinB, INPUT);
}


//---------------------------------------------------------------
// Interrupt on A changing state
void Encoder::doEncoderA(void)
{
  // Test transition
  A_set = digitalRead(encoderPinA) == HIGH;
  // and adjust counter + if A leads B
  encoderPos = (A_set != B_set) ? +1 : -1;
}


//---------------------------------------------------------------
// Interrupt on B changing state
void Encoder::doEncoderB(void)
{
  // Test transition
  B_set = digitalRead(encoderPinB) == HIGH;
  // and adjust counter + if B follows A
  encoderPos = (A_set == B_set) ? +1 : -1;
}

void Encoder::updateIndex(/* arguments */) {
  if (0 > encoderPos)
  {
    cw++;
    ccw = 0;
    change = true;
  }
  else if(0 < encoderPos)
  {
    ccw++;
    cw = 0;
    change = true;
  }

  if(change == true)
  {
    //reset values so this condition isn't executed repeatedly
    encoderPos = 0;
    change = false;

    //notches are at every 4 steps on the encoder
    //checks every 4 steps to move up/down a menu item
    if(cw >= 4)
    {
      cw = 0;
      index--;
    }
    else if(ccw >= 4)
    {
      ccw = 0;
      index++;
    }
  }
}
