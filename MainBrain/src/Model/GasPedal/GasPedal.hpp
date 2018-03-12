/**  A one line description of the class.
 *
 * #include "GasPedal.hpp"
 * Created 11-09-17 By: Smitty
 *
 * A longer description.
 */

#ifndef GASPEDAL_HPP
#define GASPEDAL_HPP

#include "../BaseModel/BaseModel.hpp"


class GasPedal : public BaseModel
{
public:
    GasPedal(void);
    ~GasPedal(void);

    void update(void);

    void setOrigin(void);

    uint16_t getLinValue(void);
    uint16_t getLogValue(void);

private:
    uint16_t _linValue;
    uint16_t _logValue;

    //The pedals will have slightly different origin (zero) values because real-world
    uint16_t _linOrigin;
    uint16_t _logOrigin;
};

#endif  //GASPEDAL_HPP
