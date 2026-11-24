# Project Objectives and System Requirements

## 1. Project Objectives

The primary objective is to develop an IoT-based Smart Energy Monitoring System capable of monitoring electrical parameters and providing accessible energy consumption information.

The specific objectives are:

1. To develop an ESP32-based embedded monitoring system.
2. To interface voltage and current sensors with the microcontroller.
3. To acquire and process electrical measurements.
4. To calculate voltage, current, power and energy consumption.
5. To monitor power factor.
6. To estimate electricity expenses using configurable tariff values.
7. To display electrical measurements through a 16×2 I2C LCD.
8. To integrate Firebase for cloud-based data communication.
9. To provide remote monitoring through a mobile application.
10. To develop a custom PCB for hardware integration.
11. To improve measurement reliability through sensor calibration and testing.
12. To refine the prototype based on testing observations and stakeholder feedback.

## 2. Functional Requirements

Functional requirements describe the operations the system is expected to perform.

| ID | Requirement | Description |
|---|---|---|
| FR01 | Voltage Measurement | Acquire voltage measurements using the ZMPT101B sensor. |
| FR02 | Current Measurement | Acquire current measurements using the ACS712 sensor. |
| FR03 | Parameter Processing | Process sensor readings using the ESP32. |
| FR04 | Power Calculation | Determine electrical power consumption. |
| FR05 | Energy Calculation | Calculate accumulated energy consumption in kWh. |
| FR06 | Power Factor | Determine the power factor of the monitored load. |
| FR07 | Cost Estimation | Estimate electricity expenses using configured tariff values. |
| FR08 | Local Display | Display monitored parameters on a 16×2 I2C LCD. |
| FR09 | Cloud Communication | Transfer monitoring data to Firebase. |
| FR10 | Mobile Monitoring | Make monitoring information accessible through the mobile application. |

*The implementation status of each requirement will be recorded after firmware and integration testing.*

## 3. Non-Functional Requirements

Non-functional requirements describe the expected quality and operational characteristics of the system.

### 3.1 Measurement Reliability
The system should provide consistent electrical measurements after appropriate sensor calibration.

### 3.2 Data Accessibility
Users should be able to access the monitored information through the local display and mobile application.

### 3.3 Responsiveness
The monitoring system should update measurements and communicate data with minimal unnecessary delay.

### 3.4 Maintainability
The firmware and software components should be organized to support debugging, modification and future development.

### 3.5 Hardware Integration
The sensing modules, microcontroller, display and supporting circuitry should operate as an integrated system.

### 3.6 Safety
The hardware implementation should incorporate suitable electrical isolation and protection measures for safe operation.

### 3.7 Expandability
The architecture should allow future enhancements to monitoring, visualization and energy analysis.

## 4. Hardware Requirements

| Component | Specification / Role |
|---|---|
| ESP32 | Main processing and wireless communication unit |
| ZMPT101B | AC voltage sensing |
| ACS712 | Current sensing, 5A module |
| 16×2 LCD | Local display |
| I2C Interface | LCD communication |
| Power Supply | Powering the electronic circuitry |
| Custom PCB | Component integration |

## 5. Software Requirements

| Software / Platform | Purpose |
|---|---|
| Arduino IDE | Firmware development |
| Embedded C/C++ | ESP32 programming |
| Firebase Realtime Database | Cloud data communication |
| MIT App Inventor | Mobile application development |

## 6. Project Constraints

The development is subject to the following considerations:

- Sensor accuracy depends on appropriate calibration.
- Measurement reliability depends on the sensing circuitry and signal processing.
- Cloud communication depends on network availability.
- Electricity cost estimation depends on the configured tariff structure.
- Hardware implementation requires appropriate electrical safety measures.
- Actual performance must be established through testing and validation.

## 7. Requirement Verification

Each requirement will be evaluated through suitable testing procedures.

The verification records will include:

- Sensor measurement observations.
- Comparison with reference measuring instruments.
- Calculation verification.
- LCD display verification.
- Firebase communication testing.
- Mobile application integration testing.
- Overall system operation.

Detailed verification results will be maintained in the `testing/` directory.
