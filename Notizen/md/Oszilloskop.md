---
title: "Oszilloskop"
author: 'ju'
date: \today
bibliography: literatur-kfz.bib
csl: zitierstil-number.csl
---
<!-----------------------------------------------------------------------
ju 5-2-24  Oszilloskop.md
pandoc  Oszilloskop.md -o  Oszilloskop.html -c inhalt.css --mathjax
------------------------------------------------------------------------->

## Empfehlung eines Oszilloskops

### Faktoren zur Berücksichtigung

- **Bandbreite**: Die Bandbreite des Oszilloskops sollte mindestens so hoch sein wie die höchste Frequenz, die Sie messen möchten.
- **Abtastrate**: Eine höhere Abtastrate ermöglicht eine genauere Darstellung schneller Signale.
- **Kanäle**: Überlegen Sie, wie viele Signale Sie gleichzeitig messen müssen. Zwei Kanäle sind üblich, aber für komplexere Analysen könnten vier oder mehr Kanäle nötig sein.
- **Speichertiefe**: Eine größere Speichertiefe ermöglicht es Ihnen, längere Zeiträume des Signals bei hoher Abtastrate zu speichern.
- **Benutzerfreundlichkeit**: Die Bedienoberfläche sollte intuitiv sein, und das Gerät sollte über ausreichende Mess- und Analysefunktionen verfügen.
- **Preis**: Oszilloskope reichen von günstigen Einsteigermodellen bis hin zu hochwertigen Geräten für professionelle Anwendungen.

### Empfehlungen

1. **Einsteiger**: Rigol DS1054Z
   - Eine beliebte Wahl für Hobbyisten und Bildungszwecke. Es bietet eine gute Bandbreite (50 MHz, software-upgradebar) und vier Kanäle zu einem erschwinglichen Preis.

2. **Mittleres Segment**: Siglent SDS1104X-E
   - Ein Schritt nach oben mit einer Bandbreite von 100 MHz und vier Kanälen. Es bietet eine hohe Abtastrate und eine benutzerfreundliche Oberfläche, was es für ernsthafte Hobbyisten und semiprofessionelle Anwendungen geeignet macht.

3. **Hochwertig/Professionell**: Keysight Technologies InfiniiVision 3000T X-Series
   - Für professionelle Anwender, die eine höhere Bandbreite (bis zu mehreren GHz), ausgezeichnete Abtastraten, tiefe Speichertiefe und fortschrittliche Analysefunktionen benötigen. Diese Oszilloskope sind teurer, bieten aber hervorragende Leistung und Zuverlässigkeit.

4. **Portabel**: Fluke 123B Industrial ScopeMeter
   - Wenn Mobilität wichtig ist, sind die ScopeMeter von Fluke robust und tragbar, ideal für Feldarbeiten oder wenn Sie ein Oszilloskop an verschiedenen Orten einsetzen müssen.

## Siglent SDS1104X-E Oszilloskop

Das Siglent SDS1104X-E ist ein digitales Speicheroszilloskop (DSO), das sich durch eine hervorragende Mischung aus Leistung, Funktionen und Preis auszeichnet, wodurch es sowohl für Hobbyisten als auch für professionelle Anwender attraktiv ist.

### Eigenschaften des Siglent SDS1104X-E

- **Bandbreite**: 100 MHz, erweiterbar durch Software-Upgrade auf höhere Bandbreiten, was es flexibel für eine Vielzahl von Anwendungen macht.
- **Kanäle**: Vier analoge Kanäle, die simultane Messungen ermöglichen und es ideal für komplexe Elektronikprojekte machen, bei denen mehrere Signale gleichzeitig verfolgt werden müssen.
- **Abtastrate**: Bis zu 1 GSa/s (Giga-Samples pro Sekunde), was eine hohe Detailtreue bei der Darstellung schneller Signale ermöglicht.
- **Speichertiefe**: 14 Mpts (Mega-Punkte) pro Kanal, was lange Aufzeichnungen bei hoher Abtastrate ermöglicht und somit eine detaillierte Analyse von Signalen über längere Zeiträume hinweg unterstützt.
- **Display**: Ein großes 7-Zoll-TFT-LCD-Farbdisplay bietet eine klare und übersichtliche Anzeige der Messdaten.
- **Messfunktionen**: Es bietet eine Vielzahl von automatisierten Messfunktionen sowie mathematische Funktionen wie FFT (Schnelle Fourier-Transformation) für die Signalanalyse.
- **Konnektivität**: USB- und LAN-Schnittstellen für Datenübertragung und Fernsteuerung erweitern die Einsatzmöglichkeiten in verschiedenen Umgebungen.

