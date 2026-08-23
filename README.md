# 🚗 RC Car – Wireless QR Code Detection and Task Execution

**Team Number: TEAM-XX**

A wireless RC-car-based robotic system combining **Wi-Fi camera streaming, computer-based QR-code detection, manual task identification, Bluetooth control, ESP32 motor control, and RC car movement**.

---

## 📌 Project Overview

This project demonstrates a wireless robotic workflow using multiple communication technologies.

A phone mounted on the RC car is used as the camera source. The camera captures the environment and transmits the video wirelessly through a **TP-Link Archer AX55 Wi-Fi 6 router** to a computer.

The computer receives the camera stream and detects the QR code.

The detected QR code is displayed on the computer. A second phone is then used to scan the QR code displayed on the computer and reveal the assigned task.

After the task is revealed, a third phone running the **Arduino Bluetooth Controller** application is used to manually control the RC car.

The movement commands are sent through Bluetooth to an **ESP32**. The ESP32 controls the motor driver, which drives the RC car motors.

---

# 🎯 Objective

The objective of this project is to demonstrate a wireless robotic system capable of:

* Capturing the environment using a camera mounted on an RC car
* Transmitting the camera feed wirelessly
* Receiving the camera stream on a computer
* Detecting QR codes
* Displaying the detected QR information
* Scanning the QR code using a second phone
* Revealing the assigned task
* Manually controlling the RC car using Bluetooth
* Using an ESP32 to control the RC motors

---

# 🔄 Complete System Workflow

```text
┌──────────────────────────────┐
│           PHONE 1            │
│                              │
│   Camera mounted on RC Car   │
└──────────────┬───────────────┘
               │
              Wi-Fi
               │
               ▼
┌──────────────────────────────┐
│       TP-Link Archer AX55    │
│          Wi-Fi Router        │
└──────────────┬───────────────┘
               │
              Wi-Fi
               │
               ▼
┌──────────────────────────────┐
│          COMPUTER            │
│                              │
│     Receive Camera Stream    │
│              ↓               │
│        Detect QR Code        │
│              ↓               │
│       Display QR Code        │
└──────────────┬───────────────┘
               │
          QR displayed
               │
               ▼
┌──────────────────────────────┐
│           PHONE 2            │
│                              │
│        QR Code Scanner       │
│              ↓               │
│         Task Revealed        │
└──────────────┬───────────────┘
               │
          Task identified
               │
               ▼
┌──────────────────────────────┐
│           PHONE 3            │
│                              │
│ Arduino Bluetooth Controller │
│          Application         │
└──────────────┬───────────────┘
               │
           Bluetooth
               │
               ▼
┌──────────────────────────────┐
│            ESP32             │
└──────────────┬───────────────┘
               │
               ▼
┌──────────────────────────────┐
│        MOTOR DRIVER          │
└──────────────┬───────────────┘
               │
               ▼
┌──────────────────────────────┐
│           RC CAR             │
│        Moves / Drives        │
└──────────────────────────────┘
```

---

# 📡 Communication Architecture

The project uses two main wireless communication systems.

## 1. Wi-Fi Camera Communication

Phone 1 acts as the camera source.

```text
Phone 1
   │
   │ Wi-Fi
   ▼
TP-Link Archer AX55
   │
   │ Wi-Fi
   ▼
Computer
```

There is **no direct wired connection between Phone 1 and the computer**.

The TP-Link Archer AX55 provides the wireless network through which the camera stream reaches the computer.

---

## 2. Bluetooth RC Control

Phone 3 is used as the manual RC controller.

```text
Phone 3
   │
   │ Bluetooth
   ▼
ESP32
   │
   ▼
Motor Driver
   │
   ▼
RC Motors
```

The Arduino Bluetooth Controller application is used to send movement commands to the ESP32.

---

# 📱 Role of Each Phone

## Phone 1 – Camera

Phone 1 is mounted on the RC car.

Functions:

* Captures the environment
* Provides the camera/video stream
* Sends the video wirelessly through Wi-Fi

---

## Phone 2 – QR Scanner

Phone 2 is used after the QR code is detected and displayed on the computer.

Functions:

* Scans the QR code displayed on the computer
* Reads the QR information
* Reveals the assigned task

There is no automatic data transfer from the computer to Phone 2. The QR code is **physically scanned using Phone 2**.

---

## Phone 3 – RC Controller

Phone 3 is used to manually control the RC car.

The **Arduino Bluetooth Controller** application is used to send movement commands.

Typical movement commands include:

```text
Forward
Backward
Left
Right
Stop
```

---

# 💻 Computer

The computer acts as the vision-processing unit.

Its main functions are:

1. Receive the camera stream
2. Process the video
3. Detect the QR code
4. Display the detected QR information

---

# 🔍 QR Code Detection

The QR detection process can be implemented using Python and OpenCV.

```text
Camera Stream
      ↓
Read Video Frame
      ↓
Process Frame
      ↓
Detect QR Code
      ↓
Decode QR Data
      ↓
Display Result
```

---

# 🔧 Hardware Components

| Component           | Function                                      |
| ------------------- | --------------------------------------------- |
| Phone 1             | Camera mounted on RC car                      |
| TP-Link Archer AX55 | Wireless network/router                       |
| Computer            | Camera stream reception and QR detection      |
| Phone 2             | QR-code scanning                              |
| Phone 3             | Bluetooth RC control                          |
| ESP32               | Bluetooth command reception and motor control |
| Motor Driver        | Drives RC motors                              |
| DC Motors           | RC-car movement                               |
| RC Chassis          | Robotic platform                              |
| Battery             | Power supply                                  |

