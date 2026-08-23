# 🚗 RC Car – Wireless QR Code Detection and Task Execution

**Team Number: TEAM-XX**

A wireless RC-car-based robotic system combining **IP Webcam streaming, Wi-Fi communication, QR-code detection, manual QR scanning, Bluetooth control, ESP32 motor control, and RC-car movement**.

---

## 📌 Project Overview

The project uses a smartphone mounted on the RC car as a wireless camera.

**Phone 1** runs the **IP Webcam** application and captures the environment. The video stream is transmitted through a **TP-Link Archer AX55 Wi-Fi 6 router** to a computer.

The computer receives the video stream and detects the QR code.

The detected QR code is displayed on the computer screen. **Phone 2** is then used to manually scan the QR code and reveal the assigned task.

After identifying the task, **Phone 3** runs the **Arduino Bluetooth Controller** application and manually controls the RC car.

Phone 3 sends Bluetooth commands to the **ESP32**, which controls the motor driver and RC-car motors.

---

## 🎯 Objective

The objective is to demonstrate a wireless robotic system that can:

- Capture video using a smartphone mounted on an RC car
- Stream video using IP Webcam
- Transfer video through Wi-Fi
- Detect QR codes using a computer
- Manually scan the QR code using another phone
- Identify the assigned task
- Control the RC car using Bluetooth
- Control motors using an ESP32 and motor driver

---

## 🔄 System Workflow

```text
        PHONE 1
     IP Webcam Camera
            │
            │ Wi-Fi
            ▼
   TP-Link Archer AX55
         Router
            │
            │ Wi-Fi
            ▼
        COMPUTER
   Camera Stream + QR
       Detection
            │
            ▼
        PHONE 2
      QR Scanner
            │
            ▼
      Task Revealed
            │
            ▼
        PHONE 3
 Arduino Bluetooth Controller
            │
         Bluetooth
            ▼
          ESP32
            │
            ▼
      Motor Driver
            │
            ▼
         RC CAR
```

---

## 📡 Communication

### Wi-Fi

Wi-Fi is used to transmit the camera stream.

```text
Phone 1
   ↓
IP Webcam
   ↓
Wi-Fi
   ↓
TP-Link Archer AX55
   ↓
Wi-Fi
   ↓
Computer
```

There is no wired connection between Phone 1 and the computer.

### Bluetooth

Bluetooth is used for RC-car movement.

```text
Phone 3
   ↓
Arduino Bluetooth Controller
   ↓
Bluetooth
   ↓
ESP32
   ↓
Motor Driver
   ↓
RC Motors
```

---

## 📱 Device Functions

| Device | Function |
|---|---|
| Phone 1 | Camera mounted on RC car |
| Phone 2 | Manually scans QR code |
| Phone 3 | Controls RC car through Bluetooth |
| TP-Link Archer AX55 | Wi-Fi network |
| Computer | Video reception and QR detection |
| ESP32 | Bluetooth command and motor control |
| Motor Driver | Drives RC motors |
| RC Car | Robotic platform |

---

## 🔍 QR Detection Process

The computer processes the IP Webcam stream.

```text
IP Webcam Stream
       ↓
Video Frame
       ↓
OpenCV
       ↓
QR Detection
       ↓
QR Data
       ↓
Display on Computer
       ↓
Phone 2 Scans QR
       ↓
Task Revealed
```

The reference QR detection program is available at:

```text
code/qr_detection.py
```

---

## 🎮 RC Control

Phone 3 uses the **Arduino Bluetooth Controller** application.

Typical commands are:

```text
F → Forward
B → Backward
L → Left
R → Right
S → Stop
```

The commands are sent to the ESP32 through Bluetooth.

```text
Phone 3
   ↓
Bluetooth
   ↓
ESP32
   ↓
Motor Driver
   ↓
RC Motors
```

---

## 🧪 Working Procedure

