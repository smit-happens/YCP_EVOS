/** Generic constant to be used across all models and constant
 * 
 * Created 3/15/18 By: Joe Maier
 * 
 */

#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

//Max analog read value
const int MAX_ANALOGREAD = 8195;    //(2^13)-1

enum msg_type{
    MSG_LOG,
    MSG_DEBUG,
    MSG_WARN,
    MSG_ERR
};

enum Stage
{
    STAGE_BOOTTEST,
    STAGE_STANDBY,
    STAGE_PRECHARGE,
    STAGE_ENERGIZED,
    STAGE_DRIVING,
    STAGE_SHUTDOWN
};

#endif  //CONSTANTS_HPP