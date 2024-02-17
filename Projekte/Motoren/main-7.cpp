/**
 * @file main.cpp
 * @brief Steuert die Bewegungen eines Rovers, einschließlich Vorwärts-, Rückwärtsbewegungen und Drehungen.
 */

#include <Arduino.h>
#include <SoftPWM.h>

// Definition der Pins für die linken Motoren A, B, C
#define LEFT_MOTOR_FORWARD_PIN 2 // Pin für Vorwärtsbewegung der linken Motoren (A, B, C)
#define LEFT_MOTOR_REVERSE_PIN 3 // Pin für Rückwärtsbewegung der linken Motoren (A, B, C)
// Definition der Pins für die rechten Motoren D, E, F
#define RIGHT_MOTOR_FORWARD_PIN 5 // Pin für Vorwärtsbewegung der rechten Motoren (D, E, F)
#define RIGHT_MOTOR_REVERSE_PIN 4 // Pin für Rückwärtsbewegung der rechten Motoren (D, E, F)

#define FORWARD_SPEED 255 // Maximalgeschwindigkeit
#define MIN_SPEED 30 // Minimalgeschwindigkeit, um MotorBrummen zu vermeiden
#define STOP 0 // Stopp-Signal

// Funktionsprototyp
void stopMotors(); 

/**
 * @brief Initialisiert die Motorsteuerung und die serielle Kommunikation.
 */
void setup() {
    Serial.begin(115200);
    SoftPWMBegin();
    // Initialisiert alle Motoren auf 0 (gestoppt)
    SoftPWMSet(LEFT_MOTOR_FORWARD_PIN, 0);
    SoftPWMSet(LEFT_MOTOR_REVERSE_PIN, 0);
    SoftPWMSet(RIGHT_MOTOR_FORWARD_PIN, 0);
    SoftPWMSet(RIGHT_MOTOR_REVERSE_PIN, 0);
}

/**
 * @brief Setzt die Geschwindigkeit der Motoren.
 * 
 * @param speedLeftForward Geschwindigkeit für die linke Seite vorwärts.
 * @param speedLeftBackward Geschwindigkeit für die linke Seite rückwärts.
 * @param speedRightForward Geschwindigkeit für die rechte Seite vorwärts.
 * @param speedRightBackward Geschwindigkeit für die rechte Seite rückwärts.
 */
void setMotorSpeeds(int speedLeftForward, int speedLeftBackward, int speedRightForward, int speedRightBackward) {
    SoftPWMSet(LEFT_MOTOR_FORWARD_PIN, max(speedLeftForward, STOP));
    SoftPWMSet(LEFT_MOTOR_REVERSE_PIN, max(speedLeftBackward, STOP));
    SoftPWMSet(RIGHT_MOTOR_FORWARD_PIN, max(speedRightForward, STOP));
    SoftPWMSet(RIGHT_MOTOR_REVERSE_PIN, max(speedRightBackward, STOP));
}

/**
 * @brief Bewegt den Rover vorwärts.
 * 
 * @param speed Optional. Die Geschwindigkeit für die Vorwärtsbewegung. Standard ist die Hälfte der maximalen Geschwindigkeit.
 */
void moveForward(int speed = FORWARD_SPEED / 2) {
    setMotorSpeeds(speed, STOP, speed, STOP);
    Serial.print("Rover bewegt sich vorwärts mit Geschwindigkeit: ");
    Serial.println(speed);
}
/**
 * @brief Bewegt den Rover rückwärts.
 * 
 * @param speed Optional. Die Geschwindigkeit für die Rückwärtsbewegung. Standard ist ein Viertel der maximalen Geschwindigkeit.
 */
void moveBackward(int speed = FORWARD_SPEED / 4) {
    setMotorSpeeds(STOP, speed, STOP, speed);
    Serial.print("Rover bewegt sich rückwärts mit Geschwindigkeit: ");
    Serial.println(speed);
}
/**
 * @brief Dreht den Rover nach rechts.
 * 
 * @param speed Optional. Die Geschwindigkeit für die Drehung. Standard ist ein Viertel der maximalen Geschwindigkeit.
 */
void turnRight(int speed = FORWARD_SPEED / 4) {
    setMotorSpeeds(speed, STOP, STOP, speed);
    Serial.print("Rover dreht nach rechts mit Geschwindigkeit: ");
    Serial.println(speed);
}
/**
 * @brief Dreht den Rover nach links.
 * 
 * @param speed Optional. Die Geschwindigkeit für die Drehung. Standard ist die maximale Geschwindigkeit.
 */
void turnLeft(int speed = FORWARD_SPEED / 4) {
    setMotorSpeeds(STOP, speed, speed, STOP);
    Serial.print("Rover dreht nach links mit Geschwindigkeit: ");
    Serial.println(speed);
}
/**
 * @brief Stoppt alle Motoren des Rovers.
 */
void stopMotors() {
    setMotorSpeeds(STOP, STOP, STOP, STOP);
    Serial.println("Rover stoppt.");
}

/**
 * @brief Hauptprogrammschleife, steuert die Bewegungen des Rovers.
 */
void loop() {
    moveForward(); // Bewegt sich vorwärts mit halber Geschwindigkeit
    delay(800);
    stopMotors();
    delay(2000);
    moveBackward(); // Bewegt sich rückwärts mit einem Viertel der Geschwindigkeit
    delay(800);
    stopMotors();
    delay(2000);
    turnRight(); // Dreht nach rechts mit einem Viertel der Geschwindigkeit
    delay(3000);
    stopMotors();
    delay(2000);
    turnLeft(); // Dreht nach links mit voller Geschwindigkeit
    delay(3000);
    stopMotors();
    delay(2000);
}
