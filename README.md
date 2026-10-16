# vehicle-tracking-system

Hardware project implementation of a vehicle tracking device: an Arduino sketch that reads
the vehicle's position from a GPS module and sends it by SMS through a GSM module.

## Overview

When a trigger input goes high, the sketch decodes NMEA data from the GPS receiver, then
uses AT commands to send a text message containing the latitude, longitude and a Google
Maps link to a preconfigured phone number. The same information is echoed to the serial
monitor for debugging.

## Hardware

- Arduino board (Uno or similar)
- GPS module (serial NMEA output)
- GSM module (e.g. SIM800/SIM900) with a SIM card that can send SMS
- A digital trigger signal on pin 13 (e.g. a switch or button)

### Wiring (as defined in the sketch)

| Arduino pin | Connected to |
|-------------|--------------|
| 2 (RX), 3 (TX) | GPS module, via `SoftwareSerial`, 9600 baud |
| 9 (RX), 10 (TX) | GSM module, via `SoftwareSerial`, 9600 baud |
| 13 | Trigger input; tracking runs while it reads HIGH |

## Software

- Arduino IDE
- Libraries: `SoftwareSerial` (bundled) and [TinyGPS](https://github.com/mikalhart/TinyGPS)

## Project structure

```
vts/
  vts.ino   # GPS read + SMS send sketch
```

## Getting started

1. Install the TinyGPS library in the Arduino IDE.
2. Open `vts/vts.ino`.
3. Replace the phone number in the `AT+CMGS` line with the number that should receive
   the location messages.
4. Wire the modules as shown above, upload the sketch and open the serial monitor at
   4800 baud to watch the output.

## Status

Student hardware project from April 2017; not actively maintained.

## License

Released under the MIT License. See [LICENSE](LICENSE).
