/**
 * @file millis_delay.cpp
 * @brief The source file of the 'mdelay' sub library.
 * @author Jonas Merkle [JJM] <a href="mailto:jonas.merkle@tam-onestone.net">jonas.merkle@tam-onestone.net</a>
 * @author Dominik Authaler <a href="mailto:dominik.authaler@team-onestone.net">dominik.authaler@team-onestone.net</a>
 * @author
 * This library is maintained by <a href="https://team-onestone.net">Team Onestone</a>.
 * E-Mail: <a href="mailto:info@team-onestone.net">info@team-onestone.net</a>
 * @version 1.0.0
 * @date 31 October 2019
 * @copyright This project is released under the GNU General Public License v3.0
 */

/////////////
// include //
/////////////
#include "millis_delay.h"

///////////////
// functions //
///////////////

/**
 * @brief Get the version of the library.
 * 
 * @retrun the current version of the library.
 */
uint16_t arduino_util::millis_delay::get_version() {
    return _MDELAY_LIB_VERSION;
}

/**
 * @brief Delay based on millis() (milliseconds resolution).
 * 
 * @param delay_time time to wait in milliseconds.
 */
void arduino_util::millis_delay::mdelay(uint32_t delay_time) {
    uint32_t time_to_wait = millis() + delay_time;

    while (millis() <= time_to_wait);
}

/**
 * @brief Delay based on micros() (microseconds resolution).
 * 
 * @param delay_time time to wait in microseconds.
 */
void arduino_util::millis_delay::micro_mdelay(uint32_t delay_time) {
    uint32_t time_to_wait = micros() + delay_time;

    while (micros() <= time_to_wait);
}

/**
 * @brief Delay based on millis() with function call during the delay (milliseconds resolution).
 * 
 * @param delay_time time to wait in milliseconds.
 * @param funct function pointer to a void function with a uint32_t argument.
 */
void arduino_util::millis_delay::mdelay_f(uint32_t delay_time, void (*funct)(uint32_t)) {
    uint32_t time_to_wait = millis() + delay_time;

    while (millis() <= time_to_wait) {
        funct(time_to_wait);
    }
}

/**
 * @brief Delay based on micros() with function call during the delay  (microseconds resolution).
 * 
 * @param delay_time time to wait in microseconds.
 * @param funct function pointer to a void function with a uint32_t argument.
 */
void arduino_util::millis_delay::micro_mdelay_f(uint32_t delay_time, void (*funct)(uint32_t)) {
    uint32_t time_to_wait = micros() + delay_time;

    while (micros() <= time_to_wait) {
        funct(time_to_wait);
    }
}

/**
 * @brief Delay based on millis() with additional break condition (milliseconds resolution).
 * 
 * @param delay_time time to wait in milliseconds.
 * @param funct function pointer to a bool function with a uint32_t argument.
 */
void arduino_util::millis_delay::mdelay_with_condition(uint32_t delay_time, bool (*condition)(uint32_t)) {
    uint32_t time_to_wait = millis() + delay_time;

    while (millis() <= time_to_wait && condition(time_to_wait));
}

/**
 * @brief Delay based on micros() with additional break condition (microseconds resolution).
 * 
 * @param delay_time time to wait in microseconds
 * @param funct function pointer to a bool function with a uint32_t argument.
 */
void arduino_util::millis_delay::micro_mdelay_with_condition(uint32_t _delay_time, bool (*_condition)(uint32_t)) {
    uint32_t _time_to_wait = micros() + _delay_time;

    while (micros() <= _time_to_wait && _condition(_time_to_wait));
}

