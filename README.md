# IoT-Based Smart Energy Monitoring System

An ESP32-based IoT solution for monitoring electrical energy consumption in real time, estimating electricity costs and providing users with accessible energy usage information through cloud connectivity and a mobile application.

---

## 1. Project Overview

The **Smart Energy Monitoring System** is an IoT-based electrical energy monitoring solution developed to make household energy consumption more visible, understandable and manageable.

The system uses voltage and current sensors interfaced with an ESP32 microcontroller to acquire electrical parameters. The acquired data is processed to determine important energy-related measurements, which are displayed locally on an LCD and made accessible remotely through Firebase and a mobile application.

The project also explores product development through hardware refinement, sensor calibration, PCB design, software integration and stakeholder feedback.

## 2. Problem Statement

Conventional electricity meters primarily provide cumulative energy consumption readings. Users may not have convenient access to detailed, real-time information about their electrical usage.

This makes it difficult to:
- Understand instantaneous power consumption.
- Identify changes in electrical usage patterns.
- Monitor energy consumption remotely.
- Estimate electricity expenses during the billing period.
- Make informed decisions about energy usage.

The project addresses these limitations through an IoT-enabled monitoring platform that provides real-time electrical measurements and accessible energy consumption information.

## 3. Project Objectives

- Develop an ESP32-based energy monitoring system.
- Measure voltage and current using dedicated sensors.
- Calculate electrical parameters such as power and energy consumption.
- Estimate electricity costs based on configurable tariff values.
- Display measurements through a 16×2 I2C LCD.
- Integrate Firebase for cloud-based data communication.
- Develop a mobile application for remote monitoring.
- Design and refine a custom PCB.
- Improve reliability through sensor calibration and testing.

## 4. Key Features

- Real-time voltage monitoring.
- Real-time current monitoring.
- Electrical power measurement.
- Energy consumption monitoring in kWh.
- Estimated electricity bill calculation.
- Local LCD-based display.
- Firebase cloud integration.
- Mobile application dashboard.
- Custom PCB development.
- Hardware and software integration.

## 5. System Architecture

The system consists of four major stages:

1. **Sensing:** Voltage and current sensors acquire electrical measurements.
2. **Processing:** The ESP32 processes sensor readings and calculates electrical parameters.
3. **Display and communication:** Measurements are displayed locally and transmitted to Firebase.
4. **User interface:** The mobile application provides access to the monitored information.

### System Block Diagram

```text
       AC Electrical Supply
                |
        +-------+-------+
        |               |
   Voltage Sensor   Current Sensor
    (ZMPT101B)        (ACS712)
        |               |
        +-------+-------+
                |
              ESP32
                |
       +--------+--------+
       |                 |
   16x2 LCD          Wi-Fi
                         |
                      Firebase
                         |
                  Mobile Application
```

## 6. Hardware Components

| Component | Purpose |
|---|---|
| ESP32 | Main microcontroller and Wi-Fi connectivity |
| ZMPT101B | Voltage sensing |
| ACS712 (5A) | Current sensing |
| 16×2 I2C LCD | Local parameter display |
| Power supply circuitry | Power management |
| Custom PCB | Hardware integration |
| Enclosure | Physical protection and product assembly |

*Component specifications and final circuit connections will be documented in the hardware section.*

## 7. Software and Technologies

| Technology | Application |
|---|---|
| Arduino IDE | Firmware development |
| Embedded C/C++ | Microcontroller programming |
| ESP32 | Data acquisition and processing |
| Firebase Realtime Database | Cloud data integration |
| MIT App Inventor | Mobile application development |
| I2C Communication | LCD interfacing |

## 8. Electrical Parameters

The system is designed to monitor and calculate the following parameters:

| Parameter | Description | Unit |
|---|---|---|
| Voltage | Electrical potential difference | V |
| Current | Electrical current consumption | A |
| Power | Electrical power consumption | W |
| Energy | Accumulated electrical energy | kWh |
| Estimated Bill | Calculated electricity cost | INR (₹) |

The calculation methods, assumptions and calibration procedures will be documented separately.

## 9. Development Journey

The project was developed through multiple stages of engineering and product refinement.

### Phase 1 — Problem Identification
Identified the need for accessible, real-time household energy monitoring.

### Phase 2 — System Design
Defined the system architecture and selected the microcontroller, sensors and display components.

### Phase 3 — Hardware Development
Integrated the ESP32 with the voltage and current sensing modules and developed the hardware prototype.

### Phase 4 — Firmware Development
Developed the embedded software for sensor acquisition, parameter calculations and system operation.

### Phase 5 — Cloud and Mobile Integration
Integrated Firebase and developed a mobile application dashboard for remote access to energy monitoring information.

### Phase 6 — Calibration and Testing
Worked on sensor calibration, measurement reliability and hardware-software integration.

### Phase 7 — PCB and Product Refinement
Developed a custom PCB, refined the hardware implementation and improved the overall product design.

### Phase 8 — Product Validation and Stakeholder Interaction
Presented the prototype at PUPA 2026 – Make in BVB, interacted with potential users and stakeholders, gathered feedback and explored further product improvements.

Detailed records of each phase will be maintained in the `docs/`, `hardware/`, `firmware/`, `software/` and `testing/` directories.

## 10. Achievements and Recognition

- Selected among the Top 17 projects at IASF 2026 and ICTIEE 2026 at GITAM Bengaluru.
- Presented the project at PUPA 2026 – Make in BVB.
- Participated in stakeholder interactions involving potential users, mentors, entrepreneurs and industry representatives.
- Continued hardware and software refinement based on feedback received during product interactions.

## 11. Repository Structure

```text
## 11. Repository Structure

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

## 12. Future Enhancements

Potential areas for further development include:

- Improved measurement accuracy and calibration.
- Enhanced electrical safety and protection.
- Historical energy consumption analysis.
- Usage trends and graphical visualizations.
- Improved mobile application experience.
- Appliance-level energy monitoring.
- Advanced energy consumption analytics.
- Further PCB and enclosure optimization.

## 13. Safety Disclaimer

This project involves electrical measurements. Working with mains electricity can cause serious injury, electric shock or fire.

All hardware development, testing and installation must be carried out with appropriate isolation, protection and supervision by qualified individuals. Never handle exposed live connections.

## 14. Contributors

**Project Team:** Team 08

Contributors and individual responsibilities will be documented here.

---

## Project Status

**Development Stage:** Prototype and product refinement.

This repository documents the engineering development, implementation, testing and product refinement of the Smart Energy Monitoring System.

---

*Developed as an academic engineering and IoT product development project.*
