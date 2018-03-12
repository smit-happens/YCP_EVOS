/**  A one line description of the class.
 *
 * #include "BrakePedal.hpp"
 * Created 12-20-17 By: Smitty
 *
 * A longer description.
 */

#ifndef BRAKEPEDAL_HPP
#define BRAKEPEDAL_HPP

#include "../BaseModel/BaseModel.hpp"

//Maybe have states the pedal can be in, since it has the chance
//of causing an error if there's an implausibility or a short in
//the wires

class BrakePedal : public BaseModel
{
public:
    BrakePedal();
    ~BrakePedal(void);

    void update(void);

    uint16_t getLinValue(void);

private:
    uint16_t _linValue;
};

#endif  //BRAKEPEDAL_HPP