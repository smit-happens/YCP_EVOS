/**  A one line description of the class.
 *
 * #include "Light.hpp"
 * Created 12-15-17  By: Smitty
 *
 * A longer description.
 */

#ifndef LIGHT_HPP
#define LIGHT_HPP

#include "../BaseModel/BaseModel.hpp"


class Light : public BaseModel
{
public:
    Light(const uint8_t lightPin);
    ~Light(void) {};

    //not necessary for each light to have an update function
    void update(void) {};

    void turnOn(void) { digitalWriteFast(_lightPin, HIGH); };
    
    void turnOff(void) { digitalWriteFast(_lightPin, LOW); };

private:
    uint8_t _lightPin;
};


#endif  //LIGHT_HPP