### Anwendungsmöglichkeiten

Mit dem Siglent SDS1104X-E können Sie eine breite Palette von Mess- und Analyseaufgaben durchführen, darunter:

- **Signalprüfung**: Überprüfen Sie die Integrität und Qualität von analogen und digitalen Signalen.
- **Fehlersuche**: Identifizieren Sie Probleme in elektronischen Schaltungen, von einfachen Geräten bis hin zu komplexen Systemen.
- **Design und Entwicklung**: Testen und Verifizieren von elektronischen Designs während des Entwicklungsprozesses.
- **Bildungsprojekte**: Ideal für Lehr- und Lernumgebungen, um die Grundlagen der Elektronik und Signalverarbeitung zu vermitteln.

Um das volle Potenzial Ihres Siglent SDS1104X-E Oszilloskops auszuschöpfen, ist es wichtig, sich mit den Grundlagen vertraut zu machen, die Voreinstellungen und automatischen Messfunktionen effektiv zu nutzen und die mathematischen sowie Analysefunktionen zu erkunden.

### 1. Lernen Sie die Grundlagen

#### a. Aufbau und Bedienelemente

- **Display**: Vertraut machen mit dem Layout des Displays, inklusive der Wellenformanzeige, Menüleiste und Statusanzeigen.
- **Tastenfeld**: Lernen Sie die Funktionen der verschiedenen Tasten kennen, z.B. die vertikalen und horizontalen Skalierungstasten, die Menütasten für die Kanalauswahl und die Einstellungstasten für Trigger und Akquisition.
- **Drehknöpfe**: Üben Sie die Verwendung der Drehknöpfe für die Einstellung der Signalanzeige, wie z.B. die Positionierung der Wellenform, die Feinjustierung der Skalierung und die Trigger-Niveau-Einstellung.

#### b. Grundlegende Messungen

- **Kanalauswahl**: Aktivieren Sie einzelne Kanäle und passen Sie die Einstellungen wie Kopplung (AC/DC), Bandbreitenbegrenzung und Vertikalskalierung an.
- **Triggerung**: Verstehen Sie, wie Sie die Triggerquelle und -art einstellen, um stabile Signalanzeigen zu erhalten. Experimentieren Sie mit verschiedenen Triggermodi wie Edge, Pulse und Video.
- **Zeitbasis und Skalierung**: Lernen Sie, wie Sie die horizontale Skalierung anpassen, um verschiedene Teile des Signals über die Zeit zu betrachten.

### 2. Nutzen Sie die Voreinstellungen und automatischen Messfunktionen

#### a. Voreinstellungen verwenden

- **Auto Set**: Nutzen Sie die „Auto Set“-Taste, um automatisch eine geeignete Vertikal- und Horizontalskalierung für das angezeigte Signal zu wählen.
- **Messvorlagen**: Verwenden Sie vordefinierte Messvorlagen für häufige Messaufgaben, um Zeit zu sparen.

#### b. Automatische Messungen

- **Messfunktionen**: Zugriff auf die automatischen Messfunktionen für Parameter wie Frequenz, Amplitude, Anstiegszeit, Fallzeit und vieles mehr.
- **Statistische Analyse**: Aktivieren Sie die statistische Analyse für Ihre Messungen, um Durchschnittswerte, Standardabweichungen und andere statistische Daten zu erhalten.

### 3. Experimentieren Sie mit den mathematischen und Analysefunktionen

#### a. Mathematische Operationen

