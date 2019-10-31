/**
* @file delay_f.ino
 * @brief Example for the usage of the delay_f() method, because this one uses fuctions pointers which make it a bit more difficult to understand. 
 * @author Dominik Authaler <a href="mailto:dominik.authaler@team-onestone.net">dominik.authaler@team-onestone.net</a>
 * @author Jonas Merkle [JJM] <a href="mailto:jonas.merkle@tam-onestone.net">jonas.merkle@tam-onestone.net</a>
 * @version 1.0.0
 * @date 31 October 2019
 * @copyright This project is released under the GNU General Public License v3.0
 */

// include section
#include "mdelay.h"

// namespace section
using namespace arduino_util::mdelay;

// global functions 
void toTrigger(uint32_t);

// arduino setup routine
void setup() {
  Serial.begin(9600);
}

// arduino main loop
void loop() {
  Serial.println("Beginning delay");
  
  //Using a function pointer as param for a method is quite simple, the only thing you need to do is writing the name of the method ;)
  mdelay_f(500, toTrigger);
  
  Serial.println("End of Delay");

  //To compare it to the normal delay --> there's nothing triggered while waiting for the end!
  delay(500);
}

/*
 * This is the method we want to trigger whilst waiting until the specified time in the delay has passed. The method receives 
 * the remaining time to the end of the delay (in milliseconds), therefore this method could be used to trigger the ultrasonic
 * measures whilst waiting a certain time. To implement this, there will be also the need of a global variable, which saves, when
 * the last measurement was started. The system time can be evaluated by calling millis().
 */
void toTrigger(uint32_t) {
    Serial.println("Triggered");
}
