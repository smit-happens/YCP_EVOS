/**  Siren used for playing the startup sound of the car
 *
 * #include "Siren.hpp"
 * Created 12-20-17  By: Smitty
 * 
 * A longer description.
 */

#ifndef SIREN_HPP
#define SIREN_HPP


#include "../Constants/Port.hpp"

//Honestly won't have a whole lot going on for this model (I hope)

class Siren
{
public:
  Siren(void);

  void playStartupSound(void);
};


#endif  //SIREN_HPP
