/**  Correlate port name with the pin number on the Teensy 3.6
 *
 * #include Port.hpp
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

#ifndef PORT_HPP
#define PORT_HPP

#include <Arduino.h>


//Status LEDs (0 = Bad; 1 = Good)
const uint8_t RTD_LED       = 0;   //[0,1] Digital Output
const uint8_t BMS_LED       = 1;   //[0,1] Digital Output
const uint8_t IMD_LED       = 2;   //[0,1] Digital Output
const uint8_t BSPD_LED      = 3;   //[0,1] Digital Output
const uint8_t PEDAL_LED     = 4;   //[0,1] Digital Output

//Precharging indicator LED
const uint8_t PRE_LED       = 35;  //[0,1] Digital Output

//Speaker for the startup sound
const uint8_t SPEAKER       = 5;   //[0,1] Digital Output

//Status lines for the saftey subsystems
const uint8_t IMD_STATUS    = 7;   //[0,1] Digital Input
const uint8_t BSPD_STATUS   = 8;   //[0,1] Digital Input

//SPI expansion
const uint8_t EX_CS2           = 20;  //To be determined
const uint8_t EX_CS1           = 9;   //To be determined
const uint8_t EX_CS0           = 10;  //To be determined
const uint8_t EX_MOSI          = 11;  //
const uint8_t EX_MISO          = 12;  //
const uint8_t EX_SCK           = 13;  //

//Pedal potentiometers
const uint8_t BRAKE         = 14;  //[0-3.3v] Analog Input
const uint8_t GAS_LIN       = 15;  //[0-3.3v] Analog Input
const uint8_t GAS_LOG       = 16;  //[0-3.3v] Analog Input

//Digital signal connection to the Unitek
const uint8_t DRIVE_EN      = 23;  //[0,1] Digital Output
const uint8_t SCADA_OK      = 22;  //[0,1] Digital Output
const uint8_t START_PRE     = 21;  //[0,1] Digital Output
const uint8_t DONE_PRE      = 6;   //[0,1] Digital Input
const uint8_t DOUT2         = 19;  //[0,1] Digital Input
const uint8_t BTB           = 18;  //[0,1] Digital Input
const uint8_t SPARE         = 17;  //[0,1] Digital Input

//GLCD screen data
// SID:     Serial data out
// SCLK:    Serial clock out
// RS/A0:   Data/Command select
// _RST:    LCD reset
// _CS:     LCD chip select
const uint8_t SID           = 24;  //ST7565 display Output
const uint8_t SCLK          = 25;  //ST7565 display Output
const uint8_t RS            = 26;  //ST7565 display Output
const uint8_t _RST          = 27;  //ST7565 display Output
const uint8_t _CS           = 28;  //ST7565 display Output

//GLCD RGB backlight
const uint8_t R             = 37;  //[0,1] PWM Output
const uint8_t G             = 38;  //[0,1] PWM Output
const uint8_t B             = 39;  //[0,1] PWM Output

//Dashboard buttons
const uint8_t PRE_BTN       = 36;  //[0,1] Digital Input
const uint8_t RTD_BTN       = 29;  //[0,1] Digital Input
const uint8_t ENC_BTN       = 30;  //[0,1] Digital Input

//Encoder output
const uint8_t ENC_PINA      = 31;  //[0,1] Digital Input
const uint8_t ENC_PINB      = 32;  //[0,1] Digital Input

//CAN connection to the CAN chip
const uint8_t CANOUT        = 33;  //FlexCAN library Output
const uint8_t CANIN         = 34;  //FlexCAN library Input

//Temperature sensing of the cooling system radiator
//TODO: Determine what values sensor will actually provide
const uint8_t RAD_OUT_TEMP  = A21; //[0-?] Analog Input
const uint8_t RAD_IN_TEMP   = A22; //[0-?] Analog Input


#endif  //PORTCONSTANTS_HPP
