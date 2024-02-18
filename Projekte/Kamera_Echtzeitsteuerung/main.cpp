/**
 * @file main.cpp
 * @brief Beispielprogramm in Arduino-Projekten.
 */
#include <Arduino.h>

int result = 0;

int myFunction(int a, int b);

void setup() {
  // Beginnt die serielle Kommunikation
  Serial.begin(115200);
  result = myFunction(2, 3);
  // Gibt das Ergebnis des Setups auf dem seriellen Monitor aus.
  Serial.println("Setup Ergebnis: " + String(result));
}

void loop() {
  // Gibt das Ergebnis im Loop auf dem seriellen Monitor aus.
  Serial.println("Ergebnis im Loop: " + String(result));
  // Verzögert die nächste Ausgabe um 1000 Millisekunden (1 Sekunde).
  delay(1000);
}

/**
 * @brief Eine Beispiel-Funktion, die zwei Zahlen addiert.
 * 
 * @param a Erster Summand.
 * @param b Zweiter Summand.
 * @return int Die Summe von a und b.
 */
int myFunction(int a, int b) {
  return a + b; // Gibt die Summe von a und b zurück.
}
