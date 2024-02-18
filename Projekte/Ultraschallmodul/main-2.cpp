/**
 * @file main.cpp
 * @brief Programmierung des Ultraschallmoduls zur Steuerung des Mars-Rovers
 * 
 * Dieser Code nutzt den Ultraschallsensor, um die Entfernung zu Hindernissen zu messen 
 * und den Mars-Rover entsprechend zu steuern. 
 * Es wird entschieden, 
 * ob der Rover vorwärts, rückwärts oder in eine bestimmte Richtung bewegt werden soll, 
 * basierend auf der gemessenen Entfernung.
 */
#include <Arduino.h>
#include <SoftPWM.h>

// Definiere den Pin für das Ultraschallmodul
#define ULTRASCHALL_SENSOR_PIN 10

// Definition der Pins für die Motoren
#define LEFT_MOTOR_FORWARD_PIN 2
#define LEFT_MOTOR_REVERSE_PIN 3
#define RIGHT_MOTOR_FORWARD_PIN 5
#define RIGHT_MOTOR_REVERSE_PIN 4

// Konstanten für die Entfernungsmessung
const float SCHALL_SPEED_CM_PER_US = 0.034; // Schallgeschwindigkeit in cm/µs
const int SAFE_DISTANCE = 50;              // Sicherheitsabstand in cm
const int CLOSE_OBSTACLE_DISTANCE = 15;    // Abstand eines nahen Hindernisses in cm
const int MINIMUM_MEASURABLE_DISTANCE = 2; // Mindestmessbare Entfernung in cm
const int FORWARD_SPEED = 200;             // Geschwindigkeit für Vorwärtsbewegung
const int VORSICHTIG_FORWARD_SPEED = 70;    // Vorsichtige Vorwärtsbewegung
const int BACKWARD_SPEED = 70;            // Geschwindigkeit für Rückwärtsbewegung
const int TURN_SPEED = 70;                // Geschwindigkeit für Drehung

// Prototypen der Funktionen
float readSensorData(); // Liest die Daten vom Ultraschallsensor
void moveForward(int speed); // Bewegt den Rover vorwärts
void moveBackward(int speed); // Bewegt den Rover rückwärts
void backLeft(int speed); // Dreht den Rover nach links
void backRight(int speed); // Dreht den Rover nach rechts

void setup() {
  SoftPWMBegin(); // Initialisiere SoftPWM für Motorsteuerung
  Serial.begin(9600); // Starte die serielle Kommunikation zur Fehlersuche
}

void loop() {
  float distance = readSensorData();

  if (distance > SAFE_DISTANCE) { // Wenn der Weg frei ist, vorwärts bewegen
    moveForward(FORWARD_SPEED);
  } else if (distance < CLOSE_OBSTACLE_DISTANCE && distance > MINIMUM_MEASURABLE_DISTANCE) { // Wenn ein Hindernis nahe ist, aber über dem Mindestabstand, rückwärts bewegen
    moveBackward(BACKWARD_SPEED);
    delay(500); // Warte kurz, bevor versucht wird zu drehen
    backLeft(TURN_SPEED);
    delay(1000); // Wartezeit nach der Drehung
  } else { // Bei mittleren Distanzen vorsichtig vorwärts bewegen
    moveForward(VORSICHTIG_FORWARD_SPEED);
  }
}


// Funktionen-Implementierungen

// Liest die Entfernung vom Ultraschallsensor und berechnet sie
float readSensorData() {
  delay(4); // Wartezeit, um den Sensor zu stabilisieren

  // Trigger-Sequenz senden
  pinMode(ULTRASCHALL_SENSOR_PIN, OUTPUT);
  digitalWrite(ULTRASCHALL_SENSOR_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(ULTRASCHALL_SENSOR_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(ULTRASCHALL_SENSOR_PIN, LOW);

  // Echo lesen
  pinMode(ULTRASCHALL_SENSOR_PIN, INPUT);
  float duration = pulseIn(ULTRASCHALL_SENSOR_PIN, HIGH);

  // Entfernung berechnen und zurückgeben
  return duration * SCHALL_SPEED_CM_PER_US / 2;
}

// Bewegt den Rover vorwärts
void moveForward(int speed) {
  SoftPWMSet(LEFT_MOTOR_FORWARD_PIN, speed);
  SoftPWMSet(LEFT_MOTOR_REVERSE_PIN, 0);
  SoftPWMSet(RIGHT_MOTOR_FORWARD_PIN, speed);
  SoftPWMSet(RIGHT_MOTOR_REVERSE_PIN, 0);
}

// Bewegt den Rover rückwärts
void moveBackward(int speed) {
  SoftPWMSet(LEFT_MOTOR_FORWARD_PIN, 0);
  SoftPWMSet(LEFT_MOTOR_REVERSE_PIN, speed);
  SoftPWMSet(RIGHT_MOTOR_FORWARD_PIN, 0);
  SoftPWMSet(RIGHT_MOTOR_REVERSE_PIN, speed);
}

// Dreht den Rover nach links
void backLeft(int speed) {
  SoftPWMSet(LEFT_MOTOR_FORWARD_PIN, 0);
  SoftPWMSet(LEFT_MOTOR_REVERSE_PIN, 0);
  SoftPWMSet(RIGHT_MOTOR_FORWARD_PIN, speed);
  SoftPWMSet(RIGHT_MOTOR_REVERSE_PIN, 0);
}

// Dreht den Rover nach rechts
void backRight(int speed) {
  SoftPWMSet(LEFT_MOTOR_FORWARD_PIN, speed);
  SoftPWMSet(LEFT_MOTOR_REVERSE_PIN, 0);
  SoftPWMSet(RIGHT_MOTOR_FORWARD_PIN, 0);
  SoftPWMSet(RIGHT_MOTOR_REVERSE_PIN, 0);
}