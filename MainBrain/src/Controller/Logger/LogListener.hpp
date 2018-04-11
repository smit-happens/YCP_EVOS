#ifndef LOGLISTENER_HPP
#define LOGLISTENER_HPP

#include "../../Model/Constants/Constants.hpp"



class LogListener //interface for broadcast 
{
public:
    LogListener(void) {};
    virtual ~LogListener(void) {};

    virtual void onLogFiled(char* key, char* message,  msg_type type) = 0;
private:
    //LogListener(void) {};
};

#endif