1. Mount Phone 1 on the RC car.
2. Open IP Webcam on Phone 1.
3. Connect Phone 1 and the computer to the TP-Link Archer AX55.
4. Start the IP Webcam server.
5. Open the camera stream on the computer.
6. Use Phone 3 to manually drive the RC car toward the QR code.
7. The camera captures the QR code.
8. The computer receives the video and detects the QR code.
9. The QR information is displayed on the computer.
10. Use Phone 2 to manually scan the QR code displayed on the computer.
11. Identify the assigned task.
12. Use Phone 3 to manually control the RC car.
13. Phone 3 sends Bluetooth commands to the ESP32.
14. The ESP32 controls the motor driver.
15. The RC car performs the assigned task.

---

## 💻 Software

- IP Webcam
- Python
- OpenCV
- NumPy
- Arduino IDE
- Arduino Bluetooth Controller
- QR Scanner application
- ESP32 firmware

---

## 🔧 Hardware

- RC Car chassis
- Phone 1
- Phone 2
- Phone 3
- TP-Link Archer AX55 Wi-Fi 6 Router
- ESP32
- Motor Driver
- DC Motors
- Battery

---

## 📂 Repository Structure

```text
RC-Car-Wireless-QR-Task/
│
├── README.md
├── LICENSE
├── .gitignore
│
├── code/
│   ├── qr_detection.py
│   ├── esp32_bluetooth_control.ino
│   └── requirements.txt
│
├── docs/
│   └── system_workflow.md
│
└── media/
    └── project-demo.mp4
```

---

## 💻 Installation

Clone the repository:

```bash
git clone https://github.com/YOUR-USERNAME/RC-Car-Wireless-QR-Task.git
cd RC-Car-Wireless-QR-Task
```

Install Python dependencies:

```bash
pip install -r code/requirements.txt
```

Run QR detection:

```bash
python code/qr_detection.py
```

For IP Webcam, replace the camera source in the Python program with the IP Webcam stream URL.

---

## 🔵 ESP32 Setup

1. Open `code/esp32_bluetooth_control.ino` in Arduino IDE.
2. Select the correct ESP32 board.
3. Select the correct COM port.
4. Verify the motor-driver GPIO connections.
5. Upload the program to the ESP32.
6. Connect Phone 3 using the Arduino Bluetooth Controller application.
7. Test the movement commands.

> The GPIO pins and Bluetooth commands may need to be changed according to the actual hardware configuration.

---

## ⚠️ Source Code Note

The original source code used during the physical demonstration is not currently available.

The code included in this repository is a **reference/reimplementation** showing how QR detection and ESP32 Bluetooth motor control can be implemented.

The code may require modification according to the actual IP Webcam URL, ESP32 GPIO pins, motor driver, and Bluetooth controller configuration.

---

## 🎥 Project Demonstration

The demonstration video is available in:

```text
media/project-demo.mp4
```

The video demonstrates the physical RC-car operation.

---

## ⚠️ Limitations

The current prototype includes manual operations:

- RC car movement is manual.
- QR scanning using Phone 2 is manual.
- Task identification is manual.
- Task execution is manual.
- IP Webcam configuration is manual.

The system is therefore a **prototype/demonstration system**, not a fully autonomous robot.

---

## 🚀 Future Improvements

- Automatic QR-code detection and task identification
- Automatic task execution
- Autonomous navigation
- Obstacle detection
- LiDAR integration
- Real-time telemetry
- Battery monitoring
- Dedicated mobile controller
- Automatic movement planning
- Integration of vision and robot control into one system

---

## 📌 Project Status

**Status: Prototype / Demonstration**

The project demonstrates the integration of:

**IP Webcam → Wi-Fi → Router → Computer → QR Detection → Phone 2 → Task → Phone 3 → Bluetooth → ESP32 → Motor Driver → RC Car**

---

## 📄 License

This project is licensed under the **MIT License**.

See the `LICENSE` file for details.
