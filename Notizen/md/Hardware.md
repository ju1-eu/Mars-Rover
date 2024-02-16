---
title: "Hardware"
author: 'ju'
date: \today
bibliography: literatur-kfz.bib
csl: zitierstil-number.csl
---
<!-----------------------------------------------------------------------
ju 5-2-24 Hardware.md
pandoc Hardware.md -o Hardware.html -c inhalt.css --mathjax
------------------------------------------------------------------------->
## Arduino Uno R3 Board

![Arduino Uno](images/uno.pdf)

- **Mikrocontroller**: ATmega328P, Herz des Arduino Uno R3 Boards, ermöglicht die Steuerung und Verarbeitung von Daten.
- **Betriebsspannung**: 5V, standardmäßig für die meisten elektronischen Komponenten und Sensoren geeignet.
- **Eingangsspannung**:
  - Empfohlen: 7-12V, idealer Bereich für stabile Leistung.
  - Limit: 6-20V, maximal zulässiger Bereich, wobei Spannungen über 12V das Board beschädigen können.
- **Digitale I/O-Pins**: 14 (mit den Nummern 0-13), von denen 6 Pins (3, 5, 6, 9-11) für PWM-Ausgänge genutzt werden können, erlauben eine flexible Steuerung von Elektronik.
- **Analoge Eingangspins**: 6 (A0-A5), für die Erfassung von analogen Signalen wie von Sensoren.
- **DC Strom pro I/O-Pin**: 20 mA, gibt den maximalen Stromfluss pro Pin an.
- **DC Strom für 3.3V Pin**: 50 mA, maximaler Stromfluss für den 3.3V Spannungsausgang.
- **Speicher**:
  - **Flash-Speicher**: 32 KB, für den Programmcode, wobei 0,5 KB vom Bootloader belegt werden.
  - **SRAM**: 2 KB, für Variablen während der Programmausführung.
  - **EEPROM**: 1 KB, für dauerhafte Datenspeicherung über Neustarts hinweg.
- **Taktfrequenz**: 16 MHz, bestimmt die Geschwindigkeit der Programmausführung.
- **LED_BUILTIN**: Pin 13, häufig verwendet für Testzwecke oder als einfache Statusanzeige.
- **Physische Abmessungen**:
  - Länge: 68,6 mm
  - Breite: 53,4 mm
  - Gewicht: 25 g
- **I2C-Port**: A4 (SDA) und A5 (SCL), für die Kommunikation mit I2C-kompatiblen Geräten.

### FLASH-SPEICHER: 32 KB

- **Verwendung**: Der Flash-Speicher dient zur Speicherung des Programmcodes. Mit 32 KB Speicherplatz können relativ umfangreiche Programme auf den ATmega328P geladen werden.
- **Bootloader**: Ein kleiner Teil des Flash-Speichers, 0,5 KB, ist für den Bootloader reserviert. Der Bootloader ermöglicht das Programmieren des Mikrocontrollers über eine einfache serielle Schnittstelle, ohne dass ein externes Programmiergerät erforderlich ist. Dies erleichtert das Hochladen von Programmen erheblich.

### SRAM: 2 KB

- **Verwendung**: SRAM (Static Random-Access Memory) wird für die Speicherung von Variablen und Zwischenergebnissen während der Ausführung eines Programms verwendet. Mit 2 KB bietet der ATmega328P genügend Platz für die meisten Anwendungen, die nicht extrem speicherintensiv sind.
- **Eigenschaften**: SRAM ist flüchtig, d.h., die Daten gehen verloren, wenn die Stromversorgung unterbrochen wird. Es ist jedoch schnell und ermöglicht einen effizienten Zugriff während der Laufzeit des Programms.

### EEPROM: 1 KB

- **Verwendung**: EEPROM (Electrically Erasable Programmable Read-Only Memory) dient zur dauerhaften Speicherung von Daten. Im Gegensatz zu Flash und SRAM bleiben die im EEPROM gespeicherten Daten auch nach dem Ausschalten des Mikrocontrollers erhalten.
- **Eigenschaften**: Mit 1 KB Speicherplatz bietet das EEPROM Platz für Konfigurationsdaten, Kalibrierwerte oder kleine Datenmengen, die zwischen den Neustarts des Mikrocontrollers persistent bleiben müssen. EEPROM-Zugriffe sind in der Regel langsamer als Flash- oder SRAM-Zugriffe und haben eine begrenzte Anzahl von Schreib-/Löschzyklen.

## GalaxyRVR Shield

![GalaxyRVR Shield Pinbelegung](images/galaxyrvr_shield_pinout.pdf)

- **Allgemeine Merkmale**:
  - Basierend auf dem ATmega328P Mikrocontroller.
  - Bietet 14 digitale Ein-/Ausgangspins, 6 analoge Eingänge und 6 PWM-Ausgänge.
  - Enthält einen 16 MHz Keramikresonator, USB-Verbindung, Strombuchse, ICSP-Header, Reset-Knopf.

