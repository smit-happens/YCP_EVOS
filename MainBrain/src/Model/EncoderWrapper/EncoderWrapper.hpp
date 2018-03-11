/**  This class acts as a wrapper for the encoder library included in platformio
 *
 * #include "EncoderWrapper.hpp"
 * Created 1-4-18 By: Smitty
 *
 * A longer description.
 */

#ifndef ENCODERWRAPPER_HPP
#define ENCODERWRAPPER_HPP

#include <Encoder.h>
#include "../Constants/Port.hpp"

//might need more functions in the future, but this works for now

class EncoderWrapper
{
public:
    EncoderWrapper();

    int getIndex(void);
    void setIndex(int index);    //can also be used to zero out the index

private:
    //private instance of the Encoder object
    Encoder* dial;
};

#endif  //ENCODERWRAPPER_HPP
