/**  Basic functions that all models will inherit
 *
 * #include "BaseModel.hpp"
 * Created 2-26-18  By: Smitty
 *
 * A longer description.
 */

#ifndef BASEMODEL_HPP
#define BASEMODEL_HPP

#include <Arduino.h>
#include "../Constants/Port.hpp"
#include "../Constants/Constants.hpp"


class BaseModel
{
public:
    BaseModel() {};
    virtual ~BaseModel() {};  //to prevent memory leaks

    //Every model should have an update function for it's locally stored data
};


#endif  //BASEMODEL_HPP
