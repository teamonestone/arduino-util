/**
* @file delay_with_us_read.ino
 * @brief Example for the usage of the delay_f() method, because this one uses fuctions pointers which make it a bit more difficult to understand. 
 * @author Dominik Authaler <a href="mailto:dominik.authaler@team-onestone.net">dominik.authaler@team-onestone.net</a>
 * @author Jonas Merkle [JJM] <a href="mailto:jonas.merkle@tam-onestone.net">jonas.merkle@tam-onestone.net</a>
 * @version 1.0.0
 * @date 31 October 2019
 * @copyright This project is released under the GNU General Public License v3.0
 */

// include section
#include "millis-delay.h"
#include <Wire.h>

// define section
#define NUMBER_OF_US_SENSORS 3          // the number of connected us sensors
#define READ_DELAY_US_SENSORS 75        // the time a us sensor takes to do a range meassurement

// namespace section
using namespace arduino_util;

// global values
uint8_t usSensorAddress[NUMBER_OF_US_SENSORS] = {0};            // the i2c address of the different us sensors
uint64_t timeOfLastUsRead[NUMBER_OF_US_SENSORS] = {0};          // the time at which the us sensor startet the measurement
int16_t distanceValueOfUsSeonsors[NUMBER_OF_US_SENSORS] = {0};  // the last meassured distance of an us sensor in cm
bool usSensorIsReadyToMeassure[NUMBER_OF_US_SENSORS] = {0};

// global functions 
void updateUS(uint64_t);        // try to update all us sensors
void initUS();                  // initialize the us sensors
int16_t getUsValue(uint8_t);    // return the value of an us sensor

// global internal functions
void startUsMeassurement(uint8_t);  // function to start an us measuerement (internal use only!)
void readValueFromUs(uint8_t);      // function to read an velaue form an us sensor (internal use only!)

// arduino setup routine
void setup() {
    Serial.begin(9600);     // initialize serial port

    // set i2c addresse 
    usSensorAddress[0] = 112;
    usSensorAddress[1] = 114;
    usSensorAddress[2] = 116;

    // inizialize us sensors
    initUS();
}

// arduino main loop
void loop() {

    md::delay_f(500, updateUS);

    for (uint8_t i =  1; i <= NUMBER_OF_US_SENSORS; i++) {
        Serial.print("US-Sensor ");
        Serial.print(i);
        Serial.print(": ");
        Serial.println(getUsValue(i));
    }

}

///////////////////////////////////////////
// Implementation of US Sensor functions //
///////////////////////////////////////////

int16_t getUsValue(uint8_t usSensorNumber) {
    if (usSensorNumber < 1 || usSensorNumber > NUMBER_OF_US_SENSORS)
        return -10;
    else 
        return distanceValueOfUsSeonsors[usSensorNumber-1];
}

void updateUS(uint64_t endTimeOfDelay) {
    // check if a measurement needs to be startet
    for (uint8_t i = 0; i < NUMBER_OF_US_SENSORS; i++) {
        if (usSensorIsReadyToMeassure[i]) {
            startUsMeassurement(i);
        }
    }

    // check if delay is over
    if (millis() >= endTimeOfDelay) return;

    // chekc if a meassured value could be read
    for (uint8_t i = 0; i < NUMBER_OF_US_SENSORS; i++) {
        if (!usSensorIsReadyToMeassure[i] 
        && millis() >= timeOfLastUsRead[i] + READ_DELAY_US_SENSORS) {
            readValueFromUs(i);
        }  
    }
}

void initUS() {
    // init i2c bus (join as master)
    Wire.begin();

    // start a measuerement on all sensors
    for (uint8_t i = 0; i < NUMBER_OF_US_SENSORS; i++) {
        startUsMeassurement(i);
    }
}

void startUsMeassurement(uint8_t usSensorNumber) {
    if (usSensorNumber < 0 || usSensorNumber >= NUMBER_OF_US_SENSORS)
        return;
    else {
        // start a meassurement
        Wire.beginTransmission(usSensorAddress[usSensorNumber]);
        Wire.write(byte(0x00));
        Wire.write(byte(0x51));
        Wire.endTransmission();

        // set flag 
        usSensorIsReadyToMeassure[usSensorNumber] = false;

        // set measurement start time
        timeOfLastUsRead[usSensorNumber] = millis();
    }
}

void readValueFromUs(uint8_t usSensorNumber) {
    if (usSensorNumber < 0 || usSensorNumber >= NUMBER_OF_US_SENSORS)
        return;
    else {
        // set the cursor to the output register
        Wire.beginTransmission(usSensorAddress[usSensorNumber]);
        Wire.write(byte(0x02));
        Wire.endTransmission();

        // request the reading ot 2 bytes from us sensor
        Wire.requestFrom(usSensorAddress[usSensorNumber], 2);

        // read the 2 bytes with the resault of the measurement from the us sensor
        if (2 <= Wire.available()) {
            int16_t reading = Wire.read();
            reading = reading << 8;
            reading |= Wire.read();
            distanceValueOfUsSeonsors[usSensorNumber] = reading;
        }
        else {
            distanceValueOfUsSeonsors[usSensorNumber] = -1;
        }

        // set flag 
        usSensorIsReadyToMeassure[usSensorNumber] = true;
    }
}