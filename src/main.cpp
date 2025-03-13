/*************************************************************************************************************
* LILYGO T-Display-S3 KY-003 Hall Magnetic Sensor Module Project
*
* This code reads the digital signal from the KY-003 module and displays the sensor state on the
*  built-in screen of the LilyGO T-Display-S3 using the TFT_eSPI library.
* The screen is only updated if there is a change in the sensor state.
*
* Pin Connections:
*  - KY-003 VCC  -> 3.3V
*  - KY-003 GND  -> GND
*  - KY-003 D0   -> GPIO1
*
* KY-003 Specifications:
*  - Operating Voltage: 3.3V to 5.5V
*  - Operating Temperature: -40°C to 85°C
*  - Output: Digital
*
* Notes:
*  - Signal on GPIO1 is active low, this means that when a magnetic field is detected, there is 0V
*    on the pin. If no magnetic field is detected, there is 3.3V on the pin. We start with sensor state HIGH.
*************************************************************************************************************/

/*************************************************************
******************* INCLUDES & DEFINITIONS *******************
**************************************************************/

#include <Arduino.h>
#include <TFT_eSPI.h>

// TFT_eSPI
TFT_eSPI tft = TFT_eSPI();

// Pin definitions
const int sensorPin = 1;   // digital pin for Hall sensor

// Global variables
int sensorState = HIGH;      // current sensor state (active low, so default is HIGH)
int lastSensorState = HIGH;  // previous sensor state
bool redrawRequired = true;  // flag to redraw the screen


/*************************************************************
********************** HELPER FUNCTIONS **********************
**************************************************************/

// Function to draw static elements on the TFT screen
void drawStaticElements() {
  // Clear the screen and set text properties
  tft.fillScreen(TFT_BLACK);
  tft.setTextFont(2);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);

  // Reset cursor to the top-left corner
  tft.setCursor(0, 0);

  // Display header
  tft.println("---------------------------");
  tft.println("KY003 Hall Sensor Module");
  tft.println("---------------------------");

  // Display static labels
  tft.setCursor(0, 70); // position for sensor state label
  tft.print("Sensor State:");
}

// Function to update dynamic elements on the TFT screen
void updateDynamicElements() {
  // Update sensor state
  tft.setCursor(0, 90);                  // position for sensor state value (below the label)
  tft.print("                        "); // clear previous value (24 spaces = entire line)
  tft.setCursor(0, 90);                  // reset cursor
  tft.print(sensorState == HIGH ? "MAGNET DETECTED" : "NO MAGNET");
}


/*************************************************************
*********************** MAIN FUNCTIONS ***********************
**************************************************************/

// SETUP
void setup() {
  // Set pin modes with internal pull-up resistor enabled
  pinMode(sensorPin, INPUT_PULLUP); // enable internal pull-up resistor

  // Initialize the TFT display
  tft.init();
  tft.setRotation(0);                     // adjust rotation (0 & 2 portrait | 1 & 3 landscape)
  tft.fillScreen(TFT_BLACK);              // black background
  tft.setTextFont(2);                     // set the font size
  tft.setTextColor(TFT_WHITE, TFT_BLACK); // set text colour (white) and background colour (black)

  // Draw static elements once
  drawStaticElements();

  // Initial display update
  redrawRequired = true; // update display
}


// MAIN LOOP
void loop() {
  // Read the current sensor state
  int reading = digitalRead(sensorPin);

  // Check if the sensor state has changed
  if (reading != lastSensorState) {
    sensorState = reading;          // update the sensor state
    redrawRequired = true;          // flag to update the display
    lastSensorState = reading;      // save the current reading
  }

  // Update the display if the sensor state has changed
  if (redrawRequired) {
    updateDynamicElements();
    redrawRequired = false; // reset the flag
  }

  delay(1); // slow down the loop to save CPU cycles
}