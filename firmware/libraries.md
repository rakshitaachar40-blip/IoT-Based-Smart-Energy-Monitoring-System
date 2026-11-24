# Firmware Libraries and Dependencies

## 1. Introduction

The ESP32 firmware uses a combination of sensor-processing, storage, wireless communication, Firebase connectivity and LCD interface libraries.

This document identifies the libraries included in the firmware and describes their roles in the Smart Energy Monitoring System.

## 2. Libraries Used

The following libraries are included in the uploaded firmware source.

| Sl. No. | Library | Header File | Purpose |
|---|---|---|---|
| 1 | EmonLib | `EmonLib.h` | Voltage and real-power measurement calculations |
| 2 | EEPROM | `EEPROM.h` | Persistent storage of accumulated energy and bill values |
| 3 | WiFi | `WiFi.h` | ESP32 wireless network connectivity |
| 4 | Firebase ESP Client | `Firebase_ESP_Client.h` | Communication with Firebase Realtime Database |
| 5 | Wire | `Wire.h` | I2C communication interface |
| 6 | LiquidCrystal_I2C | `LiquidCrystal_I2C.h` | Control of the 16×2 I2C LCD |

## 3. Library Descriptions

### 3.1 EmonLib

**Header:** `EmonLib.h`

EmonLib is used for electrical measurement processing.

In the firmware, it is used to:

- Configure voltage measurement.
- Configure current measurement.
- Calculate RMS voltage.
- Calculate real power.

The firmware initializes the voltage and current measurement channels using:

```cpp
emon.voltage(35, vCalibration, 1.7);
emon.current(34, currCalibration);
```

The measurement calculations are performed using:

```cpp
emon.calcVI(20, 2000);
```

### 3.2 EEPROM

**Header:** `EEPROM.h`

The EEPROM library provides persistent storage functionality.

The firmware uses EEPROM emulation to preserve:

- Accumulated energy consumption (`kWh`).
- Estimated electricity bill (`bill`).

The values are stored at separate memory addresses and periodically written using `EEPROM.put()` and `EEPROM.commit()`.

### 3.3 WiFi

**Header:** `WiFi.h`

The ESP32 WiFi library manages wireless network connectivity.

It is used to:

- Connect the ESP32 to a configured Wi-Fi network.
- Check connection status.
- Support network connectivity required for Firebase communication.

### 3.4 Firebase ESP Client

**Header:** `Firebase_ESP_Client.h`

This library provides the interface between the ESP32 and Firebase Realtime Database.

The firmware uses it to upload:

- Voltage.
- Current.
- Real power.
- Energy consumption.
- Estimated bill.

The database values are written using Firebase Realtime Database operations.

### 3.5 Wire

**Header:** `Wire.h`

The Wire library provides I2C communication functionality.

It is used to initialize the I2C interface with:

```cpp
Wire.begin(21, 22);
```

The configured GPIO pins are:

- SDA: GPIO 21
- SCL: GPIO 22

### 3.6 LiquidCrystal_I2C

**Header:** `LiquidCrystal_I2C.h`

This library controls the 16×2 LCD through the I2C interface.

The LCD is initialized using:

```cpp
LiquidCrystal_I2C lcd(0x27, 16, 2);
```

It is used to display:

- Voltage.
- Current.
- Real power.
- Accumulated energy.
- Estimated bill.

## 4. Library Initialization and Usage

The general firmware initialization sequence includes:

1. Serial communication initialization.
2. I2C interface initialization.
3. LCD initialization.
4. Wi-Fi connection.
5. Firebase configuration.
6. EEPROM initialization and data retrieval.
7. Sensor measurement configuration.

## 5. Installation Requirements

The following dependencies must be available in the Arduino IDE environment:

| Library | Installation |
|---|---|
| EmonLib | Install through Arduino Library Manager or its official repository |
| Firebase ESP Client | Install the compatible Firebase ESP Client library |
| LiquidCrystal_I2C | Install a compatible LiquidCrystal_I2C implementation |
| EEPROM | Provided through the ESP32 Arduino core |
| WiFi | Provided through the ESP32 Arduino core |
| Wire | Provided through the ESP32 Arduino core |

The exact library versions used during the original development have not yet been recorded.

Compatible versions should be selected and tested before reproducing the firmware.

## 6. Platform Requirements

| Parameter | Requirement |
|---|---|
| Microcontroller | ESP32 |
| Development Environment | Arduino IDE |
| Framework | Arduino framework for ESP32 |
| Programming Language | C++ |
| Connectivity | Wi-Fi |
| Cloud Database | Firebase Realtime Database |

The exact ESP32 board package version should be recorded after verifying the original development environment.

## 7. Conclusion

These libraries provide the software interfaces required for electrical measurement processing, persistent storage, wireless communication, cloud connectivity and local display operation.

Maintaining this dependency list helps developers understand the firmware environment and reproduce the project more consistently.
