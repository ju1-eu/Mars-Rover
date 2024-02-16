/**
 * @file main.cpp
 * @brief Hauptsteuerungsprogramm für den Arduino GalaxyRVR.
 *
 * Dieses Programm ermöglicht die Fernsteuerung des GalaxyRVR über die
 * SunFounder Controller APP. Es integriert verschiedene Module wie
 * IR-Hinderniserkennung, Ultraschallsensorik, SoftPWM für die Motorensteuerung
 * und eine KI-Kamera für fortgeschrittene Steuerungsmöglichkeiten.
 *
 * @version 1.1.0
 * @date 2023-09-17
 * @author Sunfounder
 *
 * @see https://github.com/sunfounder/galaxy-rvr.git
 * @see https://docs.sunfounder.com/projects/galaxy-rvr/en/latest/
 */

#include <Arduino.h> ///< Kernbibliothek für die Arduino-Funktionalität.
#include <SoftPWM.h> ///< Bibliothek für Software-PWM auf digitalen Pins.
#include <string.h>  ///< Bibliothek für String-Operationen.

#include "SunFounder_AI_Camera.h" ///< Einbinden der Bibliothek für die KI-Kamera.
#include "battery.h"     ///< Bibliothek für die Batteriestatusabfrage.
#include "car_control.h" ///< Steuerungsbibliothek für die Bewegung des Fahrzeugs.
#include "cmd_code_config.hpp" ///< Konfigurationsheader für Befehlscodes.
#include "ir_obstacle.h"       ///< Bibliothek für die IR-Hinderniserkennung.
#include "rgb.h"               ///< Bibliothek für die Steuerung der RGB-LEDs.
#include "soft_servo.h" ///< Bibliothek für die Servosteuerung über Software-PWM.
#include "ultrasonic.h" ///< Bibliothek für die Ultraschallsensorik.

// Konfigurationsdefinitionen
#define WATCH_DOG 0 ///< Definition, ob der Watchdog aktiviert sein soll.
#define TEST 0      ///< Definition, ob der Testmodus aktiviert sein soll.
#define MEM 0 ///< Definition, ob die Speichernutzung ausgegeben werden soll.
#define WIFI_MODE WIFI_MODE_AP   ///< Definition des WLAN-Modus.
#define SSID "GalaxyRVR"         ///< WLAN-SSID.
#define PASSWORD "12345678"      ///< WLAN-Passwort.
#define NAME "GalaxyRVR"         ///< Produktname.
#define TYPE "GalaxyRVR"         ///< Produkttyp.
#define PORT "8765"              ///< Portnummer für WebSocket-Kommunikation.
#define OBSTACLE_AVOID_POWER 80  ///< Motorleistung für Hindernisvermeidung.
#define OBSTACLE_FOLLOW_POWER 80 ///< Motorleistung für Hindernisverfolgung.
#define VOICE_CONTROL_POWER 80   ///< Motorleistung für Sprachsteuerung.
#define FOLLOW_DISTANCE 20 ///< Distanz für die Verfolgung von Hindernissen.
#define WS_HEADER "WS+"    ///< Header für WebSocket-Kommunikation.

/*********************** Globale Variablen ****************************/
/**
 * @var AiCamera aiCam
 * @brief Instanz der AiCamera-Klasse für die serielle Kommunikation mit dem
 * ESP32-CAM Modul.
 */
AiCamera aiCam = AiCamera(NAME, TYPE);

/**
 * @var SoftServo servo
 * @brief Instanz der SoftServo-Klasse zur Steuerung des Kamera-Servos.
 */
SoftServo servo;

#define SERVO_PIN 6 ///< Pin-Nummer, an die der Servo angeschlossen ist.
#define SERVO_REVERSE                                                          \
  false ///< Gibt an, ob die Servo-Bewegungsrichtung umgekehrt werden soll.

/**
 * @var char voice_buf_temp[20]
 * @brief Temporäres Buffer für die Sprachsteuerungsbefehle.
 */
char voice_buf_temp[20];

/**
 * @var int8_t current_voice_code
 * @brief Aktueller Sprachbefehlscode.
 */
int8_t current_voice_code = -1;

/**
 * @var int32_t voice_time
 * @brief Dauer des aktuellen Sprachbefehls in Sekunden.
 */
