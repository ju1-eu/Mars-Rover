/**
 * @file main.cpp
 * @brief Steuerungsprogramm für einen Rover mit IR-Sensoren und
 * SoftPWM-Motorsteuerung.
 *
 * Dieses Programm nutzt Infrarot(IR)-Sensoren, um Hindernisse zu erkennen und
 * steuert die Bewegung des Rovers entsprechend. Abhängig von den Signalen der
 * IR-Sensoren bewegt sich der Rover vorwärts, rückwärts, dreht nach links oder
 * rechts.
 */

#include <SoftPWM.h> ///< Einbinden der SoftPWM-Bibliothek für erweiterte PWM-Funktionalitäten.

// Definition der Pins, die mit den Motorsteuerungseingängen verbunden sind
const int in1 = 2; ///< Motor 1 Steuerpin A
const int in2 = 3; ///< Motor 1 Steuerpin B
const int in3 = 4; ///< Motor 2 Steuerpin A
const int in4 = 5; ///< Motor 2 Steuerpin B

// Definition der Pins für die IR-Sensoren
#define IR_RIGHT 7 ///< IR-Sensor rechts
#define IR_LEFT 8  ///< IR-Sensor links

/**
 * @brief Initialisiert das System und bereitet die Motor- und IR-Sensor-Pins
 * vor.
 */
void setup() {
  SoftPWMBegin(); // Startet die SoftPWM-Bibliothek für die Motorsteuerung.

  pinMode(IR_RIGHT, INPUT); // Konfiguriert den rechten IR-Sensor als Eingang
  pinMode(IR_LEFT, INPUT);  // Konfiguriert den linken IR-Sensor als Eingang
}

/**
 * @brief Hauptprogrammschleife, steuert die Bewegungen des Rovers basierend auf
 * IR-Sensor-Eingängen.
 */
void loop() {
  // Auslesen der Werte von den IR-Sensoren
  int rightValue =
      digitalRead(IR_RIGHT);            // Liest den Wert des rechten IR-Sensors
  int leftValue = digitalRead(IR_LEFT); // Liest den Wert des linken IR-Sensors

  // Steuerung der Roverbewegung basierend auf den IR-Sensorwerten
  if (rightValue == 0 && leftValue == 1) {        // Weg rechts blockiert
    backRight(150);                               // Dreht nach rechts hinten
  } else if (rightValue == 1 && leftValue == 0) { // Weg links blockiert
    backLeft(150);                                // Dreht nach links hinten
  } else if (rightValue == 0 && leftValue == 0) { // Beide Wege blockiert
    moveBackward(150);                            // Bewegt sich rückwärts
  } else {                                        // Wege frei
    moveForward(150);                             // Bewegt sich vorwärts
  }

  delay(100); // Kurze Verzögerung vor dem nächsten Durchlauf
}

/**
 * @brief Bewegt den Rover rückwärts.
 * @param speed Geschwindigkeit der Motoren.
 */
void moveBackward(int speed) {
  SoftPWMSet(in1, 0);     // Stoppt Motor 1 Richtung A
  SoftPWMSet(in2, speed); // Motor 1 Richtung B mit voller Geschwindigkeit

  SoftPWMSet(in3, speed); // Motor 2 Richtung A mit voller Geschwindigkeit
  SoftPWMSet(in4, 0);     // Stoppt Motor 2 Richtung B
}

/**
 * @brief Bewegt den Rover vorwärts.
 * @param speed Geschwindigkeit der Motoren.
 */
void moveForward(int speed) {
  SoftPWMSet(in1, speed); // Motor 1 Richtung A mit voller Geschwindigkeit
  SoftPWMSet(in2, 0);     // Stoppt Motor 1 Richtung B

  SoftPWMSet(in3, 0);     // Stoppt Motor 2 Richtung A
  SoftPWMSet(in4, speed); // Motor 2 Richtung B mit voller Geschwindigkeit
}

/**
 * @brief Dreht den Rover nach rechts hinten.
 * @param speed Geschwindigkeit der Motoren.
 */
void backRight(int speed) {
  SoftPWMSet(in1, 0);     // Stoppt Motor 1 Richtung A
  SoftPWMSet(in2, speed); // Motor 1 Richtung B mit voller Geschwindigkeit

  // Beide Motoren auf der rechten Seite stoppen, um eine Drehbewegung zu
  // ermöglichen
  SoftPWMSet(in3, 0);
  SoftPWMSet(in4, 0);
}

/**
 * @brief Dreht den Rover nach links hinten.
 * @param speed Geschwindigkeit der Motoren.
 */
void backLeft(int speed) {
  // Beide Motoren auf der linken Seite stoppen, um eine Drehbewegung zu
  // ermöglichen
  SoftPWMSet(in1, 0);
  SoftPWMSet(in2, 0);

  SoftPWMSet(in3, speed); // Motor 2 Richtung A mit voller Geschwindigkeit
  SoftPWMSet(in4, 0);     // Stoppt Motor 2 Richtung B
}
