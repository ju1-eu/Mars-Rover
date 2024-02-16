/**
 * @file main.cpp
 * @brief Demonstration der Motorsteuerung mit der SoftPWM-Bibliothek auf einem
 * Arduino-Board.
 *
 * In diesem Sketch werden alle Motoren so gesteuert, dass sie für zwei Sekunden
 * im Uhrzeigersinn drehen. Anschließend werden alle Motoren für fünf Sekunden
 * angehalten. Dieser Zyklus wiederholt sich kontinuierlich.
 */

#include <SoftPWM.h> ///< Einbinden der SoftPWM-Bibliothek für erweiterte PWM-Funktionalitäten.

// Definition der Pins, die mit den Eingängen der Motortreiber verbunden sind.
const int in1 = 2; ///< Motor 1 Steuerpin A
const int in2 = 3; ///< Motor 1 Steuerpin B
const int in3 = 4; ///< Motor 2 Steuerpin A
const int in4 = 5; ///< Motor 2 Steuerpin B

/**
 * @brief Initialisiert die SoftPWM-Bibliothek und konfiguriert die
 * Motorsteuerpins als Ausgänge.
 */
void setup() {
  SoftPWMBegin(); // Initialisiert die SoftPWM-Bibliothek.
}

/**
 * @brief Hauptprogrammschleife, steuert die Motoren in einem festgelegten
 * Muster.
 *
 * In dieser Schleife werden alle Motoren so eingestellt, dass sie für zwei
 * Sekunden im Uhrzeigersinn drehen. Danach werden alle Motoren für fünf
 * Sekunden angehalten.
 */
void loop() {
  // Einstellen aller Motoren, um im Uhrzeigersinn zu drehen.
  SoftPWMSet(in1, 0);   // Motor 1 Richtung A aus
  SoftPWMSet(in2, 255); // Motor 1 Richtung B volle Geschwindigkeit
  SoftPWMSet(in3, 0);   // Motor 2 Richtung A aus
  SoftPWMSet(in4, 255); // Motor 2 Richtung B volle Geschwindigkeit

  delay(2000); // Warte 2 Sekunden (Motoren drehen).

  // Anhalten aller Motoren.
  SoftPWMSet(in1, 0); // Motor 1 Richtung A aus
  SoftPWMSet(in2, 0); // Motor 1 Richtung B aus
  SoftPWMSet(in3, 0); // Motor 2 Richtung A aus
  SoftPWMSet(in4, 0); // Motor 2 Richtung B aus

  delay(5000); // Pause 5 Sekunden (Motoren stehen).
}