- **Grundlagen**: Nutzen Sie mathematische Operationen wie Addition, Subtraktion, Multiplikation und Division von Signalen, um komplexe Signale zu analysieren.
- **FFT (Schnelle Fourier-Transformation)**: Verwenden Sie die FFT-Funktion, um das Frequenzspektrum Ihres Signals zu analysieren. Dies ist besonders nützlich für die Untersuchung von Signalverzerrungen, Harmonischen und Rauschen.

#### b. Erweiterte Analyse

- **Signaldekodierung**: Wenn Ihr Modell es unterstützt, nutzen Sie die Signaldekodierungsfunktionen für serielle Busse wie I²C, SPI, UART/RS232, um Kommunikationsprotokolle zu analysieren.
- **Wellenform-Aufzeichnung**: Experimentieren Sie mit der Aufzeichnung und dem Rückblick von Wellenformsequenzen, um transiente Ereignisse zu erfassen und zu analysieren.

## Messen

Um Messungen mit einem Ultraschallsensor und einem IR-Sensor unter Verwendung eines Oszilloskops durchzuführen, müssen Sie die spezifischen Eigenschaften dieser Sensoren und die Art der Signale, die sie erzeugen oder empfangen, berücksichtigen. Hier sind allgemeine Richtlinien für beide Sensortypen:

### Ultraschallsensor-Messungen

Ultraschallsensoren senden Schallwellen aus und empfangen das Echo dieser Wellen, um die Entfernung zu Objekten zu messen. Typischerweise werden Sie das Trigger-Signal (das den Sendevorgang startet) und das Echo-Signal (das den Empfang des zurückkehrenden Schalls darstellt) messen wollen.

#### Einstellungen für das Oszilloskop Ultraschallsensoren

1. **Kopplung**: Stellen Sie die Eingangskopplung auf DC, um sowohl den Gleichspannungs- als auch den Wechselspannungsanteil des Signals zu erfassen.
2. **Zeitbasis**: Wählen Sie eine Zeitbasis, die es Ihnen ermöglicht, den gesamten Vorgang des Sendens und Empfangens des Echos zu sehen. Ein guter Startpunkt könnte 1 ms/Div sein, abhängig von der erwarteten Reichweite des Sensors.
3. **Triggerung**: Verwenden Sie die Edge-Triggerung, getriggert auf das Trigger-Signal, um das Oszilloskop zu stabilisieren und das Senden des Signals sichtbar zu machen.
4. **Vertikalskalierung**: Passen Sie die Vertikalskalierung an, um die Amplitude des Trigger- und Echo-Signals klar zu sehen. Dies hängt von den Signalpegeln ab, die Ihr Sensor verwendet.

#### Messungen Ultraschallsensoren

- **Trigger-Signal**: Überprüfen Sie die Dauer des Trigger-Signals, um sicherzustellen, dass es den Spezifikationen des Sensors entspricht (häufig 10 μs).
- **Echo-Zeit**: Messen Sie die Zeit zwischen dem Ende des Trigger-Signals und dem Beginn des Echo-Signals, um die Entfernung zu berechnen. Die Echo-Zeit ist proportional zur Entfernung zum Objekt.
- **Signalform**: Beobachten Sie die Form des Echo-Signals, um die Integrität und Stärke des empfangenen Signals zu bewerten.

### IR-Sensor-Messungen

IR-Sensoren (Infrarotsensoren) werden oft für Näherungsmessungen, Objekterkennung oder als Teil eines Kommunikationssystems verwendet. Die Messung kann die Überprüfung des Ausgangssignals in Reaktion auf ein erkanntes Objekt oder die Übertragung/der Empfang von IR-Kommunikationssignalen umfassen.

#### Einstellungen für das Oszilloskop IR-Sensor

1. **Kopplung**: DC-Kopplung, um das vollständige Signal zu erfassen.
2. **Zeitbasis**: Die Zeitbasis sollte auf die erwartete Signalgeschwindigkeit eingestellt werden. Für eine kontinuierliche Signalüberwachung kann eine breitere Zeitbasis (z.B. 100 ms/Div) nützlich sein, während für die Untersuchung von Kommunikationssignalen eine engere Zeitbasis (z.B. 10 μs/Div) erforderlich sein kann.
3. **Triggerung**: Verwenden Sie die Edge-Triggerung, ausgelöst durch das IR-Signal, um das Oszilloskop zu stabilisieren.
4. **Vertikalskalierung**: Passen Sie diese so an, dass das IR-Signal deutlich sichtbar ist, je nach Ausgangspegel des Sensors.

