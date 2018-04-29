/**  Display model class
 *
 * #include "Glcd.hpp"
 * Created 10-01-17 By: Smitty
 *
 * Controls a graphical LCD from here: https://www.adafruit.com/product/250
 */

#ifndef GLCD_HPP
#define GLCD_HPP

//#include "ST7565.h"
#include <U8g2lib.h>
#include <SPI.h>
#include "../BaseModel/BaseModel.hpp"
#include "../Constants/Port.hpp"
#include "../Constants/Constants.hpp"
//#include "../../Controller/Logger/Logger.hpp"


// This class should have all the menus structured out,
// basically the controller should only have to worry about passing values into the functions here

// Model stores the structure of the menus
// Model stores the data related to each menu
// View stores the user chosen values in the Model
// View asks Controller which menus to display
// Controller responds to View based on values in Model
// Controller operates on the data stored in the Model



//JustBarelyLogo
#define Just_Barely_width 128
#define Just_Barely_height 64
static unsigned char Just_Barely_bits[] = {
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00,
   0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0xf8, 0x00, 0xe0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x02, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x01, 0x3c, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0xbc, 0xc3, 0x0f,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
   0x00, 0x3e, 0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
   0x03, 0x00, 0x00, 0x00, 0x30, 0x3e, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x80, 0x03, 0x00, 0x00, 0x00, 0x7e, 0x1f, 0x1c, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x03, 0x00, 0x00, 0xe0,
   0xff, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0,
   0x03, 0x00, 0x00, 0xfc, 0xff, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0xe0, 0x07, 0x00, 0x80, 0xff, 0xff, 0x1f, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x0f, 0x00, 0xf0, 0xff,
   0xff, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0,
   0x1f, 0x00, 0xff, 0xff, 0xff, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0xf0, 0x3f, 0xe0, 0xff, 0xff, 0xe3, 0x0f, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xff, 0xff, 0xff, 0xff,
   0xc0, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8,
   0xff, 0xff, 0xff, 0x3f, 0x80, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0xf8, 0xff, 0xff, 0xff, 0x0f, 0x00, 0x07, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xff, 0xff, 0xff, 0x03,
   0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8,
   0xff, 0xff, 0xff, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0xf8, 0xff, 0xff, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xff, 0xff, 0x0f, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0,
   0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0xf0, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xff, 0x3f, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0,
   0xff, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x0c, 0x0c,
   0x3f, 0xfc, 0x0f, 0xfc, 0x03, 0x3f, 0xfc, 0xc3, 0x3f, 0x03, 0x0c, 0x0c,
   0x00, 0xfc, 0x0c, 0x0c, 0x3f, 0xfc, 0x0f, 0xfc, 0x03, 0x3f, 0xfc, 0xc3,
   0x3f, 0x03, 0x0c, 0x0c, 0x00, 0x30, 0x0c, 0xcc, 0x00, 0xc0, 0x00, 0x0c,
   0xcc, 0xc0, 0x0c, 0xcc, 0x00, 0x03, 0x0c, 0x0c, 0x00, 0x30, 0x0c, 0xcc,
   0x00, 0xc0, 0x00, 0x0c, 0xcc, 0xc0, 0x0c, 0xcc, 0x00, 0x03, 0x0c, 0x0c,
   0x00, 0x30, 0x0c, 0x0c, 0x3f, 0xc0, 0x00, 0xfc, 0xc3, 0xc0, 0xfc, 0xc3,
   0x3f, 0x03, 0x30, 0x03, 0x00, 0x30, 0x0c, 0x0c, 0x3f, 0xc0, 0x00, 0xfc,
   0xc3, 0xc0, 0xfc, 0xc3, 0x3f, 0x03, 0x30, 0x03, 0x00, 0x30, 0x0c, 0x0c,
   0xc0, 0xc0, 0x00, 0x0c, 0xcc, 0xff, 0x0c, 0xcc, 0x00, 0x03, 0xc0, 0x00,
   0x00, 0x30, 0x0c, 0x0c, 0xc0, 0xc0, 0x00, 0x0c, 0xcc, 0xff, 0x0c, 0xcc,
   0x00, 0x03, 0xc0, 0x00, 0xc0, 0x30, 0x0c, 0xcc, 0xc0, 0xc0, 0x00, 0x0c,
   0xcc, 0xc0, 0x0c, 0xcc, 0x00, 0x03, 0xc0, 0x00, 0xc0, 0x30, 0x0c, 0xcc,
   0xc0, 0xc0, 0x00, 0x0c, 0xcc, 0xc0, 0x0c, 0xcc, 0x00, 0x03, 0xc0, 0x00,
   0x00, 0x0f, 0xf0, 0x03, 0x3f, 0xc0, 0x00, 0xfc, 0xc3, 0xc0, 0x0c, 0xcc,
   0x3f, 0xff, 0xc0, 0x00, 0x00, 0x0f, 0xf0, 0x03, 0x3f, 0xc0, 0x00, 0xfc,
   0xc3, 0xc0, 0x0c, 0xcc, 0x3f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00 };


