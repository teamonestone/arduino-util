/**
 * @file millis-delay.h
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

#ifndef MILLIES_DELAY_H
#define MILLIES_DELAY_H

// includes
#include <inttypes.h>
#include <Arduino.h>

// defines
#define _MILLIES_DELAY_LIB_VERSION 100	///< The version number of the library.

/**
 * @namespace arduino_util
 * @brief The main namespace of the Arduino library with useful tools.
 */
namespace arduino_util {
	
	/**
	 * @namespace millis_delay
	 * @brief The namespace for all util delay functions based on the millis() function.
	 */
	namespace millis_delay {
		
		// functions
		static void delay(uint32_t delay_time);			                    							// Delay based on millis() (milliseconds resolution).
		static void micro_delay(uint32_t delay_time);		                    						// Delay based on micros() (microseconds resolution).
        static void delay_f(uint32_t delay_time, void (*funct)(uint64_t));								// Delay based on millis() with function call during the delay (milliseconds resolution).
		static void micro_delay_f(uint32_t delay_time, void (*funct)(uint64_t));						// Delay based on micros() with function call during the delay  (microseconds resolution).
		static void delay_with_condition(uint32_t delay_time, bool (*condition)(uint64_t));				// Delay based on millis() with additional break condition (milliseconds resolution).
		static void micro_delay_with_condition(uint32_t delay_time, bool (*condition)(uint64_t));		// Delay based on micros() with additional break condition (microseconds resolution).
		
		static uint16_t get_version();             // Get the version of the library.
	}
}

#endif