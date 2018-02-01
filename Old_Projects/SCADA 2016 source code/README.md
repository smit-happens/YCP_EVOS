# BATLOG
The files are:

DAaCSv7.ino - (short for Data Acquisition and Controls System) This is the program that runs on the Arduino Mega, and acts as the main code for the Data Acquisition system.  Communicates with the battery system, motor controller, and logs data to the SD card.

DataComm.cpp, DataComm.h - DataComm class that handles sending and receiving communications from the Arduino Mega.  Also handles logging to the SD card for the battery system.

Batt1B.ino - this program simulates the battery system using the DataComm class

Good luck working on the car!

-Ben Langsdale
