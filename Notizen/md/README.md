---
title: "README"
author: 'ju'
date: \today
bibliography: literatur-kfz.bib
csl: zitierstil-number.csl
---
<!-----------------------------------------------------------------------
ju 5-2-24 README.md
pandoc README.md -o README.html -c inhalt.css --mathjax
------------------------------------------------------------------------->

## DIY-Projekte

"DIY" steht für "Do It Yourself" und bezieht sich auf Projekte, bei denen Individuen eigenständig Dinge kreieren, bauen, modifizieren oder reparieren, anstatt sie fertig zu kaufen oder von Fachleuten erledigen zu lassen. DIY-Projekte können eine breite Palette von Aktivitäten umfassen, von Heimwerkerarbeiten über Elektronik und Softwareentwicklung. Mit der Verfügbarkeit von Anleitungen und Ressourcen im Internet hat die DIY-Bewegung an Popularität gewonnen, wobei Menschen weltweit Projekte teilen und voneinander lernen.

## IoT (Internet of Things)

IoT, das "Internet der Dinge", bezieht sich auf die Vernetzung von physischen Objekten mit dem Internet, wodurch diese Objekte Daten sammeln, senden und auf Anweisungen reagieren können. Diese Objekte, oft als "smart" oder "intelligent" bezeichnet, können eine breite Palette von Geräten und Sensoren umfassen, wie z.B. Beleuchtungssysteme, Umweltsensoren und Fahrzeuge.

## STEAM-Bildung

STEAM-Bildung steht für einen interdisziplinären Ansatz in der Bildung, der die Integration von Wissenschaft (Science), Technologie (Technology), Ingenieurwesen (Engineering), Kunst (Arts) und Mathematik (Mathematics) betont. Dieses Bildungsmodell zielt darauf ab, Schülern ein umfassendes Verständnis und Fähigkeiten in diesen Bereichen zu vermitteln, indem es die Grenzen zwischen den traditionell getrennten Fächern überbrückt. Der Ansatz fördert kritisches Denken, Problemlösungsfähigkeiten, Kreativität und Innovation bei den Lernenden.

### Hauptmerkmale der STEAM-Bildung

1. **Interdisziplinärer Ansatz**: STEAM integriert Konzepte und Fähigkeiten aus verschiedenen Disziplinen, um Lernenden zu helfen, Verbindungen zwischen den Fächern zu sehen und wie diese in der realen Welt angewendet werden können.

2. **Projektbasiertes Lernen**: STEAM fördert oft projektbasiertes Lernen, bei dem Schüler an Projekten arbeiten, die reale Probleme lösen oder kreative Werke schaffen. Dieser Ansatz fördert Teamarbeit, Kommunikationsfähigkeiten und praktische Erfahrungen.

3. **Förderung der Kreativität und Innovation**: Durch die Einbeziehung der Kunst in den traditionellen STEM-Ansatz (ohne "A" für Arts) werden Schüler ermutigt, kreativ und innovativ in ihrem Denken zu sein, was zu neuen Ideen und Lösungen führt.

4. **Betonung des lebenslangen Lernens**: STEAM-Bildung zielt darauf ab, die Neugier und die Liebe zum Lernen bei Schülern zu wecken, indem sie zeigt, wie das Gelernte in alltäglichen Situationen und zukünftigen Karrieren angewendet werden kann.

5. **Zugänglichkeit und Diversität**: STEAM-Programme bemühen sich, für alle Schüler unabhängig von ihrem Hintergrund zugänglich zu sein und fördern die Diversität in den Bereichen Wissenschaft, Technologie, Ingenieurwesen, Kunst und Mathematik.

## GNU General Public License (GPL)

Die GNU General Public License (GPL) ist eine freie Softwarelizenz, die das Recht gewährt, Software frei zu verwenden, zu studieren, zu ändern und zu verbreiten. Entwickelt von der Free Software Foundation (FSF), zielt die GPL darauf ab, die Freiheit zu sichern, Software zu teilen und zu ändern, um sicherzustellen, dass Software für alle ihre Benutzer frei ist. Es gibt mehrere Versionen der GPL, wobei die Version 3 (GPLv3) die neueste ist.

Die Kernprinzipien der GPL umfassen:

