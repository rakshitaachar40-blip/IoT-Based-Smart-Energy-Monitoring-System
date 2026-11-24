# Hardware Components List

## 1. Introduction

This document lists the major hardware components used in the development of the IoT Smart Energy Monitoring System.

The system uses voltage and current sensing modules connected to an ESP32 microcontroller. The acquired measurements are processed and made available through a local LCD display and a cloud-connected mobile application.

## 2. Component List

| Sl. No. | Component | Quantity | Purpose |
|---|---|---:|---|
| 1 | ESP32 Development Board | 1 | Main microcontroller for sensor acquisition, data processing and communication |
| 2 | ZMPT101B Voltage Sensor Module | 1 | Measures the AC voltage signal |
| 3 | ACS712 5A Current Sensor Module | 1 | Measures current flowing through the monitored circuit |
| 4 | 16×2 LCD with I2C Interface | 1 | Displays electrical measurements locally |
| 5 | Power Supply Circuit | As required | Provides the required supply to the system |
| 6 | Custom PCB | 1 | Integrates and organizes the electronic circuitry |
| 7 | Enclosure | 1 | Houses and protects the assembled hardware |
| 8 | Connecting Wires and Connectors | As required | Provides electrical interconnections |

*Quantities refer to the primary prototype configuration. Additional components may be used during assembly and testing.*

## 3. Main Component Details

### 3.1 ESP32 Development Board

**Role:** Main processing and communication unit.

The ESP32 acts as the central controller of the system. It receives sensor signals, processes measurement data and manages communication with the cloud platform.

Primary responsibilities:

- Acquiring voltage and current sensor signals.
- Processing electrical measurements.
- Calculating relevant energy parameters.
- Updating the LCD display.
- Communicating with Firebase over Wi-Fi.

The exact ESP32 board variant should be recorded after confirming the development board used in the final prototype.

### 3.2 ZMPT101B Voltage Sensor Module

**Role:** AC voltage sensing.

The ZMPT101B module is used to obtain a scaled signal corresponding to the monitored AC voltage.

Its output is interfaced with the ESP32 for signal acquisition and processing.

The module requires suitable calibration before its readings can be used for measurement calculations.

### 3.3 ACS712 5A Current Sensor Module

**Role:** Current sensing.

The ACS712 5A module is used to measure current in the monitored electrical circuit.

The sensor produces an analog output corresponding to the current flowing through its internal current path.

The output is acquired by the ESP32 and processed to estimate the current value.

Appropriate calibration and verification are required for reliable measurements.

### 3.4 16×2 LCD with I2C Interface

**Role:** Local display.

A 16×2 character LCD with an I2C interface is used to display the monitoring information locally.

The I2C interface reduces the number of GPIO connections required compared with a parallel LCD interface.

The LCD module used in the prototype has the I2C address `0x27`.

### 3.5 Power Supply Circuit

**Role:** Power distribution.

The power supply circuitry provides the required operating supply to the electronic components.

The exact supply topology, voltage ratings and protection components should be documented from the final circuit design.

### 3.6 Custom PCB

**Role:** Hardware integration.

A custom PCB was developed to organize the electronic components and their interconnections.

It supports a more integrated hardware arrangement compared with a loosely wired prototype.

### 3.7 Enclosure

**Role:** Physical housing.

An enclosure was developed to house the electronic assembly and improve the physical organization of the prototype.

Its final material, dimensions and electrical safety characteristics should be documented separately after verification.

## 4. Hardware Integration

The major hardware components are integrated as follows:

1. The voltage and current sensing modules acquire the electrical signals.
2. Their outputs are connected to the ESP32 for analog signal acquisition.
3. The ESP32 processes the acquired measurements.
4. The LCD displays the monitoring information locally.
5. The ESP32 communicates with Firebase through Wi-Fi.
6. The mobile application accesses the information made available through the cloud platform.

## 5. Specifications to Verify

The following details should be confirmed from the actual hardware before this repository is treated as a complete component specification.

| Component | Details to Verify |
|---|---|
| ESP32 | Exact development board variant |
| ZMPT101B | Module supply voltage, output range and calibration configuration |
| ACS712 | Exact module variant, sensitivity and supply voltage |
| LCD | I2C address and operating voltage |
| Power supply | Input/output ratings and protection arrangement |
| PCB | Board dimensions, material and design files |
| Enclosure | Material, dimensions and construction details |

## 6. Safety Note

The project involves monitoring AC electrical parameters. AC mains connections can cause electric shock, burns, fire or other serious hazards.

The presence of a sensor module does not automatically make the complete monitoring system safe for direct mains connection.

Circuit isolation, component ratings, protection, PCB creepage and clearance, enclosure design and testing procedures must be appropriately evaluated.

All mains-related assembly and testing must be performed under qualified supervision using suitable safety equipment.

## 7. Conclusion

The hardware components form the sensing, processing, display and communication foundation of the IoT Smart Energy Monitoring System.

Exact component specifications and ratings will be added as they are verified against the physical prototype, module markings and manufacturer documentation.
