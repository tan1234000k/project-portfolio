#include <ArduinoBLE.h>
#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// ---------------- LCD ----------------
LiquidCrystal_I2C lcd(0x27, 16, 2);

// ---------------- Servo ----------------
Servo servoH;   // Horizontal (Azimuth)
Servo servoV;   // Vertical (Elevation)

int posH = 90;
int posV = 45;

const int H_MIN = 5;
const int H_MAX = 175;
const int V_MIN = 10;
const int V_MAX = 135;

// ---------------- LDR Pins ----------------
int LDR_TL = A2;
int LDR_TR = A3;
int LDR_BL = A7;
int LDR_BR = A6;

// ---------------- Voltage Pin ----------------
int solarPin = A0;

// ---------------- Control Parameters ----------------
int tolerance = 20;
int stepSize = 2;
int delayTime = 50;

// ---------------- BLE ----------------
BLEService solarService("180A");
BLEUnsignedIntCharacteristic voltageChar("2A58", BLERead | BLENotify);

void setup() {
  Serial.begin(9600);

  // LCD Init
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Solar Tracker");
  lcd.setCursor(0, 1);
  lcd.print("Initializing...");
  delay(2000);

  // Servo Init
  servoH.attach(9);
  servoV.attach(10);

  servoH.write(posH);
  servoV.write(posV);

  delay(1000);

  // BLE Init
  if (!BLE.begin()) {
    Serial.println("BLE Failed!");
    while (1);
  }

  BLE.setLocalName("SunAxis");
  BLE.setAdvertisedService(solarService);
  solarService.addCharacteristic(voltageChar);
  BLE.addService(solarService);
  BLE.advertise();

  Serial.println("BLE Ready");
}

void loop() {

  BLEDevice central = BLE.central();

  // ----------- Read LDRs -----------
  int lt = analogRead(LDR_TL);
  int rt = analogRead(LDR_TR);
  int lb = analogRead(LDR_BL);
  int rb = analogRead(LDR_BR);

  // ----------- Average Values -----------
  int topAvg = (lt + rt) / 2;
  int bottomAvg = (lb + rb) / 2;
  int leftAvg = (lt + lb) / 2;
  int rightAvg = (rt + rb) / 2;

  int dVert = topAvg - bottomAvg;
  int dHorz = leftAvg - rightAvg;

  // ----------- Vertical Movement -----------
  if (abs(dVert) > tolerance) {
    if (topAvg > bottomAvg) {
      posV += stepSize;
    } else {
      posV -= stepSize;
    }
    posV = constrain(posV, V_MIN, V_MAX);
    servoV.write(posV);
  }

  // ----------- Horizontal Movement -----------
  if (abs(dHorz) > tolerance) {
    if (leftAvg > rightAvg) {
      posH -= stepSize;
    } else {
      posH += stepSize;
    }
    posH = constrain(posH, H_MIN, H_MAX);
    servoH.write(posH);
  }

  // ----------- Voltage Measurement -----------
  float Vout = (analogRead(solarPin) * 3.3) / 1023.0;
  float Vin = Vout * 3.0;   // Voltage divider scaling

  // ----------- LCD Display -----------
  lcd.setCursor(0, 1);
  lcd.print("V:");
  lcd.print(Vin, 1);
  lcd.print(" H:");
  lcd.print(posH);
  lcd.print(" ");

  // ----------- BLE Send -----------
  voltageChar.writeValue((unsigned int)(Vin * 100));

  // ----------- Serial Debug -----------
  Serial.print("LDRs: ");
  Serial.print(lt); Serial.print(" ");
  Serial.print(rt); Serial.print(" ");
  Serial.print(lb); Serial.print(" ");
  Serial.print(rb);

  Serial.print(" | H:");
  Serial.print(posH);
  Serial.print(" V:");
  Serial.print(posV);

  Serial.print(" | Voltage:");
  Serial.println(Vin);

  delay(delayTime);
}
