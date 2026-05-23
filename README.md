# 🤖 ESP32-CAM Solar Rover with IoT Monitoring

A smart surveillance and environmental monitoring rover using ESP32-CAM, NodeMCU, DHT11, MQ Gas Sensor, ThingSpeak, and a robotic arm with webserver control.

---

# 🚀 Features

✅ ESP32-CAM Live Video Streaming  
✅ Solar Powered Rover  
✅ Robotic Arm Control using WebServer  
✅ Temperature & Humidity Monitoring  
✅ Gas Detection System  
✅ ThingSpeak IoT Integration  
✅ WiFi Remote Control  
✅ Real-Time Sensor Monitoring  

---

# 🧰 Technologies & Domains Used

<p align="left">
  <img src="https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=Arduino&logoColor=white"/>
  <img src="https://img.shields.io/badge/ESP32--CAM-red?style=for-the-badge"/>
  <img src="https://img.shields.io/badge/IoT-grey?style=for-the-badge"/>
  <img src="https://img.shields.io/badge/Smart_Agriculture-84cc16?style=for-the-badge"/>
  <img src="https://img.shields.io/badge/Automation-4b5563?style=for-the-badge"/>
  <img src="https://img.shields.io/badge/Irrigation-f97316?style=for-the-badge"/>
  <img src="https://img.shields.io/badge/Embedded_Systems-374151?style=for-the-badge"/>
  <img src="https://img.shields.io/badge/Robotics-ef4444?style=for-the-badge"/>
</p>

---

# 🛠️ Components Used

## 🔹 Hardware Components

- ESP32-CAM Module
- ESP32 NodeMCU
- L298N Motor Driver
- DHT11 Sensor
- MQ2/MQ3 Gas Sensor
- Servo Motors
- FTDI Programmer
- Robot Chassis
- DC Motors
- Battery Pack
- Jumper Wires
- Breadboard

---

# 🔌 Circuit Connections

## 📷 ESP32-CAM Upload Connections

| FTDI Programmer | ESP32-CAM |
|----------------|-----------|
| VCC            | 5V        |
| GND            | GND       |
| TX             | U0R       |
| RX             | U0T       |

⚠️ Connect IO0 to GND before uploading code.

---

## 🤖 L298N Motor Driver Connections

| L298N Driver | ESP32-CAM |
|--------------|-----------|
| ENA          | GPIO12    |
| IN1          | GPIO13    |
| IN2          | GPIO15    |
| IN3          | GPIO14    |
| IN4          | GPIO2     |
| ENB          | GPIO12    |

---

## 🌡️ DHT11 Sensor Connections

| DHT11 | ESP32 |
|-------|-------|
| VCC   | 3.3V  |
| GND   | GND   |
| DATA  | GPIO4 |

---

## 💨 MQ Gas Sensor Connections

| MQ Sensor | ESP32 |
|-----------|-------|
| VCC       | 3.3V  |
| GND       | GND   |
| A0        | GPIO36 |

---

## 🦾 Servo Motor Connections

| Servo Motor | ESP32 |
|-------------|-------|
| Servo1      | GPIO13 |
| Servo2      | GPIO12 |
| Servo3      | GPIO14 |
| Servo4      | GPIO27 |

---

# 💻 Software Installation

## 🔹 Install Arduino IDE

Download Arduino IDE:

https://www.arduino.cc/en/software

---

# ⚙️ Install ESP32 Board

1. Open Arduino IDE  
2. Go to:

```bash
File → Preferences
```

3. Paste this URL in Additional Board Manager URLs:

```bash
https://dl.espressif.com/dl/package_esp32_index.json
```

4. Go to:

```bash
Tools → Board → Boards Manager
```

5. Search:

```bash
ESP32 by Espressif Systems
```

6. Install the latest version.

---

# 📚 Required Libraries

Install these libraries from Arduino IDE Library Manager.

## 🔹 Libraries

```bash
WiFi
HTTPClient
ESP32Servo
WebServer
DHT Sensor Library
Adafruit Unified Sensor
ESPAsyncWebServer
AsyncTCP
```

---

# ⚡ ESP32-CAM Board Settings

```bash
Board: AI Thinker ESP32-CAM
Upload Speed: 115200
Partition Scheme: Huge APP
PSRAM: Enabled
```

---

# 🌐 ThingSpeak Setup

1. Create account on ThingSpeak  
2. Create New Channel  
3. Add Fields:

```bash
Field 1 → Temperature
Field 2 → Humidity
Field 3 → Gas Value
```

4. Copy Write API Key.

---

---

# 📡 Access Robotic Arm WebServer

Connect to WiFi:

```bash
SSID: ESP32_Robot_Arm
Password: 12345678
```

Open browser:

```bash
192.168.4.1
```

---

# 📷 Applications

🏭 Industrial Monitoring  
🌱 Smart Agriculture  
🏠 Smart Home Automation  
🤖 Robotics Research  
🚨 Gas Leakage Detection  
📡 Surveillance Systems  

---

# 👨‍💻 Developed By

T. Lakshmi Hasmitha  
Robotics Engineering  
Vignan’s Foundation for Science Technology & Research  

📧 Email: [tadavarthyhasmitha@gmail.com](mailto:tadavarthyhasmitha@gmail.com)

🔗 LinkedIn: [Hasmitha Tadavarthy](https://www.linkedin.com/in/hasmitha-tadavarthy-898215345/)

---
