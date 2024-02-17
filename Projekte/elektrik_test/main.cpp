/**
 * @file main.cpp
 * @brief Hauptsteuerungsprogramm für das Arduino-Projekt mit Motoren, RGB-LED
 * und Ultraschallsensor.
 *
 * Dieses Programm testet die Motorsteuerung,
 * RGB-LED-Ansteuerung und Distanzmessung mit einem Ultraschallsensor.
 * Es ist für den Einsatz auf einem Arduino UNO Board ausgelegt.
 *
 * @version 1.0
 * @date 2024-02-16
 */

#include <Arduino.h>
#include <Servo.h>
#if defined(ARDUINO_AVR_UNO)
#include <SoftPWM.h>
#endif

// Definition der Pin-Nummern für die verschiedenen Komponenten
#define MOTOR_PIN_LEFT_A 5
#define MOTOR_PIN_LEFT_B 4
#define MOTOR_PIN_RIGHT_A 2
#define MOTOR_PIN_RIGHT_B 3
#define RGB_PIN_R 12
#define RGB_PIN_G 13
#define RGB_PIN_B 11
#define ULTRASONIC_PIN_TRIG 10
#define ULTRASONIC_PIN_ECHO 10

// Konstanten für die Ultraschallsensorik
#define MAX_DISTANCE 300  // Maximale Distanz (in cm)
#define ULTRASONIC_READ_TIMEOUT \
  18000  // Timeout für Lesevorgänge (in Mikrosekunden)

Servo servo;                // Servo-Objekt
#define SERVO_PIN 6         // Servo Pin-Nummer
#define SERVO_REVERSE true  // Servo Umkehr-Flag

/**
 * @brief Initialisiert die Hardware und grundlegende Konfigurationen.
 */
void setup() {
  Serial.begin(115200);
  Serial.println("Electric Test Begin...");
  delay(1000);

  Serial.println("Start Camera...");
  Serial.println("SET+START");
  delay(1000);

  // Initialisierung der Motor-Pins
  pinMode(MOTOR_PIN_LEFT_A, OUTPUT);
  pinMode(MOTOR_PIN_LEFT_B, OUTPUT);
  pinMode(MOTOR_PIN_RIGHT_A, OUTPUT);
  pinMode(MOTOR_PIN_RIGHT_B, OUTPUT);
  digitalWrite(MOTOR_PIN_LEFT_A, LOW);
  digitalWrite(MOTOR_PIN_LEFT_B, LOW);
  digitalWrite(MOTOR_PIN_RIGHT_A, LOW);
  digitalWrite(MOTOR_PIN_RIGHT_B, LOW);

  // Initialisierung der RGB LED-Pins
  pinMode(RGB_PIN_R, OUTPUT);
  pinMode(RGB_PIN_G, OUTPUT);
  pinMode(RGB_PIN_B, OUTPUT);

  // Initialisierung des Servos
  servo.attach(SERVO_PIN);
  servo.write(90);

#if defined(ARDUINO_AVR_UNO)
  SoftPWMBegin();  // Initialisierung von SoftPWM
#endif
}

/**
 * @brief Testet die Motorsteuerung für Vorwärts- und Rückwärtsbewegungen.
 */
void motor_test() {
  if (millis() / 1000 % 2 < 1) {
    Serial.println("FORWARD");
    digitalWrite(MOTOR_PIN_LEFT_A, HIGH);
    digitalWrite(MOTOR_PIN_LEFT_B, LOW);
    digitalWrite(MOTOR_PIN_RIGHT_A, HIGH);
    digitalWrite(MOTOR_PIN_RIGHT_B, LOW);
  } else {
    Serial.println("BACKWARD");
    digitalWrite(MOTOR_PIN_LEFT_A, LOW);
    digitalWrite(MOTOR_PIN_LEFT_B, HIGH);
    digitalWrite(MOTOR_PIN_RIGHT_A, LOW);
    digitalWrite(MOTOR_PIN_RIGHT_B, HIGH);
  }
}

/**
 * @brief Wechselt die Farbe der RGB-LED basierend auf der aktuellen Zeit.
 */
void rgb_test() {
  if (millis() / 1000 % 3 < 1) {
    Serial.println("RED");
    digitalWrite(RGB_PIN_R, HIGH);
    digitalWrite(RGB_PIN_G, LOW);
    digitalWrite(RGB_PIN_B, LOW);
  } else if (millis() / 1000 % 3 < 2) {
    Serial.println("GREEN");
    digitalWrite(RGB_PIN_R, LOW);
    digitalWrite(RGB_PIN_G, HIGH);
    digitalWrite(RGB_PIN_B, LOW);
  } else {
    Serial.println("BLUE");
    digitalWrite(RGB_PIN_R, LOW);
    digitalWrite(RGB_PIN_G, LOW);
    digitalWrite(RGB_PIN_B, HIGH);
  }
}

/**
 * @brief Testet den Ultraschallsensor durch Messen der Entfernung zu einem
 * Objekt.
 *
 * Diese Funktion sendet einen Ultraschallimpuls aus und misst, wie lange es
 * dauert, bis das Echo zurückkehrt. Daraus berechnet sie die Entfernung zum
 * nächsten Objekt. Die Messung wird nur durchgeführt, wenn eine gerade Sekunde
 * erreicht ist, um die Messfrequenz zu begrenzen.
 */
void ultasonic_test() {
  if (millis() / 1000 % 2 < 1)
    return;  // Führt die Messung nur jede zweite Sekunde durch

  pinMode(ULTRASONIC_PIN_TRIG, OUTPUT);
  digitalWrite(ULTRASONIC_PIN_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(ULTRASONIC_PIN_TRIG,
               HIGH);  // Sendet einen 10 Mikrosekunden langen Impuls
  delayMicroseconds(10);
  digitalWrite(ULTRASONIC_PIN_TRIG, LOW);
  pinMode(ULTRASONIC_PIN_ECHO, INPUT);

  noInterrupts();  // Deaktiviert Unterbrechungen, um die Messung nicht zu
                   // beeinflussen

  // Misst die Dauer des Echosignals
  float duration = pulseIn(ULTRASONIC_PIN_ECHO, HIGH, ULTRASONIC_READ_TIMEOUT);

  // Berechnet die Distanz basierend auf der Dauer des Echos
  float distance = duration * 0.017;  // Umrechnung der Zeit in Distanz

  interrupts();  // Reaktiviert Unterbrechungen

  // Überprüft, ob die gemessene Distanz größer als die maximale Distanz ist
  if (distance > MAX_DISTANCE || distance == 0) {
    Serial.println("Ultrasonic read: error");
  } else {
    Serial.print("Ultrasonic read: ");
    Serial.println(distance,
                   2);  // Gibt die Distanz mit zwei Nachkommastellen aus
  }

  delay(200);  // Kurze Pause, um nicht zu häufig zu messen
}

void loop() {
  // Funktionsaufrufe auskommentieren, wenn benötigt
  //motor_test();
  rgb_test();
  // ultasonic_test(); // Führt den Ultraschalltest durch
}
