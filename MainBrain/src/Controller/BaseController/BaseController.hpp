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


class BaseController
{
public:
    //include manager as a member field in basecontroller
    // Manager;

    BaseController();
    virtual ~BaseController();  //to prevent memory leaks

    virtual void init() = 0;
    virtual void poll() = 0;

    virtual void display();
    virtual void shutdown();
};


#endif  //BASECONTROLLER_HPP
