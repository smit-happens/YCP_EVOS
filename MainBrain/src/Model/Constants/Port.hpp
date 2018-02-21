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


/*
  ____         __      _                      _                   _
 / ___|  __ _ / _| ___| |_ _   _    ___ _   _| |__  ___ _   _ ___| |_ ___ _ __ ___  ___
 \___ \ / _` | |_ / _ \ __| | | |  / __| | | | '_ \/ __| | | / __| __/ _ \ '_ ` _ \/ __|
  ___) | (_| |  _|  __/ |_| |_| |  \__ \ |_| | |_) \__ \ |_| \__ \ ||  __/ | | | | \__ \
 |____/ \__,_|_|  \___|\__|\__, |  |___/\__,_|_.__/|___/\__, |___/\__\___|_| |_| |_|___/
                           |___/                        |___/
*/
const uint8_t IMD_STATUS    = 28;   //[0,1] Digital Input
const uint8_t BMS_STATUS    = 29;   //[0,1] Digital Input


/*
  ___ ____   ____
 |_ _|___ \ / ___|
  | |  __) | |
  | | / __/| |___
 |___|_____|\____|

*/
const uint8_t I2C_SCL           = 57;  //To be determined
const uint8_t I2C_SDA           = 56;  //To be determined


/*
  ____  ____ ___ 
 / ___||  _ \_ _|
 \___ \| |_) | | 
  ___) |  __/| | 
 |____/|_|  |___|
                 
*/
const uint8_t SPI_CS1           = 43;  //To be determined
const uint8_t SPI_CS0           = 54;  //To be determined
const uint8_t SPI_SCK           = 53;  //
const uint8_t SPI_MOSI          = 52;  //
const uint8_t SPI_MISO          = 51;  //


/*
  ____          _       _
 |  _ \ ___  __| | __ _| |___
 | |_) / _ \/ _` |/ _` | / __|
 |  __/  __/ (_| | (_| | \__ \
 |_|   \___|\__,_|\__,_|_|___/

*/
//Brake overtravel switch
const uint8_t BRAKE_OVERTRAVEL  = 13;  //[0,1] Digital Input

//Brake light
const uint8_t BRAKE_LIGHT       = 37;  //[0,1] Digital Output

//Potentiometers
const uint8_t BRAKE             = 16;  //[0-8195] 13-bit Analog Input
const uint8_t GAS_LIN           = 15;  //[0-8195] 13-bit Analog Input
const uint8_t GAS_LOG           = 14;  //[0-8195] 13-bit Analog Input


/*
  _____ ____      ____            _             _    _                         _
 |_   _/ ___|    / ___|___  _ __ | |_ _ __ ___ | |  | |__   ___   __ _ _ __ __| |
   | | \___ \   | |   / _ \| '_ \| __| '__/ _ \| |  | '_ \ / _ \ / _` | '__/ _` |
   | |  ___) |  | |__| (_) | | | | |_| | | (_) | |  | |_) | (_) | (_| | | | (_| |
   |_| |____/    \____\___/|_| |_|\__|_|  \___/|_|  |_.__/ \___/ \__,_|_|  \__,_|

*/
//Unitek logic board
const uint8_t SCADA_OK          = 23;  //[0,1] Digital Output
const uint8_t DRIVE_EN          = 22;  //[0,1] Digital Output
const uint8_t START_PRE         = 21;  //[0,1] Digital Output
const uint8_t DONE_PRE          = 20;  //[0,1] Digital Input
const uint8_t DOUT2             = 19;  //[0,1] Digital Input
const uint8_t BTB               = 18;  //[0,1] Digital Input
const uint8_t SPARE             = 17;  //[0,1] Digital Input


/*
   ____ _     ____ ____
  / ___| |   / ___|  _ \    ___  ___ _ __ ___  ___ _ __
 | |  _| |  | |   | | | |  / __|/ __| '__/ _ \/ _ \ '_ \
 | |_| | |__| |___| |_| |  \__ \ (__| | |  __/  __/ | | |
  \____|_____\____|____/   |___/\___|_|  \___|\___|_| |_|

*/
//Data lines
// SID:     Serial data out
// SCLK:    Serial clock out
// RS/A0:   Data/Command select
// _RST:    LCD reset
// _CS:     LCD chip select
const uint8_t SID               = 8;  //ST7565 display Output
const uint8_t SCLK              = 9;  //ST7565 display Output
const uint8_t RS                = 10;  //ST7565 display Output
const uint8_t _RST              = 11;  //ST7565 display Output
const uint8_t _CS               = 12;  //ST7565 display Output

