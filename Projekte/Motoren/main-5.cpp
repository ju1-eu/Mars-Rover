/**
 * @file main.cpp
 * @brief Motor beschleunigen/verlangsamen im / gegen den Uhrzeigersinn
 */
#include <Arduino.h>
#include <SoftPWM.h>

// Definition der Pins für die Linken Motoren A, B, C
const int motorA1 = 2; // INA Plus  für Motoren A, B, C sind parallel
const int motorA2 = 3; // INB Minus für Motoren A, B, C sind parallel

// Definition der Pins für die Rechten Motoren D, E, F
const int motorB1 = 5; // INA Plus  für Motoren D, E, F sind parallel
const int motorB2 = 4; // INB Minus für Motoren D, E, F sind parallel

void setup() {
    Serial.begin(115200);
    SoftPWMBegin();
    SoftPWMSet(motorA1, 0);
    SoftPWMSet(motorA2, 0);
    SoftPWMSet(motorB1, 0);
    SoftPWMSet(motorB2, 0);
}

void controlMotorSpeed(int pin, int startSpeed, int endSpeed, int delayTime, bool increase) {
    if (increase) {
        for (int speed = startSpeed; speed <= endSpeed; speed++) {
            SoftPWMSet(pin, speed);
            Serial.println("Motor beschleunigen (PWM): " + String(speed));
            delay(delayTime);
        }
    } else {
        for (int speed = startSpeed; speed >= endSpeed; speed--) {
            SoftPWMSet(pin, speed);
            Serial.println("Motor verlangsamen (PWM): " + String(speed));
            delay(delayTime);
        }
    }
    SoftPWMSet(pin, 0); // Stoppt den Motor nach der Sequenz
    Serial.println("Motor stoppt für kurze Zeit.");
    delay(20); // Kurze Pause nach dem Stopp
}

void loop() {
    // Linke Seite des Rovers
    // Beschleunigung im Uhrzeigersinn
    controlMotorSpeed(motorA1, 30, 70, 100, true);
    // Verlangsamen im Uhrzeigersinn
    controlMotorSpeed(motorA1, 70, 30, 100, true);
    // Beschleunigung gegen Uhrzeigersinn
    controlMotorSpeed(motorA2, 30, 70, 100, true);
    // Verlangsamen gegen Uhrzeigersinn
    controlMotorSpeed(motorA2, 70, 30, 100, false);

    // Rechte Seite des Rovers
    // Beschleunigung im Uhrzeigersinn
    controlMotorSpeed(motorB1, 30, 70, 100, true);
    // Verlangsamen im Uhrzeigersinn
    controlMotorSpeed(motorB1, 70, 30, 100, true);
    // Beschleunigung gegen Uhrzeigersinn
    controlMotorSpeed(motorB2, 30, 70, 100, true);
    // Verlangsamen gegen Uhrzeigersinn
    controlMotorSpeed(motorB2, 70, 30, 100, false);
}
