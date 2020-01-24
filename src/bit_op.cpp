/**
 * @file bit_op.cpp
 * @brief The source file of the bit_op sub library.
 * @author Jonas Merkle [JJM] <a href="mailto:jonas.merkle@tam-onestone.net">jonas.merkle@tam-onestone.net</a>
 * @author Dominik Authaler <a href="mailto:dominik.authaler@team-onestone.net">dominik.authaler@team-onestone.net</a>
 * @author
 * This library is maintained by <a href="https://team-onestone.net">Team Onestone</a>.
 * E-Mail: <a href="mailto:info@team-onestone.net">info@team-onestone.net</a>
 * @version 1.1.0
 * @date 31 October 2019
 * @copyright This project is released under the GNU General Public License v3.0
 */

/////////////
// include //
/////////////
#include "bit_op.h"

///////////////
// functions //
///////////////

/**
 * @brief Get the version of the library.
 * 
 * @retrun the current version of the library.
 */
uint16_t arduino_util::bit_op::getVersion() {
    return _BIT_OP_LIB_VERSION;
}

/**
 * @brief Convert a float value to a byte array.
 * 
 * @param input The input as float (pointer).
 * @param output The output as byte array (pointer). 
 * @retrun True on succes, else fals.
 */
bool arduino_util::bit_op::convFloatToBytes(float *input, uint8_t output[4]) {
    if (memcpy(output, input, 4) != nullptr) {
        return true;
    }
    else {
        return false;
    }
}

/**
 * @brief Convert a byte array to a floar value.
 * 
 * @param input The input as byte array (pointer).
 * @param output The output as float (pointer).
 * @retrun True on succes, else fals.
 */
bool arduino_util::bit_op::convBytesTofloat(uint8_t input[4], float *output) {
    if (memcpy(output, input, 4) != nullptr) {
        return true;
    }
    else {
        return false;
    }
}

