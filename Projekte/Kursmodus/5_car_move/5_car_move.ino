#include <SoftPWM.h>

/// Definiert die Pins der Motoren
const int in1 = 2;
const int in2 = 3;
const int in3 = 4;
const int in4 = 5;

/**
 * Initialisiert das System.
 * Diese Funktion wird einmal beim Start des Programms aufgerufen.
 * Hier wird die SoftPWM-Bibliothek initialisiert.
 */
void setup() {
  // Initialisiert SoftPWM
  SoftPWMBegin();
}

/**
 * Hauptprogrammschleife.
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
 * Bewegt den Rover vorwärts.
 * @param speed Geschwindigkeit der Motoren.
 */
void moveForward(int speed) {
  // Setzt die linken Motoren so, dass sie gegen den Uhrzeigersinn drehen
  SoftPWMSet(in1, speed);
  SoftPWMSet(in2, 0);

  // Setzt die rechten Motoren so, dass sie im Uhrzeigersinn drehen
  SoftPWMSet(in3, 0);
  SoftPWMSet(in4, speed);
}

/**
 * Bewegt den Rover rückwärts.
 * @param speed Geschwindigkeit der Motoren.
 */
void moveBackward(int speed) {
  // Setzt die linken Motoren so, dass sie im Uhrzeigersinn drehen
  SoftPWMSet(in1, 0);
  SoftPWMSet(in2, speed);

  // Setzt die rechten Motoren so, dass sie gegen den Uhrzeigersinn drehen
  SoftPWMSet(in3, speed);
  SoftPWMSet(in4, 0);
}

/**
 * Dreht den Rover nach links.
 * @param speed Geschwindigkeit der Motoren.
 */
void turnLeft(int speed) {
  // Setzt alle Motoren so, dass sie im Uhrzeigersinn drehen
  SoftPWMSet(in1, 0);
  SoftPWMSet(in2, speed);
  SoftPWMSet(in3, 0);
  SoftPWMSet(in4, speed);
}

/**
 * Dreht den Rover nach rechts.
 * @param speed Geschwindigkeit der Motoren.
 */
void turnRight(int speed) {
  // Setzt alle Motoren so, dass sie gegen den Uhrzeigersinn drehen
  SoftPWMSet(in1, speed);
  SoftPWMSet(in2, 0);
  SoftPWMSet(in3, speed);
  SoftPWMSet(in4, 0);
}

/**
 * Stoppt alle Motoren des Rovers.
 */
void stopMove() {
  // Stoppt alle Motoren
  SoftPWMSet(in1, 0);
  SoftPWMSet(in2, 0);
  SoftPWMSet(in3, 0);
  SoftPWMSet(in4, 0);
}