#define Shutdown_width 36
#define Shutdown_height 55
static unsigned char Shutdown_bits[] = {
   0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x80,
   0x1f, 0x00, 0x00, 0x00, 0x8c, 0x1f, 0x00, 0x00, 0x00, 0x9e, 0x1f, 0x00,
   0x00, 0x00, 0xbf, 0x1f, 0x03, 0x00, 0x00, 0xbf, 0x9f, 0x07, 0x00, 0x18,
   0xbf, 0xdf, 0x0f, 0x00, 0x3c, 0xbf, 0xdf, 0x0f, 0x00, 0x7e, 0xbf, 0xdf,
   0x0f, 0x00, 0x7e, 0xbf, 0xdf, 0x0f, 0x00, 0x7e, 0xbf, 0xdf, 0x0f, 0x00,
   0x7e, 0xbf, 0xdf, 0x0f, 0x00, 0x7e, 0xbf, 0xdf, 0x0f, 0x00, 0x7e, 0xbf,
   0xdf, 0x0f, 0x00, 0x7e, 0xbf, 0xdf, 0x0f, 0x00, 0x7e, 0xbf, 0xdf, 0x0f,
   0x00, 0x7e, 0xbf, 0xdf, 0x0f, 0x00, 0x7e, 0xbf, 0xdf, 0x0f, 0x00, 0x7e,
   0xbf, 0xdf, 0x0f, 0x00, 0x7e, 0xbf, 0xdf, 0x0f, 0x00, 0x7e, 0xbf, 0xdf,
   0x0f, 0x00, 0xfe, 0xff, 0xdf, 0x0f, 0x00, 0xfe, 0xff, 0xff, 0x0f, 0x00,
   0xfe, 0xff, 0xff, 0x0f, 0x00, 0xfe, 0xff, 0xff, 0x0f, 0x00, 0xfe, 0xff,
   0xff, 0x8f, 0x03, 0xfe, 0xff, 0xff, 0xcf, 0x07, 0xfe, 0xff, 0xff, 0xef,
   0x0f, 0xfe, 0xff, 0xff, 0xef, 0x0f, 0xff, 0xff, 0xff, 0xef, 0x0f, 0xff,
   0xff, 0xff, 0xef, 0x0f, 0xff, 0xe7, 0xf3, 0xef, 0x0f, 0xff, 0xcf, 0xf9,
   0xef, 0x0f, 0xff, 0xcf, 0xf9, 0xef, 0x0f, 0xff, 0x9f, 0xfc, 0xef, 0x0f,
   0xff, 0x3f, 0xfe, 0xef, 0x0f, 0xff, 0x3f, 0xfe, 0xef, 0x0f, 0xff, 0x3f,
   0xfe, 0xef, 0x0f, 0xff, 0x3f, 0xfe, 0xef, 0x0f, 0xff, 0x9f, 0xfc, 0xff,
   0x07, 0xff, 0xcf, 0xf9, 0xff, 0x07, 0xff, 0xcf, 0xf9, 0xff, 0x07, 0xff,
   0xe7, 0xf3, 0xff, 0x03, 0xfe, 0xff, 0xff, 0xff, 0x03, 0xfc, 0xff, 0xff,
   0xff, 0x03, 0xfc, 0xff, 0xff, 0xff, 0x01, 0xfc, 0xff, 0xff, 0xff, 0x01,
   0xf8, 0xff, 0xff, 0xff, 0x00, 0xf0, 0xff, 0xff, 0x7f, 0x00, 0xf0, 0xff,
   0xff, 0x7f, 0x00, 0xc0, 0xff, 0xff, 0x3f, 0x00, 0x80, 0xff, 0xff, 0x1f,
   0x00, 0x00, 0xff, 0xff, 0x01, 0x00, 0x00, 0xe0, 0x3f, 0x00, 0x00 };


#define HV_batt_width 16
#define HV_batt_height 16
static const unsigned char HV_batt_bits[] = {
   0xc0, 0x03, 0xc0, 0x03, 0xf0, 0x0f, 0x08, 0x10, 0x08, 0x10, 0xe8, 0x17,
   0xe8, 0x17, 0x08, 0x10, 0xe8, 0x17, 0xe8, 0x17, 0x08, 0x10, 0xe8, 0x17,
   0xe8, 0x17, 0x08, 0x10, 0xf0, 0x0f, 0x00, 0x00 };

