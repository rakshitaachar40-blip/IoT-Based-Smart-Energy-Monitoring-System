# IoT-Based Smart Energy Monitoring System

An ESP32-based IoT system for monitoring electrical energy consumption, displaying measurements locally, estimating electricity costs, and making monitoring data accessible through Firebase and a mobile application.

## 1. Project Overview

The IoT-Based Smart Energy Monitoring System is an academic engineering project developed to improve the accessibility of household energy consumption information.

The system integrates voltage and current sensing modules with an ESP32 microcontroller. The firmware processes electrical measurements, calculates energy consumption and an estimated electricity cost, displays selected values on a 16×2 I2C LCD, and transmits monitoring data to Firebase Realtime Database over Wi-Fi.

The project also includes hardware refinement, sensor calibration, custom PCB development, enclosure work, and mobile application integration.

## 2. Objectives

- Develop an ESP32-based energy monitoring prototype.
- Interface voltage and current sensing modules with the microcontroller.
- Acquire and process electrical measurements.
- Calculate electrical power and accumulated energy consumption.
- Estimate electricity expenses using configured tariff values.
- Display monitoring information through a local LCD.
- Enable remote data access through Firebase.
- Provide a mobile application interface for monitoring.
- Improve hardware integration through PCB and enclosure development.
- Evaluate measurement behaviour through calibration and testing.

## 3. Implemented Features

The current firmware supports the following functions:

- Voltage measurement using the ZMPT101B sensor and EmonLib.
- Real-power calculation using EmonLib.
- A current value derived from real power and voltage.
- Energy accumulation in kWh.
- Estimated electricity cost using configured slab rates.
- Local display of voltage, current, power, energy, and estimated bill.
- LCD display-page switching using a button.
- Wi-Fi connectivity for Firebase communication.
- Upload of monitoring values to Firebase Realtime Database.
- Persistent storage of accumulated energy and bill values using ESP32 EEPROM emulation.
- Smoothing of selected measurements in the firmware.

**Power factor is not currently calculated, displayed, or uploaded by the published firmware.** It is not listed as an implemented feature.

## 4. Hardware Components

| Component | Function |
|---|---|
| ESP32 Development Board | Main controller and Wi-Fi communication |
| ZMPT101B Voltage Sensor | AC voltage sensing |
| ACS712 5A Current Sensor | Current sensing |
| 16×2 LCD with I2C | Local display |
| Power Supply Circuit | Supplies the electronic system |
| Custom PCB | Hardware integration |
| Enclosure | Houses the assembled electronics |
| Connecting Wires and Connectors | Electrical interconnections |

Refer to the [Hardware Components List](hardware/components-list.md) and [Hardware Design](docs/hardware-design.md) for further details.

## 5. Software and Technologies

| Technology | Application |
|---|---|
| Arduino IDE | Firmware development and uploading |
| Embedded C/C++ | ESP32 programming |
| ESP32 Arduino Core | Microcontroller support |
| EmonLib | Voltage and real-power measurement |
| Firebase ESP Client | Firebase communication |
| Firebase Realtime Database | Cloud data access |
| LiquidCrystal_I2C | LCD interfacing |
| EEPROM | Persistent storage |
| Wi-Fi | Wireless communication |
| I2C | LCD communication |
| MIT App Inventor | Mobile application development |

Library details are available in [Firmware Libraries and Dependencies](firmware/libraries.md).

## 6. System Architecture

The system follows the data flow below:

```text
       AC Electrical Supply
                 |
       +---------+---------+
       |                   |
  ZMPT101B Sensor     ACS712 Sensor
    (Voltage)           (Current)
       |                   |
       +---------+---------+
                 |
               ESP32
                 |
       +---------+---------+
       |                   |
    16×2 LCD             Wi-Fi
                           |
                    Firebase RTDB
                           |
                   Mobile Application
```

The ESP32 acts as the central processing and communication unit. The LCD provides local monitoring, while Firebase enables remote access to the available readings.

See [System Architecture](docs/system-architecture.md).

## 7. Working Principle

1. The ZMPT101B and ACS712 modules provide electrical sensing signals.
2. The ESP32 acquires and processes the sensor readings.
3. EmonLib calculates voltage and real power.
4. The firmware derives the current value from real power and voltage.
5. The firmware accumulates energy using elapsed time and measured power.
6. The estimated bill is calculated using the configured tariff slabs.
7. Selected values are displayed on the LCD.
8. The ESP32 connects to Wi-Fi and sends the monitoring values to Firebase.
9. The mobile application accesses the data available through Firebase.

The monitoring cycle repeats during normal operation.

See [Working Principle](docs/working-principle.md) for the detailed explanation.

## 8. Firebase Integration

Firebase Realtime Database is used as the cloud data layer between the ESP32 firmware and the mobile application.

The firmware writes the following values under the `/energyMeter/` node:

| Parameter | Firebase Database Path |
|---|---|
| Voltage | `/energyMeter/voltage` |
| Current | `/energyMeter/current` |
| Real Power | `/energyMeter/power` |
| Energy Consumption | `/energyMeter/energy` |
| Estimated Bill | `/energyMeter/bill` |

The firmware updates these values when Firebase is ready. The application can retrieve the available values from the same database paths.

The current implementation updates the latest values; it does not provide a separate historical logging or graphing system in this repository.

Firebase configuration is stored in a private `configuration.h` file. Never publish Wi-Fi passwords, Firebase authentication tokens, or private database credentials.

## 9. Mobile Application

The mobile application was developed using **MIT App Inventor** to provide a user interface for remotely viewing energy monitoring information.

The application uses Firebase Realtime Database to access the values uploaded by the ESP32.