int32_t voice_time = 0;

/**
 * @var uint32_t voice_start_time
 * @brief Startzeitpunkt des aktuellen Sprachbefehls.
 */
uint32_t voice_start_time = 0;

/**
 * @var int8_t leftMotorPower
 * @brief Leistung des linken Motors.
 */
int8_t leftMotorPower = 0;

/**
 * @var int8_t rightMotorPower
 * @brief Leistung des rechten Motors.
 */
int8_t rightMotorPower = 0;

/**
 * @var uint8_t servoAngle
 * @brief Aktueller Winkel des Servos.
 */
uint8_t servoAngle = 90;

/**
 * @var uint32_t rgb_blink_interval
 * @brief Intervall für das Blinken der RGB-LED, wenn die Verbindung getrennt
 * ist.
 */
uint32_t rgb_blink_interval = 500;

/**
 * @var uint32_t rgb_blink_start_time
 * @brief Startzeitpunkt des RGB-Blinkens.
 */
uint32_t rgb_blink_start_time = 0;

/**
 * @var bool rgb_blink_flag
 * @brief Zustand des RGB-Blinkens.
 */
bool rgb_blink_flag = 0;

/**
 * @var bool cam_lamp_status
 * @brief Status der ESP32-CAM-Blitzlampe.
 */
bool cam_lamp_status = false;

/**
 * @brief Initialisierungsfunktion für Arduino.
 *
 * Diese Funktion initialisiert die Peripheriegeräte und konfiguriert das Gerät
 * für den Start.
 */
void setup() {
  int m = millis();
  Serial.begin(115200);
  Serial.print("GalaxyRVR version ");
  Serial.println(VERSION);

  Serial.println(F("Initialzing..."));
#if defined(ARDUINO_AVR_UNO)
  SoftPWMBegin(); // init softpwm, before the motors initialization and the rgb
                  // LEDs initialization
#endif
  rgbBegin();
  rgbWrite(ORANGE); // init hint
  carBegin();
  irObstacleBegin();
  batteryBegin();
  servo.attach(SERVO_PIN);
  servo.write(90);

#if !TEST
  aiCam.begin(SSID, PASSWORD, WIFI_MODE, PORT);
  aiCam.setOnReceived(onReceive);
#endif

  while (millis() - m < 500) { // Wait for peripherals to be ready
    delay(1);
  }

#if WATCH_DOG
  wdt_disable(); /* Disable the watchdog and wait for more than 2 seconds */
  delay(3000); /* Done so that the Arduino doesn't keep resetting infinitely in
                  case of wrong configuration */
  wdt_enable(WDTO_2S); /* Enable the watchdog with a timeout of 2 seconds */
#endif

  Serial.println(F("Okie!"));
  rgbWrite(GREEN); // init finished
}

/**
 * @brief Hauptprogrammschleife.
 *
 * Enthält die Hauptlogik des Programms, einschließlich der Behandlung von
 * Kameradaten und Modussteuerung.
 */
void loop() {
#if !TEST
  // because the value in a is constantly updated
  // Note that the cycle interval of the "aiCam.loop()" should be less than 80ms
  // to avoid data d
  aiCam.loop();
  if (aiCam.ws_connected == false) {
    currentMode = MODE_DISCONNECT;
    int8_t current_voice_code = -1;
    int8_t voice_time = 0;
    if (currentMode != MODE_DISCONNECT) {
      rgb_blink_start_time = 0;
      rgb_blink_flag = 1;
    }
  } else {
    if (currentMode == MODE_DISCONNECT)
      currentMode = MODE_NONE;
  }
  modeHandler();
#else
  /* Select the item to be tested, multiple selection allowed */
  motors_test();
  // rgb_test();
  // ultrasonic_test();
  // ir_obstacle_test();
  // obstacleAvoidance();
#endif

#if WATCH_DOG
  wdt_reset(); /* Reset the watchdog */
#endif

#if MEM
  Serial.print(F("Free RAM = ")); // F function does the same and is now a built
                                  // in library, in IDE > 1.0.0
  Serial.println(freeMemory());   // print how much RAM is available in bytes.
#endif
}

