/**  Display model class
 *
 * #include "GlcdTest.hpp"
 * Created 3-12-18 By: Smitty
 *
 * Controls a graphical LCD from here: https://www.adafruit.com/product/250
 */

#ifndef GLCDTEST_HPP
#define GLCDTEST_HPP

// #include "ST7565.h"
#include "../BaseModelTest/BaseModelTest.hpp"


// This class should have all the menus structured out,
// basically the controller should only have to worry about passing values into the functions here

// Model stores the structure of the menus
// Model stores the data related to each menu
// View stores the user chosen values in the Model
// View asks Controller which menus to display
// Controller responds to View based on values in Model
// Controller operates on the data stored in the Model



class GlcdTest : public BaseModelTest
{
public:
    GlcdTest(void);
    ~GlcdTest(void);

    void update(void);

    /**  
     * Drafting up possible functions
     * 
     * void print(string);
     * void clear(void);
     * 
     * void showBootLogo(void);
     * void showList(void);     //maybe a private function?
     * 
     * void setBacklightRgb(int r, int g, int b);
     */


private:
    enum NotificationCategory
    {
    Notification,
    Warning,
    Alert,
    Error
    };

    //private instance of the ST7565 object for our GLCD
    // ST7565* display;

};


#endif  //GLCDTEST_HPP