- **Stromversorgung**:
  - Betriebsspannung: 5V.
  - Empfohlene Eingangsspannung: 7-12V.
  - Grenzwert der Eingangsspannung: 6-20V.
  - Integrierter Ladekreislauf für Akkus mit PH2.0-3P Schnittstelle, geschätzte Ladezeit: 130 Minuten.

- **Spezifische Funktionen**:
  - **Motoranschlüsse**: Zwei Sets für Motoranschlüsse erlauben den Anschluss von bis zu 6 Motoren, gesteuert durch Signalpins 2, 3 (rechts) und 4, 5 (links).
  - **RGB-Streifen**: Anschlüsse für 2 RGB-LED-Streifen, verbunden mit Pins 12, 13 und 11.
  - **IR-Hindernisvermeidung**: Anschlüsse für links und rechts IR-Hindernisvermeidungsmodule, angeschlossen an Pins 8 und 7.
  - **Kamera**: Anschluss für Kamera-Adapter-Board, unterstützt ESP32 CAM.
  - **Ultraschallmodul**: Anschluss für das Ultraschallmodul, Trig- und Echo-Pins sind an Pin 10 angeschlossen.
  - **Solarpanelanschluss**: Ermöglicht das Laden des Akkus über Solarpanel.

- **Weitere Features**:
  - **Ladeanzeige**: Rote LED signalisiert das Laden über USB-C-Port.
  - **Betriebsanzeige**: Grüne LED zeigt den Betriebsstatus an.
  - **Batterieanzeige**: Zwei orangefarbene LEDs zeigen den Batteriestatus an.
  - **Reset-Knopf**: Ermöglicht das Zurücksetzen des Programms auf dem Arduino-Board.
  - **Netzschalter**: Zum Ein- und Ausschalten des GalaxyRVR Shields.
  - **Modus-Schalter**: Für die Nutzung des ESP32-CAM; Änderung der Position notwendig beim Hochladen von Code, um Konflikte zu vermeiden.

## ESP32-CAM Modul

![Kameraadapter-Board](images/cam_adapter_board.pdf)

### Kernmerkmale des ESP32-CAM

- **Preis**: Ungefähr 10 Dollar, macht es zu einer erschwinglichen Option für verschiedene Projekte.
- **Kompakte Größe**: Mit Abmessungen von nur 27x40.5x4.5mm ist es extrem platzsparend.
- **Geringer Stromverbrauch**: Im Tiefschlafmodus verbraucht das Modul nur 6mA, was es besonders energieeffizient macht.

### Technische Spezifikationen

- **Mikrocontroller**: ESP32-S, unterstützt durch 520KB internes RAM und zusätzlich 8MB externes PSRAM.
- **Kamera**: OV2640 Kamera integriert.
- **Kommunikation**: Unterstützt Wi-Fi 802.11 b/g/n/e/i und Bluetooth 4.2 BR/EDR sowie BLE-Standards.
- **Speicher**: Standardmäßig mit 32Mbit SPI Flash ausgestattet.
- **Schnittstellen**: Bietet UART, SPI, I2C, PWM und unterstützt microSD-Karten bis zu 4G.
- **IO Pins**: Verfügt über 9 nutzbare GPIO Pins.
- **Stromversorgung**: Kann über einen 4.75-5.25V Eingang versorgt werden.

### Pinbelegung des ESP32-CAM (AI-Thinker Modul)

![ESP32-CAM Pinbelegung](images/esp32_cam_pinout.pdf)

- **Stromversorgung und Erdung**:
  - Drei GND-Pins für die Erdung.
  - Drei Pins für die Stromversorgung: 3.3V, 5V und ein wählbarer Pin für entweder 3.3V oder 5V.

- **Serielle Kommunikation**:
  - GPIO 1 und GPIO 3 dienen als serielle Pins, notwendig für das Hochladen von Code auf das Board.

- **Flash-Modus**:
  - GPIO 0 entscheidet über den Flash-Modus des ESP32. Bei Verbindung von GPIO 0 mit GND tritt der ESP32 in den Flash-Modus.

- **Anschluss des microSD-Kartenlesers**:
  - GPIO 14 (CLK), GPIO 15 (CMD), GPIO 2 (Daten 0), GPIO 4 (Daten 1 und an Bord LED), GPIO 12 (Daten 2), GPIO 13 (Daten 3) sind mit dem microSD-Kartenleser verbunden.

### Einsatzgebiete

Das ESP32-CAM Modul eignet sich hervorragend für eine Vielzahl von IoT-Anwendungen, darunter:

- Heim-Smart-Geräte
- Industrielle drahtlose Steuerung
- Drahtlose Überwachung
- QR-drahtlose Identifikation
- Drahtlose Positionierungssysteme

### Hinweise zur Verwendung

