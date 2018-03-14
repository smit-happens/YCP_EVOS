/**  A one line description of the class.
 *
 * #include "LightTest.hpp"
 * Created 3-12-18  By: Smitty
 *
 * A longer description.
 */

#ifndef LIGHTTEST_HPP
#define LIGHTTEST_HPP

#include "../BaseModelTest/BaseModelTest.hpp"


class LightTest : public BaseModelTest
{
public:
    LightTest(void);
    ~LightTest(void);

    void update(void);


    String getName(void);

    int getState(void);
    void setState(bool);

    void turnOnAll(void);  
};


#endif  //LIGHTTEST_HPP
