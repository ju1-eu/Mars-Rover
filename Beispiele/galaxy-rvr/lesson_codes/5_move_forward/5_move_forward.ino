/**
 * @file main.cpp
 * @brief Demonstriert die Grundsteuerung von Motoren mit SoftPWM auf einem
 * Arduino.
 *
 * Dieses Programm initialisiert die SoftPWM-Bibliothek und steuert zwei
 * Motoren, indem es einen im Uhrzeigersinn und den anderen gegen den
 * Uhrzeigersinn dreht, um eine Vorwärtsbewegung zu simulieren.
 */

#include <SoftPWM.h>

// Definition der Motorsteuerungspins
const int in1 = 2; ///< Pin für Motor 1 Vorwärtsrichtung
const int in2 = 3; ///< Pin für Motor 1 Rückwärtsrichtung
const int in3 = 4; ///< Pin für Motor 2 Vorwärtsrichtung
const int in4 = 5; ///< Pin für Motor 2 Rückwärtsrichtung

/**
 * @brief Initialisiert das System.
 *
 * Diese Funktion wird einmal beim Start des Programms aufgerufen und
 * initialisiert die SoftPWM-Bibliothek zur Steuerung der Motorgeschwindigkeit.
 */
void setup() {
  SoftPWMBegin(); // Startet die SoftPWM-Bibliothek
}

/**
 * @brief Hauptprogrammschleife.
 *
 * In dieser Schleife werden die Motoren so gesteuert, dass einer der Motoren
 * vorwärts (gegen den Uhrzeigersinn) und der andere rückwärts (im
 * Uhrzeigersinn) dreht, was eine Bewegung des Fahrzeugs in eine bestimmte
 * Richtung ermöglicht.
 */
void loop() {
  // Linken Motoren gegen den Uhrzeigersinn drehen lassen
  SoftPWMSet(in1, 255); // Vollgeschwindigkeit
  SoftPWMSet(in2, 0);   // Stopp

  // Rechten Motoren im Uhrzeigersinn drehen lassen
  SoftPWMSet(in3, 0);   // Stopp
  SoftPWMSet(in4, 255); // Vollgeschwindigkeit

  // Hinweis: Diese Konfiguration führt zu einer Vorwärtsbewegung, wenn die
  // Motoren entsprechend positioniert sind. Anpassungen für andere
  // Bewegungsrichtungen können durch Ändern der Geschwindigkeitswerte und der
  // aktiven Pins vorgenommen werden.
}