- **Stromversorgung**: Für eine optimale Funktion sollte das Modul mit mindestens 5V und 2A versorgt werden.
- **GPIO32**: Steuert die Stromversorgung der Kamera. Muss für den Betrieb nach unten gezogen werden.
- **GPIO0**: Wichtig für den Flash-Modus des ESP32. Muss mit GND verbunden sein, um den Flash-Modus zu aktivieren.
- **Interne Anschlüsse**: Mehrere GPIOs sind intern mit dem microSD-Kartenleser verbunden, was bei der Verwendung dieser Pins berücksichtigt werden muss.

| Merkmal                      | Spezifikation                                 |
|------------------------------|-----------------------------------------------|
| Modell                       | ESP32-CAM                                     |
| Gehäuse                      | DIP-16                                        |
| Größe                        | 27\*40.5\*4.5（+/-0.2）mm                       |
| SPI Flash                    | Standard 32Mbit                               |
| RAM                          | Intern 520KB + Extern 8MB PSRAM               |
| Bluetooth                    | Bluetooth 4.2 BR/EDR und BLE-Standards        |
| Wi-Fi                        | 802.11 b/g/n/e/i                              |
| Unterstützte Schnittstellen  | UART, SPI, I2C, PWM                           |
| Unterstützt TF-Karte         | bis zu 4G                                     |
| IO Pins                      | 9                                             |
| Serielle Portgeschwindigkeit | Standard 115200 bps                           |
| Bildausgabeformat            | JPEG (nur OV2640 unterstützt), BMP, GRAUSTUFE |
| Spektrumbereich              | 2400 ~2483.5MHz                               |
| Antennentyp                  | On-Board PCB-Antenne, Gewinn 2dBi             |
| Sendeleistung                | 802.11n: 13+/-2 dBm (@MCS7)                   |
| Empfindlichkeit              | CCK, 1 Mbps: -90dBm                           |
| Stromverbrauch               | Tiefschlaf: 6mA@5V                            |
| Sicherheit                   | WPA/WPA2/WPA2-Enterprise/WPS                  |
| Stromversorgungsbereich      | 4.75-5.25V                                    |
| Betriebstemperatur           | -20 ~ 70 °C                                   |
| Lagerumgebung                | -40 ~ 125 °C , < 90\%RH                       |

### Stromverbrauch

- Flash aus: 180mA@5V,
- Flash an und Helligkeit maximal: 310mA@5V,
- Tiefschlaf: der niedrigste Stromverbrauch kann 6mA@5V erreichen,
- Modem-Schlaf: Minimum 20mA@5V,
- Licht-Schlaf: Minimum 6.7mA@5V

## Kamera-Adapterplatine

![Kamera-Adapterplatine](images/cam_adapter_board.pdf)

![Kamera-Adapterplatine für ESP32-CAM](images/cam_adapter_esp32cam.pdf)

![Dreiaxialer Magnetfeldsensor, Chips QMC6310, geeignet für Navigation](images/cam_adapter_qmc6310.pdf)

![Kamera-Adapterplatine Schaltplan](images/cam_adapter_sche.pdf)

- **RST:** Wird verwendet, um die ESP32-CAM zurückzusetzen.
- **SCL:** Serieller Datenpin für QMC6310
- **SDA:** Serieller Uhrenpin des QMC6310
- **RXD:** RXD der ESP32-CAM, Sie benötigen diese beiden seriellen Pins, RXD und TXD, um Code auf die ESP32-CAM hochzuladen.
- **TXD:** TXD der ESP32-CAM
- **5V:** 5V DC-Eingang
- **GND:** Masse-Eingang

- **Kamera-Adapterplatine für ESP32-CAM**:
  - Entwickelt, um die ESP32-CAM zu erweitern und eine einfache Montage am Roboter sowie Verkabelung zu ermöglichen.
  - Beinhaltet Anschlüsse wie RST (Reset), SCL und SDA (für QMC6310), RXD und TXD (für Code-Upload), 5V DC-Eingang und GND (Masse).

- **Integration des geomagnetischen Chips QMC6310**:
  - Um Störungen durch Motoren zu vermeiden, ist der QMC6310 auf der Adapterplatine platziert, entfernt von Motoren.
  - QMC6310: Dreiaxialer Magnetfeldsensor, geeignet für Anwendungen wie E-Kompass, Kartenrotation, Gaming und persönliche Navigation.

- **Technische Details der Kamera-Adapterplatine**:
  - Betriebsspannung: 5V.
  - Schnittstellenmodell: ZH1.5, 7P.
  - Abmessungen: 40mm x 27mm x 15mm.
  - Kommunikationsprotokoll: UART und I2C.

