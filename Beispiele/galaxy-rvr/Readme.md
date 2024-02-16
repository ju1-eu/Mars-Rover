"# GalaxyRVR
Das Steuerungsprogramm des GalaxyRVR für Ardunio UNO.

- [Entwicklungstestumgebung](#entwicklungstestumgebung)
- [Abhängige Bibliotheken](#abhängige-bibliotheken)
- [ESP32-CAM-Firmware](#esp32-cam-firmware)
- [Dokumentation](#dokumentation)
- [Projektstruktur](#projektstruktur)
- [Über SunFounder](#über-sunfounder)
- [Kontaktieren Sie uns](#kontaktieren-sie-uns)

## Entwicklungstestumgebung

- Board: Ardunio UNO
- IDE: Arduino IDE 1.8.19
- Compiler-Werkzeuge: Arduino AVR Boards 1.8.3

## Abhängige Bibliotheken

- IRLremote
- SoftPWM
- Servo
- ArduinoJson
- SunFounder_AI_Camera

## ESP32-CAM-Firmware
<https://github.com/sunfounder/ai-camera-firmware>

## Dokumentation
<https://docs.sunfounder.com>

## Projektstruktur

```
galaxy-rvr                  
├─ galaxy-rvr               
│  ├─ ai_camera.cpp         // Funktionen zur Kommunikation mit dem ESP32-CAM
│  ├─ ai_camera.h           
│  ├─ battery.h             // Funktionen zum Abrufen des Batteriestatus
│  ├─ car_control.cpp       // Funktionen zur Steuerung der Motoren
│  ├─ car_control.h         
│  ├─ cmd_code_config.hpp   // Die Befehlstabelle für Sprachsteuerung und das 
│  ├─ galaxy-rvr.ino        // Arduino-Hauptprogramm
│  ├─ ir_obstacle.cpp       // Funktionen für das IR-Hindernisvermeidungsmodul
│  ├─ ir_obstacle.h         
│  ├─ rgb.cpp               // Funktionen für den RGB-LED-Streifen
│  ├─ rgb.h                 
│  ├─ test.h                
│  ├─ ultrasonic.cpp        // Funktionen für das Ultraschallmodul
│  └─ ultrasonic.h          
├─ test                     
│  └─ electric-test         
│     └─ electric-test.ino  // Modultest
├─ LICENSE                  
└─ Readme.md                

```

## Über SunFounder

SunFounder ist ein Unternehmen, das sich auf STEAM-Bildung konzentriert, mit Produkten wie Open-Source-Robotern, Entwicklungsboards, STEAM-Kits, Modulen, Werkzeugen und anderen intelligenten Geräten, die weltweit vertrieben werden. Bei SunFounder bemühen wir uns, Grund- und Mittelschülern sowie Hobbyisten durch STEAM-Bildung zu helfen, ihre praktischen Fähigkeiten und Problemlösungsfähigkeiten zu stärken. Auf diese Weise hoffen wir, Wissen zu verbreiten und Fertigkeitstraining auf eine freudvolle Weise zu bieten, dadurch Ihr Interesse an Programmierung und Making zu fördern und Sie einer faszinierenden Welt der Wissenschaft und Technik näherzubringen. Um die Zukunft der künstlichen Intelligenz zu umarmen, ist es dringend und sinnvoll, reichhaltiges STEAM-Wissen zu erlernen.

## Kontaktieren Sie uns

Webseite:
    <www.sunfounder.com>

E-Mail:
    <service@sunfounder.com>"
