/**  A one line description of the class.
 *
 * #include "ButtonTest.hpp"
 * Created 3-12-18  By: Smitty
 *
 * A longer description.
 */

#ifndef BUTTONTEST_HPP
#define BUTTONTEST_HPP

#include "../BaseModelTest/BaseModelTest.hpp"


class ButtonTest : public BaseModelTest
{
public:
    ButtonTest(void);
    ~ButtonTest(void);

    void update(void);


    String getName(void);

    int getState(void);
    void setState(void);
};


#endif  //BUTTONTEST_HPP
