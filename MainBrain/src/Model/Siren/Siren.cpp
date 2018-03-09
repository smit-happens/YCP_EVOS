/**  Siren used for playing the startup sound of the car
 *
 * Bspd.cpp
 * Created 12-20-17  By: Smitty
 *
 * A longer description.
 */

#include "Siren.hpp"


/** 
 * @brief  Siren constructor
 */
Siren::Siren(void)
{
    pinMode(MB_SIREN, OUTPUT);
}


/** 
 * @brief  Pretty self explanitory
 * @note   Play the sound either through tones or some .wav file
 * @retval None
 */
void Siren::playStartupSound(void)
{
    //record the current time in milliseconds
    uint32_t currentTime = millis();

    //start the siren (RTD sound)
    digitalWriteFast(MB_SIREN, HIGH);

    //wait for 2 seconds
    while((millis() - currentTime) < TIME_SIREN)
    {
        ;
    }
    
    //stop the siren
    digitalWriteFast(MB_SIREN, LOW);
}