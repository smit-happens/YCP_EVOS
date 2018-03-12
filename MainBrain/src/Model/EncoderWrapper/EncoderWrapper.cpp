/**  This class acts as a wrapper for the encoder library included in platformio
 *
 * EncoderWrapper.cpp
 * Created 1-4-18 By: Smitty
 *
 * A longer description.
 */

#include "EncoderWrapper.hpp"


/** 
 * @brief  Encoder constructor
 */
EncoderWrapper::EncoderWrapper(void)
{
    dial = new Encoder(MB_ENC_PINA, MB_ENC_PINB);
    dial->write(0);
}


/** 
 * @brief  Current encoder index
 * @note   
 * @retval Index value
 */
int EncoderWrapper::getIndex(void)
{
  return dial->read();
}


/** 
 * @brief  Sets the value of the encoder based on
 * @note   
 * @param  index: 
 * @retval None
 */
void EncoderWrapper::setIndex(int index)
{
    dial->write(index);
}
