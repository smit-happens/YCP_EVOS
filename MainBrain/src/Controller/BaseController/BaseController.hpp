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
    BaseController();
    virtual ~BaseController();  //to prevent memory leaks

    //Due to the simgleton manager, constructors shouldn't be doing anything complicated
    //so this requires a function for initialization for every controller
    virtual void init() = 0;
    
    //complex controllers will implement a polling function
    //Ex: UnitekC, CanC, OrionC
    virtual void poll();

    virtual void display();
    virtual void shutdown();
};


#endif  //BASECONTROLLER_HPP
