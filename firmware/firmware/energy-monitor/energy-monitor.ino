/*
 ***************************************************************
 *  IoT Smart AC Energy Meter (ESP32 + EmonLib + LCD + Firebase)
 *  Slab-wise Billing
 ***************************************************************
 */

#include "EmonLib.h"
#include <EEPROM.h>
#include <WiFi.h>
#include <Firebase_ESP_Client.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "configuration.h"

// ================= FUNCTION PROTOTYPES =================
void updateLCD();
void handleButton();

// ================= LCD =================
LiquidCrystal_I2C lcd(0x27, 16, 2);

// ================= CALIBRATION =================
const float vCalibration = 47.50;
const float currCalibration = 7.50;

// ================= FIREBASE =================
FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

// ================= ENERGY MONITOR =================
EnergyMonitor emon;

// ================= ENERGY VARIABLES =================
float kWh = 0.0;
float bill = 0.0;
unsigned long lastMillis = 0;

// ================= EEPROM =================
const int addrKWh = 0;
const int addrBill = 4;
unsigned long lastEEPROMWrite = 0;

// ================= LCD CONTROL =================
int displayPage = 0;
const int displayButtonPin = 4;

// ================= SMOOTHING =================
const float SMOOTH_ALPHA = 0.15;
float smoothV = 0, smoothI = 0, smoothP = 0;
bool smoothInitialized = false;

// ================= SLAB RATES =================
#define RATE_0_50      5.74
#define RATE_51_100    6.24
#define RATE_101_200   6.74
#define RATE_201_300   7.24
#define RATE_ABOVE_300 7.74

// ================= SLAB BILL FUNCTION =================
float calculateBill(float energy) {
  float amount = 0;

  if (energy <= 50)
    amount = energy * RATE_0_50;

  else if (energy <= 100)
    amount = (50 * RATE_0_50) +
             ((energy - 50) * RATE_51_100);

  else if (energy <= 200)
    amount = (50 * RATE_0_50) +
             (50 * RATE_51_100) +
             ((energy - 100) * RATE_101_200);

  else if (energy <= 300)
    amount = (50 * RATE_0_50) +
             (50 * RATE_51_100) +
             (100 * RATE_101_200) +
             ((energy - 200) * RATE_201_300);

  else
    amount = (50 * RATE_0_50) +
             (50 * RATE_51_100) +
             (100 * RATE_101_200) +
             (100 * RATE_201_300) +
             ((energy - 300) * RATE_ABOVE_300);

  return amount;
}

// ================= SETUP =================
void setup() {
  Serial.begin(115200);

  Wire.begin(21, 22);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Energy Meter");
  lcd.setCursor(0, 1);
  lcd.print("Starting...");

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(300);
  }

  config.host = FIREBASE_HOST;
  config.signer.tokens.legacy_token = FIREBASE_AUTH;

  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);

  EEPROM.begin(512);
  EEPROM.get(addrKWh, kWh);
  EEPROM.get(addrBill, bill);

  if (isnan(kWh)) kWh = 0.0;
  if (isnan(bill)) bill = 0.0;

  pinMode(displayButtonPin, INPUT_PULLUP);

  emon.voltage(35, vCalibration, 1.7);
  emon.current(34, currCalibration);

  lastMillis = millis();
  lcd.clear();
}

// ================= LOOP =================
void loop() {

  emon.calcVI(20, 2000);

  float Vrms = emon.Vrms;
  float realPower = emon.realPower;

  if (Vrms < 5) Vrms = 0;
  if (realPower < 0) realPower = 0;

  float Ireal = (Vrms > 0) ? realPower / Vrms : 0;

  if (!smoothInitialized) {
    smoothV = Vrms;
    smoothI = Ireal;
    smoothP = realPower;
    smoothInitialized = true;
  } else {
    smoothV = SMOOTH_ALPHA * Vrms +
              (1 - SMOOTH_ALPHA) * smoothV;

    smoothI = SMOOTH_ALPHA * Ireal +
              (1 - SMOOTH_ALPHA) * smoothI;

    smoothP = SMOOTH_ALPHA * realPower +
              (1 - SMOOTH_ALPHA) * smoothP;
  }

  unsigned long now = millis();

  float timeDiff = (now - lastMillis) / 1000.0;

  kWh += (smoothP * timeDiff) / 3600000.0;

  lastMillis = now;

  bill = calculateBill(kWh);

  // ===== EEPROM WRITE EVERY 5 MINUTES =====
  if (millis() - lastEEPROMWrite > 300000) {
    EEPROM.put(addrKWh, kWh);
    EEPROM.put(addrBill, bill);
    EEPROM.commit();

    lastEEPROMWrite = millis();
  }

  // ===== FIREBASE UPDATE =====
  if (Firebase.ready()) {
    Firebase.RTDB.setFloat(&fbdo, "/energyMeter/voltage", smoothV);
    Firebase.RTDB.setFloat(&fbdo, "/energyMeter/current", smoothI);
    Firebase.RTDB.setFloat(&fbdo, "/energyMeter/power", smoothP);
    Firebase.RTDB.setFloat(&fbdo, "/energyMeter/energy", kWh);
    Firebase.RTDB.setFloat(&fbdo, "/energyMeter/bill", bill);
  }

  updateLCD();
  handleButton();

  delay(2000);
}

// ================= LCD DISPLAY =================
void updateLCD() {

  lcd.setCursor(0, 0);
  lcd.print("                ");

  lcd.setCursor(0, 1);
  lcd.print("                ");

  if (displayPage == 0) {

    lcd.setCursor(0, 0);
    lcd.print("V:");
    lcd.print(smoothV, 1);
    lcd.print(" I:");
    lcd.print(smoothI, 2);

    lcd.setCursor(0, 1);
    lcd.print("P:");
    lcd.print(smoothP, 0);
    lcd.print("W");

  } else {

    lcd.setCursor(0, 0);
    lcd.print("Energy:");
    lcd.print(kWh, 2);

    lcd.setCursor(0, 1);
    lcd.print("Bill:Rs ");
    lcd.print(bill, 2);
  }
}

// ================= BUTTON =================
void handleButton() {

  static bool lastState = HIGH;

  bool currentState = digitalRead(displayButtonPin);

  if (lastState == HIGH && currentState == LOW) {
    displayPage = (displayPage + 1) % 2;
    delay(200);
  }

  lastState = currentState;
}
