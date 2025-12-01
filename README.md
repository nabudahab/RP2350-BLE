# RP2350 BLE Heart Rate Monitor

This project demonstrates how to use the **Raspberry Pi RP2350** microcontroller with a **Digilent Pmod BLE** module to communicate with standard, off-the-shelf Bluetooth Low Energy (BLE) heart rate sensors.

## Project Overview

The goal of this project is to implement a BLE Central device on the RP2350 that scans for, connects to, and reads data from BLE peripherals advertising the standard Heart Rate Service (UUID `0x180D`).

### Hardware Requirements

*   **Microcontroller:** Raspberry Pi Pico 2 (or other RP2350-based board)
*   **BLE Module:** Digilent Pmod BLE (RN4870/RN4871 based)
*   **Sensor:** Any standard BLE Heart Rate Monitor (e.g., Polar H10, Garmin HRM)
*   **Wiring:** UART connection between RP2350 and Pmod BLE

### Features

*   Initializes the Pmod BLE via UART commands.
*   Scans for BLE devices advertising Heart Rate services.
*   Connects to a selected device.
*   Subscribes to Heart Rate Measurement notifications.
*   Parses and displays heart rate data (BPM) to the serial console.

## Getting Started


### Prerequisites

*   [Pico SDK](https://github.com/raspberrypi/pico-sdk) installed and configured.
*   CMake and a compatible build toolchain (e.g., GCC for ARM).
*   [PlatformIO](https://platformio.org/) installed for building and uploading firmware.
*   [Visual Studio Code](https://code.visualstudio.com/) (recommended IDE) with PlatformIO extension.

### Setup Instructions

1. **Hardware Setup:**  
    Wire the Digilent Pmod BLE module to the UART0 peripheral on the RP2350 board:
    - Connect Pmod BLE TX to RP2350 (UART0 RX)
    - Connect Pmod BLE RX to RP2350 (UART0 TX)
    - Connect Pmod BLE VCC and GND to appropriate power and ground pins

2. **Software Preparation:**  
    - Install the required toolchains and dependencies listed below.
    - Ensure the Pico SDK is configured for your environment.

3. **Firmware Upload:**  
    - Build and upload the firmware using PlatformIO as described in the next section.

4. **Testing:**  
    - Power on the RP2350 and BLE module.
    - Open a serial terminal at 115200 baud to observe BLE scanning and heart rate data.

### Building the Project

1.  Clone the repository:
    ```bash
    git clone <repository_url>
    cd RP2350-BLE
    ```

2. Use PlatformIO to build and upload the firmware:
    ```bash
    platformio run --target upload
    ```

## Usage

1.  Ensure your Heart Rate Monitor is worn correctly and active.
2.  Connect the RP2350 to your computer via USB.
3.  Open a serial terminal (e.g., PuTTY, minicom) connected to the Pico's USB serial port at 115200 baud.
4.  The output should display the connection status and incoming heart rate data.