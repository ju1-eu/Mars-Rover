/**
 * @file main.cpp
 * @brief Motor beschleunigen/verlangsamen im / gegen den Uhrzeigersinn
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
    // Schleife erhöht die Geschwindigkeit von 0 bis 255 anpassen!!!!!!!!
    
    // Beschleunigung im Uhrzeigersinn
    SoftPWMSet(in2, 0);//Minus
    for (int i = 30; i <= 70; i++) {
        SoftPWMSet(in1, i); // Setzt die PWM für den Motor
        Serial.println("Steuerung der Motorgeschwindigkeit (PWM): " + String(i));
        delay(100); // Kurze Verzögerung zwischen den Geschwindigkeitsänderungen
        if (i == 70) {
            // Wenn i 70 erreicht, stoppt der Motor
            SoftPWMSet(in1, 0);
            Serial.println("Motor stoppt für 1 Sekunde.");
            delay(20); // Wartet 1 Sekunde, bevor der Motor neu startet
            break; // Beendet die Schleife, damit sie von vorne beginnen kann
        }
    }

    // Kurze Pause
    delay(20);

    // verlangsamen im Uhrzeigersinn
    for (int i = 70; i >= 30; i--) {
        SoftPWMSet(in1, i); // Setzt die PWM für den Motor
        Serial.println("Steuerung der Motorgeschwindigkeit (PWM): " + String(i));
        delay(100); // Kurze Verzögerung zwischen den Geschwindigkeitsänderungen
        if (i == 30) {
            // Wenn i 70 erreicht, stoppt der Motor
            SoftPWMSet(in1, 0);
            Serial.println("Motor stoppt für 1 Sekunde.");
            delay(20); // Wartet 1 Sekunde, bevor der Motor neu startet
            break; // Beendet die Schleife, damit sie von vorne beginnen kann
        }
    }

    // Beschleunigung gegen Uhrzeigersinn
    SoftPWMSet(in1, 0);//Minus
    for (int i = 30; i <= 70; i++) {
        SoftPWMSet(in2, i); // Setzt die PWM für den Motor
        Serial.println("Steuerung der Motorgeschwindigkeit (PWM): " + String(i));
        delay(100); // Kurze Verzögerung zwischen den Geschwindigkeitsänderungen
        if (i == 70) {
            // Wenn i 70 erreicht, stoppt der Motor
            SoftPWMSet(in2, 0);
            Serial.println("Motor stoppt für 1 Sekunde.");
            delay(20); // Wartet 1 Sekunde, bevor der Motor neu startet
            break; // Beendet die Schleife, damit sie von vorne beginnen kann
        }
    }

    // Kurze Pause
    delay(20);

    // verlangsamen gegen Uhrzeigersinn
    for (int i = 70; i >= 30; i--) {
        SoftPWMSet(in2, i); // Setzt die PWM für den Motor
        Serial.println("Steuerung der Motorgeschwindigkeit (PWM): " + String(i));
        delay(100); // Kurze Verzögerung zwischen den Geschwindigkeitsänderungen
        if (i == 30) {
            // Wenn i 70 erreicht, stoppt der Motor
            SoftPWMSet(in2, 0);
            Serial.println("Motor stoppt für 1 Sekunde.");
            delay(20); // Wartet 1 Sekunde, bevor der Motor neu startet
            break; // Beendet die Schleife, damit sie von vorne beginnen kann
        }
    }

}
