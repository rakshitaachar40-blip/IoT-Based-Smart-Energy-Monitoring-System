# Hardware Design

## 1. Introduction

The hardware design of the Smart Energy Monitoring System integrates electrical sensing modules, an ESP32 microcontroller, a local display and supporting power circuitry.

The hardware is designed to acquire electrical measurements, process sensor signals and provide the necessary interfaces for local and remote monitoring.

## 2. Hardware Architecture

The major hardware subsystems are:

1. Voltage sensing subsystem.
2. Current sensing subsystem.
3. Embedded processing subsystem.
4. Local display subsystem.
5. Power supply subsystem.
6. PCB and enclosure.

## 3. ESP32 Microcontroller

The ESP32 serves as the central processing unit of the system.

### Functions

- Acquires analog signals from the sensing modules.
- Processes sensor readings.
- Performs electrical parameter calculations.
- Controls the LCD through I2C communication.
- Establishes Wi-Fi connectivity.
- Transmits monitoring data to Firebase.

The ESP32 was selected for its processing capabilities, analog input interfaces and integrated wireless connectivity.

## 4. Voltage Sensing — ZMPT101B

The ZMPT101B voltage sensor module is used to measure AC voltage.

### Operating Principle

The module uses a voltage transformer to provide an isolated, scaled representation of the input AC voltage.

Its analog output is conditioned for measurement by the microcontroller's ADC.

### Role in the Project

- Senses the AC voltage waveform.
- Provides an analog output to the ESP32.
- Enables voltage measurement after calibration.

### Important Considerations

- Sensor output scaling must be calibrated.
- ADC input limits must not be exceeded.
- Measurement accuracy depends on signal conditioning and sampling.
- Appropriate isolation and electrical safety precautions are essential.

## 5. Current Sensing — ACS712

The ACS712 5A module is used for current measurement.

### Operating Principle

The ACS712 operates using the Hall-effect principle.

Current flowing through its internal conductor produces a magnetic field. The sensor detects this field and generates an analog output proportional to the current.

### Role in the Project

- Senses current flowing through the monitored circuit.
- Provides an analog signal to the ESP32.
- Enables current measurement after offset determination and calibration.

### Important Considerations

- Zero-current offset must be determined.
- Sensor sensitivity depends on the specific module variant.
- Noise and ADC resolution affect measurement accuracy.
- The selected current range must be appropriate for the monitored load.

## 6. LCD Display

A 16×2 LCD with an I2C interface is used for local visualization.

### Functions

- Displays selected electrical measurements.
- Provides immediate access to system readings.
- Reduces the need for a separate monitoring device.

### Communication

The LCD communicates with the ESP32 using the I2C protocol.

The exact I2C address and GPIO assignments will be documented from the finalized circuit and firmware.

## 7. Power Supply Circuitry

The power supply subsystem provides the required operating power to the electronic components.

Its design must account for:

- Input supply requirements.
- ESP32 operating voltage.
- Sensor module supply requirements.
- LCD supply requirements.
- Current consumption.
- Voltage regulation and protection.

Exact power supply components and ratings will be documented using the finalized circuit design.

## 8. Custom PCB Development

A custom PCB was developed to improve hardware integration and reduce dependence on a loosely connected prototype arrangement.

### Objectives

- Organize component interconnections.
- Improve assembly and physical integration.
- Provide a compact hardware implementation.
- Support product refinement.

PCB design files, fabrication details and photographs will be maintained in the `hardware/pcb-design/` directory.

## 9. Enclosure Development

An enclosure forms part of the physical product implementation.

It is intended to organize and protect the electronic assembly while supporting practical product integration.

Final enclosure dimensions, material and fabrication details will be documented after adding the corresponding design files.

## 10. Hardware Integration

The hardware integration process involves:

1. Interfacing the voltage sensor with the ESP32.
2. Interfacing the current sensor with the ESP32.
3. Connecting the LCD through I2C.
4. Integrating the power supply circuitry.
5. Verifying component connections.
6. Integrating the circuit with the custom PCB.
7. Testing the assembled hardware.

## 11. Hardware Verification

The hardware should be evaluated for:

- Correct sensor connections.
- Stable power supply operation.
- Valid analog signal acquisition.
- LCD communication.
- Wi-Fi connectivity.
- PCB continuity and assembly quality.
- Electrical isolation and protection.

Detailed test procedures and observations will be maintained in the `testing/` directory.

## 12. Safety Considerations

This project involves AC electrical measurements.

The voltage sensing arrangement, current path, PCB layout and enclosure must be designed with appropriate electrical isolation, insulation, clearances and protection.

The ESP32 and its low-voltage circuitry must not be exposed to hazardous mains voltage.

Testing and installation must be conducted using appropriate safety equipment and qualified supervision.

## 13. Summary

The hardware design combines voltage and current sensing, embedded processing, local display and supporting circuitry into an integrated monitoring platform.

The custom PCB and enclosure development represent further steps towards a compact and practical product implementation.
