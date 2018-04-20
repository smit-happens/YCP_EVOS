/** Serial Log Listener
 *
 * 
 * Created 4-11-18 By: Aaron
 *
 * Logs messages to the serial console
 */

#ifndef SERIALLOGGER_HPP
#define SERIALLOGGER_HPP

#include "Logger.hpp"

struct filter_bits{
    uint8_t MSG_DEBUG   :1;
    uint8_t MSG_ERR     :1;
    uint8_t MSG_LOG     :1;
    uint8_t MSG_WARN    :1;
    uint8_t freespace   :4;
};

typedef union {
    uint8_t raw;
    struct filter_bits bits;
} filter_pack;


class SerialLogger: public BaseController, public LogListener
{
    public:        
        void init(void);
        static SerialLogger* getInstance();

        void setFilter(uint8_t filter_raw);
        void addFilter(msg_type type);
        void removeFilter(msg_type type);
        void onLogFiled(const char* key, const char* message, msg_type type);

    private:
        filter_pack mFilter;

        static SerialLogger* _pInstance;

        SerialLogger() {};
        virtual ~SerialLogger() {};

        bool printMessage(msg_type type);
    
};


#endif