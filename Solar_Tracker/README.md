🌞 SunAxis Control System – Dual Axis Solar Tracker
1. 📌 Project Title

SunAxis Control System – Intelligent Dual Axis Solar Tracking with Real-Time Monitoring

2. ⚠️ Problem Statement

Fixed solar panels cannot maintain an optimal angle with respect to the sun throughout the day, leading to reduced energy generation. Advanced tracking methods using GPS and astronomical algorithms often fail under cloudy conditions and increase system complexity and cost.

3. 🎯 Objective
To design a dual-axis solar tracking system that keeps the panel perpendicular to sunlight.
To implement a sensor-based control algorithm for real-time tracking.
To measure voltage, current, and power output of the solar panel.
To visualize system performance using LCD and Bluetooth-based web interface.
To improve overall energy efficiency compared to fixed panels.
4. 🧠 System Overview

The system uses four LDR sensors to detect sunlight intensity and adjusts the panel using two servo motors along azimuth and elevation axes. The Arduino Nano 33 BLE processes sensor data, controls movement, and monitors electrical output. Data is displayed on an LCD and transmitted via Bluetooth for real-time visualization.

5. 🔩 Hardware Components
Arduino Nano 33 BLE
4 × LDR Sensors
2 × SG90 Servo Motors
Solar Panel (5V–9V)
INA219 Current Sensor
Voltage Divider Circuit
16×2 LCD (I2C)
PCB Board
Power Supply / Battery
Connecting wires and mechanical frame
6. 💻 Software Components
Arduino IDE
Embedded C / Arduino Programming
Arduino Libraries:
Servo.h
Wire.h
LiquidCrystal_I2C.h
ArduinoBLE.h
Web Interface (HTML + Chart.js for visualization)
7. ⚙️ Working Principle

The system continuously reads light intensity from four LDRs placed around the panel. By comparing these values, it determines the direction of maximum sunlight and adjusts the panel using servo motors. The system maintains a near-perpendicular alignment with sunlight throughout the day. Simultaneously, voltage and current are measured, and power is calculated and displayed.

8. 🔲 Block Diagram Description

The system consists of three main blocks:

Input Block: LDR sensors, voltage divider, INA219
Control Unit: Arduino Nano 33 BLE
Output Block: Servo motors, LCD display, Bluetooth module

The sensors feed data to the controller, which processes it and sends control signals to actuators while displaying and transmitting performance data.

9. 🔌 Circuit Design Explanation
LDRs are connected to analog pins to measure light intensity.
Servo motors are connected to PWM pins for precise angular control.
The solar panel output is scaled using a voltage divider before feeding into the Arduino.
Current is measured using the INA219 module via I2C communication.
LCD is connected using I2C to reduce pin usage.
BLE module is integrated internally in Arduino Nano 33 BLE.
10. 🛠️ Implementation Steps
Assemble the mechanical structure for dual-axis movement.
Connect LDR sensors around the solar panel.
Interface servo motors with Arduino.
Build voltage and current sensing circuits.
Upload control algorithm to Arduino.
Calibrate sensor readings and servo limits.
Integrate LCD display and BLE communication.
Test tracking accuracy and data output.
11. ⚡ Challenges Faced
Noise and fluctuation in LDR readings
Servo jitter due to continuous adjustments
Voltage scaling for safe ADC input
Maintaining stability under varying light conditions
Synchronizing real-time data transmission
12. 📊 Results / Expected Output
Continuous tracking of sunlight from sunrise to sunset
Smooth azimuth and elevation movement
Improved efficiency compared to fixed panels
Real-time voltage, current, and power display
Graphical visualization via web interface
13. 🚀 Future Improvements
Integration of AI-based optimization algorithms
Weather prediction and adaptive tracking
Use of stepper motors for higher precision
IoT cloud integration for remote monitoring
Automatic storm/wind protection mechanism
14. 🌍 Applications
Solar power plants
Smart energy systems
Autonomous solar devices
Research and educational projects
Off-grid energy solutions
15. 📦 Bill of Materials
Component	Quantity
Arduino Nano 33 BLE	1
LDR Sensors	4
SG90 Servo Motors	2
Solar Panel	1
INA219 Sensor	1
LCD (16×2 I2C)	1
PCB Board	1
Power Supply	1
Misc (wires, connectors)	As required
16. 📚 References
Solar Tracking System Research Papers
Arduino Official Documentation
INA219 Datasheet
Servo Motor Control Guides
Embedded Systems Design Resources
