# Safety and Protection

## 1. Introduction

The Smart Energy Monitoring System involves electrical sensing, embedded electronics and cloud-connected monitoring.

Since the system is intended to monitor AC electrical parameters, electrical safety must be considered throughout hardware design, assembly, testing and operation.

This document describes the major safety considerations associated with the hardware implementation.

## 2. Electrical Isolation

Electrical isolation is an important consideration when interfacing AC sensing circuits with low-voltage microcontroller systems.

The voltage sensing subsystem must maintain appropriate isolation between the monitored AC supply and the low-voltage electronics.

The ZMPT101B module uses a voltage transformer-based sensing arrangement. However, the isolation and safety characteristics of the complete module must be verified from its datasheet and construction.

Additional considerations include:

- Appropriate isolation distances.
- Insulation integrity.
- Safe PCB layout.
- Proper separation of high-voltage and low-voltage sections.
- Suitable protection against accidental contact.

## 3. Voltage Sensor Safety

The ZMPT101B is used for AC voltage sensing.

Important precautions include:

- Verify the module's input voltage rating.
- Ensure proper input connections.
- Maintain suitable insulation.
- Prevent exposed live conductors.
- Verify the module's isolation characteristics.
- Avoid exceeding the rated operating conditions.

## 4. Current Sensor Safety

The ACS712 module is used for current measurement.

The monitored current passes through its internal current-carrying conductor.

Important precautions include:

- Verify the current rating of the selected module.
- Avoid exceeding its specified operating limits.
- Ensure secure current-path connections.
- Prevent loose wiring and overheating.
- Maintain suitable conductor ratings.
- Inspect the module for damage before operation.

## 5. Microcontroller Protection

The ESP32 is a low-voltage electronic controller.

Its protection considerations include:

- Keeping ADC input voltages within specified limits.
- Providing a stable regulated supply.
- Avoiding reverse polarity.
- Preventing short circuits.
- Ensuring appropriate grounding and signal references.
- Avoiding exposure to electrical transients beyond component ratings.

## 6. PCB Design Considerations

The custom PCB must account for the electrical and physical requirements of the system.

Important considerations include:

- Separation of high-voltage and low-voltage sections.
- Suitable creepage and clearance distances.
- Appropriate conductor widths.
- Secure component mounting.
- Suitable insulation.
- Protection against accidental contact.
- Adequate thermal considerations.

Actual PCB safety compliance must be established through design review and appropriate testing; it should not be assumed merely because a custom PCB has been fabricated.

## 7. Enclosure and Physical Protection

The enclosure is intended to protect and organize the electronic assembly.

Important design considerations include:

- Preventing accidental contact with hazardous conductors.
- Providing suitable insulation.
- Securing internal components.
- Preventing loose connections.
- Providing appropriate ventilation where necessary.
- Supporting safe handling and installation.

## 8. Power Supply Safety

The power supply subsystem must provide suitable operating voltages to the electronic components.

The design should account for:

- Input voltage compatibility.
- Regulated output voltage.
- Current capacity.
- Thermal performance.
- Short-circuit protection.
- Reverse-polarity protection where applicable.

## 9. Testing and Handling Precautions

The following precautions must be followed during development and testing:

1. Never handle exposed live electrical connections.
2. Disconnect power before modifying circuit connections.
3. Use properly rated and insulated test equipment.
4. Verify the test setup before applying power.
5. Avoid working on energized circuits without qualified supervision.
6. Inspect wiring and PCB connections regularly.
7. Use appropriate protective equipment and barriers.
8. Ensure that the enclosure prevents access to hazardous conductors.

## 10. Safety Limitations

The use of sensing modules does not automatically establish that the complete system is safe for permanent installation.

The final implementation requires appropriate evaluation of:

- Isolation ratings.
- PCB layout.
- Component ratings.
- Wiring and insulation.
- Enclosure construction.
- Overcurrent protection.
- Applicable electrical safety standards.

The prototype should not be treated as a certified commercial energy meter or installed as a replacement for an approved utility meter.

## 11. Summary

Electrical safety is an essential consideration in the development of the Smart Energy Monitoring System.

Appropriate component selection, isolation, PCB layout, enclosure design and controlled testing practices are necessary to support safe hardware development and future product refinement.
