/**  Monitors the GLV battery level
 *
 * #include "Batlog.hpp"
 * Created 2-6-18  By: Smitty
 *
 * A longer description.
 */

#ifndef BATLOG_HPP
#define BATLOG_HPP

#include "../BaseModel/BaseModel.hpp"


class Batlog : public BaseModel
{
public:
    Batlog(void);
    ~Batlog(void);

    void update(void);

private:
    uint16_t _batteryValue;
};


#endif  //BATLOG_HPP
