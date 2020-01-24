/**
 * @file millis_delay.h
 * @brief The header file of the 'mdelay' sub library.
 * @author Jonas Merkle [JJM] <a href="mailto:jonas.merkle@tam-onestone.net">jonas.merkle@tam-onestone.net</a>
 * @author Dominik Authaler <a href="mailto:dominik.authaler@team-onestone.net">dominik.authaler@team-onestone.net</a>
 * @author
 * This library is maintained by <a href="https://team-onestone.net">Team Onestone</a>.
 * E-Mail: <a href="mailto:info@team-onestone.net">info@team-onestone.net</a>
 * @version 1.0.0
 * @date 31 October 2019
 * @copyright This project is released under the GNU General Public License v3.0
 */

#ifndef MDELAY_H
#define MDELAY_H

// includes
#include <inttypes.h>
#include <Arduino.h>

// defines
#define _MDELAY_LIB_VERSION 100	///< The version number of the library.

namespace arduino_util {
	
	/**
	 * @namespace millis_delay
	 * 
	 * @brief The namespace for all delay functions based on the millis() function.
	 */
	namespace millis_delay {
		
		// functions
		void mdelay(uint32_t delay_time);			                    						// Delay based on millis() (milliseconds resolution).
		void micro_mdelay(uint32_t delay_time);		                    						// Delay based on micros() (microseconds resolution).
        void mdelay_f(uint32_t delay_time, void (*funct)(uint32_t));							// Delay based on millis() with function call during the delay (milliseconds resolution).
		void micro_mdelay_f(uint32_t delay_time, void (*funct)(uint32_t));						// Delay based on micros() with function call during the delay  (microseconds resolution).
		void mdelay_with_condition(uint32_t delay_time, bool (*condition)(uint32_t));			// Delay based on millis() with additional break condition (milliseconds resolution).
		void micro_mdelay_with_condition(uint32_t delay_time, bool (*condition)(uint32_t));		// Delay based on micros() with additional break condition (microseconds resolution).
		
		uint16_t get_version();             // Get the version of the library.
	}
}

#endif