//RGB backlight
const uint8_t R                 = 7;  //[0,1] PWM Output
const uint8_t G                 = 6;  //[0,1] PWM Output
const uint8_t B                 = 5;  //[0,1] PWM Output


/*
  ____            _     _                         _
 |  _ \  __ _ ___| |__ | |__   ___   __ _ _ __ __| |
 | | | |/ _` / __| '_ \| '_ \ / _ \ / _` | '__/ _` |
 | |_| | (_| \__ \ | | | |_) | (_) | (_| | | | (_| |
 |____/ \__,_|___/_| |_|_.__/ \___/ \__,_|_|  \__,_|

*/
//Buttons
const uint8_t PRE_BTN           = 47;  //[0,1] Digital Input
const uint8_t RTD_BTN           = 45;  //[0,1] Digital Input
const uint8_t ENC_BTN           = 27;  //[0,1] Digital Input
const uint8_t WAYNE_BTN         = 32;  //[0,1] Digital Input
const uint8_t SHUTDOWN_BTN      = 44;  //[0,1] Digital Input
const uint8_t STANDBY_BTN       = 46;  //[0,1] Digital Input

//Switches
const uint8_t REVERSE_SW        = 41;  //[0,1] Digital Input

//Encoder
const uint8_t ENC_PINA          = 25;  //[0,1] Digital Input
const uint8_t ENC_PINB          = 26;  //[0,1] Digital Input

//Status LEDs (0 = Bad; 1 = Good TODO: see if this is still true)
const uint8_t RTD_LED           = 0;   //[0,1] Digital Output
const uint8_t BMS_LED           = 1;   //[0,1] Digital Output
const uint8_t PEDAL_LED         = 2;   //[0,1] Digital Output
const uint8_t IMD_LED           = 3;   //[0,1] Digital Output
const uint8_t REVERSE_LED       = 4;   //[0,1] Digital Output
const uint8_t WAYNE_LED         = 24;  //[0,1] Digital Output
//Indicator LED for the energized state
const uint8_t ENERGIZE_LED      = 31;  //[0,1] Digital Output

//Siren
const uint8_t SIREN             = 30;   //[0,1] Digital Output


/*
   ____    _    _   _
  / ___|  / \  | \ | |
 | |     / _ \ |  \| |
 | |___ / ___ \| |\  |
  \____/_/   \_\_| \_|

*/
//connection to the CAN chip (MCP2562)
const uint8_t CAN_TX            = 33;  //FlexCAN library Output
const uint8_t CAN_RX            = 34;  //FlexCAN library Input


/*
   ____            _ _                ____            _
  / ___|___   ___ | (_)_ __   __ _   / ___| _   _ ___| |_ ___ _ __ ___
 | |   / _ \ / _ \| | | '_ \ / _` |  \___ \| | | / __| __/ _ \ '_ ` _ \
 | |__| (_) | (_) | | | | | | (_| |   ___) | |_| \__ \ ||  __/ | | | | |
  \____\___/ \___/|_|_|_| |_|\__, |  |____/ \__, |___/\__\___|_| |_| |_|
                             |___/          |___/
*/
//Pump control
const uint8_t PUMP_CTRL         = 48;  //[0,1] Digital Output
//Temperature sensing
const uint8_t RAD_OUTLET_TEMP   = A17; //[0-8195] 13-bit Analog Input
const uint8_t RAD_INLET_TEMP    = A16; //[0-8195] 13-bit Analog Input


/*
  ____        _   _
 | __ )  __ _| |_| | ___   __ _
 |  _ \ / _` | __| |/ _ \ / _` |
 | |_) | (_| | |_| | (_) | (_| |
 |____/ \__,_|\__|_|\___/ \__, |
                          |___/
*/
//GLV Battery logistics (Batlog)
const uint8_t BAT_MEASURE       = A24; //[0-8195] 13-bit Analog Input


#endif  //PORTCONSTANTS_HPP