#### Messungen IR-Sensoren

- **Signalpräsenz**: Bestätigen Sie die Präsenz des IR-Signals, wenn ein Objekt erkannt wird oder eine IR-Kommunikation stattfindet.
- **Signalform**: Beurteilen Sie die Form des IR-Signals, um die Qualität und Stärke der Detektion oder Kommunikation zu überprüfen.
- **Kommunikationsdaten**: Bei der Messung von IR-Kommunikationssignalen, überprüfen Sie die Pulsbreiten, um die übertragenen Daten zu decodieren.

Um die in Ihrem Projekt verwendeten 6x Getriebemotoren und 18650 Batterien effektiv mit einem Oszilloskop zu messen und zu analysieren, folgen Sie diesen detaillierten Anweisungen. Diese Anleitung hilft Ihnen, wichtige Aspekte wie PWM-Signale, Spannungsschwankungen, Motorstart- und Stoppzeiten sowie den Spannungsverlauf und die Stromaufnahme der Batterie zu überwachen.

### 6x Getriebemotoren messen

#### PWM-Signal

1. **Verbindung herstellen**: Verbinden Sie das Oszilloskop mit den PWM-Ausgängen, die die Motoren steuern. Verwenden Sie geeignete Tastköpfe für Ihre Messungen.
2. **Oszilloskop einstellen**: Stellen Sie das Oszilloskop auf eine geeignete Zeitbasis ein, um die PWM-Signale klar zu sehen, typischerweise einige Mikrosekunden pro Division (μs/div), abhängig von der PWM-Frequenz.
3. **Messung durchführen**: Beobachten Sie die Pulsbreite und Frequenz der PWM-Signale. Überprüfen Sie, ob diese mit den erwarteten Werten für die Steuerung der Motorgeschwindigkeit und -richtung übereinstimmen.

#### Spannungsschwankungen

1. **Verbindung**: Verbinden Sie das Oszilloskop direkt mit den Motoranschlüssen, um die Spannung zu messen.
2. **Einstellungen anpassen**: Wählen Sie die AC-Kopplung, um Spannungsschwankungen, oder die DC-Kopplung, um die Gesamtspannung zu beobachten. Stellen Sie die Vertikalskalierung entsprechend der erwarteten Spannungshöhe ein.
3. **Beobachtung**: Achten Sie auf Spannungsspitzen oder -einbrüche, die auf Probleme in der Motorsteuerung oder Stromversorgung hinweisen könnten.

#### Motorstart- und Stoppzeiten

1. **Triggerung einstellen**: Verwenden Sie das PWM-Signal als Triggerquelle, um das Oszilloskop zu stabilisieren.
2. **Zeit messen**: Messen Sie die Zeit zwischen dem Startsignal (Änderung des PWM-Signals) und der sichtbaren Reaktion des Motors. Verwenden Sie die Cursor-Funktion des Oszilloskops für eine präzise Messung.

### 18650 Batterie messen

#### Spannungsverlauf

1. **Verbindung**: Schließen Sie das Oszilloskop direkt an die Batteriepole an.
2. **Unter Last messen**: Aktivieren Sie den Rover, um verschiedene Aktionen durchzuführen, und beobachten Sie die Spannung der Batterie unter Last.
3. **Analyse**: Achten Sie auf signifikante Spannungseinbrüche oder -spitzen, die auf eine unzureichende Batterieleistung oder potenzielle Probleme in der Stromversorgung hinweisen könnten.

#### Stromaufnahme

