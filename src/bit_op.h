/**
 * @file bit_op.h
 * @brief The header file of the bit_op sub library.
 * @author Jonas Merkle [JJM] <a href="mailto:jonas.merkle@tam-onestone.net">jonas.merkle@tam-onestone.net</a>
 * @author Dominik Authaler <a href="mailto:dominik.authaler@team-onestone.net">dominik.authaler@team-onestone.net</a>
 * @author
 * This library is maintained by <a href="https://team-onestone.net">Team Onestone</a>.
 * E-Mail: <a href="mailto:info@team-onestone.net">info@team-onestone.net</a>
 * @version 1.1.0
 * @date 31 October 2019
 * @copyright This project is released under the GNU General Public License v3.0
 */

#ifndef BIT_OP_H
#define BIT_OP_H

// includes
#include <inttypes.h>
#include <string.h>

// defines
#define _BIT_OP_LIB_VERSION 10100	///< The version number of the library.

namespace arduino_util {
	
	/**
	 * @namespace bit_op
	 * @brief The namespace for all util bit operation function.
	 */
	namespace bit_op {
		
		// functions
        bool convFloatToBytes(float *input, uint8_t output[4]);		// convert a float value to a byte array.
    	bool convBytesTofloat(uint8_t input[4], float *output);		// convert a byte array to a floar value. 

		uint16_t getVersion();							// Get the version of the library.
	}
}

#endif