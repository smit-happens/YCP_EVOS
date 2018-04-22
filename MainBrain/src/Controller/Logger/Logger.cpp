/**  Only has knowledge about creating log files for various tests
 *
 * Logger.cpp
 * Created 10-02-17 By: Smitty
 *
 * A longer description.
 */

#include "Logger.hpp"

//to see if the instance of the class has been initialized yet
Logger* Logger::_pInstance = NULL; 


void Logger::init(void)
{
    //what do we do here??
    mNumSubscribers = 0;
}


Logger* Logger::getInstance()
{
    if(!_pInstance)
    {
        _pInstance = new Logger();
    }
    return _pInstance;
}


//Observer Pattern is broken these messages are depreciated.
bool Logger::addSubscriber(LogListener* listener)
{
    //have we exceeded number of broadcast subscribers
    if(mNumSubscribers >= MAX_SUBSCRIBERS) {return false;}
    mSubscribers[mNumSubscribers] = listener;
    mNumSubscribers++; //adds one to the subscriber count
    return true;
}


void Logger::msgPump(const char* key, const char* message, msg_type type)
{
    for(int i=0; i < mNumSubscribers; i++)
    {
        mSubscribers[i]->onLogFiled(key, message, type); //this line breaks can if called.
    }
}


bool Logger::log(const char* key, const char* message, msg_type type)
{
    //msgPump(key, message, type); //instead simply add your listener here manually
    SerialLogger::getInstance()->onLogFiled(key, message, type);
    SdCardController::getInstance()->onLogFiled(key, message, type);
    return true;
}
