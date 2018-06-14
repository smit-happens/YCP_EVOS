/**  A one line description of the class.
 *
 * #include "GasPedal.hpp"
 * Created 11-09-17 By: Smitty
 *
 * A longer description.
 */

#ifndef GASPEDAL_HPP
#define GASPEDAL_HPP

#include "../BaseModel/BasePedal.hpp"


class GasPedal : public BasePedal
{
public:
    GasPedal(void);
    ~GasPedal(void);

    void update(void);

    void setRawOrigin(void);

    uint16_t getLastValue();

private:
    uint16_t lastValue;

};

#endif  //GASPEDAL_HPP
