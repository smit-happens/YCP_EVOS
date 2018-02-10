/**  Used in the verification process of the IMD circuit
 *
 * main.cpp
 * Created 2-07-18 By: Smitty
 *
 * NOTE: I know I know! global variables are bad, you could've made functions for that, yada yada
 *       This was made at 2am for testing a circuit so I don't wanna hear it
 */

#include <Arduino.h>
#include "SdFat.h"
#include "ST7565.h"


// Log file base name
#define FILE_BASE_NAME "IMDTest"

//for readability sake
#define PASS true
#define FAIL false

// File system object.
SdFatSdioEX sd;

// Log file.
SdFile file;

//JustBarelyLogo
const uint8_t JustBarelyLogo [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
0xE0, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0xC0, 0xF0, 0xFC, 0xFF, 0xFF, 0x1E, 0x38,
0x70, 0xE0, 0xC0, 0xC0, 0xC0, 0xC0, 0xE0, 0x60, 0x60, 0x20, 0x30, 0x30, 0x10, 0x18, 0x08, 0x08,
0x0C, 0x04, 0x04, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xF8, 0xEE, 0xFF,
0xFF, 0xFF, 0xF8, 0xF0, 0xE0, 0xC0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xC0, 0xC0, 0xC0,
0xE0, 0xE0, 0xE0, 0xE0, 0xF0, 0xF0, 0xF0, 0xF8, 0xF8, 0xF8, 0xFC, 0xFC, 0xFC, 0xFE, 0xFE, 0xFE,
0x7E, 0x5F, 0x3F, 0x3F, 0x2F, 0x5F, 0xDF, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0x00, 0x00, 0x00,
0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0x5F, 0x5F, 0x3F, 0x3F, 0x1F, 0x1F, 0x0F, 0x0F, 0x05, 0x07, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03,
0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00,
0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00,
0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80,
0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x01, 0x01, 0xFF, 0xFF, 0x01, 0x01,
0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x86, 0x86,
0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0xE0, 0xE0, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0xFF, 0xFF,
0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x19, 0x19, 0x19, 0x19,
0x19, 0x19, 0xE6, 0xE6, 0x00, 0x00, 0xFE, 0xFE, 0x61, 0x61, 0x61, 0x61, 0x61, 0x61, 0xFE, 0xFE,
0x00, 0x00, 0xFF, 0xFF, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0xE6, 0xE6, 0x00, 0x00, 0xFF, 0xFF,
0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x07, 0x07, 0x18, 0x18, 0xE0, 0xE0, 0x18, 0x18, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x06, 0x06, 0x06, 0x06, 0x01, 0x01, 0x00, 0x00,
0x00, 0x00, 0x01, 0x01, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01,
0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x06, 0x06, 0x06, 0x06,
0x06, 0x06, 0x01, 0x01, 0x00, 0x00, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07,
0x00, 0x00, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x00, 0x00, 0x07, 0x07,
0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x00, 0x00, 0x07, 0x07, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

////////////////////////////////////////////////////////////////////////////
//Pin declarations
//Start/Stop Button
const uint8_t BTN         = 23;

//TODO: figure out what these actually are
const uint8_t IMD_POWER             = 38;
const uint8_t IMD_ERROR             = 14;
const uint8_t SAFETY_CIRCUIT_RESULT = 15;

//GLCD + RGB Backlight
const uint8_t SID               = 33;
const uint8_t SCLK              = 34;
const uint8_t RS                = 35;
const uint8_t _RST              = 36;
const uint8_t _CS               = 37;
// const uint8_t RLED              = 30;    //not used
// const uint8_t GLED              = 29;    //not used
// const uint8_t BLED              = 10;    //not used
//END Pin declarations
////////////////////////////////////////////////////////////////////////////

volatile bool buttonPress = false;

enum TestStage
{
    BOOT_ERROR_OFF,
    STANDBY_ERROR_ON,
    STANDBY_ERROR_OFF,
    //SHUTDOWN,
    BOOT_ERROR_ON,
    LATCH_ERROR_OFF
};

//used for determining which stage we're in & resetting
TestStage currentStage;

//ST7565 display(SID, SCLK, RS, _RST, _CS); //example input params
ST7565 glcd(SID, SCLK, RS, _RST, _CS);

//counter for current test
uint32_t testCount = 0;
uint32_t passCount = 0;
uint32_t failCount = 0;

//time since testing start
double testStart = millis();


/** 
 * @brief  Gets the time for the current test run
 * @note   
 * @retval Milliseconds since start of test
 */
double getTime(void)
{
    return millis() - testStart;
}

void relayOpenDelay(void)
{
    delay(20);  // delay for relay to open - usually takes ~6ms
}


//------------------------------------------------------------------------------
// ISR for the button press
void buttonISR(void)
{
    //ugly but it works
    buttonPress = true;
}


//------------------------------------------------------------------------------
// Restart the test to a "happy start"
void restartTest(void)
{
    digitalWriteFast(IMD_POWER, LOW);
    digitalWriteFast(IMD_ERROR, LOW);

    //wait a second for it to "settle"
    delay(100);

    //increment for next test
    testCount++;

    //setting the test stage to the first one
    currentStage = BOOT_ERROR_OFF;

    //converting from int to char
    char testCountChar[20];
    char testStageChar[20];
    //testCount to char array
    String str = String(testCount);
    str.toCharArray(testCountChar, 20);
    //testStage to char array
    str = String(currentStage);
    str.toCharArray(testStageChar, 20);

    //user feedback
    glcd.clear();
    glcd.drawstring(0, 0, "Current test count:");
    glcd.drawstring(0, 1, testCountChar);
    glcd.drawstring(0, 2, "Test stage:");
    glcd.drawstring(0, 3, testStageChar);
    glcd.drawstring(0, 4, "Press the button");
    glcd.drawstring(0, 5, "to stop");
    glcd.display();

}


//------------------------------------------------------------------------------
// Write data header.
void writeHeader() 
{
    //Time, Pass/Fail, Description
    file.println(F("Milliseconds,Test_Number,Test_Stage,Test_Result,Description"));
}


//------------------------------------------------------------------------------
// Log a data record.
void logRecord(int testStage, bool result, String description) 
{
    if(result && currentStage == LATCH_ERROR_OFF){
        passCount++;
    }
    else if(!result) {
        failCount++;
    }

    // Write to file
    file.print(getTime());          //time in msec
    file.write(',');
    file.print(testCount);          //test number
    file.write(',');
    file.print(testStage);          //stage of the current test
    file.write(',');
    file.print(result);             //1 = pass; 0 = fail
    file.write(',');
    file.println(description);      //short description
}


//==============================================================================
// Error messages stored in flash.
#define error(msg) sd.errorHalt(F(msg))
//------------------------------------------------------------------------------
int main(void) 
{
    //configuring the Pins connected to the IMD
    pinMode(IMD_POWER, OUTPUT);
    pinMode(IMD_ERROR, OUTPUT);
    pinMode(SAFETY_CIRCUIT_RESULT, INPUT);

    //initialize the GLCD
    glcd.begin(0x18);
    glcd.clear();

    // draw the bitmap
    glcd.drawbitmap(0, 0, JustBarelyLogo, 128, 64, BLACK);
    glcd.display();

    //savor the logo
    delay(2000);


    //start logging prompt
    glcd.clear();
    glcd.drawstring(0, 0, "Press the button");
    glcd.drawstring(0, 1, "to start");
    glcd.display();

    //attaching the interrupt to the button when it changes b/t high & low
    attachInterrupt(BTN, buttonISR, RISING);

    //wait for button press and reset button state
    buttonPress = false;
    while (!buttonPress) 
    {
        SysCall::yield();
    }
    //"debouncing" delay
    delay(10);
    buttonPress = false;


    // Initialize sdcard
    if (!sd.begin()) 
    {
        sd.initErrorHalt();
    }

    //creating filename
    const uint8_t BASE_NAME_SIZE = sizeof(FILE_BASE_NAME) - 1;
    char fileName[20] = FILE_BASE_NAME "00.csv";

    // Find an unused file name.
    while (sd.exists(fileName)) 
    {
        if (fileName[BASE_NAME_SIZE + 1] != '9') 
        {
            fileName[BASE_NAME_SIZE + 1]++;
        }
        else if (fileName[BASE_NAME_SIZE] != '9') 
        {
            fileName[BASE_NAME_SIZE + 1] = '0';
            fileName[BASE_NAME_SIZE]++;
        }
        else
        {
            error("Can't create file name");
        }
    }

    //creating the new log file
    if (!file.open(fileName, O_CREAT | O_WRITE | O_EXCL)) 
    {
        error("file.open");
    }

    // Write data header.
    writeHeader();

    //clock for the current test cycle
    testStart = millis();

    //used for timing certain test conditions
    double stopWatch = 0;

    //a check for if the test failed or not
    bool isFailed = true;

    //setting the current stage to the first one
    currentStage = BOOT_ERROR_OFF;

    //converting from int to char
    char testCountChar[20];
    char testStageChar[20];
    char testPassCountChar[20];
    char testFailCountChar[20];
    //testCount to char array
    String str = String(testCount);
    str.toCharArray(testCountChar, 20);
    //testStage to char array
    str = String(currentStage);
    str.toCharArray(testStageChar, 20);
    // passCount to char array
    str = String(passCount);
    str.toCharArray(testPassCountChar, 20);
    // passCount to char array
    str = String(failCount);
    str.toCharArray(testFailCountChar, 20);

    //stop logging prompt
    glcd.clear();
    glcd.drawstring(0, 0, "Test count:");
    glcd.drawstring(0, 1, testCountChar);
    glcd.drawstring(0, 2, "Pass count:");
    glcd.drawstring(0, 3, testPassCountChar);
    glcd.drawstring(0, 4, "Fail count:");
    glcd.drawstring(0, 5, testFailCountChar);
    glcd.drawstring(0, 6, "Test stage:");
    glcd.drawstring(0, 7, testStageChar);
    glcd.drawstring(0, 8, "Press btn to stop");
    glcd.display();


    //------------------------------------------------------------------------------
    while(1) 
    {
        switch(currentStage)
        {
            case BOOT_ERROR_OFF:
                //test step 1 boot w/ no error
                digitalWriteFast(IMD_POWER, HIGH);
                digitalWriteFast(IMD_ERROR, LOW);
                delay(50);

                if(!digitalReadFast(SAFETY_CIRCUIT_RESULT)) 
                {
                    //log false activation
                    logRecord(BOOT_ERROR_OFF, FAIL, "False activation on startup");
                    //restart tests
                    restartTest();
                }
                else 
                {
                    //log pass on Bootup w/ no error
                    logRecord(BOOT_ERROR_OFF, PASS, "No error detected on startup");
                    
                    //proceed to next test
                    currentStage = STANDBY_ERROR_ON;
                }
                //END test step 1 boot w/ no error
            break;


            case STANDBY_ERROR_ON:
                //test step 2 trigger error condition
                digitalWriteFast(IMD_ERROR, HIGH);
                
                relayOpenDelay();

                //setting a "stopWatch" for a 100ms interval
                stopWatch = getTime() + 100;

                //yes/no check for test
                isFailed = false;
                while(stopWatch >= getTime()) 
                {
                    if(digitalReadFast(SAFETY_CIRCUIT_RESULT))
                    {
                        isFailed = true;
                    }
                }

                //check if the test failed or not
                if(isFailed)
                {
                    //log failure
                    logRecord(STANDBY_ERROR_ON, FAIL, "Relay failed to open within 100ms of low to high error state");
                    //restart tests
                    restartTest();
                }
                else
                {
                    //log successful test portion
                    logRecord(STANDBY_ERROR_ON, PASS, "Relay opened within 100ms of error state");

                    //proceed to next test
                    currentStage = STANDBY_ERROR_OFF;
                }
                //END test step 2 trigger error condition
            break;


            case STANDBY_ERROR_OFF:
                //test step 3 standby error off (IMD shutdown circuit is latched)
                digitalWriteFast(IMD_ERROR, LOW);

                //setting a "stopWatch" for a 3000ms interval
                stopWatch = getTime() + 3000;

                //yes/no check for test
                isFailed = false;
                while(stopWatch >= getTime()) 
                {
                    if(digitalReadFast(SAFETY_CIRCUIT_RESULT))
                    {
                        isFailed = true;
                    }
                }

                //check if the test failed or not
                if(isFailed)
                {
                    //log failure
                    logRecord(STANDBY_ERROR_OFF, FAIL, "Relay Failed to latch error state");
                    //restart tests
                    restartTest();
                }
                else
                {
                    //log successful test portion
                    logRecord(STANDBY_ERROR_OFF, PASS, "Error state latch passed for 3 seconds");

                    //proceed to next test
                    currentStage = BOOT_ERROR_ON;
                }
                //END test step 3 standby error off
            break;


            case BOOT_ERROR_ON:
                //Power down IMD
                digitalWriteFast(IMD_POWER, LOW);

                //wait a second for it to "settle"
                delay(500);
                //END power down IMD

                //test step 4 Boot w/ error state
                digitalWriteFast(IMD_ERROR, HIGH);
                digitalWriteFast(IMD_POWER, HIGH);

                //setting a "stopWatch" for a 3000ms interval
                //stopWatch = getTime() + 3000;

                //yes/no check for test
                isFailed = false;
                delay(3000);    // response time of the circuit timer
                if(digitalReadFast(SAFETY_CIRCUIT_RESULT)) 
                {
                    isFailed = true;
                }

                //check if the test failed or not
                if(isFailed)
                {
                    //log failure
                    logRecord(BOOT_ERROR_ON, FAIL, "Failed to respond to IMD error on boot");
                    //restart tests
                    restartTest();
                }
                else
                {
                    //log successful test portion
                    logRecord(BOOT_ERROR_ON, PASS, "Boot with error state passed for 3 seconds");

                    //proceed to next test
                    currentStage = LATCH_ERROR_OFF;
                }
                //END test step 4 Boot w/ error state
            break;


            case LATCH_ERROR_OFF:
                //test step 5 latch from boot error
                digitalWriteFast(IMD_ERROR, LOW);

                //setting a "stopWatch" for a 1000ms interval
                stopWatch = getTime() + 1000;

                //yes/no check for test
                isFailed = false;
                while(stopWatch >= getTime()) 
                {
                    if(digitalReadFast(SAFETY_CIRCUIT_RESULT)) 
                    {
                        isFailed = true;
                    }
                }

                //check if the test failed or not
                if(isFailed)
                {
                    //log failure
                    logRecord(LATCH_ERROR_OFF, FAIL, "IMD Shutdown circuit failed to latch");
                    //restart tests
                    restartTest();
                }
                else
                {
                    //log successful test portion
                    logRecord(LATCH_ERROR_OFF, PASS, "IMD Shutdown circuit latched successfully");

                    //proceed to next test (restart tests)
                    restartTest();
                }
                //END test step 5 latch with boot error
            break;
        } //END GIANT SWITCH


           //testCount to char array
        String str = String(testCount);
        str.toCharArray(testCountChar, 20);
        //testStage to char array
        str = String(currentStage);
        str.toCharArray(testStageChar, 20);
        // passCount to char array
        str = String(passCount);
        str.toCharArray(testPassCountChar, 20);
        // passCount to char array
        str = String(failCount);
        str.toCharArray(testFailCountChar, 20);

        //stop logging prompt
        glcd.clear();
        glcd.drawstring(0, 0, "Test count:");
        glcd.drawstring(0, 1, testCountChar);
        glcd.drawstring(0, 2, "Pass count:");
        glcd.drawstring(0, 3, testPassCountChar);
        glcd.drawstring(0, 4, "Fail count:");
        glcd.drawstring(0, 5, testFailCountChar);
        glcd.drawstring(0, 6, "Test stage:");
        glcd.drawstring(0, 7, testStageChar);
        glcd.drawstring(0, 8, "Press btn to stop");
        glcd.display();


        // Force data to SD and update the directory entry to avoid data loss.
        if (!file.sync() || file.getWriteError()) {
            error("write error");
        }

        //stops logging and halts Teensy
        if (buttonPress) 
        {
            // Close file and stop.
            file.close();
            glcd.clear();
            glcd.drawstring(0,0,"Done Testing");
            glcd.display();
            SysCall::halt();
        }
        ///////////////////////////////////

    }

    return 0;
}