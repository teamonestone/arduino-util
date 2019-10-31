/**
 * @file arduino-util.h
 * @brief The header file of the Arduino library with useful tools.
 * @author Jonas Merkle [JJM] <a href="mailto:jonas.merkle@tam-onestone.net">jonas.merkle@tam-onestone.net</a>
 * @author Dominik Authaler <a href="mailto:dominik.authaler@team-onestone.net">dominik.authaler@team-onestone.net</a>
 * @author
 * This library is maintained by <a href="https://team-onestone.net">Team Onestone</a>.
 * E-Mail: <a href="mailto:info@team-onestone.net">info@team-onestone.net</a>
 * @version 1.0.0
 * @date 31 October 2019
 * @copyright This project is released under the GNU General Public License v3.0
 */

#ifndef ARDUINO_UTIL_H
#define ARDUINO_UTIL_H

// includes
#include <inttypes.h>
#include <Arduino.h>

// defines
#define _ARDUINO_UTIL_LIB_VERSION 100	///< The version number of the library.

/**
 * @namespace arduino_util
 * @brief The main namespace of the Arduino library with useful tools.
 * @details
 * 
 * This namesapces serves as the parant namespace for all sub modues ob the library.
 * 
 */
namespace arduino_util {
    
    uint16_t get_version();             // Get the version of the library.
}

#endif