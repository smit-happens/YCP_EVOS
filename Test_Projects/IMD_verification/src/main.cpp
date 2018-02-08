/**  A one line description of the class.
 *
 * main.cpp
 * Created 2-07-18 By: Smitty
 *
 * A longer description.
 */

#include <Arduino.h>
#include "SdFat.h"

// Interval between data records in milliseconds.
// The interval must be greater than the maximum SD write latency plus the
// time to acquire and write data to the SD to avoid overrun errors.
// Run the bench example to check the quality of your SD card.
const uint32_t SAMPLE_INTERVAL_MS = 100;

// Log file base name.  Must be six characters or less.
#define FILE_BASE_NAME "pedalTest"
//------------------------------------------------------------------------------
// File system object.
SdFatSdioEX sd;

// Log file.
SdFile file;

// Time in micros for next data record.
uint32_t logTime;

//==============================================================================
// User functions.  Edit writeHeader() and logData() for your requirements.

const uint8_t ANALOG_PIN = 32;
//------------------------------------------------------------------------------
// Write data header.
void writeHeader() {
    file.println(F("Milliseconds,Pedal_value"));
}
//------------------------------------------------------------------------------
// Log a data record.
void logData() {
    uint16_t data;

    // Read all channels to avoid SD write latency between readings.
    data = analogRead(ANALOG_PIN);
    // Write data to file.  Start with log time in micros.
    file.print(logTime/1000);

    // Write ADC data to CSV record.
    file.write(',');
    file.println(data);

    Serial.println(data);
}
//==============================================================================
// Error messages stored in flash.
#define error(msg) sd.errorHalt(F(msg))
//------------------------------------------------------------------------------
int main(void) {
    const uint8_t BASE_NAME_SIZE = sizeof(FILE_BASE_NAME) - 1;
    char fileName[20] = FILE_BASE_NAME "00.csv";

    Serial.begin(9600);
    
    // Wait for USB Serial 
    while (!Serial) {
        SysCall::yield();
    }
    delay(1000);

    Serial.println(F("Type any character to start"));
    while (!Serial.available()) {
        SysCall::yield();
    }
    
    // Initialize at the highest speed supported by the board that is
    // not over 50 MHz. Try a lower speed if SPI errors occur.
    if (!sd.begin()) {
        sd.initErrorHalt();
    }

    // Find an unused file name.
    while (sd.exists(fileName)) {
        if (fileName[BASE_NAME_SIZE + 1] != '9') {
        fileName[BASE_NAME_SIZE + 1]++;
        } else if (fileName[BASE_NAME_SIZE] != '9') {
        fileName[BASE_NAME_SIZE + 1] = '0';
        fileName[BASE_NAME_SIZE]++;
        } else {
        error("Can't create file name");
        }
    }
    if (!file.open(fileName, O_CREAT | O_WRITE | O_EXCL)) {
        error("file.open");
    }
    // Read any Serial data.
    do {
        delay(10);
    } while (Serial.available() && Serial.read() >= 0);

    Serial.print(F("Logging to: "));
    Serial.println(fileName);
    Serial.println(F("Type any character to stop"));

    // Write data header.
    writeHeader();

    // Start on a multiple of the sample interval.
    logTime = micros()/(1000UL*SAMPLE_INTERVAL_MS) + 1;
    logTime *= 1000UL*SAMPLE_INTERVAL_MS;

    //------------------------------------------------------------------------------
    while(1) {
    // Time for next record.
    logTime += 1000UL*SAMPLE_INTERVAL_MS;

    // Wait for log time.
    int32_t diff;
    do {
        diff = micros() - logTime;
    } while (diff < 0);

    // Check for data rate too high.
    if (diff > 10) {
        error("Missed data record");
    }

    logData();

    // Force data to SD and update the directory entry to avoid data loss.
    if (!file.sync() || file.getWriteError()) {
        error("write error");
    }

    if (Serial.available()) {
        // Close file and stop.
        file.close();
        Serial.println(F("Done"));
        SysCall::halt();
    }
    }
}