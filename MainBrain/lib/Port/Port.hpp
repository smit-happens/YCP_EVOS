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

//This will have to implement something like a method for the initialization of each set of ports
//For Example: Imd constructor calls imdPortSetup()
//             imdPortSetup() would correctly initialize the pin/s the IMD would be connected to

//Note: Thinking over all the various libraries that interact with pins (GLCD, SdioEX, SPI, FlexCan)
//      It might be easier for each class to have it's own initiallizer and make this Port class
//      into a header file just for constants

class Port
{
public:
  Port(void);

  String getName(void);

  int getState(void);
  void setState(void);
};


#endif  //PORT_HPP
