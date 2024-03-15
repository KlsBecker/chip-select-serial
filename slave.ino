/**
 * @file slave.ino
 * @brief This file contains the code for a slave device that controls an LED based on serial input.
 * 
 * The slave device reads characters from the serial communication and turns on or off an LED based on the received character.
 * The LED pin and chip select pin are defined, and the chip select pin is set as an input with a pull-up resistor enabled.
 * The code continuously checks the chip select pin and reads characters from the serial when the chip select pin is LOW.
 * If the received character is '1', the LED is turned on. If the received character is '0', the LED is turned off.
 * 
 * @author  Klaus Becker (beckerklaus@edu.unisinos.br)
 *          Carlos Eduardo de Souza (carlossouza2@edu.unisinos.br)
 */

// Add the necessary libraries
#include <Arduino.h>

// Pin definitions
const int ledPin = 13;        // LED pin
const int chipSelectPin = 10; // Chip select pin

// Variables
bool ledState = false;    // Current state of the LED

void setup() {
    // Initialize serial communication
    Serial.begin(9600);

    // Set LED pin as output
    pinMode(ledPin, OUTPUT);

    // Set chip select pin as input with pull-up resistor enabled
    pinMode(chipSelectPin, INPUT_PULLUP);
}

void loop() {
    // Check if chip select is LOW
    while(digitalRead(chipSelectPin) == LOW) {
        // Read the character from serial
        char character = Serial.read();

        // Check if the character is '1'
        if (character == '1') {
            // Turn on the LED
            digitalWrite(ledPin, HIGH);
        }
        // Check if the character is '0'
        else if (character == '0') {
            // Turn off the LED
            digitalWrite(ledPin, LOW);
        }
    }

    delay(100);
}
