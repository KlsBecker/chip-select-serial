/**
 * @file master.ino
 * @brief This file contains the code for controlling two slaves using Arduino.
 * 
 * The code defines the necessary chip select pins for each slave, button pins, and variables to store the LED and button states.
 * It initializes the serial communication, sets the chip select pins as outputs, and the button pins as inputs with pull-up resistors.
 * The loop function reads the button states, checks if a button is pressed, selects the corresponding slave, toggles the LED state, and sends the status message via serial.
 * It also waits for the button release before proceeding.
 * 
 * @author  Klaus Becker (beckerklaus@edu.unisinos.br)
 *          Carlos Eduardo de Souza (carlossouza2@edu.unisinos.br)
 */

// Add the necessary libraries
#include <Arduino.h>

// Define the chip select pins for each slave
const int slave1ChipSelectPin = 2;
const int slave2ChipSelectPin = 3;

// Define the button pins
const int button1Pin = 8;
const int button2Pin = 9;

// Variables to store the led states
bool led1State = false;
bool led2State = false;

// Variables to store the button states
bool button1State = false;
bool button2State = false;

void setup() {
  // Initialize the serial communication
  Serial.begin(9600);

  // Set the chip select pins as outputs
  pinMode(slave1ChipSelectPin, OUTPUT);
  pinMode(slave2ChipSelectPin, OUTPUT);

  // Set the button pins as inputs
  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);
}

void loop() {
  // Read the button states
  button1State = digitalRead(button1Pin);
  button2State = digitalRead(button2Pin);

  // Check if button 1 is pressed
  if (button1State == LOW) {
    // Select slave 1
    digitalWrite(slave1ChipSelectPin, LOW);
    digitalWrite(slave2ChipSelectPin, HIGH);

    // Toggle the LED state on slave 1
    led1State = !led1State;

    // Send the status message via serial

    Serial.println(led1State ? "1" : "0");

    // Wait for button release
    while (digitalRead(button1Pin) == LOW) {
      delay(10);
    }
  }

  // Check if button 2 is pressed
  if (button2State == LOW) {
    // Select slave 2
    digitalWrite(slave1ChipSelectPin, HIGH);
    digitalWrite(slave2ChipSelectPin, LOW);

    // Toggle the LED state on slave 2
    led2State = !led2State;

    // Send the status message via serial
    Serial.println(led2State ? "1" : "0");

    // Wait for button release
    while (digitalRead(button2Pin) == LOW) {
      delay(10);
    }
  }
}
