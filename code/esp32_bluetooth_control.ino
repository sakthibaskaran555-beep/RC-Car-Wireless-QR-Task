/*

* RC CAR - ESP32 BLUETOOTH MOTOR CONTROL
*
* Reference / Reimplementation
*
* Bluetooth commands:
*
* F = Forward
* B = Backward
* L = Left
* R = Right
* S = Stop
*
* IMPORTANT:
* Change the GPIO pins according to the actual
* motor-driver wiring used in the RC car.
*
* This example is intended for an ESP32 board
* supporting BluetoothSerial.
  */

#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

// =========================================================
// MOTOR DRIVER GPIO PINS
// =========================================================
//
// Example configuration.
// Change these pins according to your hardware.
//

#define MOTOR_LEFT_IN1   26
#define MOTOR_LEFT_IN2   27

#define MOTOR_RIGHT_IN1  25
#define MOTOR_RIGHT_IN2  33

// =========================================================
// SETUP
// =========================================================

void setup()
{
Serial.begin(115200);

// Start Bluetooth
SerialBT.begin("RC_CAR_ESP32");

// Configure motor pins
pinMode(MOTOR_LEFT_IN1, OUTPUT);
pinMode(MOTOR_LEFT_IN2, OUTPUT);

pinMode(MOTOR_RIGHT_IN1, OUTPUT);
pinMode(MOTOR_RIGHT_IN2, OUTPUT);

// Stop motors initially
stopCar();

Serial.println("=================================");
Serial.println("ESP32 RC CAR CONTROLLER");
Serial.println("=================================");
Serial.println("Bluetooth Name: RC_CAR_ESP32");
Serial.println("Commands:");
Serial.println("F = Forward");
Serial.println("B = Backward");
Serial.println("L = Left");
Serial.println("R = Right");
Serial.println("S = Stop");
Serial.println("=================================");
}

// =========================================================
// LOOP
// =========================================================

void loop()
{
if (SerialBT.available())
{
char command = SerialBT.read();

```
Serial.print("Received Command: ");
Serial.println(command);

executeCommand(command);
```

}

// Optional serial-monitor control
if (Serial.available())
{
char command = Serial.read();

```
Serial.print("Serial Command: ");
Serial.println(command);

executeCommand(command);
```

}
}

// =========================================================
// COMMAND PROCESSING
// =========================================================

void executeCommand(char command)
{
switch (command)
{
case 'F':
case 'f':
forward();
break;

```
case 'B':
case 'b':
  backward();
  break;

case 'L':
case 'l':
  left();
  break;

case 'R':
case 'r':
  right();
  break;

case 'S':
case 's':
  stopCar();
  break;

default:
  Serial.println("Unknown command.");
  stopCar();
  break;
```

}
}

// =========================================================
// FORWARD
// =========================================================

void forward()
{
digitalWrite(MOTOR_LEFT_IN1, HIGH);
digitalWrite(MOTOR_LEFT_IN2, LOW);

digitalWrite(MOTOR_RIGHT_IN1, HIGH);
digitalWrite(MOTOR_RIGHT_IN2, LOW);

Serial.println("FORWARD");
}

// =========================================================
// BACKWARD
// =========================================================

void backward()
{
digitalWrite(MOTOR_LEFT_IN1, LOW);
digitalWrite(MOTOR_LEFT_IN2, HIGH);

digitalWrite(MOTOR_RIGHT_IN1, LOW);
digitalWrite(MOTOR_RIGHT_IN2, HIGH);

Serial.println("BACKWARD");
}

// =========================================================
// LEFT
// =========================================================

void left()
{
digitalWrite(MOTOR_LEFT_IN1, LOW);
digitalWrite(MOTOR_LEFT_IN2, HIGH);

digitalWrite(MOTOR_RIGHT_IN1, HIGH);
digitalWrite(MOTOR_RIGHT_IN2, LOW);

Serial.println("LEFT");
}

// =========================================================
// RIGHT
// =========================================================

void right()
{
digitalWrite(MOTOR_LEFT_IN1, HIGH);
digitalWrite(MOTOR_LEFT_IN2, LOW);

digitalWrite(MOTOR_RIGHT_IN1, LOW);
digitalWrite(MOTOR_RIGHT_IN2, HIGH);

Serial.println("RIGHT");
}

// =========================================================
// STOP
// =========================================================

void stopCar()
{
digitalWrite(MOTOR_LEFT_IN1, LOW);
digitalWrite(MOTOR_LEFT_IN2, LOW);

digitalWrite(MOTOR_RIGHT_IN1, LOW);
digitalWrite(MOTOR_RIGHT_IN2, LOW);

Serial.println("STOP");
}
