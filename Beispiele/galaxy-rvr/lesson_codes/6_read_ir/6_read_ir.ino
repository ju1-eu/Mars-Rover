/**
 * @file main.cpp
 * @brief Liest die Werte von zwei IR-Sensoren und gibt diese über die serielle
 * Schnittstelle aus.
 *
 * Dieses Programm konfiguriert zwei Pins als Eingänge für die IR-Sensoren,
 * liest kontinuierlich ihre Werte und sendet diese Werte an den seriellen
 * Monitor. Es demonstriert die Grundlagen der digitalen Eingabe und der
 * seriellen Kommunikation mit dem Arduino.
 */

#include <Arduino.h>

// Definition der Pins für die IR-Sensoren.
#define IR_RIGHT 7 ///< Pin-Nummer für den rechten IR-Sensor.
#define IR_LEFT 8  ///< Pin-Nummer für den linken IR-Sensor.

/**
 * @brief Initialisiert die IR-Sensoren und die serielle Kommunikation.
 *
 * Diese Funktion wird einmal beim Start des Programms ausgeführt.
 * Sie konfiguriert die Pins, die mit den IR-Sensoren verbunden sind, als
 * Eingänge und initialisiert die serielle Kommunikation mit einer Baudrate von
 * 9600.
 */
void setup() {
  pinMode(IR_RIGHT,
          INPUT); // Setzt den Pin für den rechten IR-Sensor als Eingang.
  pinMode(IR_LEFT,
          INPUT); // Setzt den Pin für den linken IR-Sensor als Eingang.

  Serial.begin(
      9600); // Beginnt die serielle Kommunikation mit einer Baudrate von 9600.
}

/**
 * @brief Hauptprogrammschleife, liest und sendet die IR-Sensorwerte.
 *
 * Diese Schleife wird kontinuierlich wiederholt. Sie liest die Werte der
 * IR-Sensoren, gibt diese Werte über den seriellen Monitor aus und wartet dann
 * kurz, um die Ausgabe lesbar zu halten.
 */
void loop() {
  int rightValue =
      digitalRead(IR_RIGHT); // Liest den Wert des rechten IR-Sensors.
  int leftValue = digitalRead(IR_LEFT); // Liest den Wert des linken IR-Sensors.

  // Gibt die gelesenen Werte auf dem seriellen Monitor aus.
  Serial.print("Right IR: ");
  Serial.println(rightValue);
  Serial.print("Left IR: ");
  Serial.println(leftValue);

  delay(200); // Wartet 200 Millisekunden, um die Ausgabe auf dem seriellen
              // Monitor lesbar zu halten.
}
