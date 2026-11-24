# System Architecture

## 1. Introduction

The Smart Energy Monitoring System follows an IoT-based architecture consisting of sensing, embedded processing, data communication, cloud integration and user-interface layers.

The architecture integrates electrical sensing modules with an ESP32 microcontroller to acquire and process electrical measurements. The processed information is made available through a local LCD and a cloud-connected mobile monitoring interface.

## 2. Architecture Overview

The system is divided into five functional layers:

1. Sensing Layer
2. Embedded Processing Layer
3. Local Display Layer
4. Communication and Cloud Layer
5. Application Layer

### 2.1 Sensing Layer

The sensing layer acquires electrical parameters from the monitored electrical supply.

It consists of:

- **ZMPT101B Voltage Sensor:** Used for AC voltage measurement.
- **ACS712 Current Sensor:** Used for current measurement.

The sensor outputs are interfaced with the ESP32 for further processing.

### 2.2 Embedded Processing Layer

The ESP32 acts as the central processing unit of the system.

Its responsibilities include:

- Reading sensor signals.
- Processing the acquired measurements.
- Calculating electrical parameters.
- Preparing measurement data for display.
- Managing wireless communication with Firebase.

The accuracy of the calculated parameters depends on the sensor calibration and firmware implementation.

### 2.3 Local Display Layer

A 16×2 LCD with an I2C interface provides local access to the monitored information.

The display is used to present selected electrical parameters without requiring access to the mobile application.

### 2.4 Communication and Cloud Layer

The ESP32 uses its Wi-Fi connectivity to communicate with Firebase Realtime Database.

This layer enables the transfer of monitoring information from the embedded system to the cloud platform.

Firebase acts as the cloud-based data integration layer between the ESP32 and the mobile application.

### 2.5 Application Layer

The mobile application, developed using MIT App Inventor, provides a user-facing interface for accessing the monitoring information.

It allows users to view the data made available through Firebase.

## 3. System Block Diagram

```text
                ELECTRICAL SUPPLY
                       |
              +--------+--------+
              |                 |
        ZMPT101B Sensor    ACS712 Sensor
          (Voltage)          (Current)
              |                 |
              +--------+--------+
                       |
                 ESP32 MCU
                       |
              Embedded Processing
                       |
             +---------+---------+
             |                   |
          16×2 LCD             Wi-Fi
                                   |
                            Firebase RTDB
                                   |
                            Mobile Application
```

## 4. System Data Flow

The overall data flow follows these stages:

**Stage 1 — Electrical Measurement**

The voltage and current sensors acquire signals corresponding to the electrical parameters of the monitored supply.

**Stage 2 — Signal Acquisition**

The sensor outputs are interfaced with the ESP32, which acquires the corresponding readings.

**Stage 3 — Data Processing**

The firmware processes the acquired measurements and calculates the required electrical parameters.

**Stage 4 — Local Visualization**

Selected measurement values are displayed on the 16×2 I2C LCD.

**Stage 5 — Cloud Communication**

The ESP32 transmits the monitoring data through Wi-Fi to Firebase Realtime Database.

**Stage 6 — Remote Monitoring**

The mobile application accesses the information made available through Firebase and presents it to the user.

## 5. Hardware Architecture

The hardware architecture consists of:

| Component | Interface / Connection | Function |
|---|---|---|
| ZMPT101B | ESP32 analog input | Voltage sensing |
| ACS712 | ESP32 analog input | Current sensing |
| 16×2 I2C LCD | I2C | Local display |
| ESP32 | Wi-Fi | Cloud communication |
| Power supply circuitry | Power connections | Supplies the electronic system |

*Exact GPIO assignments, supply voltages and circuit connections will be documented separately using the finalized circuit diagram.*

## 6. Software Architecture

The software architecture consists of three major components:

### 6.1 Embedded Firmware

The ESP32 firmware handles:

- Sensor initialization.
- Sensor data acquisition.
- Measurement processing.
- Electrical parameter calculations.
- LCD updates.
- Firebase communication.

### 6.2 Cloud Integration

Firebase Realtime Database provides cloud-based storage and communication for the monitoring data.

The database structure and communication implementation will be documented in the software section.

### 6.3 Mobile Application

The mobile application provides the user interface for accessing energy monitoring information through the cloud-connected system.

Its interface components and Firebase integration will be documented separately.

## 7. Architecture Design Considerations

The architecture was designed with the following considerations:

- Separation of sensing, processing and visualization functions.
- Integration of local and remote monitoring.
- Wireless data communication.
- Modular hardware and software development.
- Scope for future feature expansion.
- Maintainability and ease of testing.

## 8. Future Architectural Improvements

Potential improvements include:

- Historical energy consumption storage and visualization.
- Improved communication reliability.
- Advanced energy usage analytics.
- Additional monitoring channels.
- Enhanced data security.
- Modular support for additional sensors.

## 9. Summary

The system architecture integrates electrical sensing, embedded processing, local visualization and cloud-based monitoring into a unified IoT solution.

The ESP32 serves as the central controller, while Firebase and the mobile application provide remote accessibility to the monitored information.
