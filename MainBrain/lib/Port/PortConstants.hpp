/**  Correlate port name with the pin number on the Teensy 3.6
 *
 * #include PortConstants.hpp
 * Created 12-19-17 By: Smitty
 * 
 * The port names correlate to the names given to them in the
 * original schematic document
 * 
 * NOTE: Due to the format of variable names in C++, the following
 *       conversion is made between the schematic and C++ code
 *       _RST == /RST
 *       _CS  == /CS
 */

#ifndef PORTCONSTANTS_HPP
#define PORTCONSTANTS_HPP

#include <Arduino.h>


//Status LEDs (0 = Bad; 1 = Good)
const int RTD_LED       = 0;   //[0,1] Digital Output
const int BMS_LED       = 1;   //[0,1] Digital Output
const int IMD_LED       = 2;   //[0,1] Digital Output
const int BSPD_LED      = 3;   //[0,1] Digital Output
const int PEDAL_LED     = 4;   //[0,1] Digital Output

//Precharging indicator LED
const int PRE_LED       = 35;  //[0,1] Digital Output

//Speaker for the startup sound
const int SPEAKER       = 5;   //[0,1] Digital Output

//Status lines for the saftey subsystems
const int IMD_STATUS    = 7;   //[0,1] Digital Input
const int BSPD_STATUS   = 8;   //[0,1] Digital Input

//SPI expansion
const int CS2           = 20;  //To be determined
const int CS1           = 9;   //To be determined
const int CS0           = 10;  //To be determined
const int MOSI          = 11;  //
const int MISO          = 12;  //
const int SCK           = 13;  //

//Pedal potentiometers
const int BRAKE         = 14;  //[0-3.3v] Analog Input
const int GAS_LIN       = 15;  //[0-3.3v] Analog Input
const int GAS_LOG       = 16;  //[0-3.3v] Analog Input

//Digital signal connection to the Unitek
const int DRIVE_EN      = 23;  //[0,1] Digital Output
const int SCADA_OK      = 22;  //[0,1] Digital Output
const int START_PRE     = 21;  //[0,1] Digital Output
const int DONE_PRE      = 6;   //[0,1] Digital Input
const int DOUT2         = 19;  //[0,1] Digital Input
const int BTB           = 18;  //[0,1] Digital Input
const int SPARE         = 17;  //[0,1] Digital Input

//GLCD screen data
const int SID           = 24;  //ST7565 glcd() Input
const int SCLK          = 25;  //ST7565 glcd() Input
const int RS            = 26;  //ST7565 glcd() Input
const int _RST          = 27;  //ST7565 glcd() Input
const int _CS           = 28;  //ST7565 glcd() Input

//GLCD RGB backlight
const int R             = 37;  //[0,1] PWM Output
const int G             = 38;  //[0,1] PWM Output
const int B             = 39;  //[0,1] PWM Output

//Dashboard buttons
const int PRE_BTN       = 36;  //[0,1] Digital Input
const int RTD_BTN       = 29;  //[0,1] Digital Input
const int ENC_BTN       = 30;  //[0,1] Digital Input

//Encoder output
const int ENC_PINA      = 31;  //[0,1] Digital Input
const int ENC_PINB      = 32;  //[0,1] Digital Input

//CAN connection to the CAN chip
const int CANOUT        = 33;  //FlexCAN library Output
const int CANIN         = 34;  //FlexCAN library Input

//Temperature sensing of the cooling system radiator
//TODO: Determine what values sensor will actually provide
const int RAD_OUT_TEMP  = A21; //[0-?] Analog Input
const int RAD_IN_TEMP   = A22; //[0-?] Analog Input


#endif  //PORTCONSTANTS_HPP
