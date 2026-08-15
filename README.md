# Maze Solver Robot 

An autonomous maze-solving robot built using an ESP32, three ultrasonic sensors,
a motor driver, and two DC motors.

## Features

- Three-directional obstacle detection
- Autonomous navigation
- Wall/obstacle detection
- Left/right decision-making
- ESP32-based control
- Ultrasonic distance measurement

## Components

- ESP32 Development Board
- 3 × Ultrasonic Sensors
- Motor Driver
- 2 × DC Motors
- 2 × Wheels
- Robot Chassis
- Battery Supply

## Working

The three ultrasonic sensors continuously measure the distance from the
front, left, and right sides of the robot.

The robot:
1. Moves forward when the path is clear.
2. Stops when an obstacle is detected.
3. Compares the left and right distances.
4. Turns toward the side with more available space.
5. Moves backward when no suitable path is available.

## Pin Configuration

| Component | ESP32 Pin |
|---|---:|
| Front TRIG | GPIO 13 |
| Front ECHO | GPIO 12 |
| Left TRIG | GPIO 27 |
| Left ECHO | GPIO 26 |
| Right TRIG | GPIO 25 |
| Right ECHO | GPIO 23 |
| Motor A IN1 | GPIO 33 |
| Motor A IN2 | GPIO 32 |
| Motor B IN3 | GPIO 19 |
| Motor B IN4 | GPIO 18 |
| PWM 1 | GPIO 21 |
| PWM 2 | GPIO 22 |

## Software

- Arduino IDE
- ESP32 Board Package
- C/C++

## Repository Structure

See the `docs/`, `hardware/`, and `src/` directories for detailed
documentation, and source code.
