/**  A one line description of the class.
 *
 * Logger.cpp
 * Created 10-02-17 By: Smitty
 *
 * A longer description.
 */

#include "Logger.hpp"


//---------------------------------------------------------------
// Encoder constructor
Logger::Logger(void)
{

}


// // Interval between data records in milliseconds.
// // The interval must be greater than the maximum SD write latency plus the
// // time to acquire and write data to the SD to avoid overrun errors.
// const uint32_t SAMPLE_INTERVAL_MS = 1000;
//
// // Log file base name.  Must be six characters or less.
// #define FILE_BASE_NAME "Smitty"
//
// //file system object
// SdFatSdioEX sdEx;
//
// //log file
// SdFile myFile;
//
// // Time in micros for next data record.
// uint32_t logTime;
//
// bool LEDstate = true;
//
// //==============================================================================
// // User functions.  Edit writeHeader() and logData() for your requirements.
//
// const uint8_t ANALOG_COUNT = 4;
// //------------------------------------------------------------------------------
// // Write data header.
// void writeHeader() {
//   myFile.print(F("micros"));
//   for (uint8_t i = 0; i < ANALOG_COUNT; i++) {
//     myFile.print(F(",adc"));
//     myFile.print(i, DEC);
//   }
//   myFile.println();
// }
//
// //------------------------------------------------------------------------------
// // Log a data record.
// void logData() {
//   uint16_t data[ANALOG_COUNT];
//
//   // Read all channels to avoid SD write latency between readings.
//   for (uint8_t i = 0; i < ANALOG_COUNT; i++) {
//     data[i] = analogRead(i);
//   }
//   // Write data to file.  Start with log time in micros.
//   myFile.print(logTime);
//
//   // Write ADC data to CSV record.
//   for (uint8_t i = 0; i < ANALOG_COUNT; i++) {
//     myFile.write(',');
//     myFile.print(data[i]);
//   }
//   myFile.println();
// }
//
//
// //==============================================================================
// // Error messages stored in flash.
// #define error(msg) sdEx.errorHalt(F(msg))
// //------------------------------------------------------------------------------
//
//
// void setup() {
//   const uint8_t BASE_NAME_SIZE = sizeof(FILE_BASE_NAME) - 1;
//   char fileName[13] = FILE_BASE_NAME "00.csv";
//
//   pinMode(LED_BUILTIN, OUTPUT);
//
//   // Open serial communications and wait for port to open:
//   Serial.begin(9600);
//
//   while (!Serial) {
//     ; // wait for serial port to connect
//   }
//
//   Serial.println("Enter any key");  //wait for user input
//
//   while (!Serial.available()) {
//     SysCall::yield();
//   }
//
//   Serial.print("Initializing SD card...");
//
//   if (!sdEx.begin()) {
//     Serial.println("initialization failed!");
//     sdEx.initErrorHalt();
//   }
//   Serial.println("initialization done.");
//
//   // Find an unused file name.
//   if (BASE_NAME_SIZE > 6)
//   {
//     error("FILE_BASE_NAME too long");
//   }
//
//   while (sdEx.exists(fileName)) {
//     if (fileName[BASE_NAME_SIZE + 1] != '9')
//       fileName[BASE_NAME_SIZE + 1]++;
//     else if (fileName[BASE_NAME_SIZE] != '9')
//     {
//       fileName[BASE_NAME_SIZE + 1] = '0';
//       fileName[BASE_NAME_SIZE]++;
//     }
//     else
//       error("Can't create file name");
//   }
//
//   if (!myFile.open(fileName, O_CREAT | O_WRITE | O_EXCL)) {
//     error("myFile.open");
//   }
//
//   // Read any Serial data to clear the buffer
//   do {
//     delay(10);
//   } while (Serial.available() && Serial.read() >= 0);
//
//   Serial.print(F("Logging to: "));
//   Serial.println(fileName);
//   Serial.println(F("Enter any character to stop"));
//
//   // Write data header.
//   writeHeader();
//
//   // Start on a multiple of the sample interval.
//   logTime = micros()/(1000UL*SAMPLE_INTERVAL_MS) + 1;
//   logTime *= 1000UL*SAMPLE_INTERVAL_MS;
// }
//
// void loop() {
//   // Time for next record.
//   logTime += 1000UL*SAMPLE_INTERVAL_MS;
//
//   // Wait for log time.
//   int32_t diff;
//   do {
//     diff = micros() - logTime;
//   } while (diff < 0);
//
//   // Check for data rate too high.
//   if (diff > 10) {
//     error("Missed data record");
//   }
//
//   if(LEDstate)
//     digitalWrite(LED_BUILTIN, HIGH);
//   else
//     digitalWrite(LED_BUILTIN, LOW);
//
//   LEDstate = !LEDstate;
//
//   logData();
//
//   // Force data to SD and update the directory entry to avoid data loss.
//   if (!myFile.sync() || myFile.getWriteError()) {
//     error("write error");
//   }
//
//   if (Serial.available()) {
//     // Close file and stop.
//     myFile.close();
//     Serial.println(F("Done"));
//     SysCall::halt();
//   }
// }
