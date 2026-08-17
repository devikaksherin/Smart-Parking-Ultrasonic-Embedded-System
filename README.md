# Smart Parking System using Ultrasonic Sensors

## Overview

The Smart Parking System is an embedded system project designed to monitor parking slot availability in real time using ultrasonic sensors.

The system detects whether each parking slot is free or occupied, calculates the number of available slots, and provides visual and audible indications.

The project was implemented and tested using an ESP32-based virtual simulation in Wokwi.

## Objectives

- Detect the occupancy status of parking slots.
- Calculate the number of available parking spaces.
- Display parking information using an OLED.
- Indicate slot status using red and green LEDs.
- Provide an audible alert when the parking area is full.
- Demonstrate practical Embedded Systems concepts.

## Features

- Four parking slots
- Four HC-SR04 ultrasonic sensors
- Real-time slot detection
- Free/occupied status indication
- Available slot counting
- OLED display
- Red and green LED indicators
- Parking-full buzzer alert
- Serial Monitor output
- Wokwi virtual simulation

## Components Used

- ESP32 Development Board
- 4 × HC-SR04 Ultrasonic Sensors
- 4 × Green LEDs
- 4 × Red LEDs
- SSD1306 OLED Display
- Buzzer
- 220Ω resistors
- Jumper wires

## System Architecture

```text
Parking Slot
     ↓
Ultrasonic Sensor
     ↓
Distance Measurement
     ↓
ESP32 Microcontroller
     ↓
Occupied / Free Decision
     ↓
Available Slot Count
     ↓
OLED + LEDs + Buzzer

Working Principle

Each HC-SR04 ultrasonic sensor measures the distance between the sensor and an object in the parking slot.

If the measured distance is below the configured threshold, the slot is considered occupied.

If the distance is above the threshold, the slot is considered free.

The ESP32 processes the readings from all four sensors and calculates the total number of available slots.

Parking Logic

The system uses a distance threshold of approximately 35 cm.

Distance < 35 cm  → OCCUPIED
Distance ≥ 35 cm  → FREE

Example:

Slot 1 → Occupied
Slot 2 → Free
Slot 3 → Occupied
Slot 4 → Free


Available Slots = 2
Output Indication
Slot Status	LED
FREE	Green
OCCUPIED	Red

When all four slots are occupied:

Available Slots = 0
PARKING FULL
Buzzer = ON
Pin Configuration
Ultrasonic Sensors
Slot	TRIG	ECHO
Slot 1	GPIO 5	GPIO 17
Slot 2	GPIO 16	GPIO 4
Slot 3	GPIO 27	GPIO 26
Slot 4	GPIO 25	GPIO 33
LEDs
Slot	Green LED	Red LED
Slot 1	GPIO 12	GPIO 2
Slot 2	GPIO 14	GPIO 13
Slot 3	GPIO 32	GPIO 23
Slot 4	GPIO 15	GPIO 18
OLED
OLED	ESP32
SDA	GPIO 21
SCL	GPIO 22
VCC	3.3V
GND	GND
Buzzer
Positive → GPIO 19
Negative → GND
Distance Calculation

The ultrasonic sensor works by sending an ultrasonic pulse and measuring the time taken for the echo to return.

Distance = (Echo Time × Speed of Sound) / 2

The division by 2 is required because the sound travels from the sensor to the object and then back to the sensor.

Simulation

The project was simulated using Wokwi.

The simulation was tested under different parking conditions:

All slots free.
One slot occupied.
Multiple slots occupied.
All slots occupied.
A previously occupied slot becoming free.
Parking-full buzzer alert.
OLED status display.
Serial Monitor output.
Testing Results
Test	Expected Result
All slots free	4 available slots
Slot 1 occupied	3 available slots
Two slots occupied	2 available slots
Three slots occupied	1 available slot
All slots occupied	Parking Full + buzzer
Slot becomes free	Available count increases

How to Run
Open the project in Wokwi.
Use an ESP32 board.
Connect the components according to the pin configuration.
Upload the Arduino code.
Start the simulation.
Change ultrasonic sensor distances to simulate vehicles.
Observe the LEDs, OLED and buzzer.
Check the Serial Monitor for sensor and slot information.
Applications

The concept can be used in:

Shopping malls
Hospitals
Airports
Universities
Office buildings
Residential communities
Smart cities
Commercial parking facilities
Future Improvements
ESP32 Wi-Fi dashboard
Mobile application
Cloud-based parking monitoring
RFID-based access control
Automatic barrier gate
License plate recognition
Real-time notifications
Larger multi-level parking management
Limitations
The current implementation is a virtual simulation.
Ultrasonic readings can be affected by reflections and object positioning.
Real-world deployment would require proper sensor mounting and calibration.
A production system would require reliable power and weather protection.
Learning Outcomes

Through this project, the following concepts were demonstrated:

ESP32 programming
Embedded C / Arduino programming
GPIO control
Ultrasonic sensor interfacing
Distance measurement
Threshold-based decision making
LED control
OLED interfacing
Buzzer control
Serial communication
Virtual embedded-system simulation
Author

Devika KS

B.Tech Computer Science with Data Science

Christ College of Engineering
