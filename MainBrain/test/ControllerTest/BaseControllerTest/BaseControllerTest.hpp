/**  Basic functions that all controllers will inherit
 *
 * #include "BaseControllerTest.hpp"
 * Created 1-21-18  By: Smitty
 *
 * A longer description.
 */

#ifndef BASECONTROLLERTEST_HPP
#define BASECONTROLLERTEST_HPP

#include "../../../src/Controller/Controller.hpp"
#include <Arduino.h>
#include <unity.h>

#ifdef UNIT_TEST

class BaseControllerTest {
    public:
        BaseControllerTest(){};
        virtual ~BaseControllerTest(){};

        virtual int main(){return 0};

    private:

};


#endif  //BASECONTROLLERTEST_HPP
#endif  //UNIT_TEST
