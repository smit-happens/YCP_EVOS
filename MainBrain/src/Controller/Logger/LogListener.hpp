/**  Display controller class
 *
 *
 * Created 4-10-18 By: Aaron Walsh
 *
 * Observer interface for listening to 
 * log message broadcasts.
 */

#ifndef LOGLISTENER_HPP
#define LOGLISTENER_HPP

#include "../../Model/Constants/Constants.hpp"

class LogListener //interface for broadcast 
{
public:
    LogListener(void) {};
    virtual ~LogListener(void) {};

    virtual void onLogFiled(const char* key, const char* message, msg_type type) = 0;
};

#endif