- **Eigenschaften des QMC6310**:
  - Integriert magnetische Sensoren und Signalzustands-ASIC auf einem Siliziumchip.
  - Nutzt hochauflösende, magnetoresistive Technologie mit einem 16-Bit-ADC-ASIC.
  - Bietet Vorteile wie geringes Rauschen, hohe Genauigkeit, geringer Stromverbrauch, Offset- und Temperaturkompensation.
  - Kompassgenauigkeit von 1° bis 2°.
  - Einfache Schnittstellenanbindung über I2C-Serienbus.
  - Verpackt in einem 1,2x1,2x0,53mm^3 großen, 8-Pin-LGA-Gehäuse.

## Ultraschallmodul

![Ultraschallmodul](images/ultrasonic_pic.pdf)

- **HC-SR04 Ultraschall-Abstandssensor**:
  - Bietet berührungslose Messungen im Bereich von 2 cm bis 400 cm.
  - Bereichsgenauigkeit: bis zu 3 mm.
  - Enthält Ultraschall-Sender, Empfänger und Steuerschaltung.

- **Anschluss**:
  - Vier Pins: VCC (5V Versorgung), TRIG (Trigger-Pulseingang), ECHO (Echo-Pulseausgang), GND (Erdung).

- **Merkmale**:
  - Betriebsspannung: DC5V.
  - Betriebsstrom: 16mA.
  - Arbeitsfrequenz: 40Hz.
  - Maximaler Messbereich: 500cm.
  - Minimaler Messbereich: 2cm.
  - Trigger-Eingangssignal: 10uS TTL-Impuls.
  - Echo-Ausgangssignal: TTL-Pegelsignal, Dauer proportional zur Entfernung.
  - Steckverbinder: XH2.54-4P.
  - Abmessungen: 46x20.5x15 mm.

- **Funktionsprinzip**:
  - Auslösen eines 10us hohen Signals über IO-Trigger.
  - Senden eines 8-Zyklus-Bursts von Ultraschall bei 40 kHz und Empfangen des Echo-Signals.
  - **Messprinzip** Sensor misst Entfernungen durch das Senden und Empfangen von Ultraschallwellen. Der Prozess beginnt mit einem Trigger-Signal und endet mit der Berechnung der Distanz basierend auf der Echo-Zeit.

- **Anwendungshinweise**:
  - Modul nicht unter Strom anschließen; zuerst GND verbinden.
  - Das Messobjekt sollte mindestens 0,5 Quadratmeter groß und möglichst flach sein für präzise Ergebnisse.

## IR-Hindernisvermeidungsmodul

![IR Hindernisvermeidungsmodul](images/ir_avoid.pdf)

![IR Empfängermodul](images/ir_receive.pdf)

- **IR-Hindernisvermeidungsmodul**:
  - Dient der Erkennung von Objekten im Bereich von 2 cm bis 40 cm.
  - Die Reflexionsniveaus variieren je nach Farbe des Objekts, wobei dunklere Objekte den Erfassungsbereich verkürzen.

- **Pin-Definitionen**:
  - GND: Erdung.
  - +: Stromversorgung, zwischen 3,3 und 5V DC.
  - Out: Standardmäßig hoch; wird niedrig bei Hinderniserkennung.
  - EN: Enable-Pin, standardmäßig mit GND verbunden, hält das Modul aktiv.

- **Funktionsweise**:
  - Beinhaltet ein IR-Sender-Empfänger-Paar.
  - Der Sender emittiert Infrarotlicht, das von Hindernissen reflektiert und vom Empfänger detektiert wird, woraufhin ein niedriges Signal ausgegeben wird.

- **EN-Pin und Jumper**:
  - Der niedrige Zustand des EN-Pins aktiviert das Modul.
  - Der Jumper verbindet den EN-Pin mit GND; für programmierte Steuerung wird sie entfernt.

- **Potentiometer für Einstellungen**:
  - Zwei Potentiometer zur Einstellung der Sendeleistung und -frequenz.
  - Ermöglicht Anpassung der effektiven Entfernung.

- **Kalibrierung**:
  - Erfordert präzise Ausrichtung und Anpassung der Potentiometer, um die gewünschte Erfassungsdistanz zu erreichen.

- **Technische Spezifikationen**:
  - Betriebsspannung: 3,3 V bis 5 V.
  - Ausgang: Digital (Ein/Aus).
  - Einstellschwelle: Durch 2 Potentiometer einstellbar.
  - Distanzbereich: 2 bis 40 cm.
  - Betriebstemperatur: -10 °C bis +50 °C.
  - Effektiver Winkel: 35°.
  - I/O-Schnittstelle: 4-Draht (- / + / S / EN).
  - Abmessungen: 45 x 16 x 10 mm.
  - Gewicht: 9 g.

## RGB-LED-Streifen

![4-Pin RGB-LED-Streifen](images/4_rgb_strip.pdf)

![RGB-LED-Streifen Schaltplan](images/rgb_strip_sche.pdf)

### Eigenschaften von RGB-LED-Streifen

