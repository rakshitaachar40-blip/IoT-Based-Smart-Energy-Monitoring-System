# Calibration and Testing

## 1. Introduction

Calibration and testing are essential for ensuring the reliability of an electrical energy monitoring system.

The Smart Energy Monitoring System uses voltage and current sensing modules to acquire electrical measurements. These measurements are processed by the ESP32 to determine various electrical parameters.

Since sensor characteristics, ADC behaviour and environmental conditions can influence measurement accuracy, calibration and systematic testing are necessary.

This document describes the calibration approach, verification procedures and testing considerations followed during development.

## 2. Objectives of Calibration

The primary objectives are:

- Improve voltage measurement accuracy.
- Improve current measurement accuracy.
- Account for sensor offsets.
- Determine suitable calibration parameters.
- Improve the consistency of calculated electrical measurements.
- Identify measurement errors and possible sources of variation.

## 3. Voltage Sensor Calibration

### 3.1 Sensor

The ZMPT101B module is used for AC voltage measurement.

### 3.2 Calibration Methodology

The voltage measurement is calibrated by comparing the system reading against a suitable reference measuring instrument.

The general procedure is:

1. Establish a safe and stable test setup.
2. Measure the supply voltage using a reference instrument.
3. Record the corresponding system measurement.
4. Compare the two readings.
5. Adjust the voltage calibration parameter.
6. Repeat the measurement.
7. Evaluate the consistency of the readings.

### 3.3 Calibration Considerations

- Sensor output scaling.
- ADC input characteristics.
- Signal offset.
- Noise and fluctuations.
- Sampling characteristics.
- Stability of the reference supply.

The final calibration parameter must be obtained from experimental measurements rather than assumed from a different sensor module.

## 4. Current Sensor Calibration

### 4.1 Sensor

The ACS712 5A module is used for current measurement.

### 4.2 Calibration Methodology

The current sensor is calibrated by comparing its output against a suitable reference current measurement.

The general procedure is:

1. Determine the sensor output under zero-current conditions.
2. Record the zero-current offset.
3. Connect a suitable test load using a safe and isolated test arrangement.
4. Measure the current using a reference instrument.
5. Record the corresponding system reading.
6. Adjust the current calibration parameter.
7. Repeat the process at suitable operating conditions.
8. Evaluate measurement consistency.

### 4.3 Calibration Considerations

- Zero-current offset.
- Sensor sensitivity.
- ADC resolution.
- Noise in analog readings.
- Load variation.
- Temperature-related measurement changes.

## 5. Power Measurement Verification

Power measurement depends on the accuracy of voltage and current measurements and the calculation method used in the firmware.

The verification process should include:

1. Measuring voltage and current independently.
2. Comparing the calculated power with a suitable reference instrument.
3. Checking the behaviour under different load conditions.
4. Evaluating the consistency of readings.
5. Identifying discrepancies caused by calibration or signal processing.

For AC measurements, real power verification must account for the relationship between voltage and current waveforms.

## 6. Energy Measurement Verification

Energy consumption is accumulated over time using the measured power values.

The verification process should include:

- Checking the energy counter initialization.
- Observing energy accumulation over a known time interval.
- Verifying the conversion into kWh.
- Checking the effect of measurement intervals.
- Evaluating whether accumulated energy behaves consistently with the applied load.

The energy calculation should be compared against a suitable reference energy measurement wherever possible.

## 7. Power Factor Verification

Power factor calculation depends on the relationship between real power and apparent power.

The verification process should include:

- Checking the RMS voltage and current measurements.
- Comparing real and apparent power calculations.
- Evaluating the calculated power factor under suitable load conditions.
- Checking for unrealistic values caused by measurement noise or low-load operation.

## 8. LCD Verification

The 16×2 I2C LCD is tested to verify:

- Successful initialization.
- Correct I2C communication.
- Proper display of measurement values.
- Correct formatting and units.
- Continuous display updates.

## 9. Firebase Communication Testing

Firebase integration is evaluated to ensure that the ESP32 can successfully transmit monitoring information.

The testing procedure includes:

1. Establishing Wi-Fi connectivity.
2. Connecting to the configured Firebase database.
3. Transmitting the required measurement fields.
4. Checking whether the database receives updated values.
5. Verifying that the stored values correspond to the firmware readings.
6. Observing communication behaviour during network interruptions.

## 10. Mobile Application Testing

The mobile application is verified to ensure that it can access and display the information available through Firebase.

Testing considerations include:

- Database connectivity.
- Correct retrieval of measurement values.
- Compatibility of database field names and data types.
- Dashboard value updates.
- Correct presentation of electrical parameters.

## 11. Overall System Integration Testing

After individual component verification, the complete system is evaluated.

The integrated testing process covers:

1. Sensor operation.
2. ESP32 data acquisition.
3. Electrical parameter calculations.
4. LCD visualization.
5. Wi-Fi connectivity.
6. Firebase communication.
7. Mobile application updates.
8. Continuous system operation.

## 12. Error Analysis

Measurement error can be evaluated using:

\[
\%\ Error=
\left|
\frac{X_{system}-X_{reference}}
{X_{reference}}
\right|\times100
\]

Where:

- \(X_{system}\) = Measurement obtained from the developed system.
- \(X_{reference}\) = Corresponding reference measurement.

The error should be evaluated separately for each electrical parameter.

## 13. Sources of Measurement Error

Potential sources of measurement error include:

- Sensor tolerance.
- Incorrect calibration factors.
- ADC quantization.
- Analog signal noise.
- Sensor offset variations.
- Sampling limitations.
- Waveform distortion.
- Incorrect time integration.
- Unstable power supply conditions.

## 14. Testing Records

Experimental readings and verification results should be recorded systematically.

The following information should be maintained for each test:

- Test identification.
- Parameter under evaluation.
- Applied load or operating condition.
- Reference instrument reading.
- System reading.
- Calculated percentage error.
- Observations.
- Corrective action, if required.

Actual measurement tables, photographs and test observations will be maintained in the `testing/` directory.

## 15. Iterative Improvement

Testing and calibration contributed to the engineering refinement of the prototype.

The development process involved reviewing sensor behaviour, improving measurement reliability, refining hardware implementation and evaluating system integration.

Further improvements were considered during product development and stakeholder interactions.

## 16. Summary

Calibration and testing provide the foundation for evaluating the reliability of the Smart Energy Monitoring System.

A systematic approach to sensor calibration, measurement verification and hardware-software integration helps identify limitations and guide further engineering improvements.
