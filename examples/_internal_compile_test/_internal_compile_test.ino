/*
    WARNING!!!
    This Example is only used for internal testing of the library.
    It don't represent a propper usecase for this library.

    So please ignore this file!
*/


























































































// include
#include "millis-delay.h"

// namespace
using namespace arduino_util::millis_delay;

bool f(uint64_t) {
    return true;  
}

void setup() {
	get_version();
    delay(0);
    micro_delay(0);
    delay_f(0, &f);
    micro_delay_f(0, &f);
    delay_with_condition(0, &f);
    micro_delay_with_condition(0, &f);
}

void loop() {
}