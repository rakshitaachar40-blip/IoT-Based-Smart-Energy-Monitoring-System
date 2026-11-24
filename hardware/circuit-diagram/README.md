# Circuit Diagram and Connections

## 1. Overview

The IoT Smart Energy Monitoring System consists of voltage and current sensing modules interfaced with an ESP32 microcontroller.

The ESP32 processes the acquired signals and provides the monitoring information through an LCD display and a Wi-Fi-based cloud connection.

This directory is intended to contain the circuit schematic and supporting hardware connection documentation.

## 2. Main Circuit Blocks

The hardware circuit is organized into the following blocks:

| Block | Components | Function |
|---|---|---|
| Voltage sensing | ZMPT101B module | Acquires a signal corresponding to AC voltage |
| Current sensing | ACS712 5A module | Acquires a signal corresponding to load current |
| Processing | ESP32 | Reads and processes sensor signals |
| Local display | 16×2 I2C LCD | Displays monitoring information |
| Power supply | Power supply circuitry | Supplies the electronic components |
| Hardware integration | Custom PCB | Organizes circuit connections |

## 3. Functional Connection Overview

The general signal flow is:

```text
       AC Voltage
            |
            v
     ZMPT101B Module
            |
            v
        ESP32 ADC
            |
            |
            v
       Measurement
        Processing
            ^
            |
        ESP32 ADC
            ^
            |
     ACS712 5A Module
            ^
            |
      Load Current

            |
            v
      16x2 I2C LCD

            |
            v
       Wi-Fi Connection
            |
            v
       Firebase Cloud
            |
            v
       Mobile Application
```

*This is a functional overview, not a verified electrical wiring schematic.*

## 4. Interface Description

### 4.1 Sensor-to-ESP32 Interface

The ZMPT101B and ACS712 modules provide analog output signals that are acquired by the ESP32.

The exact GPIO assignments, ADC configuration and signal conditioning details must be documented from the final firmware and circuit.

### 4.2 ESP32-to-LCD Interface

The 16×2 LCD communicates with the ESP32 through the I2C interface.

The LCD module used in the prototype has the I2C address `0x27`.

The exact SDA and SCL GPIO assignments must be confirmed from the final firmware.

### 4.3 ESP32-to-Firebase Communication

The ESP32 uses Wi-Fi connectivity to communicate with Firebase.

This is a wireless communication interface and does not require a direct physical connection between the ESP32 and the cloud platform.

## 5. Circuit Diagram Files

The final circuit diagram should be added to this directory.

Suggested filename:

`circuit-diagram.png`

A PDF version may also be included:

`circuit-diagram.pdf`

The final schematic should clearly indicate:

- ESP32 board and GPIO connections.
- Voltage sensor connections.
- Current sensor connections.
- LCD I2C connections.
- Power supply connections.
- Ground connections.
- Protection components.
- Relevant component ratings.

## 6. Connection Verification

Before publishing the final schematic, verify the following:

| Verification Item | Status |
|---|---|
| ESP32 board variant | To be confirmed |
| ZMPT101B output pin | To be confirmed |
| ACS712 output pin | To be confirmed |
| ESP32 ADC GPIO assignments | To be confirmed |
| LCD SDA connection | To be confirmed |
| LCD SCL connection | To be confirmed |
| Power supply connections | To be confirmed |
| Grounding arrangement | To be confirmed |
| Protection components | To be confirmed |

## 7. Safety Considerations

This project involves AC voltage monitoring.

The functional block diagram must not be treated as a construction guide for mains wiring.

The final electrical schematic must be reviewed for isolation, voltage ratings, current ratings, protection, creepage and clearance requirements.

Mains-related assembly and testing must be carried out under qualified supervision using suitable safety precautions.

## 8. Conclusion

This directory provides the structure for documenting the circuit schematic and hardware interfaces of the Smart Energy Monitoring System.

The final circuit diagram and verified GPIO assignments will be added after checking the actual prototype and firmware.
