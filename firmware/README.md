# Firmware Documentation

## 1. Introduction

The firmware is responsible for controlling the ESP32-based Smart Energy Monitoring System.

It acts as the central processing layer between the voltage and current sensing modules, the local LCD display and the Firebase cloud platform.

The firmware acquires sensor signals, processes measurement data and manages the communication required to make monitoring information accessible to users.

## 2. Development Environment

| Parameter | Details |
|---|---|
| Microcontroller | ESP32 |
| Development Environment | Arduino IDE |
| Programming Language | Embedded C++ |
| Voltage Sensor | ZMPT101B |
| Current Sensor | ACS712 5A |
| Local Display | 16×2 I2C LCD |
| Cloud Platform | Firebase Realtime Database |
| Communication | Wi-Fi |

## 3. Firmware Responsibilities

The firmware is designed to handle the following operations:

1. Initialize the ESP32 and connected peripherals.
2. Acquire analog signals from the voltage and current sensors.
3. Process the acquired signals.
4. Calculate relevant electrical parameters.
5. Update the LCD with monitoring information.
6. Establish Wi-Fi connectivity.
7. Communicate monitoring data with Firebase.

The exact implementation and execution sequence will be documented using the final firmware source code.

## 4. Firmware Directory Structure

```text
firmware/
├── README.md
├── libraries.md
├── configuration-example.h
└── energy-monitor/
    └── energy-monitor.ino
```

## 5. Configuration and Credentials

Configuration parameters and authentication details must be handled separately from publicly shared source code.

The repository must not contain:

- Wi-Fi passwords.
- Firebase authentication tokens.
- Private API keys.
- Other confidential credentials.

A configuration example containing placeholder values may be provided to explain the required settings without exposing actual credentials.

## 6. Firmware Verification

The firmware should be evaluated for:

- Correct sensor initialization.
- Reliable analog signal acquisition.
- Measurement calculation consistency.
- LCD display operation.
- Wi-Fi connectivity.
- Firebase data communication.
- Handling of communication interruptions.
- Stable operation over extended periods.

Actual test observations and results will be documented separately.

## 7. Source Code

The main firmware implementation will be maintained in:

`energy-monitor/energy-monitor.ino`

The source file will be added after reviewing the final working version to ensure that the published implementation reflects the actual prototype.

## 8. Conclusion

The ESP32 firmware forms the processing and communication foundation of the Smart Energy Monitoring System.

Maintaining the source code, configuration examples, library requirements and verification records will make the implementation easier to understand, reproduce and improve.
