/**  A one line description of the class.
 *
 * #include "Port.hpp"
 * Created 12-15-17  By: Smitty
 *
 * A longer description.
 */

#ifndef PORT_HPP
#define PORT_HPP

#include <Arduino.h>

class Port
{
public:
  Port(void);

  String getName(void);

  int getState(void);
  void setState(void);
};


#endif  //PORT_HPP
