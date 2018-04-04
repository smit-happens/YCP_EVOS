/**  A one line description of the class.
 *
 * Light.cpp
 * Created 12-15-17  By: Smitty
 *
 * A longer description.
 */

#include "Light.hpp"


/** 
 * @brief  Light constructor
 */
Light::Light(const uint8_t lightPin)
{
    pinMode(lightPin, OUTPUT);
    _lightPin = lightPin;
}