#define LV_Batt_width 16
#define LV_Batt_height 16
static const unsigned char LV_Batt_bits[] = {
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x18, 0x18, 0xfe, 0x7f,
   0xfe, 0x7f, 0x32, 0x4f, 0x32, 0x4f, 0x72, 0x66, 0xf2, 0x76, 0x82, 0x70,
   0x86, 0x79, 0xfe, 0x7f, 0xfe, 0x7f, 0x00, 0x00 };

#define o_fok_width 18
#define o_fok_height 18
static const unsigned char o_fok_bits[] = {
   0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x03, 0x00, 0x80, 0x04, 0x00,
   0xc0, 0x0c, 0x00, 0x40, 0x08, 0x00, 0x60, 0x1b, 0x00, 0x20, 0x13, 0x00,
   0x30, 0x33, 0x00, 0x10, 0x23, 0x00, 0x18, 0x63, 0x00, 0x08, 0x40, 0x00,
   0x0c, 0xc3, 0x00, 0x04, 0x83, 0x00, 0x06, 0x80, 0x01, 0xfc, 0xff, 0x00,
   0xf8, 0x7f, 0x00, 0x00, 0x00, 0x00 };

#define IMD_ERR_width 18
#define IMD_ERR_height 18
static const unsigned char IMD_ERR_bits[] = {
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x34, 0x73, 0x00,
   0x34, 0x93, 0x00, 0x34, 0x93, 0x00, 0xd4, 0x92, 0x00, 0xd4, 0x92, 0x00,
   0x54, 0x72, 0x00, 0x00, 0x00, 0x00, 0x10, 0x23, 0x00, 0x18, 0x63, 0x00,
   0x08, 0x43, 0x00, 0x08, 0x43, 0x00, 0x08, 0x40, 0x00, 0x18, 0x63, 0x00,
   0x10, 0x23, 0x00, 0x00, 0x00, 0x00 };

#define BMS_ERR_width 18
#define BMS_ERR_height 18
static unsigned char BMS_ERR_bits[] = {
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xde, 0xcc, 0x01,
   0xd2, 0x2c, 0x00, 0xce, 0x6c, 0x00, 0x52, 0x8b, 0x01, 0x52, 0x0b, 0x01,
   0x4e, 0xe9, 0x00, 0x00, 0x00, 0x00, 0x10, 0x23, 0x00, 0x18, 0x63, 0x00,
   0x08, 0x43, 0x00, 0x08, 0x43, 0x00, 0x08, 0x40, 0x00, 0x18, 0x63, 0x00,
   0x10, 0x23, 0x00, 0x00, 0x00, 0x00 };


#define water_temp_width 18
#define water_temp_height 18
static const unsigned char water_temp_bits[] = {
   0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x80, 0x07, 0x00, 0x80, 0xff, 0x00,
   0x80, 0xff, 0x00, 0x80, 0x07, 0x00, 0x80, 0x07, 0x00, 0x80, 0xff, 0x00,
   0x80, 0xff, 0x00, 0x80, 0x07, 0x00, 0x81, 0x07, 0x00, 0xe7, 0x1f, 0x00,
   0xbc, 0xf7, 0x03, 0x80, 0x07, 0x00, 0xc1, 0x0f, 0x00, 0xf3, 0xbf, 0x03,
   0xde, 0xef, 0x00, 0x80, 0x07, 0x00 };

#define OK_icon_width 16
#define OK_icon_height 16
static unsigned char OK_icon_bits[] = {
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x8e, 0x34, 0x91, 0x72,
   0x91, 0xf2, 0x91, 0xf1, 0x91, 0xf2, 0x91, 0x74, 0x8e, 0x34, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };




#define MODE_START_X 15
#define MODE_START_Y 20

#define BATT_BAR_START_X 19
#define HV_BAR_START_Y 48
#define LV_BAR_START_Y 48 //DEPRICATED
#define BAR_LENGTH 90
#define ERR_START_X 25
#define ERR_START_Y 45

class Glcd : public BaseModel
{
public:
    Glcd(void);
    ~Glcd(void);

    void update(void);

    void showBootLogo(void);
    void showShutdownLogo(void);
    void drawModeSelection(Stage);
    void drawBattBars(uint8_t lvBattPercent, uint8_t hvBattPercent);
    void setupBattBars(void);
    void drawOkIcon(void);
    void drawErrors(err_type);
    void clearAllErrors(void);
    /**  
     * Drafting up possible functions
     * 
     * void print(string);
     * void clear(void);
     * 
     * void showList(void);     //maybe a private function?
     * 
     * void setBacklightRgb(int r, int g, int b);
     * 
     */

    bool getDirtyBit(void); //if the buffer has been written to.
    void flushGlcdBuffer(void);
    void clearGlcdBuffer(void);

private:
    bool dirtyBit = false; //if buffer has been modified
    //private instance of the ST7565 object for our GLCD
     U8G2_ST7565_LM6059_F_4W_SW_SPI* display;

};


#endif  //GLCD_HPP