1. **Freiheit zur Ausführung der Software für jeden Zweck**: Benutzer dürfen die Software in jeder Umgebung, für jeden Zweck nutzen.
2. **Freiheit zum Studium, wie die Software funktioniert, und sie an die eigenen Bedürfnisse anzupassen**: Der Zugang zum Quellcode ist eine Voraussetzung.
3. **Freiheit zur Weiterverbreitung von Kopien**: Benutzer können Kopien der Software frei verteilen.
4. **Freiheit zur Verbesserung der Software und zur Veröffentlichung der eigenen Verbesserungen (und modifizierten Versionen im Allgemeinen)**, sodass die gesamte Community davon profitiert: Zugang zum Quellcode ist hierfür ebenfalls erforderlich.

### Software ändern die unter GPL lizenziert ist

Wenn Sie Software ändern, die unter der GNU General Public License (GPL) lizenziert ist, gibt es bestimmte Anforderungen, die Sie erfüllen müssen, um den Bedingungen der Lizenz gerecht zu werden. Hier sind die wichtigsten Punkte, die Sie beachten sollten:

1. **Quellcode muss verfügbar bleiben**: Wenn Sie die Software ändern und die modifizierte Version verbreiten, müssen Sie auch den modifizierten Quellcode unter der GPL zur Verfügung stellen. Dies stellt sicher, dass Empfänger der modifizierten Software dieselben Freiheiten haben, die ursprüngliche Software zu verwenden, zu studieren, zu ändern und weiterzuverteilen.

2. **Lizenzierung unter der GPL**: Änderungen an der Software müssen ebenfalls unter der GPL lizenziert werden. Dies bedeutet, dass Sie keine zusätzlichen Einschränkungen auferlegen dürfen, die über die Anforderungen der GPL hinausgehen.

3. **Vermerk von Änderungen**: Es ist eine gute Praxis (und in manchen Fällen erforderlich), in den Dateien, die Sie geändert haben, einen Vermerk über die Änderungen einzufügen, einschließlich des Datums der Änderung. Dies erhöht die Transparenz und hilft anderen Nutzern und Entwicklern, die Geschichte und die Art der durchgeführten Änderungen zu verstehen.
   - 2024-02-16, Max Mustermann: Funktion zur Berechnung der Geschwindigkeit hinzugefügt.
   - 2024-02-20, Erika Musterfrau: Fehler in der Geschwindigkeitsberechnung behoben.

4. **Beibehaltung von Urheberrechts- und Lizenzhinweisen**: Sie müssen alle Urheberrechts- und Lizenzhinweise, die in der ursprünglichen Software enthalten sind, unverändert lassen. Wenn Sie neue Dateien hinzufügen, die von Ihnen erstellt wurden, können Sie in diesen Dateien eigene Urheberrechts- und Lizenzhinweise hinzufügen, müssen jedoch sicherstellen, dass Ihre Lizenzierung konsistent mit der GPL ist.

\newpage

## Projekt erstellen

```bash
# Projekt erstellen
cd /Users/jan/daten/start/IOT/Mars-Rover

# Verzeichnisse erstellen
mkdir Beispiele Tutorials Dokumentation Projekte

# Notizen klonen und vorbereiten
git clone /Users/jan/notizen_latex_html_python_v1.git Notizen
cd Notizen
rm -rf .git
cd ..

# Initialisiere das Git-Repository
git init

# Erstelle eine neue Datei
touch TODO.md

# Füge Dateien zum Repository hinzu
git add .
# Committe die Änderungen
git commit -m "Initialer Commit"

# Remote-Repository auf GitHub erstellen
gh repo create Mars-Rover --public
# Füge das Remote-Repository hinzu (nachdem es auf GitHub erstellt wurde)
git remote add origin https://github.com/ju1-eu/Mars-Rover.git

# Push Änderungen zum Remote-Repository
git push -u origin main
# Änderungen von GitHub pullen (wenn nötig)
git pull origin main

# Personal Access Token (PAT) auf GitHub:
# https://github.com/settings/tokens
# 'admin:org', 'delete_repo', 'project', 'repo', 'workflow', 'write:discussion'
# Klicke auf "Generate new token"
gh auth status
gh auth login -h github.com

#---------------------------------
git add .
git commit -m"update"
git st
git push
git pull

git lg
git remote -v
git branch -a
#---------------------------------

# Lokales Bare-Repository erstellen: /Users/jan/Mars-Rover.git
git init --bare /Users/jan/Mars-Rover.git
# Verbinde dein bestehendes Projekt mit dem lokalen Bare-Repository
git remote add local-bare /Users/jan/Mars-Rover.git
# Push Änderungen zum lokalen Bare-Repository
git push local-bare main

# Lokales Repository für die Arbeit klonen
git clone /Users/jan/Mars-Rover.git
# Remote-Repository von GitHub klonen
git clone https://github.com/ju1-eu/Mars-Rover.git
```