- Verwendet vier R5050 RGB-LEDs für die Farberzeugung durch Mischung von Rot, Blau und Grün.
- Konfiguration mit gemeinsamer Anode (+5V) und individuellen Kathoden (B, R, G) für jede Farb-LED.
- Jede LED funktioniert unabhängig, erlaubt das Schneiden des Streifens an markierten Stellen ohne Beeinträchtigung anderer Segmente.
- Flexibel und einfach zu installieren dank FPC-Platine mit doppelseitigem Klebstoff.

### R5050 RGB-LED

- Kombiniert rote, blaue und grüne LEDs in einem Gehäuse für breite Farbpalette.
- Individuelle Steuerung jeder LED-Farbe durch separate Pins.
- Ermöglicht anpassbare Farbbeleuchtung für dekorative Beleuchtung und Displaytechnologien.

### Technische Merkmale

- Arbeitsspannung: DC5V.
- Vollfarbe RGB.
- Arbeitstemperatur: -15 °C bis 50 °C.
- RGB-Typ: 5050RGB.
- Strom: 150mA pro Einzelschaltkreis.
- Leistung: 1.5W.
- Dicke des Lichtstreifens: 2mm; Breite: 5.5mm.
- Anschlusskabel: ZH1.5-4P, 25cm Länge, 28AWG, in Schwarz.

### Anwendung und Konfiguration

- Mehrere R5050 RGB-LEDs werden auf einem flexiblen Schaltkreis smart angeordnet.
- Gemeinsame Anoden aller LEDs sind verbunden, während Kathoden an jeweilige Farbleitungen angeschlossen sind.
- Diese Anordnung unterstützt effiziente Farbmischung und Lichtintensitätssteuerung.

### Gesamtstromverbrauch

Angenommen, der Gesamtstromverbrauch aller drei farbigen LEDs (Rot, Grün, Blau) in einem 5050 RGB-LED-Paket beträgt 150 mA und jede LED wird mit einer Spannung von 5V betrieben.

$I_{gesamt} = 4 \times 150\, \text{mA} = 600\, \text{mA}$

### Gesamtleistung

Die Leistung ($P$) kann mit der Formel $P = U \times I$ berechnet werden:

$P_{einzel} = 5V \times 150\, \text{mA} = 0.75\, \text{W}$

Für alle vier Pakete:

$P_{gesamt} = 4 \times 0.75\, \text{W} = 3\, \text{W}$

## Servo

![Servo Funktion](images/servo_internal.pdf)

### Grundlegende Eigenschaften

- Ein Servo ist ein Motor, spezialisiert auf präzise Steuerung von Winkelpositionen.
- Ausgestattet mit brauner (GND), orangefarbener (PWM-Signalleitung) und roter Leitung (VCC für Spannungsversorgung).

### Unterschiede zu herkömmlichen Motoren

- Fähigkeit, zu spezifischen Positionen zu bewegen und diese exakt zu halten.
- Kombiniert Zahnräder, ein Potentiometer und eine Steuerschaltung für seine Funktionalität.
- Einsatz in Anwendungen, die präzise Positionskontrolle erfordern.

### Technische Spezifikationen

- **Motortyp**: Kernmotor.
- **Betriebsspannung**: 4,8 bis 6V DC.
- **Stromverbrauch**: <=50mA bei 4,8V, <=60mA bei 6V im Leerlauf.
- **Blockierstrom**: <=550mA bei 4,8V, <=650mA bei 6V.
- **Drehmoment**: >=0,6 kgf x cm bei 4,8V, >=0,7 kgf x cm bei 6V (Nennwert); >=1,4 kgf x cm bei 4,8V, >=1,6 kgf x cm bei 6V (Maximalwert).
- **Leerlaufdrehzahl**: <=0,14s/60° bei 4,8V; <=0,12s/60° bei 6V.
- **Betriebs- und Lagerungstemperatur**: -10 bis +50°C bzw. -20°C bis +60°C.
- **Feuchtigkeitsbereiche**: <= 90\%RH für Betrieb und Lagerung.
- **Gewicht**: 10+/- 0,5g.
- **Material**: ABS.
- **Betriebswinkel**: 180°+/-10°.
- **Mechanischer Begrenzungswinkel**: 360°.

### kgf (Kilogrammkraft)

"kgf x cm" ist eine Einheit für Drehmoment, die Kilogrammkraft-Zentimeter bedeutet. Diese Einheit wird verwendet, um auszudrücken, wie viel Drehmoment, also die Kraft einer Drehbewegung, von einem Motor ausgeübt werden kann.

- **kgf (Kilogrammkraft)**: Eine Krafteinheit, die der auf ein Kilogramm Masse auf der Erdoberfläche ausgeübten Gravitationskraft entspricht. Technisch gesehen entspricht 1 kgf etwa 9,81 Newton (N), der SI-Einheit der Kraft.
- **cm (Zentimeter)**: Eine Längeneinheit im metrischen System, die 1/100 eines Meters entspricht.