/**
 * @brief Behandelt den aktuellen Modus des RVR.
 *
 * Ausführung des entsprechenden Programms basierend auf dem eingestellten
 * Modus.
 */
void modeHandler() {
  switch (currentMode) {
  case MODE_NONE:
    rgbWrite(MODE_NONE_COLOR);
    carStop();
    servoAngle = 90;
    servo.write(servoAngle);
    break;
  case MODE_DISCONNECT:
    if (millis() - rgb_blink_start_time > rgb_blink_interval) {
      rgb_blink_flag = !rgb_blink_flag;
      rgb_blink_start_time = millis();
    }
    if (rgb_blink_flag)
      rgbWrite(MODE_DISCONNECT_COLOR);
    else
      rgbOff();
    carStop();
    servoAngle = 90;
    servo.write(servoAngle);
    break;
  case MODE_OBSTACLE_FOLLOWING:
    rgbWrite(MODE_OBSTACLE_FOLLOWING_COLOR);
    servo.write(servoAngle);
    obstacleFollowing();
    break;
  case MODE_OBSTACLE_AVOIDANCE:
    rgbWrite(MODE_OBSTACLE_AVOIDANCE_COLOR);
    servo.write(servoAngle);
    obstacleAvoidance();
    break;
  case MODE_APP_CONTROL:
    rgbWrite(MODE_APP_CONTROL_COLOR);
    servo.write(servoAngle);
    carSetMotors(leftMotorPower, rightMotorPower);
    break;
  case MODE_VOICE_CONTROL:
    rgbWrite(MODE_VOICE_CONTROL_COLOR);
    servo.write(servoAngle);
    voice_control();
    break;
  default:
    break;
  }
}

/**
 * @brief Folgeprogramm für Hindernisse.
 */
void obstacleFollowing() {
  byte result = irObstacleRead();
  bool leftIsClear = result & 0b00000010;
  bool rightIsClear = result & 0b00000001;
  float usDistance = ultrasonicRead();
  // usDistance = -1 while the distance is too far
  if (usDistance < 4 && usDistance > 0) {
    carStop();
  } else if (usDistance < 10 && usDistance > 0) {
    carForward(30);
  } else if (usDistance < FOLLOW_DISTANCE && usDistance > 0) {
    carForward(OBSTACLE_FOLLOW_POWER);
  } else {
    if (!leftIsClear) {
      carTurnLeft((int8_t)OBSTACLE_FOLLOW_POWER);
    } else if (!rightIsClear) {
      carTurnRight(OBSTACLE_FOLLOW_POWER);
    } else {
      carStop();
    }
  }
}

/**
 * @brief Ausweichprogramm für Hindernisse.
 */
int8_t last_clear = -1; // last_clear, 1, left; -1, right;
bool last_forward = false;

void obstacleAvoidance() {
  byte result = irObstacleRead();
  bool leftIsClear = result & 0b00000010;  // left, clear: True
  bool rightIsClear = result & 0b00000001; // right, clear: True
  bool middleIsClear = ultrasonicIsClear();

  if (middleIsClear && leftIsClear && rightIsClear) { // 111
    last_forward = true;
    carForward(OBSTACLE_AVOID_POWER);
  } else {
    if ((leftIsClear && rightIsClear) ||
        (!leftIsClear && !rightIsClear)) { // 101, 000, 010
      if (last_clear == 1)
        carTurnLeft(OBSTACLE_AVOID_POWER);
      else
        carTurnRight(OBSTACLE_AVOID_POWER);
      last_forward = false;
    } else if (leftIsClear) { // 100, 110
      if (last_clear == 1 || last_forward == true) {
        carTurnLeft(OBSTACLE_AVOID_POWER);
        last_clear = 1;
        last_forward = false;
      }
    } else if (rightIsClear) { // 001, 011
      if (last_clear == -1 || last_forward == true) {
        carTurnRight(OBSTACLE_AVOID_POWER);
        last_clear = -1;
        last_forward = false;
      }
    }
  }
}

/**
 * @brief Sprachsteuerungsprogramm.
 */
void voice_control() {
  if (voice_time == -1) {
    voice_action(current_voice_code, VOICE_CONTROL_POWER);
  } else {
    if (millis() - voice_start_time <= voice_time) {
      voice_action(current_voice_code, VOICE_CONTROL_POWER);
    } else {
      currentMode = MODE_NONE;
      voice_start_time = 0;
      current_voice_code = -1;
    }
  }
}

