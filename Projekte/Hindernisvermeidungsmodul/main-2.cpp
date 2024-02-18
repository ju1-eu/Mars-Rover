/**
 * @file main.cpp
 * @brief Entwurf eines automatischen Hindernisvermeidungssystems mit 2x Infarotsensoren
 */
#include <Arduino.h>
#include <SoftPWM.h>

// Definition der Pins für die linken Motoren A, B, C
#define LEFT_MOTOR_FORWARD_PIN 2 // Pin für Vorwärtsbewegung der linken Motoren (A, B, C)
#define LEFT_MOTOR_REVERSE_PIN 3 // Pin für Rückwärtsbewegung der linken Motoren (A, B, C)

// Definition der Pins für die rechten Motoren D, E, F
#define RIGHT_MOTOR_FORWARD_PIN 5 // Pin für Vorwärtsbewegung der rechten Motoren (D, E, F)
#define RIGHT_MOTOR_REVERSE_PIN 4 // Pin für Rückwärtsbewegung der rechten Motoren (D, E, F)

// Definition der Pins für die IR-Module
#define IR_RIGHT 7
#define IR_LEFT 8

// Zustandskonstanten für die IR-Sensoren
#define OBSTACLE 0
#define CLEAR 1

void moveBackward(int speed);
void moveForward(int speed);
void backRight(int speed);
void backLeft(int speed);

void setup() {
  // Initialisiere SoftPWM
  SoftPWMBegin();

  // Setze die Pins der IR-Module als Eingänge
  pinMode(IR_RIGHT, INPUT);
  pinMode(IR_LEFT, INPUT);

  // Konfiguriere Motorpins als Ausgänge
  pinMode(LEFT_MOTOR_FORWARD_PIN, OUTPUT);
  pinMode(LEFT_MOTOR_REVERSE_PIN, OUTPUT);
  pinMode(RIGHT_MOTOR_FORWARD_PIN, OUTPUT);
  pinMode(RIGHT_MOTOR_REVERSE_PIN, OUTPUT);
}

void loop() {
  // Lese Werte von den IR-Sensoren
  int rightValue = digitalRead(IR_RIGHT);
  int leftValue = digitalRead(IR_LEFT);

  // Steuere die Bewegungen des Rovers basierend auf den Werten der IR-Sensoren
  if (rightValue == OBSTACLE && leftValue == CLEAR) {  // Weg rechts blockiert
    backRight(70);
  } else if (rightValue == CLEAR && leftValue == OBSTACLE) {  // Weg links blockiert
    backLeft(70);
  } else if (rightValue == OBSTACLE && leftValue == OBSTACLE) {  // Beide Wege blockiert
    moveBackward(70);
  } else {  // Wege frei
    moveForward(70);
  }

  delay(100); // Einfache Entprellungsverzögerung
}

void moveBackward(int speed) {
  SoftPWMSet(LEFT_MOTOR_REVERSE_PIN, speed);
  SoftPWMSet(RIGHT_MOTOR_REVERSE_PIN, speed);
  SoftPWMSet(LEFT_MOTOR_FORWARD_PIN, 0);
  SoftPWMSet(RIGHT_MOTOR_FORWARD_PIN, 0);
}

void moveForward(int speed) {
  SoftPWMSet(LEFT_MOTOR_FORWARD_PIN, speed);
  SoftPWMSet(RIGHT_MOTOR_FORWARD_PIN, speed);
  SoftPWMSet(LEFT_MOTOR_REVERSE_PIN, 0);
  SoftPWMSet(RIGHT_MOTOR_REVERSE_PIN, 0);
}

void backRight(int speed) {
  SoftPWMSet(LEFT_MOTOR_REVERSE_PIN, speed);
  SoftPWMSet(RIGHT_MOTOR_FORWARD_PIN, 0);
  SoftPWMSet(LEFT_MOTOR_FORWARD_PIN, 0);
  SoftPWMSet(RIGHT_MOTOR_REVERSE_PIN, 0);
}

void backLeft(int speed) {
  SoftPWMSet(RIGHT_MOTOR_REVERSE_PIN, speed);
  SoftPWMSet(LEFT_MOTOR_FORWARD_PIN, 0);
  SoftPWMSet(RIGHT_MOTOR_FORWARD_PIN, 0);
  SoftPWMSet(LEFT_MOTOR_REVERSE_PIN, 0);
}
