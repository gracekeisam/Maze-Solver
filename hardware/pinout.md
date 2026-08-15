# Pin Configuration

## Ultrasonic Sensors

| Sensor | TRIG | ECHO |
|---|---:|---:|
| Front | GPIO 13 | GPIO 12 |
| Left | GPIO 27 | GPIO 26 |
| Right | GPIO 25 | GPIO 23 |

## Motor Driver

| Motor Driver | ESP32 |
|---|---:|
| IN1 | GPIO 33 |
| IN2 | GPIO 32 |
| IN3 | GPIO 19 |
| IN4 | GPIO 18 |
| PWM 1 | GPIO 21 |
| PWM 2 | GPIO 22 |

## Power

- ESP32 → logic/control
- Motor driver → motors
- Common GND between ESP32 and motor driver
- Motors should be powered from an appropriate external supply