/**
 * @brief Verarbeitet empfangene Daten über Websockets.
 */
void onReceive() {
  // --------------------- send data ---------------------
  // battery voltage
  // Serial.print(F("voltage:"));Serial.println(batteryGetVoltage());
  aiCam.sendDoc["BV"] = batteryGetVoltage();

  // IR obstacle detection data
  byte result = irObstacleRead();
  aiCam.sendDoc["N"] = int(!bool(result & 0b00000010)); // left, clear:0
  aiCam.sendDoc["P"] = int(!bool(result & 0b00000001)); // right, clear:0

  // ultrasonic
  float usDistance =
      int(ultrasonicRead() * 100) / 100.0; // round two decimal places
  aiCam.sendDoc["O"] = usDistance;

  // --------------------- get data ---------------------
  // Stop
  if (aiCam.getButton(REGION_I)) {
    currentMode = MODE_NONE;
    current_voice_code = -1;
    voice_time = 0;
    carStop();
    return;
  }

  // Mode select: obstacle following, obstacle avoidance
  if (aiCam.getSwitch(REGION_E)) {
    if (currentMode != MODE_OBSTACLE_AVOIDANCE) {
      currentMode = MODE_OBSTACLE_AVOIDANCE;
    }
  } else if (aiCam.getSwitch(REGION_F)) {
    if (currentMode != MODE_OBSTACLE_FOLLOWING) {
      currentMode = MODE_OBSTACLE_FOLLOWING;
    }
  } else {
    if (currentMode == MODE_OBSTACLE_FOLLOWING ||
        currentMode == MODE_OBSTACLE_AVOIDANCE) {
      currentMode = MODE_NONE;
      carStop();
      return;
    }
  }

  // cam lamp
  if (aiCam.getSwitch(REGION_M) && !cam_lamp_status) {
    Serial.println("lamp on");
    aiCam.lamp_on(5); // turn on cam lamp, level 0 ~ 10
    cam_lamp_status = true;
  } else if (!aiCam.getSwitch(REGION_M) && cam_lamp_status) {
    Serial.println("lamp off");
    aiCam.lamp_off(); // turn off cam lamp
    cam_lamp_status = false;
  }

  // Speech control
  if (currentMode != MODE_VOICE_CONTROL) {
    current_voice_code = -1;
    voice_time = 0;
    voice_start_time = 0;
    aiCam.sendDoc["J"] = 0;
  }

  int8_t code = -1;
  voice_buf_temp[0] = 0; // voice_buf_temp
  aiCam.getSpeech(REGION_J, voice_buf_temp);
  if (strlen(voice_buf_temp) > 0) {
    aiCam.sendDoc["J"] = 1;
    aiCam.sendData();
    aiCam.sendDoc["J"] = 0;
    code = text_2_cmd_code(voice_buf_temp);
    if (code != -1) {
      current_voice_code = code;
      voice_time = voice_action_time[code];
      voice_start_time = millis();
    }
  }

  if (current_voice_code != -1) {
    currentMode = MODE_VOICE_CONTROL;
  }

  // servo angle
  int temp = aiCam.getSlider(REGION_D);
  if (servoAngle != temp) {
    if (currentMode == MODE_NONE || currentMode == MODE_DISCONNECT) {
      currentMode = MODE_APP_CONTROL;
    }
    if (SERVO_REVERSE) {
      temp = constrain(temp, 40, 180);
      temp = 180 - temp;
    } else {
      temp = constrain(temp, 0, 140);
    }
    servoAngle = temp;
  }

  // throttle
  int throttle_L = aiCam.getThrottle(REGION_K);
  int throttle_R = aiCam.getThrottle(REGION_Q);
  // Serial.print("throttle_L: "); Serial.print(throttle_L);
  // Serial.print("throttle_R: "); Serial.println(throttle_R);
  if (throttle_L != 0 || throttle_R != 0 || throttle_L != leftMotorPower ||
      throttle_R != rightMotorPower) {
    currentMode = MODE_APP_CONTROL;
    leftMotorPower = throttle_L;
    rightMotorPower = throttle_R;
  }
}
