#include <bit_op.h>

void setup() {
    Serial.begin(9600);
}

void loop() {
    float f1 = 0;
    float f2 = 0;
    uint8_t b[4] = {0};

    f1 += random(0, 1024);
    f1 += random(0, 100) * 0.001;

    Serial.print("Random Float value to begin with: ");
    Serial.println(f1);

    arduino_util::bit_op::convFloatToBytes(&f1, b);
    arduino_util::bit_op::convBytesTofloat(b, &f2);

    Serial.print("After conversion: ");
    Serial.println(f2);

    delay(1000);
}