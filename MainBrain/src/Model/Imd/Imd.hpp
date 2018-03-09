/**  IMD == Insulation Monitoring Device
 *
 * #include "Imd.hpp"
 * Created 12-20-17  By: Smitty
 *
 * Might use this, idk at the moment though
 */

#ifndef IMD_HPP
#define IMD_HPP

#include "../BaseModel/BaseModel.hpp"


class Imd : public BaseModel
{
public:
    Imd(void);
    ~Imd(void);

    void update(void);

    bool isTriggered(void);
    void trigger(void);
};


#endif  //IMD_HPP