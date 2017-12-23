/**  BSPD == Brake System Plausibility Device
 *
 * #include "Bspd.hpp"
 * Created 12-20-17  By: Smitty
 *
 * This model might not get used during the 2017-18 car but it's
 * being created as more so of a placeholder for future development
 */

#ifndef BSPD_HPP
#define BSPD_HPP

//Might need additional methods to flesh out all the functionality

class Bspd
{
public:
  Bspd(void);

  bool isTriggered(void);
  void trigger(void);
};


#endif  //BSPD_HPP
