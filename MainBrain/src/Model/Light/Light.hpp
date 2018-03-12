/**  A one line description of the class.
 *
 * #include "Light.hpp"
 * Created 12-15-17  By: Smitty
 *
 * A longer description.
 */

#ifndef LIGHT_HPP
#define LIGHT_HPP

#include "../BaseModel/BaseModel.hpp"


class Light : public BaseModel
{
public:
    Light(void);
    ~Light(void);

    void update(void);


    String getName(void);

    int getState(void);
    void setState(bool);

    void turnOnAll(void);  
};


#endif  //LIGHT_HPP
