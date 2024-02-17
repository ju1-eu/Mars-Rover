/**
 * @file main.cpp
 * @brief Steuerung der Motorgeschwindigkeit (PWM)
 */
#include <Arduino.h>
#include <SoftPWM.h>

const int in1 = 2; // PWM-Pin für Motorrichtung 1
const int in2 = 3; // PWM-Pin für Motorrichtung 2

void setup() {
    // Beginnt die serielle Kommunikation
    Serial.begin(115200);
    // Initialisiert SoftPWM für alle verwendeten Pins
    SoftPWMBegin();
    // Setzt die PWM-Werte initial auf 0
    SoftPWMSet(in1, 0);
    SoftPWMSet(in2, 0);
}

void loop() {
    // Setzt in1 auf 0, um sicherzustellen, dass der Motor in eine Richtung dreht
    SoftPWMSet(in2, 0);
    // Schleife erhöht die Geschwindigkeit von 30 bis 255
    for (int i = 30; i <= 70; i++) {
        SoftPWMSet(in1, i); // Setzt die PWM für den Motor
        Serial.println("Steuerung der Motorgeschwindigkeit (PWM): " + String(i));
        delay(100); // Kurze Verzögerung zwischen den Geschwindigkeitsänderungen
        if (i == 70) {
            // Wenn i 255 erreicht, stoppt der Motor
            SoftPWMSet(in1, 0);
            Serial.println("Motor stoppt für 1 Sekunde.");
            delay(2000); // Wartet 1 Sekunde, bevor der Motor neu startet
            break; // Beendet die Schleife, damit sie von vorne beginnen kann
        }
    }
}
