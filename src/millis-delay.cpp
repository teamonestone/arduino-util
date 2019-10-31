/**
 * @file millis-delay.cpp
 * @brief The source file of the Arduino library with useful tools.
 * @author Jonas Merkle [JJM] <a href="mailto:jonas.merkle@tam-onestone.net">jonas.merkle@tam-onestone.net</a>
 * @author Dominik Authaler <a href="mailto:dominik.authaler@team-onestone.net">dominik.authaler@team-onestone.net</a>
 * @author
 * This library is maintained by <a href="https://team-onestone.net">Team Onestone</a>.
 * E-Mail: <a href="mailto:info@team-onestone.net">info@team-onestone.net</a>
 * @version 1.0.0
 * @date 31 October 2019
 * @copyright This project is released under the GNU General Public License v3.0
 */

/**
 * @mainpage Arduino library with useful tools
 *
 * @section intro_sec Introduction
 *
 * ...
 *
 * @section dependencies Dependencies
 *
 * This library has no special external dependencies.
 *
 * @section author Author
 *
 * Written by:
 * - Jonas Merkle [JJM] <a href="mailto:jonas.merkle@tam-onestone.net">jonas.merkle@tam-onestone.net</a>
 * - Dominik Authaler <a href="mailto:dominik.authaler@team-onestone.net">dominik.authaler@team-onestone.net</a> 
 *
 * This library is maintained by <a href="https://team-onestone.net">Team Onestone</a>.
 * E-Mail: <a href="mailto:info@team-onestone.net">info@team-onestone.net</a>
 *
 * @section license License
 *
 * This project is released under the GNU General Public License v3.0
 * 
*/

/////////////
// include //
/////////////
#include "millis-delay.h"

///////////////
// functions //
///////////////

/**
 * @brief Get the version of the library.
 * 
 * @retrun the current version of the library.
 */
uint16_t arduino_util::millis_delay::get_version() {
    return _MILLIES_DELAY_LIB_VERSION;
}

/**
 * @brief Delay based on millis() (milliseconds resolution).
 * 
 * @param delay_time time to wait in milliseconds.
 */
void arduino_util::millis_delay::delay(uint32_t delay_time) {
    uint64_t time_to_wait = millis() + delay_time;

    while (millis() <= time_to_wait);
}

/**
 * @brief Delay based on micros() (microseconds resolution).
 * 
 * @param delay_time time to wait in microseconds.
 */
void arduino_util::millis_delay::micro_delay(uint32_t delay_time) {
    uint64_t time_to_wait = micros() + delay_time;

    while (micros() <= time_to_wait);
}

/**
 * @brief Delay based on millis() with function call during the delay (milliseconds resolution).
 * 
 * @param delay_time time to wait in milliseconds.
 * @param funct function pointer to a void function with a uint64_t argument.
 */
void arduino_util::millis_delay::delay_f(uint32_t delay_time, void (*funct)(uint64_t)) {
    uint64_t time_to_wait = millis() + delay_time;

    while (millis() <= time_to_wait) {
        funct(time_to_wait);
    }
}

/**
 * @brief Delay based on micros() with function call during the delay  (microseconds resolution).
 * 
 * @param delay_time time to wait in microseconds.
 * @param funct function pointer to a void function with a uint64_t argument.
 */
void arduino_util::millis_delay::micro_delay_f(uint32_t delay_time, void (*funct)(uint64_t)) {
    uint64_t time_to_wait = micros() + delay_time;

    while (micros() <= time_to_wait) {
        funct(time_to_wait);
    }
}

/**
 * @brief Delay based on millis() with additional break condition (milliseconds resolution).
 * 
 * @param delay_time time to wait in milliseconds.
 * @param funct function pointer to a bool function with a uint64_t argument.
 */
void arduino_util::millis_delay::delay_with_condition(uint32_t delay_time, bool (*condition)(uint64_t)) {
    uint64_t time_to_wait = millis() + delay_time;

    while (millis() <= time_to_wait && condition(time_to_wait));
}

/**
 * @brief Delay based on micros() with additional break condition (microseconds resolution).
 * 
 * @param delay_time time to wait in microseconds
 * @param funct function pointer to a bool function with a uint64_t argument.
 */
void arduino_util::millis_delay::micro_delay_with_condition(uint32_t _delay_time, bool (*_condition)(uint64_t)) {
    uint64_t _time_to_wait = micros() + _delay_time;

    while (micros() <= _time_to_wait && _condition(_time_to_wait));
}

