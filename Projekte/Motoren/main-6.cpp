/**
 * @file main.cpp
 * @brief Rover vorwärts bewegen und Rover rückwärts bewegen
 */
#include <Arduino.h>
#include <SoftPWM.h>

#define MOTOR_A1 2
#define MOTOR_A2 3
#define MOTOR_B1 5
#define MOTOR_B2 4

#define FORWARD_SPEED 255 // Maximalgeschwindigkeit
#define MIN_SPEED 30 // Minimalgeschwindigkeit, um Brummen zu vermeiden
#define STOP 0 // Stopp-Signal

void stopMotors(); // Funktionsprototyp

void setup() {
    Serial.begin(115200);
    SoftPWMBegin();
    // Initialisiert alle Motoren auf 0 (gestoppt)
    SoftPWMSet(MOTOR_A1, 0);
    SoftPWMSet(MOTOR_A2, 0);
    SoftPWMSet(MOTOR_B1, 0);
    SoftPWMSet(MOTOR_B2, 0);
}

void setMotorSpeeds(int speedLeftForward, int speedLeftBackward, int speedRightForward, int speedRightBackward) {
    SoftPWMSet(MOTOR_A1, max(speedLeftForward, STOP));
    SoftPWMSet(MOTOR_A2, max(speedLeftBackward, STOP));
    SoftPWMSet(MOTOR_B1, max(speedRightForward, STOP));
    SoftPWMSet(MOTOR_B2, max(speedRightBackward, STOP));
}

void moveForward(int speed = FORWARD_SPEED / 2) {
    setMotorSpeeds(speed, STOP, speed, STOP);
    Serial.print("Rover bewegt sich vorwärts mit Geschwindigkeit: ");
    Serial.println(speed);
}

void moveBackward(int speed = FORWARD_SPEED / 4) {
    setMotorSpeeds(STOP, speed, STOP, speed);
    Serial.print("Rover bewegt sich rückwärts mit Geschwindigkeit: ");
    Serial.println(speed);
}

void turnRight(int speed = FORWARD_SPEED / 4) {
    setMotorSpeeds(speed, STOP, STOP, speed);
    Serial.print("Rover dreht nach rechts mit Geschwindigkeit: ");
    Serial.println(speed);
}

void turnLeft(int speed = FORWARD_SPEED) {
    setMotorSpeeds(STOP, speed, speed, STOP);
    Serial.print("Rover dreht nach links mit Geschwindigkeit: ");
    Serial.println(speed);
}

void stopMotors() {
    setMotorSpeeds(STOP, STOP, STOP, STOP);
    Serial.println("Rover stoppt.");
}

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
