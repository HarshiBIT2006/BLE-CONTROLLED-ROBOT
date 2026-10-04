# BLE-CONTROLLED-ROBOT
A simple Arduino-based Bluetooth-controlled robot car that can be controlled wirelessly using a smartphone.

The robot can move in four basic directions:

- ⬆️ Forward
- ⬇️ Reverse
- ⬅️ Left
- ➡️ Right
- ⏹️ Stop

## Project Overview

This project uses an **Arduino Uno**, **Bluetooth module**, **motor driver**, and **two DC motors** mounted on a robot chassis.

Commands are sent from a smartphone through Bluetooth. The Arduino receives the command and controls the two motors accordingly.

## Components Required

- Arduino Uno
- Bluetooth Module (HC-05/HC-06)
- Motor Driver
- 2 × DC Motors
- Robot Chassis
- Wheels
- Battery
- Jumper Wires

## Working Principle

The smartphone sends a movement command through the Bluetooth module.

The Bluetooth module transfers the command to the Arduino Uno. The Arduino then controls the motor driver, which determines the direction of rotation of the two DC motors.

### Basic Working

```text
        Smartphone
             │
             │ Bluetooth
             ↓
       Bluetooth Module
             │
             ↓
        Arduino UNO
             │
             ↓
        Motor Driver
          ↙       ↘
     Left Motor   Right Motor
          │          │
          └────┬─────┘
               ↓
             Robot
```

## Robot Movements

### Forward

Both motors rotate in the forward direction.

```text
Left Motor  → Forward
Right Motor → Forward
```

### Reverse

Both motors rotate in the reverse direction.

```text
Left Motor  → Reverse
Right Motor → Reverse
```

### Left

The left motor is stopped/reversed while the right motor moves forward, causing the robot to turn left.

```text
Left Motor  → Stop/Reverse
Right Motor → Forward
```

### Right

The right motor is stopped/reversed while the left motor moves forward, causing the robot to turn right.

```text
Left Motor  → Forward
Right Motor → Stop/Reverse
```

### Stop

Both motors are stopped.

```text
Left Motor  → Stop
Right Motor → Stop
```

## Pin Configuration

| Component | Arduino Pin |
|---|---:|
| Motor Driver IN1 | D2 |
| Motor Driver IN2 | D3 |
| Motor Driver IN3 | D4 |
| Motor Driver IN4 | D5 |
| Bluetooth RX | D3* |
| Bluetooth TX | D2* |

> **Note:** If you use `SoftwareSerial`, choose Bluetooth pins that do not conflict with your motor-driver pins. The exact Bluetooth wiring depends on your circuit.

## Control Commands

The smartphone sends a character for each movement.

| Command | Action |
|---|---|
| `F` | Forward |
| `B` | Reverse |
| `L` | Left |
| `R` | Right |
| `S` | Stop |

Example:

```text
F → Forward
B → Reverse
L → Left
R → Right
S → Stop
```

## Arduino Code

The Arduino continuously checks for incoming Bluetooth commands.

Basic logic:

```cpp
if (command == 'F') {
    forward();
}

else if (command == 'B') {
    reverse();
}

else if (command == 'L') {
    left();
}

else if (command == 'R') {
    right();
}

else if (command == 'S') {
    stopRobot();
}
```

## How to Use

### Step 1 — Assemble the Robot

Connect:

```text
Arduino UNO
     ↓
Motor Driver
   ↙     ↘
Motor 1  Motor 2
```

Mount both motors on the chassis and attach the wheels.

### Step 2 — Connect Bluetooth

Connect the Bluetooth module to the Arduino.

Make sure the Bluetooth module and Arduino have a common ground.

### Step 3 — Upload the Code

Open the Arduino sketch in the Arduino IDE.

Select:

```text
Board → Arduino Uno
```

Select the correct COM port and upload the program.

### Step 4 — Connect Smartphone

Turn on the robot.

Pair the smartphone with the Bluetooth module.

Open a Bluetooth control application and connect to the module.

### Step 5 — Control the Robot

Use the control buttons:

```text
        FORWARD
           ↑
           F

    LEFT ←  S  → RIGHT
           L     R

         REVERSE
           ↓
           B
```

The robot will respond to the corresponding Bluetooth commands.

## Features

- Wireless robot control
- Four-direction movement
- Bluetooth communication
- Arduino-based control
- Two-wheel drive
- Simple and beginner-friendly design

## Applications

This project can be used for:

- Arduino learning
- Embedded systems projects
- Bluetooth communication experiments
- Robotics demonstrations
- Remote-controlled vehicle projects
- College mini-projects

## Future Improvements

The project can be upgraded with:

- 📡 Obstacle detection
- 📱 Smartphone GUI
- 🎮 Joystick control
- 🛣️ Line-following mode
- 🔊 Voice control
- 📷 Camera-based monitoring
- 🤖 Autonomous navigation
- ⚡ PWM-based speed control

## Project Structure

```text
arduino-bluetooth-controlled-robot/
│
├── README.md
│
├── Arduino_Code/
│   └── bluetooth_robot.ino
│
├── Images/
│   ├── robot.jpg
│   └── circuit.jpg
│
└── LICENSE
```

## Author
Aditi Bhatnagar

---

⭐ If you found this project useful, consider giving this repository a star!
