/**  Logs serial messages to console
 *
 * SerialLogger.cpp
 * Created 4-11-18 By: Aaron
 *
 */
#include "SerialLogger.hpp"


SerialLogger* SerialLogger::_pInstance = NULL; 

SerialLogger* SerialLogger::getInstance()
{
    if(!_pInstance) {
        _pInstance = new SerialLogger();
    }
    return _pInstance;
}


void SerialLogger::init() 
{
    mFilter.raw = (uint8_t)(0xFF); //sets all fiters to high
    Logger::getInstance()->addSubscriber(this);
}


void SerialLogger::setFilter(uint8_t filter_raw)
{
    mFilter.raw = filter_raw;
}


void SerialLogger::addFilter(msg_type type) 
{
    switch(type) {
        case MSG_ERR:
            mFilter.bits.MSG_ERR = 0;
        break;
        case MSG_LOG:
            mFilter.bits.MSG_LOG = 0;
        break;
        case MSG_WARN:
             mFilter.bits.MSG_WARN = 0;
        break;
        case MSG_DEBUG:
             mFilter.bits.MSG_DEBUG = 0;
        break;
        default:break;
    }
}


void SerialLogger::removeFilter(msg_type type) 
{
    switch(type) {
        case MSG_ERR:
            mFilter.bits.MSG_ERR = 1;
        break;
        case MSG_LOG:
            mFilter.bits.MSG_LOG = 1;
        break;
        case MSG_WARN:
             mFilter.bits.MSG_WARN = 1;
        break;
        case MSG_DEBUG:
             mFilter.bits.MSG_DEBUG = 1;
        break;
        default:break;
    }
}


bool SerialLogger::printMessage(msg_type type)
{
    switch(type) {
        case MSG_ERR:   return mFilter.bits.MSG_ERR;
        case MSG_LOG:   return mFilter.bits.MSG_LOG;
        case MSG_WARN:  return mFilter.bits.MSG_WARN;
        case MSG_DEBUG: return mFilter.bits.MSG_DEBUG;
        default:        return true;
    }
}


void SerialLogger::onLogFiled(const char* key, const char* message, msg_type type)
{
    if(!printMessage(type)) { return;} //if certain log 

    //default Serial message lengthl 
    char buf[100];

    uint currentMessageLen = (unsigned)strlen(message);
    uint currentKeyLen = (unsigned)strlen(key);

    //check if current message is longer than our longest message
    if(currentMessageLen > longestMessage)
        longestMessage = currentMessageLen;

    //check if key is longer than our current longest key
    if(currentKeyLen > longestKey)
        longestKey = currentKeyLen;

    //temp variable for log message type
    char logType[8];

    switch(type) 
    {
        case MSG_ERR:   strcpy(logType, "ERR");     break;
        case MSG_LOG:   strcpy(logType, "LOG");     break;
        case MSG_WARN:  strcpy(logType, "WARN");    break;
        case MSG_DEBUG: strcpy(logType, "DEBUG");   break;
        default:    break;
    }

    sprintf(buf, "%s%*s\t%s%*s\t%s", key, longestKey-currentKeyLen, "", message, longestMessage-currentMessageLen, "", logType);

    Serial.println(buf);
}
