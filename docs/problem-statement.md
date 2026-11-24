# Problem Statement

## 1. Background

Electrical energy consumption is an essential aspect of residential and commercial environments. However, conventional electricity meters generally provide limited visibility into instantaneous electrical parameters and consumption patterns.

Users may not have convenient access to information such as real-time voltage, current, power consumption and estimated electricity expenses.

## 2. Identified Problem

The lack of accessible, real-time energy monitoring makes it difficult for users to understand their electricity consumption behaviour and make informed decisions regarding energy usage.

The key challenges identified are:

- Limited visibility into instantaneous electrical parameters.
- Difficulty in monitoring energy consumption remotely.
- Limited accessibility to continuously updated consumption information.
- Lack of convenient electricity expense estimation.
- Difficulty in understanding changes in energy consumption over time.

## 3. Proposed Solution

The proposed solution is an IoT-based Smart Energy Monitoring System using an ESP32 microcontroller.

Voltage and current sensing modules are interfaced with the ESP32 to acquire electrical measurements. The microcontroller processes the readings to calculate relevant electrical parameters.

The system provides:

- Local monitoring through an LCD.
- Remote access through Firebase cloud integration.
- A mobile application interface.
- Estimated electricity cost based on configured tariff values.

## 4. Engineering Challenge

The development involves several engineering challenges:

1. Acquiring reliable voltage and current measurements.
2. Calibrating sensors to improve measurement accuracy.
3. Processing electrical measurements using an embedded controller.
4. Integrating hardware and firmware reliably.
5. Establishing communication between the ESP32 and Firebase.
6. Presenting the monitored information through a user-friendly interface.
7. Refining the hardware implementation through PCB development.

## 5. Expected Outcome

The intended outcome is an integrated energy monitoring prototype capable of acquiring electrical measurements, processing energy-related parameters and presenting the information through local and remote interfaces.

The system aims to improve the accessibility of household energy consumption information and provide a foundation for further development of smart energy management solutions.