### Drehmomentwerte des Servos in Newtonzentimeter (Ncm)

```python
# Umrechnungsfaktor von kgf·cm in Ncm
umrechnungsfaktor_kgf_cm_zu_n_cm = 9.81

# Gegebene Drehmomentwerte in kgf·cm
drehmoment_nenn_48v_kgf_cm = 0.6
drehmoment_nenn_6v_kgf_cm = 0.7
drehmoment_max_48v_kgf_cm = 1.4
drehmoment_max_6v_kgf_cm = 1.6

# Umrechnung in Ncm
drehmoment_nenn_48v_n_cm = drehmoment_nenn_48v_kgf_cm * umrechnungsfaktor_kgf_cm_zu_n_cm
drehmoment_nenn_6v_n_cm = drehmoment_nenn_6v_kgf_cm * umrechnungsfaktor_kgf_cm_zu_n_cm
drehmoment_max_48v_n_cm = drehmoment_max_48v_kgf_cm * umrechnungsfaktor_kgf_cm_zu_n_cm
drehmoment_max_6v_n_cm = drehmoment_max_6v_kgf_cm * umrechnungsfaktor_kgf_cm_zu_n_cm

drehmoment_nenn_48v_n_cm, drehmoment_nenn_6v_n_cm, drehmoment_max_48v_n_cm, drehmoment_max_6v_n_cm
```

- Bei **4,8V Nennwert**: ≥0,6 kgf·cm entspricht etwa 5,89 Ncm.
- Bei **6V Nennwert**: ≥0,7 kgf·cm entspricht etwa 6,87 Ncm.
- Bei **4,8V Maximalwert**: ≥1,4 kgf·cm entspricht etwa 13,73 Ncm.
- Bei **6V Maximalwert**: ≥1,6 kgf·cm entspricht etwa 15,70 Ncm.

Diese Werte verdeutlichen die Kraft, die der Servo bei unterschiedlichen Spannungen ausüben kann, und zeigen, dass mit steigender Spannung das Drehmoment des Servos zunimmt.

## TT-Motor

![Motor](images/motor_size.pdf)

![TT-Getriebemotor](images/tt_motor_xh.pdf)

### Beschreibung

- Der TT-DC-Getriebemotor ist mit einem Übersetzungsverhältnis von 1:120 ausgestattet und für den Betrieb mit 3VDC konzipiert.
- Ausgeliefert wird der Motor mit zwei 250 mm langen Kabeln, die über einen XH2.54-2P-Stecker verfügen.

### Funktionsweise von Motoren

- Motoren wandeln elektrische in mechanische Energie um
- Ein Strom erzeugt ein Magnetfeld, das mit anderen Magneten interagiert und den Motor in Rotation versetzt.
- Diese Drehbewegung kann dann auf Räder übertragen werden.

### Spezifikationen des TT-Getriebemotors

- **Spannungsbereich**: 3V bis 4.5V DC.
- **Anzahl der Wellen**: Einzelwelle.
- **Übersetzungsverhältnis**: 1:120.
- **Leerlaufstrom**: 130mA.
- **Leerlaufgeschwindigkeit**: 38rpm+/-8\%rpm.
- **Startspannung**: Mindestens 2V im Leerlauf.
- **Ausgangsdrehmoment**: Bei 3V über 1.2kgf x cm.
- **Lebensdauer**: Zwischen 70 und 120 Stunden.
- **Drehrichtung**: Kann in beide Richtungen drehen.
- **Körperabmessungen**: 70 x 22,5 x 36,6mm.
- **Kabel**: Grau und Schwarz, 24AWG, 250mm Länge.
- **Stecker**: Weiß, XH2.54-2P.
- **Gewicht**: 28,5g.

### Gesamtdrehmoment berechnen

Um das Gesamtdrehmoment in Newtonzentimeter (Ncm) zu berechnen, das von sechs TT-DC-Getriebemotoren auf einem Marsrover bei einer Spannung von 3V erzeugt wird, wenn jedes einzelne Motor ein Ausgangsdrehmoment von über 1.2 kgf·cm liefert.

1. **Umrechnung von kgf·cm in Ncm**:
   - Da 1 kgf etwa 9.81 N, entspricht 1 kgf x cm somit 9.81 Ncm.

2. **Berechnung des Drehmoments pro Motor in Ncm**:
   - $1.2 \, \text{kgf·cm} \times 9.81 \, \text{Ncm/kgf·cm} = 11.772 \, \text{Ncm}$

3. **Gesamtdrehmoment für sechs Motoren**:
   - $11.772 \, \text{Ncm} \times 6 = 70.632 \, \text{Ncm}$

