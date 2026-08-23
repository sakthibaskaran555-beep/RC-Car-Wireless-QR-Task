# RC Car Wireless QR Task – System Workflow

## 1. System Architecture

The RC-car system consists of three smartphones, a Wi-Fi router, a computer, ESP32, motor driver, and RC-car motors.

```text
PHONE 1
IP Webcam
    │
    │ Wi-Fi
    ▼
TP-Link Archer AX55
    │
    │ Wi-Fi
    ▼
COMPUTER
    │
    │ OpenCV
    ▼
QR Detection
    │
    ▼
PHONE 2
QR Scanner
    │
    ▼
Task
    │
    ▼
PHONE 3
Bluetooth Controller
    │
    │ Bluetooth
    ▼
ESP32
    │
    ▼
Motor Driver
    │
    ▼
RC Car
```

---

## 2. Camera Communication

Phone 1 is physically mounted on the RC car.

The IP Webcam application converts the smartphone camera into a network camera.

```text
Phone Camera
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

No USB or video cable is required between Phone 1 and the computer.

---

## 3. QR Detection

The computer runs a Python program using OpenCV.

```text
Camera Stream
     ↓
Video Frame
     ↓
OpenCV QRCodeDetector
     ↓
QR Data
     ↓
Display
```

---

## 4. Manual QR Scanning

The detected QR code is displayed on the computer.

Phone 2 is used to manually scan the QR code.

```text
Computer Display
       ↓
     QR Code
       ↓
    Phone 2
       ↓
  QR Scanner
       ↓
Task Information
```

---

## 5. Bluetooth Control

After the task is identified, Phone 3 is used to control the RC car.

```text
Phone 3
   ↓
Arduino Bluetooth Controller
   ↓
Bluetooth
   ↓
ESP32
```

---

## 6. Motor Control

The ESP32 processes the received command and controls the motor driver.

```text
ESP32
   ↓
Motor Driver
   ↓
Left Motor + Right Motor
   ↓
RC Car
```

---

## 7. Command Mapping

| Command | Function |
| ------- | -------- |
| F       | Forward  |
| B       | Backward |
| L       | Left     |
| R       | Right    |
| S       | Stop     |

---

## 8. Complete Sequence

```text
1. Power the RC car.
2. Start the TP-Link router.
3. Connect Phone 1 to the router.
4. Connect the computer to the router.
5. Start IP Webcam on Phone 1.
6. Start the QR detection program.
7. Use Phone 3 to move the RC car.
8. Phone 1 captures the environment.
9. The camera stream reaches the computer through Wi-Fi.
10. OpenCV detects the QR code.
11. The QR code is displayed on the computer.
12. Phone 2 scans the QR code.
13. The assigned task is revealed.
14. Phone 3 controls the RC car.
15. Bluetooth commands reach the ESP32.
16. ESP32 controls the motor driver.
17. The RC car performs the task.
```

---

## 9. Communication Technologies

### Wi-Fi

Used for:

* IP Webcam video streaming
* Communication between Phone 1 and computer
* Wireless network connectivity

### Bluetooth

Used for:

* RC-car movement commands
* Communication between Phone 3 and ESP32

### USB

USB is used only during development/programming when uploading firmware to the ESP32.

It is not required for the wireless camera-streaming path.

---

## 10. Future Autonomous System

The manual workflow can later be replaced with an autonomous architecture:

```text
Camera
   ↓
Computer / Edge Processor
   ↓
QR Detection
   ↓
Task Recognition
   ↓
Task Planner
   ↓
Navigation
   ↓
ESP32 / Motor Controller
   ↓
Motor Driver
   ↓
RC Car
```