The public repository currently documents the application integration but does not include a standalone MIT App Inventor project file (`.aia`) or APK. No public application download link is provided here.

## 10. Firmware Setup and Upload

### Prerequisites

- Arduino IDE installed.
- ESP32 board support installed in Arduino IDE.
- Required firmware libraries installed.
- ESP32 board and hardware connections available.
- A private `configuration.h` file created locally.

### Install the Required Libraries

Install the external libraries listed in:

- [Firmware Libraries and Dependencies](firmware/libraries.md)

The ESP32 Arduino Core provides the built-in `WiFi`, `Wire`, and `EEPROM` libraries.

### Configure the Firmware

1. Open `firmware/configuration-example.h`.
2. Copy the file into the same folder as the main `.ino` file:
   `firmware/firmware/energy-monitor/`
3. Rename the copied file to `configuration.h`.
4. Replace the placeholder values with your own Wi-Fi and Firebase configuration.

The private file must define:

```cpp
#define WIFI_SSID "YOUR_WIFI_NAME"
#define WIFI_PASSWORD "YOUR_WIFI_PASSWORD"

#define FIREBASE_HOST "YOUR_FIREBASE_DATABASE_HOST"
#define FIREBASE_AUTH "YOUR_FIREBASE_AUTH_TOKEN"
```

The actual values must remain private. The repository's `.gitignore` excludes `configuration.h`.

### Upload the Firmware

1. Open Arduino IDE.
2. Open the firmware file:

   `firmware/firmware/energy-monitor/energy-monitor.ino`

3. Connect the ESP32 to your computer using USB.
4. Select the appropriate ESP32 board under **Tools → Board**.
5. Select the correct serial port under **Tools → Port**.
6. Confirm that the required libraries and private configuration file are available.
7. Verify and compile the sketch.
8. Upload the firmware to the ESP32.

After uploading, the ESP32 attempts to connect to the configured Wi-Fi network and initialize Firebase communication.

## 11. Firmware and Hardware Documentation

The repository contains the following documentation:

- [Project Overview](docs/project-overview.md)
- [Problem Statement](docs/problem-statement.md)
- [Objectives and Requirements](docs/objectives-and-requirements.md)
- [System Architecture](docs/system-architecture.md)
- [Working Principle](docs/working-principle.md)
- [Hardware Design](docs/hardware-design.md)
- [Software Design](docs/software-design.md)
- [Mathematical Calculations](docs/mathematical-calculations.md)
- [Calibration and Testing](docs/calibration-and-testing.md)
- [Safety and Protection](docs/safety-and-protection.md)
- [Product Development Journey](docs/product-development.md)
- [Future Enhancements](docs/future-enhancements.md)
- [Firmware Documentation](firmware/README.md)
- [Hardware Components List](hardware/components-list.md)

## 12. Repository Structure

```text
IoT-Based-Smart-Energy-Monitoring-System/
│
├── README.md
├── LICENSE
├── .gitignore
│
├── docs/
│   ├── project-overview.md
│   ├── problem-statement.md
│   ├── objectives-and-requirements.md
│   ├── system-architecture.md
│   ├── working-principle.md
│   ├── hardware-design.md
│   ├── software-design.md
│   ├── mathematical-calculations.md
│   ├── calibration-and-testing.md
│   ├── safety-and-protection.md
│   ├── product-development.md
│   └── future-enhancements.md
│
├── hardware/
│   ├── components-list.md
│   ├── circuit-diagram/
│   ├── pcb-design/
│   └── enclosure/
│
└── firmware/
    ├── README.md
    ├── libraries.md
    ├── configuration-example.h
    └── firmware/
        └── energy-monitor/
            └── energy-monitor.ino
```

## 13. Limitations

The current prototype has the following limitations:

- Power factor is not implemented in the published firmware.
- The current value reported by the firmware is derived from real power and voltage; it is not separately reported as an independent RMS-current measurement.
- Measurement accuracy depends on sensor calibration, ADC characteristics, and the test conditions.
- The electricity cost is a prototype estimate based on hard-coded slab rates. It is not an official utility bill or a complete billing-period calculation.
- Firebase currently stores the latest monitoring values at fixed database paths; historical analytics and trend graphs are not implemented in the firmware.
- The mobile application source project and APK are not included in the public repository.
- Further electrical safety and long-duration validation are required before permanent or commercial deployment.

## 14. Future Scope

Possible future improvements include:

- More systematic sensor calibration and accuracy evaluation.
- Power factor calculation and validation.
- Historical energy data storage and visualization.
- Daily, monthly, and yearly consumption summaries.
- Improved mobile application dashboards.
- Configurable energy usage alerts.
- More accurate tariff and billing-period calculations.
- Enhanced communication reliability.
- Further PCB and enclosure optimization.
- Additional electrical safety and protection evaluation.

See [Future Enhancements](docs/future-enhancements.md).

## 15. Safety Disclaimer

This project involves electrical measurements. AC mains connections can cause electric shock, burns, fire, or serious injury.

Hardware assembly, testing, and installation must be carried out using suitable isolation, protection, and supervision by qualified individuals. Never handle exposed live connections.

A sensor module or custom PCB alone does not establish that the complete system is electrically safe.

## 16. Achievements and Recognition

- Selected among the Top 17 projects at IASF 2026 and ICTIEE 2026 at GITAM Bengaluru.
- Presented at PUPA 2026 – Make in BVB.
- Participated in stakeholder interactions and product feedback activities.
- Continued hardware and software refinement during product development.

## 17. Project Credits

**Project Team:** Team 08  
**Institution:** KLE Technological University, Hubballi

Developed as an academic engineering and IoT product development project.

## 18. License

This repository is distributed under the MIT License. See [LICENSE](LICENSE) for details.
