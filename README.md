# GLUTOR
### An IoT-Enabled Breath Acetone Sensing System for Exploratory Glucose-Related Analysis

GLUTOR is a student major project exploring an IoT-based system for collecting and visualizing gas-sensor and environmental readings.

## Project Overview

The project combines a sensor setup, an ESP32 microcontroller, and a browser-based dashboard to display experimental readings, record sessions, and export observations as CSV files.

## Planned Hardware

- ESP32 development board
- MQ-138 gas sensor
- BME680 environmental sensor
- OLED display (planned for the hardware setup)

Hardware integration and measurements must be verified on the physical prototype.

## Software

- HTML, CSS, and JavaScript dashboard
- ESP32 firmware using Arduino IDE
- Browser Web Serial API for USB serial communication
- Browser localStorage for local session history
- CSV export for experimental records

## Running the Website

1. Download or clone this repository.
2. Open the project folder in Visual Studio Code.
3. Install the Live Server extension.
4. Open `index.html` with Live Server.
5. Use Demo Mode to test the dashboard without hardware.
6. For hardware testing, connect the ESP32 by USB and use the dashboard's serial connection feature in a compatible desktop browser.

See `README_FIRST_STEPS.txt` for additional setup guidance.

## Data Storage

The current starter stores session history in the browser on the local computer. It does not currently use a cloud database, and browser data is not automatically shared between team members.

## Important Limitations

The project is for educational and exploratory use. The MQ-138 is a broad-response gas sensor and is not specific to acetone. Sensor readings must not be interpreted as blood glucose values or used for medical diagnosis.

## Project Status

The website demo is operational. Physical sensor integration, hardware validation, and real-device testing remain to be verified.

## Team

- Anshul Mandloi
- Ashish Aishwar
- Harsh Suryavanshi
- Kanak Vani

Shri Govindram Seksaria Institute of Technology and Science (SGSITS), Indore  
Department of Information Technology
