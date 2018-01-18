/**  IMD == Insulation Monitoring Device
 *
 * #include "Imd.hpp"
 * Created 12-20-17  By: Smitty
 *
 * Might use this, idk at the moment though
 */

#ifndef IMD_HPP
#define IMD_HPP

//Might need additional methods to flesh out all the functionality

class Imd
{
public:
  Imd(void);

  bool isTriggered(void);
  void trigger(void);
};


#endif  //IMD_HPP