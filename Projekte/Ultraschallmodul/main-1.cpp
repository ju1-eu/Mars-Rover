/**
 * @file main.cpp
 * @brief Programmierung des Ultraschallsensors
 * 
 * Dieser Code ermöglicht es, die Entfernung zu einem Objekt mithilfe des HC-SR04 Ultraschallsensors zu
 * messen. Die serielle Kommunikation wird genutzt, um die gemessene Entfernung in Zentimetern auszugeben.
 * Der Sensor wird durch einen kurzen High-Puls aktiviert, und die Zeit, die das Echo benötigt, 
 * um zum Sensor zurückzukehren, wird verwendet, um die Entfernung zum Objekt zu berechnen.
 */
#include <Arduino.h>

// Definiere den Pin für das Ultraschallmodul
#define ULTRASCHALL_SENSOR_PIN 10

void setup() {
  // Starte die serielle Kommunikation
  Serial.begin(115200);
  // Eine Verzögerung von 4ms ist erforderlich, sonst könnte das Ergebnis 0 sein
  delay(4);  
}

void loop() {
  // Setze den Pin als Ausgang, um das Signal zu senden
  pinMode(ULTRASCHALL_SENSOR_PIN, OUTPUT);

  // Setze den Trigger-Pin zurück auf niedrig
  digitalWrite(ULTRASCHALL_SENSOR_PIN, LOW);
  delayMicroseconds(2);

  // Aktiviere den Sensor, indem ein High-Puls für 10µs gesendet wird
  digitalWrite(ULTRASCHALL_SENSOR_PIN, HIGH);
  delayMicroseconds(10);

  // Setze den Trigger-Pin wieder auf niedrig
  digitalWrite(ULTRASCHALL_SENSOR_PIN, LOW);

  // Setze den Pin als Eingang, um zu lesen
  pinMode(ULTRASCHALL_SENSOR_PIN, INPUT);

  // pulseIn gibt die Dauer des Pulses am Pin zurück
  float duration = pulseIn(ULTRASCHALL_SENSOR_PIN, HIGH);

  // Berechne die Entfernung (in cm) basierend auf der Schallgeschwindigkeit (340 m/s oder 0,034 cm/µs)
  float distance = duration * 0.034 / 2;

  // Zeige die Entfernung auf dem seriellen Monitor an
  Serial.print("Die Entfernung beträgt: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Verzögere ein wenig, damit der Sensor sich vor der nächsten Messung stabilisieren kann
  delay(200);
}