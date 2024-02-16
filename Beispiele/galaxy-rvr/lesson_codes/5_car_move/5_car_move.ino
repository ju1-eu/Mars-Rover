/**
 * @file main.cpp
 * @brief Steuerungsprogramm für einen Rover mit SoftPWM-Bibliothek.
 *
 * Dieses Programm ermöglicht die Steuerung der Bewegungsrichtung eines Rovers,
 * indem es die Geschwindigkeit und Richtung der Motoren über die
 * SoftPWM-Bibliothek einstellt.
 */

#include <SoftPWM.h>

/// Motorenpins definieren
const int in1 = 2; ///< Motor 1 Steuerpin
const int in2 = 3; ///< Motor 2 Steuerpin
const int in3 = 4; ///< Motor 3 Steuerpin
const int in4 = 5; ///< Motor 4 Steuerpin

/**
 * @brief Initialisiert das System.
 *
 * Diese Funktion wird einmal beim Start des Programms aufgerufen.
 * Hier wird die SoftPWM-Bibliothek initialisiert.
 */
void setup() {
  SoftPWMBegin(); // Initialisiert SoftPWM
}

/**
 * @brief Hauptprogrammschleife.
 *
 * Diese Funktion enthält die Hauptlogik des Programms und wird kontinuierlich
 * wiederholt.
 */
void loop() {
  moveForward(200); // Bewegt den Rover vorwärts
  delay(1000);

  moveBackward(200); // Bewegt den Rover rückwärts
  delay(1000);

  turnLeft(200); // Dreht den Rover nach links
  delay(1000);

  turnRight(200); // Dreht den Rover nach rechts
  delay(1000);

  stopMove(); // Stoppt den Rover
  delay(5000);
}

/**
 * @brief Bewegt den Rover vorwärts.
 *
 * @param speed Geschwindigkeit der Motoren.
 */
void moveForward(int speed) {
  SoftPWMSet(in1, speed); // Setzt die linken Motoren so, dass sie gegen den
                          // Uhrzeigersinn drehen
  SoftPWMSet(in2, 0);

  SoftPWMSet(
      in3, 0); // Setzt die rechten Motoren so, dass sie im Uhrzeigersinn drehen
  SoftPWMSet(in4, speed);
}

/**
 * @brief Bewegt den Rover rückwärts.
 *
 * @param speed Geschwindigkeit der Motoren.
 */
void moveBackward(int speed) {
  SoftPWMSet(
      in1, 0); // Setzt die linken Motoren so, dass sie im Uhrzeigersinn drehen
  SoftPWMSet(in2, speed);

  SoftPWMSet(in3, speed); // Setzt die rechten Motoren so, dass sie gegen den
                          // Uhrzeigersinn drehen
  SoftPWMSet(in4, 0);
}

/**
 * @brief Dreht den Rover nach links.
 *
 * @param speed Geschwindigkeit der Motoren.
 */
void turnLeft(int speed) {
  SoftPWMSet(in1, 0); // Setzt alle Motoren so, dass sie im Uhrzeigersinn drehen
  SoftPWMSet(in2, speed);
  SoftPWMSet(in3, 0);
  SoftPWMSet(in4, speed);
}

/**
 * @brief Dreht den Rover nach rechts.
 *
 * @param speed Geschwindigkeit der Motoren.
 */
void turnRight(int speed) {
  SoftPWMSet(
      in1,
      speed); // Setzt alle Motoren so, dass sie gegen den Uhrzeigersinn drehen
  SoftPWMSet(in2, 0);
  SoftPWMSet(in3, speed);
  SoftPWMSet(in4, 0);
}

/**
 * @brief Stoppt alle Motoren des Rovers.
 */
void stopMove() {
  SoftPWMSet(in1, 0); // Stoppt alle Motoren
  SoftPWMSet(in2, 0);
  SoftPWMSet(in3, 0);
  SoftPWMSet(in4, 0);
}
