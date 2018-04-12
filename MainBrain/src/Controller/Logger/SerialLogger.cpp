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
        case MSG_ERR:
            return mFilter.bits.MSG_ERR;
        break;
        case MSG_LOG:
            return mFilter.bits.MSG_LOG;
        break;
        case MSG_WARN:
            return mFilter.bits.MSG_WARN;
        break;
        case MSG_DEBUG:
            return mFilter.bits.MSG_DEBUG;
        break;
        default:break;
    }
}


void SerialLogger::onLogFiled(const char* key, const char* message, msg_type type)
{
   //TODO: Move to serial logger class. 
   if(!printMessage(type)) { return;} //if certian log type is fitered. 

    Serial.print(key); 
    Serial.print("\t");
    Serial.print(message);
    Serial.print("\t");

    switch(type) {
        case MSG_ERR:
            Serial.print(" ERR");
        break;
        case MSG_LOG:
            Serial.print(" LOG");
        break;
        case MSG_WARN:
             Serial.print(" WARN");
        break;
        case MSG_DEBUG:
             Serial.print(" DEBUG");
        break;
        default:break;
    }

    Serial.println();
}
