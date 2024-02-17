/**
 * @file main.cpp
 * @brief Wie würdest du den Code ändern, um sechs Motoren gleichzeitig zu steuern?
 */
#include <Arduino.h>
const int in3 = 4;
const int in4 = 5;

void setup() {
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
}

void loop() {
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    delay(2000);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    delay(2000);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, HIGH);
    delay(5000);
}