## PlatformIO

```bash
# VS-Code / PlatformIO / Terminal
# PlatformIO CLI verwenden, um Arduino - Bibliotheken zu installieren
pio lib install "Servo"
pio lib install "SoftPWM"
# Cache löschen
pio run -t clean

# Projektordner verschieben
cd /Users/jan/Documents/PlatformIO/Projects
mv elektrik_test /Users/jan/PlatformIO/Projects
# VS-Code / Arbeitsbereich speichern unter / elektrik_test.code-workspace + Alias erstellen

# Erstellen eines Backups
cd /Users/jan/PlatformIO/Projects
zip -r Projekt_Backup_elektrik_test.zip elektrik_test/
mv *.zip /Users/jan/daten/start/IoT/Mars-Rover/Projekte
```

## ChatGPT

ChatGPT <https://chat.openai.com/>

```markdown
# Für C- oder C++-Projekte wird oft der JavaDoc-Stil empfohlen
Erstelle Code mit Doxygen-kompatiblen Kommentaren

# Zusammenfassung
benutze Konventionen für Markdown
Schreibstil: Expositorisch ohne Form du/sie
Erstelle je nach Schreibstil eine ansprechende Zusammenfassung des folgenden Artikels in Aufzählungsform und gleichzeitig gebe die wichtigsten Informationen (Didaktische Reduktion) genau wieder. Bereite die Antwort gehirngerecht auf.

# ESP32 für PlattformIO programmieren
# Konventionen von PlatformIO für C++-Projekte
Erstelle ein "Hallo Welt"-C++Programm für einen ESP32 Mikrocontroller 
Erstelle ein "Hallo Welt"-Programm in MicroPython für einen ESP32 Mikrocontroller 
```

## Quellen

[GalaxyRVR - SunFounder Mars Rover Kit](https://docs.sunfounder.com/projects/galaxy-rvr/de/latest/index.html)

Quellcode <https://github.com/sunfounder/galaxy-rvr>

Dokumentation <https://github.com/sunfounder/galaxy-rvr/blob/docs-de/docs/source/index.rst>

Arduino Language Reference <https://www.arduino.cc/reference/en/>

Arduino Downloads <https://www.arduino.cc/en/software>

**Sonix** <https://sonix.ai/de/fast-transcription>

Sonix ist ein automatisierter Transkriptionsdienst, der speziell für die Genauigkeit bei der Transkription von Audio- und Videodateien entwickelt wurde. Sonix unterstützt mehrere Sprachen und bietet eine einfache Möglichkeit, YouTube-Videos zu transkribieren, indem du die URL des Videos hochlädst.

1. Lektion 1: Enthüllung des Mars-Rovers
2. Lektion 2: Verständnis und Bau des Rocker-Bogie-Systems
3. Lektion 3: Einstieg in die Welt von Arduino und Programmierung
4. Lektion 4: Beherrschung des TT-Motors
5. Lektion 5: Entfesselung der Beweglichkeit des Mars Rovers
6. Lektion 6: Erkundung des Hindernisvermeidungsmoduls
7. Lektion 7: Verbesserung der Rover-Navigation mit Ultraschallmodul
8. Lektion 8 Fortgeschrittene Hindernisvermeidung und intelligentes Folgesystem
9. Lektion 9: Den Weg mit RGB-LED-Streifen beleuchten
10. Lektion 10: Erkundung des visuellen Systems des Mars-Rovers - Servo und Kippmechanismus
11. Lektion 11: Erforschung des visuellen Systems des Mars-Rovers - Kamera und Echtzeitsteuerung
12. Lektion 12: Steuerung des Rovers mit der App
13. Lektion 13: Untersuchung des Energiesystems des Mars-Rovers

## Hardware

- SunFounder R3 Board
- GalaxyRVR Shield
- ESP32 CAM
- Kamera-Adapterplatine
- Ultraschallmodul
- IR-Hindernisvermeidungsmodul
- 4 RGB-LED-Streifen
- Servo
- TT-Motor
- Solarpanel
- 18650 Batterie

## FAQ

1. Q1: Kompilierungsfehler: SoftPWM.h: Datei oder Verzeichnis nicht gefunden?
1. Q2: avrdude: stk500_getsync() Versuch 10 von 10: nicht synchronisiert: resp=0x6e?
1. Q3: Wie kann ich den STT-Modus auf meinem Android-Gerät verwenden?
1. Q4: Über die ESP32 CAM Firmware
1. Q5: Wie wird eine neue Firmware auf einen ESP32 CAM geflasht?