```python
# Umrechnung von kgf·cm in Ncm für ein Drehmoment von 1.2 kgf·cm
drehmoment_pro_motor_kgf_cm = 1.2
umrechnungsfaktor_kgf_cm_zu_n_cm = 9.81  # 1 kgf·cm entspricht 9.81 Ncm

# Berechnung des Drehmoments pro Motor in Ncm
drehmoment_pro_motor_n_cm = drehmoment_pro_motor_kgf_cm * umrechnungsfaktor_kgf_cm_zu_n_cm

# Gesamtdrehmoment für sechs Motoren in Ncm
gesamtdrehmoment_n_cm = drehmoment_pro_motor_n_cm * 6

gesamtdrehmoment_n_cm
```

Das Gesamtdrehmoment, das von den sechs TT-DC-Getriebemotoren auf einem Marsrover bei einer Spannung von 3V erzeugt wird, beträgt etwa 70.632 Ncm (Newtonzentimeter).

Dieses Drehmoment ermöglicht dem Rover, effektiv Bewegungen und Aktionen auf der Marsoberfläche durchzuführen, wie das Überwinden von Hindernissen oder das Manövrieren in schwierigem Gelände, indem es eine starke und präzise Kraftübertragung auf die Räder oder andere mechanische Komponenten bietet.

## Solarpanel

![Solarpanel](images/solar_panel.pdf)

Solarpanele wandeln Lichtenergie der Sonne in elektrische Energie um.

- **Funktionsweise**: Solarpanele bestehen aus photovoltaischen Zellen, häufig aus Silizium. Diese Zellen wandeln Sonnenlicht direkt in Elektrizität um. Wenn Sonnenlicht auf die Zellen trifft, werden Elektronen freigesetzt, die durch das Material fließen und so einen elektrischen Strom erzeugen.

- **Merkmale eines Solarpanels**:
  - **Ausgangsleistung**: 6V/660mA, was die Energiemenge angibt, die das Panel unter optimalen Bedingungen erzeugen kann.
  - **Ladezeit**: Es benötigt theoretisch 7,2 Stunden unter starkem Sonnenlicht, um einen Akku vollständig aufzuladen. Diese Zeit kann als Richtwert für die Effizienz des Panels dienen.
  - **Größe**: Mit Abmessungen von 170mm x 170mm ist es kompakt und vielseitig einsetzbar.
  - **Kabel und Stecker**: Ausgestattet mit einem grauen und schwarzen Kabel (200mm lang, 24AWG) und einem weißen XH2.54-2P Stecker, was die Installation und Verbindung erleichtert.

### Rechenbeispiel unter verschiedenen Lichtverhältnissen

Um die Auswirkungen verschiedener Lichtverhältnisse auf Solarpanels zu illustrieren, nehmen wir an, dass ein Solarpanel unter optimalen Bedingungen (starkes Sonnenlicht) eine Ausgangsleistung von 6V/660mA liefert und einen Akku in 7,2 Stunden vollständig aufladen kann.

1. **Starkes Sonnenlicht**:
   - Ausgangsleistung: 6V/660mA
   - Ladezeit: 7,2 Stunden

2. **Schwaches Sonnenlicht** (angenommen 50\% der optimalen Bedingungen):
   - Ausgangsleistung wird halbiert: 6V/330mA (0,33A)
   - Ladezeit verdoppelt sich theoretisch: 14,4 Stunden

3. **Bewölkt** (angenommen 25\% der optimalen Bedingungen):
   - Ausgangsleistung wird auf ein Viertel reduziert: 6V/165mA (0,165A)
   - Ladezeit vervierfacht sich theoretisch: 28,8 Stunden

4. **Nacht**:
   - Keine Ausgangsleistung, da keine Sonneneinstrahlung vorhanden ist: 0mA (0A)
   - Keine Aufladung möglich

### Auswirkungen

- **Starkes Sonnenlicht** ermöglicht die maximale Effizienz des Solarpanels, wodurch der Akku in der kürzesten Zeit aufgeladen wird.
- **Schwaches Sonnenlicht** und **bewölkte Bedingungen** reduzieren die Ausgangsleistung des Panels, was zu einer verlängerten Ladezeit führt.
- **Nacht** ist keine Aufladung möglich, da das Solarpanel auf die Umwandlung von Sonnenlicht in elektrische Energie angewiesen ist.

## 18650 Batterie

![3-Pin 18650 Batterie](images/3pin_battery.pdf)

- **Aufbau**: Das Batteriepaket besteht aus zwei 18650 Zellen mit jeweils einer Kapazität von 2000mAh, was eine Gesamtkapazität von 4000mAh ergibt.
- **Anschlüsse**:
  - **VCC**: Positive Anschlüsse, vorhanden in zwei Sätzen, um den Stromfluss zu erhöhen und den Widerstand zu minimieren.
  - **Middle**: Dient der Spannungsausgleichung zwischen den Zellen, um die Batterie zu schützen.
  - **GND**: Negative Anschlüsse für den Stromkreis.
