/**  A one line description of the class.
 *
 * #include "BasePedal.hpp"
 * Created 3-14-18 By: Smitty
 *
 * A longer description.
 */

#ifndef BASEPEDAL_HPP
#define BASEPEDAL_HPP

#include "BaseModel.hpp"


class BasePedal : public BaseModel
{
public:
    BasePedal(void) {};
    ~BasePedal(void) {};

    //not implimented into the BasePedal due to different pins for each pedal
    virtual void update(void) {};


    /** 
     * @brief  Returns origin of the Linear Potentiometer
     * @note   value of 0-8195
     * @retval Analog voltage sensed at origin (zero position)
     */
    uint16_t getRawOrigin(void) { return _rawOrigin; };


    /** 
     * @brief  set origin point of a pedal
     * @note   Every pedal will have an origin
     * @retval None
     */
    virtual void setRawOrigin(void) = 0;


    /** 
     * @brief  Retrieves the value of the Linear Potentiometer
     * @note   value of 0-8195
     * @retval Analog voltage sensed
     */
    uint16_t getRawValue(void) { return _rawValue; };


protected:
    //raw 0-8195 int representing analog pedal value
    uint16_t _rawValue;

    //The pedals will have slightly different origin (zero) values because real-world
    uint16_t _rawOrigin;
};

#endif  //BASEPEDAL_HPP
