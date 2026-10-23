GLUTOR WEB STARTER — BEGINNER SETUP
===================================

WHAT IS INCLUDED
----------------
1. index.html              Website dashboard (no framework or npm needed)
2. esp32_glutor_serial.ino Example ESP32 firmware that streams sensor data as JSON
3. README_FIRST_STEPS.txt  This guide

WHAT WORKS IN THIS STARTER
--------------------------
- A dashboard for MQ-138 raw ADC response, BME680 temperature, humidity and gas resistance
- Live serial reading support using Web Serial in desktop Chrome/Edge
- Start/stop experiment sessions
- Session history and readings table
- CSV export for one session or all sessions
- Demo mode to test the interface; generated values are clearly marked SIMULATED
- Session records saved locally in the same browser on the same laptop

IMPORTANT LIMITATIONS
---------------------
- This is a local prototype. It is not a deployed public website and has no cloud database/login.
- Local browser storage is not a backup. Export CSV files regularly.
- Live device connection requires ESP32 firmware to send newline-separated JSON at 115200 baud.
- Raw MQ-138 values are not acetone ppm and are not glucose values.
- BME680 is environmental/broad gas-response context, not a direct acetone or glucose sensor.
- No ML training or medical interpretation is included.

PART A — OPEN THE WEBSITE IN VS CODE
------------------------------------
1. Download and install Visual Studio Code if needed.
2. Create a folder named GLUTOR_Web_Starter on your laptop.
3. Put index.html in that folder.
4. Open VS Code -> File -> Open Folder -> choose GLUTOR_Web_Starter.
5. In VS Code, open Extensions (the four-squares icon) and install "Live Server" by Ritwick Dey.
6. Right-click index.html -> "Open with Live Server".
7. The site should open in your browser at a localhost address, often http://127.0.0.1:5500.
8. Use desktop Google Chrome or Microsoft Edge for Web Serial support. Opening the HTML by double-clicking may not allow device connection.

PART B — TEST THE WEBSITE BEFORE CONNECTING HARDWARE
---------------------------------------------------
1. Click "Start demo mode".
2. Watch the cards, chart, session history and table update.
3. Click "Stop demo mode" when finished.
4. Try "Export all CSV" and open the CSV in Excel/LibreOffice.
5. Remember: demo data is simulated and must not be included as real experimental results.

PART C — SEND REAL SENSOR DATA FROM ESP32
-----------------------------------------
1. Confirm your exact ESP32 board and MQ-138 breakout/module wiring.
2. SAFETY: ESP32 pins are not 5 V tolerant. Never connect a 5 V sensor output directly to an ESP32 GPIO. Check module output voltage and use appropriate voltage divider/conditioning. Do not power an MQ sensor heater from a GPIO pin.
3. In Arduino IDE, install the board package for your ESP32 and these libraries through Library Manager:
   - Adafruit BME680 Library
   - Adafruit Unified Sensor
4. Open esp32_glutor_serial.ino.
5. Confirm MQ138_PIN and BME680 I2C pins/address for your actual hardware. The code tries I2C address 0x76 and 0x77.
6. Select the correct ESP32 board and USB/serial port, then upload the sketch.
7. Close Arduino Serial Monitor before connecting from the website (only one app can normally own the serial port at a time).
8. Return to the website and click "Connect ESP32". Choose the ESP32 serial port in the browser dialog.
9. Type a session name and click "Start session". New JSON readings will be recorded in that session.
10. Click "Stop session" at the end and export the session CSV.

EXPECTED SERIAL FORMAT
----------------------
The website expects one JSON object per line, for example:
{"mq138_raw":1234,"temperature_c":25.4,"humidity_pct":47.2,"pressure_hpa":1007.8,"bme680_gas_ohms":84500}

The included sketch emits this shape automatically. The website also accepts common MQ field names such as mq_raw, mq138, mq, adc or raw.

TROUBLESHOOTING
---------------
- No Connect button support: use current desktop Chrome/Edge and serve the site through Live Server (localhost).
- No serial port appears: check the USB data cable, driver, board, permissions and selected port. Some cables are charge-only.
- Port is busy: close Arduino Serial Monitor or other serial terminal.
- Values do not update: confirm baud rate is 115200 and the firmware sends JSON lines ending with newline.
- MQ value stays at 0 or 4095: check sensor power, signal wiring, ADC range and voltage conditioning; do not assume this is a valid gas measurement.
- BME680 shows null: confirm I2C wiring, power, address, library installation and sensor detection.
- Website session data missing on another computer/browser: localStorage is browser/device-specific. Export CSV for transfer/backup.

NEXT SUGGESTED MILESTONES
-------------------------
1. Verify the hardware safely and stream stable raw readings over USB serial.
2. Capture baseline/ambient readings and document conditions, warm-up time and repeatability.
3. Add actual prototype photographs and verified wiring diagram to the project report.
4. Only if remote access or multiple laptops are required, add a backend/database later. This starter intentionally avoids that complexity.