- **Anschlussart**: Verwendet wird ein XH2.54 3P-Anschluss, der eine direkte Aufladung des Batteriepakets ermöglicht, sobald es in ein kompatibles Shield eingesteckt wird.
- **Leistung**:
  - **Ladung**: Das Batteriepaket kann mit 5V/2A aufgeladen werden.
  - **Ausgang**: Es liefert einen Ausgang von 5V/5A, geeignet für Anwendungen, die eine hohe Stromstärke benötigen.
- **Spezifikationen**:
  - **Batteriekapazität**: Jede Zelle hat eine Kapazität von 3.7V und 2000mAh, insgesamt also 4000mAh bei Zusammenschaltung.
  - **Batterielebensdauer**: Das Paket ermöglicht eine Laufzeit von etwa 90 Minuten bei voller Ladung.
  - **Ladezeit**: Die vollständige Aufladung des Batteriepakets dauert ca. 130 Minuten.

### Ladeanschluss (Charge Port)

- **Typ**: USB-C-Port mit 5V/2A für das Aufladen.
- **Ladezeit**: Der Akku kann innerhalb von 130 Minuten vollständig aufgeladen werden.

### Batterieanschluss (Battery Port)

- **Spannungsbereich**: 6.6V bis 8.4V über einen PH2.0-3P-Stromversorgungseingang.

### Solaranschluss

- **Funktion**: Ermöglicht das Aufladen des Akkus über ein Solarpanel.
- **Anschlusstyp**: XH2.54, 2P.
- **Ausgangsleistung des Solarpanels**: 6V/660mA.
- **Ladezeit**: Unter starkem Sonnenlicht kann der Akku theoretisch in 7,2 Stunden vollständig aufgeladen werden.

### 2x18650 Batterien in Reihe

- **Konfiguration**: Zwei 18650 Batterien, jede mit 3.7V und 2000mAh.
- **Schaltung in Reihe**: Durch die Reihenschaltung der beiden Batterien erhöht sich die Gesamtspannung auf 7.4V, während die Gesamtkapazität bei 2000mAh bleibt.

### Ladezeit berechnen

Die Ladezeit eines Akkus hängt von seiner Kapazität (in Milliamperestunden, mAh) und dem Ladestrom (in Ampere, A) ab.

$\text{Ladezeit (Stunden)} = \frac{\text{Kapazität des Akkus (mAh)}}{\text{Ladestrom (mA)}}$

Für zwei 18650 Batterien in Reihe geschaltet, mit jeweils 3.7V und 2000mAh, ergibt sich eine Gesamtspannung von 7.4V und eine Kapazität von 2000mAh (da die Kapazität in Reihe gleich bleibt). Der Ladestrom ist mit 2A (oder 2000mA) angegeben.

```python
# Gegebene Daten
kapazitaet_mAh = 2000  # Kapazität einer der 18650 Batterien in mAh
ladestrom_mA = 2000  # Ladestrom in mA (5V/2A)

# Berechnung der Ladezeit in Stunden
ladezeit_stunden = kapazitaet_mAh / ladestrom_mA

# Umrechnung der Ladezeit in Minuten
ladezeit_minuten = ladezeit_stunden * 60

ladezeit_minuten
```

Die berechnete Ladezeit für eine 18650 Batterie mit einer Kapazität von 2000mAh unter Verwendung eines Ladestroms von 2A (2000mA) beträgt 60 Minuten.

Die Angabe von 130 Minuten Ladezeit könnte auf eine konservativere Schätzung hinweisen, die möglicherweise Effizienzverluste beim Laden oder die Charakteristiken des spezifischen Ladesystems berücksichtigt. Es könnte auch darauf hindeuten, dass der tatsächliche Ladestrom unter bestimmten Umständen, wie zum Beispiel bei niedrigerer Spannung des Ladegeräts oder bei internen Widerständen in der Batterieschaltung, effektiv niedriger als 2A ist, was zu einer längeren Ladezeit führt.

### Batterielebensdauer und Entladestromstärke berechnen

Wenn die Batterie 90 Minuten lang hält, können wir den durchschnittlichen Entladestrom ($I$) berechnen, der für diese Laufzeit benötigt wird, mit der Formel:

$I = \frac{\text{Kapazität}}{\text{Betriebsdauer in Stunden}}$

Um die Betriebsdauer in Stunden umzurechnen, teilen wir 90 Minuten durch 60:

$\text{Betriebsdauer} = \frac{90}{60} = 1,5 \, \text{Stunden}$

Daraus ergibt sich:

$I = \frac{2000 \, \text{mAh}}{1,5 \, \text{Stunden}} = \frac{2000}{1,5} \, \text{mA} = 1333,33 \, \text{mA}$

Dies bedeutet, dass das Gerät durchschnittlich etwa 1333,33 mA (oder 1,33 A) über die Dauer von 90 Minuten verbraucht, um die Batterie vollständig zu entladen.
