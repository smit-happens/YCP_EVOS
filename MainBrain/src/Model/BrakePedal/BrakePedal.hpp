/**  A one line description of the class.
 *
 * #include "BrakePedal.hpp"
 * Created 12-20-17 By: Smitty
 *
 * A longer description.
 */

#ifndef BRAKEPEDAL_HPP
#define BRAKEPEDAL_HPP

#include "../BaseModel/BasePedal.hpp"

//Maybe have states the pedal can be in, since it has the chance
//of causing an error if there's an implausibility or a short in
//the wires

class BrakePedal : public BasePedal
{
public:
    BrakePedal();
    ~BrakePedal(void);

    void update(void);

    void setRawOrigin(void);

private:

};

#endif  //BRAKEPEDAL_HPP