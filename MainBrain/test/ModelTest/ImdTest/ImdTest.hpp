/**  IMD == Insulation Monitoring Device
 *
 * #include "ImdTest.hpp"
 * Created 3-12-18  By: Smitty
 *
 * Might use this, idk at the moment though
 */

#ifndef IMDTEST_HPP
#define IMDTEST_HPP

#include "../BaseModelTest/BaseModelTest.hpp"


class ImdTest : public BaseModelTest
{
public:
    ImdTest(void);
    ~ImdTest(void);

    void update(void);

    bool isTriggered(void);
    void trigger(void);
};


#endif  //IMDTEST_HPP