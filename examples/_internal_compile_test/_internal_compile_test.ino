/*
    WARNING!!!
    This Example is only used for internal testing of the library.
    It don't represent a propper usecase for this library.

    So please ignore this file!
*/


























































































// include
#include "millis_delay.h"
#include "bit_op.h"

// namespace
using namespace arduino_util;

void f (uint32_t) {
    ;
}

bool fc(uint32_t) {
    return true;  
}

float a = 0.0;
uint8_t b[4] = {0};

void setup() {
    // mdelay.h
    millis_delay::getVersion();
    millis_delay::mdelay(0);
    millis_delay::micro_mdelay(0);
    millis_delay::mdelay_f(0, &f);
    millis_delay::micro_mdelay_f(0, &f);
    millis_delay::mdelay_with_condition(0, &fc);
    millis_delay::micro_mdelay_with_condition(0, &fc);

    //bit_op.h
    bit_op::getVersion();
    bit_op::convFloatToBytes(&a, b);
    bit_op::convBytesTofloat(b, &a);   
}

void loop() {
}