/**  Basic functions that all controllers will inherit
 *
 * #include "BaseController.hpp"
 * Created 1-21-18  By: Smitty
 *
 * A longer description.
 */

#ifndef BASECONTROLLER_HPP
#define BASECONTROLLER_HPP

#include <Arduino.h>
#include "../../Model/Constants/TimeDelay.hpp"
#include "../../Model/Constants/Constants.hpp"


class BaseController
{
public:
    BaseController() {};
    virtual ~BaseController() {};  //to prevent memory leaks

    //Due to the singleton manager, constructors shouldn't be doing anything complicated
    //so this requires a function for initialization for every controller
    virtual void init() = 0;

    virtual void display() {};
};


#endif  //BASECONTROLLER_HPP
