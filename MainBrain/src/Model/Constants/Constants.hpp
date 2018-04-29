/** Generic constant to be used across all models and constant
 * 
 * Created 3/15/18 By: Joe Maier
 * 
 */

#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

//Max analog read value
const int MAX_ANALOGREAD = 8195;    //(2^13)-1

//types of log statements we can use
enum msg_type{
    MSG_LOG,
    MSG_DEBUG,
    MSG_WARN,
    MSG_ERR
};

enum err_type {
    ERR_ORION,
    ERR_IMD,
    ERR_UNITEK,
    ERR_TMP,
    ERR_ALL
};

//percent threshold that the brake light activates
const int BRAKE_LIGHT_PERCENT = 90;

#endif  //CONSTANTS_HPP