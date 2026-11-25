# Software Design

## 1. Introduction

The software architecture of the Smart Energy Monitoring System consists of embedded firmware, cloud-based data communication and a mobile application interface.

The ESP32 acts as the central controller, acquiring sensor readings, processing electrical measurements, updating the LCD and communicating with Firebase Realtime Database.

## 2. Software Architecture

The software is organized into three major subsystems:

1. Embedded firmware.
2. Cloud database integration.
3. Mobile application.

### 2.1 Embedded Firmware

The firmware runs on the ESP32 and is developed using the Arduino IDE.

Its primary responsibilities include:

- Initializing hardware peripherals.
- Acquiring voltage sensor readings.
- Acquiring current sensor readings.
- Processing sensor data.
- Calculating electrical parameters.
- Updating the LCD.
- Establishing Wi-Fi connectivity.
- Communicating with Firebase.

### 2.2 Cloud Database Integration

Firebase Realtime Database provides cloud-based data communication between the ESP32 and the mobile application.

The ESP32 transmits monitoring information to the configured database structure.

The database serves as the central point through which the mobile application accesses the available readings.


The firmware writes the latest voltage, current, power, energy and bill values to the following Firebase Realtime Database paths:

- `/energyMeter/voltage`
- `/energyMeter/current`
- `/energyMeter/power`
- `/energyMeter/energy`
- `/energyMeter/bill`

These paths are also documented in the Firebase Integration section of the root README.

### 2.3 Mobile Application

The mobile application was developed using MIT App Inventor.

Its purpose is to provide a user-friendly interface for accessing the monitoring information.

The application interacts with Firebase to retrieve the data made available by the ESP32.


The mobile application was developed using MIT App Inventor and accesses monitoring data through Firebase.

The public repository does not include the MIT App Inventor project file, so the exact application components and data bindings cannot be independently verified from the repository.
The MIT App Inventor project file (`.aia`) and APK are not included in this public repository.

## 3. Embedded Firmware Workflow

The firmware follows the general workflow below.

### Stage 1 — Initialization

- Initialize serial communication.
- Configure sensor input pins.
- Initialize the LCD.
- Establish Wi-Fi connectivity.
- Initialize Firebase communication.

### Stage 2 — Sensor Data Acquisition

- Read voltage sensor signals.
- Read current sensor signals.
- Acquire the required ADC samples.

### Stage 3 — Signal Processing

- Process the acquired sensor signals.
- Account for sensor offsets.
- Apply calibration parameters.
- Determine the required electrical measurements.

### Stage 4 — Parameter Calculation

Calculate the required parameters using the implemented algorithms:

- RMS voltage calculated using EmonLib.
- Real power calculated using EmonLib.
- Current value derived from real power divided by voltage.
- Accumulated energy calculated using smoothed real power and elapsed time.
- Estimated electricity cost calculated using the configured slab rates.

### Stage 5 — Local Display

Update the LCD with the selected measurement values.

### Stage 6 — Cloud Communication

Prepare the processed data and transmit it to Firebase using Wi-Fi.

### Stage 7 — Continuous Operation

Repeat the monitoring and communication process during normal system operation.

## 4. Firmware Development Environment

| Tool / Technology | Purpose |
|---|---|
| Arduino IDE | Firmware development and uploading |
| Embedded C/C++ | Application programming |
| ESP32 Arduino Core | Microcontroller development support |
| Wi-Fi | Wireless communication |
| I2C | LCD communication |
| Firebase integration library | Cloud database communication |

The exact library names and versions will be recorded after inspecting the final firmware.

## 5. Communication Interfaces

### 5.1 Analog Interface

The ZMPT101B and ACS712 modules provide analog outputs that are acquired through ESP32 ADC inputs.

### 5.2 I2C Interface

The LCD uses I2C communication for transferring display data between the ESP32 and LCD module.

### 5.3 Wi-Fi Interface

The ESP32 uses its integrated Wi-Fi capability to connect to the network and communicate with Firebase.

### 5.4 Firebase Interface

The firmware communicates with Firebase Realtime Database to make the monitoring data available remotely.

## 6. Cloud Data Flow

The cloud communication process follows this sequence:

1. ESP32 processes sensor readings.
2. Firmware prepares the measurement data.
3. ESP32 connects to the configured Wi-Fi network.
4. Data is transmitted to Firebase Realtime Database.
5. Firebase makes the available data accessible to the mobile application.
6. The mobile application presents the retrieved information.

## 7. Mobile Application Workflow

The mobile application provides the user interface for remote monitoring.

Its general workflow is:

1. Establish access to the configured Firebase database.
2. Retrieve available monitoring data.
3. Interpret the received values.
4. Display the parameters through the application dashboard.

The public repository does not include the MIT App Inventor project file, so the exact application components and data bindings cannot be independently verified from the repository.

## 8. Software Integration Considerations

The following aspects are important for reliable operation:

- Consistent data types between firmware and database.
- Matching Firebase paths and field names.
- Handling Wi-Fi disconnections.
- Handling unsuccessful database updates.
- Maintaining compatibility with the existing mobile application.
- Avoiding unnecessary database writes.
- Protecting authentication credentials.
- Ensuring that measurement calculations use correctly calibrated values.

## 9. Configuration and Credential Management

Sensitive configuration information must not be committed to a public repository.

This includes:

- Wi-Fi SSIDs and passwords.
- Firebase authentication credentials.
- Database access tokens.
- Private configuration files.

A sample configuration file containing placeholder values may be provided for developers.

Actual credentials must remain outside version control.

## 10. Software Verification

Software testing should cover:

- Sensor acquisition.
- Measurement calculations.
- LCD updates.
- Wi-Fi connection.
- Firebase communication.
- Mobile application data retrieval.
- Handling of communication failures.
- Overall system operation.

Refer to `docs/calibration-and-testing.md` for the testing information documented in this repository.

## 11. Summary

The software architecture integrates embedded processing, cloud communication and mobile application functionality.

The ESP32 coordinates the monitoring operations, while Firebase provides cloud-based data access and the mobile application acts as the remote user interface.
