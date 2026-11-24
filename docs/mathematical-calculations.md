# Mathematical Calculations

## 1. Introduction

The Smart Energy Monitoring System processes voltage and current measurements to determine important electrical parameters.

The mathematical calculations involved include:

1. Root Mean Square (RMS) voltage.
2. Root Mean Square (RMS) current.
3. Real power.
4. Apparent power.
5. Power factor.
6. Electrical energy consumption.
7. Estimated electricity cost.

The equations presented in this document describe the theoretical calculation methods. The final implementation must be verified against the actual firmware algorithms.

## 2. RMS Voltage

Alternating voltage varies continuously with time. RMS voltage represents the equivalent DC voltage that would produce the same heating effect across a resistive load.

For discrete voltage samples:

\[
V_{RMS}=\sqrt{\frac{1}{N}\sum_{n=1}^{N}v_n^2}
\]

Where:

- \(V_{RMS}\) = RMS voltage in volts.
- \(v_n\) = Instantaneous voltage sample.
- \(N\) = Total number of samples.

The voltage samples must represent the actual AC waveform. Any ADC bias or DC offset must be removed before calculating RMS voltage.

## 3. RMS Current

RMS current represents the effective value of alternating current.

For discrete current samples:

\[
I_{RMS}=\sqrt{\frac{1}{N}\sum_{n=1}^{N}i_n^2}
\]

Where:

- \(I_{RMS}\) = RMS current in amperes.
- \(i_n\) = Instantaneous current sample.
- \(N\) = Total number of samples.

For accurate measurement, the sensor's zero-current offset must be accounted for before calculating RMS current.

## 4. Real Power

Real power represents the actual electrical power consumed by a load.

For sampled voltage and current waveforms:

\[
P=\frac{1}{N}\sum_{n=1}^{N}v_n i_n
\]

Where:

- \(P\) = Real power in watts.
- \(v_n\) = Instantaneous voltage sample.
- \(i_n\) = Corresponding instantaneous current sample.
- \(N\) = Number of sample pairs.

Voltage and current samples must be synchronized for this calculation.

For sinusoidal AC waveforms, real power can also be expressed as:

\[
P=V_{RMS}\times I_{RMS}\times PF
\]

## 5. Apparent Power

Apparent power is the product of RMS voltage and RMS current.

\[
S=V_{RMS}\times I_{RMS}
\]

Where:

- \(S\) = Apparent power in volt-amperes (VA).
- \(V_{RMS}\) = RMS voltage.
- \(I_{RMS}\) = RMS current.

## 6. Power Factor

Power factor indicates how effectively electrical power is converted into useful work.

It is defined as the ratio of real power to apparent power.

\[
PF=\frac{P}{S}
\]

Substituting the apparent power equation:

\[
PF=\frac{P}{V_{RMS}\times I_{RMS}}
\]

For sinusoidal waveforms:

\[
PF=\cos\phi
\]

Where:

- \(PF\) = Power factor.
- \(\phi\) = Phase difference between voltage and current.

For distorted waveforms, power factor is not necessarily equal to the cosine of the phase difference alone.

## 7. Electrical Energy Consumption

Electrical energy represents the accumulated power consumption over time.

Energy is calculated by integrating real power over the measurement period.

For discrete measurements:

\[
E=\sum_{j=1}^{M}P_j\Delta t_j
\]

Where:

- \(E\) = Energy in watt-seconds.
- \(P_j\) = Real power during measurement interval \(j\).
- \(\Delta t_j\) = Duration of the corresponding interval in seconds.
- \(M\) = Number of measurement intervals.

To convert watt-seconds into kilowatt-hours:

\[
E_{kWh}=\frac{\sum_{j=1}^{M}P_j\Delta t_j}{3,600,000}
\]

The energy calculation must use actual elapsed time or a sufficiently accurate measurement interval.

## 8. Electricity Cost Estimation

The estimated electricity cost is determined using accumulated energy consumption and the applicable tariff.

### 8.1 Uniform Tariff

For a constant tariff:

\[
C=E_{kWh}\times T
\]

Where:

- \(C\) = Estimated electricity cost in INR.
- \(E_{kWh}\) = Energy consumption in kWh.
- \(T\) = Tariff in INR per kWh.

### 8.2 Slab-Based Tariff

For a slab-based tariff, the estimated cost is calculated by applying the corresponding rate to the consumption falling within each slab.

\[
C=\sum_{k=1}^{L}E_kT_k
\]

Where:

- \(E_k\) = Energy consumption assigned to slab \(k\).
- \(T_k\) = Applicable tariff for slab \(k\).
- \(L\) = Number of applicable tariff slabs.

The tariff structure must be configurable according to the applicable electricity billing rules.

This calculation represents an estimate and may not include fixed charges, taxes, subsidies or other billing adjustments.

## 9. Sensor Calibration

Sensor calibration is required to convert the acquired ADC readings into meaningful electrical measurements.

### 9.1 Voltage Calibration

The voltage sensor output is compared against a suitable reference measuring instrument.

A calibration factor is determined to align the sensor measurement with the reference value.

A simplified relationship is:

\[
V_{actual}=V_{measured}\times K_V
\]

Where:

- \(V_{actual}\) = Calibrated voltage.
- \(V_{measured}\) = Uncalibrated voltage measurement.
- \(K_V\) = Voltage calibration factor.

### 9.2 Current Calibration

The current sensor output is calibrated using a reference current measurement.

A simplified relationship is:

\[
I_{actual}=I_{measured}\times K_I
\]

Where:

- \(I_{actual}\) = Calibrated current.
- \(I_{measured}\) = Uncalibrated current measurement.
- \(K_I\) = Current calibration factor.

The actual calibration procedure must also account for sensor offset, sensitivity and ADC characteristics.

## 10. Measurement Accuracy

Measurement accuracy can be evaluated by comparing the system reading with a reference instrument.

Percentage error is calculated as:

\[
\%\ Error=
\left|
\frac{X_{measured}-X_{reference}}
{X_{reference}}
\right|\times100
\]

Where:

- \(X_{measured}\) = Value measured by the developed system.
- \(X_{reference}\) = Corresponding reference value.

A lower percentage error indicates closer agreement with the reference measurement.

This evaluation should be performed separately for voltage, current and power wherever suitable reference measurements are available.

## 11. Important Implementation Considerations

The accuracy of the mathematical calculations depends on:

- Correct sensor calibration.
- Removal of sensor DC offsets.
- ADC resolution and sampling characteristics.
- Appropriate sampling frequency.
- Synchronization of voltage and current samples.
- Accurate time integration for energy calculation.
- Correct handling of measurement units.
- Suitable treatment of low-load readings.

The theoretical equations must be distinguished from simplified calculations or approximations used in the firmware.

## 12. Summary

The mathematical foundation of the system involves RMS measurement, real and apparent power determination, power factor calculation, energy integration and electricity cost estimation.

These calculations convert the acquired electrical signals into meaningful information for energy monitoring.