---

# 💻 Software

The project involves:

* Camera/video streaming application
* Python
* OpenCV
* QR-code detection
* Arduino IDE
* ESP32 firmware
* Arduino Bluetooth Controller application
* QR scanner application

---

# 🧪 Demonstration Procedure

## Step 1 – Camera Setup

Phone 1 is mounted on the RC car and the camera streaming application is started.

## Step 2 – Wi-Fi Connection

Phone 1 and the computer connect to the TP-Link Archer AX55 router.

## Step 3 – Camera Streaming

Phone 1 sends the camera stream through the Wi-Fi network.

## Step 4 – Computer Video Reception

The computer receives and displays the camera stream.

## Step 5 – QR Detection

The computer processes the video and detects the QR code.

## Step 6 – QR Display

The detected QR code is displayed on the computer.

## Step 7 – QR Scanning

Phone 2 is used to scan the QR code displayed on the computer.

## Step 8 – Task Identification

The QR code reveals the assigned task.

The task is manually interpreted by the operator.

## Step 9 – RC Control

Phone 3 is used with the Arduino Bluetooth Controller application.

## Step 10 – Bluetooth Communication

Phone 3 sends movement commands to the ESP32 through Bluetooth.

## Step 11 – Motor Control

The ESP32 controls the motor driver.

## Step 12 – Task Execution

The RC car is manually driven according to the identified task.

---

# 🏗️ System Architecture

```text
                    VISION SYSTEM

 ┌───────────────┐
 │    PHONE 1    │
 │    Camera     │
 └───────┬───────┘
         │
        Wi-Fi
         │
         ▼
 ┌───────────────┐
 │ TP-Link AX55  │
 │    Router     │
 └───────┬───────┘
         │
        Wi-Fi
         │
         ▼
 ┌───────────────┐
 │   COMPUTER    │
 │ Video + QR    │
 │  Detection    │
 └───────┬───────┘
         │
         ▼
 ┌───────────────┐
 │    PHONE 2    │
 │ QR Scanner    │
 └───────┬───────┘
         │
         ▼
   TASK REVEALED
         │
         ▼

                    CONTROL SYSTEM

 ┌───────────────┐
 │    PHONE 3    │
 │ Bluetooth     │
 │ Controller    │
 └───────┬───────┘
         │
     Bluetooth
         │
         ▼
 ┌───────────────┐
 │     ESP32     │
 └───────┬───────┘
         │
         ▼
 ┌───────────────┐
 │ Motor Driver  │
 └───────┬───────┘
         │
         ▼
 ┌───────────────┐
 │    RC CAR     │
 └───────────────┘
```

---

# 🎥 Project Demonstration

A demonstration video of the project is included in the repository.

The video demonstrates:

* RC car movement
* Camera mounted on the RC car
* Wireless camera communication
* TP-Link router communication
* Computer-side QR detection
* QR-code scanning
* Task identification
* Bluetooth control
* ESP32 motor control
* RC car movement

## Demo Video

The project video is available in:

```text
media/project-demo.mp4
```

---

# 💻 Reference Source Code

The `code/` directory contains reference implementations for:

* QR-code detection using Python and OpenCV
* ESP32 Bluetooth-based RC control

> **Important:** The original source code used during the physical demonstration is not currently available. The code included in this repository is therefore provided as a reference/reimplementation and should not be considered an exact copy of the original demonstration code.

---

# 📂 Repository Structure

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

# 🚀 Future Improvements

Possible improvements include:

* Automatic QR-code detection
* Automatic task identification
* Automatic task execution
* Removing manual QR scanning
* Developing a dedicated RC controller
* Autonomous navigation
* Obstacle detection
* LiDAR integration
* Ultrasonic sensor integration
* Real-time telemetry
* Battery monitoring
* Automatic movement planning
* Integration of QR detection and robot control into a single application
* Automatic generation of movement commands based on the detected task

---

# 📌 Project Status

**Status: Prototype / Demonstration**

The current repository documents the architecture, communication system, hardware, software, workflow, reference code, and demonstration video.

The demonstrated system uses:

* Wireless camera streaming
* Computer-based QR detection
* Manual QR scanning using Phone 2
* Manual task interpretation
* Manual RC control using Phone 3
* Bluetooth communication with ESP32
* Motor-driver-based RC-car control

---

# ⭐ Overall Workflow

```text
📱 PHONE 1
Camera
   ↓
📡 Wi-Fi
   ↓
📶 TP-Link Archer AX55
   ↓
📡 Wi-Fi
   ↓
💻 COMPUTER
   ↓
🔍 QR Detection
   ↓
🖥️ QR Displayed
   ↓
📱 PHONE 2
   ↓
🔎 QR Scan
   ↓
🎯 Task Revealed
   ↓
👤 Manual Task Interpretation
   ↓
📱 PHONE 3
   ↓
🎮 Arduino Bluetooth Controller
   ↓
📡 Bluetooth
   ↓
ESP32
   ↓
⚙️ Motor Driver
   ↓
🚗 RC CAR
   ↓
🎯 Task Performed
```

---

# 🏁 Conclusion

This project demonstrates the integration of wireless communication, computer vision, Bluetooth control, embedded systems, mobile devices, and an RC-car platform.

The complete demonstrated workflow is:

**Camera → Wi-Fi → TP-Link Router → Computer → QR Detection → Phone 2 → Task Identification → Phone 3 → Bluetooth → ESP32 → Motor Driver → RC Car**

The project provides a foundation for future development toward a fully autonomous QR-based robotic task-execution system.
