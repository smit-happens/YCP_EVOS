/**  Only has knowledge about creating log files for various tests
 *
 * #include "Logger.hpp"
 * Created 10-02-17 By: Smitty
 *
 * A longer description.
 */

#ifndef LOGGER_HPP
#define LOGGER_HPP

#include "../../Controller/SdCardController/SdCardController.hpp"

enum msg_type{
    MSG_LOG,
    MSG_DEBUG,
    MSG_WARN
};


class Logger
{
public:

    ~Logger(void);

    static Logger* getInstance();
    //public logging functions
    bool log(char* key, char* message,  msg_type);
    

private:
    Logger();
    Logger(Logger const&) {};

    static Logger* _pInstance;
    //private logging functions/ variables

};

class LogListener
{
public:
    virtual ~LogListener(void) {};

    virtual void onLogFiled(char* key, char* message,  msg_type) const = 0;
private:
    LogListener() {};
};

#endif  //LOGGER_HPP
