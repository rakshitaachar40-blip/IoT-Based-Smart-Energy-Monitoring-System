Working Principle

1. Introduction

The Smart Energy Monitoring System operates by acquiring electrical measurements through dedicated sensing modules, processing the sensor outputs using an ESP32 microcontroller and making the resulting information available through local and cloud-connected interfaces.

The system follows a continuous monitoring approach in which electrical parameters are acquired, processed, displayed and transmitted for remote access.

2. Overall Working Sequence

The system operates through the following sequence:

The voltage and current sensors acquire electrical signals from the monitored supply.

The sensor outputs are interfaced with the ESP32.

The ESP32 acquires and processes the sensor readings.

Electrical parameters are calculated using the implemented firmware algorithms.

Selected values are displayed on the 16×2 I2C LCD.

The ESP32 establishes wireless communication using Wi-Fi.

Monitoring data is transmitted to Firebase Realtime Database.

The mobile application accesses the cloud data and presents it to the user.

3. Voltage Measurement

The ZMPT101B module is used for AC voltage sensing.

It provides an analog output corresponding to the input AC voltage. The ESP32 reads this output through its analog-to-digital converter (ADC).

The acquired signal is processed by the firmware to determine the voltage measurement.

For AC voltage measurement, the theoretical RMS voltage is:

[
V_{RMS}=\sqrt{\frac{1}{N}\sum_{i=1}^{N}v_i^2}
]

Where:

(V_{RMS}) = Root Mean Square voltage.

(v_i) = Individual sampled voltage values after removing the DC offset.

(N) = Number of samples.

The actual measurement depends on sensor calibration, ADC characteristics and the implemented signal-processing method.

4. Current Measurement

The ACS712 current sensor is used to measure electrical current.

The sensor operates using the Hall-effect principle and provides an analog output that varies with the current flowing through its current path.

The ESP32 acquires the sensor output through an analog input.

The firmware processes the acquired signal to determine the current measurement.

The theoretical RMS current is:

[
I_{RMS}=\sqrt{\frac{1}{N}\sum_{i=1}^{N}i_i^2}
]

Where:

(I_{RMS}) = Root Mean Square current.

(i_i) = Individual sampled current values after removing the zero-current offset.

(N) = Number of samples.

Accurate current measurement requires appropriate zero-current offset determination and sensor calibration.

5. Electrical Power Calculation

Electrical power represents the rate at which electrical energy is consumed.

For AC circuits, real power is theoretically calculated using:

[
P=\frac{1}{N}\sum_{i=1}^{N}v_i i_i
]

Where:

(P) = Real power in watts.

(v_i) = Instantaneous voltage samples.

(i_i) = Corresponding instantaneous current samples.

(N) = Number of samples.

For sinusoidal AC waveforms, the relationship can also be expressed as:

[
P=V_{RMS}\times I_{RMS}\times PF
]

The actual calculation method used by the firmware will be documented alongside the source code.

6. Energy Consumption Calculation

Energy consumption represents the accumulated electrical energy used over a period of time.

It is obtained by integrating real power over time.

For discrete measurements:

[
E_{kWh}=\frac{\sum P_j\Delta t_j}{3,600,000}
]

Where:

(E_{kWh}) = Energy consumption in kilowatt-hours.

(P_j) = Real power in watts.

(\Delta t_j) = Time interval in seconds.

3,600,000 = Conversion factor from watt-seconds to kilowatt-hours.

The accuracy of the accumulated energy value depends on the power measurement, sampling interval and time integration implemented in the firmware.

7. Power Factor

Power factor represents the relationship between real power and apparent power.

It is expressed as:

[
PF=\frac{P}{S}
]

Where:

(PF) = Power factor.

(P) = Real power in watts.

(S) = Apparent power in volt-amperes.

Apparent power is calculated as:

[
S=V_{RMS}\times I_{RMS}
]

Therefore:

[
PF=\frac{P}{V_{RMS}\times I_{RMS}}
]

For a sinusoidal supply, power factor is related to the phase difference between voltage and current.

8. Electricity Cost Estimation

The system includes an electricity cost estimation feature.

The estimated cost is determined using the calculated energy consumption and configured electricity tariff values.

For a simple uniform tariff:

[
\text{Estimated Cost}=E_{kWh}\times T
]

Where:

(E_{kWh}) = Energy consumption.

(T) = Applicable tariff per kWh.

For slab-based tariffs, the cost is calculated by applying the corresponding rate to the consumption within each applicable slab.

The tariff configuration and calculation method will be documented separately. The estimate should not be treated as an official electricity bill.

9. Local Data Visualization

A 16×2 LCD with an I2C interface is used to display selected electrical measurements.

The ESP32 communicates with the display through the I2C protocol.

This provides a local monitoring interface without requiring a separate computer or mobile device.

10. Cloud Communication

The ESP32 uses its built-in Wi-Fi capability to communicate with Firebase Realtime Database.

The processed monitoring information is transmitted to the cloud platform.

Firebase provides a common data-access layer for the mobile application.

The database structure, data fields and communication implementation will be documented in the software section.

11. Mobile Application Monitoring

The mobile application, developed using MIT App Inventor, provides remote access to the monitoring information.

It retrieves the data made available through Firebase and presents the relevant parameters through its dashboard.

This allows users to access energy monitoring information beyond the physical LCD interface.

12. Continuous Monitoring Cycle

The system follows a repeated monitoring cycle:

Sensing → Data Acquisition → Processing → Calculation → LCD Display → Firebase Communication → Mobile Application

The cycle continues during normal system operation, subject to power availability and network connectivity.

13. Summary

The working principle combines electrical sensing, embedded signal processing, parameter calculation, local visualization and cloud-based communication.

The ESP32 acts as the central controller, coordinating the sensing modules, LCD and Firebase integration to provide an IoT-enabled energy monitoring solution.
