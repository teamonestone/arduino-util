/*
    WARNING!!!
    This Example is only used for internal testing of the library.
    It don't represent a propper usecase for this library.

    So please ignore this file!
*/


























































































// include
#include "mdelay.h"

// namespace
using namespace arduino_util::mdelay;

void f (uint32_t) {
  
}

bool fc(uint32_t) {
    return true;  
}

void setup() {
    get_version();
    mdelay(0);
    micro_mdelay(0);
    mdelay_f(0, &f);
    micro_mdelay_f(0, &f);
    mdelay_with_condition(0, &fc);
    micro_mdelay_with_condition(0, &fc);
}

void loop() {
}