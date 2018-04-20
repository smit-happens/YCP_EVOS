/**  Only has knowledge about creating log files for various tests
 *
 * #include "Logger.hpp"
 * Created 10-02-17 By: Smitty
 *
 * A longer description.
 */

#ifndef LOGGER_HPP
#define LOGGER_HPP

// #include "../../Controller/SdCardController/SdCardController.hpp"
#include "../../Controller/BaseController/BaseController.hpp"
#include "LogListener.hpp"

class LogListener; //forward declaration of logListener


class Logger: BaseController
{
public:
    //maximum number of broadcast subscribers

    static const int MAX_SUBSCRIBERS = 20;
    ~Logger(void) {};

    void init(void); //we do need an init to setup the singleton.


    //singleton getter
    static Logger* getInstance();
    //logs message 
    bool log(const char* key, const char* message,  msg_type type);
    //adds new subscribers to list 
    bool addSubscriber(LogListener *listener);
    

private:
    Logger() {};
    Logger(Logger const&) {};
    
    int mNumSubscribers;
    LogListener* mSubscribers[MAX_SUBSCRIBERS];
    void msgPump(const char* key, const char* message,  msg_type type);

    static Logger* _pInstance;
    //private logging functions/ variables

};

#endif  //LOGGER_HPP
