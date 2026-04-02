# Smart Assistive Stick for Blind and Elderly People

## 1. Project Title

**Smart Assistive Stick with Obstacle Detection, Fall Detection, GPS Tracking, and Camera Support using ESP32 & ESP32-CAM**

---

## 2. Problem Statement

Visually impaired and elderly individuals often face difficulty navigating unfamiliar environments safely. Traditional walking sticks provide only physical support but lack intelligent sensing capabilities to detect obstacles, monitor falls, or communicate location information. There is a need for a compact, low-cost assistive device that enhances safety, situational awareness, and emergency response.

---

## 3. Objective

* Develop a **smart assistive stick** capable of detecting obstacles in real time.
* Provide **haptic and audible feedback** to the user through vibration motors and a buzzer.
* Detect **falls or abnormal motion** using an inertial sensor.
* Provide **location tracking** using GPS.
* Integrate a **camera module for visual assistance or remote monitoring**.
* Allow the device to **switch between blind and elderly assistance modes** using a toggle switch.

---

## 4. System Overview

The system is built around an **ESP32 microcontroller** that processes sensor data and controls feedback devices. A **Time-of-Flight (ToF) distance sensor mounted on a servo motor** scans the environment to detect obstacles. A **MPU6050 accelerometer/gyroscope** detects sudden movements or falls. A **GPS module** provides real-time location tracking.

An **ESP32-CAM module** acts as a secondary subsystem responsible for capturing images or streaming video when required. The system provides alerts using **vibration motors and a buzzer**, ensuring that feedback can be perceived by both visually impaired and elderly users.

---

## 5. Hardware Components

* ESP32 Development Board (Main Controller)
* ESP32-CAM Module (Camera subsystem)
* VL53L0X Time-of-Flight Distance Sensor
* SG90 Servo Motor (for scanning detection)
* MPU6050 Accelerometer and Gyroscope
* NEO-6M GPS Module
* Active Buzzer
* Two Vibration Motors
* Toggle Switch (Mode selection)
* NPN Transistors (for driving motors)
* Flyback Diodes
* Resistors (1 kΩ, 4.7 kΩ pull-ups)
* 5V Power Supply / Battery
* Breadboard / PCB and jumper wires

---

## 6. Software Components

* Arduino IDE
* ESP32 Arduino Core
* I2C communication libraries
* VL53L0X sensor library
* MPU6050 library
* ESP32 Servo library
* TinyGPS++ library
* ESP32-CAM camera library
* Serial communication for ESP32 ↔ ESP32-CAM

---

## 7. Working Principle

The ESP32 continuously reads sensor data and processes it to determine environmental conditions.

1. The **servo motor rotates the ToF sensor from 0° to 180°** to scan the surroundings.
2. Distance measurements are analyzed to detect obstacles.
3. If an obstacle is detected within a threshold distance, **vibration motors and buzzer alert the user**.
4. The **MPU6050 monitors acceleration and orientation** to detect falls or abnormal movements.
5. The **GPS module retrieves latitude and longitude coordinates** for location tracking.
6. The **ESP32-CAM captures images or streams video** when triggered.
7. A **toggle switch selects between blind-assist mode and elderly-assist mode**, adjusting system behavior accordingly.

---

## 8. Block Diagram Description

The system consists of a **central ESP32 controller** connected to multiple sensors and feedback devices.

* **Input Layer:** ToF sensor, MPU6050, GPS module, toggle switch
* **Processing Layer:** ESP32 microcontroller
* **Output Layer:** Servo motor, buzzer, vibration motors
* **Vision Module:** ESP32-CAM connected through UART communication

Sensor data flows into the ESP32, which processes the data and generates alerts or control signals accordingly.

---

## 9. Circuit Design Explanation

Sensors such as the **VL53L0X and MPU6050 communicate with the ESP32 via the I2C bus**, sharing SDA and SCL lines with pull-up resistors. The **GPS module communicates using UART**, transmitting location data to the microcontroller.

The **servo motor receives PWM signals** from the ESP32 to rotate the sensor for scanning. Vibration motors are driven through **NPN transistor driver circuits** to safely control higher current loads. Flyback diodes are used across motors to protect the microcontroller from voltage spikes.

The **ESP32-CAM communicates with the main ESP32 through UART**, allowing camera control or image transfer.

---

## 10. Implementation Steps

1. Design the system architecture and select appropriate sensors.
2. Interface ESP32 with the ToF sensor and MPU6050 via I2C.
3. Integrate GPS module using UART communication.
4. Connect servo motor and implement scanning algorithm.
5. Implement vibration and buzzer feedback system.
6. Program fall detection using MPU6050 data.
7. Integrate ESP32-CAM and establish UART communication with the main ESP32.
8. Implement mode switching functionality using the toggle switch.
9. Assemble hardware on a prototype board.
10. Test obstacle detection, fall detection, and feedback mechanisms.

---

## 11. Challenges Faced

* Limited available GPIO pins on ESP32-CAM modules.
* Managing stable power supply for motors and camera module.
* Ensuring reliable I2C communication between multiple sensors.
* Handling sensor noise and false obstacle detections.
* Synchronizing communication between ESP32 and ESP32-CAM.

---

## 12. Results / Expected Output

* Real-time obstacle detection within a defined distance range.
* Immediate tactile and audible alerts when obstacles are detected.
* Detection of abnormal movements or falls.
* Accurate GPS coordinates available for tracking.
* Camera module capable of capturing or streaming visual data.

---

## 13. Future Improvements

* Integration of **AI-based object recognition** using ESP32-CAM.
* Mobile application for location tracking and alerts.
* Voice guidance using audio modules.
* Ultrasonic or LiDAR fusion for improved obstacle detection.
* Integration with IoT cloud platforms for remote monitoring.

---

## 14. Applications

* Assistive technology for visually impaired individuals.
* Mobility aid for elderly people.
* Smart navigation assistance devices.
* Safety monitoring systems for vulnerable individuals.

---

## 15. Bill of Materials

| Component               | Quantity |
| ----------------------- | -------- |
| ESP32 Development Board | 1        |
| ESP32-CAM Module        | 1        |
| VL53L0X ToF Sensor      | 1        |
| SG90 Servo Motor        | 1        |
| MPU6050 Sensor          | 1        |
| NEO-6M GPS Module       | 1        |
| Active Buzzer           | 1        |
| Vibration Motors        | 2        |
| Toggle Switch           | 1        |
| NPN Transistors         | 2        |
| Resistors               | Several  |
| Flyback Diodes          | 2        |
| Battery / Power Module  | 1        |

---

## 16. References

1. ESP32 Technical Reference Manual – Espressif Systems
2. VL53L0X Time-of-Flight Sensor Datasheet – STMicroelectronics
3. MPU6050 Motion Tracking Sensor Datasheet – InvenSense
4. NEO-6M GPS Module Documentation – u-blox
5. ESP32-CAM Camera Module Documentation – AI Thinker
6. Arduino ESP32 Core Documentation
