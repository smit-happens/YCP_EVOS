/**  Monitors the GLV battery level
 *
 * #include "BatlogTest.hpp"
 * Created 3-12-18  By: Smitty
 *
 * A longer description.
 */

#ifndef BATLOGTEST_HPP
#define BATLOGTEST_HPP

#include "../BaseModelTest/BaseModelTest.hpp"


class BatlogTest : public BaseModelTest
{
public:
    BatlogTest(void);
    ~BatlogTest(void);

    void update(void);

private:
    uint16_t _batteryValue;
};


#endif  //BATLOGTEST_HPP
