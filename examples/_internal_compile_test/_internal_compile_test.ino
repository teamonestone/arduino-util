/*
    WARNING!!!
    This Example is only used for internal testing of the library.
    It don't represent a propper usecase for this library.

    So please ignore this file!
*/


























































































// include
#include "millis-delay.h"

// namespace
using namespace arduino_util;

bool f(uint64_t) {
    return true;  
}

void setup() {
    md::get_version();
    md::delay(0);
    md::micro_delay(0);
    md::delay_f(0, &f);
    md::micro_delay_f(0, &f);
    md::delay_with_condition(0, &f);
    md::micro_delay_with_condition(0, &f);
}

void loop() {
}