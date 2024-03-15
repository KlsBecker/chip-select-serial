# chip-select-serial
Serial Communication and GPIO Control for Master-Slave Microcontroller Network

## Description

This repository hosts the software for a communication network between one master and three slave microcontrollers, designed as part of the coursework for the **Sistemas Microcontrolados** class in the **Computer Engineering program at UNISINOS**. It demonstrates serial communication and GPIO for chip selection, controlling LEDs on slave microcontrollers based on button inputs on the master.

## Functionality

### Master Microcontroller

- Monitors three buttons, each linked to a specific slave microcontroller.
- Sends serial commands to toggle LEDs on or off on the slave microcontrollers.
- Utilizes GPIO pins for chip select functionality, ensuring that only the targeted slave microcontroller processes the command.

### Slave Microcontrollers

- Listen for serial commands from the master.
- Toggle an LED based on the received commands.
- Only the selected slave via chip select will act upon the command.

## How It Works

1. **Button Press:** A button press on the master microcontroller identifies which slave microcontroller's LED should be toggled.
2. **Serial Command:** The master sends a command via serial communication to turn the LED on or off, using GPIO pins for chip selection.
3. **LED Toggle:** The targeted slave microcontroller toggles its LED based on the command, while non-selected slaves ignore the command.

## Technical Details

- **Communication:** Utilizes serial communication for command transmission.
- **Chip Selection:** Employs GPIO pins on the master for selecting the active slave microcontroller.
- Includes code for both master and slave microcontrollers, detailed protocol explanation, and hardware setup instructions.
