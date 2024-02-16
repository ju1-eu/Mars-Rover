/**
 * @file main.cpp
 * @brief Steuerungsprogramm für Motoren mit SoftPWM auf Arduino.
 *
 * Dieses Programm zeigt, wie man mit der SoftPWM-Bibliothek die Geschwindigkeit
 * und Richtung von Motoren steuert. Es demonstriert eine einfache Sequenz, in
 * der die Motoren zunächst in einer niedrigen Geschwindigkeit und dann in einer
 * höheren Geschwindigkeit drehen, gefolgt von einer Pause.
 */

#include <SoftPWM.h>

// Definition der Pins, die mit den Motorsteuerungseingängen verbunden sind
const int in1 = 2; ///< Steuerpin für den linken Motor (Vorwärtsrichtung)
const int in2 = 3; ///< Steuerpin für den linken Motor (Rückwärtsrichtung)
const int in3 = 4; ///< Steuerpin für den rechten Motor (Vorwärtsrichtung)
const int in4 = 5; ///< Steuerpin für den rechten Motor (Rückwärtsrichtung)

/**
 * @brief Initialisiert das System und bereitet die SoftPWM-Bibliothek vor.
 *
 * Diese Funktion wird einmal beim Start des Programms ausgeführt. Sie
 * initialisiert die SoftPWM-Bibliothek, die für die Steuerung der
 * Motorgeschwindigkeit verwendet wird.
 */
void setup() {
  SoftPWMBegin(); // Initialisierung der SoftPWM-Bibliothek
}

/**
 * @brief Enthält die Hauptlogik für die Steuerung der Motoren.
 *
 * Diese Funktion wird in einer Endlosschleife ausgeführt und steuert die
 * Motoren durch Einstellen ihrer Geschwindigkeit und Richtung. Zuerst werden
 * die Motoren so eingestellt, dass sie sich mit unterschiedlichen
 * Geschwindigkeiten drehen, dann werden alle Motoren gestoppt.
 */
void loop() {
  // Linken Motoren in niedriger Geschwindigkeit gegen den Uhrzeigersinn drehen
  // lassen
  SoftPWMSet(in1, 40); // Niedrige Geschwindigkeit
  SoftPWMSet(in2, 0);  // Stop

  // Rechten Motoren im Uhrzeigersinn in höherer Geschwindigkeit drehen lassen
  SoftPWMSet(in3, 0);   // Stop
  SoftPWMSet(in4, 200); // Höhere Geschwindigkeit

  delay(2000); // Warte 2 Sekunden

  // Alle Motoren stoppen
  SoftPWMSet(in1, 0);
  SoftPWMSet(in2, 0);
  SoftPWMSet(in3, 0);
  SoftPWMSet(in4, 0);

  delay(5000); // Pause für 5 Sekunden
}