1. **Shunt-Widerstand**: Schalten Sie einen geeigneten Shunt-Widerstand in Serie zum Stromkreis der Batterie.
2. **Verbindung**: Verbinden Sie das Oszilloskop über den Shunt-Widerstand, um die Spannung über diesem zu messen. Die gemessene Spannung ist proportional zum Strom durch den Shunt-Widerstand.
3. **Berechnung**: Berechnen Sie den Strom durch den Shunt-Widerstand anhand des Ohmschen Gesetzes (I = V/R), wobei V die gemessene Spannung über dem Shunt und R der Widerstandswert des Shunt-Widerstands ist.

### Zusätzliche Tipps

- **Sicherheit**: Achten Sie stets auf die Sicherheit beim Umgang mit elektrischen Komponenten, insbesondere bei der Arbeit mit Batterien und Motoren.
- **Dokumentation**: Halten Sie die Ergebnisse Ihrer Messungen fest, um Veränderungen über die Zeit oder nach Anpassungen im System zu vergleichen.

## Shunt-Widerstands für die Strommessung

Die Wahl eines geeigneten Shunt-Widerstands für die Strommessung in Ihrem Rover-Projekt hängt von mehreren Faktoren ab, einschließlich des maximalen Stroms, der durch das System fließt, der Spannung, die Ihr Messgerät sicher handhaben kann, und der Auflösung, die Sie erreichen möchten. Hier sind einige Überlegungen und Empfehlungen:

### Überlegungen

1. **Maximaler Strom**: Bestimmen Sie den maximalen Strom, der durch Ihren Rover fließen wird. Dieser Wert ist wichtig, um einen Shunt-Widerstand mit einer geeigneten Nennleistung zu wählen.

2. **Spannungsabfall**: Der Shunt-Widerstand erzeugt einen Spannungsabfall proportional zum durchfließenden Strom. Dieser Spannungsabfall sollte groß genug sein, um messbar zu sein, aber nicht so groß, dass er die Leistung Ihres Systems beeinträchtigt. Ein typischer Wert für den Spannungsabfall über einen Shunt-Widerstand liegt zwischen 50 mV und 200 mV bei maximalem Strom.

3. **Auflösung und Genauigkeit**: Die Auflösung Ihres Messgeräts (z.B. eines Oszilloskops oder eines Multimeters im Strommessmodus) bestimmt, wie klein der Widerstandswert des Shunt sein kann, ohne dass die Messgenauigkeit beeinträchtigt wird.

### Empfehlungen Shunt-Widerstands für die Strommessung

- **Für niedrige Ströme (bis zu 1 A)**: Ein Widerstandswert von 0,1 Ohm bis 1 Ohm mit einer Nennleistung von mindestens 1 W könnte geeignet sein. Dies würde einen messbaren Spannungsabfall erzeugen, ohne zu viel Leistung zu verbrauchen.

- **Für mittlere Ströme (1 A bis 10 A)**: Ein Widerstandswert im Bereich von 10 mOhm bis 100 mOhm mit einer Nennleistung von 2 W bis 5 W könnte passend sein. Für solche Anwendungen sind Präzisions-Shunt-Widerstände mit niedrigem Temperaturkoeffizienten und hoher Genauigkeit verfügbar.

- **Für höhere Ströme (über 10 A)**: Sie benötigen möglicherweise einen spezialisierten Shunt-Widerstand mit einem sehr niedrigen Widerstandswert (z.B. 1 mOhm bis 10 mOhm) und einer hohen Nennleistung (10 W oder mehr), um die Wärmeentwicklung zu bewältigen.

### Spezifisches Produkt

Ein spezifisches Produkt zu empfehlen, ohne genauere Details zu Ihrem Projekt zu kennen, ist schwierig. Allerdings sind Shunt-Widerstände von Herstellern wie Vishay, Bourns oder TE Connectivity allgemein als hochwertig anerkannt. Ein Beispiel für einen häufig verwendeten Shunt-Widerstand ist der Vishay Dale WSBS8518... Serie für höhere Stromanwendungen, der eine Nennleistung von bis zu 36 W aufweisen kann und für Strommessungen in Automotive- und Industrieanwendungen entwickelt wurde.

## Verhalten des Rovers unter realen Betriebsbedingungen zu analysieren

