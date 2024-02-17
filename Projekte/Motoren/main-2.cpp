/**
 * @file main.cpp
 * @brief Rover vorwärts bewegen und Rover rückwärts bewegen
 */
#include <Arduino.h>
#include <SoftPWM.h>

// Definition der Pins für die linken Motoren A, B, C
const int motorA1 = 2; // INA Plus  für Motoren A, B, C sind parallel
const int motorA2 = 3; // INB Minus für Motoren A, B, C sind parallel

// Definition der Pins für die rechten Motoren D, E, F
const int motorB1 = 5; // INA Plus  für Motoren D, E, F sind parallel
const int motorB2 = 4; // INB Minus für Motoren D, E, F sind parallel

void setup() {
    // Initialisiert die SoftPWM-Bibliothek
    SoftPWMBegin();
}

void loop() {
    // Rover vorwärts bewegen
    // linke Motoren
    SoftPWMSet(motorA1, 120);  // etwa halbe Geschwindigkeit
    SoftPWMSet(motorA2, 0);    // Stop
    // rechte Motoren
    SoftPWMSet(motorB1, 120);  // etwa halbe Geschwindigkeit
    SoftPWMSet(motorB2, 0);    // Stop

    // Rover rückwärts bewegen
    // linke Motoren
    SoftPWMSet(motorA1, 0);    // Stop
    SoftPWMSet(motorA2, 120);  // etwa halbe Geschwindigkeit
    // rechte Motoren
    SoftPWMSet(motorB1, 0);    // Stop
    SoftPWMSet(motorB2, 120);  // etwa halbe Geschwindigkeit
}