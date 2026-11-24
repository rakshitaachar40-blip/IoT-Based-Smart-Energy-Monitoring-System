# Firmware Documentation

## 1. Introduction

The firmware is responsible for controlling the ESP32-based Smart Energy Monitoring System.

It acts as the processing and communication layer between the voltage and current sensing modules, the local LCD display and the Firebase cloud platform.

The firmware processes electrical measurements, calculates energy consumption and estimated electricity costs, updates the LCD and transmits monitoring data to Firebase Realtime Database.

## 2. Development Environment

| Parameter | Details |
|---|---|
| Microcontroller | ESP32 |
| Development Environment | Arduino IDE |
| Programming Language | Embedded C++ |
| Voltage Sensor | ZMPT101B |
| Current Sensor | ACS712 (5A) |
| Local Display | 16×2 I2C LCD |
| Cloud Platform | Firebase Realtime Database |
| Communication | Wi-Fi |

## 3. Firmware Responsibilities

The firmware handles the following operations:

1. Initialize the ESP32 and connected peripherals.
2. Configure voltage and current measurement channels.
3. Process electrical measurement signals using EmonLib.
4. Calculate voltage, real power and derived current values.
5. Accumulate energy consumption in kWh.
6. Estimate electricity costs using configurable slab rates.
7. Store accumulated energy and bill values using EEPROM emulation.
8. Display electrical measurements and calculated values on the LCD.
9. Establish Wi-Fi connectivity.
10. Transmit monitoring data to Firebase Realtime Database.

## 4. Firmware Directory Structure

The current repository structure is:

```text
firmware/
├── README.md
├── libraries.md
├── configuration-example.h
└── firmware/
    └── energy-monitor/
        └── energy-monitor.ino
```

The main firmware source file is:

`firmware/firmware/energy-monitor/energy-monitor.ino`

## 5. Configuration and Credentials

The firmware uses a separate configuration file to keep sensitive credentials out of the publicly shared source code.

The main firmware includes:

```cpp
#include "configuration.h"
```

The configuration file must define the following parameters:

- `WIFI_SSID`
- `WIFI_PASSWORD`
- `FIREBASE_HOST`
- `FIREBASE_AUTH`

### Creating the Configuration File

1. Locate `configuration-example.h` in the repository's `firmware/` directory.
2. Copy this file into the `firmware/firmware/energy-monitor/` directory.
3. Rename the copied file to `configuration.h`.
4. Replace the placeholder values with your actual Wi-Fi and Firebase credentials.

The resulting local directory should contain:

```text
energy-monitor/
├── energy-monitor.ino
└── configuration.h
```

**Important:** The actual `configuration.h` file must remain private and must not be uploaded to GitHub. The repository's `.gitignore` excludes this filename.

The publicly available `configuration-example.h` contains placeholders for reference.

## 6. Required Libraries

The firmware requires the following libraries:

- EmonLib
- Firebase ESP Client
- LiquidCrystal_I2C
- EEPROM
- WiFi
- Wire

Installation details and library descriptions are available in [`libraries.md`](libraries.md).

EEPROM, WiFi and Wire are provided through the ESP32 Arduino core.

## 7. Running the Firmware

### Prerequisites

Before uploading the firmware, ensure that:

- Arduino IDE is installed.
- ESP32 board support is installed in Arduino IDE.
- The required libraries are installed.
- The private `configuration.h` file has been created locally.
- The hardware connections are completed.

### Upload Procedure

1. Open Arduino IDE.
2. Open `energy-monitor.ino` from the firmware directory.
3. Connect the ESP32 to the computer using a USB cable.
4. Select the appropriate ESP32 board under **Tools → Board**.
5. Select the corresponding serial port under **Tools → Port**.
6. Verify that the required libraries and configuration file are available.
7. Compile the firmware.
8. Upload the compiled firmware to the ESP32.

After uploading, the ESP32 attempts to connect to the configured Wi-Fi network and initialize Firebase communication.

## 8. Firebase Data Structure

The firmware publishes monitoring information to the following Firebase Realtime Database paths:

| Parameter | Database Path |
|---|---|
| Voltage | `/energyMeter/voltage` |
| Current | `/energyMeter/current` |
| Real Power | `/energyMeter/power` |
| Energy Consumption | `/energyMeter/energy` |
| Estimated Bill | `/energyMeter/bill` |

These values support remote monitoring through the connected application.

## 9. Firmware Verification

The firmware should be evaluated for:

- Correct sensor initialization.
- Measurement calculation consistency.
- LCD display operation.
- Wi-Fi connectivity.
- Firebase data communication.
- EEPROM data storage and retrieval.
- Stable operation over extended periods.

Actual test observations and results should be documented separately.

The published source code represents the documented firmware implementation. Compilation and hardware verification should be performed in the target development environment before deployment.

## 10. Source Code Maintenance

The firmware source code is maintained in:

`firmware/firmware/energy-monitor/energy-monitor.ino`

The repository also provides:

- `libraries.md` – Library and dependency documentation.
- `configuration-example.h` – Public configuration template.
- `.gitignore` – Excludes private configuration files.

Future firmware improvements and modifications should be documented alongside the corresponding source code updates.

## 11. Conclusion

The ESP32 firmware forms the processing and communication foundation of the Smart Energy Monitoring System.

Maintaining the firmware source, configuration examples, library requirements and verification records makes the implementation easier to understand, reproduce and improve.