Für die Analyse des Verhaltens Ihres Rovers unter realen Betriebsbedingungen würde ich ein integriertes System aus Datenloggern und drahtloser Kommunikation empfehlen, das es ermöglicht, Daten in Echtzeit zu erfassen und zu überwachen, während der Rover sich bewegt.

### Datenerfassung und -speicherung

- **Onboard-Datenlogger**: Verwenden Sie SD-Kartenmodule für Arduino oder die SD-Kartenfunktion des Raspberry Pi, um Daten zu speichern, falls die drahtlose Verbindung unterbrochen wird.
- **Datenformatierung**: Implementieren Sie eine Datenspeicherstruktur, die Zeitstempel für jede Messung enthält, um die Analyse zu erleichtern.

### ESP32-CAM

#### Echtzeit-Videoüberwachung

- **Kamera**: Nutzen Sie die integrierte OV2640 Kamera des ESP32-CAM für Echtzeit-Videoüberwachung oder zur Aufnahme von Fotos. Dies ermöglicht Ihnen, die Umgebung, in der sich der Rover bewegt, visuell zu analysieren und zu dokumentieren.
- **Video Streaming**: Implementieren Sie Video-Streaming über Wi-Fi, um die Live-Bilder vom Rover auf ein Smartphone, Tablet oder einen PC zu übertragen. Dies kann besonders nützlich sein, um die Navigation des Rovers zu überwachen und zu steuern.

#### Datenerfassung und -übertragung

- **Sensordaten**: Neben der Videodaten können Sie auch andere Sensordaten wie Temperatur, Beschleunigung oder sogar die Position (über GPS, falls angeschlossen) erfassen.
- **Drahtlose Kommunikation**: Verwenden Sie Wi-Fi oder Bluetooth für die drahtlose Übertragung dieser Daten in Echtzeit oder speichern Sie die Daten auf einer microSD-Karte für spätere Analysen.

#### Erweiterte Navigation und Steuerung

- **Integration des geomagnetischen Chips QMC6310**: Nutzen Sie den geomagnetischen Sensor für fortschrittliche Navigationsfunktionen, wie die Bestimmung der Ausrichtung des Rovers. Dies kann für automatisierte Navigationsrouten oder zur Verbesserung der Wegfindungsalgorithmen hilfreich sein.
- **Bewegungserkennung und -analyse**: Analysieren Sie die Bewegung des Rovers durch die Videoaufnahmen, um z.B. die Effizienz der Wegfindung oder das Verhalten bei der Hindernisumgehung zu beurteilen.

#### Programmierung und Anpassung

- **Anpassbare Skripte**: Entwickeln Sie eigene Skripte für die ESP32-CAM, um spezifische Aufgaben wie das Auslösen von Fotos unter bestimmten Bedingungen, die Steuerung der Bewegung basierend auf visuellen Signalen oder die Anpassung der Datenübertragungsraten zu automatisieren.

#### Sicherheits- und Überwachungsanwendungen

- **Überwachung**: Setzen Sie den Rover für Sicherheitsüberwachungsaufgaben ein, indem Sie die Kamera nutzen, um Bereiche zu überwachen und bei Erkennung von Bewegungen oder anderen definierten Ereignissen Benachrichtigungen zu senden.

#### Hinweise zur Implementierung

- Stellen Sie sicher, dass die Stromversorgung des ESP32-CAM Moduls den Anforderungen entspricht, insbesondere wenn Sie planen, es kontinuierlich für Video-Streaming oder umfangreiche Datenerfassung zu nutzen.
- Beachten Sie die IO-Pinbelegung und die Funktionen der Pins, insbesondere wenn Sie zusätzliche Sensoren oder Module anschließen möchten.

Das ESP32-CAM Modul bietet eine kostengünstige und flexible Lösung für erweiterte Rover-Projekte, die Videoüberwachung und die Erfassung von Sensordaten in Echtzeit erfordern. Mit seiner Hilfe können Sie nicht nur das Verhalten und die Leistung Ihres Rovers unter verschiedenen Bedingungen analysieren, sondern auch innovative Funktionen für Navigation, Sicherheit und Interaktion implementieren.
