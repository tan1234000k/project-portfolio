## 🔌 Circuit Design

The circuit consists of the following subsystems:

### Sensor Section
- 4 LDRs connected to analog pins
- Arranged for directional light sensing

### Measurement Section
- Voltage divider to scale solar voltage (9V → 3.3V)
- INA219 module for current measurement via I2C

### Control Section
- Arduino Nano 33 BLE acts as central controller

### Actuation Section
- Two SG90 servo motors for azimuth and elevation control

### Output Section
- LCD display for real-time data
- Bluetooth communication for remote monitoring

The circuit is designed to be compact and mounted on a PCB base for stability.
