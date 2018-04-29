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

//this value is the max temperature for the batteries that is allowed before the car will shut down
const int MAXCELLTEMPERATURECELCIUS = 60;

#endif  //CONSTANTS_HPP