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

Mit dem Siglent SDS1104X-E Oszilloskop können Sie eine Vielzahl von Messungen durchführen, die für die Entwicklung und Fehlersuche an einem autonomen Rover wie dem in Ihrem Code beschriebenen sehr nützlich sind.

### Ultraschallsensor und IR-Sensoren

- **Signalform**: Überprüfen Sie die Form der Trigger-Signale und der Echo-Signale des Ultraschallsensors sowie der Signale der IR-Sensoren, um sicherzustellen, dass sie korrekt generiert und empfangen werden.
- **Timing**: Messen Sie die Zeitdauer zwischen dem Senden und Empfangen der Signale, um die Distanzmessungen zu verifizieren und zu kalibrieren.
- **Störungen**: Suchen Sie nach möglichen elektromagnetischen Störungen oder Signalübersprechen zwischen den Sensoren, die die Messgenauigkeit beeinträchtigen könnten.

### 6x Getriebemotoren

- **PWM-Signal**: Analysieren Sie die PWM-Signale, die an die Motoren gesendet werden, um sicherzustellen, dass die Geschwindigkeit und Richtung der Motoren wie erwartet gesteuert werden.
- **Spannungsschwankungen**: Beobachten Sie die Spannung an den Motoren während des Betriebs, um festzustellen, ob es zu unerwünschten Spannungseinbrüchen kommt, die die Motorleistung beeinträchtigen könnten.
- **Motorstart- und Stoppzeiten**: Messen Sie, wie schnell die Motoren auf Befehle reagieren, um die Effizienz der Bewegungssteuerung zu optimieren.

### 18650 Batterie

- **Spannungsverlauf**: Überwachen Sie die Spannung der Batterie unter Last, um die Batterielebensdauer und den Einfluss auf die Systemleistung zu bewerten.
- **Stromaufnahme**: Messen Sie den Stromverbrauch des gesamten Systems, um die Energieeffizienz zu beurteilen und sicherzustellen, dass die Batterie die erforderliche Leistung liefern kann.

## Messungen

### Ultraschallsensor und IR-Sensoren messen

#### Signalform

- **Setup**: Verbinden Sie den Ausgangspunkt des Ultraschallsensors (TRIG) und den Eingangspunkt (ECHO) sowie die Ausgänge der IR-Sensoren mit den verschiedenen Kanälen Ihres Oszilloskops. Verwenden Sie Tastköpfe mit passender Bandbreite und stellen Sie sicher, dass sie korrekt auf das Signalniveau eingestellt sind (x1 oder x10, abhängig von der erwarteten Signalstärke).
- **Messung**: Aktivieren Sie den Sensor und beobachten Sie die Trigger- und Echo-Signale auf dem Bildschirm. Achten Sie auf die Form des Signals, um sicherzustellen, dass keine Verzerrungen oder unerwartete Änderungen vorliegen.

#### Timing

- **Messung**: Verwenden Sie die Zeitbasis und die Cursor-Funktion Ihres Oszilloskops, um die Zeit zwischen dem Senden des Trigger-Signals und dem Empfang des Echo-Signals zu messen. Diese Zeit wird verwendet, um die Entfernung zum Objekt zu berechnen. Vergleichen Sie diese Zeit mit den erwarteten Werten, um die Genauigkeit Ihrer Messung zu verifizieren.

#### Störungen

- **Untersuchung**: Überprüfen Sie das Signal auf unerwünschte Spitzen oder Rauschen, die auf elektromagnetische Störungen hindeuten könnten. Platzieren Sie die Sensoren möglicherweise näher beieinander oder fügen Sie Abschirmungen hinzu, um das Signalübersprechen zu minimieren.

### 6x Getriebemotoren messen

#### PWM-Signal

- **Messung**: Verbinden Sie das Oszilloskop mit den PWM-Ausgängen, die die Motoren steuern. Beobachten Sie die Pulsbreite und die Frequenz der PWM-Signale, um sicherzustellen, dass sie den erwarteten Werten entsprechen, die für die Steuerung der Motorgeschwindigkeit und -richtung benötigt werden.

#### Spannungsschwankungen

- **Überwachung**: Beobachten Sie die Spannung an den Motoren während des Betriebs. Verwenden Sie die AC-Kopplung Ihres Oszilloskops, um die Spannungsschwankungen zu sehen, oder die DC-Kopplung, um die Gesamtspannung einschließlich der Schwankungen zu messen.

#### Motorstart- und Stoppzeiten

- **Analyse**: Messen Sie, wie schnell die Motoren auf Steuerbefehle reagieren, indem Sie die Zeit zwischen dem Ändern des PWM-Signals und der Reaktion des Motors messen. Dies kann Ihnen helfen, die Effizienz der Bewegungssteuerung zu verbessern.

### 18650 Batterie messen

#### Spannungsverlauf

- **Überwachung**: Schließen Sie das Oszilloskop an die Batterie an, um die Spannung unter Last zu messen. Beobachten Sie, wie die Spannung variiert, wenn der Rover verschiedene Aktionen durchführt, um sicherzustellen, dass die Batterie stabil bleibt und keine unerwünschten Spannungseinbrüche auftreten.

#### Stromaufnahme

- **Messung**: Um den Stromverbrauch zu messen, benötigen Sie möglicherweise ein zusätzliches Strommessgerät oder einen Shunt-Widerstand, über den Sie die Spannung messen können, um den durch ihn fließenden Strom zu berechnen. Verbinden Sie das Oszilloskop in Serie mit dem Strommessgerät oder dem Shunt, um die Veränderungen der Stromaufnahme während des Betriebs zu beobachten.

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
