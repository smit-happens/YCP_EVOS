/**  Basic functions that all models will inherit
 *
 * #include "BaseModelTest.hpp"
 * Created 3-12-18  By: Smitty
 *
 * A longer description.
 */

#ifndef BASEMODELTEST_HPP
#define BASEMODELTEST_HPP

#include <Arduino.h>
#include "../../../src/Model/Model.hpp"
#include <unity.h>

class BaseModelTest
{
public:
    BaseModelTest();
    // virtual ~BaseModelTest();  //to prevent memory leaks

    //Every model should have an update function for it's locally stored data
    // virtual void update();
};


#endif  //BASEMODELTEST_HPP
