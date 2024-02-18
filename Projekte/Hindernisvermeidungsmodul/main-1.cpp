/**
 * @file main.cpp
 * @brief Auslesen der 2 Infarot-Module
 */
#include <Arduino.h>
// Definiere die Pins für die IR-Module
#define IR_RIGHT 7
#define IR_LEFT 8

void setup() {
  // Setze die Pins der IR-Module als Eingänge
  pinMode(IR_RIGHT, INPUT);
  pinMode(IR_LEFT, INPUT);

  // Beginne die serielle Kommunikation
  Serial.begin(115200);
}

void loop() {
  // Lese die Werte von den IR-Modulen
  int rightValue = digitalRead(IR_RIGHT);
  int leftValue = digitalRead(IR_LEFT);

  // Ausgabe auf den seriellen Monitor
  Serial.print("Rechter IR: ");
  Serial.println(rightValue);
  Serial.print("Linker IR: ");
  Serial.println(leftValue);

  // Warte kurz, um die Lesbarkeit zu verbessern
  delay(200);
}
